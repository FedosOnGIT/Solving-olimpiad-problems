#include<bits/stdc++.h>

using namespace std;

/*
 * Задано натуральное число N.

 * Требуется написать программу, которая найдет следующее за ним число, в двоичном разложении которого столько же единиц, сколько в двоичном разложении числа N.
 */

long long next(long long number) {
    vector<long long> decomposition;
    while (number != 0) {
        decomposition.push_back(number % 2);
        number /= 2;
    }
    int size = decomposition.size();
    int position = 0;
    int deleted = 0;
    while (position < size - 1 && decomposition[position] <= decomposition[position + 1]) {
        if (decomposition[position]) {
            deleted++;
            decomposition[position] = 0;
        }
        position++;
    }
    for (int i = 0; i < deleted; i++) {
        decomposition[i] = 1;
    }
    if (position != size - 1) {
        swap(decomposition[position], decomposition[position + 1]);
    } else {
        decomposition.pop_back();
        decomposition.push_back(0);
        decomposition.push_back(1);
        size++;
    }
    long long next = 0;
    long long multiply = 1;
    for (long long i = 0; i < size; i++) {
        next += decomposition[i] * multiply;
        multiply *= 2;
    }
    return next;
}

int main() {
    long long number;
    cin >> number;
    cout << next(number) << "\n";
}
