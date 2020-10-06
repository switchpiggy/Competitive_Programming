#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
string t;

const ll maxn = 4294967295;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    stack<ll> s;
    ll curfor = 1, ans = 0;

    for(ll i = 0; i < n; ++i) {
        if(ans > maxn) {
            cout << "OVERFLOW!!!\n";
            return 0;
        }

        cin >> t;
        if(t == "end") {
            curfor /= s.top();
            s.pop();
        } else if(t == "add") {
            ans += curfor;
        } else {
            cin >> k;
            s.push(k);
            curfor *= k;
        }
    }



    cout << ans << '\n';
    return 0;
}