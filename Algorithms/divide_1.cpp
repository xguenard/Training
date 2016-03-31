#include <cstdio>
#include <iostream>
#include <utility>

const int Sz = 8;
char data[Sz][Sz] = {{ 0 }};

struct cases{ int left_shift, bot_shift; };
cases cases_arr[4] = { { 0, 0 }, { 1, 0 }, { 0, 1 }, { 1, 1 } };
char elem{ 'a' };

template<int N>
void print_data()
{
    for (int i(0); i < N; ++i)
    {
        for (int j(0); j < N; ++j)
            std::printf("%c", data[i][j]);
        std::printf("\n");
    }
}


template< int N>
bool pos_checked(const std::pair< int , int > top_left)
{
    for (int i(0); i < N; ++i)
        for (int j(0); j < N; ++j)
            if (data[top_left.first + i][top_left.second + j] != 0)
                return true;
    return false;
}


template< int N>
void divideEsImpera(const std::pair<int, int > top_left )
{
    const int N2_1 = N / 2 - 1;
    const int N2 = N / 2;
    std::pair< int, int > positions[4] = { top_left
                                         , { top_left.first + N2, top_left.second }
                                         , { top_left.first, top_left.second + N2}
                                         , { top_left.first + N2, top_left.second + N2 } };

    std::pair< int, int > paddings[4] = { { N2_1, N2_1 }, { N2, N2_1 }, { N2_1, N2 }, { N2, N2 } };
    for (int i(0); i < 4; ++i)
    {
        if (!pos_checked< N2 >(positions[i]))
            data[top_left.first + paddings[i].first][top_left.second + paddings[i].second] = elem;
    }
    ++elem;
    
    for (int i(0); i < 4; ++i)
    {
        divideEsImpera<N2>(positions[i]);
    }
}

template<>
void divideEsImpera<2>(const std::pair<int , int > top_left)
{
    for (int i(0); i < 4; ++i)
    {
        int I = top_left.first + cases_arr[i].left_shift;
        int J = top_left.second + cases_arr[i].bot_shift;
    
        if (data[I][J] == 0)
            data[I][J] = elem;
    }
    ++elem;
}


//MAIN AS ANSWER
#ifndef atHome

int main()
{
    int i,j;
    std::scanf("%d%d", &i , &j );
    data[i][j] = '#';
    divideEsImpera<Sz>(std::make_pair<int, int>(0, 0));
    print_data<Sz>();
    return 0;
}

//BOOST UNIT TEST FOR HOME TESTS
#else
#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>

template< int N >
bool check_if_filled()
{
    for( int i(0) ;  i < N ; ++i )
        for( int j(0) ; j < N ; ++j )
            if (data[i][j] == 0)
                return false;
    return true;
}

BOOST_AUTO_TEST_CASE( test1 )
{
    data[1][1] = 'x';
    divideEsImpera<Sz>(std::make_pair< int , int >( 0 , 0 ));
    print_data<Sz>();
    std::printf("simpleTest");
    BOOST_CHECK( check_if_filled<Sz>() );
}

#endif
