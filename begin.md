# `Yc::xor_list<T,Allocator>::begin,cbegin`

|||
|:-|:-|
|`iterator begin()noexcept;`|(1)|
|`const_iterator begin()const noexcept;`|(2)|
|`const_iterator cbegin()const noexcept;`|(3)|

返回指向 `xor_list` 首元素的迭代器。

如果 `xor_list` 为空，那么返回的迭代器等于 `end()` 。

## 参数

（无）

## 返回值

指向首元素的迭代器。

## 复杂度

常数。
