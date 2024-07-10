# `Yc::xor_list<T,Allocator>::~xor_list`

|||
|:-|:-|
|`~xor_list();`||

销毁 xor_list。调用各元素的析构函数，然后解分配所用的存储。注意，若元素是指针，则不销毁所指向的对象。

## 复杂度

与 `std::distance(begin(),end())` 成线性。
