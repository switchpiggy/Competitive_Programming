#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        if((a + b + c)%9 == 0 && (a + b + c)/9 <= min(a, min(b, c))) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}