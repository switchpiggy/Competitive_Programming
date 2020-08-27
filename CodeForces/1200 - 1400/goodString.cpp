#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    scanf("%lld", &n);
    cin >> s;

    string ans = "";

    for(ll i = 0; i < n; ++i) {
        if(ans.size()%2 == 0 || ans.back() != s[i]) {
            ans.push_back(s[i]);
        }
    }

    if(ans.size()%2 == 1) ans.pop_back();

    cout << s.size() - ans.size() << endl;
    cout << ans << endl;

    return 0;
}