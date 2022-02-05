#include<iostream>
using namespace std;

//=========================STACK USING ARRAY===========================//

// class stack{
//     int top;
//     int *arr;
//     int size;
//     public:
//     stack(){
//         //cin>>size;
//         size=100;
//         top = -1;
//         arr= new int [100]{0};
//     }
//     void push(int data){
//         if(top!=size-1){
//             arr[++top]=data;
//         }
//         else
//         cout<<" stack overflow";
//     }

//     int pop(){
//         if(top !=-1){
//             return arr[top--];
//         }
//         else
//         cout<<" stack undertflow";
//     }

//     int peak(){
//         return arr[top];
//     }
//     int isempty(){
//         return top==-1;
//     }
//     int isfull(){
//         return top==size-1;
//     }
//     void print(){
//         for(int i=top;i>=0;i--){
//             cout<<arr[i]<<" ";
//         }
//     }
// };

//=========================STACK USING SLL===========================//



class node{
    public:
    int data;
    node *next;
    node(){
        next=0;
    }
    node(int data,node *ptr=0){
        next=ptr;
        this->data=data;
    }
};

class stack{
    node *top;
    public:
    stack(){
        top=0;
    }
    void push(int data){
        if (top==0)
        {
            top = new node(data);
        }
        else{
            node *temp= new node(data,top);
            top=temp;
        }
    }
    int pop(){
        node *temp= top;
        top = top->next;
        int x= temp->data;
        delete temp;
        return x;
    }
    bool peak(){
        return top->data;
    }
    void print(){
        for(node *temp=top;temp!=0;temp=temp->next){
            cout<<temp->data<<" ";
        }
    }
    bool empty(){
        return top==0;
    }

void sortedInsert(int x)
{
    if (empty() || x > peak()) {
        push(x);
        return;
    }
    int temp = pop();
    sortedInsert(x);
    push(temp);
}
void sortStack()
{
    if (!empty()) {
        int x = pop();
        sortStack();
        sortedInsert(x);
    }
    }
   

int insert_at_bottom(int x)
{
    if(empty())
    push(x);
    else
    {
        int a = pop();
        insert_at_bottom(x);
        push(a);
    }
}

int reverse()
{
    if(!empty())
    {
        int x = pop();
        reverse();
        insert_at_bottom(x);
    }
}
};


//====================/* C++ implementation to convert/=========================
//======================infix expression to postfix*/=========================



//Function to return precedence of operators
///================STEPS=======================
//1.Write precedence function
//2.Check for A to Z or 0 to 9
//3.Check for ( if present push
//4.check for ) if present check till ( and keep poping
//5.if operator check precedence of intacter is less 
//  then top if yes pop and append with string
//6. push charachter

// int prec(char c) {
// 	if(c == '^')
// 		return 3;
// 	else if(c == '/' || c=='*')
// 		return 2;
// 	else if(c == '+' || c == '-')
// 		return 1;
// 	else
// 		return -1;
// }

// void infixToPostfix(string s) {
// 	stack st; 
// 	string result;
// 	for(char i = 0; i < s.length(); i++) {
		
//         char c = s[i];
// 		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
// 		result = result + c;

// 		else if(c == '(')
// 			st.push('(');

// 		else if(c == ')') {
// 			while(st.peak() != '(')
// 			{
// 				result += st.peak();
// 				st.pop();
// 			}
// 			st.pop();
// 		}

// 		//If an operator is scanned
// 		else {
// 			while(!st.isempty() && prec(s[i]) <= prec(st.peak())) {
// 				result += st.pop();
// 			}
// 			st.push(c);
// 		}
// 	}

// 	// Pop all the remaining elements from the stack
// 	while(!st.isempty()) {
// 		result += st.peak();
// 		st.pop();
// 	}

// 	cout << result << endl;
// }

//====================/* C++ implementation to convert/=========================
//======================prefix expression to infix*/=========================

// 1.Read the Prefix expression in reverse order (from right to left)
// 2.If the symbol is an operand, then push it onto the Stack
// 3.If the symbol is an operator, then pop two operands from the Stack 
// 4.Create a string by concatenating the two operands and the operator between them. 
// 5.string = (operand1 + operator + operand2) 
// 6.And push the resultant string back to Stack
// 7.Repeat the above steps until end of Prefix expression.

