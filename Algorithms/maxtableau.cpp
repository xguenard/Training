#include<cstdio>
#include<vector>
#include<algorithm>

std::vector< int > data;
int pow2( const int T )
{
	int out(1);
	for( int i(0) ; i < T ; ++i )
		out *= 2;
	return out;
}


int binaryMax( const int N, const int st, const int ed )
{
	if( N == 2)
		return data[st-1]>data[ed-1]? data[st-1] : data[ed-1];

	int out(0);
	int N2 = N/2;
	int Dr = binaryMax( N2 , ed-N2 , ed );
	int Ga = binaryMax( N2 , st , st + N2 );
	out = Dr > Ga ? Dr : Ga;
	return out;
}

int main()
{
	int H, R ;
	std::scanf("%d%d", &H, &R );
	int out(0);
	H = pow2(H);
	data = std::vector< int >(H);

	for( int i(0) ; i < R ; ++i )
	{
		int tmp, nb;
		scanf("%d%d",&nb, &tmp );
		data[nb] = tmp;
		out = binaryMax(H , 0 , H-1 ); 
		std::printf("%d\n", out );
	}

	return 0;
}
