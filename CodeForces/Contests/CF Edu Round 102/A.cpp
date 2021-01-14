#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll t, n, d, a[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> d;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);

        bool ok = 1;
        for(ll i = 0; i < n; ++i) {
            if(a[i] > d && a[0] + a[1] > d) {
                ok = 0;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}