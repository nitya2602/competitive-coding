//Dynamic programming approach
/*table[i] will be storing the number of solutions for value i.
 We need n+1 rows as the table is constructed in bottom up manner using the base case(n=0)
 */

class Solution {
public:
        int change(int amount, vector<int>& coins) {
        	//initialize all table values as 0
            vector<int> table(amount+1, 0);
            
            //base case(if given value is 0)
            table[0] = 1;
            
            /*pick all coins one by one and update the table[] values
            after the index greater than or equal to the value of the picked coin
			*/ 
            for(int i=0; i<coins.size(); i++)
            {
                for(int j=coins[i]; j<=amount; j++)
                {
                    table[j] += table[j - coins[i]];
                }
            }
            return table[amount];
    }
};
