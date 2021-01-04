#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue

ll n, k;
string s;
set<string> st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> s;
    benqueue<string> ben;
    ben.push(s);
    st.insert(s);

    ll ans = 0;
    while(!ben.empty() && (ll)st.size() < k) {
        string t = ben.front();
        ben.pop();

        if(t.empty()) continue;

        for(ll i = 0; i < (ll)t.length(); ++i) {
            string v = t;
            v.erase(i, 1);
            if(!st.count(v) && (ll)st.size() < k) {
                st.insert(v);
                ben.push(v);
                ans += n - (ll)v.length();
            }
        }
    }

    if((ll)st.size() < k) ans = -1;
    cout << ans << '\n';
}