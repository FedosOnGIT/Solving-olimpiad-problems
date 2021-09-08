#include<bits/stdc++.h>

using namespace std;

/*
 * Требуется найти наибольший общий делитель двух чисел Фибоначчи.
 */

const long long Mod = 1e9;

int gcd(int first, int second) {
    while (first % second && second % first) {
        if (first > second) {
            first %= second;
        } else {
            second %= first;
        }
    }
    return min(first, second);
}

long long get(int upper) {
    long long first = 0;
    long long second = 1;
    int index = 1;
    while (index < upper) {
        long long help = (first + second) % Mod;
        first = second;
        second = help;
        index++;
    }
    return second;
}

int main() {
    int first, second;
    cin >> first >> second;
    cout << get(gcd(first, second)) << "\n";
}
