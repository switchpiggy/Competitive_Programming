#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, ans[200007];
string s;

int main() {
    cin >> n >> s;

    ll maxD = 0, cur = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == '(') cur++;
        maxD = max(cur, maxD);
        if(s[i] == ')') cur--;
    }

    maxD /= 2, cur = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == '(') cur++;
        if(cur > maxD) {
            ans[i] = 1;
        }
        if(s[i] == ')') cur--;
    }

    for(ll i = 0; i < (ll)s.length(); ++i) cout << ans[i];
    cout << '\n';
    return 0;
}