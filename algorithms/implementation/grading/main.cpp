// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

vector < int > solve(vector < int > grades){
    vector < int > rounded_grades;
    for (ssize_t i = 0; i < grades.size(); ++i) {
        int rounded_grade;
        int grade = grades[i];

        if (grade < 38) {
            rounded_grade = grade;
        } else if (grade % 5 >= 3) {
            rounded_grade = 5 * (1 + grade / 5);
        } else {
            rounded_grade = grade;
        }

        rounded_grades.push_back(rounded_grade);
    }

    return rounded_grades;
}

int main() {
    int n;
    cin >> n;
    vector<int> grades(n);
    for(int grades_i = 0; grades_i < n; grades_i++){
        cin >> grades[grades_i];
    }
    vector < int > result = solve(grades);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
