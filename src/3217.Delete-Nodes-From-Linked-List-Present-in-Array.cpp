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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>mp(nums.begin(), nums.end());
        while(head&&mp.count(head->val)){
            head=head->next;
        }

        ListNode* cur=head;
        while(cur&&cur->next){
            while(cur->next&&mp.count(cur->next->val)){
                cur->next=cur->next->next;
            }
            cur=cur->next;
        }
        return head;
    }
};
