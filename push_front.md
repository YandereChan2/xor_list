# `Yc::xor_list<T,Allocator>::push_front`

|||
|:-|:-|
|`void push_front( const T& value );`|(1)|
|`void push_front( T&& value );`|(2)|

追加给定元素 `value` 到容器头部。

- (1) 初始化新元素为 `value` 的副本。

- (2) 移动 `value` 进新元素。

`begin()` 迭代器和 `rend()` 迭代器会失效。

## 参数

||||
|-:|-|:-|
|`value`|-|要追加的元素值。|

### 类型要求

- 为使用重载 (1)， T 必须满足[_可复制插入 (CopyInsertable)_](https://zh.cppreference.com/w/cpp/named_req/CopyInsertable) 。
- 为使用重载 (2)， T 必须满足[_可移动插入 (MoveInsertable)_](https://zh.cppreference.com/w/cpp/named_req/MoveInsertable) 。

## 返回值

（无）

## 复杂度

常数。

## 异常

若抛出了异常（可能因为 `Allocator::allocate()` 或元素复制/移动构造函数/赋值），则保留容器不修改，如同未曾调用过此函数（强异常保证）。
