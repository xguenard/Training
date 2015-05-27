#include <cstdio>
#include <vector>



int main()
{
	int N;
	std::scanf("%d" , &N );

	int N1( (N-2)/2 );
	int N2( N/2 - (N+1)%2 );

	std::printf("%d %d\n", N1 + 1 , N2 );
	std::printf("1 2\n");

	for(int i(0) ; i < N1; ++i)
	{
		std::printf("%d %d\n", 3+i , N-i);
	}

	for(int i(0) ; i < N2 ; ++i )
	{
		std::printf("%d %d\n", 2+i , N-i );
	}


	return 0;
}
