#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<ll> ans;
ll n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    ll cur = 0;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == 'W') {
            if(cur) ans.push_back(cur);
            cur = 0;
        } else cur++;
    }

    if(cur) ans.push_back(cur);

    cout << (ll)ans.size() << '\n';
    for(ll i : ans) cout << i << ' ';
    cout << '\n';
    return 0;
}