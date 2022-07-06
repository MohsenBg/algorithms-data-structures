#ifndef SEARCH_CPP
#define SEARCH_CPP

#include <vector>
#include <iostream>
#include <map>
#include "Node.cpp"
using namespace std;

class Search
{
	public:
	 
	// Breadth First Search
	  static void BFS(Node start )
	  {
		
		map<string,bool> visited;
		vector<Node*> queue;
		queue.push_back(&start);
		
		while(queue.size() != 0)
		{
			Node *currentNode = queue[0];
		
			//Remove first Element
			queue.erase(queue.begin());
		
			if(visited[currentNode->name])
				continue;
			
			vector<Node*>neighbors = currentNode->GetNeighbor();
			cout << currentNode->name<< endl;	
			for(Node *neighbor:neighbors)
				queue.push_back(neighbor);

			visited[currentNode->name] = true;
		}

	  }
	
	//Depth First Search
	static void DFS(Node start)
	{
		map<string,bool> visited;
		vector<Node*> stack;
		stack.push_back(&start);
		
		while(stack.size() != 0)
		{
			int n = stack.size();
			Node *currentNode = stack[n - 1];
			stack.pop_back();

			if(visited[currentNode->name])
				continue;
			
			vector<Node*>neighbors = currentNode->GetNeighbor();
			cout << currentNode->name<< endl;	
			
			for(Node *neighbor:neighbors)
				stack.push_back(neighbor);

			visited[currentNode->name] = true;
		}
	}

};

#endif
