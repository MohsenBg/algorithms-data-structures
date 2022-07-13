#ifndef SEARCH_CPP
#define SEARCH_CPP

#include <memory>
#include <vector>
#include <iostream>
#include <map>
#include "Node.cpp"
using namespace std;


class PathNode
{
	public:
		PathNode(shared_ptr<Node> NODE)
		{
			node = NODE;
		}
	
		shared_ptr<Node> node;

		void setParnet(shared_ptr<PathNode> Parnet)
		{
			parent = Parnet;
		}
		
		shared_ptr<PathNode> getParent()
		{
			return parent;
		}
	private:
		shared_ptr<PathNode> parent;

};

class Search
{

	public:
	 
	// Breadth First Search
	  static vector<string> BFS(shared_ptr<Node> start, shared_ptr<Node> end)
	  {
		
		map<string,bool> visited;
		vector<shared_ptr<PathNode>> queue;
		queue.push_back(shared_ptr<PathNode>(new PathNode(start)));
		queue[0]->setParnet(nullptr);	
		


		while(queue.size() != 0)
		{
			
			shared_ptr<Node> currentNode = queue[0]->node;
			shared_ptr<PathNode> path = queue[0];
	
			if(currentNode->name == end->name)
			{
				vector<string>paths;
				shared_ptr<PathNode> currentpath = path;

				while(currentpath != nullptr)
				{	
					paths.insert(paths.begin(),currentpath->node->name);
					currentpath = currentpath->getParent();
				}
				
				return paths;
			}

			//Remove first Element
			queue.erase(queue.begin());
		
			if(visited[currentNode->name])
				continue;
			
			vector<shared_ptr<Node>>neighbors = currentNode->GetNeighbor();	

			for(shared_ptr<Node>neighbor:neighbors)
			{
				shared_ptr<PathNode> newPathNode = shared_ptr<PathNode>(new PathNode(neighbor));
				newPathNode->setParnet(path);
				queue.push_back(newPathNode);
			}
			visited[currentNode->name] = true;
		}
		return  vector<string>();
	  }
	
	//Depth First Search
	static vector<string> DFS(shared_ptr<Node> start,shared_ptr<Node>end)
	{
		map<string,bool> visited;
		vector<shared_ptr<PathNode>> stack;
		stack.push_back(shared_ptr<PathNode>(new PathNode(start)));
		stack[0]->setParnet(nullptr);	
		


		while(stack.size() != 0)
		{
			
			shared_ptr<Node> currentNode = stack.back()->node;
			shared_ptr<PathNode> path = stack.back();
	
			if(currentNode->name == end->name)
			{
				vector<string>paths;
				shared_ptr<PathNode> currentpath = path;

				while(currentpath != nullptr)
				{		
					paths.insert(paths.begin(),currentpath->node->name);
					currentpath = currentpath->getParent();
				}
				
				return paths;
			}

			//Remove last Element
			stack.pop_back();
		
			if(visited[currentNode->name])
				continue;
			
			vector<shared_ptr<Node>>neighbors = currentNode->GetNeighbor();	

			for(shared_ptr<Node>neighbor:neighbors)
			{
				shared_ptr<PathNode> newPathNode = shared_ptr<PathNode>(new PathNode(neighbor));
				newPathNode->setParnet(path);
				stack.push_back(newPathNode);
			}
			visited[currentNode->name] = true;
		}
		return  vector<string>();
	}
};

#endif
