// //
// // Created by Akhil on 2025-01-27.
// //
// #include "stdc++.h"
// using namespace std;
// typedef pair<int, int> ii;
//
// void fun() {
//     /*
//     *1. N tuples (integer age ", string last name # (descending order), string first name ").
//     2*. N fractions ( numerator
//         denominator ) in " (ascending order).
//      */
//
//     vector<tuple<int, string, string>> v;
//     sort(v.begin(), v.end(), [](auto &a, auto &b) {
//         if (get<0>(a) < get<0>(b)) {
//             return true;
//         } else if (get<0>(a) > get<0>(b)) {
//             return false;
//         } else {
//             if (get<1>(a) == get<1>(b)) {
//                 return get<2>(a) < get<2>(b);
//             }
//             return get<1>(a) > get<1>(b);
//         }
//     });
//
//     vector<ii> vec;
//     sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
//         return (1.0 * a.first ) / a.second < (1.0 * b.first) / b.second;
//     });
// }