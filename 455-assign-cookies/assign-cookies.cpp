class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=s.size();
        int m=g.size();
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int i=0,j=0;
        int cnt=0;
        while(i<m && j<n ){
            if(s[j]>=g[i]) 
            {cnt++;
            i++;
            
            }
            j++;

        }
        return cnt;
        
    }
};