#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int jw = 0;
        ListNode* ans = l1;
        int temp;
        while(l1 != NULL && l2 != NULL) {
            temp = l1->val+l2->val;
            l1->val = (temp+jw)%10;
            jw = (temp+jw)/10;
            if(l1->next == NULL && l2->next == NULL && jw != 0) {
                l1->next = new ListNode(jw);
                l1 = l1->next;
                jw = 0;
                break;
            } else if(l1->next == NULL) {
                l1->next = l2->next;
                l1 = l1->next;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL && jw != 0) {
            temp = l1->val+jw;
            l1->val = temp%10;
            jw = temp/10;
            if(l1->next == NULL && jw != 0) {
                l1->next = new ListNode(jw);
                l1 = l1->next;
            }
            l1 = l1->next;
        }
        return ans;
    }
};
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    int number1, number2;
    scanf("%d%d", &number1, &number2);
    ListNode* n1 = new ListNode(number1%10);
    number1 /= 10;
    ListNode* temp;
    temp = n1;
    while(number1 != 0) {
        ListNode* t1 = new ListNode(number1%10);
        number1 /= 10;
        temp->next = t1;
        temp = t1;
    }
    ListNode* n2 = new ListNode(number2%10);
    number2 /= 10;
    temp = n2;
    while(number2 != 0) {
        ListNode* t2 = new ListNode(number2%10);
        number2 /= 10;
        temp->next = t2;
        temp = t2;
    }
    ListNode* n3 = Solution().addTwoNumbers(n1, n2);
    while(n3 != NULL) {
        printf("%d", n3->val);
        n3 = n3->next;
    }
    return 0;
}