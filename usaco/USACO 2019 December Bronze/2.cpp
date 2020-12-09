#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;
map<string, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    cin >> n >> s;
    for(ll i = 1; i <= n; ++i) {
        bool ok = 1;
        for(ll j = 0; j < n - i + 1; ++j) {
            string cur = s.substr(j, i);
            //s.substr(x, y);
            if(occ[cur]) {
                ok = 0;
                break;
            }

            occ[cur]++;
        }

        if(ok) {
            cout << i << '\n';
            return 0;
        }
    }    
}