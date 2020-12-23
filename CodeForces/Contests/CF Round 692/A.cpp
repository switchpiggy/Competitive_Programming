#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> s;
        ll cnt = 0;
        for(ll i = n - 1; i >= 0; --i) {
            if(s[i] == ')') cnt++;
            else break;
        }

        if(cnt > n - cnt) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}