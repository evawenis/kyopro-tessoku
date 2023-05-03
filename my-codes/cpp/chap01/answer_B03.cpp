#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &&i: a) {
        cin >> i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (a.at(i) + a.at(j) + a.at(k) == 1000) {
                    cout << "Yes"s << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No"s << endl;
}
