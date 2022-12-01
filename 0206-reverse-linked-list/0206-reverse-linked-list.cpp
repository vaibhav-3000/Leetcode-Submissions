/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* rev(ListNode* &head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextPtr;
        while(curr!=NULL){
            //cout<<curr->val<<endl;
            nextPtr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextPtr;
        }
        return prev;    
    }
        
    ListNode* reverseList(ListNode* head) {
        head=rev(head);
        // ListNode* temp=head;
        // ListNode* prev=head;
        // while(temp!=NULL){
        //     if(temp->val>mx){
        //         prev=temp;
        //         temp=temp->next;
        //     }
        //     else{
        //         prev->next=temp->next;
        //         ListNode* x=temp;
        //         temp=temp->next;
        //         delete(x);
        //     }
        // }
        // rev(head);nt mx=0;
        
        return head;
        
    }
};