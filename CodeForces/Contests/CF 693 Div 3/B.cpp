#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll t, n, a[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll c = 0, b = 0, sum = 0;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i] == 2) b++;
            else c++;
            sum += a[i];
        }

        if(b%2 == 1 && c%2 == 0 && c >= 2) cout << "YES\n";
        else if(b%2 == 0 && c%2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}