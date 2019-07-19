#pragma once
#include <iterator>
#include <vector>

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
	const_iterator begin() const {
		return const_iterator{a};
	}
	const_iterator cend() const {
		return const_iterator{b};
	}
	const_iterator end() const {
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
};

class union_find {
	std::vector<int> parent;
public:
	int find( int a );
	int cfind( int a ) const;
	int join( int a, int b );
	bool equivalent( int a, int b ) const;
	union_find( int n );
};