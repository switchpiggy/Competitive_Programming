#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
priority_queue<ll> a, b;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        ll temp;
        scanf("%lld", &temp);
        a.push(temp);
    }

    for(ll i = 0; i < n; ++i) {
        ll temp;
        scanf("%lld", &temp);
        b.push(temp);
    }

    ll s = 0, t = 0, step = 0;

    while(!a.empty() || !b.empty()) {
        if(step%2 == 0) {
            if((a.top() >= b.top() && a.size()) || !b.size()) {
                ll tp = a.top();
                //cout << tp << ' ' << 'a' << endl;
                a.pop();
                s += tp;
            } else if(b.size()) {
                //cout << "b " << b.top() << endl;
                b.pop();
            }
        } else {
            if((b.top() >= a.top() && b.size()) || !a.size()) {
                ll tp = b.top();
                //cout << tp << ' ' << 'b' << endl;
                b.pop();
                t += tp;
            } else if(a.size()) {
                //cout << "a " << a.top() << endl;
                a.pop();
            }
        }
        step++;
        //cout << step << endl;
    }

	//cout << s << ' ' << t << endl;
    printf("%lld\n", s - t);

    return 0;
}