
# `Yc::xor_list`

在标头`"xor_list.h"`定义。

```C++
template<
            class T
            class Allocator = std::allocator<T>
        >class xor_list
```

`Yc::xor_list` 是支持从容器任何位置进行常数时间的元素插入和移除的容器。不支持快速随机访问。它实现为XOR链表。与 `std::list` 相比，此容器空间利用率稍高，和 `std::forward_list` 相当。但是更容易触发迭代器失效。

在 `Yc::xor_list` 内或在数个 `Yc::xor_list` 间添加、移除和移动元素不会使引用失效。但是只要有任意两个相邻的元素分开，或者其中一个元素消失，或者头尾元素的位置发生变动，指向这些元素的迭代器都会失效。

`Yc::xor_list` 满足[_容器 (Container)_](https://zh.cppreference.com/w/cpp/named_req/Container)，[_序列容器 (SequenceContainer)_](https://zh.cppreference.com/w/cpp/named_req/SequenceContainer)，及[_可逆容器 (ReversibleContainer)_](https://zh.cppreference.com/w/cpp/named_req/ReversibleContainer)要求。目前尚不满足[_知分配器容器 (AllocatorAwareContainer)_](https://zh.cppreference.com/w/cpp/named_req/AllocatorAwareContainer)，将在日后满足。

## 模板参数

| | |
|:-----|:-----|
|`T`|元素的类型，至少应当满足[_可擦除 (Erasable)_](https://zh.cppreference.com/w/cpp/named_req/Erasable)，但是一些函数提出了更高的要求。|
|`Allocator`|用于获取/释放内存及构造/析构内存中元素的分配器。类型必须满足[_分配器 (Allocator)_](https://zh.cppreference.com/w/cpp/named_req/Allocator)。|

## 成员类型

|成员类型|定义|
|:-|:-|
|`value_type`|`T`|
|`allocator_type`|`Allocator`|
|`difference_type`|`ptrdiff_t`|
|`reference`|`T&`|
|`const reference`|`const T&`|
|`iterator`|指向 `value_type` 的[_老式双向迭代器 (LegacyBidirectionalIterator)_](https://zh.cppreference.com/w/cpp/named_req/BidirectionalIterator)|
|`const_iterator`|指向 `const value_type` 的[_老式双向迭代器 (LegacyBidirectionalIterator)_](https://zh.cppreference.com/w/cpp/named_req/BidirectionalIterator)|
|`reverse_iterator`|`iterator`|
|`const_reverse_iterator`|`const_iterator`|

## 成员函数

|||
|:-|:-|
|（构造函数）|构造 `xor_list` <br>（公开成员函数）|
|（析构函数）|析构 `xor_list` <br>（公开成员函数）|

### 元素访问

|||
|:-|:-|
|`front`|访问第一个元素<br>（公开成员函数）|
|`back`|访问最后一个元素<br>（公开成员函数）|

### 迭代器

|||
|:-|:-|
|`begin`<br>`cbegin`|返回指向起始的迭代器<br>（公开成员函数）|
|`end`<br>`cend`|返回指向末尾的迭代器<br>（公开成员函数）|
|`rbegin`<br>`crbegin`|返回指向起始的逆向迭代器<br>（公开成员函数）|
|`rend`<br>`crend`|返回指向末尾的逆向迭代器<br>（公开成员函数）|
|`make_reverse_iterator`|从迭代器构造同类型的反向迭代器，指向原迭代器的上一个元素（静态公开成员函数）|

### 容量

|||
|:-|:-|
|`empty()`|检查容器是否为空<br>（公开成员函数）|

### 修改器

|||
|:-|:-|
|`clear`|清除内容<br>（公开成员函数）|
|`insert`|插入元素<br>（公开成员函数）|
|`emplace`|原位构造元素<br>（公开成员函数）|
|`erase`|擦除元素<br>（公开成员函数）|
|`push_back`|将元素添加到容器末尾<br>（公开成员函数）|
|`emplace_back`|在容器末尾原位构造元素<br>（公开成员函数）|
|`pop_back`|移除末元素<br>（公开成员函数）|
|`push_front`|插入元素到容器起始<br>（公开成员函数）|
|`emplace_front`|在容器头部原位构造元素<br>（公开成员函数）|
|`pop_front`|移除首元素<br>（公开成员函数）|
|`swap`|交换内容<br>（公开成员函数）|

### 操作

|||
|:-|:-|
|`merge`|合并两个有序列表<br>（公开成员函数）|
|`splice`|从另一个 `xor_list` 中移动元素<br>（公开成员函数）|
|`remove`<br>`remove_if`|移除满足特定标准的元素<br>（公开成员函数）|
|`reverse`|反转元素的顺序<br>（公开成员函数）|
|`unique`|删除连续的重复元素<br>（公开成员函数）|

### 非成员函数

|||
|:-|:-|
|`operator==`<br>`operator<=>`（尚未实现）|按照字典顺序比较两个 `xor_list` 的值<br>（函数模板）|
|`Yc::swap`|交换内容（函数模板）|