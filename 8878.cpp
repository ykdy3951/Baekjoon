// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <iomanip> 

// using namespace std;

// double p, x;

// double arr[50001];

// double f(int b, int c) {
//     return (c-b*x/100) / (arr[c] - 1);
// }

// double e(int b, int c) {
//     return f(b, c) * (arr[b] - 1) - b * (1-x/100);
// }

// int main(void) {

//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> x >> p;

//     double _p = 100 - p;

//     arr[0] = 1;
//     for(int i = 1; i <= 50000; i++) 
//     {
//         arr[i] = arr[i-1] * _p / p;
//     }

//     int sb = 0, eb = 5000;
//     while(eb-sb >= 3) {
//         int mb1 = (sb * 2 + eb) / 3, mb2 = (sb + eb * 2) / 3;

//         int sc = mb1, ec = 20530;
//         while(ec - sc >= 3) {
//             int mc1 = (sc * 2 + ec) / 3, mc2 = (sc + ec * 2) / 3;

//             if (f(mb1, mc1) > f(mb1, mc2)) {
//                 ec = mc2;
//             }
//             else {
//                 sc = mc1;
//             }
//         }

//         int c1 = 0;
//         double r1 = 0;

//         for(int i = sc; i <= ec; i++) {
//             if (r1 < f(mb1, i)) {
//                 r1 = f(mb1, i);
//                 c1 = i;
//             }
//         }

//         sc = mb2, ec = 20530;
//         while(ec - sc >= 3) {
//             int mc1 = (sc * 2 + ec) / 3, mc2 = (sc + ec * 2) / 3;

//             if (f(mb2, mc1) > f(mb2, mc2)) {
//                 ec = mc2;
//             }
//             else {
//                 sc = mc1;
//             }
//         }

//         int c2 = 0;
//         double r2 = 0;

//         for(int i = sc; i <= ec; i++) {
//             if (r2 < f(mb2, i)) {
//                 r2 = f(mb2, i);
//                 c2 = i;
//             }
//         }

//         if (e(mb1, c1) > e(mb2, c2)) {
//             eb = mb2;
//         }
//         else {
//             sb = mb1;
//         }
//     }

//     double res = 0;
//     int b = 0, c = 0;

//     for(int i = sb; i <= eb; i++) {
//         int sc = sb, ec = 20530;
//         while (ec - sc >= 3) {
//             int mc1 = (sc * 2 + ec) / 3, mc2 = (sc + ec * 2) / 3;

//             if (f(i, mc1) > f(i, mc2)) {
//                 ec = mc2;
//             }
//             else {
//                 sc = mc1;
//             }
//         }

//         for(int j = sc; j <= ec; j++) {
//             if (res < e(i, j)) {
//                 res = e(i, j);
//                 b = i;
//                 c = j;
//             }
//         }
//     }

//     cout << setprecision(10) << res << endl;

//     return 0;
// }

#include <iostream>
#include <cmath>

double calculateProbability(double p, double x, int L, int W) {
    double r = 1 - p;
    double alpha = (r * W - r * L) / (1 - r * L);
    double beta = (r * L - r * W) / (1 - r * L);

    double P = alpha + beta * p;

    return P;
}

int main() {
    double p;  // probability of winning each round
    double x;  // precision

    std::cin >> x >> p;

    int bestL = 0;
    int bestW = 0;
    double bestExpectedGain = 0.0;

    for (int L = 0; L <= 20528; L++) {
        for (int W = 0; W <= 2498; W++) {
            double expectedGain = calculateProbability(p, x, L, W);

            if (expectedGain > bestExpectedGain) {
                bestExpectedGain = expectedGain;
                bestL = L;
                bestW = W;
            }
        }
    }

    std::cout << "Best L: " << bestL << std::endl;
    std::cout << "Best W: " << bestW << std::endl;
    std::cout << "Best expected gain: " << bestExpectedGain << std::endl;

    return 0;
}
