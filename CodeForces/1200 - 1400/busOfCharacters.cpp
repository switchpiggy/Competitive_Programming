#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, w[200007];
string s;
map<ll, ll> m;
priority_queue<ll, vector<ll>, greater<ll>> mins;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &w[i]);
        m[w[i]] = i + 1;
        mins.push(w[i]);
    }

    cin >> s;

    priority_queue<ll> maxs;

    for(ll i = 0; i < s.length(); ++i) {
        if(s[i] == '0') {
            ll g = mins.top();
            mins.pop();
            maxs.push(g);
            printf("%lld ", m[g]);
        } else {
            ll g = maxs.top();
            maxs.pop();
            printf("%lld ", m[g]);
        }
    }

    return 0;
}