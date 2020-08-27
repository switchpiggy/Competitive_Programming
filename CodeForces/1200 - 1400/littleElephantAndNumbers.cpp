#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x;
string s;
set<char> ch;

bool check(ll num) {
    string st = to_string(num);
    for(ll i = 0; i < st.length(); ++i) {
        if(ch.find(st[i]) != ch.end()) return true;
    }

    return false;
}

int main() {
    scanf("%lld", &x);
    s = to_string(x);

    for(ll i = 0; i < s.length(); ++i) ch.insert(s[i]);

    ll cnt = 0;

    for(ll i = 1; i <= sqrt(x); ++i) {
        if(x%i == 0 && check(i)) {
            cnt++;
            
        }
        if(x%i == 0 && i != x/i && check(x/i)) cnt++;
    }

    printf("%lld\n", cnt);

    return 0;
}