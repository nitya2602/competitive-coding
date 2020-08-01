class Solution {
public:
    int aux(vector<int> citations, int l, int r)
    {
        //important step to avoid runtime error
        if(l>r)
            return citations.size() - l;
        
        int mid = l + (r-l)/2;
        if(citations.size()-mid == citations[mid])
            return citations.size()-mid;
        else if(citations.size()-mid > citations[mid])
        {
            return aux(citations, mid+1, r);
        }
            return aux(citations, l, mid-1);
    }
    int hIndex(vector<int>& citations) {
        if(citations.size()==0)
            return 0;
        if(citations.size()==1)
        {
            if(citations[0]!=0)
                return 1;
            else
                return 0;
        }
        return aux(citations, 0, citations.size()-1);
    }
};
