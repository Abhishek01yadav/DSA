class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        
        int m=reward1.size();
        int n=reward2.size();
        int sum1=accumulate(reward2.begin(),reward2.end(),0);
        vector<int>diff(m);
        for(int i=0;i<m;i++){
            diff[i]= reward1[i]-reward2[i];
        }

//sort(diff.rbegin(),diff.rend());
priority_queue<int,vector<int>,greater<int>>pq;
for(int i=0;i<diff.size();i++){
    pq.push(diff[i]);
    if(pq.size()>k){
        pq.pop();
    }
    
}
while(!pq.empty()){
    sum1+=pq.top();
    pq.pop();
}
// for(int i=0;i<k;i++){
//     sum1+=diff[i];

// }
return sum1;


    }
};