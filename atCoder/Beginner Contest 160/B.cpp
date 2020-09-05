#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x;

    ll ans = 0;
    ans += (x/500) * 1000;
    x %= 500;
    ans += (x/5) * 5;

    cout << ans << endl;
    return 0;
}