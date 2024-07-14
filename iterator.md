# `Yc::xor_list<T,Allocator>::iterator`

和普通容器的迭代器不一样， `xor_list` 的迭代器必须保有正确的前驱节点（可能是 _`before_begin()`_ ）指针才能寻找到后继节点。这是 XOR 链表的性质所致。

该迭代器满足[_老式双向迭代器 (LegacyBidirectionalIterator)_](https://zh.cppreference.com/w/cpp/named_req/BidirectionalIterator)。

## 成员类型

|成员类型|定义|
|:-|:-|
|`value_type`|`T`|
|`size_type`|`size_t`|
|`difference_type`|`ptrdiff_t`|
|`reference`|`T&`|
|`const reference`|`const T&`|
|`iterator_category`|`std::bidirectional_iterator_tag`|
|_`Node_ptr`_|仅用于阐释的节点指针类型。|

## 数据成员

|类型|成员名|描述|
|:-|:-|:-|
|_`Node_ptr`_|_`last`_|前驱节点的指针<br>（*仅用于阐释）|
|_`Node_ptr`_|_`current`_|当前节点的指针<br>（*仅用于阐释）|

## 成员函数

|||
|:-|:-|
|`operator++`|自增运算符重载<br>（公开成员函数）|
|`operator--`|自减运算符重载<br>（公开成员函数）|
|`operator*`|解引用运算符重载<br>（公开成员函数）|
|`operator->`|成员访问运算符重载<br>（公开成员函数）|
|`operator==`|相等运算符重载<br>（公开成员函数）|
|`turn_around`|改变迭代器方向<br>（公开成员函数）|

## 迭代器失效条件与可解引用迭代器

在链表操作时，如果让原先相邻的元素不再相邻，可能会导致 _`last`_ 不再指向正确的前驱节点，甚至不指向节点。只要 _`current`_ 指针仍指向正确的节点，那么解引用访问依然是良定义的。但是自增自减运算轻则使迭代器处于无效状态，重则引发未定义行为。

只要原容器生命周期没有结束， _`before_begin()`_ 和 _`after_end()`_ 迭代器就一定不失效，且可以用对 `begin()` 或 `end()` 迭代器自减或自增得到。这些迭代器是不可解引用的，且不能进一步的自减或自增。

## 反向迭代器

如果 _`last`_ 指针指向的是实际上的后继节点，那么由于 XOR 链表的性质，此时自增自减操作依然是良定义的。因此， `xor_list` 的迭代器和反向迭代器是同一种类型。 `xor_list::make_reverse_iterator` 实质上执行的是 `std::swap(`_`last`_`,`_`current`_`)` 。
