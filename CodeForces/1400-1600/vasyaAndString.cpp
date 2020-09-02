#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
string s;

//vector<ll> a;
//vector<ll> b;

int main() {
    cin >> n >> k >> s;
    ll ans = 0;

    ll l = 0, r = 0, cura = 0, curb = 0;

    while(r < n) {
        if(s[r] == 'a') cura++;
        else curb++;

        if(min(cura, curb) <= k) ans = max(ans, cura + curb);
        else {
            if(s[l] == 'a') cura--;
            else curb--;

            l++;
        }

        r++;
    }
    cout << ans << endl;
    return 0;
}