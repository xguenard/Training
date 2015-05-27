#include<cstdio>
#include<vector>
#include<algorithm>

class machine
{
	public:
	short m_etime;//end time
	short m_ptime;//process time

	machine() : m_etime(0), m_ptime(0) {}
};

class ligne_prod
{
	public:
	std::vector< machine > m_machines;
	int m_inuse;
	ligne_prod( int card ) : m_machines(card) , m_inuse(0) {}

	int assign( int in , const int timer)
	{
		for( std::size_t i(m_machines.size()) ; i > 0 ; --i )
		{
			if( timer >= m_machines[i-1].m_etime )
			{
				m_machines[i-1].m_etime = timer + m_machines[i-1].m_ptime ;
				--in;
			}
		}
		return in;
	}
};




int main()
{
	int N, M1;
	std::scanf("%d%d", &N , & M1 );
	
	ligne_prod ligne1( M1 );

	for( int i(0) ; i < M1 ; i++ )
		std::scanf("%hd", & ligne1.m_machines[i].m_ptime );
	
	return 0;
}
