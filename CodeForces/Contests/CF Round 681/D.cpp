#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[30007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];

        ll i = 1;
        while(i + 1 < n - 1 && a[i] <= a[i + 1]) i++;

        while(i + 1 < n - 1 && a[i] >= a[i + 1]) i++;
        
        if(i == n - 2 && (i <= 2 || (a[0] >= a[1] && a[n - 1] >= a[n - 2]))) {
            cout << "YES\n";
            continue;
        }

        i = 0;
        while(i + 1 < n && a[i] >= a[i + 1]) i++;
        while(i + 1 < n && a[i] <= a[i + 1]) i++;
        
        if(i == n - 1) {
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }

    return 0;
}