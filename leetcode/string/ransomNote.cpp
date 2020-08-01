class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mag[26] = {0};
        for(int i=0; i<magazine.size(); i++)
        {
            mag[magazine[i] - 'a']++;
        }
        int count = 0;
        for(int i=0; i<ransomNote.size(); i++)
        {
            if(mag[ransomNote[i] - 'a']<=0)
                count++;
            else
                mag[ransomNote[i] - 'a']--;
        }
        if(count<=0)
            return true;
        return false;
    }
};
