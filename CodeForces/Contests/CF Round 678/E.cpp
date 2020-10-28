#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], occ[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(occ, -1, sizeof(occ));

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        if(occ[a[i]] == -1) occ[a[i]] = i;
    }

    ll prev = -1;
}