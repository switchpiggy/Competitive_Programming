#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);

    ll l = 0, r = n - 1, prev = 0;
    string ans = "";

    while(l <= r) {
        vector<pair<ll, char>> v;
        if(prev < a[l]) v.push_back(make_pair(a[l], 'L'));
        if(prev < a[r]) v.push_back(make_pair(a[r], 'R'));

        sort(v.begin(), v.end());

        if(v.size() == 2) v.pop_back();
        if(v.size() == 1) {
            if(v[0].second == 'L') {
                prev = a[l];
                ans += 'L';
                ++l;
            } else {
                prev = a[r];
                ans += 'R';
                --r;
            }
        } else break;
    }

    cout << ans.length() << endl;
    cout << ans << endl;

    return 0;
}