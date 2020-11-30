#include <iostream>
#include<vector>
#include<algorithm>
#include <map>
#include <string>


using namespace std;

struct PersonNameByYear {
    map<int, string> first_name;
    map <int, string> last_name;

};

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        person_name.first_name[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        person_name.last_name[year] = last_name;
    }
    string GetFullName(int year) {
        string current_first_name;
        string current_last_name;
        if (person_name.first_name[year].empty()) {
            for (auto &item: person_name.first_name) {
                if (item.first < year && !item.second.empty()) {
                    current_first_name = item.second;
                }
            }
        }
        if (person_name.last_name[year].empty()) {
            for (auto &item: person_name.last_name) {
                if (item.first < year && !item.second.empty()) {
                    current_last_name = item.second;
                }
            }
        }
        if (person_name.first_name[year].empty() && !person_name.last_name[year].empty() && current_first_name.empty()) {
            return person_name.last_name[year] + " with unknown first name";
        }
        else if (!person_name.first_name[year].empty() && person_name.last_name[year].empty() && current_last_name.empty()) {
            return person_name.first_name[year] + " with unknown last name";
        }
        else if (person_name.first_name[year].empty() && person_name.last_name[year].empty() && current_first_name.empty() && current_last_name.empty()) {
            return "Incognito";
        }
        else if (!current_first_name.empty() && !current_last_name.empty()) {
            return current_first_name + ' ' + current_last_name;
        }
        else if (!current_first_name.empty() && current_last_name.empty() && person_name.last_name[year].empty()) {
            return current_first_name + " with unknown last name";
        }
        else if (current_first_name.empty() && !current_last_name.empty() && person_name.first_name[year].empty()) {
            return current_last_name + " with unknown first name";
        }
        else if (!person_name.first_name[year].empty() && !person_name.last_name[year].empty()){
            return person_name.first_name[year] + ' ' + person_name.last_name[year];
        }
        else if (!person_name.first_name[year].empty() && !current_last_name.empty()) {
            return person_name.first_name[year] + ' ' + current_last_name;
        }
        else if (!person_name.last_name[year].empty() && !current_first_name.empty()) {
            return current_first_name + ' ' + person_name.last_name[year];
        }
    }
private:
    PersonNameByYear person_name;
};

