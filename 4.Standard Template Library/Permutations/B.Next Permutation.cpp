#include<bits/stdc++.h>

using namespace std;

/*
 * Найдите по заданной перестановке следующую в лексикографическом порядке
 (будем считать, что за перестановкой (N, N-1, ... , 3, 2, 1) следует тождественная перестановка, то есть (1, 2, 3, ... , N)).
 */

bool next(vector<int> &permutation) {
    int size = permutation.size();
    int position = size - 2;
    while (position >= 0 && permutation[position] > permutation[position + 1]) {
        position--;
    }
    if (position >= 0) {
        int last = position + 1;
        while (last + 1 < size && permutation[position] < permutation[last + 1]) {
            last++;
        }
        swap(permutation[last], permutation[position]);
        reverse(permutation.begin() + position + 1, permutation.end());
        return true;
    }
    return false;
}

int main() {
    int size;
    cin >> size;
    // int permutation[size];
    vector<int> permutation(size, 0);
    for (int i = 0; i < size; i++) {
        cin >> permutation[i];
    }
    bool has = next(permutation);
    if (!has) {
        reverse(permutation.begin(), permutation.end());
    }
    // next_permutation(permutation, permutation + size);
    for (int element : permutation) {
        cout << element << " ";
    }
    cout << "\n";
}
