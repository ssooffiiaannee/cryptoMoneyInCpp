// g++ -std=c++17 main.cpp -o prog
#include <iostream>
#include <tuple>
// #include "base_algorithms.h"
// #include "datastructures.h"
#include "elliptic_curves.h"
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;

int main(int argc, char const *argv[]){
    // cout << sha::isLittleEndian() << endl;
    // char * c = "this";
    // cout << strlen(c) << endl;
    cout <<  int512_t{-sha::pad("365")}.str(0, std::ios::hex | std::ios::showbase) << endl;
    cout << int512_t{1}.str(0, std::ios::hex) << endl;
}



// int main(int argc, char const *argv[])
// {
//     // test<int>(33);
//     /*auto [a, b, c] = extended_euclidean_algorithm<int>(40, 3);
//     printf("%d %d %d", a, b , c);*/
//     // std::cout << std::numeric_limits<int512_t>::max() << endl;
//     // int512_t a("0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F");

//     Curve<int512_t> bitcoin_curve(
//         int512_t("0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F"),
//         int512_t("0x0000000000000000000000000000000000000000000000000000000000000000"), //# a = 0
//         int512_t("0x0000000000000000000000000000000000000000000000000000000000000007") //# b = 7
//     );
    
//     Point<int512_t> G(
//         bitcoin_curve,
//         int512_t("0x79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798"),
//         int512_t("0x483ada7726a3c4655da4fbfc0e1108a8fd17b448a68554199c47d08ffb10d4b8")
//     );

//     int512_t a = binaryExponentiation<int512_t>(G.x, 3, bitcoin_curve.p); //((G.x*G.x)%bitcoin_curve.p*G.x)%bitcoin_curve.p;
//     int512_t b = binaryExponentiation<int512_t>(G.y, 2, bitcoin_curve.p); //(G.y*G.y)%bitcoin_curve.p;

// /*    int512_t a = (G.x*G.x)%bitcoin_curve.p*G.x%bitcoin_curve.p;
//     int512_t b = (G.y*G.y)%bitcoin_curve.p;*/

//     cout << "Generator IS on the curve: " <<  toPositiveModulo(b - a - 7, bitcoin_curve.p) << endl;
//     return 0;
// }