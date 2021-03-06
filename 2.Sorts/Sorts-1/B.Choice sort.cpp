#include<bits/stdc++.h>

using namespace std;

/*
 * В этой задаче вам предлагается реализовать сортировку выбором.

 * Задан массив целых чисел a0, a1, …, an−1. Отсортируем его следующим образом:
 1. Выберем наибольший элемент массива и поменяем его местами с последним элементом (если последний и есть найденный максимум, то обмен можно не совершать).
 2. Исключим из рассмотрения последний элемент и если длина оставшегося участка больше нуля перейдем опять к предыдущему пункту.

 * Таким образом, этот алгоритм состоит их n фаз, на каждой из которых выбирается максимум.
 Ваша задача реализовать эту сортировку описанным способом и вывести n чисел — индексы максимума на каждой из n фаз.
 Если максимум встречается более одного раза, то надо всегда выбирать первый из них.
 */

void choice(vector<int> &array) {
    int size = array.size();
    for (int i = size - 1; i >= 0; i--) {
        int position = 0;
        for (int j = 1; j <= i; j++) {
            if (array[position] < array[j]) {
                position = j;
            }
        }
        cout << position << " ";
        swap(array[position], array[i]);
    }
    cout << "\n";
}

int main() {
    int number;
    cin >> number;
    vector<int> array(number);
    for (int i = 0; i < number; i++) {
        cin >> array[i];
    }
    choice(array);
}
