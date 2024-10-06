#include <iostream>
#include <vector>

using namespace std;

int ackermann_non_recursive(int m, int n, vector<vector<int>>& dp_v)
{
    if(m == 2)
    {

        return n*2 + 3;
    }

    if(dp_v[m-3].size() <= n)
    {

        int start_j = dp_v[m-3].size();
        dp_v[m - 3].resize(n + 1);
        for(int j = start_j ; j <= n ; j++)
        {
            dp_v[m - 3][j] = ackermann_non_recursive(m - 1, dp_v[m - 3][j - 1], dp_v);
        }

    }

    return dp_v[m-3][n];

}

int main()
{


    int m,n;
    cin >> m >> n;

    if(m < 2)
    {
        cout << n+1+m << endl;
        return 0;
    }
    else if(m == 2)
    {
        cout << n*2 + 3 << endl;
        return 0;
    }

    vector<vector<int>> dp_v(m-2);

    for(int i = 3 ; i <= m ; i++)
    {
        dp_v[i-3].resize(n+1);
        for(int j = 0 ; j <= n  ; j++)
        {
            if(j == 0)
            {
                dp_v[i-3][j] = ackermann_non_recursive(i-1,1,dp_v);
            }
            else
            {
                dp_v[i-3][j] = ackermann_non_recursive(i-1,dp_v[i-3][j-1],dp_v);
            }
        }
    }

    cout << dp_v[m-3][n] << endl;



    return 0;
}
