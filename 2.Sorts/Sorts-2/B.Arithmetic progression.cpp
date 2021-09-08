#include<bits/stdc++.h>

using namespace std;

/*
 * Задана последовательность натуральных чисел из диапазона [1, 2147483647].
 Необходимо определить: можно ли выстроить эти числа в отрезок арифметической прогрессии.
 При необходимости порядок чисел в последовательности можно изменять.

 * Требуется написать программу для решения этой задачи.
 */

void quick(int start, int end, vector<int> &sequence) {
    if (start < end) {
        int left = start;
        int right = end;
        int value = sequence[start + (end - start) / 3];
        while (left < right) {
            while (sequence[left] < value) {
                left++;
            }
            while (sequence[right] > value) {
                right--;
            }
            if (left < right) {
                swap(sequence[left++], sequence[right--]);
            }
        }
        if (left == right) {
            if (sequence[right] > value) {
                right--;
            }
        }
        quick(start, right, sequence);
        quick(right + 1, end, sequence);
    }
}

bool progression(vector<int> &sequence) {
    int range = (int) sequence.size() - 1;
    quick(0, range, sequence);
    int step = sequence[1] - sequence[0];
    for (int i = 0; i < range; i++) {
        if (sequence[i + 1] - sequence[i] != step) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> sequence;
    int element;
    while (cin >> element) {
        sequence.push_back(element);
    }
    if (progression(sequence)) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}
