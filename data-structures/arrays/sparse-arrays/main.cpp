#include <iostream>
#include <map>

using namespace std;

int main() {
    int n_s, n_q;
    string s, q;
    map<string, unsigned> counts;

    cin >> n_s;
    for (int i = 0; i < n_s; ++i) {
        cin >> s;
        if (!counts.count(s))
            counts[s] = 0;

        counts[s] += 1;
    }

    cin >> n_q;
    for (int j = 0; j < n_q; ++j) {
        cin >> q;
        cout << counts[q] << "\n";
    }

    return 0;
}
