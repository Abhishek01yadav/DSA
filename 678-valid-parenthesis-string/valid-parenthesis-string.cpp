class Solution {
public:
bool check(string &s,int i,int open){
    if(open < 0){
        return false;
    }
    if(i==s.length()) return open==0;
   
        if(s[i]=='('){
            return check(s,i+1,open+1);
        }
        else if(s[i]==')'){
            return check(s,i+1,open-1);
        }

        else{
            return check(s,i+1,open+1)|| check(s,i+1,open-1)|| check(s,i+1,open);

        }

  
   
}
    bool checkValidString(string s) {
       int minopen=0,maxopen=0;

       for(auto ch :s){
        if(ch=='('){
            minopen++;
            maxopen++;
        }

        else if(ch==')'){
            minopen--;
            maxopen--;
        }

        else{
            minopen--;
            maxopen++;
        }

        if(maxopen < 0){
            return false;
        }
        

        minopen=max(minopen,0);

       }



      
       return minopen==0; 
    }
};