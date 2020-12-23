#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, l[100007], suf[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        cin >> l[i];
        if(i + l[i] > n) {
            cout << "-1\n";
            return 0;
        }
    }
    
    for(ll i = m - 1; i >= 0; --i) suf[i] = suf[i + 1] + l[i];
    if(suf[0] < n) {
        cout << "-1\n";
        return 0;
    }

    for(ll i = 0; i < m; ++i) {
        cout << max(i + 1, n - suf[i] + 1) << ' ';
    }

    return 0;
}