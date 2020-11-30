#include <iostream>
#include<vector>
#include<string>
#include <map>
#include<set>

using namespace std;
int main() {
    int n;
    cin >> n;
    int indicator;
    set <string> route_set;
    map<set<string>, int> routes;
    for (int i = 0; i < n; i++) {
        int number_of_stops;
        cin >> number_of_stops;
        set<string> stops;
        string stop;
        for (int j = 0; j < number_of_stops; j++) {
            cin >> stop;
            stops.insert(stop);
        }
        if (!routes.empty()) {
            indicator = 0;
            for (auto &item:routes) {
                if (item.first == stops) {
                    cout << "Already exists for" << ' ' << item.second << endl;
                    indicator = item.second;
                    break;
                }
            }
            if (indicator == 0) {
                int new_value = routes.size();
                routes[stops] = new_value + 1;
                cout << "New bus" << ' ' <<new_value + 1<<endl;
            }

        }
        else {
            routes[stops] = 1;
            cout << "New bus 1" << endl;
        }
        stops.clear();
    }
    return 0;
}
