# `Yc::xor_list<T,Allocator>::sort`

|||
|:-|:-|
|`void sort();`|(1)|
|`template< class Compare >`<br>`void sort( Compare comp );`|(2)|

排序元素，并保持等价元素的顺序。

1) 用 `operator<` 比较元素。

2) 用 `comp` 比较元素。

## 参数

||||
|-:|-|:-|
|`comp`|-|比较函数对象（即满足[_比较 (Compare)_](https://zh.cppreference.com/w/cpp/named_req/Compare) 概念的对象），在第一参数小于（即先序于）第二参数时返回 ​true。<br>比较函数的签名应等价于如下：<br><br>`bool cmp(const Type1 &a, const Type2 &b);`<br><br>虽然签名不必有 `const&`，函数也不能修改传递给它的对象，而且必须接受（可为 `const` 的）类型 `Type1` 与 `Type2` 的值，无关乎值类别。类型 `Type1` 与 `Type2` 必须使得 `xor_list<T,Allocator>::const_iterator` 类型的对象能在解引用后隐式转换到这两个类型。​​|

### 类型要求

- `Compare` 必须满足[_比较 (Compare)_](https://zh.cppreference.com/w/cpp/named_req/Compare) 。

## 返回值

（无）

## 复杂度

令 $N$ 为 `size()`：

- (1) 应用大约 $N⋅log(N)$ 次 `operator<` 进行比较。

- (2) 应用大约 $N⋅log(N)$ 次比较函数 `comp` 。

## 迭代器失效

依据实际被移除的元素而定，几乎所有迭代器都会失效，具体规则参见迭代器介绍页面。
