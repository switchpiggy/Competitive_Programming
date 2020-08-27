#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], mins = INT_MAX;

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    for(ll i = n - 1; i >= 0; --i) {
        if(a[i] > mins) {
            cout << i + 1 << endl;
            return 0;
        }
        mins = min(mins, a[i]);
    }

    cout << 0 << endl;
    return 0;
}