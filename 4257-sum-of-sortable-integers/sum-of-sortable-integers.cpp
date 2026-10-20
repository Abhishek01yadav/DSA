class Solution {
public:
void computeLPS(vector<int>&pattern,vector<int>&lps){
    int m=pattern.size();
    int len=0;//lenght of the previous largest prefix and suffix
    lps[0]=0;
    int i=1;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len !=0)  len=lps[len-1];

            else{
                lps[i]=0;
                i++;
            }
            
        }

    }



}

bool kmpsearch(vector<int>&pat,vector<int>&txt){
    int n=txt.size();
    int m=pat.size();
    vector<int>lps(m,0);
    computeLPS(pat,lps);

    int i=0,j=0;

    while(i<n){
        if(txt[i]==pat[j]){
            i++;
            j++;
        }

        if(j==m){
            return true;
        }

        else if( i<n &&txt[i]!=pat[j]){
            if(j !=0){
                 j=lps[j-1];

            }

            else{
                i++;
            }
           
        }
    }
    return false;

}

bool isPossible(vector<int>&vec1,vector<int>&vec2){
    vector<int>txt=vec2;
   txt .insert(txt.end(),vec2.begin(),vec2.end());
 return    kmpsearch(vec1,txt);

}
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end());
        for(int k=1;k<=n;k++){
            if(n%k !=0) continue;

            bool valid=true;
            for(int start=0;start<n;start+=k){
                vector<int>vec1(nums.begin()+start,nums.begin()+start+k);
                 vector<int>vec2(sorted.begin()+start,sorted.begin()+start+k);

                 if(!isPossible(vec1,vec2)){
                    valid=false;
                    break;
                 }



            }

            if(valid) result+=k;
        }
        
        return result;
    }
};