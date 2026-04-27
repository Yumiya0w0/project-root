// 1. 寄存器操作 (The Basics)
// 這是 BMC 開發者的日常，絕對不能寫錯。

// Set Bit: 
reg |= (1U << n)
// Clear Bit:  
reg &= ~(1U << n)
// Toggle Bit:
reg ^= (1U << n)
// Check Bit: 
reg &= (1U << n)

// 2. 判斷 Power of 2 (The Trick)
// 這招在檢查 Buffer 大小對齊時經常用到。
if(reg & (reg -1) == 0) // !!
bool isPowOfTwo(uint32_t reg){
 return (reg != 0) && ((reg & (reg-1)) == 0);
}

// 3. 計算 1 的個數 (Popcount - Kernighan's)
// 不要一個一個 Shift，要學會跳著走。
int countSetBits(uint32_t& n)
{
    uint32_t reg = n;
    int count = 0;
    // while((reg != 0) && (reg & (reg-1)))
    while(reg)
    {
        reg &= (reg-1);
        count++;
    }
    return count;
}
// 4. 向上對齊 (Alignment)
// 假設 align 是 2 的冪次（例如 64, 4096）。

// C++
// #define ALIGN(addr, align) (((addr) + (align) - 1) & ~((uintptr_t)(align) - 1))
// 註：這行要寫得很順，特別是 ~((align) - 1)。
// 公式拆解：(((addr) + (align) - 1) & ~((align) - 1))
// 我們可以把這個公式分成兩部分來看：「加法補位」與「遮罩截斷」。
// 第一部分：
// (addr + align - 1) 
// —— 確保進位這步的目的是：除了已經對齊的數字外，強迫所有數字「進位」到下一個對齊區間。
// 如果 addr 已經對齊（是 align 的倍數），加 align - 1 不會讓它跨過下一個倍數門檻。
// 如果 addr 多出了哪怕只有 1，加 align - 1 就會讓它達到或超過下一個倍數。
// 第二部分：& ~(align - 1) 
// —— 捨去餘數這步是位元運算的精華。
// 前提是 align 必須是 2 的冪次（如 2, 4, 8, 16...）。
// 假設 align = 8 ($2^3$)，二進位是 ...00001000。
// align - 1 = 7，二進位是 ...00000111。
// ~(align - 1) 就是 ...11111000。
// 與這個遮罩做 AND (&)，效果就是：把低位的 3 個 bit 強制清零。

// mask = ~(align-1)
#define ALIGN(addr, align) ((addr)+(align)-1) & (~((uintptr_t)(align)-1))

// 5. 獲取最低位的 1 (Lowbit)
// 用於各種索引尋找。
uint32_t lowBit(uint32_t n) { return n & (-n); }
int lowBitIndex(uint32_t reg)
{
    // or just built in ctz
    if(!reg) return -1;
    int count = 0;
    while(!(reg & 1U))
    {
        reg >>= 1;
        count++;
    }
    return count;
}

// 💡 複習小叮嚀
// 括號：在寫 #define 或複雜表達式時，括號多加沒關係，少加會出事（尤其是 & 的優先級比 == 低）。

// 1U：永遠記得加上 U。