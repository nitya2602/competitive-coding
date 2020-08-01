class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0 || prices.size()==1)
            return 0;
        int minPrice = *max_element(prices.begin(), prices.end());
        int maxProfit = 0;
        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i] < minPrice)
                minPrice = prices[i];
            else if(prices[i] - minPrice > maxProfit)
                maxProfit = prices[i] - minPrice;
        }
        return maxProfit;
    }
};
