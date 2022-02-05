#include<iostream>
using namespace std;
int TABLE_SIZE = 128;

class HashNode
{
    public:
	int key;
	int value;
	HashNode* next;
	HashNode(int k, int v)
	{
	    key = k;
	    value = v;
	    next = NULL;
	}
};

class HashTable
{
    private:
		HashNode** htable;
    public:
	HashTable()
	{
	    htable = new HashNode*[TABLE_SIZE];
	    for (int i = 0; i < TABLE_SIZE; i++)
			htable[i] = NULL;
	}
	
	int HashFunc(int key)
	{
	    return key % TABLE_SIZE;
	}
	
	void Insert(int key, int value)
	{
	    int hash_val = HashFunc(key);
	    HashNode* prev = NULL;
	    HashNode* entry = htable[hash_val];
		HashNode* temp = new HashNode(key, value);
	    while (entry != NULL)
	    {
			entry = entry->next;
	    }
	    entry = temp;
	}
	
	int Search(int key)
	{
	    bool flag = false;
	    int hash_val = HashFunc(key);
	    HashNode* entry = htable[hash_val];
	    while (entry != NULL)
	    {
			if (entry->key == key)
			{
			    cout<<entry->value<<" ";
			    flag = true;
			}
			entry = entry->next;
	    }
	    if (!flag)
			return -1;	
	}
	
	void Remove(int key)
	{
	    int hash_val = HashFunc(key);
	    HashNode* entry = htable[hash_val];
	    HashNode* prev = NULL;
	    if (entry == NULL || entry->key != key)
	    {
			cout<<"No Element found at key "<<key<<endl;
			return;
	    }
	    while (entry->next != NULL)
	    {
			prev = entry;
			entry = entry->next;
	    }
	    if (prev != NULL)
	    {
			prev->next = entry->next;
	    }
	    delete entry;
	    cout<<"Element Deleted"<<endl;
	    // Alternatively, remove node with exactly same key
	}
	
	~HashTable()
	{
	    for (int i = 0; i < TABLE_SIZE; ++i)
	    {
			HashNode* entry = htable[i];
			while (entry != NULL)
			{
			    HashNode* prev = entry;
			    entry = entry->next;
			    delete prev;
			}
	    }
	    delete[] htable;
	}
	
	void reHashing()
	{
	    int OLD_TABLE_SIZE = TABLE_SIZE;
	    TABLE_SIZE = TABLE_SIZE * 2 + 1;
	
	    // allocate new table, use () to value-initialize nullptr entries
	    HashNode** newHashTable = new HashNode*[TABLE_SIZE]();
	
	    //fill in the new temp table with old info
	    for (int i = 0; i < OLD_TABLE_SIZE; ++i)
	    {
	        HashNode *n = htable[i];
	        while (n != nullptr)
	        {
	            HashNode *tmp = n;
	            n = n->next;
				
				//insert at front of SLL
	            HashNode* head = newHashTable[HashFunc(tmp->key)];
	            tmp->next = head;
	            head = tmp;
	        }
	    }
	
	    delete [] htable;
	    htable = newHashTable;
	}
};

int main()
{
    HashTable hash;
    int key, value;
    int choice;
    while (1)
    {
	cout<<"\n----------------------"<<endl;
	cout<<"Operations on Hash Table"<<endl;
	cout<<"\n----------------------"<<endl;
	cout<<"1.Insert element into the table"<<endl;
	cout<<"2.Search element from the key"<<endl;
	cout<<"3.Delete element at a key"<<endl;
	cout<<"4.Exit"<<endl;
	cout<<"Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
	case 1:
	    cout<<"Enter element to be inserted: ";
	    cin>>value;
	    cout<<"Enter key at which element to be inserted: ";
	    cin>>
	    key;
	    hash.Insert(key, value);
	    break;
	case 2:
	    cout<<"Enter key of the element to be searched: ";
	    cin>>key;
	    cout<<"Element at key "<<key<<" : ";
	    if (hash.Search(key) == -1)
	    {
		cout<<"No element found at key "<<key<<endl;
		continue;
	    }
	    break;
	case 3:
	    cout<<"Enter key of the element to be deleted: ";
	    cin>>key;
	    hash.Remove(key);
	    break;
	case 4:
	    exit(1);
	default:
	   cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}
