// BOJ-02157 / 여행
// devgeon, 2024.08.28, C++17
// https://www.acmicpc.net/problem/2157

#include <iostream>
#include <vector>

using namespace std;

class Flight {
  public:
    int from = 0;
    int to = 0;
    int score = 0;

    Flight(int from, int to, int score) {
        this->from = from;
        this->to = to;
        this->score = score;
    }

    friend istream &operator>>(istream &in, Flight &flight) {
        in >> flight.from >> flight.to >> flight.score;
        return in;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_cities = 0, num_flights, limit = 0;
    cin >> num_cities >> limit >> num_flights;

    vector<vector<Flight>> flight_list(num_cities, vector<Flight>());
    vector<vector<int>> cache(2, vector<int>(num_cities, -1));

    for (int i = 0, from = 0, to = 0, score = 0; i < num_flights; i++) {
        cin >> from >> to >> score;
        if (from > to) {
            continue;
        }
        flight_list[to - 1].emplace_back(from - 1, to - 1, score);
    }

    for (int r = 1; r < limit; r++) {
        cache[(r - 1) % 2][0] = 0;
        for (int c = 1; c < num_cities; c++) {
            for (Flight flight : flight_list[c]) {
                if (cache[(r - 1) % 2][flight.from] < 0) {
                    continue;
                }
                cache[r % 2][c] =
                    max(cache[r % 2][c],
                        cache[(r - 1) % 2][flight.from] + flight.score);
            }
        }
    }
    cout << cache[(limit - 1) % 2][num_cities - 1] << endl;

    return 0;
}
