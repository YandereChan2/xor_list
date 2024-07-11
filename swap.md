# `Yc::xor_list<T,Allocator>::swap`

|||
|:-|:-|
|`void swap( list& other ) noexcept(/* 见下文 */);`||

将内容与 `other` 的交换。不在单独的元素上调用任何移动、复制或交换操作。

除非 `*this` 和 `other` 指代同一个 `xor_list` ，否则两个 `xor_list` 的 `begin()` ， `end()` ， `rend()` ， `rbegin()` 迭代器都会失效。

## 参数

||||
|-:|-|:-|
|`other`|-|要与之交换内容的容器。|

## 返回值

（无）

## 复杂度

常数。

## 异常

`noexcept` 说明：  
`noexcept(std::allocator_traits<Allocator>::is_always_equal::value)`
