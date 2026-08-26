
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map< ListNode* ,int> mp;
        ListNode* temp=head;
        while(temp !=NULL){
            if(mp.find(temp)==mp.end()){
                mp[temp]=1;
                temp=temp->next;
                
            }
            else{
                return true;
            }
        }
        return false;


        
    }
};