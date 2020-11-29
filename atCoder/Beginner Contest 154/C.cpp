#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    bool ok = 1;
    sort(a, a + n);
    for(ll i = 0; i < n - 1; ++i) {
       if(a[i] == a[i + 1]) ok = 0; 
    }

    cout << (ok ? "YES\n" : "NO\n");
}