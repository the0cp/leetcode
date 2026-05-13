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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;
        ListNode dummy(0);
        dummy.next=head;

        ListNode* cur=head;
        ListNode* group=&dummy;

        int cnt=0;
        while(cur){
            cnt++;
            cur=cur->next;
        }

        while(cnt>=k){
            cur=group->next;
            ListNode* next=nullptr;
            ListNode* prev=nullptr;
            for(int i=0; i<k; i++){
                next=cur->next;
                cur->next=prev;
                prev=cur;
                cur=next;
            }
            cnt-=k;

            ListNode* tail=group->next;
            group->next=prev;
            tail->next=cur;
            group=tail;
        }

        return dummy.next;
    }
};
