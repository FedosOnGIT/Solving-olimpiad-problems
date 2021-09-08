#include<bits/stdc++.h>

using namespace std;

/*
 * Как великолепна страна Байтландия!
 В ней есть цветущие леса, прозрачные реки, кисельные берега… Но речь пойдет не о них.
 Уже много лет в Байтландии функционирует НИИ “Цитологии и генетики”.
 В нем выводятся новые формы жизни.
 Недавно ученым этого НИИ удалось разработать принципиально новый вид организмов.
 Особенностью этих организмов является то, что они состоят из большого количества однотипных клеток, то есть являются моноклеточными.

 * Правительство Байтландии заинтересовалось новой разработкой и сделало заказ на производство двух моноклеточных организмов, в каждом из которых должно быть по M клеток.
 За несколько дней до сдачи проекта было обнаружено, что в одном из организмов получается не M клеток, а N.
 На какой из стадий разработки была допущена ошибка неизвестно, но положение надо исправлять!

 * Сотрудниками НИИ было принято решение о преобразовании моноклеточного с N клетками в моноклеточное с M клетками.
 Для этого в экстренном режиме было разработано два типа вещества:

    1. Вещество, которое делит клетки моноклеточного организма, т.е. каждая клетка делится на P частей.
    В результате количество клеток умножается на P, где P – простое число.

    2. Вещество, объединяющее клетки. Клетки организма объединяются в группы по T штук, где Т также простое число.
    Далее каждая группа клеток объединяется в одну клетку.
    В результате общее количество клеток делится на T.
    При этом T выбирается таким, чтобы деление происходило без остатка.

  * Серьезным недостатком этих веществ является их высокая стоимость. В соответствии с этим требуется преобразовать моноклеточное с N клетками в моноклеточное с M клетками за минимальное количество операций. За одну операцию к моноклеточному можно применить одно вещество из двух заданных типов. Помогите НИИ “Цитологии и генетики” разрешить эту непростую задачу!
 */

vector<int> factorization(int number) {
    vector<int> prime;
    int divider = 2;
    while (number != 1 && divider <= sqrt(number)) {
        if (number % divider == 0) {
            prime.push_back(divider);
            number /= divider;
        } else {
            divider++;
        }
    }
    if (number != 1) {
        prime.push_back(number);
    }
    return prime;
}

int difference(int have, int want) {
    vector<int> primeHave = factorization(have);
    vector<int> primeWant = factorization(want);
    int indexHave = 0;
    int indexWant = 0;
    int difference = 0;
    while (indexHave != (int) primeHave.size() && indexWant != (int) primeWant.size()) {
        if (primeHave[indexHave] == primeWant[indexWant]) {
            indexHave++;
            indexWant++;
        } else if (primeHave[indexHave] > primeWant[indexWant]) {
            difference++;
            indexWant++;
        } else {
            difference++;
            indexHave++;
        }
    }
    difference += (int) primeHave.size() - indexHave;
    difference += (int) primeWant.size() - indexWant;
    return difference;
}

int main() {
    int have, want;
    cin >> have >> want;
    cout << difference(have, want) << "\n";
}