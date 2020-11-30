#include <iostream>
#include<vector>
#include<set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct Specialization {
    string specialization;
    explicit Specialization (const string& new_specialization) {
        specialization = new_specialization;
    }
};

struct Course {
    string course;
    explicit Course (const string& new_course) {
        course = new_course;
    }
};

struct Week {
    string week;
    explicit Week(const string& new_week) {
        week = new_week;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(Specialization new_specialization, Course new_course, Week new_week) {
        specialization = new_specialization.specialization;
        course = new_course.course;
        week = new_week.week;
    }
};
