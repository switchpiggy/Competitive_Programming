#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, temp;
vector<ll> pos;
vector<ll> neg;

int main() {
    cin >> n;
    ll zero = 0;
    pos.clear();
    neg.clear();
    for(ll i = 0; i < n; ++i) {
        cin >> temp;
        if(temp > 0) pos.push_back(temp);
        else if(temp < 0) neg.push_back(temp); 
        else zero++;
    }

    sort(neg.begin(), neg.end());

    if(zero == n) {
        cout << '0' << endl;
        return 0;
    }

    if(n == 1) {
        if(pos.empty()) {
            cout << neg[0] << endl;
        } else if(zero) cout << 0 << endl;
        else cout << pos[0] << endl;

        return 0;
    }

    if(neg.size() == 1 && pos.empty()) {
        if(zero) cout << 0 << endl;
        else cout << neg[0] << endl;
        return 0;
    }

    for(ll i = 0; i < pos.size(); ++i) cout << pos[i] << ' ';
    ll i = 0;
    
    while(neg.size() - i >= 2) {
        cout << neg[i] << ' ' << neg[i + 1] << ' ';
        i += 2;
    }

    return 0;
}