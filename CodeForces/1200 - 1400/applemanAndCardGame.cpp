#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
map<char, ll> occ;
vector<ll> ans;
string s;

int main() {
    scanf("%lld %lld", &n, &k);
    cin >> s;

    for(ll i = 0; i < s.length(); ++i) occ[s[i]]++;

    for(auto itr = occ.begin(); itr != occ.end(); ++itr) {
    	//cout << itr->second << endl;
        ans.push_back(itr->second);
    }
    
    sort(ans.begin(), ans.end(), greater<int>());

    ll res = 0;

    for(ll i = 0; i < ans.size(); ++i) {
    	//cout << ans[i] << endl;
        if(ans[i] >= k) {
            res += k * k;
            break;
        } else {
            res += ans[i] * ans[i];
            k -= ans[i];
        }
    }

    printf("%lld\n", res);


    return 0;
}