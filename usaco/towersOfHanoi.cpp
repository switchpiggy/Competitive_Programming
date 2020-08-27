#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n;

void move(ll cur, char st, char ed, char aux) {
    if(cur == 1) {
        cout << st << ' ' << ed << endl;
        return;
    }

    move(cur - 1, st, aux, ed);
    cout << st << ' ' << ed << endl;
    move(cur - 1, aux, ed, st);

    return;
}

int main() {
    scanf("%lld", &n);
    move(n, 'A', 'C', 'B');
}  