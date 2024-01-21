// BOJ-02327 / 말아톤
// devgeon, 2024.01.21, C++17
// https://www.acmicpc.net/problem/2327

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int HEIGHT = 0, SPEED = 1;
    int height_requirement = 0, num_of_students = 0, height = 0, speed = 0;
    cin >> height_requirement >> num_of_students;
    vector<vector<int>> students(num_of_students, vector<int>(2, 0));
    vector<vector<int>> table(num_of_students,
                              vector<int>(height_requirement, -1));
    for (int i = 0; i < num_of_students; i++) {
        cin >> students[i][HEIGHT] >> students[i][SPEED];
    }

    for (int r = 0; r < num_of_students; r++) {
        height = students[r][HEIGHT];
        speed = students[r][SPEED];
        for (int c = 0; c < height_requirement; c++) {
            if (r - 1 >= 0) {
                table[r][c] = table[r - 1][c];
                if (c - height >= 0) {
                    table[r][c] =
                        max(table[r][c], min(table[r - 1][c - height], speed));
                }
            }
            if (c - height + 1 == 0) {
                table[r][c] = max(table[r][c], speed);
            }
        }
    }

    cout << table[num_of_students - 1][height_requirement - 1] << endl;
    return 0;
}
