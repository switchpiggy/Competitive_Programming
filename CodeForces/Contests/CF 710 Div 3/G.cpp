#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m1(x) memset(x, 1, sizeof(x))
#define m0(x) memset(x, 0, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll t, last[200007];
bool used[200007];
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        m0(used);
        m0(last);
        cin >> s;   
        vector<char> ans;

        for(ll i = 0; i < sz(s); ++i) last[s[i] - 'a'] = i;

        for(ll i = 0; i < sz(s); ++i) {
            if(used[s[i] - 'a']) continue;
            while(sz(ans) && ans.back() < s[i] && last[ans.back() - 'a'] >= i) used[ans.back() - 'a'] = 0, ans.pop_back();
            ans.push_back(s[i]);
            used[s[i] - 'a'] = 1;
        }

        for(char i : ans) cout << i;
        cout << '\n';
    }

    return 0;
}