# `Yc::xor_list<T,Allocator>::unique`

|||
|:-|:-|
|`size_type unique();`|(1)|
|`template< class BinaryPredicate >`<br>`size_type unique( BinaryPredicate p );`|(2)|

从容器移除所有相继的重复元素。只留下相等元素组中的第一个元素。

- (1) 用 `operator==` 比较元素。

- (2) 用二元谓词 `p` 比较元素。

如果对应的的比较器没有建立等价关系，那么行为未定义。

## 参数

||||
|-:|-|:-|
|`p`|-|若元素应被当做相等则返回 `​true` 的二元谓词。<br>谓词函数的签名应等价于如下：<br><br>`bool pred(const Type1 &a, const Type2 &b);`<br><br>虽然签名不必有 `const &` ，函数也不能修改传递给它的对象，而且必须接受（可为 `const` 的）类型 `Type1` 与 `Type2` 的值，无关乎值类别）。类型 `Type1` 与 `Type2` 必须使得 `xor_list<T,Allocator>::const_iterator` 类型的对象能在解引用后隐式转换到这两个类型。​​|

### 类型要求

- `BinaryPredicate` 必须满足[_二元谓词 (BinaryPredicate)_](https://zh.cppreference.com/w/cpp/named_req/BinaryPredicate)。

## 返回值

移除的元素数。

## 复杂度

当 `empty()` 是 `true` 时不进行比较。

否则，给定 $N$ 为 `std::distance(begin(), end())`：

- (1) 恰好应用 $N − 1$ 次 `operator==` 进行比较。

- (2) 恰好应用 $N − 1$ 次谓词 `p` 。

## 迭代器失效

依据实际被移除的元素而定，具体规则参见迭代器介绍页面。
