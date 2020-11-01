#include<bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int m, int n, int lookup[][30]){
    if(m==0 || n==0)
        return 0;
    if(lookup[m][n]==0)
    {
        if(X[m]==Y[n])
            lookup[m][n] = LCS(X, Y, m-1, n-1, lookup) + 1;
        else
            lookup[m][n] = max(LCS(X, Y, m-1, n, lookup), LCS(X, Y, m, n-1, lookup));
    }
    return lookup[m][n];
}

int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
    int lookup[X.length()][30];
    cout<<LCS(X, Y, X.length(), Y.length(), lookup);
    return 0;
}
