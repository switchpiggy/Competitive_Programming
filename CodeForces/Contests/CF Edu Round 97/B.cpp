#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> s;
        ll cur = 0, maxn = 0;
        for(ll i = 0; i < (ll)s.length(); ++i) {
            if(s[i] == '1') cur++;
            else {
                maxn = max(maxn, cur);
                cur = 0;
            }
        }

        maxn = max(cur, maxn);

        if(maxn) cout << maxn - 1 << '\n';
        else cout << 0 << '\n';
    }
}