#include<bits/stdc++.h>
using namespace std;

/*
 * Statement:
 * Катя решила пригласить к себе в гости n друзей.
 * Так как ее друзья очень любят фрукты, то в качестве угощения для них она купила m одинаковых апельсинов.
 * Она хочет разрезать каждый апельсин на одинаковое число равных долек так, чтобы их можно было распределить между гостями (сама Катя апельсины есть не будет), и всем гостям досталось поровну долек.
 * Напишите программу, которая вычисляет минимальное количество долек, на которое необходимо разрезать каждый апельсин, чтобы были выполнены указанные выше условия.
 */

int gcd(int first, int second) {
    while (first % second && second % first) {
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
    int guests, oranges;
    cin >> guests >> oranges;
    int divider = gcd(guests, oranges);
    cout << guests / divider << "\n";
}
