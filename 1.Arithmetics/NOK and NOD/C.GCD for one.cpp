#include<bits/stdc++.h>
using namespace std;

/*
 * Statement:
 * Заданы два натуральных числа в десятичной системе счисления, состоящие из единиц.
 * В первом числе ровно N единиц, а во втором их ровно M.
 * Требуется найти НОД этих чисел. Напомним, что НОД (наибольший общий делитель) двух чисел a и b — это такое максимальное число c, что b делится на c и a делится на c.
 */

int gcd(int first, int second) {
    while (first % second != 0 && second % first != 0) {
        if (first > second) {
            first %= second;
        } else {
            second %= first;
        }
    }
    return min(first, second);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int first, second;
    cin >> first >> second;
    int number = gcd(first, second);
    for (int i = 0; i < number; i++) {
        cout << 1;
    }
    cout << "\n";
}
