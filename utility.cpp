#include "utility.h"

class union_find {
	mutable std::vector<int> parent;
public:
	int find( int a ) const;
	int join( int a, int b );
	bool equivalent( int a, int b ) const;
	union_find( int n );
};

int union_find::find( int a ) const {
	int b = a, c;
	while( parent[b] != b )
		b = parent[b];
	while( parent[a] != a ) {
		c = parent[a];
		parent[a] = b;
		a = c;
	}
	return b;
}

int union_find::join( int a, int b ) {
	parent[find(a)] = b;
}

bool union_find::equivalent( int a, int b ) const {
	return cfind( a ) == cfind( b );
}

union_find::union_find( int n ) : parent( n ) {
	for( int i = 0; i < n; ++i )
		parent[i] = i;
}

