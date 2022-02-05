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

class BST
{
   
    node* root;

    void makeEmpty(node* p)
    {
        if(p == NULL)
            return;
        makeEmpty(p->lchild);
        makeEmpty(p->rchild);
        delete p;
    }

    node* insert(int x, node* p)
    {
        if(p == NULL)
        {
            p = new node(x);
        }
        else if(x < p->data)
        {
            p->lchild = insert(x, p->lchild);
        }
        else if(x > p->data)
        {
            p->rchild = insert(x, p->rchild);     
        }
            int balancefactor = height(p->lchild) - height(p->rchild);
            if(balancefactor == 2)
            {
                if(x < p->lchild->data)
                    p = RightRotate(p);
                else
                    p = LeftRightRotate(p);
            }
            if(balancefactor == -2)
            {
                if(x > p->rchild->data)
                    p = LeftRotate(p);
                else
                    p = RightLeftRotate(p);
            }
        return p;
    }

    node* RightRotate(node* &p)
    {
        node* temp = p->lchild;
        p->lchild = temp->rchild;
        temp->rchild = p;
         return temp;
    }

    node* LeftRotate(node* &p)
    {
        node* temp = p->rchild;
        p->rchild = temp->lchild;
        temp->lchild = p;
         return temp;
    }

    node* RightLeftRotate(node* &p)
    {
        p->rchild = RightRotate(p->rchild);
        return LeftRotate(p);
    }

    node* LeftRightRotate(node* &p)
    {
        p->lchild = LeftRotate(p->lchild);
        return RightRotate(p);
    }

    node* findMin(node* p)
    {
        if(p == NULL)
            return NULL;
        else if(p->lchild == NULL)
            return p;
        else
            return findMin(p->lchild);
    }

    node* findMax(node* p)
    {
        if(p == NULL)
            return NULL;
        else if(p->rchild == NULL)
            return p;
        else
            return findMax(p->rchild);
    }

    node* remove(int x, node* p)
    {
        node* temp;

        // Element not found
        if(p == NULL)
            return NULL;

        // Searching for element
        else if(x < p->data)
            p->lchild = remove(x, p->lchild);
        else if(x > p->data)
            p->rchild = remove(x, p->rchild);

        // Element found
        // With 2 children
        else if(p->lchild && p->rchild)
        {
            temp = findMin(p->rchild);
            p->data = temp->data;
            p->rchild = remove(p->data, p->rchild);
        }
        // With one or zero child
        else
        {
            temp = p;
            if(p->lchild == NULL)
                p = p->rchild;
            else if(p->rchild == NULL)
                p = p->lchild;
            delete temp;
        }
        if(p == NULL)
            return p;


        // If node is unbalanced
        // If lchild node is deleted, rchild case
        int balancefactor=height(p->lchild) - height(p->rchild);
        if(balancefactor == 2)
        {
            // rchild rchild case
            if(height(p->lchild->lchild) - height(p->lchild->rchild) == 1)
                return LeftRotate(p);
            // rchild lchild case
            else
                return RightLeftRotate(p);
        }
        // If rchild node is deleted, lchild case
        else if(balancefactor == -2)
        {
            // lchild lchild case
            if(height(p->rchild->lchild)-height(p->rchild->rchild)   == -1)
                return RightRotate(p);
            // lchild rchild case
            else
                return  LeftRightRotate(p);
        }
        return p;
    }


    int height(node* root)
    {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(height(root->lchild), height(root->rchild));
    }

    int getBalance(node* p)
    {
        if(p == NULL)
            return 0;
        else
            return height(p->lchild) - height(p->rchild);
    }

    void inorder(node* p)
    {
        if(p == NULL)
            return;
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    BST p;
    p.insert(20);
    p.insert(25);
    p.insert(15);
    p.insert(10);
    p.insert(30);
    p.insert(5);
    p.insert(35);
    p.insert(67);
    p.insert(43);
    p.insert(21);
    p.insert(10);
    p.insert(89);
    p.insert(38);
    p.insert(69);
    p.display();
    p.remove(5);
    p.remove(35);
    p.remove(65);
    p.remove(89);
    p.remove(43);
    p.remove(88);
    p.remove(20);
    p.remove(38);
    p.display();
}