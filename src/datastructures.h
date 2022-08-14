#ifndef DATASTRUCTURES
#define DATASTRUCTURES

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/optional.hpp>

using namespace boost::multiprecision;

#define BYTE_SIZE (int) 8

template<typename T>
struct Curve{
    explicit Curve(T p = 0, T a = 0, T b = 0): p(p), a(a), b(b){}
    T p;
    T a;
    T b;
};

template<class T>
struct Point
{
	explicit Point(){}
	explicit Point(Curve<T> curve, T x, T y): curve (curve), x (x), y (y){}
    Curve<T> curve; // the curve where the point is located
    T x;
    T y;
};

template<typename T>
struct Generator{
    explicit Generator(Point<T> G, int n): G(G), n(n){

    }

    Point<T> G;
    int n;
};

template<class T>
bool operator==(const Point<T> &a, const Point<T> &b)
{
    return compare(a, b);
}

template<class T>
bool compare(const Point<T> &a, const Point<T> &b)
{
    if(b.x == a.x && b.y == a.y)
        return true;
    else 
        return false;
}

namespace CST_int128_t{
    Curve<int128_t> InfCurve(0, 0, 0);
    Point<int128_t> INF (InfCurve, -1, -1);
}

namespace CST_int256_t{
    Curve<int256_t> InfCurve(0, 0, 0);
    Point<int256_t> INF (InfCurve, -1, -1); // point at infinity
}


#endif