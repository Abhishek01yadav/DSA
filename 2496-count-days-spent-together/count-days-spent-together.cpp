class Solution {
public:
int findDay(string date,vector<int>&cummdays){
    int month=stoi(date.substr(0,2));
    int days=stoi(date.substr(3));

    return cummdays[month-1]+days;
}
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>monthdays={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int>cummdays(13,0);
    cummdays[1]=monthdays[0];

    for(int i=2;i<12;i++){
        cummdays[i]=cummdays[i-1]+monthdays[i-1];

    }

    int  arriveAliceDay=findDay(arriveAlice,cummdays);

   int  leaveAliceDay=findDay(leaveAlice,cummdays);

    int  arriveBobDay=findDay(arriveBob,cummdays);

   int  leaveBobDay=findDay(leaveBob,cummdays);

   int ans=min(leaveAliceDay,leaveBobDay) -max(arriveAliceDay,arriveBobDay) +1;
   return ans<0? 0:ans;

        
    }
};