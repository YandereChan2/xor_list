# `Yc::xor_list<T,Allocator>::rend,crend`

|||
|:-|:-|
|`iterator rend()noexcept;`|(1)|
|`const_iterator rend()const noexcept;`|(2)|
|`const_iterator crend()const noexcept;`|(3)|

返回指向逆向的 `xor_list` 末元素后一元素的逆向迭代器。它对应非逆向 `xor_list` 首元素的前一元素。此元素表现为占位符，试图访问它导致未定义行为。

注意这里的返回类型是 `iterator` ，事实上 `xor_list` 的 `reverse_iterator` 类型就是 `iterator` 。具体细节参见迭代器的介绍。

## 参数

（无）

## 返回值

指向首元素前一元素的逆向迭代器。

## 复杂度

常数。
