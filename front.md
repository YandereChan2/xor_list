# `Yc::xor_list<T,Allocator>::front`

|||
|:-|:-|
|`reference front();`|(1)|
|`const_reference front()const;`|(2)|

返回到容器首元素的引用。

在空容器上对 `front` 的调用是未定义的。

## 参数

（无）

## 返回值

到首元素的引用。

## 复杂度

常数。

## 注解

对于容器 `c` ，`c.front()` 等价于 `*c.begin()` 。
