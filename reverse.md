# `Yc::xor_list<T,Allocator>::reverse`

|||
|:-|:-|
|`void reverse()noexcept;`||

逆转容器中的元素顺序。

除非是空容器或者只有一个元素（此时什么都不做），否则 `begin()` ， `end()` ， `rbegin()` ， `rend()` 迭代器都会失效，_`before_begin()`_ 和 _`after_end()`_ 迭代器仍保持不变，其余迭代器都会变成指向元素不变但是方向相反的迭代器。

## 参数

（无）

## 返回值

（无）

## 复杂度

常数
