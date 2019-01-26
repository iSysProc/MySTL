#include "vector.h"
#include "list.h"
#include "stack.h"
#include "queue.h"

#include <iostream>
#include <string>

void checkVector() {
	std::cout << std::endl << "==================== vector ===================="  << std::endl;

	mstl::vector<std::string> cont;
	std::cout << std::endl << "vector()" << std::endl;
	std::cout << "size = " << cont.size()
		<< ", capacity = " << cont.capacity() << std::endl;

	cont.push_back("first");
	std::cout << std::endl << "push_back()" << std::endl;
	std::cout << "size = " << cont.size()
		<< ", capacity = " << cont.capacity() << std::endl;
	std::cout << cont[0] << " = " << cont.at(0) << " = " << cont.front() << std::endl;
	
	cont.push_back("second");
	cont.push_back("third");
	std::cout << std::endl << "push_back() x2" << std::endl;
	std::cout << "size = " << cont.size()
		<< ", capacity = " << cont.capacity() << std::endl;
	std::cout << cont.front() << " " << cont.at(1) << " " << cont.back() << std::endl;

	std::cout << std::endl << "const_iterator loop" << std::endl;
	for (auto it = cont.cbegin(); it != cont.cend(); it++) {
		*it = *it + " -cit";
		std::cout << *it << std::endl;
	}

	std::cout << std::endl << "iterator loop" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " -it";
		std::cout << *it << std::endl;
	}

	std::cout << std::endl << "const_reverse_iterator loop" << std::endl;
	for (auto it = cont.crbegin(); it != cont.crend(); it++) {
		*it = *it + " -crit";
		std::cout << *it << std::endl;
	}

	std::cout << std::endl << "reverse_iterator loop" << std::endl;
	for (auto it = cont.rbegin(); it != cont.rend(); it++) {
		*it = *it + " -rit";
		std::cout << *it << std::endl;
	}


	cont.pop_back();
	std::cout << std::endl << "pop_back()" << std::endl;
	std::cout << "size = " << cont.size()
		<< ", capacity = " << cont.capacity() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	cont.reserve(100);
	std::cout << std::endl << "reserve(100)" << std::endl;
	std::cout << "size = " << cont.size()
		<< ", capacity = " << cont.capacity() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	cont.reserve(10);
	std::cout << std::endl << "reserve(10)" << std::endl;
	std::cout << "size = " << cont.size()
		<< ", capacity = " << cont.capacity() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	cont.resize(5);
	std::cout << std::endl << "resize(5)" << std::endl;
	std::cout << "size = " << cont.size()
		<< ", capacity = " << cont.capacity() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	cont.resize(20, "resize");
	std::cout << std::endl << "resize(20)" << std::endl;
	std::cout << "size = " << cont.size()
		<< ", capacity = " << cont.capacity() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	cont.resize(5);
	std::cout << std::endl << "resize(5)" << std::endl;
	std::cout << "size = " << cont.size()
		<< ", capacity = " << cont.capacity() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	auto it_in = cont.begin();
	it_in++;
	it_in++;
	it_in++;
	cont.insert(it_in, "it_in");
	std::cout << std::endl << "it_in = begin(); it_in++ x4; insert(it_in)" << std::endl;
	std::cout << "size = " << cont.size()
		<< ", capacity = " << cont.capacity() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	it_in = cont.begin();
	it_in++;
	cont.erase(it_in);
	std::cout << std::endl << "it_in = begin(); it_in++; erase(it_in)" << std::endl;
	std::cout << "size = " << cont.size()
		<< ", capacity = " << cont.capacity() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	mstl::vector<std::string> new_cont = cont;
	std::cout << std::endl << "new_cont = cont" << std::endl;
	std::cout << "size = " << new_cont.size()
		<< ", capacity = " << new_cont.capacity() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = new_cont.begin(); it != new_cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	mstl::vector<std::string> new_cont2(10, "fill");
	std::cout << std::endl << "new_cont2 = vector(10, ...)" << std::endl;
	std::cout << "size = " << new_cont2.size()
		<< ", capacity = " << new_cont2.capacity() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = new_cont2.begin(); it != new_cont2.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	new_cont2.clear();
	std::cout << std::endl << "new_cont2.clear()" << std::endl;
	std::cout << "size = " << new_cont2.size()
		<< ", capacity = " << new_cont2.capacity() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = new_cont2.begin(); it != new_cont2.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}
}

