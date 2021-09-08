#include<bits/stdc++.h>

using namespace std;

/*
 * Задана последовательность, содержащая n целых чисел.
 Необходимо найти число, которое встречается в этой последовательности наибольшее количество раз, а если таких чисел несколько,
    то найти минимальное из них, и после этого переместить все такие числа в конец заданной последовательности.
 Порядок расположения остальных чисел должен остаться без изменения.

 * Например, последовательность 1, 2, 3, 2, 3, 1, 2 после преобразования должна превратиться в последовательность 1, 3, 3, 1, 2, 2, 2.

 * Требуется написать программу, которая решает данную задачу.
 */

void transformation(vector<int> &sequence) {
    map<int, int> numbers;
    int maximal = 0;
    int maxValue = 0;
    for (int element : sequence) {
        if (numbers.count(element) != 0) {
            numbers[element]++;
        } else {
            numbers.emplace(element, 1);
        }
        if (numbers[element] > maxValue) {
            maximal = element;
            maxValue = numbers[element];
        } else if (numbers[element] == maxValue) {
            if (element < maximal) {
                maximal = element;
                maxValue = numbers[element];
            }
        }
    }
    vector<int> results;
    for (int element : sequence) {
        if (element != maximal) {
            results.push_back(element);
        }
    }
    for (int i = 0; i < maxValue; i++) {
        results.push_back(maximal);
    }
    for (int result : results) {
        cout << result << " ";
    }
    cout << "\n";
}

int main() {
    int number;
    cin >> number;
    vector<int> sequence(number);
    for (int i = 0; i < number; i++) {
        cin >> sequence[i];
    }
    transformation(sequence);
}
