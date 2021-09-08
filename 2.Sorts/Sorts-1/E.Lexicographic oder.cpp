#include<bits/stdc++.h>

using namespace std;

/*
 * Натуральные числа от 1 до N упорядочены лексикографически.
 Например, для N=25 результат этого упорядочения будет таким:
 1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 2, 20, 21, 22, 23, 24, 25, 3, 4, 5, 6, 7, 8, 9.

 * Требуется написать программу, которая определит, на каком месте оказалось число K.
 */

int position(int size, int value) {
    vector<string> numbers(size);
    for (int i = 0; i < size; i++) {
        numbers[i] = to_string(i + 1);
    }
    sort(numbers.begin(), numbers.end(), [](string &first, string &second) {
        int one = first.size(), two = second.size();
        for (int i = 0; i < min(one, two); i++) {
            if (first[i] != second[i]) {
                return first[i] < second[i];
            }
        }
        return one < two;
    });
    int position = 0;
    string need = to_string(value);
    while (numbers[position] != need) {
        position++;
    }
    return position + 1;
}

int main() {
    int size, value;
    cin >> size >> value;
    cout << position(size, value) << "\n";
}
