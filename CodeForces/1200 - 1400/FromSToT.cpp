#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q;
string s, t, p;

int main() {
    scanf("%lld", &q);
    while(q-- ) {
        map<char, ll> occ;
        cin >> s >> t >> p;

        for(ll i = 0; i < p.length(); ++i) occ[p[i]]++;

        bool flag = false;
        ll is = 0, it = 0;

        while(is < s.length()) {
            if(it == t.length()) {
                flag = 1;
                break;
            }

            if(s[is] == t[it]) {
                is++;
                it++;
                continue;
            }

            --occ[t[it]];
            ++it;
        }
        while(it< t.length()) {
            --occ[t[it]];
            ++it;
        }

        for(auto itr = occ.begin(); itr != occ.end(); ++itr) {
            if(itr->second < 0) flag = 1;
        }

        if(flag) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}