#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[500007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    bool pos = 0, neg = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] > 0) pos = 1;
        if(a[i] < 0) neg = 1;
    }

    if(n == 1) {
        cout << a[0] << '\n';
        return 0;
    }

    ll sum = 0, mins = INT_MAX;
    for(ll i = 0; i < n; ++i) {
        mins = min(mins, abs(a[i]));
        sum += abs(a[i]);
    }

    if(!neg || !pos) cout << sum - 2 * mins << '\n';
    else cout << sum << '\n';
    return 0;                                                                                                                                                                                                                                                                                                                                                                                   
}