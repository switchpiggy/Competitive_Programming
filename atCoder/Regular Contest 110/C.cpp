#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p[200007], d[200007];
bool used[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }

    for(ll i = 0; i < n; ++i) d[i] = p[i];
    queue<ll> q;
    vector<ll> v;
    q.push(0);
    v.push_back(0);

    while(!q.empty()) {
        ll t = q.front();
        q.pop();
        if(used[t]) break;
        used[t] = 1;
        q.push(d[t]);
        v.push_back(d[t]);
    }

    for(ll i = 0; i < n; ++i) if(!used[i]) {
        cout << "-1\n";
        return 0;
    }

    ll prev = 0;

    for(ll i = 0; i < n; ++i) {
        if(d[i] >= i) continue;
        for(ll j = i - 1; j >= prev; --j) cout << j + 1 << '\n';
        prev = i; 
    }

    return 0;
}