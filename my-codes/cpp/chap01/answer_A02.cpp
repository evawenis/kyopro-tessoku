#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &&i: a) {
        cin >> i;
    }
    cout << (find(a.begin(), a.end(), x) != a.end() ? "Yes"s : "No"s) << endl;
}
