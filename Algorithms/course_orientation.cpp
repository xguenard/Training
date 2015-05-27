#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

typedef std::vector< std::pair< int , int > > vii;

struct node
{
	vii neighB; // < id , distance >;
};

class element
{
	public:
	int dist;
	int id;
	int range;
	element( const int a, const int b , const int c ) 
		: dist(a) , id(b ) , range(c) {}
	bool operator<( const element & A ) const 
	{
		return dist < A.dist ? false : true ;
	}
};

node data[1010];
void fillData(const int A)
{
	for( int i(0) ; i < A ; ++i )
	{
		int a, b, c;
		std::scanf("%d%d%d", &a , &b , &c );
		data[a].neighB.push_back( std::make_pair( b , c ) );
	}
}

void lowestWay( const int st, const int ed )
{
	std::priority_queue< element > pQ;
	element tmpElem( 0 , st, 0 );
	pQ.push(tmpElem);
	bool found(false);
	int out(0);

	while( !pQ.empty() )
	{
		tmpElem = pQ.top();
		pQ.pop();

		if( tmpElem.range > ed + 1 )
		{
			std::printf("ERREUR\n");
			return;
		}
		if( tmpElem.id == ed )
		{
			if( !found )
			{
				found = true;
				out= tmpElem.dist;
			}
			else
			{
				if( out > tmpElem.dist )
				{
					std::printf("ERREUR\n");
					return;
				}

			}
		}
		
		node  tmpNode = data[ tmpElem.id ] ;
		int N = tmpNode.neighB.size() ;
		int r1 = tmpElem.range +1;

		for( int i(0) ; i < N ; ++i )
		{
			element toPush( tmpNode.neighB[i].second + tmpElem.dist , tmpNode.neighB[i].first
					, r1 );
			pQ.push( toPush );
		}
	}

}


int main()
{
	int A,N;
	std::scanf("%d%d", &N , &A );

	fillData(A );
	lowestWay(1, N);
	return 0;
}
