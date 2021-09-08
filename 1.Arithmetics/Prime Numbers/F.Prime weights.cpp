#include<bits/stdc++.h>

using namespace std;

/*
 * Имеются гири с массами: 1 г, 2 г, …, N г.
 Требуется написать программу, распределяющую эти гири на максимально возможное количество пар так, чтобы суммарный вес гирь в каждой паре выражался простым числом.
 */

vector<int> sieve(int number) {
    vector<bool> numbers(number * 2, true);
    vector<int> near(number * 2, 0);
    int last = 1;
    for (int i = 2; i < number * 2; i++) {
        if (numbers[i]) {
            for (int j = last; j < i; j++) {
                near[j] = i;
            }
            last = i;
            if (1ll * i * i <= number * 2) {
                for (int j = i * i; j < number * 2; j += i) {
                    numbers[j] = false;
                }
            }
        }
    }
    return near;
}

void pairs(int number) {
    vector<int> near = sieve(number);
    while (number > 1) {
        int left = near[number] - number;
        int right = number;
        while (right > left) {
            cout << left << " " << right << "\n";
            right--;
            left++;
        }
        number = near[number] - number - 1;
    }
}

int main() {
    int number;
    cin >> number;
    pairs(number);
}
