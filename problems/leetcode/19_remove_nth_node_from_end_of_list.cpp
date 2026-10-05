class Solution {
        public:
                ListNode* removeNthFromEnd(ListNode* head, int n) {
                        ListNode* fast = head;
                        ListNode* slow = head;

                        for (int i = 0; i < n; i++) {
                                fast = fast->next;
                        }
                        if (!fast) {
                                return head->next;
                        }

                        while (fast->next) {
                                fast = fast->next;
                                slow = slow->next;
                        }

                        slow->next = slow->next->next;
                        return head;
                }
};
/* MY SOLUTION (WRONG ANSWER 188 / 208 test cases passed) */
class Solution {
        public:
                ListNode* removeNthFromEnd(ListNode* head, int n) {
                        ListNode* ptr = head;
                        int size = 0;
                        while (ptr != nullptr) {
                                ptr = ptr->next;
                                size++;
                        }

                        ptr = head;
                        ListNode* prev = head;
                        for (int i = 0; i < size - n; i++) {
                                prev = ptr;
                                ptr = ptr->next;
                        }

                        ListNode* temp = ptr->next; 
                        prev->next = temp;
                        ptr->next = nullptr;

                        return size == 1 ? nullptr : head;
                }
};
