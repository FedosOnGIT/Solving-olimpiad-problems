#include<bits/stdc++.h>

using namespace std;

/*
 * Каждый из N выпускников школы чародейства и волшебства получает посох силы ai и кольцо силы bi.
 При этом сила i-го выпускника определяется соотношением ai / bi.

 * Перед выпускным балом экзаменационная комиссия решила распределить посохи и кольца таким образом, чтобы суммарная сила всех выпускников была максимальной.
 А так как маги больше преуспели в создании волшебных зелий, чем в математике, им потребуется ваша помощь.
 */

void power(vector<pair<long long, int> > &staffs, vector<pair<long long, int> > &rings, int students) {
    sort(staffs.begin(), staffs.end(), [](pair<long long, int> &first, pair<long long, int> &second) {
        return tie(first.first, first.second) < tie(second.first, second.second);
    });
    sort(rings.begin(), rings.end(), [](pair<long long, int> &first, pair<long long, int> &second) {
        return tie(first.first, first.second) > tie(second.first, second.second);
    });
    for (pair<long long, int> staff : staffs) {
        cout << staff.second + 1 << " ";
    }
    cout << "\n";
    for (pair<long long, int> ring : rings) {
        cout << ring.second + 1 << " ";
    }
    cout << "\n";
}

int main() {
    int students;
    cin >> students;
    vector<pair<long long, int> > staffs;
    staffs.reserve(students);
    vector<pair<long long, int> > rings;
    rings.reserve(students);
    for (int i = 0; i < students; i++) {
        long long staff;
        cin >> staff;
        staffs.emplace_back(staff, i);
    }
    for (int i = 0; i < students; i++) {
        long long ring;
        cin >> ring;
        rings.emplace_back(ring, i);
    }
    power(staffs, rings, students);
}
