#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q, n, k;
string s, t = "RGB";

int main() {
    cin >> q;
    while(q--) {
        cin >> n >> k >> s;

        ll ans = INT_MAX;
        for(ll i = 0; i < n - k + 1; ++i) {
            string cur = s.substr(i, k);
            //cout << cur << endl;
            for(ll rotate = 0; rotate < 3; ++rotate) {
                ll res = 0;
                for(ll j = 0; j < cur.size(); ++j) {
                    if(cur[j] != t[(j + rotate)%3]) res++;
                }
                ans = min(ans, res);
            }
        }

        cout << ans << endl;
    }

    return 0;   
}