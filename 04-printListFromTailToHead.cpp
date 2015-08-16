/********************************
 *@file:
 *@author: Pan HU
 *@data:
 *@version: 0.1
 *@describe:
 ********************************/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
          val(x), next(NULL) {
    }
};

vector<int> printListFromTailToHead(struct ListNode* head)
{

    if(head == NULL)
    {
        vector<int> vec;
        return vec;
    }

    struct ListNode *pNode = head;
    vector<int>::size_type sizeList(0);
    while(pNode != NULL)
    {
        ++sizeList;
        pNode = pNode->next;
    }

    pNode = head;
    vector<int> ivec(sizeList,0);
    while(pNode != NULL)
    {
        ivec[--sizeList] = pNode->val;
        pNode = pNode->next;
    }

    return ivec;

}

int main2()
{
    struct ListNode* head =NULL;// new ListNode(1);
    struct ListNode* node = head;
//    for(int i=2; i <= 10; ++i)
//    {
//        node->next = new ListNode(i);
//        node = node->next;
//    }
    vector<int> vec(0,0);
    vec = printListFromTailToHead(head);
    for(vector<int>::size_type i = 0; i < vec.size(); ++i)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;

    return 0;
}
