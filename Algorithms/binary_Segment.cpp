#include<cstdio>
#include<vector>


class BSegTree
{
public:
    std::vector< bool > _b_tree;
    int _N;

    int Left( const int p ) { return (p << 1) + 1; }
    int Right( const int p ) { return (p+1) << 1; }

    BSegTree( const int N )
    {
        _N = N;
        _b_tree.assign( 4 * N , false );
    }

    void Update( int p , int L , int R , int pos , bool val )
    {
        if( pos < L || pos > R ) return;
        //update leaf
        if( L == R )
        {
            _b_tree[ p ] = val;
            return;
        }

        //update children
        int l = Left(p);
        int r = Right(p);
        Update( l , L , (R+L)/2 , pos , val );
        Update( r ,  (R+L)/2 +1 , R , pos , val );
        _b_tree[p] = _b_tree[r] || _b_tree[l];
    }
    
    int Query( int p, int L , int R , int sup_pos )
    {
        if( L > sup_pos ) return -1;
        if( !_b_tree[p] ) return -1;
        if( L == R ) return L;

        int pr = Query( Right(p) , (R+L)/2 + 1 , R , sup_pos );
        if( pr != -1 ) return pr;

        return Query( Left(p) , L , (R+L)/2 , sup_pos );
    }
    void Update( int k , int v ){ Update( 0 , 0 , _N-1 , k , v ); }
    int Query( int pos ){ return Query( 0 , 0 , _N-1 , pos ); }
};





int main()
{
    int N, R;
    std::scanf("%d %d" , &N , &R );
    BSegTree b_tree( N );

    char c;
    int a , b;
    for( int i(0) ; i < R ; ++i )
    {
        std::scanf(" %c", &c );
        if( c == 'M' )
        {
            std::scanf("%d %d", &a , &b );
            b_tree.Update( a , b);
        }
        else
        {
            std::scanf("%d" , &a );
            std::printf("%d\n" , b_tree.Query( a ) );
        }
    }



    return 0;
}

