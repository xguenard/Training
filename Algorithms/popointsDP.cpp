#include<cstdio>
#include<utility>
#include<vector>
typedef std::vector< std::pair< int , int > > vii;
typedef std::pair< int , int > pii;


struct node
{
	vii neighB;
};

node data[1010];

int result[1010][1010] = {{0}};

void init( const int N ) 
{
	for( int i(1); i <= N ; ++i )
		result[0][i] = 0;
}

int process( const int T, const int pos )
{
	//take the best value of the neighbours at time t-1;
	const int sz = data[pos].neighB.size();
	int out = result[T][pos];

	for( int i(0) ; i < sz ; ++i )
	{
		int tmp = result[T][ data[pos].neighB[i].first ];
		tmp += data[pos].neighB[i].second;
		out = out > tmp ? out :  tmp; 
	}
	return out;
}

void calculate( const int N , const int T )
{
	//fill the grid of result
	for( int t(1); t <= T ; ++t )
	{
		int t1 = t-1;
		for( int i(1) ; i <= N ; ++i )
			result[t][i] = process( t1 , i );
	}
}

int main()
{
	int A, N , st , T;
	std::scanf("%d%d%d%d", &N , &A , &st , &T );
	init( N );

	for( int i(0) ; i < A ; ++i )
	{
		int i1, i2 , i3;
		std::scanf("%d%d%d", &i1 , &i2 , &i3 );
		data[i1].neighB.push_back( std::make_pair( i2, i3 ) ) ;
	}
	calculate( N , T ) ;
	std::printf("%d\n", result[T][st] );	
	return 0;

}
