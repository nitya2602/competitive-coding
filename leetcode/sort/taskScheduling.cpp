class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequency(26, 0);
        int total = tasks.size();
        for(int i=0; i<total; i++)
            frequency[tasks[i]-'A']++;
        sort(frequency.begin(), frequency.end());
        int max_freq = frequency[25] - 1;
        int spaces = max_freq*n;
        for(int i=24; i>=0; i--)
        {
            spaces -= min(max_freq, frequency[i]);
        }
        if(spaces>0)
            return total + spaces;
        return total;
    }
};
