# `Yc::xor_list<T,Allocator>::rbegin,crbegin`

|||
|:-|:-|
|`iterator rbegin()noexcept;`|(1)|
|`const_iterator rbegin()const noexcept;`|(2)|
|`const_iterator crbegin()const noexcept;`|(3)|

返回指向逆向的 `xor_list` 的首元素的逆向迭代器。它对应非逆向 `xor_list` 的末元素。如果 `xor_list` 为空，那么返回的迭代器等于 `rend()` 。

注意这里的返回类型是 `iterator` ，事实上 `xor_list` 的 `reverse_iterator` 类型就是 `iterator` 。具体细节参见迭代器的介绍。

## 参数

（无）

## 返回值

指向末元素的逆向迭代器。

## 复杂度

常数。
