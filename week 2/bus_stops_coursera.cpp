#include <iostream>
#include<vector>
#include<string>
#include <map>

using namespace std;
int main() {
    int n;
    cin >> n;
    map <string, vector<string>> bus_schedule;
    string command;
    vector<string> bus_order;
    string bus_stop;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "NEW_BUS") {
            string bus;
            int stop_count;
            cin >> bus;
            cin >> stop_count;
            for (int j = 0; j < stop_count; j++) {
                cin >> bus_stop;
                bus_schedule[bus].push_back(bus_stop);
            }
            bus_order.push_back(bus);
        }
        else if (command == "BUSES_FOR_STOP") {
            string stop;
            string result_bfs;
            cin >> stop;
            int count = 0;
            for (auto &item:bus_order) {
                for (auto &item_stop:bus_schedule[item]) {
                    if (item_stop == stop) {
                        cout << item << ' ';
                        count++;
                    }
                }
            }
            if (count != 0) {
                cout << endl;
            }
            else {
                cout << "No stop" << endl;
            }
        }
        else if (command == "ALL_BUSES") {
            if (bus_schedule.empty()) {
                cout << "No buses" << endl;
            }
            for (auto &item:bus_schedule) {
                cout <<"Bus"<<' '<< item.first << ":" <<' ';
                for (auto &station:item.second) {
                    cout << station << ' ';
                }
                cout << endl;
            }

        }
        else if (command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            int indicator = 0;
            int buses_count;
            for (auto &item:bus_schedule) {
                if (item.first == bus) {
                    indicator++;
                    for (auto &station_item:item.second) {
                        cout << "Stop" << ' '<< station_item << ':' << ' ';
                        buses_count = 0;
                        for (auto &buses:bus_order) {
                            if (buses == bus && bus_order.size() > 1) {
                                continue;
                            }
                            else if (bus_order.size() == 1) {
                                break;
                            }
                            else {
                                for (auto &item_stop:bus_schedule[buses]) {
                                    if (item_stop == station_item) {
                                        cout << buses << ' ';
                                        buses_count++;
                                        break;
                                    }
                                }
                            }
                        }
                        if (buses_count == 0) {
                            cout << "no interchange";
                        }
                        cout << endl;
                    }
                }
            }
            if (indicator == 0) {
                cout << "No bus" << endl;
            }
        }
    }
    return 0;
}
