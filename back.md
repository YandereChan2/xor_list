# `Yc::xor_list<T,Allocator>::back`

|||
|:-|:-|
|`reference back();`|(1)|
|`const_reference back()const;`|(2)|

返回到容器末尾元素的引用。

在空容器上对 `back` 的调用是未定义的。

## 参数

（无）

## 返回值

到末尾元素的引用。

## 复杂度

常数

## 注解

对于容器 `c` ，`c.back()` 等价于 `*std::prev(c.begin())` 。
