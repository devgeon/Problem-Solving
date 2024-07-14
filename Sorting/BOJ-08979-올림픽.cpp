// BOJ-08979 / 올림픽
// devgeon, 2024.07.14, C++17
// https://www.acmicpc.net/problem/8979

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Country {
  public:
    int id = 0;
    int gold_medal = 0;
    int silver_medal = 0;
    int bronze_medal = 0;

    bool operator!=(const Country &country) const {
        return this->gold_medal != country.gold_medal ||
               this->silver_medal != country.silver_medal ||
               this->bronze_medal != country.bronze_medal;
    }
};

istream &operator>>(istream &in, Country &country) {
    in >> country.id >> country.gold_medal >>
        country.silver_medal >> country.bronze_medal;
    return in;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, query = 0;
    cin >> num >> query;

    vector<Country> results(num);
    for (Country &country : results) {
        cin >> country;
    }
    sort(results.begin(), results.end(),
         [](Country country1, Country country2) -> bool {
             if (country1.gold_medal > country2.gold_medal) {
                 return true;
             }
             if (country1.gold_medal == country2.gold_medal &&
                 country1.silver_medal > country2.silver_medal) {
                 return true;
             }
             if (country1.gold_medal == country2.gold_medal &&
                 country1.silver_medal == country2.silver_medal &&
                 country1.bronze_medal > country2.bronze_medal) {
                 return true;
             }
             return false;
         });

    for (int i = 0, rank = 1; i < num; i++) {
        if (i > 0 && results[i - 1] != results[i]) {
            rank = i + 1;
        }
        if (results[i].id == query) {
            cout << rank << endl;
            break;
        }
    }

    return 0;
}
