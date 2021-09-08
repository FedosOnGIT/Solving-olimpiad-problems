#include<bits/stdc++.h>

using namespace std;

/*
 * Требуется найти N-е число Фибоначчи.
 */

int get(int index) {
    if (index == 0) {
        return 0;
    }
    if (index == 1) {
        return 1;
    }
    int first = 0;
    int second = 1;
    int number = 1;
    while (number < index) {
        int help = first + second;
        first = second;
        second = help;
        number++;
    }
    return second;
}

int main() {
    int index;
    cin >> index;
    cout << get(index) << "\n";
}
