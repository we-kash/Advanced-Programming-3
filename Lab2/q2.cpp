bst *del(bst *root, int x)
{
    if (root == NULL)
        return root;
    else if (x < root->data)
        root->lc = del(root->lc, x);
    else if (x > root->data)
        root->rc = del(root->rc, x);

    else
    {

        if (root->lc == NULL & root->rc == NULL)
        {

            delete root;
            root = NULL;
        }
        else if (root->lc == NULL)
        {
            bst *temp = root;
            root = root->rc;
            delete temp;
        }
        else if (root->rc == NULL)
        {
        }
        else
        {
        }
    }

    bst *temp = root;
    root = root->lc;
    delete temp;

    bst *temp = root;
    while (temp->lc != NULL)
        temp = temp->lc;
    root->data = temp->data;
    root->rc = del(root->rc, temp->data);

    return root;
}