#include<cstdio>
#include<vector>

class SumTree
{
public:
    std::vector< int > data;
    std::vector< int > tree;
    int N;
    int inline CLeft ( const int p ){ return (p << 1 )+1; }

    int inline CRight ( const int p ){ return ( (p+1) << 1 )  ; }
    
    int inline Parent( const int p ){ return (p-1)>>1; }
    
    SumTree( std::vector< int > & A)
    {
        data = A;
        N = (int)data.size();
        tree.assign( 4 * N , 0 );
        build_tree(0 , 0 , N - 1 );
    }

    void build_tree( int node, int L , int R )
    {
        if( L == R )
        {
            tree[node] = data[L];
            data[L] = node;
            return;
        }

        build_tree( CLeft( node ) , L , (L+R)/2 );
        build_tree( CRight( node ) ,  (L+R)/2 +1 , R );
        tree[ node ] = tree[ CLeft( node )]  + tree[ CRight( node )] ; 
        return;
    }


    
    void update( int p , int diff)
    {
        tree[ p ] += diff;
        if( p != 0 )
            update( Parent(p ) , diff);
    }

    void change_value( int position , int value )
    {
       int node = data[position];
       int diff = value - tree[ node ] ;
       tree[node] = value;

       update( Parent(node) , diff );
    }

    int rmq( int i , int j ) { return rmq( 0  , 0 , N-1 , i , j ) ; }
    
private:
    int rmq ( int p , int L , int R , int i , int j )
    {
        if( i > R || j < L ) return 0;

        if( L >= i && R <= j ) return tree[p];

        int p1 = rmq( CLeft( p ) , L , ( L + R )/2 , i , j );
        int p2 = rmq( CRight( p ) , (L + R )/2 + 1 , R , i , j );
        return p1 + p2;
    }           
};
