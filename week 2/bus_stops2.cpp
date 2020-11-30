#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;
    map <vector<string>, int> routes;
    for (int i = 0; i < q; i++)
    {
        int stops_number;
        cin >> stops_number;
        vector<string> stops;
        for (int j = 0; j < stops_number; j++) {
            string stop;
            cin >> stop;
            stops.push_back(stop);
        }
            if (routes.count(stops) == 0) {
                int route_number = routes.size();
                routes[stops] = route_number + 1;
                cout << "New bus " << route_number + 1 << endl;
            } else{
                cout << "Already exists for " << routes[stops] << endl;
            }
            stops.clear();
    }
    return 0;
}
