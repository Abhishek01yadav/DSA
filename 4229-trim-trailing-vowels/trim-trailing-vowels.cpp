class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o'|| ch=='u') return true;
        return false;
    }
    string trimTrailingVowels(string s) {
        int n=s.size();
        int idx=0;

        for(int  i=n-1;i>=0;i--){
            if(!isvowel(s[i]) ) {
               idx=i+1;
                break;
              
           
            }
        
        }
       s= s.substr(0,idx);
        return s;
        
    }
};