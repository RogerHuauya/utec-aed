#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Node  {
    int data;
    int priority;
    Node* l, *r;
    Node(int d) {
        this->data = d;
        this->priority = rand() % 100;
        this->l= this->r = nullptr;
    }
    Node(int d, int p) {
        this->data = d;
        this->priority = p;
        this->l= this->r = nullptr;
    }
};

void LRot(Node* &root) {
    Node* R = root->r;
    Node* X = root->r->l;
    R->l = root;
    root->r= X;
    root = R;
}
void RRot(Node* &root) {
    Node* L = root->l;
    Node* Y = root->l->r;
    L->r = root;
    root->l= Y;
    root = L;
}
void insert(Node* &root, int d) {
    if (root == nullptr) {
        root = new Node(d);
        return;
    }
    if (d < root->data) {
        insert(root->l, d);
        if (root->l != nullptr && root->l->priority > root->priority)
            RRot(root);
    } else {
        insert(root->r, d);
        if (root->r!= nullptr && root->r->priority > root->priority)
            LRot(root);
    }
}
bool search(Node* root, int key) {
    if (root == nullptr)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return search(root->l, key);
    return search(root->r, key);
}
void Delete(Node* &root, int key) {
    if (root == nullptr)
        return;
    if (key < root->data)
        Delete(root->l, key);
    else if (key > root->data)
        Delete(root->r, key);
    else {
        if (root->l ==nullptr && root->r == nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->l && root->r) {
            if (root->l->priority < root->r->priority) {
                LRot(root);
                Delete(root->l, key);
            } else {
                RRot(root);
                Delete(root->r, key);
            }
        }

        else {
            Node* child = (root->l)? root->l: root->r;
            Node* curr = root;
            root = child;
            delete curr;
        }
    }
}
void display(Node *root, int space = 0, int height =10) {
    if (root == nullptr)
        return;
    space += height;
    display(root->l, space);
    cout << endl;
    for (int i = height; i < space; i++)
        cout << ' ';
    cout << root->data << "(" << root->priority << ")\n";
    cout << endl;
    display(root->r, space);
}
