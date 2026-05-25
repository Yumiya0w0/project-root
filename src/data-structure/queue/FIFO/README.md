設計一個環形緩衝區 (Design Circular Queue)

不使用 STL（因為這題常考在無 Heap 環境），請利用 Array 實作一個固定大小的 Circular Queue。
你需要實作以下介面：

enQueue(int value)：加入元素，成功回傳 true，滿了回傳 false。

deQueue()：刪除元素，成功回傳 true，空了回傳 false。

Front()：取得最前面的元素，若空則回傳 -1。

Rear()：取得最後面的元素，若空則回傳 -1。

isEmpty() 與 isFull()。