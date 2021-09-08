#include<bits/stdc++.h>

using namespace std;

/*
 * Число называется совершенным, если оно равно сумме всех своих делителей, меньших его самого.
 Требуется найти все совершенные числа от M до N.
 */

long long power(long long base, int degree) {
    if (degree == 0) {
        return 1;
    }
    long long half = power(base, degree / 2);
    long long answer = half * half;
    if (degree % 2) {
        answer *= base;
    }
    return answer;
}

bool check(long long prime) {
    long long divider = 2;
    while (divider <= (long long) sqrt(prime)) {
        if (prime % divider == 0) {
            return false;
        }
        divider++;
    }
    return true;
}

void perfect(long long start, long long finish) {
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    bool bad = true;
    for (int prime : primes) {
        long long half = (power(2, prime) - 1);
        if (check(half)) {
            long long number = power(2, prime - 1) * half;
            if (start <= number) {
                if (number <= finish) {
                    bad = false;
                    cout << number << "\n";
                } else {
                    break;
                }
            }
        }
    }
    if (bad) {
        cout << "Absent" << "\n";
    }
}

int main() {
    long long start, finish;
    cin >> start >> finish;
    perfect(start, finish);
}
