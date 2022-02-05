
#include<iostream>
#include<math.h>
using namespace std;
class Node
{
	public:
    	int data;
		Node* lchild;
		Node* rchild;
    	
    	Node()
    	{
    		data = 0;
    	    lchild = NULL;
			rchild = NULL;
		} 
    	   Node(int data,Node *ptr1=0,Node *ptr2=0)
    	{
    		this->data = data;
    	    lchild = ptr1;
            rchild = ptr2;
		}
};

class Queue{
	public:
    	int size;
    	int rear;
    	int front;
        Node ** array;
    Queue()
    	{
    	    rear = -1;
			front = -1;
            size = 10;
            array = new Node*[size]{NULL};
    	}
    
	void Enqueue(Node* data){
            if(rear == size - 1) {
            cout << "Queue Overflow!" << endl;
            }
            else
            {
                array[++rear] = data; 
            }
}
        
	Node* Dequeue(void){
    Node * X = NULL;
	if (IsEmpty()) 
    {  
        cout << "Queue Underflow!" << endl;  
    }      
    else
    {
        X = array[++front];
    }
    return X;
}

	bool IsEmpty(void){
            return (front == rear);
    }

	Node* Peek(void){
	return array[front];
}
};

//================================stack for bt
class stack{
    int top;
    Node ** arr;
    int size;
    public:
    stack(){
        //cin>>size;
        size=100;
        top = -1;
        arr= new Node *[100]{NULL};
    }
    void push(Node *data){
        if(top!=size-1){
            arr[++top]=data;
        }
        else
        cout<<" stack overflow";
    }

    Node* pop(){
        if(top !=-1){
            return arr[top--];
        }
        else
        cout<<" stack undertflow";
    }

    Node* peak(){
        return arr[top];
    }
    int isempty(){
        return top==-1;
    }
    int isfull(){
        return top==size-1;
    }
    void print(){
        for(int i=top;i>=0;i--){
            cout<<arr[i]->data<<" ";
        }
    }
};
//================================BINARY TREE-===============================//
class BT
{
private:
    Node * root;
public:
    BT(){
        root = new Node;
    }

    void create(){
        Queue q;
        cout<<"Enter root's value: ";
        cin>>root->data;
        q.Enqueue(root);
        Node *insert,*temp;
        int data;
        while(!q.IsEmpty()){
            temp = q .Dequeue();
            cout<<"Enter value of left child of "<<temp->data<<": ";
            cin>>data;
                if(data!=-1){
                	insert = new Node(data);
                    temp->lchild=insert;
                     q.Enqueue(insert);
                }
            cout<<"Enter value of right child of "<<temp->data<<": ";
            cin>>data;
                if(data!=-1){
                	insert = new Node(data);
                    temp->rchild=insert;
                    q.Enqueue(insert);
                }
        }
    }

    void Preorder(){//VLR
        Preorder(root);
    }

    void Preorder(Node *temp){
    if(temp)
        {
        cout<<temp->data<<"   ";
        Preorder(temp->lchild);
        Preorder(temp->rchild);
        }
    }
    void IPreorder()
    {
        IPreorder(root);
    }
    void IPreorder(Node *p)
    {
        stack st;
        
    while(p || !st.isempty())
    {
        if(p){
            cout<<p->data<<" ";
            st.push(p);
            p=p->lchild;}
        else{
            p=st.pop();
            p=p->rchild;}
    }
    }

    void Inorder(){//LVR
        Inorder(root);
    }

    void Inorder(Node *temp){
    if(temp)
        {
        Inorder(temp->lchild);
        cout<<temp->data<<"   ";
        Inorder(temp->rchild);
        }
    }

    void IInorder()
    {
        IInorder(root);
    }
    void IInorder(Node *p)
    {
        stack st;
        
    while(p || !st.isempty())
    {
        if(p){
            st.push(p);
            p=p->lchild;}
        else{
            p=st.pop();
            cout<<p->data<<" ";
            p=p->rchild;}
    }
    }

    void Postorder(){//LRV
        Postorder(root);
    }

