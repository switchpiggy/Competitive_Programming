#include <bits/stdc++.h>

using namespace std;



int main() {

    int n, m;
    
    char vect[505][505];

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; ++i) {

        for(int j = 1; j <= m; ++j) {

            cin >> vect[i][j];

            if(vect[i][j] == 'S') {

                if(vect[i][j - 1] == 'W' | vect[i - 1][j] == 'W') {

                    return printf("NO"), 0;

                }

            }

            if(vect[i][j] == 'W') {

                if(vect[i][j - 1] == 'S' | vect[i - 1][j] == 'S') {

                    return printf("NO"), 0;

            	}

            }

            if(vect[i][j] == '.') vect[i][j] = 'D';

        }

    }

    printf("YES\n");

    for(int i = 1; i <= n; ++i) {

        for(int j = 1; j <= m; ++j) {

            cout << vect[i][j];

        }

        printf("\n");

    }

	return 0;



}