#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll m;
vector<ll> v;

void dfs(ll b, ll step, ll last) {
    if(step == m) {
        cout << "YES\n";
        for(auto i : v) cout << i << ' ';
        cout << '\n';
        exit(0);
    }

    for(ll i = 0; i < 10; ++i) {
        if(i == last || s[i] == '0' || (b > 0 && b >= i + 1) || (b < 0 && b <= -1 * (i + 1))) continue;
        v.push_back(i + 1);
        if(b > 0) dfs(b - i - 1, step + 1, i);
        else dfs(b + i + 1, step + 1, i);

        v.pop_back();
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> m;

    dfs(0, 0, -1);

    cout << "NO\n";
    return 0;
}