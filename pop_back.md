# `Yc::xor_list<T,Allocator>::pop_back`

|||
|:-|:-|
|`void pop_back();`||

移除容器的末元素。

在空容器上调用 `pop_back` 导致未定义行为。

末元素迭代器， `end()` 迭代器，`rbegin()` 迭代器，`std::next(rbegin())` 迭代器，都会失效。

## 参数

（无）

## 返回值

（无）

## 复杂度

常数。
