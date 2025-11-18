#include<iostream>
using namespace std;

class ListNode{
    public : 
        int data;
        ListNode* next;

        ListNode(int val){
            data = val;
            next = NULL;
        }
};

class Solution{
    public :
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
            if(list1 == NULL || list2 == NULL){
                if(list1 == NULL){
                    return list2;
                }
                else{
                    return list1;
                }
            }

            if(list1->data <= list2->data){
                list1->next = mergeTwoLists(list1->next,list2);
                return list1;
            }

            else{
                list2->next = mergeTwoLists(list1,list2->next);
                return list2;
            }
        }
};

int main(){
    // List 1
    ListNode* List1 = new ListNode(1);
    List1->next = new ListNode(2);
    List1->next->next = new ListNode(4);

    // List 2
    ListNode* List2 = new ListNode(1);
    List2->next = new ListNode(3);
    List2->next->next = new ListNode(4);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(List1, List2);
    cout << "Merged Sorted List: ";
    while(mergedList != NULL){
        cout << mergedList->data << " ";
        mergedList = mergedList->next;
    }
}