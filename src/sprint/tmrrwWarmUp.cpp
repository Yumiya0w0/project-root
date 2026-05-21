// 2. 記憶體操作：My Memcpy (Handling Alignment)
// 目標：實作一個考慮到 4-byte 對齊搬移的 memcpy。
void* myMemcpy(void* dest, const void* src, size_t n) 
{
    uint8_t* d8 = (uint8_t*) dest;
    const uint8_t* s8 = (const uint8_t*) src;
    // align
    while(n>0 && (d8 & 3)>0)
    {
        *d8++ = *s8++;
        n--;
    }
    uint32_t* d32 = (uint32_t*) d8;
    const uint32_t* s32 = (const uint32_t*) s8;
    for(int i = 0; i < n/4; i++)
    {
        *d32++ = *s32++;...
    }
    n = n %4;
}

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < 32; i++)
    {
        int count = 0;
        for(int n: nums)
        {
            if(n & (1U << i)) { count++; }
        }
        ans |= ((count%3) << i);
    }
    return ans;
}

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < 32; ++i) {
        int count = 0;
        // 統計第 i 位元在所有數字中出現 1 的總次數
        for (int x : nums) {
            if ((x >> i) & 1) count++;
        }
        // 如果 count 不能被 3 整除，說明答案的第 i 位是 1
        if (count % 3 != 0) {
            ans |= (1U << i);
        }
    }
    return ans;
}

// Remove Duplicates from Sorted Array
int removeDuplicates(vector<int>& nums)
{
    if(nums.empty()) return 0;
    int write_pos = 1; // pos to write
    for(int read_pos = 1; read_pos < nums.size(); read_pos++)
    {
        if(nums[write_pos-1] != nums[read_pos] )
        {
            nums[write_pos++] = nums[read_pos];
        }
    }
    return write_pos;
}

int removeDuplicatesAtMostTwice(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    
    int w = 2; // 前兩個元素不管怎樣都可以留下
    for (int r = 2; r < nums.size(); r++) {
        if(nums[w-1] != nums[r] || nums[w-2] != nums[r])
        {
            nums[w++] = nums[r];
        }
    }
    return w;
}