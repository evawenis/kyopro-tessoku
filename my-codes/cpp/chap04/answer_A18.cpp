#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto &&i: a) {
        cin >> i;
    }
    vector<bool> dp(s + 1, false);
    dp.front() = true;
    for (auto &&i: a) {
        for (int j = s; j >= i; --j) {
            if (dp.at(j - i)) {
                dp.at(j) = true;
            }
        }
    }
    cout << (dp.back() ? "Yes"s : "No"s) << endl;
}
