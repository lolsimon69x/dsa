class Solution {
        public:
                ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
                        ListNode* temp1 = l1;
                        ListNode* temp2 = l2;
                        ListNode* res;
                        res = (ListNode*)malloc(sizeof(struct ListNode));
                        int car = 0;
                        while (temp1->next != nullptr && temp2->next != nullptr) {
                                if (temp1->next == nullptr) {
                                        res->val = temp2->val + car;
                                }
                                if (temp2->next == nullptr) {
                                        res->val = temp1->val + car;
                                }

                                int sum = 0;
                                int v1 = temp1->val;
                                int v2 = temp2->val;


                                if (v1 + v2 > 10) {
                                        car = 1;
                                }
                                else {
                                        car = 0;
                                }

                                sum = v1 + v2 + car;

                                res->val = sum % 10;
                                temp1 = temp1->next;
                                temp2 = temp2->next;
                        }

                        return res;
                }
};

class Solution {
        public:
                ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
                        ListNode* dummy = new ListNode();
                        ListNode* res = dummy;
                        int total = 0, carry = 0;

                        while (l1 || l2 || carry) {
                                total = carry;

                                if (l1) {
                                        total += l1->val;
                                        l1 = l1->next;
                                }
                                if (l2) {
                                        total += l2->val;
                                        l2 = l2->next;
                                }

                                int num = total % 10;
                                carry = total / 10;
                                dummy->next = new ListNode(num);
                                dummy = dummy->next;
                        }

                        ListNode* result = res->next;
                        delete res;
                        return result;
                }
};

/*
class Solution {
        public:
                ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
                        int sl1 = 0, sl2 = 0;
                        ListNode* res;

                        ListNode* ptr = l1;
                        while (ptr->next != nullptr) {
                                sl1++;
                        }
                        ptr = l2;
                        while (ptr->next != nullptr) {
                                sl2++;
                        }

                        int n = max(sl2, sl1);
                        for (int i = 0; i < n; i++) {
                                int sum = 0, int v1, int v2;
                                v1 = l1->val;
                                v2 = l2->val;

                                sum = v1 + v2;
                                res->val = sum;
                        }
                }
};
*/
