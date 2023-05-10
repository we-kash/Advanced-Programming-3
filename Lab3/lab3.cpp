#include <bits/stdc++.h> 
using namespace std; 
enum Color {RED, BLACK};
struct Node{
int data;
bool color;
Node *left, *right, *parent;
Node(int data)
{
    this->data = data;
    left = NULL, right = NULL, parent = NULL;
    color = RED;
}
}
;
void left_rotation(Node *&root, Node *&x)
{
    Node *y = x->right;
    x->right = y->left;
    if (x->right != NULL)
    {
        x->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL)
    {
        root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}
void right_roation(Node *&root, Node *&x)
{
    Node *y = x->left;
    x->left = y->right;
    if (x->left != NULL)
    {
        x->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL)
    {
        root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
}
void case_1(Node *&parent, Node *&grandparent, Node *&y, Node *&z)
{
    grandparent->color = RED;
    parent->color = BLACK;
    y->color = BLACK;
    z = grandparent;
}
void insert_fixup(Node *&root, Node *&z)
{
    Node *parent = NULL, *y = NULL, *grandparent = NULL;
    while ((z != root) && (z->color != BLACK) && (z->parent->color == RED))
    {
        parent = z->parent;
        grandparent = z->parent->parent;
        if (parent == grandparent->left)
        {
            y = grandparent->right;
            if (y != NULL && y->color == RED)
            {
                case_1(parent, grandparent, y, z);
            }
            else
            {
                if (z == parent->right)
                {
                    left_rotation(root, parent);
                    z = parent;
                    parent = z->parent;
                }
                right_roation(root, grandparent);
                swap(parent->color, grandparent->color);
                z = parent;
            }
        }
        else
        {
            Node *y = grandparent->left;
            if ((y != NULL) && (y->color == RED))
            {
                case_1(parent, grandparent, y, z);
            }
            else
            {
                if (z == parent->left)
                {
                    right_roation(root, parent);
                    z = parent;
                    parent = z->parent;
                }
                left_rotation(root, grandparent);
                swap(parent->color, grandparent->color);
                z = parent;
            }
        }
    }
