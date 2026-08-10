class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=g.size();
        int n=s.size();
        int i=0,j=0;
        int cnt=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while(i<m && j<n){

            if(s[j]>=g[i]){
                cnt++;
            i++;
            j++;
                
            }


          else if  (  s[j] < g[i] ){
                j++;
            }

            else{
          
           i++;
            j++;

            }
                

            
        }
        return cnt;
    }
};