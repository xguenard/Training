#include<cstdio>


//MAIN AS ANSWER
#ifndef atHome

int main()
{
    std::printf("base main ");
    return 0;
}

//BOOST UNIT TEST FOR HOME TESTS
#else
#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>


BOOST_AUTO_TEST_CASE( test1 )
{
    std::printf("base boost");
    BOOST_CHECK( true );
}

#endif
