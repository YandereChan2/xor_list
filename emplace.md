# `Yc::xor_list<T,Allocator>::emplace`

|||
|:-|:-|
|`template<class... Args>`<br>`iterator emplace( const_iterator pos, Args&&... args );`||

在紧接 `pos` 之前的位置向容器插入新元素

`pos`可以是 `iterator` 或 `const_iterator` 类型的反向迭代器，此时插入的位置在 `pos` 的后面。

通过 [`std::allocator_traits::construct`](https://zh.cppreference.com/w/cpp/memory/allocator_traits/construct) 构造元素，用 `placement new` 在容器提供的位置原位构造元素。

将实参 `args...` 作为 [`std::forward`](http://zh.cppreference.com/w/cpp/utility/forward)`<Args>(args)...` 转发给构造函数。 `args...` 可以直接或间接地指代容器中的值。

`pos` 迭代器会失效。且预先求值的 `make_reverse_iterator(pos)` 也会失效。

## 参数

||||
|-:|-|:-|
|`pos`|-|将内容插入到它前面的迭代器。 `pos` 可以是 `end()` 或者 `rend()` 迭代器。|
|`args`|-|转发给元素构造函数的实参。|

### 类型要求

- `T`（容器的元素类型） 必须满足[_可就位构造 (EmplaceConstructible)_](https://zh.cppreference.com/w/cpp/named_req/EmplaceConstructible) 。

## 返回值

指向被安置的元素的迭代器。迭代器的方向与 `pos` 保持一致。

## 复杂度

常数。

## 异常

若抛出了异常（例如由构造函数），则保留容器不修改，如同未曾调用过此函数（强异常保证）。
