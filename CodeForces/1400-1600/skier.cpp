#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t;
string s;
set<pair<pair<ll, ll>, pair<ll, ll>>> st;

int main() {
    scanf("%lld", &t);
    while(t--) {
        cin >> s;
        st.clear();
        ll cnt = 0, x = 0, y = 0;

        for(ll i = 0; i < s.length(); ++i) {
            ll dx = 0, dy = 0;
            if(s[i] == 'N') dy++;
            else if(s[i] == 'S') dy--;
            else if(s[i] == 'E') dx++;
            else dx--;

            if(st.find(make_pair(make_pair(x, y), make_pair(x + dx, y + dy))) != st.end()) cnt++;
            else {
                cnt += 5;
                st.insert(make_pair(make_pair(x, y), make_pair(x + dx, y + dy)));
                st.insert(make_pair(make_pair(x + dx, y + dy), make_pair(x, y)));
            }

            x += dx;
            y += dy;
        }

        printf("%lld\n", cnt);
    }

    return 0;
}