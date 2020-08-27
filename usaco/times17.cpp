#include <iostream>
#include <string>
using namespace std;

typedef long long int ll;
string n, s, t;
ll ans[1007];

int main() {
    cin >> n;
    s = "0" + n + "0000";
    t = "00000" + n;

    for(ll i = t.length() - 1; i > 0; --i) {
        ll cur = (s[i] - '0') + (t[i] - '0');
        ans[i] += cur;
        if(ans[i] >= 2) {
            ans[i] -= 2;
            ans[i - 1]++;
        }
    }

    ll i = 0;
    if(ans[0] == 0) i++;
    for(; i < s.length(); ++i) cout << ans[i] << ' ';
    
    return 0;
}