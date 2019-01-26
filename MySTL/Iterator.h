#ifndef ITERATOR_H
#define ITERATOR_H

namespace mstl {

	typedef unsigned __int64 size_type;

	template<typename T, typename Derived>
	class const_container_iterator {
	protected:
		Derived *this_iterator;

	public:
		const_container_iterator() {
			this_iterator = static_cast<Derived*>(this);
		}

		T operator*() {
			return this_iterator->operator*();
		}

		Derived& operator++() {
			return this_iterator->operator++();
		}

		Derived operator++(int i) {
			return this_iterator->operator++(i);
		}

		Derived& operator--() {
			return this_iterator->operator--();
		}

		Derived operator--(int i) {
			return this_iterator->operator--(i);
		}

		bool operator==(const const_container_iterator &it) {
			return this_iterator->operator==(static_cast<const Derived&>(it));
		}

		bool operator!=(const const_container_iterator &it) {
			return this_iterator->operator!=(static_cast<const Derived&>(it));
		}
	};

	template<typename T, typename Derived>
	class container_iterator : public const_container_iterator<T, Derived> {
	public:
		container_iterator() : const_container_iterator<T, Derived>() {}

		T& operator*() {
			return const_container_iterator<T, Derived>::this_iterator->operator*();
		}
	};

	//TODO fix (distance changing it1) need copy constructor
	template<typename Iterator>
	size_type distance(const Iterator *it1, Iterator *it2) {
		size_type counter = 0;
		Iterator it(*it1);
		while (it != *it2) {
			it++;
			counter++;
		}

		return counter;
	}

	//TODO fix (distance changing it) need copy constructor
	template<typename Iterator>
	Iterator* next(Iterator it, int pos) {
		Iterator* newIterator = &it;
		for (int i = 0; i < pos; i++) {
			(*newIterator)++;
		}
		return newIterator;
	}
}

#endif // !ITERATOR_H

