#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    cin >> n;
    while(n--) {

        ll ans = 0;
        cin >> s;
        for(char i = '0'; i <= '9'; ++i) {
            for(char j = '0'; j <= '9'; ++j) {
                char cur = i;
                ll cnt = 0;

                for(ll k = 0; k < s.length(); ++k) {
                    if(s[k] == cur) {
                        cnt++;
                        if(cur == i) cur = j;
                        else cur = i;
                    }
                }

                if(cnt%2 == 1 && i != j) cnt--;

                ans = max(ans, cnt);
            }
        }

        cout << s.length() - ans << endl;
    }

    return 0;
}