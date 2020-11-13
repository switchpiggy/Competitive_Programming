#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];
vector<ll> zero, one;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n - 1; ++i) {
        if(a[i]%2 == a[i + 1]%2 && a[i]%2 == 1) {
            a[i]--;
            a[i + 1]--;
            i++;
        }
    }

    ll cur = 1;
    for(ll i = 1; i < n; ++i) {
        if(a[i]%2 == a[i - 1]%2) cur++;
        else {
            if(a[i - 1]%2 == 0) zero.push_back(cur);
            else one.push_back(cur);
            cur = 1;
        }
    }

    if(a[n - 1]%2 == 0) zero.push_back(cur);
    else one.push_back(cur);

    bool ok = 1;
    for(ll i = 0; i < (ll)zero.size(); ++i) {
        if(zero[i]%2) {
            ok = 0;
            break;
        }
    }

    bool ok2 = 1;
    for(ll i = 0; i < (ll)one.size(); ++i) {
        if(one[i]%2) {
            ok2 = 0;
            break;
        }
    }

    if(ok || ok2) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}