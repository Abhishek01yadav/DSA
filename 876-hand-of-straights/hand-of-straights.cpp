class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n % groupSize !=0){
            return false;
        }

        map<int,int>mp;

        priority_queue<int,vector<int>,greater<int>>pq;

        for(int &x : hand){
            mp[x]++;
            pq.push(x);

        }


        while(!pq.empty()){
            int start=pq.top();
            pq.pop();

            if(mp[start]==0)  continue;

            for(int i=0;i<groupSize;i++){
                int curr=start+i;

                if(mp[curr]==0){
                    return false;
                }

                mp[curr]--;
            }
        }

        return true;
    }
};