# `Yc::xor_list<T,Allocator>::remove,remove_if`

|||
|:-|:-|
|`size_type remove( const T& value );`|(1)|
|`template< class UnaryPredicate >`<br>`size_type remove_if( UnaryPredicate p );`|(2)|

移除所有满足特定标准的元素。

- (1) 移除所有等于 `value` 的元素（用 `operator==` 判断）。
- (2) 移除所有谓词 `p` 对它返回 `true` 的元素。

## 参数

||||
|-:|-|:-|
|`value`|-|要移除的元素的值。|
|`p`|-|若应该移除该元素则返回 ​`true` 的一元谓词。<br>对每个（可为 `const` 的） `T` 类型参数 `v` ，表达式 `p(v)` 必须可转换到 `bool` ，无关乎值类别，而且必须不修改 `v` 。从而不允许 `T&` 类型参数，亦不允许 `T` ，除非对 `T` 而言移动等价于复制。​|

### 类型要求

- `UnaryPredicate` 必须满足[_谓词(Predicate)_](https://zh.cppreference.com/w/cpp/named_req/Predicate) 。

## 返回值

移除的元素数。

## 复杂度

给定 $N$ 为 `std::distance(begin(), end())`：

1) 应用 $N$ 次 `operator==` 进行比较。
2) 应用 $N$ 次谓词 `p` 。

## 迭代器失效

依据实际被移除的元素而定，具体规则参见迭代器介绍页面。
