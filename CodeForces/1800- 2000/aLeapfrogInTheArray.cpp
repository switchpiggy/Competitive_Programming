#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, x;

ll solve(ll x) {
    if(x%2 == 1) return (x + 1)/2;
    return solve(x + (n - x/2));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    while(q--) {
        cin >> x;
        cout << solve(x) << '\n';
    }

    return 0;
}