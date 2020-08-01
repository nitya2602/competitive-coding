class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()==0)
            return 0;
        stringstream str(s);
        vector<string> words;
        string word;
        while(str>>word)
            words.push_back(word);
        if(words.size()==0)
            return 0;
        return words[words.size()-1].size();
    }
};
