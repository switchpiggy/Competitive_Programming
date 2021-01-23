#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
ll n, a[100007], odd[100007], even[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        if(i%2 == 0) even[a[i]]++;
        else odd[a[i]]++;
    }

    ll maxeven = 0, maxodd = 0;
    for(ll i = 1; i <= 100000; ++i) {
        if(even[i] > even[maxeven]) {
            maxeven = i;
        }

        if(odd[i] > odd[maxodd]) maxodd = i;
    }

    sort(even, even + 100001, greater<ll>());
    sort(odd, odd + 100001, greater<ll>());

    if(maxeven == maxodd) {
        cout << n - max(even[0] + odd[1], odd[0] + even[1]) << '\n';
        return 0;
    }

    cout << n - (even[0] + odd[0]) << '\n';
    return 0;
}