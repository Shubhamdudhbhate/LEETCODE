#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class ListNode
{

public:
    int data;
    ListNode *next;
    ListNode *head;

    ListNode(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
public:
    bool IsCycle = false;

    ListNode *detectCycle(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        bool IsCycle = false;

        while (fast != NULL && fast->next != NULL)
        { // To  detect loop

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                IsCycle = true;
                break;
            }
        }

        if (!IsCycle)
        {
            return NULL;
        }

        slow = head;
        ListNode*prev = NULL;
        while (slow != fast)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }

        prev->next = NULL; // to remove cycle

        return slow;
    }
};