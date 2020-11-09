#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> s;
    bool ok = 1;

    string t(s);
    for(ll i = 0; i < n - k; ++i) {
        if(t[i] != t[i + k]) {
            t[i + k] = t[i];
        }
    }

    if(t >= s) {
        cout << n << '\n' << t << '\n';
        return 0;
    }

    cout << n << '\n';

    string u = t.substr(0, k);
    for(ll i = k - 1; i >= 0; --i) {
        if(u[i] == '9') continue;
        for(ll j = i + 1; j < k; ++j) u[j] = '0';
        u[i]++;
        break;
    }

    string ans;
    for(ll i = 0; i < n/k; ++i) ans.append(u);
    ans.append(u.substr(0, n%k));
    
    cout << ans << '\n';
    return 0;
}