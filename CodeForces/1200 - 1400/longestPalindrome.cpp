#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int MOD     = 1e9+7;
const int INT_INF = 0x3f3f3f3f;
const ll  LL_INF  = 0x3f3f3f3f3f3f3f3f;
const int POS[8]  = {0, 1, 0, -1, 1, 0, 1, -1};
const int MAXM    = 1000005;
const int MAXN    = 100005;
 
vector<string> pl;
set<string> S, SP;
 
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i< n; i++) {
        string s;
        cin>> s;
        int flag = 1;
        for(int j = 0; j < s.length() / 2; j++)
            if(s[j] != s[s.length() - j - 1]) flag = 0;
 
        if(flag) pl.push_back(s);
        else S.insert(s);
    }
    string ans = "";
    for(auto s: S){
        if(SP.find(s) != SP.end()) continue;
        string t = "";
        for(int j = s.length() - 1; j >= 0; j--) t += s[j];
        if(S.find(t) != S.end()) {
            ans += s;
            SP.insert(t);
        }
    }
    int len = ans.length() * 2;
    if(pl.size() > 0) len += m;
    cout << len << endl;
    cout << ans;
    if(pl.size() > 0 ) cout << pl[0];
    string t = "";
    for(int j = ans.length() - 1; j >= 0; j--) t += ans[j];
    cout << t << endl;
 
 
 
    return 0;
}
 