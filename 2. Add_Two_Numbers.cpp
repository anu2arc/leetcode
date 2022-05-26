#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// This is an O(N) solution and cannot be improved further

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode dummy(-1, NULL), *temp;
        temp = &dummy;
        while (l1 || l2 || carry)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            temp->next = new ListNode(sum % 10, NULL);
            temp = temp->next;
            carry = sum / 10;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return dummy.next;
    }
};

int main()
{
    return 0;
}
