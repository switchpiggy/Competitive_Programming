#include <bits/stdc++.h>

using namespace std;

int visited[205][205];

int main() {

    int x = 100;

    int y = 100;

    string str;

    cin >> str;

    visited[x][y] = 1;

    for(int i = 0; i < str.length(); ++i) {

        if(str[i] == 'L') x--;

        else if(str[i] == 'R') x++;

        else if(str[i] == 'U') y++;

        else if(str[i] == 'D') y--;

        if(visited[x][y] == 1) {

            printf("BUG");

            return 0;

        }

        int total = visited[x][y + 1] + visited[x][y - 1] + visited[x + 1][y] + visited[x - 1][y];

        if(total > 1) {

            printf("BUG");

            return 0;

        }
            visited[x][y] = 1;

    }

    printf("OK");

}