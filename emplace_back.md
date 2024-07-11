# `Yc::xor_list<T,Allocator>::emplace_back`

|||
|:-|:-|
|`template<class...Args> T& emplace_back( Args&&... args );`||

添加新元素到容器尾。元素通过 [`std::allocator_traits::construct`](https://zh.cppreference.com/w/cpp/memory/allocator_traits/construct) 构造，通常用 `placement new` 于容器所提供的位置原位构造元素。实参 `args...` 以 [`std::forward`](http://zh.cppreference.com/w/cpp/utility/forward)`<Args>(args)...` 转发到构造函数。

`end()` 迭代器和 `rbegin()` 迭代器会失效。

## 参数

||||
|-:|-|:-|
|`args`|-|转发到元素构造函数的实参。|

### 类型要求

- `T`（容器的元素类型） 必须满足[_可就位构造 (EmplaceConstructible)_](https://zh.cppreference.com/w/cpp/named_req/EmplaceConstructible) 。

## 返回值

到被插入元素的引用。

## 复杂度

常数。

## 异常

若抛出了异常，则保留容器不修改，如同未曾调用过此函数（强异常保证）。
