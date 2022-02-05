# include <iostream>
# include <queue>
using namespace std;

// # define MAXSIZE 10
// int i, j, k, temp, TEMP;

// class LinearQueueUsingArray
// {
// 	public:
//     	int array[MAXSIZE];
//     	int rear;
//     	int front;
  
//     LinearQueueUsingArray()
//     	{
//     	    rear = -1;
// 			front = -1;
//     	}
    
// 	void Enqueue(int data){
//             if(rear == MAXSIZE - 1) {
//             cout << "Queue Overflow!" << endl;
//             return;}
//             if(front == -1 && rear == -1)										 
//             {
//                 front++;			   									  	
//                 array[++rear] = data; 	}
//             else
//             {
//                 array[++rear] = data; 
//             }
// }
        
// 	void Dequeue(void){
// 	if (front == -1 || front > rear) /* If Queue is Empty (also when front moves ahead of rear) */
//     {  
//         cout << "Queue Underflow!" << endl;  
//     }      
//     if(front == rear)
//     {  
//         front = -1;
// 		rear = -1;
// 	}
//     else
//     {
//         front++;
//     }
// }
// 	bool IsEmpty(void){
//             return (front == -1 && rear == -1);
//         }

// 	int Peek(void){
// 	return array[MAXSIZE - 1];
// }
// };



// class Node
// {
// 	public:
//     	int data;
    
// 		Node* next;
    	
//     	Node()
//     	{
//     		data = 0;
//     	    next = NULL;
// 		}
    	
// 		Node(int DATA, Node* ptr=0)
//     	{
//     	    data = DATA;
//     	    next = ptr;
//     	}
// };
  
// class LinearQueueUsingLinkedList
// {
// 	public:
//     	Node* front; 
// 		Node* rear;
    	
//     	LinearQueueUsingLinkedList()
//     	{
//     	    front = NULL;
// 			rear = NULL;
//     	}
    	
//     void Enqueue(int data){
//         Node* nptr = new Node(data);
//         if (front == NULL) 
// 		{
//             front = rear = nptr;
//             return;
//         }
// 		else
// 		{
// 			rear -> next = nptr; 
//     		rear = nptr;			   		
// 		}
//     }

//     void Dequeue(){
//     if (front == NULL){
//     	return;}
// 	else
// 	{
// 		Node* nptr = front;				
// 		front = nptr -> next; 
// 		delete (nptr);
// 		if(nptr -> next == NULL) 
//     	{
//     		rear = NULL;
// 		}
// 	}}
    
//     int Peek(void){
//             return front->data;
//     }
// };


class Queue
{
    int size;
    int front;
    int rear;
    int *Q;
    public:
    Queue(){
            size = 10;
            front = rear = 0;
            Q = new int[10]{};
        }

    void enqueue(int x){
        if((rear+1)%size==front)
            cout<<"Queue is Full";
        else
        {
        rear=(rear+1)%size;
        Q[rear]=x;
        }
    }

    int dequeue(){
    int x=-1;
    if(front==rear)
        cout<<"Queue is Empty\n";
    else{
        front=(front+1)%size;
         x=Q[front];
    }
    return x;
    }

void Display()
{
 int i=front+1;
 
 do
 {
 
 cout<<Q[i]<<" ";
 i=(i+1)%size;
 }while(i!=(rear+1)%size);
}};
int main()
{
 Queue q;
 q.enqueue(18);
 q.enqueue(10);                           
 q.enqueue(20);
 q.enqueue(30);
 q.enqueue(40);
 q.enqueue(50);
 q.enqueue(60);
 q.Display();
 return 0;}
