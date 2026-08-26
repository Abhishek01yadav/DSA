
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*temp = headA;

        unordered_map<ListNode* ,int>mp;

        while(temp !=NULL ){
            mp[temp]=1;
            temp=temp->next;

        }

        temp=headB;

        while(temp !=NULL){
            if(mp.find(temp)!=mp.end()){
                return temp;
            }

            temp=temp->next;
        }
        return NULL;



        
    }
};