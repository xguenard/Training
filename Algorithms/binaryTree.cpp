#include<cstdio>
#include<vector>

inline int pow2( const int N )
{
	int out(1);
	for( int i(0) ; i < N ; ++i)
		out*=2;
	return out;
}


void rearrange( const int pos, const int val , )
{


}


int main()
{
	int H,R;
	std::scanf("%d%d", &H , &R );
	std::vector< int > data;

	std::vector< std::vector< int > > tree(H);

	int padding(1);
	for( int i(0) ; i < H ; ++i )
	{
		tree[i] = std::vector<int>(padding);
		padding*=2;
	}



	return 0;
}
