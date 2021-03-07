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
ll n, m, a, b, cur, cur1;
char c;
map<pair<ll, ll>, char> cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while(m--) {
        cin >> c;
        if(c == '+') {
            cin >> a >> b >> c;
            if(cnt.find({b, a}) != cnt.end()) cur1++;
            cnt[{a, b}] = c;
            if(cnt.find({b, a}) != cnt.end() && cnt[{a, b}] == cnt[{b, a}]) cur++;
        } else if(c == '-') {
            cin >> a >> b;
            if(cnt.find({b, a}) != cnt.end()) cur1--;
            if(cnt.find({b, a}) != cnt.end() && cnt[{a, b}] == cnt[{b, a}]) cur--;
            cnt.erase({a, b});
        } else {
            cin >> a;
            cout << (cur1 && (cur || a%2) ? "YES\n" : "NO\n");
        }
    }

    return 0;
}