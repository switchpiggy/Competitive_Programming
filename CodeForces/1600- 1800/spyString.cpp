#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        v.clear();
        cin >> n >> m;
        for(ll i = 0; i < n; ++i) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        bool ok3 = 0;

        for(ll i = 0; i < m; ++i) {
            bool ok2 = 0;
            for(char c = 'a'; c <= 'z'; ++c) {
                if(c == v[0][i] && i != 0) continue;
                bool ok = 1;

                string s = v[0];
                s[i] = c;

                for(ll k = 1; k < n; ++k) {
                    ll cnt = 0;
                    for(ll l = 0; l < m; ++l) {
                        if(v[k][l] != s[l]) cnt++;
                    }

                    if(cnt > 1) {
                        ok = 0;
                        break;
                    }
                }

                if(ok) {
                    cout << s << '\n';
                    ok2 = 1;
                    break;
                }
            }

            if(ok2) {
                ok3 = 1;
                break;
            }
        }

        if(!ok3) cout << "-1\n";
    }

    return 0;
}