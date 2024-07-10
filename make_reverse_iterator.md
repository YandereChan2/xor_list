# `Yc::xor_list<T,Allocator>::make_reverse_iterator`

|||
|:-|:-|
|`constexpr static iterator make_reverse_iterator(iterator it) noexcept;`|(1)|
|`constexpr static const_iterator make_reverse_iterator(const_iterator it) noexcept;`|(2)|

构造指向迭代器 `it` 所指向的元素的上一个元素（即 `--it` 所指向的元素）的反向迭代器。

## 参数

||||
|-:|-|:-|
|`it`|-|源迭代器|

## 返回值

指向 `it` 前驱元素的反向迭代器。如果 `it` 已经是反向迭代器，那么返回的是正向迭代器。如果 `it == begin()` ，那么返回值等于 `rend()` 。对于常量迭代器同理。

## 复杂度

常数

## 注解

因为XOR链表的特殊性，其迭代器和反向迭代器可以使用同一个类型不加区分的表示。因此不必使用 [`std::reverse_iterator`](http://zh.cppreference.com/w/cpp/iterator/reverse_iterator) 构造反向迭代器。
