#include<bits/stdc++.h>

using namespace std;

/*
 * Первое задание
 Дана строка, состоящая из N попарно различных символов.
 Требуется вывести все перестановки символов данной строки.

 * Второе задание
 Дана строка, состоящая из N символов.
 Требуется вывести все перестановки символов данной строки.
 */

int main() {
    string input;
    cin >> input;
    int size = input.length();
    int permutation[size];
    for (int i = 0; i < size; i++) {
        permutation[i] = input[i] - 'a';
    }
    string answer;
    while (answer != input) {
        answer = "";
        next_permutation(permutation, permutation + size);
        for (int letter : permutation) {
            answer.push_back((char) (letter + 'a'));
        }
        cout << answer << "\n";
    }
}
