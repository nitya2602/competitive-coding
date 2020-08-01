class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        vector<int> B;
        sort(A.begin(), A.end());
        A[0] += K;
        A[A.size()-1] -= K;
        if(A[A.size()-1] - A[0] < 0)
            return 0;
        return A[A.size()-1] - A[0];
    }
};
