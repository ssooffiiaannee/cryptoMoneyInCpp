#include "../src/base_algorithms.h"
#include <gtest/gtest.h>
#include <tuple>


TEST (BaseAlgorithmsTest, ExtEuclideanAlgo) { // TestSuiteName, TestName
    // EXPECT_EQ((std::make_tuple(1, 2, 3), std::tuple<long, long, long>{1, 1, 3}));
    EXPECT_EQ (std::make_tuple(1, 1, -13), extended_euclidean_algorithm<int>(40, 3));
}

TEST(BaseAlgorithmsTest, toPositiveTest){
    EXPECT_EQ(4, toPositiveModulo<int>(-1, 5));
    EXPECT_EQ(16, toPositiveModulo<int>(-35, 17));
}

// test that points are in curves
// 

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



/*#include <boost/multiprecision/cpp_int.hpp>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>
#include "../src/elliptic_curves.h"
// #include "../src/datastructures.h"


using namespace boost::multiprecision;
// typedef boost::optional<int128_t> oint128_t;

// Point<oint128_t> INF (boost::none, boost::none);

int main(){
	oint128_t a = boost::none;
	// a = 3;
	// std::cout << a << a << std::endl;
	// std::cout << (a == boost::none) << std::endl;
	// std::cout << (CST::INF == Point<oint128_t> (boost::none, boost::none)) << std::endl;

	// Point<oint128_t> P((oint128_t) 90, (oint128_t) 5);
	// Point<oint128_t> Q((oint128_t) 91, (oint128_t) 31);
	Point<oint128_t> P(90, 5);
	Point<oint128_t> Q(91, 31);
	// if(P == Q) 
	// 	std::cout << "h" << std::endl;
	// std::cout << (P == Q) << std::endl;
	// EllipticCurve<oint128_t> curve(0, 33, 17, 97);

	// Point<oint128_t> R = curve.add(P, Q);
	// std::cout << R.x << " " << R.y << std::endl;
}*/

/*#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/optional.hpp>
#include "../src/datastructures.h"

using namespace boost::multiprecision;

template<class T>
struct Point
{
    explicit Point(T x, T y): x (x), y (y){}
    T x;
    T y;
};


int main(){
    Point<int128_t> Q(-1, -1);
    // std::cout << CST::INF.x << std::endl;
    // std::cout << (Q == CST::INF) << std::endl;
    // std::cout << (Q == Point<int>(-1, -1)) << std::endl;
    std::cout << (Q == CST_int128_t::INF) << std::endl;
}*/

