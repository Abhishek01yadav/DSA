class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());
        for(auto ele:strs){
            cout<<ele<<" ";
        }
        
        
        string first=strs[0];
       
        string last=strs[n-1];
       
        string res="";

       int i=0,j=0;
       while(i<first.size() && j <last.size()){
        if(first[i]==last[j]) res+=first[i];
        else break;
       
       
        i++;
        j++;
        
       }

        return res;
    }
};