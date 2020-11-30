#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> people;
    vector<int> count_vector;
    string command;
    int number;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "COME") {
            cin >> number;
            if (number > 0) {
                for (int t = 0; t < number; t++) {
                    people.push_back(0);
                }
            }
            else {
                for (int t = 0; t < -number; t++) {
                    people.pop_back();
                }
            }
        }
        else if (command == "QUIET") {
            cin >> number;
            people[number] = 0;
        }
        else if (command == "WORRY") {
            cin >> number;
            people[number] = 1;
        }
        else if (command == "WORRY_COUNT") {
            int count = 0;
            for (int r = 0; r < people.size(); r++) {
                if (people[r] == 1) {
                    count++;
                }
            }
            count_vector.push_back(count);
        }
    }
    for (auto i:count_vector) {
        cout <<i <<endl;
    }
    return 0;
}
