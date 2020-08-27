#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m;
vector<string> v;

int main() {
    scanf("%lld", &t);
    while(t--) {
        v.clear();
        scanf("%lld %lld", &n, &m);
        for(ll i = 0; i < n; ++i) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        ll ans = 0;

        for(ll i = 0; i < m - 1; ++i) ans += v[n - 1][i] == 'D';
        for(ll i = 0; i < n - 1; ++i) ans += v[i][m - 1] == 'R';

        printf("%lld\n", ans);
    }

    return 0;
}