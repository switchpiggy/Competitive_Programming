#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
char type;
map<string, ll> occ;

string getPattern(ll n) {
    string res;

    while(n) {
        if((n%10)%2 == 0) res += '0';
        else res += '1';
        n /= 10;
    }

    reverse(res.begin(), res.end());

    while(res[0] == '0' && res.length() > 1) {
        res.erase(0, 1);
    }
	
    return res;
}

int main() {
    scanf("%lld", &t);
    while(t--) {
        cin >> type >> n;
        //cout << getPattern(n) << endl;
        if(type == '+') occ[getPattern(n)]++;
        else if(type == '-') occ[getPattern(n)]--;
        else {
            string st = to_string(n);
            while(st[0] == ' ' && st.length() > 1) {
            	st.erase(0, 1);
            }
            printf("%lld\n", occ[st]);
        }
    }

    return 0;
}