// bool isOperator(char x) {
//   switch (x) {
//   case '+':
//   case '-':
//   case '/':
//   case '*':
//     return true;
//   }
//   return false;
// }

// string preToInfix(string exp) {
//   stack s;
//   for (int i = exp.size() - 1; i >= 0; i--) {
//     if (isOperator(exp[i])) {
//       string op1 =s.pop();  
//       string op2 = s.pop();   
//       string temp = "(" + op1 + exp[i] + op2 + ")";
//       s.push(temp);
//     }
//     else{
//     s.push(string(1,exp[i]));}
//   }
//   return s.peak();
// }
 
// // Driver Code
// int main() {
//   string pre_exp = "*-A/BC-/AKL";
//   cout << "Infix : " << preToInfix(pre_exp);
//   return 0;
// }

//====================/* C++ implementation to convert/=========================
//======================prefix expression to postfix*/=========================

// 1.Read the Prefix expression in reverse order (from right to left)
// 2.If the symbol is an operand, then push it onto the Stack
// 3.If the symbol is an operator, then pop two operands from the Stack 
// 4.Create a string by concatenating the two operands and the operator between them. 
// 5.string = operand1 + operand2 + operator 
// 6.And push the resultant string back to Stack
// 7.Repeat the above steps until end of Prefix expression.

// bool isOperator(char x) {
//   switch (x) {
//   case '+':
//   case '-':
//   case '/':
//   case '*':
//     return true;
//   }
//   return false;
// }

// string preToInfix(string exp) {
//   stack s;
//   for (int i = exp.size() - 1; i >= 0; i--) {
//     if (isOperator(exp[i])) {
//       string op1 =s.pop();  
//       string op2 = s.pop();   
//       string temp = op1 + op2 + exp[i];
//       s.push(temp);
//     }
//     else{
//     s.push(string(1,exp[i]));}
//   }
//   return s.peak();
// }
 
// // Driver Code
// int main() {
//   string pre_exp = "*-A/BC-/AKL";
//   cout << "Infix : " << preToInfix(pre_exp);
//   return 0;
// }

//====================/* C++ implementation to convert/=========================
//======================postfix expression to prefix*/=========================

// 1.Read the Prefix expression in reverse order (from right to left)
// 2.If the symbol is an operand, then push it onto the Stack
// 3.If the symbol is an operator, then pop two operands from the Stack 
// 4.Create a string by concatenating the two operands and the operator between them. 
// 5.string = operand1 + operand2 + operator 
// 6.And push the resultant string back to Stack
// 7.Repeat the above steps until end of Prefix expression.

// bool isOperator(char x) {
//   switch (x) {
//   case '+':
//   case '-':
//   case '/':
//   case '*':
//     return true;
//   }
//   return false;
// }

// string preToInfix(string exp) {
//   stack s;
//   for (int i = exp.size() - 1; i >= 0; i--) {
//     if (isOperator(exp[i])) {
//       string op1 =s.pop();  
//       string op2 = s.pop();   
//       string temp =  exp[i] + op1 + op2 ;
//       s.push(temp);
//     }
//     else{
//     s.push(string(1,exp[i]));}
//   }
//   return s.peak();
// }
 
// // Driver Code
// int main() {
//   string pre_exp = "*-A/BC-/AKL";
//   cout << "Infix : " << preToInfix(pre_exp);
//   return 0;
// }

//=================================// A Stack based C++ program to find next
//==================================// greater element for all array elements



// void print(int arr[], int n)
// {
// 	stack s;
//     s.push(arr[0]);
//     for (int i = 1; i < n; i++)
// 	{
// 		while (!s.isempty()&& s.peak() < arr[i])
// 		{
// 			cout << s.pop()<< " --> " << arr[i] << endl;
// 		}
// 		s.push(arr[i]);
// 	}
// 	while (s.isempty() == false) {
// 		cout << s.pop() << " --> " << -1 << endl;
// 	}
// }

// int main()
// {
// 	int arr[] = { 11, 3, 4, 2 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	print(arr, n);
// 	return 0;
// }

int main() {
  stack s1;
  s1.push(0);
  s1.push(9);
  s1.push(3);
  s1.push(2);
  s1.push(6);
  s1.reverse();
  s1.print();
  return 0;
}