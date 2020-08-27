#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main() {
	ll t;
	string s;
	vector<ll> v;
	
    scanf("%lld", &t);
    for(int tc = 1; tc <= t; ++tc) {

        v.clear();
        v.push_back(0);
        cin >> s;

        for(int i = 0; i < s.length(); ++i) {
            v.push_back(s[i] - '0');
        }
        v.push_back(0);
		printf("Case #%lld: ", tc);
		
        for(ll i = 1; i < v.size(); ++i) {
        	//printf("%lld", v[i]);
            ll diff = v[i] - v[i - 1];
            if(diff > 0) {
                for(int j = 0; j < diff; ++j) printf("(");
                if(i != v.size() - 1) printf("%lld", v[i]);
            } else if(diff < 0) {
                for(int j = 0; j < diff * (-1); ++j) printf(")");
                if(i != v.size() - 1) printf("%lld", v[i]);
            } else if(i != v.size() - 1) {
                printf("%lld", v[i]);
            }
        }
        printf("\n");
    }
}