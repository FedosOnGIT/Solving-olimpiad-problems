#include<bits/stdc++.h>

using namespace std;

/*
 * Пусть задано некоторое слово, состоящее из букв английского алфавита длиной не более 80 символов (например, “WORD”).
 Рассмотрим набор возможных перестановок, состоящих из букв данного слова (например, “RDOW”, “WODR” и т.д.).
 Требуется выбрать из этого множества слово, следующее по алфавиту за исходным.
 */

void next(vector<int> &permutation) {
    int size = permutation.size();
    int position = size - 2;
    while (position >= 0 && permutation[position] >= permutation[position + 1]) {
        position--;
    }
    if (position >= 0) {
        int last = position + 1;
        while (last + 1 < size && permutation[last + 1] > permutation[position]) {
            last++;
        }
        swap(permutation[position], permutation[last]);
        reverse(permutation.begin() + position + 1, permutation.end());
    }
}

int main() {
    string word;
    cin >> word;
    /* vector<int> permutation(word.length());
    for (int i = 0; i < (int) word.length(); i++) {
        permutation[i] = word[i] - 'a';
    }
    next(permutation);
    */
    int permutation[word.length()];
    for (int i = 0; i < word.length(); i++) {
        permutation[i] = word[i] - 'a';
    }
    next_permutation(permutation, permutation + word.length());
    for (int element : permutation) {
        cout << (char) (element + 'a');
    }
    cout << "\n";
}
