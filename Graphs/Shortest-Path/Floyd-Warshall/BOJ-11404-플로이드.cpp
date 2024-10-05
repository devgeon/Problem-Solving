// BOJ-11404 / 플로이드
// devgeon, 2024.10.05, C++17
// https://www.acmicpc.net/problem/11404

#include <iostream>
#include <vector>

using namespace std;

using MatrixRow = vector<int>;
using Matrix = vector<MatrixRow>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int INF = 100'000 * 100 + 1;
    int num_of_cities = 0, num_of_buses = 0;
    cin >> num_of_cities >> num_of_buses;

    vector<Matrix> cache(2, Matrix(num_of_cities, MatrixRow(num_of_cities, INF)));
    for (int i = 0; i < num_of_cities; i++) {
        cache[1][i][i] = 0;
    }
    for (int i = 0, from = 0, to = 0, cost = 0; i < num_of_buses; i++) {
        cin >> from >> to >> cost;
        cache[1][from - 1][to - 1] = min(cost, cache[1][from - 1][to - 1]);
    }

    for (int layover = 0; layover < num_of_cities; layover++) {
        for (int from = 0; from < num_of_cities; from++) {
            for (int to = 0; to < num_of_cities; to++) {
                cache[layover % 2][from][to] =
                    min(cache[(layover + 1) % 2][from][to],
                        cache[(layover + 1) % 2][from][layover] +
                        cache[(layover + 1) % 2][layover][to]);
            }
        }
    }

    for (int from = 0; from < num_of_cities; from++) {
        for (int to = 0, cost = 0; to < num_of_cities; to++) {
            cost = cache[(num_of_cities + 1) % 2][from][to];
            cout << (cost == INF ? 0 : cost) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
