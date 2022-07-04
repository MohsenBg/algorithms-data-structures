#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node
{
	private:
	vector<Node> neighbors;

	bool IsNeighborsExist (Node node)
	{	
		for(Node neighbor:neighbors)
			if(neighbor.name == node.name)
				return true;
		return false;
	}


	public:
	string name;
	
	Node(string Name)
	{
		name = Name;	
	}

	void AddNeighbors(Node node)
	{
		if(!IsNeighborsExist(node))
			neighbors.push_back(node);	
	}

	void DebugLog()
	{
	
		string show = "["+ name +"]: {";
		
		for(Node neighbor:neighbors)
			show += neighbor.name + ",";
		
		if(neighbors.size() > 0)
			show.pop_back();
		
		show += "}";
		
		cout << show << endl;
	}
};
