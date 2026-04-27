# Bit Manipulation 常用 Mask 與手法精華錄

在嵌入式系統與 BMC 開發中，位元運算是不僅是效能優化的手段，更是直接操控硬體寄存器（Registers）的唯一方式。

## 1. 基礎位元操作 (The Big Four)

| 操作 | 程式碼實作 | 說明 |
| :--- | :--- | :--- |
| **Set Bit** | `reg \|= (1U << n);` | 將第 n 位設為 1 (OR 1) |
| **Clear Bit** | `reg &= ~(1U << n);` | 將第 n 位設為 0 (AND 0) |
| **Toggle Bit** | `reg ^= (1U << n);` | 反轉第 n 位 (XOR 1) |
| **Check Bit** | `if (reg & (1U << n))` | 檢查第 n 位是否為 1 |

---

## 2. 常用 Mask (遮罩) 生成手法

### 生成低 N 位全為 1 的 Mask
例如 `n = 4` 得到 `0x0000000F`
```c
uint32_t mask = (1U << n) - 1;
```
## 3. 進階位元技巧 (Kernel Style)
A. 檢查是否為 2 的冪次 (Power of 2)
原理：2 的冪次在二進位中只有一個 1，減 1 後會導致該位變 0 且後方全變 1。
```c
bool isPowerOfTwo(uint32_t n) {
    return (n != 0) && ((n & (n - 1)) == 0);
}
```

B. 快速移除最低位的 1 (Brian Kernighan's Algorithm)
這是計算 Set bits (Popcount) 的最快方式，因為它直接跳過 0。
```c
n &= (n - 1); // 每次執行都會消掉最右邊的一個 1
```

C. 獲取最低位的 1 (Isolate lowest set bit)
```c
uint32_t lowest_bit = n & -n; 
// 補數原理：-n 是 n 取反加 1，與原數做 AND 只會保留最低位的 1
```

D. 對齊運算 (Alignment)
將 addr 向上對齊到 align (必須是 2 的冪次) 的倍數。這是 aligned_malloc 的靈魂。
```c
#define ALIGN(addr, align) (((addr) + (align) - 1) & ~((uintptr_t)(align) - 1))
```

## 4. 欄位提取與寫入 (Field Manipulation)
提取位元欄位 (Extract Field)
從寄存器中取出 start 到 end 的數值。
```c
uint32_t val = (reg >> start) & ((1U << (end - start + 1)) - 1);
```

更新位元欄位 (Update Field)
將 value 寫入寄存器的特定區間，且不影響其他無關位元。
```c
uint32_t mask = ((1U << (end - start + 1)) - 1) << start;
reg = (reg & ~mask) | ((value << start) & mask);
```
## 5. 面試常考範例實作
Popcount (計算 1 的個數)

```c
int countSetBits(uint32_t n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // 跳過中間的 0
        count++;
    }
    return count;
}
```

Byte Swap (Endianness 轉換)
針對 32-bit 整數進行大端/小端轉換 (Little-endian <-> Big-endian)。

```c
uint32_t swap32(uint32_t n) {
    return ((n >> 24) & 0xff) |      // Byte 3 -> 0
           ((n << 8) & 0xff0000) |   // Byte 1 -> 2
           ((n >> 8) & 0xff00) |     // Byte 2 -> 1
           ((n << 24) & 0xff000000); // Byte 0 -> 3
}
```
Reverse Bits (位元反轉)
將 10110000 變為 00001101。

```c
uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++) {
        res = (res << 1) | (n & 1);
        n >>= 1;
    }
    return res;
}
```

💡 關鍵筆記與陷阱預防
1. 使用 1U：務必加上 U 綴字（Unsigned），避免 Signed Integer 在左移時因為符號位元引發未定義行為（Undefined Behavior）。

2. 優先級 (Priority)：位元運算的優先級（如 &, |, ^）極低，甚至低於 ==。在巨集或表達式中請**「括號加滿」**。

3. Volatile：當操作硬體寄存器時，必須確保該指標指向的型別有 volatile 修飾，防止編譯器優化掉重複的讀寫。