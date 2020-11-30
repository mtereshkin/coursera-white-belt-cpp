#include <iostream>
#include<vector>
#include<string>
#include <map>
#include<set>

using namespace std;
int main() {
    int n;
    cin >> n;
    map<string, set<string>> synonims_dict;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            synonims_dict[word1].insert(word2);
            synonims_dict[word2].insert(word1);
        }
        else if (command == "COUNT") {
            string word;
            cin >> word;
            int count = 0;
            cout << synonims_dict[word].size() + count<<endl;
        }
        else if (command == "CHECK") {
            string  word1, word2;
            int indicator = 0;
            cin >>word1 >> word2;
            if (synonims_dict[word1].count(word2) == 1 || synonims_dict[word2].count(word1) == 1) {
                cout << "YES"<<endl;
            }
            else {
                cout << "NO"<<endl;
            }
        }
    }
    return 0;
}
