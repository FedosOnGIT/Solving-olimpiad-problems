#include<bits/stdc++.h>

using namespace std;

/*
 * Как известно, Россия является одним из ведущих экспортеров нефти.
 Разные страны мира, от достаточно больших до сравнительно маленьких, нуждаются в этой нефти как в воздухе.
 В ее состав в больших количествах входят ароматические углеводороды, которые обуславливают ее высокое качество.
 Доставка нефти в пункт назначения осуществляется с помощью нефтепровода.
 Считается, что количество нефти, отправленное в страну назначения, равно количеству полученной нефти.
 На самом деле это, конечно, не так. Как и многое другое, нефть воруют некоторые несознательные личности.
 Причем неофициально считается, что больше нефти воруют в нефтепроводах тех стран, куда нефти посылается больше (может быть, несознательные личности считают, что приносят, таким образом, меньше ущерба, кто знает...).
 Официальное руководство компании «Русская Нефть» решило узнать, правдивый это слух или нет, чтобы усилить (а может просто установить) охрану на тех нефтепроводах, где больше всего воруют нефть.

 * Для этого им нужно отсортировать нефтепроводы по количеству нефти, которая протекает в направлении какой-то страны за сутки.
 У компании «Русская Нефть», как и у любой уважающей себя компании, есть несколько штатных программистов, и руководство предложило им решить эту, в сущности, нетрудную задачу.
 Но программистов поставило в тупик то, что данные о количестве нефти представлены в разных единицах измерения (начиная от граммов и заканчивая тоннами).

 * Поэтому они решили найти человека, который был бы в силах решить эту задачу за них, и обещают взять его на работу в эту перспективную и процветающую компанию.
 Решите задачу, и, кто знает, может, повезет именно Вам?
 */

long long coeff(const string &u) {
    char p, v;

    if (strchr("gpt", u[0])) {
        v = u[0];
        p = ' ';
    } else {
        p = u[0];
        v = u[1];
    }

    long long r = 1;

    switch (v) {
        case 'g':
            r = 1000ll;
            break;

        case 'p':
            r = 16380000ll;
            break;

        case 't':
            r = 1000000000ll;
            break;
    }

    switch (p) {
        case 'm':
            r /= 1000;
            break;

        case 'k':
            r *= 1000;
            break;

        case 'M':
            r *= 1000000;
            break;

        case 'G':
            r *= 1000000000;
            break;
    }

    return r;
}

int main() {
    int N;
    vector<tuple<double, int, long long, string>> v;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        long long val;
        string unit;
        cin >> val >> unit;
        v.emplace_back(double(val) * (double) coeff(unit), i, val, unit);
    }

    sort(v.begin(), v.end());

    for (auto t : v)
        cout << get<2>(t) << " " << get<3>(t) << endl;
}
