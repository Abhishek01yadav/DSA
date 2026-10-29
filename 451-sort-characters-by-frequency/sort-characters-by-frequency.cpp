class Solution {
public:
typedef pair<char,int>P;
    string frequencySort(string s) {
        string result="";
        vector<P>v(123);
        
        for(auto &ch:s){
            int freq=v[ch].second;
            v[ch]={ch,freq+1};
        }

       auto lambda=[&](P &p1,P &p2){
        int freq1=p1.second;
        int freq2=p2.second;
        if(freq1!= freq2){
            return  freq1>freq2;
        }
        return p1.first< p2.first;
       };

       sort(v.begin(),v.end(),lambda);

       for(int i=0;i<=122;i++){
        int freq=v[i].second;
        if(freq>0){
            char ch=v[i].first;
            int freq=v[i].second;
            string temp=string(freq,ch);
            result+=temp;
        }
       }
        return result;
    }
};