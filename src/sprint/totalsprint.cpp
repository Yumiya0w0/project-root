// 🚀 20 分鐘肌肉記憶清單
// 1. 位元運算：Count Set Bits (Brian Kernighan)
// 目標：計算 n 的二進位中有多少個 1。

// int countSetBit(uint32_t& val)
int countSetBit(uint32_t val)
{
    uint32_t n = val;
    int count = 0;
    while(n)
    {
        n &= (n-1);
        count++;
    }
    return count;
}

// 2. 記憶體操作：My Memcpy (Handling Alignment)
// 目標：實作一個考慮到 4-byte 對齊搬移的 memcpy。
void* myMemcpy(void* dest, const void* src, size_t n) {
    uint32_t* d32 = (uint32_t*)dest;
    const uint32_t* s32 = (const uint32_t*)src;
    
    // 1. 先處理 4-byte 對齊的部分
    size_t words = n / 4;
    for (size_t i = 0; i < words; i++) {
        d32[i] = s32[i];
    }
    
    // 2. 處理剩下的餘數 (n % 4)
    uint8_t* d8 = (uint8_t*)(d32 + words);
    const uint8_t* s8 = (const uint8_t*)(s32 + words);
    size_t rem = n % 4;
    for (size_t i = 0; i < rem; i++) {
        d8[i] = s8[i];
    }
    return dest;
}

// 3. 陣列/指標：Reverse String / Array (In-place)
// 目標：原地翻轉一個陣列或字串。

void reverseArray(array<int, 128>& arr, int size)
{
    int steps = size/2;
    /* while (l < r) swap(arr[l++], arr[r--]); */
    for(int i = 0; i < steps; i++)
    {
        swap(arr[i], arr[size-i-1]);
    }
}

// 4. 鍊錶基礎：Linked List Cycle Detection
// 目標：判斷一個 Linked List 是否有環。
class LinkList
{
    LinkList* next;
    int val;
}
using LL = LinkList;
bool llHasCycle(LL* head)
{
    LL* fast = head;
    LL* slow = head;
    while(fast && fast->next) // && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) return true;
    }
    return false;
}

// 5. 寄存器操作：Field Update (Masking)
// 目標：給定 reg, val, start_bit, end_bit，更新該區間的值且不影響其他位元。
void setField(uint32_t reg, uint32_t val, int start, int end)
{
    // assume that all input are valid
    // start is lower than end
    // trim val
    uint32_t mask = ~0U << (end-start+1); // 111..000..
    val &= (~mask);
    // zero out the field
    reg &= (mask << start);
    reg |= (val << start);
}

// Need review
uint32_t setField(uint32_t reg, uint32_t val, int start, int end) {
    // 1. 生成區間遮罩。例如 start=4, end=7 -> 0xF0
    uint32_t range_mask = ((1U << (end - start + 1)) - 1) << start;
    
    // 2. 把 reg 的目標區間清零
    reg &= ~range_mask;
    
    // 3. 把 val 移到正確位置並確保它不會溢出到區間外
    uint32_t val_to_insert = (val << start) & range_mask;
    
    return reg | val_to_insert;
}