//keep on extracting elements starting from the end and keep on adding them at the end
//or do a similar thing starting from the beginning
//do not extract elements from one end and insert at the other as it wll give same string as result
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=s.size()-1; i>=0; i--)
        {
            char a = s[i];
            s.erase(s.begin()+i);
            s.push_back(a);
        }
    }
};
