#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
long double a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long double curSum = 0;
    ll size = 0;
    pair<long double, ll> res = {0, 0};
    for(ll i = 0; i < n; ++i) cin >> a[i];

    for(ll i = 0; i < n; ++i) {
        if(!size || a[i] >= curSum/size) {
            curSum += a[i];
            size++;
        } else {
            if(curSum/(long double)size > res.first || (curSum/(long double)size == res.first && size > res.second)) {
                res.first = curSum/size;
                res.second = size;
            }
            curSum = size = 0;
        }
    }

    if(size) {
        if(curSum/(long double)size > res.first || (curSum/(long double)size == res.first && size > res.second)) {
            res.first = curSum/size;
            res.second = size;
        }
    }

    cout << res.second << '\n';
    return 0;
}