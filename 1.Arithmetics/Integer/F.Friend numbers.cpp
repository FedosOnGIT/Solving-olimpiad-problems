#include<bits/stdc++.h>

using namespace std;

/*
 * Два различных натуральных числа называются дружественными, если первое из них равно сумме делителей второго числа,
 за исключением самого второго числа, а второе равно сумме делителей первого числа, за исключением самого первого числа.

 * Требуется найти все пары дружественных чисел, оба из которых принадлежат промежутку от M до N.
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

vector<int> sieve(int end) {
    vector<bool> prime(end + 1, true);
    vector<int> numbers;
    for (int i = 0; i <= end; i++) {
        numbers.push_back(i);
    }
    vector<int> sums(end + 1, 1);
    for (int i = 2; i <= end; i++) {
        if (prime[i]) {
            if (1ll * i * i <= end) {
                for (int j = i * i; j <= end; j += i) {
                    prime[j] = false;
                    int degree = 1;
                    while (numbers[j] % i == 0) {
                        numbers[j] /= i;
                        degree++;
                    }
                    sums[j] *= (power(i, degree) - 1) / (i - 1);
                }
            }
        }
    }
    for (int i = 1; i <= end; i++) {
        if (numbers[i] != 1) {
            sums[i] *= (numbers[i] * numbers[i] - 1) / (numbers[i] - 1);
        }
        sums[i] -= i;
    }
    return sums;
}

void pairs(int start, int end) {
    vector<int> sums = sieve(end);
    vector<bool> checked(end + 1, false);
    int accepted = 0;
    for (int i = start; i <= end; i++) {
        if (!checked[i]) {
            int sum1 = sums[i];
            if (sum1 >= start && sum1 <= end) {
                if (sum1 != i && sums[sum1] == i) {
                    accepted++;
                    cout << i << " " << sum1 << "\n";
                    checked[sum1] = true;
                }
            }
        }
    }
    if (!accepted) {
        cout << "Absent" << "\n";
    }
}

int main() {
    int start, end;
    cin >> start >> end;
    pairs(start, end);
}
