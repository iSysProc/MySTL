#ifndef LIST_H
#define LIST_H

#include "SequenceContainer.h"

namespace mstl {

	template<typename T>
	class Node {
		Node *prev;
		Node *next;
		T data;

	public:
		Node(T data = T(), Node *prev = nullptr, Node *next = nullptr) {
			this->data = data;
			this->prev = prev;
			this->next = next;
		}

		Node* getNext() {
			return next;
		}

		Node* getPrev() {
			return prev;
		}

		void setNext(Node *next) {
			this->next = next;
		}

		void setPrev(Node *prev) {
			this->prev = prev;
		}

		T& getData() {
			return data;
		}
	};

	template<typename T>
	class const_list_iterator : public const_container_iterator<T, const_list_iterator<T>> {
	protected:
		Node<T>* node;

	public:
		const_list_iterator() : node(nullptr) {}
		const_list_iterator(Node<T>* node) {
			this->node = node;
		}

		T operator* () {
			return node->getData();
		}

		const_list_iterator& operator++() {
			node = node->getNext();
			return *this;
		}

		const_list_iterator operator++(int) {
			const_list_iterator tmp(node);
			++(*this);
			return tmp;
		}

		const_list_iterator& operator--() {
			node = node->getPrev();
			return *this;
		}

		const_list_iterator operator--(int) {
			const_list_iterator tmp(node);
			--(*this);
			return tmp;
		}

		bool operator == (const const_list_iterator &it) {
			return node == it.node;
		}

		bool operator!= (const const_list_iterator &it) {
			return node != it.node;
		}
	};

	template<typename T>
	class list_iterator : public const_list_iterator<T>, public container_iterator<T, list_iterator<T>> {
		template<typename T>
		friend class list; //void list<T>::erase(Iterator it)
	public:
		list_iterator() {}
		list_iterator(Node<T> *node) : const_list_iterator<T>(node) {}

		T& operator*() {
			return const_list_iterator<T>::node->getData();
		}

		list_iterator<T>& operator++() {
			const_list_iterator<T>::node = const_list_iterator<T>::node->getNext();
			return *this;
		}

		list_iterator<T> operator++(int i) {
			list_iterator tmp(const_list_iterator<T>::node);
			++(*this);
			return tmp;
		}

		list_iterator<T>& operator--() {
			const_list_iterator<T>::node = const_list_iterator<T>::node->getPrev();
			return *this;
		}

		list_iterator<T> operator--(int i) {
			list_iterator tmp(const_list_iterator<T>::node);
			--(*this);
			return tmp;
		}

		bool operator == (const list_iterator<T> &it) {
			return this->const_list_iterator<T>::operator==(it);
		}

		bool operator!= (const list_iterator<T> &it) {
			return this->const_list_iterator<T>::operator!=(it);
		}
	};

	template<typename T>
	class const_reverse_list_iterator {
	protected:
		Node<T> *node;

	public:
		const_reverse_list_iterator() : node(nullptr) {}
		const_reverse_list_iterator(Node<T> *node) {
			this->node = node;
		}

		T operator*() {
			return node->getData();
		}

		const_reverse_list_iterator& operator++() {
			node = node->getPrev();
			return *this;
		}

		const_reverse_list_iterator operator++(int) {
			const_reverse_list_iterator tmp(node);
			++(*this);
			return tmp;
		}

		const_reverse_list_iterator& operator--() {
			node = node->getNext();
			return *this;
		}

		const_reverse_list_iterator operator--(int) {
			const_reverse_list_iterator tmp(node);
			--(*this);
			return tmp;
		}

		bool operator==(const const_reverse_list_iterator &it) {
			return node == it.node;
		}

		bool operator!=(const const_reverse_list_iterator &it) {
			return node != it.node;
		}
	};

	template<typename T>
	class reverse_list_iterator : public const_reverse_list_iterator<T> {
	public:
		reverse_list_iterator() : const_reverse_list_iterator<T> (){}
		reverse_list_iterator(Node<T> *node) : const_reverse_list_iterator<T>(node) {}

		T& operator*() {
			return const_reverse_list_iterator<T>::node->getData();
		}
	};

	template<typename T>
	class list : public SequenceContainer<T, list<T>, list_iterator<T>> {
	public:
		typedef const_list_iterator<T> const_iterator;
		typedef const_reverse_list_iterator<T> const_reverse_iterator;
		typedef list_iterator<T> iterator;
		typedef reverse_list_iterator<T> reverse_iterator;

	private:
		Node<T> *head;
		Node<T> *tail;
		size_type _size;

	public:
		list();
		list(const list &l);
		list(const size_type, const T &t = T());
		~list();

		list& operator= (const list& l);
		size_type size();
		void resize(const size_type size, const T &t = T());
		bool empty();
		void push_back(const T &t);
		void push_front(const T &t);
		void pop_back();
		void pop_front();
		void remove(const T &t);
		T& front();
		T& back();
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

