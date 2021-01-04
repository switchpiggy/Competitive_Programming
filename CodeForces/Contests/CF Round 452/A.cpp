#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll n, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll x = 0, y = 0;
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] == 1) x++;
        else y++;
    }

    cout << min(x, y) + max(0ll, x - y)/3 << '\n';
    return 0;
}