#include<bits/stdc++.h>

using namespace std;

/*
 * Число Смита — такое составное число, сумма цифр которого равняется сумме цифр всех его простых сомножителей.
 Так, примером числа Смита может служить 202, поскольку 2 + 0 + 2 = 4 и 2 + 1 + 0 + 1 = 4 (202 = 2 * 101).
 Напишите программу, которая для заданной последовательности чисел определяет, какие из них являются числами Смита.
 */

int sum(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

vector<int> dividers(int number) {
    vector<int> prime;
    int divider = 2;
    while (number != 1 && divider <= sqrt(number)) {
        if (number % divider == 0) {
            number /= divider;
            prime.push_back(divider);
        } else {
            divider++;
        }
    }
    if (number != 1) {
        prime.push_back(number);
    }
    return prime;
}

vector<bool> check(vector<int> &sequence) {
    vector<bool> result;
    for (int number : sequence) {
        vector<int> primes = dividers(number);
        if (primes.size() == 1) {
            result.push_back(false);
        } else {
            int whole = sum(number);
            for (int prime : primes) {
                whole -= sum(prime);
            }
            if (whole == 0) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
    }
    return result;
}

int main() {
    vector<int> sequence;
    int number;
    while (cin >> number) {
        sequence.push_back(number);
    }
    vector<bool> results = check(sequence);
    for (bool result : results) {
        if (result) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << "\n";
}