void checkList() {
	std::cout << std::endl << "==================== list ====================" << std::endl;

	mstl::list<std::string> cont;
	std::cout << std::endl << "list()" << std::endl;
	std::cout << "size = " << cont.size() << std::endl;

	cont.push_back("first");
	std::cout << std::endl << "push_back()" << std::endl;
	std::cout << "size = " << cont.size() << std::endl;
	std::cout << "front =  " << cont.front() << " back = " << cont.back() << std::endl;

	cont.push_back("second");
	cont.push_back("third");
	std::cout << std::endl << "push_back() x2" << std::endl;
	std::cout << "size = " << cont.size() << std::endl;
	std::cout << "front =  " << cont.front() << " back = " << cont.back() << std::endl;

	std::cout << std::endl << "const_iterator loop" << std::endl;
	for (auto it = cont.cbegin(); it != cont.cend(); it++) {
		*it = *it + " -cit";
		std::cout << *it << std::endl;
	}

	std::cout << std::endl << "iterator loop" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " -it";
		std::cout << *it << std::endl;
	}

	std::cout << std::endl << "const_reverse_iterator loop" << std::endl;
	for (auto it = cont.crbegin(); it != cont.crend(); it++) {
		*it = *it + " -crit";
		std::cout << *it << std::endl;
	}

	std::cout << std::endl << "reverse_iterator loop" << std::endl;
	for (auto it = cont.rbegin(); it != cont.rend(); it++) {
		*it = *it + " -rit";
		std::cout << *it << std::endl;
	}


	cont.pop_back();
	std::cout << std::endl << "pop_back()" << std::endl;
	std::cout << "size = " << cont.size() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	cont.push_front("Super first");
	std::cout << std::endl << "push_front(\"Super first\")" << std::endl;
	std::cout << "size = " << cont.size() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	cont.pop_front();
	std::cout << std::endl << "pop_front()" << std::endl;
	std::cout << "size = " << cont.size() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	cont.resize(10);
	std::cout << std::endl << "resize(10)" << std::endl;
	std::cout << "size = " << cont.size() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	cont.resize(5);
	std::cout << std::endl << "resize(5)" << std::endl;
	std::cout << "size = " << cont.size() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	auto it_in = cont.begin();
	it_in++;
	it_in++;
	it_in++;
	cont.insert(it_in, "it_in");
	std::cout << std::endl << "it_in = begin(); it_in++ x4; insert(it_in)" << std::endl;
	std::cout << "size = " << cont.size() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	it_in = cont.begin();
	it_in++;
	cont.erase(it_in);
	std::cout << std::endl << "it_in = begin(); it_in++; erase(it_in)" << std::endl;
	std::cout << "size = " << cont.size() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = cont.begin(); it != cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	mstl::list<std::string> new_cont = cont;
	std::cout << std::endl << "new_cont = cont" << std::endl;
	std::cout << "size = " << new_cont.size() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = new_cont.begin(); it != new_cont.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	mstl::list<std::string> new_cont2(10, "fill");
	std::cout << std::endl << "new_cont2 = list(10, ...)" << std::endl;
	std::cout << "size = " << new_cont2.size() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = new_cont2.begin(); it != new_cont2.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}

	new_cont2.clear();
	std::cout << std::endl << "new_cont2.clear()" << std::endl;
	std::cout << "size = " << new_cont2.size() << std::endl;
	std::cout << "elements:" << std::endl;
	for (auto it = new_cont2.begin(); it != new_cont2.end(); it++) {
		*it = *it + " |";
		std::cout << *it << std::endl;
	}
}

void checkStack() {
	std::cout << std::endl << "==================== Stack ====================" << std::endl;

	mstl::stack<std::string> stack;
	std::cout << std::endl << "stack() //default - vector" << std::endl;
	std::cout << "size = " << stack.size() << " empty = " << stack.empty() << std::endl;

	stack.push("first");
	std::cout << std::endl << "push(\"first\")" << std::endl;
	std::cout << "size = " << stack.size() << " empty = " << stack.empty() << std::endl;
	std::cout << "top = " << stack.top() << std::endl;

	stack.push("second");
	stack.push("third");
	std::cout << std::endl << "push() x2" << std::endl;
	std::cout << "size = " << stack.size() << " empty = " << stack.empty() << std::endl;
	std::cout << "top = " << stack.top() << std::endl;

	stack.pop();
	std::cout << std::endl << "pop()" << std::endl;
	std::cout << "size = " << stack.size() << " empty = " << stack.empty() << std::endl;
	std::cout << "top = " << stack.top() << std::endl;

	stack.pop();
	std::cout << std::endl << "pop()" << std::endl;
	std::cout << "size = " << stack.size() << " empty = " << stack.empty() << std::endl;
	std::cout << "top = " << stack.top() << std::endl;


	mstl::stack<std::string, mstl::list<std::string>> stack1;
	std::cout << std::endl << "stack() //list" << std::endl;
	std::cout << "size = " << stack1.size() << " empty = " << stack1.empty() << std::endl;

	stack1.push("first");
	std::cout << std::endl << "push(\"first\")" << std::endl;
	std::cout << "size = " << stack1.size() << " empty = " << stack1.empty() << std::endl;
	std::cout << "top = " << stack1.top() << std::endl;

	stack1.push("second");
	stack1.push("third");
	std::cout << std::endl << "push() x2" << std::endl;
	std::cout << "size = " << stack1.size() << " empty = " << stack1.empty() << std::endl;
	std::cout << "top = " << stack1.top() << std::endl;

	stack1.pop();
	std::cout << std::endl << "pop()" << std::endl;
	std::cout << "size = " << stack1.size() << " empty = " << stack1.empty() << std::endl;
	std::cout << "top = " << stack1.top() << std::endl;

	stack1.pop();
	std::cout << std::endl << "pop()" << std::endl;
	std::cout << "size = " << stack1.size() << " empty = " << stack1.empty() << std::endl;
	std::cout << "top = " << stack1.top() << std::endl;
}

