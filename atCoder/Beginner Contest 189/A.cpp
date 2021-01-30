#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define flout cout << fixed << setprecision(12)
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    if(s[0] == s[1] && s[1] == s[2]) cout << "Won\n";
    else cout << "Lost\n";
}