#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
vector<string> v;
string ans[57];

int main() {
    cin >> n >> k;

    for(ll i = 0; i < n - k + 1; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    char c = 'a';
    string cur = "a";

    for(ll i = 0; i < n - k + 1; ++i) {
        if(ans[i].empty()) ans[i] = cur;
        if(v[i] == "NO") {
            ans[i + k - 1] = ans[i];
        }

        cur += c;
        if(cur.length() > 10) {
            c++;
            cur = string(1, c);
        }
    }

    for(ll i = 0; i < n; ++i) {
        if(!ans[i].empty()) {
            ans[i][0] = toupper(ans[i][0]);
            cout << ans[i] << ' ';
        } else {
            string s = cur;
            s[0] = toupper(s[0]);
            cout << s << ' ';
            cur += c;
            if(cur.length() > 10) {
                c++;
                cur = string(1, c);
            }
        }
    }

    return 0;
}