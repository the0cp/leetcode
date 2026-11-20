/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* nodeA=headA;
        ListNode* nodeB=headB;
        while(nodeA!=nodeB){
            nodeA=nodeA==nullptr?headB:nodeA->next;
            nodeB=nodeB==nullptr?headA:nodeB->next;
        }
        return nodeA;
    }
};
