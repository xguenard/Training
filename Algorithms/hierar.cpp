#include <cstdio>
#include <vector>

struct node
{
	int pdg;
	int patron;
};

int main()
{
	int N,R;
	std::scanf("%d%d", &N , &R );

	std::vector< node > data(N);
	for( int i(0) ; i < N ; ++i )
	{
		data[i].patron = i;
		data[i].pdg = i;
	}
	for( int i(0) ; i < R ; ++i)
	{
		int a,b;
		std::scanf("%d%d" , &a , &b );
		
		if( a == b)
		{
			std::printf("%d", a );
			while( a != data[a].pdg)
			{
				a = data[a].patron;
				std::printf(" %d", a );
			}
			std::printf("\n");
		}
		else if( data[a].pdg != data[b].pdg)
		{
			int tmp = data[b].pdg;
			data[ tmp  ].patron = data[a].pdg;
			
			for( int j(0) ; j < N ; ++j )
				if(data[j].pdg == tmp )
					data[j].pdg = data[a].pdg;
		}

	}
	return 0;
}
