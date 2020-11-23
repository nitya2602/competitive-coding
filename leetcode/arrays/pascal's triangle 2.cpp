//done using space  optimisation
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        ans[0] = 1;
        ans[rowIndex] = 1;
        if(rowIndex == 0 || rowIndex == 1)
            return ans;
        long long i = 0;
        for(i = 1; i <= rowIndex/2; i++)
        {
            ans[i] = (ans[i-1]*(rowIndex - i + 1))/i;
        }
        long long j;
        if(rowIndex%2 == 0)
            j = i - 2;
        else j = i - 1;
        for(long long k = i; k < rowIndex; k++)
        {
            ans[k] = ans[j--];
        }
        return ans;
    }
};