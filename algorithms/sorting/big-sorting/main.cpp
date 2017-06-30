#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool big_sort(string s, string t) {
    if (s.size() != t.size())
        return s.size() < t.size();

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != t[i])
            return s[i] < t[i];
    }

    return false;
}

int main(){
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }

    sort(unsorted.begin(), unsorted.end(), big_sort);

    for (int i = 0; i < n; ++i)
        cout << unsorted[i] << "\n";

    return 0;
}
