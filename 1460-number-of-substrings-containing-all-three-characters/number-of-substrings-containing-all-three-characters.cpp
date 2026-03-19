class Solution {
public:
    int numberOfSubstrings(string s) {
        
       // brute force
        // int n=s.size();
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     vector<int>hash(3,0);
        //     for(int j=i;j<n;j++){
        //         hash[s[j]-'a']=1;
        //         if(hash[0]+hash[1]+hash[2]==3) 
        // {
        //     cnt=cnt+(n-j);
        //     break;
        // }

                
        //     }
            
        // }
        
        // return cnt;

       // 2nd approach: sliding window
       int n=s.size();
       vector<int>lastseen(3,-1);
       int cnt=0;
       for(int i=0;i<n;i++){
        lastseen[s[i]-'a']=i;
        if(lastseen[0]!=-1 && lastseen[1]!=-1  && lastseen[2]!=-1){
            int x= min(lastseen[0] ,lastseen[1]);
            int y=min(x,lastseen[2]);
            cnt=cnt+1+y;

        }
       }
       return cnt;


    }
};