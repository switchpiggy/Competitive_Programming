#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> s;
        queue<ll> q;

        ll cur = 0;
        for(ll i = 0; i < n; ++i) {
            if(i && s[i] != s[i - 1]) cur++;
            if(i && s[i] == s[i - 1]) q.push(cur);
        }

        ll ans = 0, cnt = 0;
        for(ll i = 0; i < n; ++i) {
            if(q.empty()) break;

            q.pop();
            ans++;
            cnt++;

            while(!q.empty() && q.front() == i) {
                q.pop();
                cnt++;
            }

            cnt++;
        }

        cout << ans + (n - cnt + 1)/2 << '\n';
    }

    return 0;
}