class Solution {
public:
static bool cmp(vector<int>&a ,vector<int>&b){
    return a[1]<b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int lastend=INT_MIN;
        int cnt=0;
        for(auto & interval:intervals){
            int s=interval[0];
            int e=interval[1];
            if(s>=lastend){
                cnt++;
                lastend=e;
            }

        }


return intervals.size()-cnt;
        
    }
};