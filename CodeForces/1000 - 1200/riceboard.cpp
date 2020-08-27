#include <bits/stdc++.h>

using namespace std;

int main() {

  int t;

  cin >> t;

  for(int count = 1; count <= t; ++count) {

    long long int r, n, m;

    cin >> r >> n >> m;

    long long int sum = 0;

    long long int cur = 1;

    for(long long int i = 0; i < n * n; ++i) {

      sum += cur%m;

      cur *= r;

    }

    cout << "Case #" << count << ": " << sum%m << endl;

  }

}