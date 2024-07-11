# `Yc::swap(Yc::xor_list)`

|||
|:-|:-|
|`template<class T,class Allocator>`<br>`void swap(xor_list<T,Alloc>& l,void swap(xor_list<T,Alloc>& r)noexcept(/*见下文*/);`||

交换l和r的内容。调用成员函数版的 `l.swap(r)` 。此非成员函数版本主要供 [adl](https://zh.cppreference.com/w/cpp/language/adl) 使用。

## 参数

||||
|-:|-|:-|
|`l` , `r`|-|要交换内容的容器。|

## 返回值

（无）

## 复杂度

常数。

## 异常

`noexcept` 说明：  
`noexcept(noexcept(lhs.swap(rhs)))`
