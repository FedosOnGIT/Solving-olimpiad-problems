#include<bits/stdc++.h>
using namespace std;

/*
 * Требуется вывести представление целого числа N в виде произведения простых чисел.
 */

int main() {
    int number;
    cin >> number;
    vector<int> factorization;
    int divider = 2;
    while (number != 1 && divider <= sqrt(number)) {
        if (number % divider == 0) {
            number /= divider;
            factorization.push_back(divider);
        } else {
            divider++;
        }
    }
    if (number != 1) {
        factorization.push_back(number);
    }
    for (int i = 0; i < factorization.size() - 1; i++) {
        cout << factorization[i] << "*";
    }
    cout << factorization.back() << "\n";
}
