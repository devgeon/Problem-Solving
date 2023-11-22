// BOJ-12865 / 평범한 배낭
// devgeon, 2023.11.22, C++17
// https://www.acmicpc.net/problem/12865

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int total_object = 0, max_weight = 0;
    cin >> total_object >> max_weight;
    vector<vector<int>> object_data(total_object, vector<int>(2, 0));
    vector<vector<int>> table(total_object + 1, vector<int>(max_weight + 1, 0));

    for (int i = 0; i < total_object; i++) {
        int weight = 0, value = 0;
        cin >> weight >> value;
        object_data[i][0] = weight;
        object_data[i][1] = value;
    }

    for (int obj_num = 1; obj_num < total_object + 1; obj_num++) {
        for (int weight = 1; weight < max_weight + 1; weight++) {
            // 물건이 무게제한에 걸리지 않아 담을 수 있을 때
            if (object_data[obj_num - 1][0] <= weight) {
                table[obj_num][weight] = max(
                    // 물건을 담지 않는 경우
                    table[obj_num - 1][weight],
                    // 물건을 담는 경우
                    table[obj_num - 1][weight - object_data[obj_num - 1][0]] +
                        object_data[obj_num - 1][1]);
            } else {
                table[obj_num][weight] = table[obj_num - 1][weight];
            }
        }
    }

    cout << table[total_object][max_weight];
    return 0;
}
