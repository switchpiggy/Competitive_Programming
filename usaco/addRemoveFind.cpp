#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
map<ll, ll> occ;
ll n;

int main() {
    scanf("%lld", &n);

    for(ll i = 0; i < n; ++i) {
        string s;
        ll k;
        cin >> s >> k;

        if(s == "Add") {
            occ[k]++;
        } else if(s == "Remove") {
            if(occ[k]) occ[k]--;
        } else {
            printf("%lld\n", occ[k]);
        }
    }

    return 0;
}