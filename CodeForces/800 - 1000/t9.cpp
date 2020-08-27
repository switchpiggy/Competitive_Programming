#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;
int L, K, cost[30][30], key[300];
char sir[10009];
vector < int > dp[10009][30];
vector < pair < int, int > > how[10009][30];
vector < int > v[300];

void setC (char c, int pos)
{
    v[pos].push_back (c - 'A'); //v[number] = vector of corresponding letters
    key[c - 'A'] = pos; //key[charNumber] = number;
}

void printString (int i, int j, int k)
{
    if (i != 0)
        printf ("%c", 'A' + j);
    if (i == L)
    {
        printf ("\n");
        return ;
    }
    printString (i + 1, how[i][j][k].first, how[i][j][k].second);
}

int main ()
{

//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
setC ('A', 2), setC ('B', 2), setC ('C', 2);
setC ('D', 3), setC ('E', 3), setC ('F', 3);
setC ('G', 4), setC ('H', 4), setC ('I', 4);
setC ('J', 5), setC ('K', 5), setC ('L', 5);
setC ('M', 6), setC ('N', 6), setC ('O', 6);
setC ('P', 7), setC ('Q', 7), setC ('R', 7), setC ('S', 7);
setC ('T', 8), setC ('U', 8), setC ('V', 8);
setC ('W', 9), setC ('X', 9), setC ('Y', 9), setC ('Z', 9);
v[10].push_back (26);
scanf ("%d", &tests);
int testId = 0;
while (tests --)
{
    printf ("Case #%d: ", ++testId);
    scanf ("%d %d", &L, &K);
    for (int i=0; i<26; i++)
        for (int j=0; j<26; j++)
            scanf ("%d", &cost[i][j]); //cost[i][j] = probability of j to come after i
    scanf ("%s", sir + 1), assert (L == strlen (sir + 1)); 
    for (int i=1; i<=L; i++)
        sir[i] -= '0', assert (0 <= sir[i] && sir[i] < 10);
    for (auto j : v[sir[L]]) //v[sir[L]] = the vector of letters that corrsepond to the Lth number in the string
    {
        dp[L][j].clear (), how[L][j].clear ();
        dp[L][j] = vector < int > (1, 0), //dp[L][j] = 0
        how[L][j] = vector < pair < int, int > > (1, make_pair (-1, -1)); //how[L][j] push back pair<int, int>(-1, -1)
    }
    sir[0] = 10;
    for (int i=0; i<26; i++)
        cost[26][i] = 0;
    int currSize = 0;
    for (int i=L - 1; i>=0; i--) //iterate backwards through string
    {
        for (auto j : v[sir[i]]) //iterate through array of corrseponding letters for number
        {
            vector < pair < int, pair < int, int > > > curr;
            for (auto k : v[sir[i + 1]]) //iterate through similar array of next number
            {
                int currPos = 0;
                for (auto it : dp[i + 1][k]) 
                    curr.push_back ({-it - cost[j][k], {k, currPos}}),
                    currPos ++;
            }
            sort (curr.begin (), curr.end ());
            dp[i][j].clear (), how[i][j].clear ();
            for (int p=0; p<curr.size () && p < K; p++)
                dp[i][j].push_back (-curr[p].first),
                how[i][j].push_back (curr[p].second);
            currSize += dp[i][j].size ();
            assert (dp[i][j].size () == how[i][j].size ());
        }
    printString (0, 26, K - 1);
}
return 0;
}
