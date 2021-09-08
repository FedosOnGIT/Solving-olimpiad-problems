#include<bits/stdc++.h>

using namespace std;

/*
 * Одной из классических задач комбинаторной оптимизации является так называемая «задача о назначениях».
 Формулируется она следующим образом.

 * Есть n работников, пронумерованных числами от 1 до n, и n работ, также пронумерованных числами от 1 до n.
 Если i-ый работник выполняет j-ую работу, то ему выплачивается зарплата в размере cij денежных единиц.
 Необходимо найти такое назначение работников на работы (каждый работник выполняет ровно одну работу, каждая работа выполняется ровно одним работником),
    что суммарная зарплата работников минимальна (соответствующая сумма называется стоимостью назначения).

 * Напишите программу, решающую задачу о назначениях.
 */

int factorial(int number) {
    int answer = 1;
    for (int i = 2; i <= number; i++) {
        answer *= i;
    }
    return answer;
}

int cost(vector<vector<int> > &assignment, int number) {
    int range = factorial(number);
    vector<int> permutation;
    permutation.reserve(number);
    for (int i = 0; i < number; i++) {
        permutation.push_back(i);
    }
    int minimal = INT_MAX;
    for (int i = 0; i < range; i++) {
        int cost = 0;
        for (int j = 0; j < number; j++) {
            cost += assignment[j][permutation[j]];
        }
        minimal = min(cost, minimal);
        next_permutation(permutation.begin(), permutation.end());
    }
    return minimal;
}

int main() {
    int number;
    cin >> number;
    vector<vector<int> > assignment(number, vector<int>(number, 0));
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            cin >> assignment[i][j];
        }
    }
    cout << cost(assignment, number) << "\n";
}
