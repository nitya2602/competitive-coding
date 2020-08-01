class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        /*for(int i=0; i<target.size(); i++)
        {
            if(target[i]!=arr[i])
                return false;
        }
        return true;
        */
        
        //second best method
        /*if(target==arr)
            return true;
        return false;*/
        
        //best method
        return equal(target.begin(), target.end(), arr.begin());
    }
};
