#include<bits/stdc++.h>

using namespace std;

/*
 * Назовем перестановку из N чисел 1…N K-перестановкой, если любые два соседних в ней элемента отличаются не более, чем на K.
 */

int factorial(int number) {
    int answer = 1;
    while (number > 1) {
        answer *= number;
        number--;
    }
    return answer;
}

int check(vector<int> &permutation, int size, int minimal) {
    for (int i = 0; i < size - 1; i++) {
        if (abs(permutation[i] - permutation[i + 1]) > minimal) {
            return 0;
        }
    }
    return 1;
}

int different(int number, int minimal) {
    int range = factorial(number);
    int answer = 0;
    vector<int> permutation;
    for (int i = 1; i <= number; i++) {
        permutation.push_back(i);
    }
    int index = 0;
    while (index < range) {
        answer += check(permutation, number, minimal);
        next_permutation(permutation.begin(), permutation.end());
        index++;
    }
    return answer;
}

int main() {
    int number, minimal;
    cin >> number >> minimal;
    cout << different(number, minimal) << "\n";
}
