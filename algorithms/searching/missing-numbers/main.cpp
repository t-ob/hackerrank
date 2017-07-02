#include <vector>
#include <iostream>


static const int max_diff = 101;
using namespace std;


int main() {
    int m, n;

    int x;
    int x_min = 0;
    int a[max_diff] = {0};
    int b[max_diff] = {0};

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a[x % max_diff] += 1;
    }

    cin >> m;
    for (int j = 0; j < m; ++j) {
        cin >> x;
        if (!x_min || x_min > x)
            x_min = x;

        b[x % max_diff] += 1;
    }

    for (int k = 0; k < max_diff; ++k) {
        int idx = (x_min + k) % max_diff;
        if (a[idx] != b[idx]) {
            cout << x_min + k << " ";
        }
    }
    
    cout << "\n";

    return 0;
}
