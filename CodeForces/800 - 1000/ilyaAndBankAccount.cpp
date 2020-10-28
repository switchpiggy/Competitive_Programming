#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if(n >= 0) {
        cout << n << '\n';
        return 0;
    }

    ll ans;
    string t = to_string(abs(n));
    ans = stoll(t.substr(0, (ll)t.length() - 1));

    string v = t.substr(0, (ll)t.length() - 2) + t.substr((ll)t.length() - 1);
    ans = min(ans, stoll(v));

    cout << -1 * ans << '\n';
    return 0;
}