#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include <array>
#include "maxHeap.hpp"



BOOST_AUTO_TEST_CASE( test1 )
{
    MaxCompare< int > max_comparator;
    std::array< int , 5 > data={ 1 , 3 , 17 , 33 , 8 };
    MaxHeap< int , MaxCompare<int> > max_heap_test1( data.begin() , data.end() , max_comparator );
    max_heap_test1.BuildMaxHeap();

    BOOST_CHECK( max_heap_test1.GetTop() == 33 );
}
