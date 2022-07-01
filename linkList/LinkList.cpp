#include "Node.cpp"
#include <iostream>
#include <string>
using namespace std;

class LinkList
{
	private:
		//first Node
		Node *head;
		//last Node
		Node *tail;
		int counter = 0;
	public:
		int Count()
		{
			return counter;
		}
		
		Node begin()
		{
			return *head;
		}

		Node end()
		{
			return *tail;
		}

		void DebugLog()
		{
			Node *currentNode = head;
			int c = 0;
			
			string data = "["; 
			//loop all node and get values (start from head)
			while(currentNode != nullptr)
			{
				data += to_string(currentNode->value) + ",";
				currentNode = currentNode->Next();
				c++;
			}
			
			if(c > 0)
				data.pop_back();
			data +="]";
			cout << data << endl;
		}

		void AddElement(int value)
		{
			
			// first Element
			if(counter == 0)
			{
				head = new Node(value);
				tail = head;
				counter +=1;
				return;
			}
			Node *newNode = new Node(value);
			tail->setNext(newNode);
			tail = newNode;
			counter += 1; 
		}

		// store All value in Array
		int *GetValues()
		{
			int *Values=  new int[counter];
			Node *currentNode = head;
			int c = 0;
			
			//loop all node and get values (start from head)
			while(currentNode != nullptr)
			{
				Values[c] =  currentNode->value;
				currentNode = currentNode->Next();
				c++;
			}

			return Values;
		}
};
