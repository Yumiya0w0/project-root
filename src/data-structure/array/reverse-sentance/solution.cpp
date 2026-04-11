#include <string>
#include <iostream>
// 使用 static inline 提升效能，並改用指標或索引
static inline void reverseStr(std::string& str, int start, int end) {
    while (start < end) {
        std::swap(str[start++], str[end--]);
    }
}

void reverseSentence(std::string& str) {
    if (str.empty()) return;

    // Step 1: 翻轉整個字串
    reverseStr(str, 0, (int)str.size() - 1);

    // Step 2: 翻轉每個單字
    int n = str.size();
    int start = 0;
    while (start < n) {
        // 跳過開頭空格
        while (start < n && str[start] == ' ') start++;
        if (start >= n) break;

        // 找單字結尾
        int end = start;
        while (end < n && str[end] != ' ') end++;

        // 翻轉該單字 (注意：end 此時在空格上，所以要 -1)
        reverseStr(str, start, end - 1);
        start = end;
    }
}