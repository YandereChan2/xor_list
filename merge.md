# `Yc::xor_list<T,Allocator>::merge`

|||
|:-|:-|
|`void merge( list& other );`|(1)|
|`void merge( list&& other );`|(2)|
|`template< class Compare >`<br>`void merge( list& other , Compare comp);`|(3)|
|`template< class Compare >`<br>`void merge( list&& other , Compare comp);`|(4)|

如果 `other` 与 `*this` 指代同一对象，那么什么也不做。

否则，将 `other` 合并到 `*this`。两个 `xor_list` 都应有序。不复制元素，并且在操作后容器 `other` 会变为空。此操作是稳定的：对于两个链表中的等价元素，来自 `*this` 的元素始终在来自 `other` 的元素之前，并且不更改 `*this` 和 `other` 的等价元素顺序。

引用不会失效，但是几乎所有迭代器都会失效，除了 _`before_begin()`_ 和 _`after_end()`_ 决不失效。指向或指代从 `other` 移走的元素的指针、引用和侥幸未失效的迭代器将不再涉及 `other` ，而是会指代 `*this` 中的相同元素。

- (1,2) 用 `std::less<>()` 比较元素。
- (3,4) 用 `comp` 比较元素。
如果 `other` 或 `*this` 没有按对应的比较器有序，或者 `get_allocator() != other.get_allocator()` ，那么行为未定义。

## 参数

||||
|-:|-|:-|
|`other`|-|要交换的另一容器。|
|`comp`|-|比较函数对象（即满足[_比较 (Compare)_](https://zh.cppreference.com/w/cpp/named_req/Compare) 概念的对象），在第一参数小于（即先序于）第二参数时返回 ​true。<br>比较函数的签名应等价于如下：<br>`bool cmp(const Type1 &a, const Type2 &b);`<br>虽然签名不必有 `const&`，函数也不能修改传递给它的对象，而且必须接受（可为 `const` 的）类型 `Type1` 与 `Type2` 的值，无关乎值类别。类型 `Type1` 与 `Type2` 必须使得 `xor_list<T,Allocator>::const_iterator` 类型的对象能在解引用后隐式转换到这两个类型。|

### 类型要求

- Compare 必须满足[_比较 (Compare)_](https://zh.cppreference.com/w/cpp/named_req/Compare) 。

## 返回值

（无）

## 复杂度

如果 `other` 与 `*this` 指代同一对象，那么不会进行比较。

否则给定 $N$ 为 `std::distance(begin(), end())`，$R$ 为 `std::distance(other.begin(), other.end())`：

- (1,2) 应用最多 $N+R−1$ 次 `operator<` 进行比较。

- (3,4) 应用最多 $N+R−1$ 次比较函数 `comp` 。

## 异常

除非比较操作内部发生异常，否则此函数决不抛出异常（前文省略了该函数的 `noexcept` 说明符）。如果比较操作抛出异常，保证 `other` 与 `*this` 处于某个合法状态。
