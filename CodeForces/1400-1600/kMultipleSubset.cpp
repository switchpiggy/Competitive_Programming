#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[100007];
set<ll> s;

int main() {
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n);

    for(ll i = 0; i < n; ++i) {
        if(a[i]%k == 0 && s.count(a[i]/k)) continue;
        s.insert(a[i]);
    }

    cout << s.size();
    return 0;
}