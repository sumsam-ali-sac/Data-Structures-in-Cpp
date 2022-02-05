#include<math.h>
#include<iostream>

using namespace std;

float A = 0.618033;

class HashNode {
public:
	int value;
	int key;

	HashNode(int key, int value)
	{
		this->value = value;
		this->key = key;
	}
};


class HashMap {
	HashNode ** arr;
	int capacity;
	int size;
	HashNode * dummy;

	public:
	HashMap()
	{
		capacity = 20;
		size = 0;
		arr = new HashNode *[capacity];
		for (int i = 0; i < capacity; i++)
			arr[i] = NULL;
		dummy = new HashNode (-1, -1);
	}
	
	//	Mid Square Value Method
	//In Mid square, the key is squared and the address is selected from the middle of the
	//result. 
	int HashFuncms(int a) {
      	
   		long int x=a*a;
	
		   		cout <<x;
				if(x>99 && x <1000){
				cout <<"Key against the value is "<<(x / 10) % 10<<endl;
				return (x / 10) % 10 ;
			
				}
				
			else 	if(x>999 && x <100000){
					cout <<"Key against the value is "<<(x / 10) % 100 <<endl;
				return  (x / 10) % 100 ;
				
				}
				
			else	if(x>9999 && x <100000){
				cout <<"Key against the value is "<<(x / 10) % 100<<endl;
				return (x / 10) % 1000 ;
		
				}
      
      }
	//multiplication
	//	k is the key and A can be any constant value between 0 and 1. Both k and A are
	//multiplied and their fractional part is separated. This is then multiplied with n to get the
	//hash value.
	//	h(k) = floor( size( k A mod 1 ) )
    int HashFuncm(int key) {
      	cout <<"Key against the value is " <<floor (1000 * fmod((key*A),1))<<endl;
           return	floor (1000 * fmod((key*A),1));
    }
    
	int hashCode(int key)
	{
		return key % capacity;
	}

	void insertNode(int key, int value)
	{
		HashNode * temp = new HashNode (key, value);

		int hashIndex = hashCode(key);
		//linear probing
		while (arr[hashIndex] != NULL&& arr[hashIndex]->key != key&& arr[hashIndex]->key != -1) {
			hashIndex++;
			hashIndex %= capacity;
		}

		if (arr[hashIndex] == NULL|| arr[hashIndex]->key == -1){
		size++;
		arr[hashIndex] = temp;}
	}

	int deleteNode(int key)
	{
		int hashIndex = hashCode(key);

		while (arr[hashIndex] != NULL) {
			if (arr[hashIndex]->key == key) {
				HashNode * temp = arr[hashIndex];

				arr[hashIndex] = dummy;

				size--;
				return temp->value;
			}
			hashIndex++;
			hashIndex %= capacity;
		}

		return -1;
	}

	int get(int key)
	{
		int hashIndex = hashCode(key);
		int counter = 0;

		while (arr[hashIndex] != NULL) { 

			if (counter++ > capacity) 
				return -1;

			if (arr[hashIndex]->key == key)
			return arr[hashIndex]->value;
			hashIndex++;
			hashIndex %= capacity;
		}

		return -1;
	}

	int sizeofMap()
	{
		return size;
	}

	bool isEmpty()
	{
		return size == 0;
	}

	void display()
	{
		for (int i = 0; i < capacity; i++) {
			if (arr[i] != NULL && arr[i]->key != -1)
				cout << "key = " << arr[i]->key
					<< " value = "
					<< arr[i]->value << endl;
		}
	}
};

int main()
{
	HashMap * h = new HashMap ;
	h->insertNode(1, 1);
	h->insertNode(2, 2);
	h->insertNode(2, 3);
	h->display();
	cout << h->sizeofMap() << endl;
	cout << h->deleteNode(2) << endl;
	cout << h->sizeofMap() << endl;
	cout << h->isEmpty() << endl;
	cout << h->get(2);

	return 0;
}

