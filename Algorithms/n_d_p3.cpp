#include <iostream>
#include <vector>

typedef unsigned long long mon_int;

mon_int Pascal_triangle( int K , int N , std::vector< std::vector<mon_int> >& data)
{
  if( K == N) return 1;
  if( K == 1) return N;
  
  if (data[N-1][K-1] != 0 )
    return data[N-1][K-1];
    
  data[N-1][K-1] = Pascal_triangle( K - 1 , N - 1 , data ) + Pascal_triangle( K , N - 1 , data);
  return data[N-1][K-1];
}


int main()
{
  int k,n;
  std::cin >> n >> k ;
  
  std::vector< std::vector< mon_int > > data(n);

  for( int i(n-1) ; i >= 0 ; --i)
    data[i] = std::vector<mon_int>(k);
  
    
  std::cout << Pascal_triangle( k , n+k-1 , data) << "\n";
  return 0;
}
