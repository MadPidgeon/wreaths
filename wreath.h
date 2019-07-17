#pragma once
#include <vector>
#include "utility.h"

struct symmetric_group {
	typedef std::vector<int> element;
	int n;

	element composition( element a, element b ) const;
	element inverse( element a ) const;
	element id() const;
	symmetric_group( int _n );
};

class connected_groupoid {
public:
	typedef int object;
	struct morphism {
		object source, target;
		int id;
	};
private:
	int _n, _k;
	std::vector<std::vector<int>> _comp;
	std::vector<int> _inv;
public:
	range objects() const;
	bool are_compatible( morphism f, morphism g ) const;
	morphism composition( morphism f, morphism g ) const;
	morphism inverse( morphism f ) const;
	morphism id( object a ) const;
};

class wreath {
public:
	typedef connected_groupoid cat;
	typedef std::vector<cat::morphism> element;
private:
	cat _category;
public:
	element composition( element a, element b ) const;
	element inverse( element a ) const;
	element id() const;
	wreath( cat category );
};

