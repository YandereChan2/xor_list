# `Yc::xor_list<T,Allocator>::pop_front`

|||
|:-|:-|
|`void pop_front();`||

移除容器的首元素。

在空容器上调用 `pop_front` 导致未定义行为。

 `begin()` 迭代器，`std::next(begin())` 迭代器，`rend()` 迭代器，`std::prev(rend())` 迭代器都会失效。

## 参数

（无）

## 返回值

（无）

## 复杂度

常数。
