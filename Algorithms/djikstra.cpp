#include<cstdio>
#include<cstring>
#include <queue>
#include <utility>

int data[1010][1010] ;
int L , C;

const int Y[4] = { -1 , 1 , 0 , 0 };
const int X[4] = { 0 , 0 , 1 , -1 };

class Node
{
	public:
	int dist;
	int i;
	int j;

	Node( const int _i , const int _j , const int _dist)
		: dist(_dist) , i(_i) , j(_j) {}

	bool operator<( const Node & A ) const
	{
		return dist < A.dist ? false : true;
	}

};


inline void setZero()
{
	std::memset( data , 0 , sizeof(data) );
}

inline int charInt( const char a )
{
	if( a == '.' ) return 0;
	if( a == '#' ) return -1;
	
	return int(a - '0') ;
}

void fill()
{
	std::scanf("%d %d", &L , &C);
	for( int i(0) ; i < L ; ++i)
		for( int j(0) ; j < C ; ++j)
		{
			char tmp;
			std::scanf( "%c", &tmp );
			if( tmp == '\n' )
				std::scanf( "%c", &tmp );
			data[i][j] = charInt(tmp);
		}
}

void print()
{
	for( int i(0) ; i < L ; ++i)
	{
		for( int j(0) ; j < C ; ++j)
			std::printf("%d ", data[i][j] );
		std::printf("\n");
	}
}

inline bool isOk( const int i , const int j ) 
{
	if( i <= 0 || i >= L ) return false;
	if( j <= 0 || j >= C ) return false;
	if( data[i][j] < 0 ) return false;	
	return true;
}
inline bool isend( const int i , const int j )
{
	if( i == L-1 && j == C-2 ) return true;
	return false;
}
int main()
{
	setZero();
	fill();

	std::priority_queue< Node  > Pq; 

	Node tmp( 1 , 0 , data[1][0] );
	Pq.push( tmp );
	while( !Pq.empty()  )
	{
		Node N = Pq.top();
		Pq.pop();
		int dist = data[ N.i ][N.j];
		if( isend( N.i , N.j ) )
		{
			std::printf("%d\n", dist+N.dist );
			return 0;
		}
		data[ N.i ][N.j] = -1;

		for( int k(0) ; k < 4 ; ++k )
		{
			int i = N.i + X[k] ;
			int j = N.j + Y[k] ;
			if( isOk(i , j ) )
			{
				Node elem( i , j , N.dist + data[i][j] );
				Pq.push( elem) ;
			}
		}
	}
	return 0;
}

