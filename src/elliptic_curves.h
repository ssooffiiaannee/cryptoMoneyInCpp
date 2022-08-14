#ifndef ELLIPTIC_CURVES
#define ELLIPTIC_CURVES

#include "base_algorithms.h"
#include "datastructures.h"
#include <iostream>
#include <vector>
#include <math.h>

template<typename T>
struct EllipticCurve{
    explicit EllipticCurve(T seed, T a, T b, T p): seed(seed), a (a), b (b), p (p)
    {
        assert((4 * a * a * a + 27 * b * b) % p != 0);
    }
    ~EllipticCurve()
    {

    }
    Point<T> mult(const Point<T> &P, T n)
    {
        bool first = true;
        Point<T> Q = P;
        Point<T> ans = Q;
        while(n != 0)
        {
            if(n % 2 && !first)
                ans = add(ans, Q);
            else if(n % 2 && first)
            {
                ans = Q;
                first = false;
            }
            Q = add(Q, Q);
            n /= 2;
        }
        return ans;
    }
    
    Point<T> add(const Point<T> &P, const Point<T> &Q)
    {
        T m;
        if(P == Q)
        {
            m = (3 * P.x * P.x + a) * inverse(toPositiveModulo(2 * P.y, p), p);
        }
        else
        {   
            // std::cout << inverse(toPositiveModulo(P.x - Q.x, p), p) << std::endl;
            m = toPositiveModulo(P.y - Q.y, p) * inverse(toPositiveModulo(P.x - Q.x, p), p);
        }
        m %= p;

        Point<T> R;
        R.x = toPositiveModulo(m*m - P.x - Q.x, p);
        R.y = toPositiveModulo(P.y + m * (R.x - P.x), p);
        return R;
    }
    // same order as initialization to avoid -Wreorder error
    T seed, a, b, p;
};

namespace sha{
    template <typename T>
    T rotr(T x, int n, int size=32){
        return (x >> n) | (x << size - n) & (2 << size - 1);
    }

    template <typename T>
    T shr(T x, int n){
        return x >> n;
    }

    template <typename T>
    T sig0(T x){
        return rotr(x, 7) ^ rotr(x, 18) ^ shr(x, 3);
    }

    template <typename T>
    T sig1(T x){
        return rotr(x, 17) ^ rotr(x, 19) ^ shr(x, 10);
    }

    template <typename T>
    T capsig0(T x){
        return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22);
    }

    template <typename T>
    T capsig1(T x){
        return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25);
    }

    template <typename T>
    T ch(T x,T y,T z){
        return (x & y)^ (~x & z);
    }

    template <typename T>
    T maj(T x,T y,T z){
        return (x & y) ^ (x & z) ^ (y & z);
    }

    bool isLittleEndian(){
        long long x = 1;
        return (*(char *)&x == 1);
    }

    template <typename T>
    T switchEndianess(T x){
        T x_l = 0;
        T mask = 0xff;
        if(! isLittleEndian()){
            int sz = sizeof(x);
            for(int i = 0; i<sz; i++){
                mask = (mask << i * BYTE_SIZE);
                x_l |= ((x & mask) << ((sz - i - 1) * BYTE_SIZE)); 
                // cout << std::hex << x_l << endl;
            }
        }
        return x_l;
    }

    template <typename T>
    T toBig(T x){
        if(isLittleEndian()){
            return switchEndianess(x);
        }
        return x;
    }

    template <typename T>
    bool isPrime(T n){
        for(T i = 0; i*i < n; i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }

    template <typename T>
    std::vector<T> first_n_primes(T n){
        std::vector<T> v;
        T i = 2;
        while((int) v.size() < n){
            if(isPrime(i))
                v.push_back(i);
            i++;
        }
        return v;
    }

    int frac_bin(float f, int n = 32){
        f -= (int) f;
        f *=  pow(2, n);

        return (int) f;
    }

    std::vector<int> genK(){
        std::vector<int> primes = first_n_primes(64);
        std::vector<int> v;
        for(auto &val: primes){
            v.push_back(frac_bin(pow(val, 1.0/3.0)));
        }
        return v;
    }

    std::vector<int> genH(){
        std::vector<int> primes = first_n_primes(8);
        std::vector<int> v;
        for(auto &val: primes){
            v.push_back(frac_bin(pow(val, 1.0/2.0)));
        }
        return v;
    }

    int512_t pad(const char *s){
        int l = strlen(s);
        int512_t b = 0;
        for(int i = 0; i<l; i++){
            int512_t mid = (int512_t) s[i];
            b |= (mid << (BYTE_SIZE*i));
        }
        b |= (128 << (BYTE_SIZE*l));
        b |= toBig (l * BYTE_SIZE);
        return b;
    }
}

#endif