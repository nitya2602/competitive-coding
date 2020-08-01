class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i=0; i<arr.size()-1; i++)
        {
            for(int j=i+1; j<arr.size(); j++)
            {
                if(arr[i] == arr[j]*2 || (float)arr[i]==(float)arr[j]/2)
                    return true;
            }
        }
        return false;
    }
};
