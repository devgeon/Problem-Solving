// BOJ-18706 / Coffee
// devgeon, 2024.08.22, C++17
// https://www.acmicpc.net/problem/18706

#include <iostream>
#include <unordered_map>

using namespace std;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 0;
    cin >> cases;

    while (cases--) {
        solve();
    }

    return 0;
}

void solve() {
    int num_of_menus = 0, num_of_persons = 0, delivery_fee = 100;
    string menu_name = "", person_name = "", size = "";
    int small_price = 0, medium_price = 0, large_price = 0, total_price = 0, delivery_fee_per_person = 0;
    unordered_map<string, unordered_map<string, int>> menus;

    cin >> num_of_menus >> num_of_persons;
    delivery_fee_per_person = delivery_fee / num_of_persons;
    for (int i = 0; i < num_of_menus; i++) {
        cin >> menu_name >> small_price >> medium_price >> large_price;
        menus[menu_name] = unordered_map<string, int>({
            {"small", small_price},
            {"medium", medium_price},
            {"large", large_price}
        });
    }
    for (int i = 0; i < num_of_persons; i++) {
        cin >> person_name >> size >> menu_name;
        total_price = menus[menu_name][size] + delivery_fee_per_person;
        if (total_price % 5 == 1) {
            total_price--;
        } else if (total_price % 5 == 4) {
            total_price++;
        }
        cout << person_name << ' ' << total_price << '\n';
    }
}
