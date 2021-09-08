#include<bits/stdc++.h>

using namespace std;

/*
 * Иван Иванович – очень ответственный, но очень рассеянный человек.
 Поэтому когда он начинает очередное дело, он на отдельном листочке пишет дату и время начала (например, 29.01. 10:30), а когда заканчивает, то так же на отдельном листочке – дату и время окончания (например, 02.02. 12:15).
 Листочки аккуратно укладываются в стопку один на другой.
 А так как одновременно Иван Иванович может заниматься только одним делом, то листочки однозначно упорядочены в стопке:
    листок начала какого-то дела,
    листок окончания этого дела,
    листок начала,
    листок окончания… и т.д.
 Дело начинается в начале минуты, указанной в листочке начала этого дела, а заканчивается в конце минуты, указанной на листочке окончания.
 Иван Иванович ходит на работу каждый день и его рабочий день продолжается с 10:00 до 18:00.
 Таким образом, пара листочков «18.11. 15:13» — «20.11. 10:27» была написана при начале и окончании дела длительностью 11ч.15м.

 * Однажды в конце декабря уборщица Дуся нечаянно уронила эту стопку на пол и, не зная важной закономерности их укладки, собрала листочки обратно в каком-то произвольном порядке.
 Иван Иванович обнаружил этот прискорбный факт только 31 декабря, когда ему надо было произвести учет своего рабочего времени за год.
 Год был невисокосный.

 * Помогите Ивану Ивановичу найти его суммарные затраты времени за год.
 */


struct Date {
    Date(string &date, string &time) {
        day = transform(date[0], date[1]);
        month = transform(date[3], date[4]);
        hour = transform(time[0], time[1]) - 10;
        minute = transform(time[3], time[4]);
    }

    long long expand() {
        long long minutes = 0;
        for (int i = 0; i < month - 1; i++) {
            minutes += months[i] * 8 * 60;
        }
        minutes += day * 8 * 60 + hour * 60 + minute;
        return minutes;
    }

    long long month;
    long long day;
    long long hour;
    long long minute;
private:
    static long long transform(char first, char second) {
        return (first - '0') * 10 + (second - '0');
    }

    const vector<long long> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

string output(long long time) {
    long long hours = time / 60;
    long long minutes = time % 60;
    string plus = minutes < 10 ? "0" : "";
    return to_string(hours) + ":" + plus + to_string(minutes);
}

string distance(vector<Date> &dates) {
    vector<long long> expands;
    expands.reserve(dates.size());
    for (Date &date : dates) {
        expands.push_back(date.expand());
    }
    sort(expands.begin(), expands.end());
    long long distance = 0;
    for (int i = 0; i < (int) expands.size(); i += 2) {
        distance += expands[i + 1] - expands[i] + 1;
    }
    return output(distance);
}

int main() {
    int number;
    cin >> number;
    vector<Date> dates;
    for (int i = 0; i < number; i++) {
        string date, time;
        cin >> date >> time;
        dates.emplace_back(date, time);
    }
    cout << distance(dates) << "\n";
}
