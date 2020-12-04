#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, r[10], fst[2007][10], lst[2007][10], ans[10], lr[10], lc[10], c[10], f[2007][10], l[2007][10];
vector<string> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        memset(fst, 0, sizeof(fst));
        memset(lst, 0, sizeof(lst));
        memset(r, 0, sizeof(r));
        memset(ans, 0, sizeof(ans));
        memset(lc, 0, sizeof(lc));
        memset(lr, 0, sizeof(lr));
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        memset(l, 0, sizeof(l));

        cin >> n;
        v.clear();
        for(ll i = 0; i < n; ++i) {
            string s; 
            cin >> s;
            v.push_back(s);
        }

        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < n; ++j) {
                if(!r[v[i][j] - '0']) r[v[i][j] - '0'] = i + 1;
                lr[v[i][j] - '0'] = i + 1;
                if(!fst[i][v[i][j] - '0']) fst[i][v[i][j] - '0'] = j + 1;
                lst[i][v[i][j] - '0'] = j + 1;
                l[j][v[i][j] - '0'] = max(l[j][v[i][j] - '0'], i + 1);
                if(!f[j][v[i][j] - '0']) f[j][v[i][j] - '0'] = i + 1;
                else f[j][v[i][j] - '0'] = min(f[j][v[i][j] - '0'], i + 1);
                if(!c[v[i][j] - '0']) c[v[i][j] - '0'] = j + 1;
                else c[v[i][j] - '0'] = min(c[v[i][j] - '0'], j + 1);
                lc[v[i][j] - '0'] = max(lc[v[i][j] - '0'], j + 1);
            }
        }

        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < n; ++j) {
                for(ll k = 0; k <= 9; ++k) {
                    if(fst[i][k]) {
                        if(r[k]) ans[k] = max(ans[k], abs((i + 1) - r[k]) * abs(fst[i][k] - (j + 1)));
                        if(lr[k]) ans[k] = max(ans[k], abs((i + 1) - lr[k]) * abs(fst[i][k] - (j + 1)));
                    }
                    if(lst[i][k]) {
                        if(r[k]) ans[k] = max(ans[k], abs((i + 1) - r[k]) * abs(lst[i][k] - (j + 1)));
                        if(lr[k]) ans[k] = max(ans[k], abs((i + 1) - lr[k]) * abs(lst[i][k] - (j + 1)));
                    }
                }
            }
        }

        for(ll j = 0; j < n; ++j) {
            for(ll i = 0; i < n; ++i) {
                for(ll k = 0; k <= 9; ++k) {
                    if(f[j][k]) {
                        if(c[k]) ans[k] = max(ans[k], abs((j + 1) - c[k]) * abs((i + 1) - f[j][k]));
                        if(lc[k]) ans[k] = max(ans[k], abs((j + 1) - lc[k]) * abs(f[j][k] - (i + 1)));
                    }
                    if(l[j][k]) {
                        if(c[k]) ans[k] = max(ans[k], abs((j + 1) - c[k]) * abs((i + 1) - l[j][k]));
                        if(lc[k]) ans[k] = max(ans[k], abs((j + 1) - lc[k]) * abs((i + 1) - l[j][k]));
                    }
                }
            }
        }

        for(ll i = 0; i <= 9; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}