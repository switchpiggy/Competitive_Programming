#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007], pre[200007], suf[200007];
ll p = -1;
string ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    ll l = 0, r = n - 1;

    if(n == 1) {
        cout << "1\nL\n";
        return 0;
    }

    for(ll i = n - 1; i >= 0; --i) {
        if(i < n - 1 && a[i] < a[i + 1]) pre[i] = pre[i + 1] + 1;
        else pre[i] = 1;
    } 

    for(ll i = 0; i < n; ++i) {
        if(i && a[i] < a[i - 1]) suf[i] = suf[i - 1] + 1;
        else suf[i] = 1;
    }

    while(l <= r) {
        if(a[r] <= p && a[l] <= p) break;
        if(a[r] <= p) {
            ans += 'L';
            p = a[l];
            l++;
        } else if(a[l] <= p) {
            ans += 'R';
            p = a[r];
            r--;
        } else if(a[r] < a[l]) {
            ans += 'R';
            p = a[r];
            r--;
        } else if(a[l] < a[r]) {
            ans += 'L';
            p = a[l];
            l++;
        } else {
            if(min(pre[l], r - l + 1) >= min(suf[r], r - l + 1)) {
                ans.append(string(min(pre[l], r - l + 1), 'L'));
            } else ans.append(string(min(suf[r], r - l + 1), 'R'));
            break;
        }
    }

    cout << (ll)ans.length() << '\n' << ans << '\n';
    return 0;
}