#include<iostream>
#include<vector>
#include<array>
#include<algorithm>

template<  typename T , typename Comparator >
class MaxHeap
{
    //build max heap
    //max heapify
    public:
    MaxHeap( int n , Comparator c ) : data_tree_( std::vector< T >( n ) ), comparator_(c) {};
    
    template< typename Iterator>
    MaxHeap ( Iterator beg , Iterator end , Comparator c) : comparator_(c)
    {
        int dist = std::distance( beg, end );
        data_tree_ = std::vector< T >( dist );
        std::copy( beg, end , data_tree_.begin() ) ;
    }

    void MaxHeapify( const int i)
    {
        
        int size( data_tree_.size() );
        int l( GetLChild(i) );
        int r( GetRChild(i) );
        int largest( i);

        if( l < size && comparator_( data_tree_[l] , data_tree_[i]) )
            largest = l;
        if( r < size &&  comparator_( data_tree_[r] , data_tree_[largest])  )
            largest = r;

        if( largest != i )
        {
            std::swap( data_tree_[i] , data_tree_[ largest ] );
            MaxHeapify( largest );
        }
    }

    void BuildMaxHeap()
    {
        for( int i( data_tree_.size()/2 ) ; i >= 0 ; --i )
            MaxHeapify( i );
    }
    
    void PrintTop()
    {
        std::cout << data_tree_[0] <<"\n";
    
    }

    T GetTop()
    {
        return data_tree_[0];
    }
    
    private:
    std::vector< T > data_tree_;
    Comparator comparator_;

    inline T GetLChild( const int p ){ return (p << 1) + 1; }

    inline T GetRChild( const int p ){ return (p << 1) + 2; }

    inline T GetParent( const int p ){ return (p-1)/2; }
 
};

template< typename T >
struct MaxCompare
{
    bool operator()(const T & a ,const T & b ) const
    {
        return (a > b);
    }
};
