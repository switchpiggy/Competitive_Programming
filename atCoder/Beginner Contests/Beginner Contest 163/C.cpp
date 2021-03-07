#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, ans[200007];

int main() {
    cin >> n;
    for(ll i = 2; i <= n; ++i) {
        cin >> a;
        ans[a]++;
    }

    for(ll i = 1; i <= n; ++i) cout << ans[i] << endl;
    return 0;
}