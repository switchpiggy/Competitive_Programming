#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i]) occ[a[i]]++;
    }

    cout << (ll)occ.size() << '\n';
    return 0;
}