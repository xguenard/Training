#include<vector>

template< typename Comparator >
class SegmentTree
{
    //Work on all associative binary function applied on range of datas

private:
    std::vector< int > st,A;
    Comparator comparator;
    int n;
    inline int Left( const int p ){ return p << 1 ;}
    inline int Right( const int p){ return (p << 1) + 1; }
    inline int PLeft( const int p ){ return p >> 1; }
    inline int PRight( const int p){ return (p >> 1) + 1;}

    void Build( int p , int L , int R )
    {
        if (L == R )
            st[p] = L ;
        else
        {
            Build( Left(p) , L , ( L+R)/2 );
            Build( Right(p) , (L+R)/2 + 1 , R );
            int p1 = st[ Left(p) ], p2 = st[ Right(p) ];
            st[p] = ( comparator( A[p1] , A[p2]) ) ? p1 : p2;
        }
    }

    int Rmq( int p , int L , int R , int i , int j )
    {
        if( i > R || j < L ) return -1;
        if( L >= i && R <=j ) return st[p];

        int p1 = Rmq( Left(p), L , (L+R)/2 , i , j );
        int p2 = Rmq( Right(p) , (L+R)/2 + 1 , R , i , j );
         if( p1 == -1) return p2;
         if( p2 == -1) return p1;

         return ( comparator( A[p1] , A[p2] ))? p1 : p2 ;
    }


public :
    SegmentTree( const std::vector< int > & _A , Comparator c )
    {
        A = _A;
        n =( int) A.size();
        comparator = c;
        st.assign( 4 * n , 0 ) ;
        Build( 1 , 0 , n -1 ) ;
    }
    int Rmq( int i , int j ) { return A[Rmq( 1 , 0 , n -1 , i , j )]; }
};


#include<cstdio>

struct Max
{
    bool operator()( int A , int B ) const { return A > B ? true : false ;}
};
int main()
{
    int N ;
    std::scanf( "%d" , &N );
    std::vector< int > data( N );

    for( int i(0 ) ; i < N ; ++i )
        std::scanf( "%d" , &data[i] );
    
    Max m;
    SegmentTree< Max > segTree( data , m );

    int I;
    std::scanf( "%d" , &I );
    int a, b;
    for( int i(0) ; i < I ; ++i )
    {
        std::scanf("%d%d" , &a , &b );
        std::printf( "%d\n", segTree.Rmq( a , b ));
    }
    return 0;
}
