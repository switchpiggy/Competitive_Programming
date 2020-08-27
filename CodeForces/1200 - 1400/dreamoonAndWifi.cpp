#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;
ll a, b, q;
double ans;

void getAns(ll step, ll cur) {
	//cout << cur << endl;
    if(step == q) {
        if(cur == a - b) ans += 1;
        return;
    }

    getAns(step + 1, cur - 1);
    getAns(step + 1, cur + 1);

    return;
}

int main() {
    cin >> s >> t;

    for(ll i = 0; i < s.length(); ++i) {
        if(s[i] == '+') a++;
        else a--;
    }

    for(ll i = 0; i < t.length(); ++i) {
        if(t[i] == '+') b++;
        else if(t[i] == '?') q++;
        else b--;
    }
    
    //cout << a << ' ' << b << ' ' << q << endl;

    if(a == b && q == 0) {
        printf("1.000000000000\n");
        return 0;
    } else if(b + q < a || b - q > a) {
        printf("0.000000000000\n");
        return 0;
    }

    getAns(1, 1);
    getAns(1, -1);

    printf("%.10lf", ans/pow(2, q));
}