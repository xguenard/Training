#include<cstdio>
#include<cstring>

int data[1010][1010] ;
int L , C;

const int Y[4] = { -1 , 1 , 0 , 0 };
const int X[4] = { 0 , 0 , 1 , -1 };
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

int recursive( const int i , const int j  )
{
	if( i ==  L-1 && j == C-2 ) 
	{
		return data[i][j];
	}
	if( i <= 0 || i >= L ) return -1;
	if( j <= 0 || j >= C ) return -1;
	if( data[i][j] < 0 ) return -1;	

	int T = data[i][j];
	data[i][j] = -1;

	int out  = -1;

	for(int k(0) ; k < 4 ; ++k )
	{
		int tmp = recursive( i + X[k] , j + Y[k]);
		if ( tmp >= 0 ) 
		{
			if ( out >= 0 )
				out = tmp < out ? tmp : out;
			else
				out = tmp;
		}
	}
	data[i][j] = T;
	if( out >=0 )
		return out + T;
	else
		return out;
}

int travel()
{
	int out = data[1][0];
	data[1][0] = -1;
	return out + recursive( 1 , 1  );
}
int main()
{
	setZero();
	fill();
	std::printf("%d\n", travel() );
	return 0;
}

