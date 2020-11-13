#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        string ans;
        for(ll i = 0; i < k; ++i) {
            ans += (i + 'a');
        }

        string s;
        for(ll i = 0; i < n/k; ++i) {
            s.append(ans);
        }

        for(ll i = 0; i < n%k; ++i) s += 'a';

        cout << s << '\n';
    }

    return 0;
}