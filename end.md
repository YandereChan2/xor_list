# `Yc::xor_list<T,Allocator>::end,cend`

|||
|:-|:-|
|`iterator end()noexcept;`|(1)|
|`const_iterator end()const noexcept;`|(2)|
|`const_iterator cend()const noexcept;`|(3)|

返回指向 `xor_list` 末元素后一元素的迭代器。

此元素表现为占位符；试图访问它导致未定义行为。

## 参数

（无）

## 返回值

指向后随最后元素的迭代器。

## 复杂度

常数。
