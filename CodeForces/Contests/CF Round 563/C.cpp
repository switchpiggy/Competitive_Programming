#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, ans[100007];
bool composite[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ll cur = 1;
    
    for(ll i = 2; i <= n; ++i) {
        if(composite[i]) continue;

        ans[i] = cur;

        for(ll j = i * 2; j <= n; j += i) {
            composite[j] = 1;
            ans[j] = cur;
        }

        cur++;
    }

    for(ll i = 2; i <= n; ++i) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}