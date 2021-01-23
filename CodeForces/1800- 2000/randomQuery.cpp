#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
ll n, a[1000007], last[1000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    memset(last, -1, sizeof(last));
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    long double ans = 0;

    for(ll i = 0; i < n; ++i) {
        if(last[a[i]] == -1) {
            ans += 2 * (n - i - 1) * i + 2 * (n - i - 1) + 2 * (i) + 1;
        } else ans += 2 * (n - i - 1) * (i - last[a[i]] - 1) + 2 * (i - last[a[i]] - 1) + 2 * (n - i - 1) + 1; 

        last[a[i]] = i;
    }

    long double ln = n;
    //cout << ans << '\n';
    cout << ans/(ln * ln) << '\n';
    return 0;
}