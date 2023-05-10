#include <bits/stdc++.h> using namespace std; struct bst
{
    int data;
    bst *lc;
    bst *rc;
    bst(int val)
    {
        data = val;
        lc = NULL;
        rc = NULL;
    }
};
void insert(bst **root, int x)
{
    if (*root == NULL)
    {
        *root = new bst(x);
    }
    else if (x < (*root)->data)
    {
        insert(&((*root)->lc), x);
    }
    else if (x > (*root)->data)
    {
        insert(&((*root)->rc), x);
    }
}
int main()
{
    bst *root = NULL;
    insert(root, 25);
    insert(root, 15);
    insert(root, 5);
    insert(root, 20);
    insert(root, 40);
    insert(root, 3);
    insert(root, 6);
    insert(root, 21);
    insert(root, 16);
    return 0;
}