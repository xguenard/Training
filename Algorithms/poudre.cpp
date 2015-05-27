#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
#include<stack>


class node
{
	public:
	bool visited;
	std::stack< std::pair< int , int > > voisins;

	node() : visited(false){}
};

class contain
{
	public:
	int id;
	int dis;
	bool operator<( const contain & A ) const
	{
		if( dis < A.dis ) return false;
		if( dis == A.dis )
			return id < A.id ? false : true;
		return true;
	}
};

int main()
{
	int N , A , strt;
	std::scanf("%d%d%d", &N , &A , &strt );

	std::vector< node > data( N+1 );

	for( int i(0) ; i < A ; ++i )
	{
		int a,b,d;
		std::scanf("%d%d%d", &a , &b , &d );
		data[a].voisins.push( std::make_pair( b , d ) ) ;
		data[b].voisins.push( std::make_pair( a , d ) ) ;
	}

	std::priority_queue< contain > Pq;
	contain tmp;
	tmp.id = strt;
	tmp.dis = 0;
	Pq.push( tmp );


	while(!Pq.empty() )
	{
		tmp  = Pq.top();
		Pq.pop();
		if( data[ tmp.id].visited ) continue;
		std::printf("%d %d\n" ,  tmp.dis , tmp.id );
		data[ tmp.id ].visited = true;

		while ( !data[ tmp.id ].voisins.empty() )
		{
			std::pair< int , int > ii = data[tmp.id].voisins.top();
			data[tmp.id].voisins.pop();
			if( !data[ii.first].visited )
			{
				contain T;
				T.id = ii.first;
				T.dis = ii.second + tmp.dis;
				Pq.push(T);
			}
		}
	}
	return 0;
}
