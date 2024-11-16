#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, sum = 0, count = 0;
    cin >> num;

    vector<int> seq(num, 0);
    for (int &n : seq) {
        cin >> n;
    }
    sort(seq.begin(), seq.end());
    cin >> sum;

    for (int n : seq) {
        count += upper_bound(seq.begin(), seq.end(), sum - n) -
                 lower_bound(seq.begin(), seq.end(), sum - n);
    }
    cout << count / 2 << endl;

    return 0;
}