	template<typename T>
	list<T>::list() {
		_size = 0;
		head = new Node<T>(T(), nullptr, nullptr);
		tail = new Node<T>(T(), head, nullptr);
		head->setNext(tail);
	}

	template<typename T>
	list<T>::list(const list& t) : list() {
		if (t._size > 0) {
			Node<T> *tmp = t.head->getNext();
			push_back(tmp->getData());
			while ((tmp = tmp->getNext()) != t.tail) {
				push_back(tmp->getData());
			}
		}
	}

	template<typename T>
	list<T>::list(const size_type size, const T &t) : list() {
		for (size_type i = 0; i < size; i++) {
			push_back(t);
		}
	}

	template<typename T>
	list<T>::~list() {
		clear();
	}

	template<typename T>
	list<T>& list<T>::operator=(const list<T> &ls) {
		if (ls._size != 0) {
			Node<T> *tmp = ls.head->getNext();
			push_back(tmp->getData());
			while ((tmp = tmp->getNext()) != ls.tail) {
				push_back(tmp->getData());
			}
		}
		return *this;
	}

	template<typename T>
	size_type list<T>::size() {
		return _size;
	}

	template<typename T>
	bool list<T>::empty() {
		return _size ? false : true;
	}

	template<typename T>
	void list<T>::push_back(const T &t) {
		Node<T> *tmp =new Node<T>(t, tail->getPrev(), tail);
		tmp->getPrev()->setNext(tmp);
		tail->setPrev(tmp);
		_size++;
	}

	template<typename T>
	void list<T>::push_front(const T &t) {
		Node<T> *tmp = new Node<T>(t, head, head->getNext());
		head->setNext(tmp);
		tmp->getNext()->setPrev(tmp);
		_size++;
	}

	template<typename T>
	void list<T>::pop_back() {
		if (_size != 0) {
			Node<T> *tmp = tail->getPrev();
			tmp->getPrev()->setNext(tail);
			tail->setPrev(tmp->getPrev());
			delete tmp;
			_size--;
		}
	}

	template<typename T>
	void list<T>::pop_front() {
		if (_size != 0) {
			Node<T> *tmp = head->getNext();
			tmp->getNext()->setPrev(head);
			head->setNext(tmp->getNext());
			delete tmp;
			_size--;
		}
	}

	template<typename T>
	T& list<T>::front() {
		return head->getNext()->getData();
	}

	template<typename T>
	T& list<T>::back() {
		return tail->getPrev()->getData();
	}

	template<typename T>
	void list<T>::clear() {
		while (_size != 0) {
			pop_back();
		}
	}

	template<typename T>
	void list<T>::remove(const T &t) {
		Node<T> *current = head->getNext();

		while (current != tail) {
			if (current->getData() == t) {
				if (Node<T> *tmp = current->getNext()) {
					tmp->setPrev(current->getPrev());
				}
				if (Node<T> *tmp = current->getPrev()) {
					tmp->setNext(current->getNext());
				}
				
				Node<T>* tmp = current;
				current = current->getNext();
				delete tmp;
				_size--;

			} else {
				current = current->getNext();
			}
		}
	}

	template<typename T>
	void list<T>::resize(size_type size, const T &t) {
		while (_size != size) {
			if (_size < size) {
				push_back(t);
			} else {
				pop_back();
			}
		}
	}

	template<typename T>
	const_list_iterator<T> list<T>::cbegin() {
		return const_iterator(head->getNext());
	}

	template<typename T>
	const_list_iterator<T> list<T>::cend() {
		return const_iterator(tail);
	}

	template<typename T>
	const_reverse_list_iterator<T> list<T>::crbegin() {
		return const_reverse_iterator(tail->getPrev());
	}

	template<typename T>
	const_reverse_list_iterator<T> list<T>::crend() {
		return const_reverse_iterator(head);
	}

	template<typename T>
	list_iterator<T> list<T>::begin() {
		return iterator(head->getNext());
	}

	template<typename T>
	list_iterator<T> list<T>::end() {
		return iterator(tail);
	}

	template<typename T>
	reverse_list_iterator<T> list<T>::rbegin() {
		return reverse_iterator(tail->getPrev());
	}

	template<typename T>
	reverse_list_iterator<T> list<T>::rend() {
		return reverse_iterator(head);
	}

	template<typename T>
	void list<T>::insert(iterator it, const T &t) {
		if (it.node == head) {
			push_front(t);
		} else if(it.node == tail) {
			push_back(t);
		} else {
			Node<T> *current = new Node<T>(t, it.node->getPrev(), it.node);
			it.node->getPrev()->setNext(current);
			it.node->setPrev(current);

			_size++;
		}
	}

	template<typename T>
	void list<T>::erase(iterator it) {
		if (it.node == head) {
			throw -100;
		}
		else if (it.node == tail) {
			throw -100;
		}
		else {
			Node<T> *tmp = it.node;
			tmp->getPrev()->setNext(tmp->getNext());
			tmp->getNext()->setPrev(tmp->getPrev());
			delete tmp;
			_size--;
		}
	}
}

#endif 