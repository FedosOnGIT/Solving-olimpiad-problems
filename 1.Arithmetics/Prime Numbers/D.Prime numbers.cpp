#include<bits/stdc++.h>

using namespace std;

/*
 * Необходимо вывести все простые числа от M до N включительно.
 */

vector<int> sieve(int start, int end) {
    vector<bool> numbers(end + 1, true);
    vector<int> prime;
    for (int i = 2; i <= end; i++) {
        if (numbers[i]) {
            if (i >= start) {
                prime.push_back(i);
            }
            if (1ll * i * i <= end) {
                for (int j = i * i; j <= end; j += i) {
                    numbers[j] = false;
                }
            }
        }
    }
    return prime;
}

int main() {
    int start, end;
    cin >> start >> end;
    vector<int> primes = sieve(start, end);
    if (primes.empty()) {
        cout << "Absent" << "\n";
    } else {
        for (int prime : primes) {
            cout << prime << "\n";
        }
    }
}