    void Postorder(Node *temp){
    if(temp)
        {
        Postorder(temp->lchild);
        Postorder(temp->rchild);
        cout<<temp->data<<"   ";
        }
    }

    void IPostorder()
    {
        IPostorder(root);
    }

    void IPostorder(Node *p){
        stack st; 	
        Node *q = root; 
        while (p != 0) {
        for ( ; p->lchild != 0; p = p->lchild) 
        st.push(p);
        while (p->rchild == 0 || p->rchild == q) {     
            cout<<p->data<<" ";
            q = p;
            if (st.isempty()) return;
            p = st.pop();}
             st.push(p); 
        p = p->rchild;} 
    }

    void LevelOrder(){
    LevelOrder(root);
    }

    void LevelOrder(Node *p){
        Queue q;
        
        cout<<p->data<<" ";
        q.Enqueue(p);
        
        while(!q.IsEmpty())
        {
            p=q.Dequeue();
            if(p->lchild)
            {
                cout<<p->lchild->data<<" ";
                q.Enqueue(p->lchild);
            }
            if(p->rchild)
            {
                cout<<p->rchild->data<<" ";
                q.Enqueue(p->rchild);
            }
            }
        }

     int factorial(int n){
        if(n > 1)
            return n * factorial(n - 1);
        else
            return 1;
    }

     void NoOfBinaryTressFromNodes(){
         int flag,nodes,trees;
         cout<<"ENTER THE NUMBER OF NODES: ";
         cin>>nodes;
         cout<<"ENTER 1 if NODES are lablled or 0 if they are not: ";
         //====unlabelled
         //2n
         //  C
         //    n
         //-------
         //  n+1
         //labelled
         //2n
         //  C
         //    n
         //------- * n!
         //  n+1
         //
         cin>>flag;
         if (flag){
             trees = ((factorial(2*nodes)/(factorial(nodes)*factorial(nodes)))/(nodes+1))*factorial(nodes);
         }
         else{
                trees = (factorial(2*nodes)/(factorial(nodes)*factorial(nodes)))/(nodes+1);    
         }
         cout<<"THE NUMBER OF TREES THAT CAN BE GENERATED ARE : "<<trees;
         cout<<endl<<"Trees with maximum height will be: "<< pow(2,nodes-1); 
     }

    
    void COUNTNODESANDHEIGHT(){
        int height,nodes;
        cout<<"enter height: ";
        cin>>height;
        cout<<"enter nodes: ";
        cin>>nodes;
        cout<<"min nodes required to reach this height: "<<height+1;
        cout<<"\nmax nodes required to reach this height: "<<pow(2,height+1)-1;
        cout<<"min height reached from these nodes: "<<log(nodes+1)+1;
        cout<<"\nmax height reached from these nodes: "<<nodes-1;

        cout<<"min nodes required to reach this height of a strict BT: "<<2*height+1;
        cout<<"\nmax nodes required to reach this height of a strict BT: "<<pow(2,height+1)-1;
        cout<<"min height reached of a strict BT from these nodes : "<<log(nodes+1)+1;
        cout<<"\nmax height reached of a strict BT from these nodes: "<<((nodes-1)/2);
    }

    void countnodes(){
        countnodes(root);
    }
    int countnodes(Node* p){
        if(p)
        return countnodes(p->lchild)+countnodes(p->rchild)+1;
        return 0;
    }
    
    void height(){
        height(root);
    }
    int height(Node *p){
        int x=0,y=0;
        if(!p)
        return 0;
        x=height(p->lchild);
        y=height(p->rchild);
        if(x>y)
        return x+1;
        else
        return y+1;
        } 

};

int main()
{
 BT t;
 //t.NoOfBinaryTressFromNodes();
  t.create();
//   cout<<"Preorder ";
//   t.IPreorder();
//  cout<<endl;
//  cout<<"Inorder ";
//  t.Inorder();
//  cout<<endl;
//  cout<<"Postorder ";
//  t.IPostorder();
//  cout<<endl<<endl;
 t.LevelOrder();
 return 0;
}
