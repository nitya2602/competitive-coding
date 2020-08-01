class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int temp;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        deque<int> d(nums.begin(), nums.end());
        vector<int> aux;
        for(int i=0; i<n; i++)
        {
            temp = d.front();
            if(temp!=i+1)
                aux.push_back(i+1);
            else
                d.pop_front();
        }
        return aux;
    }
};
