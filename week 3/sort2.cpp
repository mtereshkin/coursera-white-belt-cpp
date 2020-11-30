#include <iostream>
#include<vector>
#include<algorithm>
#include <cctype>
#include <string>

using namespace std;

int main() {
    int n;
    vector <string> letters;
    cin >> n;
    string letter;
    for (int i = 0; i < n; i++) {
        cin >> letter;
        letters.push_back(letter);
    }
    sort(begin(letters), end(letters), [](string a, string b) {
        for (auto &item:a) {
            item = (char)tolower(item);
        }
        for (auto &item:b) {
            item = (char)tolower(item);
        }
        if (a < b) {
            return true;
        }
        return false;
    });
    for(auto &item:letters) {
        cout << item << ' ';
    }
    return 0;
}
