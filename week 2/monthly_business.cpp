#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    int months = 1;
    cin >> q;
    vector<vector<string>> current_month(31);

    for (int i = 0; i < q; ++i) {
        string code;
        cin >> code;

        if (code == "ADD") {
            int date;
            cin >> date;
            string business;
            cin >> business;
            current_month[date-1].push_back(business);

        } else {
            if (code == "DUMP") {
                int date_index;
                cin >> date_index;
                cout << current_month[date_index-1].size();
                for (auto c : current_month[date_index-1]) {
                    cout << " " << c;
                }
                cout << endl;
            }

            else if (code == "NEXT") {

                months++;
                if (months > 12)
                {
                    months = months % 12;
                }
                switch (months)
                {
                    case 2: {
                        vector<string> extra_business;
                        for (int j = 28; j < current_month.size(); j++) {
                            for (auto s : current_month[j]) {
                                extra_business.push_back(s);
                            }
                        }
                        current_month.resize(28);
                        current_month[current_month.size() - 1].insert(end(current_month[current_month.size()-1]), begin(extra_business), end(extra_business));
                        extra_business.clear();
                        break;
                    }
                    case 4: {
                        vector<string> extra_business;
                        for (int j = 30; j < current_month.size(); j++) {
                            for (auto s : current_month[j]) {
                                extra_business.push_back(s);
                            }
                        }
                        current_month.resize(30);
                        current_month[current_month.size() - 1].insert(end(current_month[current_month.size()-1]), begin(extra_business), end(extra_business));
                        extra_business.clear();
                        break;
                    }
                    case 6: {
                        vector<string> extra_business;
                        for (int j = 30; j < current_month.size(); j++) {
                            for (auto s : current_month[j]) {
                                extra_business.push_back(s);
                            }
                        }
                        current_month.resize(30);
                        current_month[current_month.size() - 1].insert(end(current_month[current_month.size()-1]), begin(extra_business), end(extra_business));
                        extra_business.clear();
                        break;
                    }
                    case 9: {
                        vector<string> extra_business;
                        for (int j = 30; j < current_month.size(); j++) {
                            for (auto s : current_month[j]) {
                                extra_business.push_back(s);
                            }
                        }
                        current_month.resize(30);
                        current_month[current_month.size() - 1].insert(end(current_month[current_month.size()-1]), begin(extra_business), end(extra_business));
                        extra_business.clear();
                        break;
                    }
                    case 11: {
                        vector<string> extra_business;
                        for (int j = 30; j < current_month.size(); j++) {
                            for (auto s : current_month[j]) {
                                extra_business.push_back(s);
                            }
                        }
                        current_month.resize(30);
                        current_month[current_month.size() - 1].insert(end(current_month[current_month.size()-1]), begin(extra_business), end(extra_business));
                        extra_business.clear();
                        break;
                    }
                    default:
                    {
                        current_month.resize(31);
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
