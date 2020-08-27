#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, t;
string s;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> s;
        ll ans = 0, cnt = 0;
        while(s.size() && s[0] == s.back()) {
            cnt++;
            s.pop_back();
        }

        if(s.empty()) {
            if(n <= 2) cout << '0' << endl;
            else if(n == 3) cout << '1' << endl;
            else cout << (cnt + 2)/3 << endl;
            continue;
        }

        for(ll i = 0; i < s.size(); ++i) {
            cnt++;
            if(i < s.size() - 1 && s[i] != s[i + 1]) {
                ans += cnt/3;
                cnt = 0;
            }
        }

        ans += cnt/3;

        cout << ans << endl;
    }

    return 0;
}