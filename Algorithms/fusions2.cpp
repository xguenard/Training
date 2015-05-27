#include <cstdio>
#include <utility>
#include <vector>
#include <list>

class UnionFind
{
	std::vector< int > p,rank;

	public:

	UnionFind(int N) 
	{
		rank.assign( N , 0 );
		p.assign( N , 0 );
		for ( int i(0) ; i < N ; ++i )
			p[i] = i;
	}
	int findSet( const int i ) { return p[i] == i?  i : findSet(p[i] ); };
	bool isSameSet( const int i, const int j )
	{
		return findSet(i) == findSet(j);
	}
	void unionSet( int i, int j)
	{
		i = findSet(i);
		j = findSet(j);
		if( rank[i] > rank[j] ) p[j] = i;
		else
		{
			p[i] = j;
			if( rank[i] == rank[j] ) rank[j]++;
		}
		return;
	}
};

int main()
{

	int N,R;
	std::scanf("%d%d", &N, &R );
	UnionFind data(N);

	for( int i(0) ; i < R ; ++i)
	{
		int a,b;
		std::scanf("%d%d" , &a , &b);
		if( !data.isSameSet( a , b ) )
		{
			std::printf("%d %d\n" , a , b );
			data.unionSet( a , b );
		}
	}
	return 0;
}
