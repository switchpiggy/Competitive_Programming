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
string s, temp;
stack<ll> st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    temp = s;

    for(ll i = 0; i < sz(s); ++i) {
        if(s[i] == '0') {
            if(!st.empty()) {
                temp[i] = temp[st.top()] = '.';
                st.pop();
            }
        } else {
            st.push(i);
        }
    }

    for(ll i = 0; i < sz(s); ++i) {
        if(temp[i] == '.') cout << s[i];
        else cout << '0';
    }

    cout << '\n';
    return 0;
}