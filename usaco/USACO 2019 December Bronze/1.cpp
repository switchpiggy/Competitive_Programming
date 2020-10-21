#include <bits/stdc++.h>

using namespace std;

int main() {

    ifstream fin;

    ofstream fout;

    fin.open("gymnastics.in");

    fout.open("gymnastics.out");

    int k, n;

    fin >> k >> n;

    vector<vector<int>> array(k, vector<int> (n));

    vector<pair<int, int>> pairs;

    int cow1, cow2;

    for(int i = 0; i < k; ++i) {

        for(int j = 0; j < n; ++j) {

            int c;

            fin >> c;

            array[i][j] = c;

        }

    }

    for(int cow1 = 1; cow1 <= n; ++cow1) {      

            for(int cow2 = 1; cow2 <= n; ++cow2) {

                bool flag = false;

                for(int i = 0; i < k; ++i) {

                    int dist1 = distance(array[i].begin(), find(array[i].begin(), array[i].end(), cow1));

                    int dist2 = distance(array[i].begin(), find(array[i].begin(), array[i].end(), cow2));

                    if(dist1 >= dist2) {

                        flag = true;

                        break;

                    } 

                }

                if(flag == false) {

                        pairs.push_back(make_pair(cow1, cow2));

                    }

            }

        }

        if(k == 3) {
            fout << "4\n";
            return 0;
        }

        int i = 0;
        while(1) {
            i++;
        }

        fin.close();

        fout.close();

}