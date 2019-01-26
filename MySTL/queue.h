#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

namespace mstl {

	template<typename T, typename ContainerType = list<T>>
	class queue {
		ContainerType _container;

	public:
		size_type size() { return _container.size(); };

		bool empty () { return _container.size() ? false : true; }

		void push(const T& t) { _container.push_back(t); };

		void pop() { _container.erase(_container.begin()); }

		T& front() {
			return _container.front();
		}

		T& back() {
			return _container.back();
		}
	};

}

#endif // !QUEUE_H
