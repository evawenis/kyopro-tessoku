#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    if (!n) {
        return 0;
    }
    return solve(n / 2) * 10 + n % 2;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << setfill('0') << setw(10) << solve(n) << endl;
}
