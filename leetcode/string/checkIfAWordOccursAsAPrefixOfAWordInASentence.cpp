class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream s(sentence);
        vector<string> words;
        string word;
        while(s>>word)
            words.push_back(word);
        for(int i=0; i<words.size(); i++)
        {
            if(words[i].size()<searchWord.size())
                continue;
            if(searchWord==words[i].substr(0, searchWord.size()))
                return i+1;
        }
        return -1;
    }
};
