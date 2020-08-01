class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        /*vector<int> even;
        vector<int> odd;
        vector<int> result(A.size(), 0);
        for(int i=0; i<A.size(); i++)
        {
            if(A[i]%2==0)
                even.push_back(A[i]);
            else
                odd.push_back(A[i]);
        }
        int j=0; 
        int k=0;
        for(int i=0; i<A.size(); i+=2)
            result[i] = even[j++];
        for(int i=1; i<A.size(); i+=2)
            result[i] = odd[k++];
        return result;*/
        
        //better solution
        int j = 0;
        int k = 1;
        vector<int> result(A.size(), 0);
        for(int i = 0; i<A.size(); i++)
        {
            if(A[i]%2==0)
            {
                result[j] = A[i];
                j = j+2;
            }
            else
            {
                result[k] = A[i];
                k = k+2;
            }
        }
            return result;
    }
};
