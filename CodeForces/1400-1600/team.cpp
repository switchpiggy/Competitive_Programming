#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    
    cin >> n >> m;

    if((n - 1) > m || m > (n + 1) * 2) {

        cout << -1;

        return 0;

    }

    if(n == m || n - 1 == m) {

        for(int i = 1; i <= n + m; ++i) {

            if(i%2 == 1) cout << 0;

            else cout << 1;

        }

    } else if(m - 1 == n) {

        for(int i = 1; i <= n + m; ++i) {

            if(i%2 == 1) cout << 1;

            else cout << 0;

        }

    } else {

        int l = m - (n + 1);
        
        int sub = l;

        for(int i = 1; i <= n + m - l; ++i) {

            if(i%2 == 1) {

                cout << 1;

                if(sub != 0) {

                    cout << 1;

                    sub--;

                }

            } else cout << 0;


        }

    }

    return 0;

}