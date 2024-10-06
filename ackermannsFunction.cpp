#include<iostream>
#include<vector>
using namespace std;


int ackermann(int m , int n)
{
    //cout << "M:" << m << "N:" << n << endl;
    if(m == 0)
    {
        return n+1;
    }
    if(n == 0)
    {
        return ackermann(m-1,1);
    }

    return ackermann(m-1,ackermann(m,n-1));
}

int ackermann_non_recursive(int m, int n, vector<vector<int>>& dp_v, vector<int>& dp_n)
{
    if(m < 2)
    {
        return n+1+m;
    }
    else if(m == 2)
    {

        return n*2 + 3;
    }
    //cout << "function:" << m << " " << n << endl;
    if(dp_v[m-3].size() <= n)
    {
        vector<int> ret = dp_v[m-3];
        int start_j = dp_v[m-3].size();
        //cout <<"start J:" << start_j << endl;
        for(int j = start_j ; j <= n ; j++)
        {
            //dp[i][j] = ackermann_non_recursive[i][j];
            ret.push_back(ackermann_non_recursive(m-1,ret[j-1],dp_v,dp_n));
            //cout << dp[i][j] << endl;
        }
        dp_v[m-3] = ret;
    }

    return dp_v[m-3][n];

}


int main()
{
    int m , n;

    cin >> m >> n;

    //int dp[m][n];

    vector<vector<int>> dp_v;


    cout << ackermann(m,n) << endl;

    /*for(int i = 3 ; i <= 3 ; i++)
    {
        vector<int> dp_n;
        for(int j = 0 ; j <= 25  ; j++)
        {
            //dp[i][j] = ackermann_non_recursive[i][j];
            if(j == 0)
            {
                dp_n.push_back(ackermann_non_recursive(i-1,1,dp_v,dp_n));
            }
            else
            {
                dp_n.push_back(ackermann_non_recursive(i-1,dp_n[j-1],dp_v,dp_n));
            }

            //cout << dp[i][j] << endl;
        }
        dp_v.push_back(dp_n);
    }


    for(int i = 0 ; i < dp_v.size() ; i++)
    {
        for(int j = 0 ; j < dp_v[i].size() ; j++)
        {
            cout << dp_v[i][j] << " ";
        }
        cout << endl;
    }




    /*for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            cout << i << " " << j << " / ";
            cout << ackermann(i,j) << endl;
        }
    }*/

    return 0;
}
