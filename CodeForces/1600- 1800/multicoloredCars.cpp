#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, c[100007], cnt[1000007];
bool ok[1000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a;
    for(ll i = 1; i <= 1000000; ++i) ok[i] = 1;
    for(ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if(x == a) cnt[a]++;
        else {
            if(cnt[x] < cnt[a]) ok[x] = 0;
            else if(ok[x]) cnt[x]++;
        }
    }

    for(ll i = 1; i <= 1000000; ++i) {
        if(i == a) continue;
        if(ok[i] && cnt[i] >= cnt[a]) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}