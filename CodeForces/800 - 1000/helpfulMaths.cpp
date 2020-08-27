#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
vector<ll> ans;

int main() {
    cin >> s;
    for(ll i = 0; i < s.length(); ++i) {
        if(i%2 == 0) ans.push_back(s[i] - '0');
    }

    sort(ans.begin(), ans.end());

    for(ll i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if(i + 1 < ans.size()) cout << '+';
    }
    return 0;
}