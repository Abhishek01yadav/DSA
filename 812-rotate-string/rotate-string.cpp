class Solution {
public:
    bool rotateString(string s, string goal) {
        int m=s.size();
        int n=goal.size();
        if(m !=n) return false;

      for(int k=0;k<m;k++){
         rotate(s.begin(),s.begin()+1,s.end());
        if(s==goal) return true;
      }
      return false;
        
    }
};