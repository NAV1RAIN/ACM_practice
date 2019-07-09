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
        ListNode* ans = l1;
        bool jl1, jl2;
        jl1 = jl2 = true;
        int jw = 0;
        while(jl1 || jl2) {
            if(jl1 && jl2) l1->val += l2->val+jw;
            else if(jl1) l1->val += jw;
            else if(jl2) l2->val += jw;
            if(jl1 && l1->val/10 != 0) {
                jw = 1;
                l1->val %= 10;
            } else if(jl2 && l2->val/10 != 0) {
                jw = 1;
                l2->val %= 10;
            } else {
                jw = 0;
            }
            
            if(l1->next == NULL) jl1 = false;
            else l1 = l1->next;
            if(l2->next == NULL) jl2 = false;
            else if(jl1) l2 = l2->next;
            else {
                l1->next = l2->next;
                l1 = l2->next;
                l2 = l2->next;
            }
            // if(!jl1 && !jl2 && jw != 0) {
            //     ListNode* tt = new ListNode(jw);
            //     l1->next = tt;
            // }
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
    int hh = 0;
    ListNode* n3 = Solution().addTwoNumbers(n1, n2);
    while(n3 != NULL && hh++ < 100) {
        printf("%d", n3->val);
        n3 = n3->next;
    }
    return 0;
}