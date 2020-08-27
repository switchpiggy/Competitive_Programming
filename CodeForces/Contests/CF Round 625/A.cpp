#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
ll a[107];
ll ba[107];

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n; ++i) cin >> ba[i];

    //for(int i = 0; i < n; ++i) cout << ba[i] << ' ';

    ll r = 0, b = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] && !ba[i]) r++;
        else if(!a[i] && ba[i]) b++;
    }

    if(!r) {
        cout << "-1" << endl;
        return 0;
    }

    cout << b/r + 1 << endl;
    return 0;
}