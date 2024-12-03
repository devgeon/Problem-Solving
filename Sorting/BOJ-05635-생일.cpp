// BOJ-05635 / 생일
// devgeon, 2024.12.03, C++17
// https://www.acmicpc.net/problem/5635

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Date {
  public:
    int year, month, day;

    bool operator>(const Date &date) {
        if (year > date.year || year == date.year && month > date.month ||
            month == date.month && day > date.day) {
            return true;
        }
        return false;
    }

    friend istream &operator>>(istream &in, Date &date) {
        in >> date.day >> date.month >> date.year;
        return in;
    }
};

class Person {
  public:
    string name;
    Date birthday;

    bool operator<(const Person &person) {
        if (birthday > person.birthday) {
            return true;
        }
        return false;
    }

    friend istream &operator>>(istream &in, Person &person) {
        person.birthday = Date();
        in >> person.name >> person.birthday;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Person &person) {
        out << person.name;
        return out;
    }
};

int main() {
    int num = 0;
    cin >> num;

    vector<Person> people(num);
    for (Person &person : people) {
        cin >> person;
    }
    sort(people.begin(), people.end());

    cout << people[0] << '\n' << people[num - 1] << endl;

    return 0;
}
