class Solution {
public:
    int maxDistance(string moves) {
        int u=0,d=0,l=0,r=0,k=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U' )u++;
           else  if(moves[i]=='D' )d++;
            else  if(moves[i]=='L' )l++;
           else  if(moves[i]=='R' )r++;
            else k++;
        }

        int hor=abs(l-r);
        int ver=abs(u-d);
        return hor +ver+ k;



        
        
    }
};