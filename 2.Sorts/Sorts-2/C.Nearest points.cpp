#include<bits/stdc++.h>

using namespace std;

/*
 * Антон в школе начал изучать математику.
 Его внимание привлекло новое для него понятие числовой прямой.
 Антон быстро научился вычислять расстояния между двумя точками на этой прямой, задавать отрезки и интервалы на ней.

 * Готовясь к контрольной работе, Антон столкнулся со следующей задачей:
    «На числовой прямой задано n точек. Необходимо найти среди них две ближайшие».
    Расстояние между двумя точками числовой прямой x и y равно |x - y|.

 * Требуется написать программу, которая поможет Антону решить поставленную задачу.
 */

void quick(int start, int end, vector<pair<int, int> > &points) {
    if (start < end) {
        int left = start;
        int right = end;
        int point = points[(end - start) / 3 + start].first;
        while (left < right) {
            while (points[left].first < point) {
                left++;
            }
            while (points[right].first > point) {
                right--;
            }
            if (left < right) {
                swap(points[left++], points[right--]);
            }
        }
        if (left == right) {
            if (points[right].first > point) {
                right--;
            }
        }
        quick(start, right, points);
        quick(right + 1, end, points);
    }
}

void minimal(vector<pair<int, int> > &points, int number) {
    quick(0, number - 1, points);
    int minimal = points[1].first - points[0].first;
    int first = points[0].second;
    int second = points[1].second;
    for (int i = 0; i < number - 1; i++) {
        int distance = points[i + 1].first - points[i].first;
        if (distance < minimal) {
            minimal = distance;
            first = points[i].second;
            second = points[i + 1].second;
        }
    }
    cout << minimal << "\n";
    cout << first << " " << second << "\n";
}

int main() {
    int number;
    cin >> number;
    vector<pair<int, int> > points;
    for (int i = 0; i < number; i++) {
        int position;
        cin >> position;
        points.emplace_back(position, i + 1);
    }
    minimal(points, number);
}
