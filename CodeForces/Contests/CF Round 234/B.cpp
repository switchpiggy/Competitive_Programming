#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
vector<string> v;
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    bool ok = 1;
    for(ll i = 0; i < n; ++i) {
        if(v[i][m - 1] == 'G') {
            ok = 0;
            break;
        }
    }

    if(!ok) {
        cout << "-1\n";
        return 0;
    }
    for(ll i = 0; i < n; ++i) {
        ll pos1, pos2;
        for(ll j = 0; j < m; ++j) {
            if(v[i][j] == 'G') pos1 = j;
            else if(v[i][j] == 'S') pos2 = j;
        }

        if(pos1 < pos2) occ[pos2 - pos1]++;
        else {
            cout << "-1\n";
            return 0;
        }
    }

    cout << (ll)occ.size() << '\n';
}