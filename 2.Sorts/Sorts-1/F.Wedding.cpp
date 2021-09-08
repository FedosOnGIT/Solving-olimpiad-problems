#include<bits/stdc++.h>

using namespace std;

/*
 * Одна предприимчивая и очень симпатичная дамочка с прелестнейшим именем Горгона решила заработать себе денег на роскошную жизнь.
 N молодых людей так влюблены в нее, что предложили руку и сердце.
 К несчастью для них, Горгона видит в них только мешок с деньгами.
 Она планирует выйти замуж и почти сразу же развестись с некоторыми из молодых людей ради денежной выгоды.
 Все, что ей нужно, это подзаработать как можно больше денег (и уж, конечно, остаться незамужней).
 По законам этой прекрасной страны при разводе каждый из супругов получает половину всего имущества.

 * Вы планируете опубликовать статью, в которой опишете всю подлость и меркантильность этой особы.
 Для того чтобы статья получилась особенно красочной, нужно указать максимальную сумму денег, которую сможет получить Горгона.
 */

double plan(vector<double> &grooms, double fiancee) {
    sort(grooms.begin(), grooms.end());
    for (double groom : grooms) {
        if (groom > fiancee) {
            fiancee += groom;
            fiancee /= 2;
        }
    }
    return fiancee;
}

int main() {
    int number;
    cin >> number;
    vector<double> grooms(number);
    for (int i = 0; i < number; i++) {
        cin >> grooms[i];
    }
    double fiancee;
    cin >> fiancee;
    cout << fixed << setprecision(6) << plan(grooms, fiancee) << "\n";
}