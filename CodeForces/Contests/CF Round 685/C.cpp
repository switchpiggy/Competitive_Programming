#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k, occ[26][2];
string s, v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        memset(occ, 0, sizeof(occ[0][0]) * 2 * 26);
        cin >> n >> k >> s >> v;

        int maxa = 0, maxb = 0;
        for(ll i = 0; i < n; ++i) {
            maxa = max(maxa, s[i] - 'a');
            maxb = max(maxb, v[i] - 'a');

            occ[s[i] - 'a'][0]++;
            occ[v[i] - 'a'][1]++;
        }

        if(maxa > maxb) {
            cout << "No\n";
            continue;
        }

        for(ll cc = 0; cc < 26; ++cc) {
            if(occ[cc][0] > occ[cc][1]) {
                occ[cc][0] -= occ[cc][1];
                occ[cc][1] = 0;
            }

            if(occ[cc][1] > occ[cc][0]) {
                occ[cc][1] -= occ[cc][0];
                occ[cc][0] = 0;
            }

            if(occ[cc][1] == occ[cc][0]) occ[cc][1] = occ[cc][0] = 0;
        }

        bool ok = 1;
        for(ll cc = 0; cc < 26; ++cc) {
            //cout << occ[cc][0] << ' ' << occ[cc][1] << '\n';
            if(!occ[cc][1]) continue;
            if(occ[cc][1]%k != 0) {
                ok = 0;
                break;
            }

            ll cur = 0;
            for(ll c = 0; c < cc; ++c) {
                if(occ[c][0]%k != 0) {
                    ok = 0;
                    break;
                }

                while(occ[c][0] && cur < occ[cc][1]) {
                    occ[c][0] -= k;
                    cur += k;
                }

                if(cur == occ[cc][1]) break;
            }

            if(cur < occ[cc][1]) ok = 0;
            if(!ok) break;
        }

        cout << (ok ? "Yes\n" : "No\n");
    }

    return 0;
}