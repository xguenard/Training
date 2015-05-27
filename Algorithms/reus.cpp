#include<cstdio>                                                                
#include<vector>                                                                
#include<cmath>                                                                 
#include<utility>

std::vector< int > data;

void primes( int n)                                                             
{                                                                               
  std::vector< bool > sieve(n+1);                                               
  for( int i(0); i <= n ; i++)                                                  
  {                                                                             
    sieve[i] = true;                                                            
  }                                                                             
                                                                                
  if( n == 0 )                                                                  
  {                                                                             
    return;                                                                     
  }                                                                             
  else if( n == 1 )                                                             
  {                                                                             
    return;                                                                     
  }                                                                             
  else                                                                          
  {                                                                             
    for( int i(2) ; i <= n ; i++ )                                              
    {                                                                           
      if( sieve[i] ) data.push_back(i);
      if( i <= int(std::sqrt( n )+1 ) )                                            
        for( int j( i*i ) ; j <= n ; j+=i )                                     
            sieve[j] = false;                                                   
    }                                                                           
  }                                                                             
}                                                                               
                                                                                
int main()                                                                      
{                                                                               
  int in;                                                                       
  std::scanf("%d", &in);                                                        
  primes( in/2 );                                                                 

	std::vector< std::pair<int , int > > out;	

	for( int i(0) ; i < int(data.size() ) ; ++i )
		if(data[i]%in == 0 )
			out.push_back( std::make_pair( data[i] , in/data[i] ) );

	if( out.empty() )
		std::printf("0\n");
	else
	{
		for( int i(0) ; i < int( out.size() ) ; ++i )
			std::printf("%d\n",out[i].first);

		for( int i( int(out.size()) -1) ; i >= 0 ; --i )
			std::printf("%d\n",out[i].second);
	}


                                                                                
  return 0;                                                                     
}  
