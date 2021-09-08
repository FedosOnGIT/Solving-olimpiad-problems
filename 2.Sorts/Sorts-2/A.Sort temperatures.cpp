#include<bits/stdc++.h>

using namespace std;

/*
 * На планете «Аурон» атмосфера практически отсутствует, поэтому она известна своими перепадами температур в различных точках.
 Известно, что эти перепады колеблются от -100 до 100 градусов.
 Нашим специалистам удалось выяснить значения температур в N точках этой планеты.
 К сожалению, эти значения вычислены с большими погрешностями, поэтому их решили округлить до целых чисел.
 Хотелось бы наглядно видеть участки с повышенной и пониженной температурой.
 Вам требуется помочь.
 Вы должны упорядочить температуры участков по неубыванию.
 */

void quick(int start, int end, vector<int> &temperatures) {
    if (start < end) {
        int position = (end - start) / 3 + start;
        int left = start;
        int right = end;
        int temperature = temperatures[position];
        while (left < right) {
            while (temperatures[left] < temperature) {
                left++;
            }
            while (temperatures[right] > temperature) {
                right--;
            }
            if (left < right) {
                swap(temperatures[left++], temperatures[right--]);
            }
        }
        if (left == right) {
            if (temperatures[right] > temperature) {
                right--;
            }
        }
        quick(start, right, temperatures);
        quick(right + 1, end, temperatures);
    }
}

void sorting(vector<int> &temperatures) {
    quick(0, (int) temperatures.size() - 1, temperatures);
    for (int temperature : temperatures) {
        cout << temperature << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int number;
    cin >> number;
    vector<int> temperatures(number, 0);
    for (int i = 0; i < number; i++) {
        cin >> temperatures[i];
    }
    sorting(temperatures);
}
