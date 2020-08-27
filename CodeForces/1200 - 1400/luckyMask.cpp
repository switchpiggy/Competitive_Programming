#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a;
string b;

string mask(ll x) {
    string s;
    stringstream str;
    str << x;
    str >> s;

    string res = "";

    for(ll i = 0; i < s.length(); ++i) {
        if(s[i] == '4' || s[i] == '7') res += s[i];
    }

    return res;
}

int main() {
    cin >> a >> b;
    ll x = a + 1;
    while(mask(x) != b) x++;
    printf("%lld\n", x);
    return 0;
}