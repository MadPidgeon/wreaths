#include <vector>
#include "utility.h"

// Symmetric Group

symmetric_group::element symmetric_group::composition( symmetric_group::element a, symmetric_group::element b ) const {
	element c( n );
	for( int i = 0; i < n; ++i )
		c[i] = a[b[i]];
	return c;
}

symmetric_group::element symmetric_group::inverse( symmetric_group::element a ) const {
	element c( n );
	for( int i = 0; i < n; ++i )
		c[a[i]] = i;
	return c;
}

symmetric_group::element symmetric_group::id() const {
	element c( n );
	for( int i = 0; i < n; ++i )
		c[i] = i;
	return c;
}

// Connected Groupoid

range connected_groupoid::objects() const {
	return range(n);
}

bool connected_groupoid::are_compatible( connected_groupoid::morphism f, connected_groupoid::morphism g ) const {
	return g.target == f.source;
}

connected_groupoid::morphism connected_groupoid::composition( connected_groupoid::morphism f, connected_groupoid::morphism g ) const {

}

connected_groupoid::morphism connected_groupoid::inverse( connected_groupoid::morphism f ) {
	return 
}

connected_groupoid::morphism id( connected_groupoid::object a ) const {
	return connected_groupoid::morphism{ a, a, 0 };
}

// Wreath

wreath::element wreath::composition( wreath::element a, wreath::element b ) const {
	auto o = _category.objects();
	element c( o.size() );
	for( auto x : o )
		c[x] = _category.composition( a[b[x].target], b[x] );
	return c;
}

wreath::element wreath::inverse( wreath::element a ) const {
	auto o = _category.objects();
	element c( o.size() );
	for( auto x : o )
		c[a[x].target] = _category.inverse( a[x] ); 
	return c;
}

wreath::element wreath::id() const {
	auto o = _category.objects();
	element c( o.size() );
	for( auto x : o )
		c[x] = _category.id( x ); 
	return c;

}

wreath::wreath( wreath::cat category ) {
	_category = category;
}
