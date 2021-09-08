#include<bits/stdc++.h>

using namespace std;

/*
 * Определение 1:
    n!!...!=n(n-k)(n-2k)...(n mod k), если n не делится на k,
    n!!...!=n(n-k)(n-2k)...k, если n делится на k (знаков ! в обоих случаях k штук).
 * Определение 2:
    X mod Y — остаток от деления X на Y.
    Например, 10 mod 3 = 1; 3! = 3•2•1; 10!!! = 10•7•4•1;
 * Мы по заданным n и k смогли вычислить значение выражения из определения 1. А вам слабо?
*/

long long factorial(long long base, int factorial) {
    long long answer = 1;
    while (base > 0) {
        answer *= base;
        base -= factorial;
    }
    return answer;
}

int main() {
    long long base;
    string step;
    cin >> base >> step;
    cout << factorial(base, (int) step.size()) << "\n";
}
