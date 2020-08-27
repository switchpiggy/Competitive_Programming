#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, val, n;
string s;
priority_queue<ll, vector<ll>, greater<ll>> q;
priority_queue<ll, vector<ll>, greater<ll>> p;

int main() {
    cin >> a >> b >> c;
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> val >> s;
        if(s == "PS/2") {
            q.push(val);
        } else p.push(val);
    }

    ll ans = 0, sum = 0;
    while(a && !p.empty()) {
        ll t = p.top();
        p.pop();
        sum += t;
        ans++;
        a--;
    }

    while(b && !q.empty()) {
        ll t = q.top();
        q.pop();
        sum += t;
        ans++;
        b--;
    }

    while(c && (!q.empty() || !p.empty())) {
        ll t = INT_MAX;
        if(!q.empty()) {
            t = min(t, q.top());
        }

        if(!p.empty()) {
            t = min(t, p.top());
        }

        if(!q.empty() && t == q.top()) {
            q.pop();
            sum += t;
            ans++;
        } else if(!p.empty() && t == p.top()) {
            p.pop();
            sum += t;
            ans++;
        }
        c--;
    }

    cout << ans << ' ' << sum << endl;
    return 0;
}