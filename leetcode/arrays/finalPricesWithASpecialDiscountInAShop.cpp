class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> final_prices(prices.size(), 0);
        final_prices[prices.size()-1] = prices[prices.size()-1];
        for(int i=0; i<prices.size()-1; i++)
        {
            int temp=0;
            for(int j=i+1; j<prices.size(); j++)
            {
                if(prices[j]<=prices[i])
                {
                    temp = prices[j];
                    break;
                }
            }
            final_prices[i] = prices[i] - temp;
        }
        return final_prices;
    }
};
