class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
      int m=logs.size();
        vector<int>answer(queries.size());
        sort(logs.begin(),logs.end(),[&](vector<int>a,vector<int>b){
            return a[1]<b[1];
        });

       vector< pair<int,int>>q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});


        }

        sort(q.begin(),q.end(),[&](pair<int,int>a,pair<int,int>b){
            return a.first < b.first;
        });

        int i=0,j=0;
        unordered_map<int,int>mp;
        

        for(int k=0;k<q.size();k++){
            int cnt=0;
            int s=q[k].first-x;
            int e=q[k].first;

            while(j<m && logs[j][1]<=e){
                mp[logs[j][0]]++;
                j++;
            }

            while(i<m && logs[i][1]<s){
             
                mp[logs[i][0]]--;
                if(mp[logs[i][0]]==0){
                    mp.erase(logs[i][0]);
                }
                i++;
            }
            cnt=mp.size();
            answer[q[k].second]=n-cnt;

        }



return answer;
        
    }
};