#ifndef STACK_H
#define STACK_H

#include "vector.h"

namespace mstl {
	
	template<typename T, typename ContainerType = vector<T>>
	class stack {
		ContainerType _container;

	public:
		size_type size() { return _container.size(); }

		bool empty() { return _container.size() ? false : true; }

		void push(const T &t) { _container.push_back(t); }

		void pop() { _container.pop_back(); }

		T& top() { return _container.back(); }
	};
}

#endif // !STACK_H
