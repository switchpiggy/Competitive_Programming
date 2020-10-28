#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, occ[200007];
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> s;
    ll ans = 0;
    char an;
    for(char a = 'a'; a <= 'z'; ++a) {
        ll res = 0, cur = 0;
        for(ll i = 0; i < (ll)s.length(); ++i) {
            if(s[i] == a) {
                cur++;
            } else {
                res += cur/k;
                cur = 0;
            }
        }

        res += cur/k;
        if(res > ans) {
            ans = res;
            an = a;
        }
    }

    cout << ans << '\n';

    return 0;
}