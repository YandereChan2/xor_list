# `Yc::xor_list<T,Allocator>::insert`

|||
|:-|:-|
|`iterator insert( const_iterator pos, const T& value );`|(1)|
|`iterator insert( const_iterator pos, T&& value );`|(2)|

插入元素到容器中 `pos` 前的位置。

`pos`可以是 `iterator` 或 `const_iterator` 类型的反向迭代器，此时插入的位置在 `pos` 的后面。

`pos` 迭代器会失效。且预先求值的 `make_reverse_iterator(pos)` 也会失效。

## 参数

||||
|-:|-|:-|
|`pos`|-|将内容插入到它前面的迭代器。 `pos` 可以是 `end()` 或者 `rend()` 迭代器。|
|`value`|-|要插入的元素值。|

## 返回值

指向被插入 `value` 的迭代器。迭代器的方向与 `pos` 保持一致。

## 复杂度

常数。

## 异常

若抛出了异常（可能因为 `Allocator::allocate()` 或元素复制/移动构造函数/赋值），则保留容器不修改，如同未曾调用过此函数（强异常保证）。
