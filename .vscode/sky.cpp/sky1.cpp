class Solution {
public:

    int f(int i, int j, string &s1, string &s2 , vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
        {
            if (i < 0)
            {
                int ans = 0;
                for (int a = j; a >= 0; a--)
                {
                    ans += s2[a];
                }
                return ans;
            }

            if (j < 0)
            {
                int ans = 0;
                for (int a = i; a >= 0; a--)
                {
                    ans += s1[a];
                }
                return ans;
            }
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int take=1e9;

        if (s1[i] == s2[j])
        {
            take= f(i - 1, j - 1, s1, s2 ,dp);
        }

        int nottake = min(int(s1[i]) + f(i - 1, j, s1, s2,dp), int(s2[j]) + f(i, j - 1, s1, s2,dp));

        return dp[i][j]= min(take,nottake);

    }

    int minimumDeleteSum(string s1, string s2)
    {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return f(n-1, m-1, s1, s2 , dp);
    }
};