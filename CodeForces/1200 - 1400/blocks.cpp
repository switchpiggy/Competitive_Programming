#include <iostream>
using namespace std;
 
int main()
{
    int n, i, k = 0, op[601], b, w;
    char c[201];
    cin >> n >> c;
    b = w = 0;
    for (i = 0; i<n; i++)
    {
        if (c[i] == 'W')
            w++;
        else
            b++;
    }
    if (w == n || b == n)
    {
        cout << 0;
        return 0;
    }
    
    if (w%2 == 1 && b%2 == 1)
    {
        cout << -1;
        return 0;
    }
    
    if (w%2 == 0)
    {
        for (i = 0; i<n-1; i++)
        {
            if (c[i] == 'W')
            {
                k++;
                op[k] = i+1;
                if (c[i+1] == 'W')
                {
                    c[i] = 'B';
                    c[i+1] = 'B';
                }
                else
                {
                    c[i] = 'B';
                    c[i+1] = 'W';
                }
            }
        }
    }
    else
    {
        //b%2 == 0
        for (i = 0; i<n-1; i++)
        {
            if (c[i] == 'B')
            {
                k++;
                op[k] = i+1;
                if (c[i+1] == 'B')
                {
                    c[i] = 'W';
                    c[i+1] = 'W';
                }
                else
                {
                    c[i] = 'W';
                    c[i+1] = 'B';
                }
            }
        }
    }
    cout << k << '\n';
    for (i = 1; i<=k; i++)
        cout << op[i] << ' ';
    return 0;
}