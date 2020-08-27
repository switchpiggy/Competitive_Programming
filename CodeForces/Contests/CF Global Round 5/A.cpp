#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[13847], ans[13847];

void sol() {
    for(ll i = 0; i < n; ++i) cout << ans[i] << endl;
    exit(0);
}

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll sum = 0;
    for(ll i = 0; i < n; ++i) {
        ans[i] = a[i]/2;
        sum += ans[i];
    }

    bool ok = 0;
    if(sum > 0) ok = 1;
    else if(sum < 0) ok = 0;
    else sol();

    for(ll i = 0; i < n; ++i) {
        if(ok) {
            if(a[i] < 0 && a[i]%2 != 0) {
                ans[i]--;
                sum--;
            }
        } else {
            if(a[i] > 0 && a[i]%2 != 0) {
                ans[i]++;
                sum++;
            }
        }

        if(sum == 0) {
            sol();
        }
    }

    return 0;
}