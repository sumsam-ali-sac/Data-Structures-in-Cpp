#include<iostream>
using namespace std;
  class node {
        public:
        int data;
        node* lchild;
        node* rchild;
        	node()
    	{
    		data = 0;
    	    lchild = NULL;
			rchild = NULL;
		} 
    	   node(int data,node *ptr1=0,node *ptr2=0)
    	{
    		this->data = data;
    	    lchild = ptr1;
            rchild = ptr2;
		}};
    
class BST {
    node* root;
    
    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node(x);
        }
        else if(x < t->data)
            t->lchild = insert(x, t->lchild);
        else if(x > t->data)
            t->rchild = insert(x, t->rchild);
        return t;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->lchild == NULL)
            return t;
        else
            return findMin(t->lchild);
    }

    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->rchild == NULL)
            return t;
        else
            return findMax(t->rchild);
    }

    node* find(node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->lchild, x);
        else if(x > t->data)
            return find(t->rchild, x);
        else
            return t;
    }

    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->lchild);
        cout << t->data << " ";
        inorder(t->rchild);
    }

    node* remove(int x, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->lchild = remove(x, t->lchild);
        else if(x > t->data)
            t->rchild = remove(x, t->rchild);

        //if found check if both lchild and rchild cild exist
        //find min node in right subtree
        //replace node's data with minimum data
        //remove min node
        else if(t->lchild && t->rchild)
        {
            temp = findMin(t->rchild);
            t->data = temp->data;
            t->rchild = remove(t->data, t->rchild);
        }
        else
        {
            temp = t;
            if(t->lchild == NULL)
                t = t->rchild;
            else if(t->rchild == NULL)
                t = t->lchild;
            delete temp;
        }
  
        return t;
        }
     node *findLCAUtil(node* p, int n1, int n2, bool &v1, bool &v2)
    {
        if (p == NULL) return NULL;
        if (p->data == n1)
        {
            v1 = true;
            return p;
        }
        if (p->data == n2)
        {
            v2 = true;
            return p;
        }
        node *lchild_lca = findLCAUtil(p->lchild, n1, n2, v1, v2);
        node *rchild_lca = findLCAUtil(p->rchild, n1, n2, v1, v2);

        if (lchild_lca && rchild_lca) return p;
        return (lchild_lca != NULL)? lchild_lca: rchild_lca;
    }

    bool findnode(node *p, int k)
    {
        if (p == NULL)
            return false;
        if (p->data == k || findnode(p->lchild, k) || findnode(p->rchild, k))
            return true;
        return false;
    }
    node *findLCA(node *p, int n1, int n2)
    {
        bool v1 = false, v2 = false;
        node *lca = findLCAUtil(p, n1, n2, v1, v2);
        if (v1 && v2 || v1 && findnode(lca, n2) || v2 && findnode(lca, n1))
            return lca;
        return NULL;
    }


    int size(node* p)
    {
        if (p == nullptr) {
            return 0;
        }
        return size(p->lchild) + 1 + size(p->rchild);
    }
    bool isBST(node* p, int min, int max)
    {
        if (p == nullptr) {
            return true;
        }
    
        if (p->data < min || p->data > max) {
            return false;
        }
        return isBST(p->lchild, min, p->data) && isBST(p->rchild, p->data, max);
    }
    
    int findLargestBST(node* p)
    {
        if (isBST(p, INT_MIN, INT_MAX)) {
            return size(p);
        }
        return max(findLargestBST(p->lchild), findLargestBST(p->rchild));
    }
  


    public:
        BST() {
            root = NULL;
        }

        ~BST() {
            root = makeEmpty(root);
        }
        node* makeEmpty(node* t) {
            if(t == NULL)
                return NULL;
            {
                makeEmpty(t->lchild);
                makeEmpty(t->rchild);
                delete t;
            }
            return NULL;
        }

        void insert(int x) {
            root = insert(x, root);
        }
        void createFromPreorder(int pre[]){
                int size = 7;
                int i=0;
                while(i<size){
                    insert(pre[i++]);
                }
                display();
            }
        void remove(int x) {
            root = remove(x, root);
        }

        void display() {
            inorder(root);
            cout << endl;
        }

        void search(int x) {
            root = find(root, x);
        }
};

int main() {
    BST t;
    int arr[]={ 15, 10, 8, 12, 20, 16, 25 };
    t.createFromPreorder(arr);
    // t.insert(20);
    // t.insert(25);
    // t.insert(15);
    // t.insert(10);
    // t.insert(30);
    // t.display();
    // t.remove(20);
    // t.display();
    // t.remove(25);
    // t.display();
    // t.remove(30);
    // t.display();
    return 0; 
}