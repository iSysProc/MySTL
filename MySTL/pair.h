#ifndef PAIR_H
#define PAIR_H

#include "Container.h"

namespace mstl {

	template<typename T1, typename T2>
	struct pair: Container {
		T1 first;
		T2 second;

		pair(const T1 &first,const T2 &second);
		pair(const pair<T1, T2> &p);
	};

	template<typename T1, typename T2>
	pair<T1, T2>::pair(const T1 &first, const T2 &second) {
		this->first = first;
		this->second = second;
	}

	template<typename T1, typename T2>
	pair<T1, T2>::pair(const pair<T1, T2> &p) {
		this->first = p.first;
		this->second = p.second;
	}

}

#endif // !PAIR_H
