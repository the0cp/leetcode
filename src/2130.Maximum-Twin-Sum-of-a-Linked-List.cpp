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
    int pairSum(ListNode* head) {
        vector<int>value;
        while(head){
            value.push_back(head->val);
            head=head->next;
        }
        int maxSum=0;
        for(int i=0; i<value.size()/2; i++){
            maxSum=max(maxSum, value[i]+value[value.size()-i-1]);
        }
        return maxSum;
    }
};
