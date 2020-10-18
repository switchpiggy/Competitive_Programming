#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], b[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n; ++i) cin >> b[i];

    ll i = 0, j = 0;
    while(i < n || j < n) {
        if(i >= n) {
            cout << b[j] << ' ';
            j++;
            continue;
        }

        if(j >= n) {
            cout << a[i] << ' ';
            i++;
            continue;
        }

        if(a[i] <= b[j]) {
            cout << a[i] << ' ';
            i++;
        } else {
            cout << b[j] << ' ';
            j++;
        }
    }

    return 0;
}