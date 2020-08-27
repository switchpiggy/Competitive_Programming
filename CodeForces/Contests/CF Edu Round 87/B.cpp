#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    scanf("%lld", &n);
    while(n--) {
        cin >> s;
        ll ans = INT_MAX;
        for(ll i = 1; i < s.size() - 1; ) {
            ll j = i;
            while(s[j + 1] == s[i] && j < s.size() - 2) j++;
            //cout << i << ' ' << j << endl;
            if(s[i] != s[i - 1] && s[j] != s[j + 1] && s[i - 1] != s[j + 1]) ans = min(ans, j - i + 3);
            i = j + 1;
        }

        if(ans == INT_MAX) ans = 0;
        printf("%lld\n", ans);
    }

    return 0;
}