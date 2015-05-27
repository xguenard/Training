#include<cstdio>

typedef unsigned long long long_int;

long_int fibonacci( int N )
{
	if( N <= 1 ) return N;

	return fibonacci( N - 2) + fibonacci( N - 1 );
}

long_int fibonacci_2( int N )
{
	long_int out(1);
	long_int a(0), t(0);
	while( N-- > 1 ) 
	{
		t = a;
		a = out;
		out += t;
	}
	return out;
}

int main()
{
	int in;
	std::scanf("%d", &in );

	std::printf("%llu\n", fibonacci( in ) );
	return 0;
}
