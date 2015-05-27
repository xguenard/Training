#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<utility>

class Node
{
	public:
	int pater;
	std::stack< std::pair< int , int > > neighs;
};

Node  data[1010];

void initialize()
{
	for( int i(0) ; i < 1010 ; ++i )
		data[i].pater = -1;
}

class container
{
	public:
	int nextElem;
	int pater;
	int dist;

	bool operator<( const container & A ) const
	{
		return dist < A.dist ? false : true ;
	}
};

void printQ( const int st, const int ed, const int result )
{
	int tmp(ed);
	std::stack< int > out;
	while( tmp != st )
	{
		out.push( tmp );
		tmp = data[tmp].pater ;
	}
	out.push(st);
	std::printf("%d %d\n",result , (int)out.size() ); 
	while( !out.empty() )
	{
		std::printf("%d ", out.top() );
		out.pop();
	}

	return;
}

void shortestPath( const int st , const int ed )
{
	std::priority_queue< container > pQ;
	container tmp;
	tmp.nextElem = st;
	tmp.pater = st;
	tmp.dist = 0;
	pQ.push( tmp );

	while( !pQ.empty() )
	{
		tmp = pQ.top();
		pQ.pop();
		if( tmp.nextElem == ed )
		{
			data[ed].pater = tmp.pater;
			printQ( st, ed , tmp.dist );
			return;
		}
		if ( data[tmp.nextElem].pater == -1 )
			data[tmp.nextElem].pater = tmp.pater;

		
		while( !data[tmp.nextElem].neighs.empty() )
		{
			container tmp2;
			std::pair< int , int > ii = data[tmp.nextElem].neighs.top();
			tmp2.nextElem = ii.second;
			tmp2.dist = tmp.dist + ii.first;
			tmp2.pater = tmp.nextElem; 
			data[tmp.nextElem].neighs.pop();

			pQ.push( tmp2 );
		}
	}
}

int main()
{
	initialize() ;
	int N, A , st , ed;
	std::scanf("%d%d%d%d", &N , &A , &st , &ed );
	
	for( int i(0) ; i < A ; ++i )
	{
		int a , b , d;
		std::scanf("%d%d%d" , &a , &b , &d );
		data[a].neighs.push( std::make_pair( d, b ) );
		data[b].neighs.push( std::make_pair( d, a ) );
	}
	shortestPath( st, ed );
}

