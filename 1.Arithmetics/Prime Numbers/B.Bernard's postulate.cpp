#include<bits/stdc++.h>
using namespace std;

/*
 * Постулат Бертрана (теорема Бертрана-Чебышева, теорема Чебышева) гласит, что для любого n > 1 найдется простое число p в интервале n < p < 2n.
 Такая гипотеза была выдвинута в 1845 году французским математиком Джозефем Бертраном (проверившим ее до n=3000000) и доказана в 1850 году Пафнутием Чебышевым.
 Раманужан в 1920 году нашел более простое доказательство, а Эрдеш в 1932 – еще более простое.

 * Ваша задача состоит в том, чтобы решить несколько более общую задачу – а именно по числу n найти количество простых чисел p из интервала n < p < 2n.
 */

int sieve(int number) {
    vector<bool> prime(number * 2, true);
    for (int i = 2; i < number * 2; i++) {
        if (prime[i]) {
            if (1ll * i * i <= number * 2) {
                for (int j = i * i; j < number * 2; j += i) {
                    prime[j] = false;
                }
            }
        }
    }
    int answer = 0;
    for (int i = number + 1; i < number * 2; i++) {
        if (prime[i]) {
            answer++;
        }
    }
    return answer;
}

int main() {
    int number;
    cin >> number;
    cout << sieve(number) << "\n";
}
