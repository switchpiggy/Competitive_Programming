#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <limits>
#include <queue>
using namespace std;
 
int answer = INT_MAX;
string str;
bool maze[55][55];
bool bfs_maze[55][55];
vector<pair<int, int>> sta, fin;
queue<pair<int, int>> bfs;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
 
int main()
{
    cin >> n;
 
    int tmp0, tmp1;
    cin >> tmp0 >> tmp1;
    sta.push_back(make_pair(tmp0, tmp1));
    cin >> tmp0 >> tmp1;
    fin.push_back(make_pair(tmp0, tmp1));
    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        for (int j = 1; j <= n; j++)
        {
            if (str[j - 1] == '0')
            {
                maze[i][j] = true;
            }
        }
    }
    bfs.push(sta[0]);
    bfs_maze[sta[0].first][sta[0].second] = true;
    pair<int, int> tmp2, tmp3;
    while (!bfs.empty())
    {
        tmp2 = bfs.front();
        bfs.pop();
        for (int i = 0; i < 4; i++)
        {
            tmp3.first = tmp2.first + dx[i], tmp3.second = tmp2.second + dy[i];
            if (maze[tmp3.first][tmp3.second] && (!bfs_maze[tmp3.first][tmp3.second]) && tmp3.first <= n && tmp3.first > 0 && tmp3.second > 0 && tmp3.second <= n)
            {
                bfs_maze[tmp3.first][tmp3.second] = true;
                bfs.push(tmp3);
                sta.push_back(tmp3);
            }
        }
    }
    bfs.push(fin[0]);
    bfs_maze[fin[0].first][fin[0].second] = true;
    while (!bfs.empty())
    {
        tmp2 = bfs.front();
        bfs.pop();
        for (int i = 0; i < 4; i++)
        {
            tmp3.first = tmp2.first + dx[i], tmp3.second = tmp2.second + dy[i];
            if (maze[tmp3.first][tmp3.second] && (!bfs_maze[tmp3.first][tmp3.second]) && tmp3.first <= n && tmp3.first > 0 && tmp3.second > 0 && tmp3.second <= n)
            {
                bfs_maze[tmp3.first][tmp3.second] = true;
                bfs.push(tmp3);
                fin.push_back(tmp3);
            }
        }
    }
    int tmp4;
    for (int i = 0, limit = sta.size(); i < limit; i++)
    {
        for (int j = 0, limit0 = fin.size(); j < limit0; j++)
        {
            tmp4 = (sta[i].first - fin[j].first) * (sta[i].first - fin[j].first) + (sta[i].second - fin[j].second) * (sta[i].second - fin[j].second);
            if (tmp4 < answer)
            {
                answer = tmp4;
            }
        }
    }
    cout << answer;
}