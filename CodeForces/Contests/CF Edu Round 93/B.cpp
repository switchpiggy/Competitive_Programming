#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t;
string s;

int main() {
    scanf("%lld", &t);
    while(t--) {
        ll a = 0, b = 0;
        cin >> s;
        ll step = 0;
        while(!s.empty()) {
            ll maxn = 0;
            pair<ll, ll> ms;
            bool ok = 0;
            for(ll i = 0; i < s.length(); ++i) {
                if(s[i] == '0') continue;
                ll j = i;
                while(s[j + 1] == s[i]) j++;

                if(j - i + 1 > maxn) {
                    maxn = j - i + 1;
                    ms.first = i;
                    ms.second = j;
                    ok = 1;
                }
            }

            for(ll k = ms.first; k <= ms.second; ++k) s[k] = '0';
            if(step%2 == 0) a += maxn;
            if(!ok) break;
            step++;
        }

        printf("%lld\n", a);
            
    }
}