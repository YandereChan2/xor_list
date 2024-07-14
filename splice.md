# `Yc::xor_list<T,Allocator>::splice`

|||
|:-|:-|
|`/*未指定*/ splice( const_iterator pos,const_iterator first, const_iterator last)noexcept;`|(1)|
|`iterator splice( const_iterator pos, xor_list& other)noexcept;`|(2)|
|`iterator splice( const_iterator pos, xor_list& other)noexcept;`|(3)|

从一个 `xor_list` 转移元素给另一个。

不复制或移动元素，仅对 XOR 链表结点的内部指针进行重指向。没有引用会失效，但现在指代到 `*this` 中，而不是到 `other` 中。

- (1)把范围 $[$ `first`,`last` $)$ 中的元素移动到 `pos` 前。保证在 `first()==last()` 时无操作。
- (2,3)把 `other` 中全部元素移动到 `pos` 前。操作后 `other` 为空。

在以下情况下行为未定义：

- `get_allocator() != other.get_allocator()`。

- 对于重载 (1)：

  - $[$ `first` , `last` $)$ 不是有效范围。

  - `pos` 在 $[$ `first` , `last` $)$ 中。
- 对于重载（2,3）:
  - `pos` 在 `other` 中。

严格来说，并未规定 `pos` 是 `*this` 中的迭代器，但是出于语义明确的角度考虑， `pos` 最好是 `*this` 中的迭代器。

## 参数

||||
|-:|-|:-|
|`pos`|-|将插入内容到它之前的元素。|
|`first, last`|-|要转移的元素范围。|
|`other`|-|要清空的容器。|

## 返回值

- (1)匿名结构体，保证可以被结构化绑定 `auto [pos,first,last]` 承接，其中`pos` ，`first` ， `last` 为指向同名参数的迭代器所指向的元素的新迭代器。（见下文迭代器失效）

- (2,3)指向 `pos` 所指向元素的新迭代器。

## 复杂度

常数。

## 异常

不抛出。

## 迭代器失效

两个重载传入的迭代器都会失效，可以通过返回值获取正确的迭代器。
