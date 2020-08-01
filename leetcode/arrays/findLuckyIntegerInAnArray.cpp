class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> aux;
        for(const auto &number : arr)
        {
            aux[number]++;
        }
        int max = -1;
        for(const auto &i : aux)
        {
            if(i.first==i.second && i.first>max)
                max = i.first;
        }
        return max;
    }
};
