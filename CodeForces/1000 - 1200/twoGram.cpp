#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;
map<string, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(ll i = 0; i < n - 1; ++i) {
        occ[s.substr(i, 2)]++;
    }

    string ans;
    for(auto i = occ.begin(); i != occ.end(); ++i) if(i->second > occ[ans]) ans = i->first;

    cout << ans << '\n';
    return 0;
}