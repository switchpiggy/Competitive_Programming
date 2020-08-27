#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll res[1000005], a[100007];
stack<ll> s;
ll n;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);

    for(ll j = 0; j < 2 * n; ++j) {
    	ll i = j%n;
        if(s.empty()) {
            s.push(i);
        } else if(a[i] > a[s.top()]) {
            while(!s.empty() && a[i] > a[s.top()]) {
            	cout << s.top() << ' ' << a[i] << endl;
                if(!res[s.top()]) res[s.top()] = a[i];
                s.pop();
            }
            s.push(i);
        } else s.push(i);
    }
    


    for(ll i = 0; i < n; ++i) {
    	if(!res[i]) printf("-1 ");
        else printf("%lld ", res[i]);
    }

    return 0;
}