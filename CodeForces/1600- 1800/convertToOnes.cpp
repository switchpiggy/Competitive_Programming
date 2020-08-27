#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <ll ,ll> pll;
typedef pair <int ,int> pii;
typedef pair <double , double> pt;
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define prar(a , n) {for (int iiiiiiiiii = 0; iiiiiiiiii < n; iiiiiiiiii++) cout << a[iiiiiiiiii] << ' '; cout << '\n';}
#define inar(a , n) {for (int iiiiiiiiii = 0; iiiiiiiiii < n; iiiiiiiiii++) cin >> a[iiiiiiiiii];}
#define prvc(a) {for (int iiiiiiiiii = 0; iiiiiiiiii < a.size(); iiiiiiiiii++) cout << a[iiiiiiiiii] << ' '; cout << '\n';}
#define invc(a , n) {for (int iiiiiiiiii = 0; iiiiiiiiii < n; iiiiiiiiii++) a.pb(next());}
#define fi first
#define se second
 
 
ll next() {ll x; cin >> x; return x;}
const ll inf = 4e18 , mod = 1e9 + 7;
const int intf = 2e9 , MaxN = 2e5;
const double PI = 3.141592653589 , eps = 1e-6;
 
 
int main()
{
    #ifdef HERE
        freopen("input.txt" , "r" , stdin);
    #else
        //freopen("keepcounted.in" , "r" , stdin); freopen("keepcounted.out" , "w" , stdout);
        ios_base::sync_with_stdio(false);
    #endif
    cout.precision(20); cin.tie(0); cout.tie(0);
 
    int n = next();
    ll x = next() , y = next();
    vector <ll> dp(n);
    string s; cin >> s;
 
    int i;
    for (i = 0; i < n && s[i] == '1'; i ++);
 
    if (i >= n){
        cout << "0";
        return 0;
    }
 
    dp[i++] = y;
 
    for (; i < n; i ++){
        if (s[i] == '1'){
            dp[i] = dp[i - 1];
            continue;
        }
        if (s[i - 1] == '1'){
            dp[i] = dp[i - 1] + min(x , y);
        } else {
            dp[i] = dp[i - 1];
        }
    }
    cout << dp[n - 1];
 
    return 0;
 
}