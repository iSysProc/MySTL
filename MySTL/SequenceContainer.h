#ifndef SEQUNCE_CONTAINER_H
#define SEQUNCE_CONTAINER_H

#include "Container.h"


namespace mstl {

	template<typename T, class Derived, class Iterator>
	class SequenceContainer : Container {
		Derived *this_container;

	public:
		SequenceContainer() {
			this_container = static_cast<Derived*>(this);
		}

		Derived& operator= (const Derived &container) { 
			return this_container->operator=(container);
		};

		size_type size() { 
			return this_container->size();
		};

		void resize(const size_type size, const T &t = T()) { 
			this_container->resize(size, t);
		};

		bool empty() {
			return this_container->empty();
		}

		void push_back(const T &t) {
			this_container->push_back(t);
		}

		void pop_back() {
			this_container->pop_back();
		}

		T& front() {
			return this_container->front();
		}

		T& back() {
			return this_container->back();
		}

		void clear() {
			this_container->clear();
		}
		
		Iterator begin() {
			return this_container->begin();
		}
		
		Iterator end() {
			return this_container->end();
		}

		void insert(Iterator it, const T &t) {
			this_container->insert(it, t);
		}

		void erase(Iterator it) {
			this_container->erase(it);
		}
	};

}

#endif