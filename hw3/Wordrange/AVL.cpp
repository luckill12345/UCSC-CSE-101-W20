
#include "AVL.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

AVL::AVL()
{
    root = NULL;
}

int height(Node *current)
{
    if (current == NULL)
        return 0;
    return current->height;
}

int balanceFactor(Node *current)
{
    if (current == NULL)
        return 0;
    return height(current->left) - height(current->right);
}

int size(Node *current)
{
    return current->ldesc + current->rdesc + 1;
}

Node *rr_rotation(Node *current) //left rotate
{
    Node *temp = current->right;
    current->right = temp->left;
    temp->left = current;

    current->height = max(height(current->left), height(current->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;

    current->rdesc = temp->ldesc;
    temp->ldesc = size(current);

    return temp;
}
Node *ll_rotation(Node *current) //right rotate
{
    Node *temp = current->left;
    current->left = temp->right;
    temp->right = current;

    current->height = max(height(current->left), height(current->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;

    current->ldesc = temp->rdesc;
    temp->rdesc = size(current);

    return temp;
}
Node *rl_rotation(Node *current)
{
    Node *temp = current->right;
    current->right = ::ll_rotation(temp);
    return ::rr_rotation(current);
}
Node *lr_rotation(Node *current)
{
    Node *temp = current->left;
    current->left = ::rr_rotation(temp);
    return ::ll_rotation(current);
}

Node *balance(Node *current)
{
    int balanceFactor = ::balanceFactor(current);
    if (balanceFactor > 1)
    {
        if (::balanceFactor(current->left) > 0)
            current = ::ll_rotation(current);
        else
            current = ::lr_rotation(current);
    }
    else if (balanceFactor < -1)
    {
        if (::balanceFactor(current->right) > 0)
            current = ::rl_rotation(current);
        else
            current = ::rr_rotation(current);
    }
    return current;
}

bool find(Node *current, string val)
{
    if (current == NULL)
        return 0;
    if (current->key == val)
        return 1;
    if (val < current->key)
        return find(current->left, val);
    else
        return find(current->right, val);
}

Node *insert(Node *current, string val)
{
    if (current == NULL)
        return new Node(val);
    if (val < current->key)
    {
        current->left = ::insert(current->left, val);
        current->ldesc++;
    }
    else
    {
        current->right = ::insert(current->right, val);
        current->rdesc++;
    }
    current->height = 1 + max(height(current->left), height(current->right));
    current = ::balance(current);
    return current;
}

void AVL::insert(string val)
{
    if (!::find(root, val))
        root = ::insert(root, val);
    else
        cout << val << " already exists..." << endl;
}

void printLvl(Node *current, int lvl)
{
    if (current == NULL)
    {
        cout << "NULL\t";
        return;
    }
    if (lvl == 1)
        cout << current->key << "\t";
    else if (lvl > 1)
    {
        printLvl(current->left, lvl - 1);
        printLvl(current->right, lvl - 1);
    }
}

void inorder(Node *current)
{
    if (current == NULL)
        return;
    inorder(current->left);
    cout << current->key << " ";
    inorder(current->right);
}
void preorder(Node *current)
{
    if (current == NULL)
        return;
    cout << current->key << ":" << current->height << " ";
    preorder(current->left);
    preorder(current->right);
}
void postorder(Node *current)
{
    if (current == NULL)
        return;
    postorder(current->left);
    postorder(current->right);
    cout << current->key << " ";
}

void print2D(Node *root, int space)
{
    int spcInc = 5;
    if (root == NULL)
    {
        space += spcInc;
        for (int i = spcInc; i < space; i++)
            cout << " ";
        cout << "NULL\n";
        return;
    }
    space += spcInc;
    print2D(root->right, space);
    for (int i = spcInc; i < space; i++)
        cout << " ";
    cout << root->key << " Total Desc: " << ::size(root) - 1 << " Left Desc: " << root->ldesc << " Right Desc: " << root->rdesc << "\n";
    print2D(root->left, space);
}

void AVL::printTree()
{
    int height = ::height(root);
    cout << "Total Num Nodes: " << ::size(root) << endl;
    for (int i = 1; i <= height; i++)
    {
        cout << "Level " << i << endl;
        printLvl(root, i);
        cout << endl;
    }

    cout << "InOrder: ";
    inorder(root);
    cout << endl;

    cout << "PreOrder: ";
    preorder(root);
    cout << endl;

    cout << "PostOrder: ";
    postorder(root);
    cout << endl;

    cout << "2DUtil: \n"
         << endl;
    print2D(root, 0);
    cout << endl;
}

Node *lca(Node *current, string left, string right)
{
    if (current == NULL)
        return current;

    if (left.compare(current->key) > 0 && right.compare(current->key) > 0)
        return lca(current->right, left, right);

    if (left.compare(current->key) < 0 && right.compare(current->key) < 0)
        return lca(current->left, left, right);

    return current;
}

int nodesInRange(Node *current, string left, string right)
{
    if (current == NULL)
        return 0;

    if (left.compare(current->key) == 0 && right.compare(current->key) == 0)
        return 1;

    if (left.compare(current->key) <= 0 && right.compare(current->key) >= 0)
        return nodesInRange(current->left, left, right) + nodesInRange(current->right, left, right) + 1;

    else if (left.compare(current->key) > 0)
        return nodesInRange(current->right, left, right);
    else
        return nodesInRange(current->left, left, right);
}

int countGrtr(Node *current, string left)
{
    int ttl = 0;
    while (current != NULL)
    {
        int desc = (current->right != NULL) ? current->rdesc : 0;
        if (current->key > left)
        {
            ttl += desc + 1;
            current = current->left;
        }
        else if (current->key < left)
            current = current->right;
        else
        {
            ttl += desc + 1;
            break;
        }
    }
    return ttl;
}

int countLssr(Node *current, string right)
{
    int ttl = 0;
    while (current != NULL)
    {
        int desc = (current->left != NULL) ? current->ldesc : 0;
        if (current->key < right)
        {
            ttl += desc + 1;
            current = current->right;
        }
        else if (current->key > right)
            current = current->left;
        else
        {
            ttl += desc + 1;
            break;
        }
    }
    return ttl;
}

int range2(Node *current, string left, string right)
{
    return countLssr(current->right, right) + countGrtr(current->left, left) + 1;
}

int AVL::range(string left, string right)
{
    Node *lca = ::lca(root, left, right);
    if (lca == NULL)
        return 0;
    else
        return ::range2(lca, left, right);
}