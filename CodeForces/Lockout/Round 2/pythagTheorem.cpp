#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, ans;
 
int main(){
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = i; j <= n; ++j) {
            ll k = sqrt(i * i + j * j);
            if(k <= n && k * k == i * i + j * j) ans++;
        }
    }

    cout << ans << '\n';
}