#pragma once
#include <iterator>

class range {
	int a, b;
public:
	struct const_iterator {
		typedef int value_type;
		value_type i;
		value_type operator*() {
			return i;
		}
		const_iterator& operator++() {
			++i;
			return *this;
		}
		bool operator!=( const_iterator other ) {
			return i != other.i;
		} 
	};
	const_iterator cbegin() const {
		return const_iterator{a};
	}
	const_iterator cend() const {
		return const_iterator{b};
	}
	size_t size() const {
		return b-a;
	}
	range( int begin, int end ) {
		a = begin;
		b = end;
	}
	range( int end ) : range( 0, end ) {}
}