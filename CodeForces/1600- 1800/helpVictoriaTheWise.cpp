#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
map<string, ll> m;
string x;

void check (string s){
	if (m[s]) return; 
	m[s]++;
 
	string s1 = {s[1], s[2], s[3], s[0], s[4], s[5]};
	check(s1);
	
	string s2 = {s[0], s[5], s[2], s[4], s[1], s[3]};
	check(s2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string x;
    int ans = 0;
    cin >> x;
    sort(x.begin(), x.end());
 
    do
    {
        if(m[x]==0) ans++;
        check(x);
    } while(next_permutation(x.begin(), x.end()));
    
    cout << ans << '\n';
    return 0;
}