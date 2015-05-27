#include<cstdio>
#include<utility>
#include<vector>
#include<map>

struct node
{
	std::vector< std::pair< int , int >  > neighB;
};

node data[1010];
std::map< std::pair< int , int > ,  int > DP;
int _min(-1000000000);

void initialize( const int N )
{
	for( int i(0) ; i < N ; ++i )
		data[i].neighB.push_back( std::make_pair( i , 0 ) ) ;
}

int biggest( const int st , const int T, const int val )
{
	if( T == 0 )
	{
		if(val > _min) _min = val;
		return 0;
	}
	
	const int N = (int)data[st].neighB.size() ;
	const int T1 = T-1;
	int out(0);
	bool tested(false);
	std::map< std::pair< int , int >,int >::iterator it = DP.find( 
			std::make_pair( st, T1 ) );
	if( it != DP.end() )
		return it->second;

	for( int i(0) ; i < N ; ++i )
	{
		int tmp =biggest( data[st].neighB[i].first 
					, T1 , val + data[st].neighB[i].second );
		if( !tested)
			out = tmp;
		else
			out = out > tmp ? out : tmp ;
	}
	DP[ std::make_pair( st, T1 ) ] =  out  ;
	return out;
}

int main()
{
	int N, A , st , T;
	std::scanf("%d%d%d%d",&N , &A , &st , &T );
	initialize( N ) ;

	for( int i(0) ; i < A ; ++i )
	{
		int i1,i2,i3;
		std::scanf("%d%d%d", &i1, &i2 , &i3 );
		data[i1].neighB.push_back( std::make_pair( i2 , i3 ) );
	}
	biggest( st, T , 0 ) ;
	std::printf("%d\n", _min );
	return 0;
}
