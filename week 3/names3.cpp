#include <iostream>
#include<vector>
#include<set>
#include <map>
#include <string>
#include <algorithm>


using namespace std;

struct PersonNameByYear {
    map<int, string> first_name;
    map <int, string> last_name;

};

class Person {
public:
    Person(const string& first_name, const string& last_name, int birth_year) {
        person_name.first_name[birth_year] = first_name;
        person_name.last_name[birth_year] = last_name;
    }

    void ChangeFirstName(int year, const string& first_name) {
        int min_year = 32566;
        for (auto &item:person_name.first_name) {
            if (min_year > item.first) {
                min_year = item.first;
            }
        }
        if (year > min_year) {
            person_name.first_name[year] = first_name;
        }

    }
    void ChangeLastName(int year, const string& last_name) {
        int min_year = 32566;
        for (auto &item:person_name.last_name) {
            if (min_year > item.first) {
                min_year = item.first;
            }
        }
        if (year > min_year) {
            person_name.last_name[year] = last_name;
        }
    }
    string GetFullName(int year) const{
        int min_year = 32566;
        for (auto &item:person_name.last_name) {
            if (min_year > item.first) {
                min_year = item.first;
            }
        }
        if (year < min_year) {
            return "No person";
        }
        bool is_exist_keyfirstname = false;
        bool is_exist_keylastname = false;
        for (auto &item:person_name.first_name) {
            if (item.first == year) {
                is_exist_keyfirstname = true;
            }
        }
        for (auto &item:person_name.last_name) {
            if (item.first == year) {
                is_exist_keylastname = true;
            }

        }
        string current_first_name;
        string current_last_name;
        if (!is_exist_keyfirstname) {
            for (auto &item: person_name.first_name) {
                if (item.first < year && !item.second.empty()) {
                    current_first_name = item.second;
                }
            }
        }
        if (!is_exist_keylastname) {
            for (auto &item: person_name.last_name) {
                if (item.first < year && !item.second.empty()) {
                    current_last_name = item.second;
                }
            }
        }
        if (!is_exist_keyfirstname && is_exist_keylastname && current_first_name.empty()) {
            return person_name.last_name.at(year) + " with unknown first name";
        }
        else if (is_exist_keyfirstname && !is_exist_keylastname && current_last_name.empty()) {
            return person_name.first_name.at(year) + " with unknown last name";
        }
        else if (!is_exist_keyfirstname && !is_exist_keylastname && current_first_name.empty() && current_last_name.empty()) {
            return "Incognito";
        }
        else if (!current_first_name.empty() && !current_last_name.empty()) {
            return current_first_name + ' ' + current_last_name;
        }
        else if (!current_first_name.empty() && current_last_name.empty() && !is_exist_keylastname) {
            return current_first_name + " with unknown last name";
        }
        else if (current_first_name.empty() && !current_last_name.empty() && !is_exist_keyfirstname) {
            return current_last_name + " with unknown first name";
        }
        else if (is_exist_keyfirstname && is_exist_keylastname){
            return person_name.first_name.at(year) + ' ' + person_name.last_name.at(year);
        }
        else if (is_exist_keyfirstname && !current_last_name.empty()) {
            return person_name.first_name.at(year) + ' ' + current_last_name;
        }
        else if (is_exist_keylastname && !current_first_name.empty()) {
            return current_first_name + ' ' + person_name.last_name.at(year);
        }
    }
    string GetFullNameWithHistory(int year) const{
        int min_year = 32566;
        for (auto &item:person_name.last_name) {
            if (min_year > item.first) {
                min_year = item.first;
            }
        }
        if (year < min_year) {
            return "No person";
        }
        vector <string> first_names;
        vector <string>last_names;
        string history;
        string year_name_and_last_name;
        string year_name;
        string year_last_name;
        string result;
        for (auto &item: person_name.first_name) {
            if (first_names.empty() && !item.second.empty()) {
                first_names.push_back(item.second);
            }
            else if (item.first <= year && !item.second.empty() && item.second != first_names[first_names.size() - 1]) {
                first_names.push_back(item.second);
            }
        }
        if (!first_names.empty()) {
            first_names.pop_back();
        }

        for (auto &item: person_name.last_name) {
            if (last_names.empty()&&!item.second.empty()) {
                last_names.push_back(item.second);
            }
            else if (item.first <= year && !item.second.empty() && item.second != last_names[last_names.size() - 1]) {
                last_names.push_back(item.second);
            }
        }
        if (!last_names.empty()) {
            last_names.pop_back();
        }
        for (int k = first_names.size() - 1; k > -1; k--) {
            history += first_names[k] + ',' + ' ';
        }
        if (!history.empty()) {
            history.erase(history.size() - 2, 2);
        }
        if (!history.empty()) {
            history = '(' + history + ')';
        }
        year_name_and_last_name = GetFullName(year);
        int i = 0;
        while (i < year_name_and_last_name.size()) {
            if (year_name_and_last_name[i] == ' ') {
                break;
            }
            else {
                i++;
            }
        }
        if (year_name_and_last_name == "Incognito") {
            year_name = year_name_and_last_name;
            result = year_name;
            return result;
        }
        else if (year_name_and_last_name.substr(i + 1) == "with unknown first name") {
            year_last_name = year_name_and_last_name.substr(0, i);
            year_name = year_name_and_last_name.substr(i + 1);
            history.clear();
            for (int item_count = last_names.size() - 1; item_count > -1; item_count--) {
                history += last_names[item_count] + ',' + ' ';
            }
            if (!history.empty()) {
                history.erase(history.size() - 2, 2);
            }
            if (!history.empty()) {
                history = '(' + history + ')';
            }
        if (!history.empty()) {
            result = year_last_name + ' ' + history + ' ' + year_name;
            return result;
        }
        return year_name_and_last_name;
        }
        else if (year_name_and_last_name.substr(i + 1) == "with unknown last name"){
            year_name = year_name_and_last_name.substr(0, i);
            year_last_name = year_name_and_last_name.substr(i+1);
            result = year_name + ' ' + history + ' ' + year_last_name;
            if (!history.empty()) {
                return result;
            }
            return year_name_and_last_name;

        }
        else {
            year_name = year_name_and_last_name.substr(0, i);
            year_last_name = year_name_and_last_name.substr(i+1);
            if (!history.empty()) {
                result = year_name + ' ' + history + ' ' + year_last_name;
            }
            else {
                result = year_name_and_last_name;
            }
            history.clear();
            for (int item_count = last_names.size() - 1; item_count > -1; item_count--) {
                history += last_names[item_count] + ',' + ' ';
            }
            if (!history.empty()) {
                history.erase(history.size() - 2, 2);
            }
            if (!history.empty()) {
                history = '(' + history + ')';
            }

            if (!history.empty()) {
                result += ' ' + history;
                return result;
            }
            return result;

        }
    }
private:
    PersonNameByYear person_name;
};



