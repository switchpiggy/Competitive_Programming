#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;

    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<int> b(a.begin(), a.end());

    sort(b.begin(), b.end());

    int count = 0;

    for(int i = 0; i < n; ++i) {

        if(a[i] != b[i]) count++;

    }

    if(count == 2 || count == 0) printf("YES");

    else printf("NO");



}