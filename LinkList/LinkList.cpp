#include "Node.cpp"
#include <iostream>
#include <memory>
#include <string>
#include <vector>
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
		vector<int> GetValues()
		{
			vector<int> Values;
			Node *currentNode = head;
			
			//loop all node and get values (start from head)
			while(currentNode != nullptr)
			{
				Values.push_back(currentNode->value);
				currentNode = currentNode->Next();
			}

			return Values;
		}
	
		// find node with value if not find it return nullptr
		Node *Find(int val)
		{
			Node *currentNode  = head;
			while(currentNode != nullptr)
			{
				if(currentNode->value == val)
					return  currentNode;
				currentNode = currentNode->Next();
			}
			return nullptr;
		}
		
		Node *AtIndex(int index)
		{
			Node *currentNode  = head;
			int c=0;
			while(c<= index)
			{
				if(c == index)
					return currentNode;
				currentNode = currentNode->Next();
				c++;
			}
			return nullptr;
		}

		void Insert(int value,int index=-1)
		{
			// count index from last
			if(index == -1)
				AddElement(value);

			if(index < 0)
				index = counter - index;
	
			Node *newNode = new Node(value);
		
			Node *currentNode;
		
			if(index == 0)
			{
				currentNode = head;
				head = newNode;
				head->setNext(currentNode);
				counter +=1;
				return;
			}
			currentNode	= AtIndex(index-1);
			Node  *nextNode = currentNode->Next();
			currentNode->setNext(newNode);
			newNode->setNext(nextNode);
		}
};