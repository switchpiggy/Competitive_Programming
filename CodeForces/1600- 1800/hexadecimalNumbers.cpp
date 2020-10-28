#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
ll ans = 0;

void solve(string s) {
    if(stoll(s) > n) return;
    ans++;
    solve(s + "0");
    solve(s + "1");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    solve("1");

    cout << ans << '\n';
    return 0;
}