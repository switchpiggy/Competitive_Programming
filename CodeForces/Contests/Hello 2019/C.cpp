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
ll n, cnt[500007][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    stack<char> st;
    ll res = 0;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        
        ll cur = 0, a = 0, b = 0;
        for(char c : s) {
            if(c == '(') st.push(c);
            else {
                if(st.empty()) a++;
                else {
                    st.pop();
                }
            }
        }

        while(!st.empty()) {
            st.pop();
            b++;
        }
        
        if(!a && !b) res++;
        else if(!b) cnt[a][1]++;
        else if(!a) cnt[b][0]++;
    }

    ll ans = 0;
    for(ll i = 0; i <= 500000; ++i) {
        ans += min(cnt[i][0], cnt[i][1]);
    }

    cout << ans + res/2 << '\n';
    return 0;


}