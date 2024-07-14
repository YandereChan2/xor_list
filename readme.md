
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

`Yc::xor_list` 满足[_容器 (Container)_](https://zh.cppreference.com/w/cpp/named_req/Container)，[_序列容器 (SequenceContainer)_](https://zh.cppreference.com/w/cpp/named_req/SequenceContainer)，及[_可逆容器 (ReversibleContainer)_](https://zh.cppreference.com/w/cpp/named_req/ReversibleContainer)，[_知分配器容器 (AllocatorAwareContainer)_](https://zh.cppreference.com/w/cpp/named_req/AllocatorAwareContainer)要求。

## 模板参数

| | |
|:-----|:-----|
|`T`|元素的类型，至少应当满足[_可擦除 (Erasable)_](https://zh.cppreference.com/w/cpp/named_req/Erasable)，但是一些成员函数提出了更高的要求。|
|`Allocator`|用于获取/释放内存及构造/析构内存中元素的分配器。类型必须满足[_分配器 (Allocator)_](https://zh.cppreference.com/w/cpp/named_req/Allocator)。|

## 成员类型

|成员类型|定义|
|:-|:-|
|`value_type`|`T`|
|`allocator_type`|`Allocator`|
|`size_type`|`size_t`|
|`difference_type`|`ptrdiff_t`|
|`reference`|`T&`|
|`const reference`|`const T&`|
|[`iterator`](/iterator.md)|指向 `value_type` 的[_老式双向迭代器 (LegacyBidirectionalIterator)_](https://zh.cppreference.com/w/cpp/named_req/BidirectionalIterator)|
|`const_iterator`|指向 `const value_type` 的[_老式双向迭代器 (LegacyBidirectionalIterator)_](https://zh.cppreference.com/w/cpp/named_req/BidirectionalIterator)|
|`reverse_iterator`|`iterator`|
|`const_reverse_iterator`|`const_iterator`|

## 成员函数

|||
|:-|:-|
|（构造函数）|构造 `xor_list` <br>（公开成员函数）|
|[（析构函数）](/destructor.md)|析构 `xor_list` <br>（公开成员函数）|
|[`get_allocator`](/get_allocator.md)|返回关联的分配器<br>（公开成员函数）|

### 元素访问

|||
|:-|:-|
|[`front`](/front.md)|访问第一个元素<br>（公开成员函数）|
|[`back`](/back.md)|访问最后一个元素<br>（公开成员函数）|

### 迭代器

|||
|:-|:-|
|[`begin`<br>`cbegin`](/begin.md)|返回指向起始的迭代器<br>（公开成员函数）|
|[`end`<br>`cend`](/end.md)|返回指向末尾的迭代器<br>（公开成员函数）|
|[`rbegin`<br>`crbegin`](/rbegin.md)|返回指向起始的逆向迭代器<br>（公开成员函数）|
|[`rend`<br>`crend`](/rend.md)|返回指向末尾的逆向迭代器<br>（公开成员函数）|
|_`before_begin`_|返回起始迭代器的前驱迭代器<br>（*仅用于阐释的私有成员函数）|
|_`after_end`_|返回末尾迭代器的后继迭代器<br>（*仅用于阐释的私有成员函数）|
|[`make_reverse_iterator`](/make_reverse_iterator.md)|从迭代器构造同类型的反向迭代器，指向原迭代器的上一个元素<br>（静态公开成员函数）|

### 容量

|||
|:-|:-|
|[`empty`](/empty.md)|检查容器是否为空<br>（公开成员函数）|
|[`max_size`](/max_size.md)|返回最大可能的元素数量<br>（公开静态成员函数）|

### 修改器

|||
|:-|:-|
|[`clear`](/clear.md)|清除内容<br>（公开成员函数）|
|[`insert`](/insert.md)|插入元素<br>（公开成员函数）|
|[`emplace`](/emplace.md)|原位构造元素<br>（公开成员函数）|
|[`erase`](/erase.md)|擦除元素<br>（公开成员函数）|
|[`push_back`](/push_back.md)|将元素添加到容器末尾<br>（公开成员函数）|
|[`emplace_back`](/emplace_back.md)|在容器末尾原位构造元素<br>（公开成员函数）|
|[`pop_back`](/pop_back.md)|移除末元素<br>（公开成员函数）|
|[`push_front`](/push_front.md)|插入元素到容器起始<br>（公开成员函数）|
|[`emplace_front`](/emplace_front.md)|在容器头部原位构造元素<br>（公开成员函数）|
|[`pop_front`](/pop_front.md)|移除首元素<br>（公开成员函数）|
|[`swap`](/swap.md)|交换内容<br>（公开成员函数）|

### 操作

|||
|:-|:-|
|[`merge`](/merge.md)|合并两个有序列表<br>（公开成员函数）|
|[`splice`](/splice.md)|从另一个 `xor_list` 中移动元素<br>（公开成员函数）|
|[`remove`<br>`remove_if`](/remove.md)|移除满足特定标准的元素<br>（公开成员函数）|
|[`reverse`](/reverse.md)|反转元素的顺序<br>（公开成员函数）|
|[`unique`](/unique.md)|删除连续的重复元素<br>（公开成员函数）|
|[`sort`](/sort.md)|对元素进行排序<br>（公开成员函数）|

### 非成员函数

|||
|:-|:-|
|`operator==`<br>`operator<=>`|按照字典顺序比较两个 `xor_list` 的值<br>（函数模板）|
|[`Yc::swap`](/adl_swap.md)|交换内容<br>（函数模板）|
