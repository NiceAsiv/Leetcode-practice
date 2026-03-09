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
#include<iostream>
using namespace std;
struct ListNode
{
    int    val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode *firstHalfEnd = endOfFirstHalf(head);
        ListNode *secondHalfStart = reverseList(firstHalfEnd->next);

        bool result = true;
        ListNode *p1 = head;
        ListNode *p2 = secondHalfStart;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // Restore list structure so caller sees original list unchanged.
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
    }

    ListNode *endOfFirstHalf(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
     
    ListNode *reverseList(ListNode *head){
        ListNode *prev =nullptr;
        ListNode *current= head;
        while(current!=nullptr){
            ListNode *next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};

// testcase
// head =
// [1,1,2,1]
// 输出
// false

int main()
{
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(1);
    head -> next -> next = new ListNode(2);
    head -> next -> next -> next = new ListNode(1);
    Solution solution;
    cout << solution.isPalindrome(head) << endl;
    return 0;
}