// BOJ-12867 / N차원 여행
// devgeon, 2024.09.06, C++17
// https://www.acmicpc.net/problem/12867

#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

using namespace std;

class Coord : public map<int, int> {
  public:
    bool operator==(const Coord &coord) {
        for (auto it = coord.begin(); it != coord.end(); it++) {
            if (it->second == 0) {
                continue;
            }
            if (this->find(it->first) == this->end() ||
                this->find(it->first)->second != it->second) {
                return false;
            }
        }
        return true;
    }
};

struct CoordHash {
    size_t operator()(const Coord &coord) const {
        hash<string> hash_func;
        string coord_str = "|";
        for (auto it = coord.begin(); it != coord.end(); it++) {
            if (it->second == 0) {
                continue;
            }
            coord_str += to_string(it->first) + ",";
            coord_str += to_string(it->second) + "|";
        }
        return hash_func(coord_str);
    }
};

int main() {
    int dimension = 0, length = 0;
    bool answer = true;
    cin >> dimension >> length;

    Coord coord;
    unordered_set<Coord, CoordHash> set;

    vector<int> index(length);
    vector<bool> direction(length);
    for (int i = 0; i < length; i++) {
        cin >> index[i];
        index[i]--;
    }
    cin.ignore();
    for (int i = 0; i < length; i++) {
        direction[i] = (cin.get() == '+');
    }

    set.insert(coord);
    for (int i = 0; i < length; i++) {
        coord[index[i]] += (direction[i] ? 1 : -1);
        if (coord[index[i]] == 0) {
            coord.erase(index[i]);
        }
        if (!set.insert(coord).second) {
            answer = false;
            break;
        }
    }
    cout << (int)answer << endl;

    return 0;
}
