#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    cin >> n;
    if(n < 3) {
        cout << "-1" << endl;
        return 0;
    }
    if(n == 3) {
        cout << 210 << endl;
        return 0;
    }
    
    ll r = 1000%210;

    for(ll i = 5; i <= n; ++i) r = (r * 10)%210;
    r = (210 - r)%210;

    cout << 1;
    for(ll i = 1; i < n - 3; ++i) cout << 0;
    string j = to_string(r);

    for(ll i = 0; i < 3 - j.length(); ++i) cout << 0;
    cout << r << endl;

    return 0;
}