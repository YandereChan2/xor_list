# `Yc::xor_list<T,Allocator>::max_size`

|||
|:-|:-|
|`constexpr static size_type max_size() noexcept;`||

返回容器可保有的元素最大数量，即对于最大容器的 `std::distance(begin(), end())`。

## 参数

（无）

## 返回值

元素数量的最大值

## 复杂度

常数

## 注解

此值为 `std::numeric_limits<size_type>::max()` ，为满足具名要求而设，无实际意义。
