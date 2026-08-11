class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       
       unordered_map<char,int>mp;

        for(auto &ch :tasks){
            mp[ch]++;

        }

        int time=0;

        priority_queue<int>pq;

        for(auto &ele :mp){
                pq.push(ele.second);
           
        }


        while(!pq.empty()){
            vector<int>temp;

           for(int i=1;i<=n+1;i++){

            if(!pq.empty()){
            int freq=pq.top();
            pq.pop();
            freq--;
            temp.push_back(freq);
           }
           }

           for(int &freq :temp){
            if(freq>0){
                pq.push(freq);
            }
           }

           if(pq.empty()){
            time+=temp.size();
           }

           else{
            time+=(n+1);
           }

        }







      return time;

        
    }
};