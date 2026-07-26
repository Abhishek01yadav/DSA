class Solution {
public:
    string reverseWords(string s) {
        string res="";
        int n=s.size();
       
int i=0;
        while(i<n && s[i]==' '){
            i++;
        }

        vector<string>ans;
         string temp="";

        while(i<n ){
            
           
            while( i<n && s[i]!=' '){
                temp+=s[i];
                i++;

            }
            
            ans.push_back(temp);
            temp="";
            
             
             while( i<n && s[i]==' '){
                i++;
             }
           

        }
        reverse(ans.begin(),ans.end());

       for(int i=0;i<ans.size();i++){
        res+=ans[i];
        if(i !=ans.size()-1){
            res+=' ';
        }
       }

       
return res;
      
    }
};