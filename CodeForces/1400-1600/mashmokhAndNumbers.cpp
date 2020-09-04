#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    if(n == 1 && k) {
        cout << "-1" << '\n';
        return 0; 
    }
    if(n == 1 && !k) {
        cout << 1 << '\n';
        return 0;
    }
    if(n/2 > k) {
        cout << "-1\n";
        return 0;
    }

    cout << k - (n - 2)/2 << ' ' << 2 * (k - (n - 2)/2) << ' ';
    for(ll i = 1; i < n - 1; ++i) cout << 2 * (k - (n - 2)/2) + i << ' ';
    cout << '\n';

    return 0;
}