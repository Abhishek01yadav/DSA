
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

         ListNode *temp=head;
         unordered_map< ListNode* ,int>mp;

         while(temp !=NULL){
            if(mp.find(temp)==mp.end()){
                mp[temp]++;
                temp=temp->next;
            }
            else{
                return temp;
            }
        
         }
return NULL;
        
    }
};