#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include<algorithm>
#include <stdexcept>
#include <iostream>
#include <exception>
#include <string>
#include <iomanip>
#include <iterator>
using namespace std;




class Date {
public:
    Date(int year_input, int month_input, int day_input) {
        if (month_input < 1 || month_input > 12) {
            throw invalid_argument("Month value is invalid: " + to_string(month_input));
        }
        else if (day_input < 1 || day_input > 31) {
            throw invalid_argument("Day value is invalid: " + to_string(day_input));
        }
        year = year_input;
        month = month_input;
        day = day_input;
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }

private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs)  {
    if (lhs.GetYear() < rhs.GetYear()) {
        return true;
    }
    else if (lhs.GetYear() > rhs.GetYear()) {
        return false;
    }
    else {
        if (lhs.GetMonth() < rhs.GetMonth()) {
            return true;
        } else if (lhs.GetMonth() > rhs.GetMonth()) {
            return false;
        }
        else {
            return lhs.GetDay() < rhs.GetDay();
        }
    }
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        if (count(begin(dates_events[date]), end(dates_events[date]), event) == 0) {
            dates_events[date].push_back(event);
        }

    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (count(begin(dates_events[date]), end(dates_events[date]), event) == 0) {
            return false;
        }
        else {
            dates_events[date].erase(find(begin(dates_events[date]), end(dates_events[date]), event));
            return true;
        }
    }
    int  DeleteDate(const Date& date) {
        int N = dates_events[date].size();
        dates_events.erase(date);
        return N;
    }

    vector<string> Find(const Date& date)  {
        bool ind = false;
        for (auto &item:dates_events) {
            if (item.first.GetYear() ==  date.GetYear() && item.first.GetMonth() == date.GetMonth() && item.first.GetDay() == date.GetDay()) {
                ind = true;
            }
        }
        if (ind) {
            sort(begin(dates_events.at(date)), end(dates_events.at(date)));
            return dates_events.at(date);
        }
        else {
            throw out_of_range("");
        }

    }

    void Print()  {
        for (auto& item: dates_events) {
            sort(begin(item.second), end(item.second));
            for (auto& event:item.second) {
                cout << setw(4) << setfill('0') << item.first.GetYear() << '-' << setw(2) <<
                setfill('0')<<item.first.GetMonth()<< '-' << setw(2) <<setfill('0')<<item.first.GetDay()<<
                ' '<< event<<endl;

            }
        }
    }
private:
    map<Date, vector<string>> dates_events;
};



int main() {
    Database db;
    string command;
    while (getline(cin, command)) {
        stringstream ss;
        if (command.substr(0, 3) == "Add") {
            ss << command.substr(4, command.size() - 4);
            string event;
            int year;
            int month;
            int day;
            bool flag = true;
            ss>>year;
            if (ss.bad() || ss.peek() != '-') {
                flag = false;
                cout << "Wrong date format: " << command.substr(4, find(begin(command) + 4, end(command), ' ') - begin(command) - 4) << endl;
            }
            else {
                ss.ignore(1);
                ss >> month;
                if (ss.bad() || ss.peek() != '-') {
                    flag = false;
                    cout << "Wrong date format: " << command.substr(4, find(begin(command) + 4, end(command), ' ') - begin(command) - 4) << endl;
                } else {
                    ss.ignore(1);
                    ss >> day;
                    if (ss.bad() || ss.peek() != ' ') {
                        flag = false;
                        cout << "Wrong date format: " << command.substr(4, find(begin(command) + 4, end(command), ' ') - begin(command) - 4) << endl;
                    }
                    else {
                        ss>> event;
                    }
                }
            }
            if (flag) {
                try {
                    Date date = Date(year, month, day);
                    db.AddEvent(date, event);
                }
                catch (invalid_argument& inv_arg) {
                    cout << inv_arg.what()<<endl;
                }
            }
        }
        else if (command.substr(0, 4) == "Find") {
            ss << command.substr(5, command.size() - 5);
            string event;
            int year;
            int month;
            int day;
            bool flag = true;
            ss>>year;
            if (ss.bad() || ss.peek() != '-') {
                flag = false;
                cout << "Wrong date format: " << command.substr(5, find(begin(command) + 5, end(command), ' ') - begin(command) - 5) << endl;
            }
            else {
                ss.ignore(1);
                ss >> month;
                if (ss.bad() || ss.peek() != '-') {
                    flag = false;
                    cout << "Wrong date format: " << command.substr(5, find(begin(command) + 5, end(command), ' ') - begin(command) - 5) << endl;
                } else {
                    ss.ignore(1);
                    ss >> day;
                    if (ss.bad()) {
                        flag = false;
                        cout << "Wrong date format: " << command.substr(5, find(begin(command) + 5, end(command), ' ') - begin(command) - 5) << endl;
                    }
                    else {
                    }
                }
            }
            if (flag) {
                try {
                    Date date = Date(year, month, day);
                    vector<string> events = db.Find(date);
                    for (auto &item: events) {
                        cout << item <<endl;
                    }
                }
                catch (invalid_argument& inv_arg) {
                    cout << inv_arg.what()<<endl;
                }
                catch (out_of_range& out) {

                }
            }
        }
        else if (command.substr(0, 5) == "Print") {
            db.Print();
        }

        else if (command.substr(0, 3) == "Del") {
            ss << command.substr(4, command.size() - 4);
            string event;
            int year;
            int month;
            int day;
            bool flag = true;
            ss>>year;
            if (ss.bad() || ss.peek() != '-') {
                flag = false;
                cout << "Wrong date format: " << command.substr(4, find(begin(command) + 4, end(command), ' ') - begin(command) - 4) << endl;
            }
            else {
                ss.ignore(1);
                ss >> month;
                if (ss.bad() || ss.peek() != '-') {
                    flag = false;
                    cout << "Wrong date format: " << command.substr(4, find(begin(command) + 4, end(command), ' ') - begin(command) - 4) << endl;
                } else {
                    ss.ignore(1);
                    ss >> day;
                    if (ss.bad() || !ss.eof() && ss.peek() != ' ') {
                        flag = false;
                        cout << "Wrong date format: " << command.substr(4, find(begin(command) + 4, end(command), ' ') - begin(command) - 4) << endl;
                    }
                }
            }
            if (flag) {
                if (ss.eof()) {
                    try {
                        Date date = Date(year, month, day);
                        int n = db.DeleteDate(date);
                        cout << "Deleted " << n <<" events"<<endl;
                    }
                    catch (invalid_argument& inv_arg) {
                        cout << inv_arg.what()<<endl;
                    }
                }
                else {
                    ss >> event;
                    try {
                        Date date = Date(year, month, day);
                        bool indicator = db.DeleteEvent(date, event);
                        if (indicator) {
                            cout << "Deleted successfully" <<endl;
                        }
                        else {
                            cout <<"Event not found" <<endl;
                        }
                    }
                    catch (invalid_argument& inv_arg) {
                        cout << inv_arg.what()<<endl;
                    }
                }

            }
        }
        else if (!command.empty()) {
            cout << "Unknown command:" << ' ' <<command.substr(0, find(begin(command), end(command), ' ') - begin(command))
            <<endl;
        }
    }

    return 0;
}

