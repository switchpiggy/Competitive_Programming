#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    scanf("%lld", &n);
    string res = "";
    ll z = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> s;
        bool ok = 1;
        if(s[0] > '1' || s[0] == '0') ok = 0;
        if(s.size() == 1 && s[0] == '0') {
            printf("0\n");
            return 0;
        }

        for(ll j = 1; j < s.length(); ++j) if(s[j] != '0') ok = 0;

        if(!ok) res = s;
        else z += s.size() - 1;
    }

    if(res.empty()) res = "1";

    cout << res;
    for(ll i = 0; i < z; ++i) cout << '0';
    return 0;
}