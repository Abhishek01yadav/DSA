class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal) return true;
        vector<string>temp;
        for(int i=0;i<s.size();i++){
            string s1=s.substr(0,i+1);
            string s2=s.substr(i+1);
            if((s2+s1)==goal) return true;
            cout<<s2+s1<<" ";
        }
        return false;
        
    }
};