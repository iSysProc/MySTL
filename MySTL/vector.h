#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept> 
#include "SequenceContainer.h"

namespace mstl {

	template<typename T>
	class const_vector_iterator {
	protected:
		T *ptr;

	public:
		const_vector_iterator() : ptr(){}
		const_vector_iterator(T &p) : ptr(&p) {}

		T operator*() {
			return *ptr;
		}

		const_vector_iterator& operator++() {
			ptr++;
			return *this;
		}

		const_vector_iterator operator++(int) {
			const_vector_iterator tmp(*ptr);
			++(*this);
			return tmp;
		}

		const_vector_iterator& operator--() {
			ptr--;
			return *this;
		}

		const_vector_iterator operator--(int) {
			const_vector_iterator tmp(*ptr);
			--(*this);
			return tmp;
		}

		bool operator==(const const_vector_iterator &it) {
			return it.ptr == ptr;
		}

		bool operator!=(const const_vector_iterator &it) {
			return it.ptr != ptr;
		}
	};

	template<typename T>
	class vector_iterator : public const_vector_iterator<T>, public container_iterator<T, vector_iterator<T>> {
	public:
		vector_iterator() : const_vector_iterator<T>() {}
		vector_iterator(T &p) : const_vector_iterator<T>(p) {}

		T& operator*() {
			return *(const_vector_iterator<T>::ptr);
		}

		vector_iterator& operator++() {
			const_vector_iterator<T>::ptr++;
			return *this;
		}

		vector_iterator operator++(int) {
			vector_iterator tmp(*(const_vector_iterator<T>::ptr));
			++(*this);
			return tmp;
		}

		vector_iterator& operator--() {
			const_vector_iterator<T>::ptr--;
			return *this;
		}

		vector_iterator operator--(int) {
			vector_iterator tmp(*(const_vector_iterator<T>::ptr));
			--(*this);
			return tmp;
		}

		bool operator==(const vector_iterator &it) {
			return this->const_vector_iterator<T>::operator==(it);
		}

		bool operator!=(const vector_iterator &it) {
			return this->const_vector_iterator<T>::operator!=(it);
		}
	};

	template<typename T>
	class const_reverse_vector_iterator {
	protected:
		T *ptr;

	public:
		const_reverse_vector_iterator() : ptr() {}
		const_reverse_vector_iterator(T &p) :ptr(&p) {}

		T operator*() {
			return *ptr;
		}

		const_reverse_vector_iterator& operator=(const_reverse_vector_iterator& it) {
			return const_reverse_vector_iterator(it);
		}

		const_reverse_vector_iterator& operator++() {
			ptr--;
			return *this;
		}

		const_reverse_vector_iterator operator++(int) {
			const_reverse_vector_iterator tmp(*ptr);
			++(*this);
			return tmp;
		}

		const_reverse_vector_iterator& operator--() {
			ptr++;
			return *this;
		}

		const_reverse_vector_iterator operator--(int) {
			const_reverse_vector_iterator tmp(*ptr);
			--(*this);
			return tmp;
		}

		bool operator==(const const_reverse_vector_iterator &it) {
			return it.ptr == ptr;
		}

		bool operator!=(const const_reverse_vector_iterator &it) {
			return it.ptr != ptr;
		}
	};

	template<typename T>
	class reverse_vector_iterator : public const_reverse_vector_iterator<T> {
	public:
		reverse_vector_iterator() : const_reverse_vector_iterator<T>() {}
		reverse_vector_iterator(T &p) : const_reverse_vector_iterator<T>(p) {}

		T& operator*() {
			return *(const_reverse_vector_iterator<T>::ptr);
		}
	};

	template <typename T>
	class vector : public SequenceContainer<T, vector<T>, vector_iterator<T>> {
	public:
		typedef const_vector_iterator<T> const_iterator;
		typedef const_reverse_vector_iterator<T> const_reverse_iterator;
		typedef vector_iterator<T> iterator;
		typedef reverse_vector_iterator<T> reverse_iterator;

	private:
		T *_arr;
		size_type _size;
		size_type _capacity;

	public:
		vector();
		vector(vector &v);
		vector(const size_type size, const T &t = T());
		~vector();

		vector& operator= (const vector &v);
		T& operator[](const size_type n);
		size_type size();
		size_type capacity();
		void reserve(const size_type cap);
		void resize(const size_type size, const T &t = T());
		bool empty();
		void push_back(const T &t);
		void pop_back();
		T& front();
		T& back();
		T& at(const size_type n);
		void clear();

		const_iterator cbegin();
		const_iterator cend();
		const_reverse_iterator crbegin();
		const_reverse_iterator crend();
		iterator begin();
		iterator end();
		reverse_iterator rbegin();
		reverse_iterator rend();

		void insert(iterator it, const T &t);
		void erase(iterator it);
	};

