#include <iostream>

using namespace std;

string super_reduced_string(string s){
    string r = "";
    for (int i = 0; i < s.size(); ++i) {
        r.push_back(s[i]);
        if (r.size() > 1) {
            while (r[r.size() - 1] == r[r.size() - 2]) {
                r.pop_back();
                r.pop_back();
                if(r.size() == 0)
                    break;
            }
        }
    }

    if (r == "")
        return "Empty String";

    return r;
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}