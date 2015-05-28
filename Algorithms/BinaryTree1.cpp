#include <cstdio>
#include <vector>
#include <cmath>

std::vector< std::vector< int > > data;

inline int pow2( const int N)
{
	return 1<<N;
}

void init( const int N )
{
	std::vector< int > tmp;

	for( int i(N) ; i > -1 ; --i)
	{
		tmp.resize( pow2(i) );
		data.push_back( tmp );
	}
}

inline void maxElem( const int K, const int pos )
{
	data[K][pos] = std::max( data[K-1][ 2*pos], data[K-1][ 2*pos+1] );
}

void changeElem( const int N , int pos, const int val )
{
	data[0][pos] = val;

	for( int i(1) ; i <= N ; ++i )
	{
		pos = std::floor( pos/2 );
		maxElem( i , pos ) ;
	}
}

int main()
{
	int H, R;
	std::scanf("%d%d" , &H , &R );

	init( H );

	int pos,val;
	for( int i(0) ; i < R ; ++i )
	{
		std::scanf("%d%d", &pos , & val );
		changeElem( H , pos , val );
		std::printf("%d\n" , data[H][0] );
	}

	return 0;
}
