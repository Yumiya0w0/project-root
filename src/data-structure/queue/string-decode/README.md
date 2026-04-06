給予一個經過編碼的字串，請回傳它解碼後的字串。
編碼規則為：k[encoded_string]，表示方括號內部的 encoded_string 正好重複 k 次。注意 k 保證為正整數。

範例：
輸入：`s = "3[a]2[bc]"`
輸出："aaabcbc"

輸入：`s = "3[a2[c]]"`
輸出："accaccacc" (嵌套情況)

# Note
These operation are in pair. 
- `[`: push
- `]`: top and pop and set zero
- Final result is settled as current in end of `]`,
    so return current.
- `decoded`: Don't forget to concate previous string