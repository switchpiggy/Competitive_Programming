#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll h;

ll solve(ll x) {
    if(x == 1) return 1;
    return 1 + 2 * (solve(x/2));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h;
    cout << solve(h) << '\n';
}