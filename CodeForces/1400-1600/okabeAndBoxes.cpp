#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
string s;
stack<ll> a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ll cur = 1, ans = 0;
    for(ll i = 0; i < 2 * n; ++i) {
        cin >> s;
        if(s == "add") {
            cin >> k;
            a.push(k);
        } else {
            if(a.empty()) {
                cur++;
                continue;
            }
            
            if(cur == a.top()) {
                a.pop();
            } else {
                ans++;
                while(!a.empty()) a.pop();
            }

            cur++;
        }
    }

    cout << ans << '\n';
    return 0;
}