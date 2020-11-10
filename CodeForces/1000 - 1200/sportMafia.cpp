#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    ll l = 0, r = n + 1;
    while(l < r) {
        ll m = (l + r)/2;
        if((m * (m + 1))/2 - (n - m) == k) {
            cout << n - m << '\n';
            return 0;
        } else if((m * (m + 1))/2 - (n - m) < k) l = m + 1;
        else r = m;
    }

    return 0;
}