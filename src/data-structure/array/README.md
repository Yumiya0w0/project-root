# Array 
## Note
### Array on Stack
```cpp
#include <array>

std::array<int, 5> a1;              // 未初始化
std::array<int, 5> a2 = {1, 2, 3};  // 部分初始化，其餘補 0
std::array<int, 5> a3{0};           // a3[0]=0, 其餘補 0 (注意：不能用 {-1} 初始化全部)

// 推薦方式
a1.fill(-1);                        // 將所有元素設為 -1
```
```cpp
// 在 Stack 上分配
int arr1[5];                 // 未初始化 (內容是隨機值/垃圾值)
int arr2[5] = {1, 2, 3, 4, 5}; // 完全初始化
int arr3[5] = {1, 2};        // 部分初始化，其餘自動補 0: {1, 2, 0, 0, 0}
int arr4[5] = {0};           // 全員補 0 (最常用)
int arr5[] = {1, 2, 3};      // 自動推導長度為 3
```
### Dynamic Array
```cpp
// C 風格
int* d_arr = (int*)malloc(5 * sizeof(int));
free(d_arr);

// C++ 風格
int* cpp_arr = new int[5]();        // 加括號 () 會初始化為 0
int* cpp_arr2 = new int[5]{1,2,3};  // 初始化特定值
delete[] cpp_arr;                   // 記得使用 delete[]

// 現代 C++ 推薦 (自動管理記憶體)
#include <vector>
std::vector<int> v(5, -1);          // 大小為 5，全部初始化為 -1
vec.reserve(size); //這會預先在 Heap 拿好空間，避免多次搬移資料產生的效能損耗。
```
## static 的使用方法與場景
在 C/C++ 中，static 是一個「一詞多義」的關鍵字。根據它出現的位置，其作用完全不同。

A. 靜態區域變數 (Static Local Variable)
位置：定義在函式內部。

作用：變數的生命週期貫穿整個程式（存在 Data 或 BSS 段），但可見範圍僅限該函式。它會「記憶」上次執行的結果。

場景：計數器或單例模式 (Singleton) 的延遲初始化。

```cpp
void interruptHandler() {
    static int eventCount = 0; // 只在第一次呼叫時初始化
    eventCount++;
    // 紀錄這個中斷觸發了幾次，即使函式結束，數值也不會消失
}
```
B. 靜態全域變數 / 函式 (Static Global / Function)
位置：定義在 .c 或 .cpp 檔案的最外層，不屬於任何類別。

作用：隱藏符號 (Internal Linkage)。該變數或函式只能在「目前的檔案」內被存取，其他 .c 檔看不到它。

場景：封裝 (Encapsulation)。在開發驅動程式時，為了避免函式名稱與其他模組衝突（例如大家都有 init()），加上 static 可以防止符號外洩。

```cpp
// 在 i2c_driver.c 中
static void reset_hardware() { ... } // 只有這個檔案能用，不怕跟 i2s_driver.c 衝突
```

C. 類別中的靜態成員 (Static Class Member)
位置：定義在 class 或 struct 內。

作用：該變數不屬於任何「實例 (Instance)」，而是屬於「類別」本身。所有物件共享同一個變數。

場景：資源管理。例如紀錄目前有多少個物件被建立，或者定義全類別通用的常數。

D. 類別中的靜態函式 (Static Class Method)
位置：定義在 class 內。

作用：該函式沒有 this 指標，不能存取非靜態成員。

場景：工具類函式 (Utility Functions)。例如 Math::sqrt() 或當作中斷的 Callback 進入點（因為中斷不認識 C++ 的物件實例，但認識靜態函式的位址）。

## static inline
結合了 static（限制作用域） 與 inline（建議展開） 兩者的優點，是提升程式碼效能與模組化程度的利器。
通常我們將 static inline 函式定義在 .h（標頭檔） 之中。

如果只用 inline：
編譯器可能會選擇不展開它。如果多個 .c 檔案都包含這個標頭檔，Linker 可能會因為發現多個相同的函式符號而產生衝突。

如果只用 static：
每個包含該標頭檔的 .c 檔案都會擁有一份該函式的獨立複本。如果函式沒被展開，會浪費 Code Space。

組合技 static inline：
這告訴編譯器：「這個函式是私有的（static），且請盡可能把它直接嵌入到呼叫端（inline）」。如果編譯器決定不展開它，它也會被當作該檔案私有的普通函式處理，不會造成 Linker 符號衝突。

2. 核心優點
A. 取代「帶參數的巨集 (Macro)」
在舊式的 C 語言中，我們會用 #define SQUARE(x) ((x)*(x)) 來節省函式呼叫開銷。但巨集沒有型別檢查，容易出錯。
static inline 提供了與巨集一樣的效能，同時擁有編譯器的型別檢查。

B. 提升效能 (Zero Overhaul)
在嵌入式中，有些函式非常短小（例如讀取某個暫存器的特定位元）。使用 static inline 可以省去：

將參數推入 Stack 的時間。
跳轉指令 (Branch) 的時間。
從函式返回的時間。

C. 更好的優化空間
因為函式碼被嵌入到了呼叫端，編譯器可以結合上下文進行更深入的優化（例如常數摺疊 constant folding）。
