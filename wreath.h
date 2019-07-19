#pragma once
#include <vector>
#include <utility>
#include "utility.h"

struct symmetric_group {
	typedef std::vector<int> element;
	struct cycles {
		std::vector<std::pair<int,int>> element_orbit;
		std::vector<std::vector<int>> orbits;
	};

	int n;

	element composition( element a, element b ) const;
	element inverse( element a ) const;
	element id() const;
	
	cycles element_to_cycles( element a ) const;
	// element cycles_to_elements( element a ) const;

	symmetric_group( int _n );
};

class group {
public:
	typedef int element;
private:
	std::vector<std::vector<element>> _comp;
	std::vector<element> _inv;
public:
	size_t size() const;
	element composition( element a, element b ) const;
	element inverse( element a ) const;
	element id() const;
	symmetric_group::element cayley( element a ) const;
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
	symmetric_group::element object_restriction( element a ) const;
	element conjugator( element a, element b ) const;
	wreath( cat category );
};

