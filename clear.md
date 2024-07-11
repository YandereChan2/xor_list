# `Yc::xor_list<T,Allocator>::clear`

|||
|:-|:-|
|`void clear();`||

从容器擦除所有元素。

使任何指代所含元素的引用、指针和迭代器失效。除非 `xor_list` 原先本来就为空，否则 `begin()` 和 `end()` 也失效。但是 _`before_begin()`_ 和 _`after_end()`_ 决不失效。

## 参数

（无）

## 返回值

（无）

## 复杂度

和 `std::distance(begin(),end())` 呈线性。