	template <typename T>
	vector<T>::vector() {
		this->_size = 0;
		this->_capacity = 0;
		this->_arr = new T[_capacity];
	}

	template <typename T>
	vector<T>::vector(vector &v){
		this->_capacity = v.capacity();
		this->_size = v.size();
		this->_arr = new T[_capacity];

		for (int i = 0; i < _size; i++) {
			this->_arr[i] = v[i];
		}
	}

	template <typename T>
	vector<T>::vector(const size_type size, const T &t){
		if (size == 0) {
			vector();
		} else {
			this->_size = size;
			this->_capacity = size;
			this->_arr = new T[_capacity];

			for (int i = 0; i < size; i++) {
				_arr[i] = T(t);
			}
		}
	}

	template<typename T>
	vector<T>::~vector() {
		delete[] _arr;
	}

	template<typename T>
	vector<T>& vector<T>::operator=(const vector& v) {
		T* tmp = _arr;
		delete tmp;

		_capacity = v.capacity();
		_size = v.size();
		_arr = new T[_capacity];

		for (int i = 0; i < _size; i++) {
			_arr[i] = v[i];
		}

		return *this;
	}

	template<typename T>
	T& vector<T>::operator[](const size_type n) {
		return _arr[n];
	}

	template<typename T>
	size_type vector<T>::size() {
		return _size;
	}

	template<typename T>
	size_type vector<T>::capacity() {
		return _capacity;
	}

	template<typename T>
	void vector<T>::reserve(const size_type cap) {
		T *tmp = _arr;
		_arr = new T[cap];

		std::copy(tmp, tmp + _size, _arr);

		_capacity = cap;
	}

	template<typename T>
	void vector<T>::resize(const size_type size, const T &t) {
		if (_size < size) {
			if (_capacity < size) {
				reserve(size);
			}
			while (_size != size)
			{
				push_back(t);
			}
		} else {
			while (_size != size)
			{
				pop_back();
			}
		}
	}

	template<typename T>
	bool vector<T>::empty() {
		return _size ? false : true;
	}

	template<typename T>
	void vector<T>::push_back(const T &t) {
		if (_size == _capacity) {
			if (_capacity == 0) _capacity = 1;
			reserve(2 * _capacity);
		}

		_arr[_size++] = T(t);
	}

	template<typename T>
	void vector<T>::pop_back() {
		if (_size > 0) _arr[--_size] = T();
	}

	template<typename T>
	T& vector<T>::front() {
		return _arr[0];
	}

	template<typename T>
	T& vector<T>::back() {
		return _arr[_size - 1];
	}

	template<typename T>
	T& vector<T>::at(const size_type n) {
		if (_size - 1 < n || _size < 0) 
			throw std::out_of_range("mstl::vector<T>::at(size_type)");
		return _arr[n];
	}

	template<typename T>
	void vector<T>::clear() {
		for (int i = 0; i < _size; i++) {
			_arr[i] = T();
		}
		_size = 0;
	}

	template<typename T>
	const_vector_iterator<T> vector<T>::cbegin() {
		return const_iterator(*_arr);
	}

	template<typename T>
	const_vector_iterator<T> vector<T>::cend() {
		return const_iterator(*(_arr + _size));
	}

	template<typename T>
	const_reverse_vector_iterator<T> vector<T>::crbegin() {
		return const_reverse_iterator(*(_arr + _size - 1));
	}

	template<typename T>
	const_reverse_vector_iterator<T> vector<T>::crend() {
		return const_reverse_iterator(*(_arr - 1));
	}

	template<typename T>
	vector_iterator<T> vector<T>::begin() {
		return iterator(*_arr);
	}

	template<typename T>
	vector_iterator<T> vector<T>::end() {
		return iterator(*(_arr + _size));
	}

	template<typename T>
	reverse_vector_iterator<T> vector<T>::rbegin() {
		return reverse_iterator(*(_arr + _size - 1));
	}

	template<typename T>
	reverse_vector_iterator<T> vector<T>::rend() {
		return reverse_iterator(*(_arr - 1));
	}

	template<typename T>
	void vector<T>::insert(iterator it, const T &t) {
		if (_size == _capacity) {
			size_type indx = &(*it) - &(*begin());
			reserve(2 * _capacity);
			iterator n_current = iterator(*(_arr + indx));
			it = n_current;
		}

		iterator itend = end();
		_size++;
		while (it != itend) {
			iterator tmp = itend;
			*tmp = *(--itend);
		}
		*it = T(t);
	}

	template<typename T>
	void vector<T>::erase(iterator it) {
		*it = T();
		for (iterator it_next = it; it != end(); it++) {
			T tmp = *it;
			*it = *(++it_next);
			*it_next = tmp;
		}
		_size--;
	}
}

#endif // !VECTOR_H



