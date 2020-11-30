#include <iostream>
#include<vector>
#include<algorithm>
#include <cmath>


bool Comparator(int a, int b) {
    if (abs(a) < abs(b)) {
        return true;
    }
    return false;
}

using namespace std;
int main() {
    int n;
    cin >> n;
    vector <int> numbers;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        numbers.push_back(number);
    }
    sort(begin(numbers), end(numbers), Comparator);
    for (auto &item:numbers) {
        cout << item << ' ';
    }
    return 0;
}
