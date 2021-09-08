#include<bits/stdc++.h>

using namespace std;

/*
 * Требуется написать программу, которая определяет, является ли заданное число числом Фибоначчи.
*/

int get(long long upper) {
    long long first = 0;
    long long second = 1;
    int index = 1;
    while (second < upper) {
        long long help = first + second;
        first = second;
        second = help;
        index++;
    }
    if (second == upper) {
        return index;
    }
    return -1;
}

int main() {
    int upper;
    cin >> upper;
    int index = get(upper);
    if (index == -1) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
        cout << index << "\n";
    }
}
