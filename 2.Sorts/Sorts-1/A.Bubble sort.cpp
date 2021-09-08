#include<bits/stdc++.h>

using namespace std;

/*
 * Задан целочисленный массив, состоящий из N элементов.
 Требуется посчитать число инверсий (обмена значений соседних элементов массива) в процессе сортировки элементов массива по неубыванию при использовании алгоритма сортировки «пузырьком» (BubbleSort).
 */

int bubble(vector<int> &array) {
    int inversions = 0;
    int size = array.size();
    for (int i = 0; i < size; i++) {
        for (int j = i; j > 0; j--) {
            if (array[j] < array[j - 1]) {
                swap(array[j - 1], array[j]);
                inversions++;
            } else {
                break;
            }
        }
    }
    return inversions;
}

int main() {
    int number;
    cin >> number;
    vector<int> array(number, 0);
    for (int i = 0; i < number; i++) {
        cin >> array[i];
    }
    cout << bubble(array) << "\n";
}
