// BOJ-14674 / STOP USING MONEY
// devgeon, 2025.01.11, C++17
// https://www.acmicpc.net/problem/14674

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Game {
  public:
    int num = 0, price = 0, score = 0;

    bool operator>(const Game &game) const {
        long long rate_a = (long long)this->score * game.price;
        long long rate_b = (long long)game.score * this->price;

        return (rate_a > rate_b ||
                (rate_a == rate_b && this->price < game.price) ||
                (rate_a == rate_b && this->price == game.price &&
                 this->num < game.num));
    }

    friend istream &operator>>(istream &in, Game &game) {
        in >> game.num >> game.price >> game.score;
        return in;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_games = 0, num_to_select = 0;
    cin >> total_games >> num_to_select;

    vector<Game> game_list(total_games);
    for (Game &game : game_list) {
        cin >> game;
    }
    sort(game_list.begin(), game_list.end(), greater());

    for (int i = 0; i < num_to_select; i++) {
        cout << game_list[i].num << '\n';
    }

    return 0;
}
