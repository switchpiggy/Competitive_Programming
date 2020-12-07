#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
map<char, bool> occ;
string s;
char c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> s;
    for(ll i = 0; i < k; ++i) {
        cin >> c;
        occ[c] = 1;
    }

    ll cur = 0, ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(occ[s[i]]) cur++;
        else {
            ans += (cur * (cur + 1))/2;
            cur = 0;
        }
    }

    if(cur) ans += (cur * (cur + 1))/2;

    cout << ans << '\n';
    return 0;
}