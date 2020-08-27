#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[1007];

int main() {
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll minn = INT_MAX, mindex = -1;
    for(ll i = 0; i < n; ++i) {
        ll cnt = 0;
        bool ok = 1;

        for(ll j = 0; j < n; ++j) {
            if(a[i] + (j - i) * k <= 0) {
                ok = 0;
                break;
            }
            if(a[j] != a[i] + (j - i) * k) cnt++;
        }

        if(!ok) continue;

        if(cnt < minn) {
            minn = cnt;
            mindex = i;
        }
    }

    cout << minn << endl;
    for(ll i = 0; i < n; ++i) {
        ll target = a[mindex] + (i - mindex) * k;
        if(target < a[i]) cout << "- " << i + 1 << ' ' << abs(target - a[i]) << endl;
        else if(target > a[i]) cout << "+ " << i + 1 << ' ' << abs(target - a[i]) << endl;
    }

    return 0;
}