#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i + 1 < n; i += 2) {
        if(i%4 == 0) cout << "aa";
        else cout << "bb"; 
    }
    if(n%4 == 3) cout << 'b';
    if(n%4 == 1) cout << 'a';
}