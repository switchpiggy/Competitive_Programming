#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;

    scanf("%d", &n);

    int res;

    int r = 0, b = 0;

    string c;

    cin >> c;

    for(int i = 0; i < n; ++i) {

        if(i%2 == 0 && c[i] == 'b') b++;

        else if(i%2 == 1 && c[i] == 'r') r++;

    }

    res = max(r, b);

    r = 0;

    b = 0;

    for(int i = 0; i < n; ++i) {

        if(i%2 == 1 && c[i] == 'b') b++;

        else if(i%2 == 0 && c[i] == 'r') r++;

    }

    res = min(res, max(r, b));

    printf("%d", res); 

}