/*
 * Rebuild a binary tree from its preorder and inorder traversal sequences.
 */

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int TREELEN = 10;

struct NODE
{
    NODE *pLeft;
    NODE *pRight;
    char chValue;
};

void Rebuild(char *pPreOrder, char *pInOrder, int nTreeLen, NODE **pRoot)
{
    if (nTreeLen == 1)
    {
        NODE *pTemp = new NODE;
        pTemp->chValue = *pPreOrder;
        pTemp->pLeft = NULL;
        pTemp->pRight = NULL;
        *pRoot = pTemp;
        return;
    }
    if (nTreeLen == 0)
    {
        *pRoot = NULL;
        return;
    }
    char ch = *pPreOrder;
    char *p = strchr(pInOrder, ch);
    int leftLen = p - pInOrder;
    NODE *pTemp = new NODE;

    pTemp->chValue = ch;
    Rebuild(pPreOrder+1, pInOrder, leftLen, &pTemp->pLeft);
    Rebuild(pPreOrder+1+leftLen, p+1, nTreeLen-1-leftLen, &pTemp->pRight);
    *pRoot = pTemp;
}

/*
 * traverse: Preorder traversal
 */
void traverse(NODE *pRoot)
{
    if (!pRoot) return;

    cout << pRoot->chValue;
    traverse(pRoot->pLeft);
    traverse(pRoot->pRight);
}

int main(int argc, char *argv[])
{
    freopen("in.txt", "r", stdin);

    char szPreOrder[TREELEN], szInOrder[TREELEN];

    cin >> szPreOrder >> szInOrder;
    int len = strlen(szPreOrder);
    NODE *pRoot = NULL;
    Rebuild(szPreOrder, szInOrder, len, &pRoot);
    traverse(pRoot);
    cout << endl;
    return 0;
}
