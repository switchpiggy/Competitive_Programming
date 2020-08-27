#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, cnt[107];
vector<string> v;
const ll MOD = 1e9 + 7;

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    for(ll i = 0; i < m; ++i) {
        set<char> c;
        for(ll j = 0; j < n; ++j) c.insert(v[j][i]);
        cnt[i] = c.size();
    } 

    ll res = 1;
    for(ll i = 0; i < m; ++i) {
        res *= cnt[i]%MOD;
        res %= MOD;
    }

    printf("%lld\n", res);
    return 0;
}