void checkQueue() {
	mstl::queue<std::string> queue;
	std::cout << std::endl << "queue() //default - list" << std::endl;
	std::cout << "size = " << queue.size() << " empty = " << queue.empty() << std::endl;

	queue.push("first");
	std::cout << std::endl << "push(\"first\")" << std::endl;
	std::cout << "size = " << queue.size() << " empty = " << queue.empty() << std::endl;
	std::cout << "front = " << queue.front() << " back = " << queue.back() << std::endl;

	queue.push("second");
	queue.push("third");
	std::cout << std::endl << "push() x2" << std::endl;
	std::cout << "size = " << queue.size() << " empty = " << queue.empty() << std::endl;
	std::cout << "front = " << queue.front() << " back = " << queue.back() << std::endl;

	queue.pop();
	std::cout << std::endl << "pop()" << std::endl;
	std::cout << "size = " << queue.size() << " empty = " << queue.empty() << std::endl;
	std::cout << "front = " << queue.front() << " back = " << queue.back() << std::endl;

	queue.pop();
	std::cout << std::endl << "pop()" << std::endl;
	std::cout << "size = " << queue.size() << " empty = " << queue.empty() << std::endl;
	std::cout << "front = " << queue.front() << " back = " << queue.back() << std::endl;


	mstl::queue<std::string, mstl::vector<std::string>> queue1;
	std::cout << std::endl << "queue() //vector" << std::endl;
	std::cout << "size = " << queue1.size() << " empty = " << queue1.empty() << std::endl;

	queue1.push("first");
	std::cout << std::endl << "push(\"first\")" << std::endl;
	std::cout << "size = " << queue1.size() << " empty = " << queue1.empty() << std::endl;
	std::cout << "front = " << queue1.front() << " back = " << queue1.back() << std::endl;

	queue1.push("second");
	queue1.push("third");
	std::cout << std::endl << "push() x2" << std::endl;
	std::cout << "size = " << queue1.size() << " empty = " << queue1.empty() << std::endl;
	std::cout << "front = " << queue1.front() << " back = " << queue1.back() << std::endl;

	queue1.pop();
	std::cout << std::endl << "pop()" << std::endl;
	std::cout << "size = " << queue1.size() << " empty = " << queue1.empty() << std::endl;
	std::cout << "front = " << queue1.front() << " back = " << queue1.back() << std::endl;

	queue1.pop();
	std::cout << std::endl << "pop()" << std::endl;
	std::cout << "size = " << queue1.size() << " empty = " << queue1.empty() << std::endl;
	std::cout << "front = " << queue1.front() << " back = " << queue1.back() << std::endl;
}

void checkIterator() {
	mstl::list<std::string> v;
	v.push_back("asdf");
	v.push_back("zxcv");
	v.push_back("qwer");

	mstl::SequenceContainer<std::string, mstl::list<std::string>, mstl::list_iterator<std::string>> *sq = &v;

	mstl::container_iterator<std::string, mstl::list_iterator<std::string>> *it1 = &sq->begin();
	mstl::container_iterator<std::string, mstl::list_iterator<std::string>> *it2 = &sq->end();

	std::cout << std::endl << "=========== Container_iterator ================" << std::endl;

	while (*it1 != *it2) {
		std::cout << **it1 << std::endl;
		(*it1)++;
	}
	std::cout << std::endl;
}

int main() {
	checkVector();
	system("pause");

	checkList();
	system("pause");

	checkStack();
	system("pause");

	checkQueue();
	system("pause");

	checkIterator();
	system("pause");

	return 0;
}