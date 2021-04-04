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
ll t, n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> s;
        ll x = 0, y = 0;
        for(char i : s) {
            x += (i == '1');
            y += (i == '0');
        }

        if(y%2 || x%2 || s[0] == '0' || s.back() == '0') {
            cout << "NO\n";
            continue;
        }

        vector<char> a, b;
        ll cur = 0, cur2 = 0;
        for(char i : s) {
            if(i == '0') {
                if(cur2%2) a.push_back('.'), b.push_back('.');
                else a.push_back('.'), b.push_back('.'); 
                cur2++;
            } else {
                if(cur < x/2) a.push_back('('), b.push_back('(');
                else a.push_back(')'), b.push_back(')');
                cur++;
            }
        }

        bool ok = 1;
        ll bala = 0, balb = 0;
        for(ll i = 0; i < n; ++i) {
            if(a[i] == '.') {
                if(max(bala, balb) == 0) {
                    ok = 0;
                    break;
                }

                if(bala > balb) a[i] = ')', b[i] = '(', balb++, bala--;
                else a[i] = '(', b[i] = ')', balb--, bala++;
            } else {
                if(a[i] == '(') bala++, balb++;
                else bala--, balb--;
            }
        }

        if(!ok) cout << "NO\n";
        else {
            cout << "YES\n";
            for(char i : a) cout << i;
            cout << '\n';
            for(char i : b) cout << i;
            cout << '\n';
        }
    }

    return 0;
}