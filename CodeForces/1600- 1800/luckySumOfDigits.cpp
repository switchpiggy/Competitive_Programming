#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string s = "";

    for(ll i = 0; i <= n/7; ++i) {
        if((n - (7 * i))%4 == 0) {
            ll k = (n - (7 * i))/4;
            string t = string(k, '4') + string(i, '7');
            s = t;
        }
    }

    if(s.empty()) s = "-1"; 
    cout << s << '\n';
    return 0;
}