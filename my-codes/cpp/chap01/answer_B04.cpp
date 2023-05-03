#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    if (!n) {
        return 0;
    }
    return solve(n / 10) * 2 + n % 10;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << solve(n) << endl;
}
