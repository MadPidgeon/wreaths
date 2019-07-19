#include <vector>
#include <exception>
#include "utility.h"
#include "wreath.h"

// Symmetric Group

symmetric_group::element symmetric_group::composition( element a, element b ) const {
	element c( n );
	for( int i : range(n) )
		c[i] = a[b[i]];
	return c;
}

symmetric_group::element symmetric_group::inverse( element a ) const {
	element c( n );
	for( int i : range(n) )
		c[a[i]] = i;
	return c;
}

symmetric_group::element symmetric_group::id() const {
	element c( n );
	for( int i : range(n) )
		c[i] = i;
	return c;
}

symmetric_group::cycles symmetric_group::element_to_cycles( element a ) const {
	cycles c;
	c.element_orbit.assign( n, std::make_pair( -1, -1 ) );
	for( int i : range(n) ) {
		if( c.element_orbit[i].first == -1 ) {
			std::vector<int> orbit;
			int j = i;
			do {
				c.element_orbit[j].first = c.orbits.size();
				c.element_orbit[j].second = orbit.size();
				orbit.push_back(j);
				j = a[i];
			} while( i != j );
			c.orbits.push_back( std::move( orbit ) );
		}
	}
	return c;
}

// Connected Groupoid

range connected_groupoid::objects() const {
	return range( _n );
}

bool connected_groupoid::are_compatible( morphism f, morphism g ) const {
	return g.target == f.source;
}

connected_groupoid::morphism connected_groupoid::composition( morphism f, morphism g ) const {
	if( not are_compatible( f, g ) )
		throw std::runtime_error( "Morphisms not compatible" );
	return morphism{ g.source, f.target, _comp[f.id][g.id] };
}

connected_groupoid::morphism connected_groupoid::inverse( morphism f ) const {
	return morphism{ f.target, f.source, _inv[f.id] };
}

connected_groupoid::morphism connected_groupoid::id( object a ) const {
	return morphism{ a, a, 0 };
}

// Wreath

wreath::element wreath::composition( element a, element b ) const {
	auto o = _category.objects();
	element c( o.size() );
	for( auto x : o )
		c[x] = _category.composition( a[b[x].target], b[x] );
	return c;
}

wreath::element wreath::inverse( element a ) const {
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

wreath::wreath( cat category ) {
	_category = category;
}

symmetric_group::element wreath::object_restriction( element a ) const {
	auto o = _category.objects();
	symmetric_group::element alpha( o.size() );
	for( auto x : o )
		alpha[x] = a[x].target;
	return alpha;
}

wreath::element wreath::conjugator( element a, element b ) const {
	auto o = _category.objects();
	symmetric_group Sn( o.size() );
	symmetric_group::element alpha = object_restriction( a ), beta = object_restriction( b );
	symmetric_group::cycles A = Sn.element_to_cycles( alpha ), B = Sn.element_to_cycles( beta );
	
}