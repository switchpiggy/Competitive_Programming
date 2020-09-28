#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    ll cur = 0;
    for(ll i = 0; i < (ll)b.length(); ++i) {
        if(a[i] != b[i]) cur++;
    }

    ll ans = (cur%2 == 0);
    for(ll i = 1; i < (ll)a.length() - (ll)b.length() + 1; ++i) {
        if(a[i - 1] != b[i - 1]) cur--;
        if(a[i + (ll)b.length() - 1] != b[i + (ll)b.length() - 1]) cur++;

        if(cur%2 == 0) ans++;
    }

    cout << ans << '\n';
    return 0;
}