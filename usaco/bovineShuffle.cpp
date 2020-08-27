#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
ll n, pos[107];
string id[107];
string res[107];
 
int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    scanf("%lld", &n);
    for(ll i = 0; i < n;++i) scanf("%lld", &pos[i]);
    for(ll i = 0; i < n; ++i) cin >> id[i];
 
    for(ll i = 0; i < n; ++i) {
        res[pos[i] - 1] = id[i];
    }
 
    for(ll i = 0; i < n; ++i) cout << res[i] << endl;

    return 0;
}