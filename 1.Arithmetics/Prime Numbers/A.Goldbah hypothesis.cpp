#include<bits/stdc++.h>

using namespace std;

/*
 * Известно, что любое чётное число, большее 2, представимо в виде суммы 2 простых чисел, причём таких разложений может быть несколько.
 Впервые гипотезу о существовании данного разложения сформулировал математик Х. Гольдбах.

 * Требуется написать программу, производящую согласно утверждению Гольдбаха, разложение заданного чётного числа.
 Из всех пар простых чисел, сумма которых равна заданному числу, требуется найти пару, содержащую наименьшее простое число.
 */

vector<bool> sieve(int size) {
    vector<bool> prime(size + 1, true);
    for (int i = 2; i <= size; i++) {
        if (prime[i]) {
            if (1ll * i * i <= size) {
                for (int j = i * i; j <= size; j += i) {
                    prime[j] = false;
                }
            }
        }
    }
    /*
    vector<int> prime;
    for (int i = 2; i < size; i++) {
        if (numbers[i]) {
            prime.push_back(i);
        }
    }*/
    return prime;
}

int main() {
    int number;
    cin >> number;
    vector<bool> prime = sieve(number);
    for (int i = 2; i <= number; i++) {
        if (prime[i] && prime[number - i]) {
            cout << i << " " << number - i << "\n";
            return 0;
        }
    }
}
