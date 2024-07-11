# `Yc::xor_list<T,Allocator>::erase`

|||
|:-|:-|
|`iterator erase( const_iterator pos );`||

从容器擦除位于 `pos` 的元素。

迭代器 `pos` 必须合法且可解引用，因此不能以 `end()` 迭代器（合法，但不可解引用）作为 `pos` 的值。

`pos` 迭代器会失效。且预先求值的 `std::next(pos)` ， `make_reverse_iterator(pos)` ，`std::next(make_reverse_iterator(pos))` 也会失效。

`pos` 可以是同类型的反向迭代器。

## 参数

||||
|-:|-|:-|
|`pos`|-|指向要移除的元素的迭代器|

## 返回值

移除元素之后的同方向迭代器，可能是 `end()` 或 `rend()` 。

## 复杂度

常数。

## 异常

（无）
