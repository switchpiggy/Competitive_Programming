#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m0(x) memset(x, 0, sizeof(x))
#define m1(x) memset(x, 1, sizeof(x))
#define mn1(x) memset(x, -1, sizeof(x))
#define flout cout << fixed << setprecision(12)
ll n, t, s;
stack<ll> st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll curspeed = -1, curlimit = -1, osigns = 0;
    //bool o = 1;
    ll ans = 0;
    while(n--) {
        cin >> t;
        if(t == 1) {
            cin >> s;
            while(!st.empty() && curspeed > st.top()) {
                ans++;
                st.pop();
            }
            curspeed = s;
            while(!st.empty() && curspeed > st.top()) {
                ans++;
                st.pop();
            }
        } else if(t == 3) {
            cin >> s;
            while(!st.empty() && curspeed > st.top()) {
                ans++;
                st.pop();
            }
            st.push(s);
            while(!st.empty() && curspeed > st.top()) {
                ans++;
                st.pop();
            }
        } else if(t == 2) {
            ans += osigns;
            osigns = 0;
        } else if(t == 4) {
            osigns = 0;
        } else if(t == 5) {
            st.push(301);
        } else {
            osigns++;
        }
    }

    cout << ans << '\n';
    return 0;
}