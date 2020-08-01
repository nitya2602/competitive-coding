//solving via graphs
//calculating in and out degree of each node
//node with N-1 indegree and 0 outdegree is the answer
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<pair<int, int>> res(N+1);
        //first is indegree and second is outdegree
        for(int i=0; i<trust.size(); i++)
        {
            res[trust[i][1]].first++;
            res[trust[i][0]].second++;
        }
        for(int i=1; i<=N; i++)
        {
            if(res[i].first==N-1 && res[i].second==0)
                return i;
        }
        return -1;
    }
};
