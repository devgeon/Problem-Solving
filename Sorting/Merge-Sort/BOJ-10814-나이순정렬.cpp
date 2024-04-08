// BOJ-10814 / 나이순 정렬
// devgeon, 2024.04.08, C++17
// https://www.acmicpc.net/problem/10814

#include <iostream>
#include <vector>

using namespace std;

class Member {
  public:
    string name = "";
    int age = 0;
    int registration_time = 0;

    Member(string name, int age, int registration_time) {
        this->name = name;
        this->age = age;
        this->registration_time = registration_time;
    }

    bool operator==(const Member &member) const {
        return (this->age == member.age &&
                this->registration_time == member.registration_time);
    }

    bool operator<(const Member &member) const {
        return ((this->age < member.age) ||
                (this->age == member.age &&
                 this->registration_time < member.registration_time));
    }

    bool operator>(const Member &member) const {
        return ((this->age > member.age) ||
                (this->age == member.age &&
                 this->registration_time > member.registration_time));
    }

    bool operator<=(const Member &member) const {
        return (*this < member || *this == member);
    }

    bool operator>=(const Member &member) const {
        return (*this > member || *this == member);
    }
};

void merge_sort(vector<Member> &members, int begin, int end);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, age = 0;
    string name = "";
    cin >> num;

    vector<Member> members;
    members.reserve(num);
    for (int i = 0; i < num; i++) {
        cin >> age >> name;
        members.push_back(Member(name, age, i));
    }

    merge_sort(members, 0, num);

    for (auto member : members) {
        cout << member.age << ' ' << member.name << '\n';
    }

    return 0;
}

void merge_sort(vector<Member> &members, int begin, int end) {
    int mid = (begin + end) / 2, left = begin, right = mid;
    vector<Member> sorted;

    if (end - begin == 1) {
        return;
    }

    sorted.reserve(end - begin);
    merge_sort(members, begin, mid);
    merge_sort(members, mid, end);

    while (left < mid && right < end) {
        if (members[left] < members[right]) {
            sorted.push_back(members[left++]);
        } else {
            sorted.push_back(members[right++]);
        }
    }
    while (left < mid) {
        sorted.push_back(members[left++]);
    }
    while (right < end) {
        sorted.push_back(members[right++]);
    }

    for (int i = begin; i < end; i++) {
        members[i] = sorted[i - begin];
    }
}
