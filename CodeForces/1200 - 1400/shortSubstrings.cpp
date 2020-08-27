#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t;
string a;

int main() {
    scanf("%lld", &t);

    while(t--) {
        cin >> a;
        string ans = "";
        ans += a[0];

        for(ll i = 1; i < a.length() - 1; ++i) {
            if(i%2 == 1) ans += a[i];
        }

        ans += a[a.length() - 1];

        cout << ans << endl;
    }
}