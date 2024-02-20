// BOJ-30502 / 미역은 식물 아닌데요
// devgeon, 2024.02.20, C++17
// https://www.acmicpc.net/problem/30502

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int total_types = 0, total_experiments = 0;
    int count_plants = 0, count_non_plants = 0;
    int number = 0, has_function = 0;
    char function_type = 0;
    cin >> total_types >> total_experiments;
    vector<int> is_photosynthetic(total_types, -1);
    vector<int> is_motile(total_types, -1);

    for (int i = 0; i < total_experiments; i++) {
        cin >> number >> function_type >> has_function;
        if (function_type == 'P') {
            is_photosynthetic[number - 1] = has_function;
        } else { // function_type=='M'
            is_motile[number - 1] = has_function;
        }
    }

    for (int i = 0; i < total_types; i++) {
        if (is_photosynthetic[i] == 0 || is_motile[i] == 1) {
            count_non_plants++;
        } else if (is_photosynthetic[i] == 1 && is_motile[i] == 0) {
            count_plants++;
        }
    }

    cout << count_plants << " " << total_types - count_non_plants << endl;
    return 0;
}
