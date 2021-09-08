#include<bits/stdc++.h>

using namespace std;

int gcd(int first, int second) {
    while (first % second != 0 && second % first != 0) {
        if (first > second) {
            first %= second;
        } else {
            second %= first;
        }
    }
    return min(first, second);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int first, second;
    cin >> first >> second;
    cout << first * second / gcd(first, second) << "\n";
}
