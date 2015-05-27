#include <cstdio>
#include <utility>
#include <vector>


int main()
{

	int N,R;
	std::scanf("%d%d", &N, &R );

	std::vector< std::pair<int , int > > data(N);

	for(int i(0) ; i < N ; ++i)
	{
		data[i].first = i;
		data[i].second = i;
	}

	for( int i(0) ; i < R ; ++i )
	{
		int a,b;
		std::scanf("%d%d", &a , &b );

		if( data[a].second != data[b].second)
		{
			int tmp = data[b].second;
			std::printf("%d %d\n", a , b );
			for( int j(0) ; j< N ; ++j )
				if( data[j].second == data[a].second )
					data[j].second = tmp;
		}
	}

	return 0;
}
