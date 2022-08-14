#ifndef BASE_ALGORITHMS
#define BASE_ALGORITHMS
#include <iostream>
#include <tuple>
#include <cassert>

template<typename T>
T toPositiveModulo(T a, T p)
{
    // std::cout << "toPositiveMOdulo : " << a << " " << p << std::endl;
    // assert(p > 0 && "Modulo number has to be positive !");
    assert(((void) "Modulo number has to be positive !", p > 0));
    if(a >= 0)
        return a % p;
    else
        return ((-a/p + 1)*p + a) % p;
}

template<typename T>
T binaryMultiplication(T P, T n, T mod)
{
    T mid = P;
    T ans = 0;
    while(n != 0)
    {
        if(n % 2)
            ans = (ans + mid) % mod;
        mid = (2*mid) % mod;
        n /= 2;
    }
    return ans;
}

template<typename T>
T binaryExponentiation(T P, T n, T mod)
{
    T mid = P;
    T ans = 1;
    while(n != 0)
    {
        if(n % 2)
            ans = (ans * mid) % mod;
        mid = (mid*mid) % mod;
        n /= 2;
    }
    return ans;
}

template<typename T>
void test(T a){
    std::cout << "hello " << a << std::endl;
}

template<typename T>
std::tuple<T, T, T> extended_euclidean_algorithm(T a, T b)
{
    std::cout << "euclidean algo : " << a << " " << b << std::endl;
    T s = 0, old_s = 1;
    T t = 1, old_t = 0;
    T r = b, old_r = a;
    while(r != 0)
    {
        T quotient = old_r/r;
        T r_ = r;
        r = old_r - quotient * r;
        old_r = r_;
        
        T s_ = s;
        s = old_s - quotient * s;
        old_s = s_;

        T t_ = t;
        t = old_t - quotient * t;
        old_t = t_;
    }
    return std::tuple<T, T, T>{old_r, old_s, old_t};
}

template<typename T>
T inverse(T n, T p)
{
    std::cout << "inverse : " << n << " " << p << std::endl;
    auto [gcd, x, y] = extended_euclidean_algorithm(n, p);
    assert ((n * x + p * y) % p == gcd);

    if(gcd != 1)
    {
        std::cout << "n = " << n << " and p = " << p << " may not be coprime." << std::endl;
        throw std::invalid_argument("Check parameters !");
    }
    return x % p;
}
#endif