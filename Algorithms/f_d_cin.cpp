#include<cstdio>
#include<vector>
#include<algorithm>


class date
{
	public:
	int m_f, m_s; //finish date, start date
	
	date() : m_f(0), m_s(0) {}

	bool operator<( const date & A ) const
	{
		if( m_f < A.m_f ) return true;
		if( m_f == A.m_f && m_s > A.m_s ) return true;
		return false;
	}
};

int main()
{
	//Acquisition
	int card_in;
	std::scanf("%d", & card_in );
	std::vector< date > in( card_in );
	
	for( int i(0); i < card_in ; i++ )
		std::scanf("%d%d", & in[i].m_s , & in[i].m_f );

	//Processing
	
	std::sort( in.begin() , in.end() );
	
	int temp_f(in[0].m_f);
	int out(1);
	for( int i(0); i < card_in ; i++ )
		if( in[i].m_s > temp_f )
		{
			temp_f = in[i].m_f;
			out++;
		}
	std::printf("%d\n", out );

	return 0;
}
