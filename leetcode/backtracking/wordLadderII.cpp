//used bfs + dfs + backtracking
class Solution {
public:
    unordered_map<string, vector<string>> map;
    vector<vector<string>> ans;
    vector<string> vec;
    int count;
    void DFS(string beginWord, string endWord)
    {
        if(beginWord == endWord)
        {
            ans.resize(count+1);
            ans[count] = vec;
            count++;
        }
        else
        {
            for(auto i : map[beginWord])
            {
                vec.push_back(i);
                DFS(i, endWord);
                vec.pop_back();
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> visited;
        
        queue<string> q;
        q.push(beginWord);
        
        unordered_map<string, int> dict;
        visited[beginWord] = 1;
        
        for(int i = 0; i < wordList.size(); i++)
        {
            dict[wordList[i]] = 1;
        }
        
        int flag = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            vector<string> aux;
            for(int i = 0; i < size; i++)
            {
                string str = q.front();
                int dist = visited[str];
                q.pop();
                if(str == endWord)
                {
                    flag = 1;
                    //break;
                }
                string temp = str;
                for(int j = 0; j < str.length(); j++)
                {
                    str = temp;
                    for(int k = 0; k < 26; k++)
                    {
                        str[j] = 'a' + k;
                        if(dict[str] == 1 && visited.find(str) == visited.end())
                        {
                            q.push(str);
                            aux.push_back(str);
                            map[temp].push_back(str);
                            visited[str] = dist + 1;
                        }
                        else if(visited.find(str) != visited.end() && visited[str] == dist + 1)
                            map[temp].push_back(str);
                    }
                }
            }
        }
        for(auto i = map.begin(); i != map.end(); i++)
        {
            for(int j = 0; j < i->second.size(); j++)
                cout<<i -> first<<" -> "<<i -> second[j]<<" ";
            cout<<endl;
        }
        if(flag == 0)
            return ans;
        if(flag == 1)
        {
            vec.push_back(beginWord);
            DFS(beginWord, endWord);
        }
        return ans;
    }
};