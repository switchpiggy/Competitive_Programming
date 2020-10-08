#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[2007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < 2 * n; ++i) cin >> a[i];
    sort(a, a + 2 * n);
    
    if(a[0] == a[2 * n - 1]) {
        cout << "-1\n";
        return 0;
    }

    for(ll i = 0; i < 2 * n; ++i) cout << a[i] << ' ';
    cout << '\n';
}