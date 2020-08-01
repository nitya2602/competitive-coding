class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int INFI = 1e8;
        K++;
        vector<int> dp(n, INFI);
        dp[src] = 0;
        for(int k=1; k<=K; k++)
        {
            vector<int> newWeight(n);
            for(int i=0; i<n; i++)
            {
                newWeight[i] = dp[i];
            }
            for(vector<int> &e : flights)
            {
                newWeight[e[1]] = min(newWeight[e[1]], dp[e[0]] + e[2]);
            }
            dp = newWeight;
        }
        return dp[dst] == INFI ? -1 : dp[dst];
    }
};
