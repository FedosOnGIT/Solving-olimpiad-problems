#include<bits/stdc++.h>

using namespace std;

/*
 * В одном из государств все решения традиционно принимались простым большинством голосов на общем собрании граждан, которых, к счастью, было не очень много.
 Одна из местных партий, стремясь прийти к власти как можно более законным путем, смогла добиться некоторой реформы избирательной системы.
 Главным аргументом было то, что население острова в последнее время значительно возросло, и проведение общих собраний перестало быть легкой задачей.

 * Суть реформы состояла в следующем: с момента введения ее в действие все избиратели острова делились на K групп (необязательно равных по численности).
 Голосование по любому вопросу теперь следовало проводить отдельно в каждой группе, причем считалось, что группа высказывается "за", если "за" голосует более половины людей в этой группе, а в противном случае считалось, что группа высказывается "против".
 После проведения голосования в группах подсчитывалось количество групп, высказавшихся "за" и "против", и вопрос решался положительно в том и только том случае, когда групп, высказавшихся "за", оказывалось более половины общего количества групп.

 * Эта система вначале была с радостью принята жителями острова.
 Когда первые восторги рассеялись, очевидны стали, однако, некоторые недостатки новой системы.
 Оказалось, что сторонники партии, предложившей систему, смогли оказать некоторое влияние на формирование групп избирателей.
 Благодаря этому, они получили возможность проводить некоторые решения, не обладая при этом реальным большинством голосов.

 * Пусть, например, на острове были сформированы три группы избирателей, численностью в 5, 5 и 7 человек соответственно.
 Тогда партии достаточно иметь по три сторонника в каждой из первых двух групп, и она сможет провести решение всего 6-ю голосами "за", вместо 9-и, необходимых при общем голосовании.

 * Требуется написать программу, которая по заданному разбиению избирателей на группы определит минимальное количество сторонников партии, достаточное для принятия любого решения.
 */

int need(vector<int> &groups) {
    sort(groups.begin(), groups.end());
    int number = ((int) groups.size() + 2) / 2;
    int need = 0;
    for (int i = 0; i < number; i++) {
        need += (groups[i] + 2) / 2;
    }
    return need;
}

int main() {
    int number;
    cin >> number;
    vector<int> groups(number);
    for (int i = 0; i < number; i++) {
        cin >> groups[i];
    }
    cout << need(groups) << "\n";
}
