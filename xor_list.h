#pragma once
#include<memory>
#include<algorithm>
namespace Yc
{
	namespace details
	{
		template<size_t N>
		struct alignas(N) node_t
		{
			size_t p;
		};
	}
	template<class T,class Alloc=std::allocator<T>>
	class xor_list
	{
		using Node = details::node_t<alignof(T)>;
		using Node_ptr = Node*;
		static constexpr size_t node_size = sizeof(T) / sizeof(Node) + (sizeof(T) % sizeof(Node) != 0);
		using alloc_trait = std::allocator_traits<Alloc>;
		[[no_unique_address]]Alloc alloc{};
		Node head{};
		Node tail{};
		using rb_alloc = alloc_trait::template rebind_alloc<Node[node_size + 1]>;
		constexpr rb_alloc rb_a()const
		{
			return alloc;
		}
		//rb_alloc rb_a{};
		Node_ptr get_new_node()
		{
			auto rb_al = rb_a();
			return (Node_ptr)rb_al.allocate(1);
		}
		void delete_node(Node_ptr p)
		{
			auto rb_al = rb_a();
			rb_al.deallocate((decltype(rb_al.allocate(1)))p, 1);
		}
	public:
		xor_list()noexcept :head{ ((size_t)(Node_ptr{nullptr}))^(size_t)(&tail)},tail{ ((size_t)(Node_ptr{nullptr})) ^ (size_t)(&head) }
		{
		}
		explicit xor_list(const Alloc& alloc)noexcept(std::is_nothrow_copy_constructible_v<Alloc>) :alloc { alloc }, head{ ((size_t)(Node_ptr{nullptr})) ^ (size_t)(&tail) }, tail{ ((size_t)(Node_ptr{nullptr})) ^ (size_t)(&head) }
		{
		}
		xor_list(const xor_list& other) :alloc{alloc_trait::select_on_container_copy_construction(other.get_allocator())},head { ((size_t)(Node_ptr{ nullptr })) ^ (size_t)(&tail) }, tail{ ((size_t)(Node_ptr{nullptr})) ^ (size_t)(&head) }
		{
			for (auto& i : other)
			{
				push_back(i);
			}
		}
		xor_list(xor_list&& other)noexcept :alloc{std::move(other.alloc)}, head{ ((size_t)(Node_ptr{nullptr})) ^ (size_t)(&tail) }, tail{ ((size_t)(Node_ptr{nullptr})) ^ (size_t)(&head) }
		{
			splice(begin(), other);
		}
		xor_list(std::initializer_list<T>lst, const Alloc& alloc = Alloc()) :alloc{ alloc }, head{ ((size_t)(Node_ptr{nullptr})) ^ (size_t)(&tail) }, tail{ ((size_t)(Node_ptr{nullptr})) ^ (size_t)(&head) }
		{
			for (auto& t : lst)
			{
				push_back(std::move(t));
			}
		}
		xor_list& operator=(const xor_list& other)
		{
			if (this == std::addressof(other))
			{
				return *this;
			}
			this->~xor_list();
			new(this)xor_list(other);
			return *this;
		}
		xor_list& operator=(xor_list&& other)noexcept(noexcept(swap(other)))
		{
			swap(other);
			return *this;
		}
		constexpr Alloc get_allocator()const
		{
			return alloc;
		}
		bool empty()const noexcept
		{
			return (Node_ptr)(head.p ^ (size_t)((Node_ptr)nullptr)) == &tail;
		}
		class iterator
		{
			Node_ptr last, current;
			friend xor_list;
			constexpr auto node_info()const noexcept
			{
				struct
				{
					Node_ptr last, current, next;
				}ret{last,current,nullptr};
				auto tmp = *this;
				tmp++;
				ret.next = tmp.current;
				return ret;
			}
		public:
			constexpr iterator(Node_ptr last,Node_ptr current)noexcept:last{last},current{current}
			{}
			constexpr iterator() = default;
			constexpr iterator& operator++()noexcept
			{
				Node_ptr tmp = current;
				current = (Node_ptr)((current->p) ^ ((size_t)(last)));
				last = tmp;
				return *this;
			}
			constexpr iterator operator++(int)noexcept
			{
				iterator tmp = *this;
				this->operator++();
				return tmp;
			}
			constexpr iterator& operator--()noexcept
			{
				Node_ptr tmp = last;
				last = (Node_ptr)((last->p) ^ ((size_t)(current)));
				current = tmp;
				return *this;
			}
			constexpr iterator operator--(int)noexcept
			{
				iterator tmp = *this;
				this->operator--();
				return tmp;
			}
			constexpr T& operator*()const noexcept
			{
				return *((T*)(current + 1));
			}
			constexpr T* operator->()const noexcept
			{
				return ((T*)(current + 1));
			}
			constexpr bool operator==(const iterator& other)const noexcept
			{
				return (last == other.last) && (current == other.current);
			}
			using value_type = T;
			using difference_type = ptrdiff_t;
			using pointer = T*;
			using reference = T&;
			using iterator_category = std::bidirectional_iterator_tag;
		};
		class const_iterator:public iterator
		{
		public:
			using iterator::iterator;
			constexpr const_iterator(const iterator&other):iterator{other}
			{}
			constexpr const T& operator*()const noexcept
			{
				return this->iterator::operator*();
			}
			constexpr const T* operator->()const noexcept
			{
				return this->iterator::operator->();
			}
			using value_type = const T;
			using difference_type = ptrdiff_t;
			using pointer = const T*;
			using reference = const T&;
			using iterator_category = std::bidirectional_iterator_tag;
		};
		constexpr iterator begin()noexcept
		{
			iterator ret( (Node_ptr)nullptr,&head );
			++ret;
			return ret;
		}
		constexpr iterator end()noexcept
		{
			iterator ret(& tail, (Node_ptr)nullptr );
			--ret;
			return ret;
		}
		constexpr const_iterator begin()const noexcept
		{
			iterator ret((Node_ptr)nullptr, (Node_ptr)&head);
			++ret;
			return ret;
		}
		constexpr const_iterator end()const noexcept
		{
			iterator ret((Node_ptr)( &tail) , (Node_ptr)nullptr);
			--ret;
			return ret;
		}
		constexpr const_iterator cbegin()const noexcept
		{
			return begin();
		}
		constexpr const_iterator cend()const noexcept
		{
			return end();
		}
		constexpr iterator rbegin()noexcept
		{
			iterator ret(nullptr, &tail);
			++ret;
			return ret;
		}
		constexpr iterator rend()noexcept
		{
			iterator ret(&head, nullptr);
			--ret;
			return ret;
		}
		constexpr const_iterator rbegin()const noexcept
		{
			iterator ret(nullptr, &tail);
			++ret;
			return ret;
		}
		constexpr const_iterator rend()const noexcept
		{
			iterator ret(&head, nullptr);
			--ret;
			return ret;
		}
		constexpr const_iterator crbegin()const noexcept
		{
			return rbegin();
		}
		constexpr const_iterator crend()const noexcept
		{
			return rend();
		}
		static constexpr iterator make_reverse_iterator(iterator i)noexcept
		{
			std::swap(i.last, i.current);
			return i;
		}
		constexpr T& front()noexcept
		{
			return *begin();
		}
		constexpr const T& front()const noexcept
		{
			return *begin();
		}
		constexpr T& back()noexcept
		{
			auto tmp = end();
			--tmp;
			return *tmp;
		}
		constexpr const T& back()const noexcept
		{
			auto tmp = end();
			--tmp;
			return *tmp;
		}
		iterator insert(iterator i,const T& t)
		{
			auto [last, current, next] = i.node_info();
			auto ptr = get_new_node();
			//new(ptr + 1)T(t);
			alloc_trait::construct(alloc, ptr + 1, t);
			ptr->p = ((size_t(last)) ^ (size_t(current)));
			auto llast = Node_ptr((size_t(last->p)) ^ (size_t(current)));
			last->p = ((size_t)(llast)) ^ ((size_t)(ptr));
			current->p = (size_t(ptr) ^ size_t(next));
			return { last,ptr };
		}
		iterator insert(iterator i, T&& t)
		{
			auto [last, current, next] = i.node_info();
			auto ptr = get_new_node();
			//new(ptr + 1)T(std::move(t));
			alloc_trait::construct(alloc, ptr + 1, std::move(t));
			ptr->p = ((size_t(last)) ^ (size_t(current)));
			auto llast = Node_ptr((size_t(last->p)) ^ (size_t(current)));
			last->p = ((size_t)(llast)) ^ ((size_t)(ptr));
			current->p = (size_t(ptr) ^ size_t(next));
			return { last,ptr };
		}
		template<class... Args>
		iterator emplace(iterator i, Args&&... args)
		{
			auto [last, current, next] = i.node_info();
			auto ptr = get_new_node();
			new(ptr + 1)T(std::forward<Args>(args)...);
			ptr->p = ((size_t(last)) ^ (size_t(current)));
			auto llast = Node_ptr((size_t(last->p)) ^ (size_t(current)));
			last->p = ((size_t)(llast)) ^ ((size_t)(ptr));
			current->p = (size_t(ptr) ^ size_t(next));
			return { last,ptr };
		}
		iterator erase(iterator i)
		{
			auto [last, current, next] = i.node_info();
			std::destroy_at<T>((T*)(current + 1));
			delete_node(current);
			(last->p )^= (size_t)current;
			(last->p )^= (size_t)next;
			(next->p )^= (size_t)current;
			(next->p )^= (size_t)last;
			iterator ret{ last,next };
			++ret;
			return ret;
		}
		void push_front(const T& t)
		{
			insert(begin(), t);
		}
		void push_front(T&& t)
		{
			insert(begin(), std::move(t));
		}
		template<class... Args>
		void emplace_front(Args&&... args)
		{
			emplace(begin(), std::forward(args)...);
		}
		void pop_front()
		{
			erase(begin());
		}
		void push_back(const T& t)
		{
			auto it = end();
			insert(it, t);
		}
		void push_back(T&& t)
		{
			auto it = end();
			insert(it, std::move(t));
		}
		template<class... Args>
		void emplace_back(Args&&... args)
		{
			auto it = end();
			emplace(it, std::forward(args)...);
		}
		void pop_back()
		{
			auto it = end();
			erase(it);
		}
		void clear()
		{
			while (!empty())
			{
				pop_front();
			}
		}
		void swap(xor_list& other)noexcept(noexcept(std::swap(alloc,other.alloc)))
		{
			if (std::addressof(other) == this)
			{
				return;
			}
			if (empty())
			{
				if (other.empty())
				{
					return;
				}
				alloc = other.alloc;
				size_t h = other.head.p;
				auto ptr_h = (Node_ptr)(h ^ (size_t((void*)nullptr)));
				size_t t = other.tail.p;
				auto ptr_t = (Node_ptr)(t ^ (size_t((void*)nullptr)));
				auto ptr_h2 = &other.head;
				auto ptr_t2 = &other.tail;
				head.p = ((size_t)((void*)nullptr) )^(size_t) ptr_h;
				tail.p = ((size_t)((void*)nullptr) )^ (size_t)ptr_t;
				ptr_h->p ^= (size_t)ptr_h2;
				ptr_h->p ^= (size_t)&head;
				ptr_t->p ^= (size_t)ptr_t2;
				ptr_t->p ^= (size_t)&tail;
				other.head.p = ((size_t)((void*)nullptr)) ^ (size_t)(&other.tail);
				other.tail.p = ((size_t)((void*)nullptr)) ^ (size_t)(&other.head);
				return;
			}
			else
			{
				if (other.empty())
				{
					return other.swap(*this);
				}
				std::swap(alloc, other.alloc);
				size_t h1 = other.head.p,t1=other.tail.p,h2=head.p,t2=tail.p;
				Node_ptr ph1 = Node_ptr(h1 ^ (size_t((void*)nullptr)));
				Node_ptr ph2 = Node_ptr(h2 ^ (size_t((void*)nullptr)));
				Node_ptr pt1 = Node_ptr(t1 ^ (size_t((void*)nullptr)));
				Node_ptr pt2 = Node_ptr(t2 ^ (size_t((void*)nullptr)));
				head.p = (size_t)ph1 ^ (size_t((void*)nullptr));
				tail.p = (size_t)pt1 ^ (size_t((void*)nullptr));
				other.head.p = (size_t)ph2 ^ (size_t((void*)nullptr));
				other.tail.p = (size_t)pt2 ^ (size_t((void*)nullptr));
				ph1->p ^= size_t(&other.head);
				ph1->p ^= size_t(&head);
				pt1->p ^= size_t(&other.tail);
				pt1->p ^= size_t(&tail);
				ph2->p ^= size_t(&head);
				ph2->p ^= size_t(&other.head);
				pt2->p ^= size_t(&tail);
				pt2->p ^= size_t(&other.tail);
				return;
			}
		}
		auto splice(iterator pos,iterator first, iterator last)noexcept
		{
			auto [prev, current, next] = pos.node_info();
			auto [prev1, current1, next1] = first.node_info();
			auto [prev2, current2, next2] = last.node_info();
			prev->p ^= (size_t)current;
			prev->p ^= (size_t)current1;
			current1->p ^= (size_t)prev1;
			current1->p ^= (size_t)prev;
			prev1->p ^= (size_t)current1;
			prev1->p ^= (size_t)current2;
			current2->p ^= (size_t)prev2;
			current2->p ^= (size_t)prev1;
			current->p ^= (size_t)prev;
			current->p ^= (size_t)prev2;
			prev2->p ^= (size_t)current2;
			prev2->p ^= (size_t)current;
			struct
			{
				iterator pos1, first1, last1;
			}ret{ {prev2,current},{prev,current1},{prev1,current2} };
			return ret;
		}
		iterator splice(iterator pos,xor_list& other)noexcept
		{
			auto [pos1, _1, _2] = splice(pos, other.begin(), other.end());
			return pos1;
		}
		void reverse()noexcept
		{
			if (empty())
			{
				return;
			}
			std::swap(head.p, tail.p);
		}
		void unique()
		{
			if (empty())
			{
				return;
			}
			iterator i1 = begin();
			iterator i2 = begin();
			i2++;
			xor_list tmp;
			while (i2 != end())
			{
				if (*i1 != *i2)
				{
					i1++;
					i2++;
				}
				else
				{
					i2++;
					while (i2!=end()&&*i1==*i2)
					{
						i2++;
					}
					i1++;
					auto [_1, _2, it] = tmp.splice(tmp.begin(), i1, i2);
					if (it != end())
					{
						i1 = it;
						it++;
						i2 = it;
					}
					else
					{
						return;
					}
				}
			}
		}
		size_t remove(const T& t)
		{
			auto it = begin();
			size_t c{};
			while (it != end())
			{
				if (*it == t)
				{
					c++;
					it = erase(it);
				}
			}
			return c;
		}
		template<class UnaryPredicate>
			requires requires(UnaryPredicate u) { u(std::declval<T>()); }
		size_t remove_if(UnaryPredicate u)
		{
			auto it = begin();
			size_t c{};
			while (it != end())
			{
				if (u(it))
				{
					c++;
					it = erase(it);
				}
			}
			return c;
		}
		void merge(xor_list& other)
		{
			auto it1 = begin();
			auto it2 = other.begin();
			while (it2 != other.end() && it1 != end())
			{
				if (*it2 < *it1)
				{
					auto it3 = it2;
					it3++;
					while (it3 != other.end() && *it3 < *it1)
					{
						it3++;
					}
					auto [pos, first, last] = splice(it1, it2, it3);
					it1 = pos;
					it2 = last;
					it1++;
				}
				else
				{
					it1++;
				}
			}
			if (it1 == end())
			{
				splice(it1, other);
			}
		}
		void merge(xor_list&& other)
		{
			auto it1 = begin();
			auto it2 = other.begin();
			while (it2 != other.end() && it1 != end())
			{
				if (*it2 < *it1)
				{
					auto it3 = it2;
					it3++;
					while (it3 != other.end() && *it3 < *it1)
					{
						it3++;
					}
					auto [pos, first, last] = splice(it1, it2, it3);
					it1 = pos;
					it2 = last;
					it1++;
				}
				else
				{
					it1++;
				}
				if (it1 == end())
				{
					splice(it1, other);
				}
			}
		}
		template<class compare>
		void merge(xor_list& other, compare comp)
		{
			auto it1 = begin();
			auto it2 = other.begin();
			while (it2 != other.end() && it1 != end())
			{
				if (comp(*it2,*it1))
				{
					auto it3 = it2;
					it3++;
					while (it3 != other.end() && comp(*it3,*it1))
					{
						it3++;
					}
					auto [pos, first, last] = splice(it1, it2, it3);
					it1 = pos;
					it2 = last;
					it1++;
				}
				else
				{
					it1++;
				}
				if (it1 == end())
				{
					splice(it1, other);
				}
			}
		}
		template<class compare>
		void merge(xor_list&& other, compare comp)
		{
			auto it1 = begin();
			auto it2 = other.begin();
			while (it2 != other.end() && it1 != end())
			{
				if (comp(*it2, *it1))
				{
					auto it3 = it2;
					it3++;
					while (it3 != other.end() && comp(*it3, *it1))
					{
						it3++;
					}
					auto [pos, first, last] = splice(it1, it2, it3);
					it1 = pos;
					it2 = last;
					it1++;
				}
				else
				{
					it1++;
				}
				if (it1 == end())
				{
					splice(it1, other);
				}
			}
		}
		~xor_list()
		{
			while (!empty())
			{
				pop_front();
			}
		}
		constexpr static size_t max_size()noexcept
		{
			return -1;
		}
		using value_type = T;
		using reference = T&;
		using const_reference = const T&;
		using allocator_type = Alloc;
		using reverse_iterator = iterator;
		using const_reverse_iterator = const_iterator;
		using difference_type = ptrdiff_t;
		using size_type = size_t;
	};
	template<class T>
	bool operator==(const xor_list<T>& l, const xor_list<T>& r)noexcept(noexcept(std::declval<T>()== std::declval<T>()))
	{
		auto it1 = l.begin();
		auto it2 = r.begin();
		for (; it1 != l.end() && it2 != r.end(); it1++, it2++)
		{
			if (*it1 != *it2)
			{
				return false;
			}
		}
		return it1 == l.end() && it2 == r.end();
	}
	template<class T>
	auto operator<=>(const xor_list<T>& l, const xor_list<T>& r)
	{
		return std::lexicographical_compare_three_way(l.begin(), l.end(), r.begin(), r.end());
	}
	template<class T>
	void swap(xor_list<T>& l, xor_list<T>& r)
	{
		l.swap(r);
	}
};