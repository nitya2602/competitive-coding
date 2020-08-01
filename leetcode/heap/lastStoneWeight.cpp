class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int ans;
        if(stones.size()==1)
            return stones[0];
        sort(stones.begin(), stones.end());
        while(stones.size()>=2)
        {
            int stone1 = stones[stones.size()-1];
            int stone2 = stones[stones.size()-2];
            if(stone1!=stone2)
            {
                if(stone1<stone2)
                {
                    stones.pop_back();
                    stones.pop_back();
                    stones.push_back(stone2-stone1);
                    sort(stones.begin(), stones.end());
                }
                else if(stone2<stone1)
                {
                    stones.pop_back();
                    stones.pop_back();
                    stones.push_back(stone1-stone2);
                    sort(stones.begin(), stones.end());
                }
            }
            else
                {
                    stones.pop_back();
                    stones.pop_back();
                }
        }
        if(stones.size()==0)
            ans=0;
        if(stones.size()==1)
            ans = stones[0];
        return ans;
    }
};
