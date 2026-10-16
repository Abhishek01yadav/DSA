class Solution {
public:
typedef long long ll;
const int mod=1e9+7;
int n;
vector<ll>SumSegtree;
vector<ll>SqSumSegtree;
vector<ll>lazytree;

void lazyaddition(int i,int l,int r,int val){
    int len=r-l+1;
    SqSumSegtree[i]+=2*val*SumSegtree[i]+len*val*val;
    SumSegtree[i]+=(len*val);
}
void updateRange(int start,int end,int i,int l,int r,int val){
    if(lazytree[i]!=0){
        lazyaddition(i,l,r,lazytree[i]);
    }
    
    if(l!=r){
        lazytree[2*i+1]+=lazytree[i];
          lazytree[2*i+2]+=lazytree[i];

    }

    lazytree[i]=0;

//out of range
    if(l>end || r <start || l>r){
        return;
    }

    //completly within range

if(l>=start && r<=end){
    lazyaddition(i,l,r,val);

    if(l!=r){
        lazytree[2*i+1]+=val;
          lazytree[2*i+2]+=val;

    }
    return;


}

int mid=l+(r-l)/2;
updateRange(start,end,2*i+1,l,mid,1);
updateRange(start,end,2*i+2,mid+1,r,1);
SumSegtree[i]=SumSegtree[2*i+1]+SumSegtree[2*i+2];
SqSumSegtree[i]=SqSumSegtree[2*i+1]+SqSumSegtree[2*i+2];



}
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        SumSegtree.assign(4*n,0);
        SqSumSegtree.assign(4*n,0);
        lazytree.assign(4*n,0);

vector<int>lastSeen(100001,-1);
ll result=0;
        for(int i=0;i<n;i++){
            int start=lastSeen[nums[i]]+1;
            int end=i;

        updateRange(start,end,0,0,n-1,1);
        result=(result+SqSumSegtree[0])%mod;
        lastSeen[nums[i]]=i;


            
        }
        
        return result;
    }
};