#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
map<string, string> s;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    string t, u;
    for(ll i = 0; i < m; ++i) {
        cin >> t >> u;
        s[t] = u;
    }

    for(ll i = 0; i < n; ++i) {
        cin >> t;
        if((ll)s[t].length() < (ll)t.length()) cout << s[t] << ' ';
        else cout << t << ' ';
    }

    return 0;
}