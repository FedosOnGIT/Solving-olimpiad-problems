#include<bits/stdc++.h>

using namespace std;

/*
 * Требуется выполнить сортировку временных моментов, заданных в часах, минутах и секундах.
 */

struct Time {
    Time(int hour, int minute, int second) : hour(hour), minute(minute), second(second) {}

    friend ostream &operator<<(ostream &out, Time &output);

    int hour;
    int minute;
    int second;
};

ostream &operator<<(ostream &out, Time &output) {
    out << output.hour << " " << output.minute << " " << output.second;
    return out;
}

void sorting(vector<Time> &times) {
    sort(times.begin(), times.end(), [](Time &one, Time &two) {
        return tie(one.hour, one.minute, one.second) < tie(two.hour, two.minute, two.second);
    });
    for (Time time : times) {
        cout << time << "\n";
    }
}

int main() {
    int number;
    cin >> number;
    vector<Time> times;
    for (int i = 0; i < number; i++) {
        int hour, minute, second;
        cin >> hour >> minute >> second;
        times.emplace_back(hour, minute, second);
    }
    sorting(times);
}
