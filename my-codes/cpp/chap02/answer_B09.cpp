#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> z(1501, vector<int>(1501, 0));
    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ++z.at(c).at(b);
        ++z.at(a).at(d);
        --z.at(a).at(b);
        --z.at(c).at(d);
    }
    for (int i = 0; i < 1500; ++i) {
        for (int j = 0; j <= 1500; ++j) {
            z.at(i + 1).at(j) += z.at(i).at(j);
        }
    }
    for (int i = 0; i <= 1500; ++i) {
        for (int j = 0; j < 1500; ++j) {
            z.at(i).at(j + 1) += z.at(i).at(j);
        }
    }
    int ans = 0;
    for (auto &&i: z) {
        for (auto &&j: i) {
            if (j) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
}
