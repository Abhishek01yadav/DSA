class Solution {
public:
    int minPartitions(string n) {
       
       sort(n.begin(),n.end());
       
    int maxele=*max_element(n.begin(),n.end());
    return maxele-48;
       

        
    }
};