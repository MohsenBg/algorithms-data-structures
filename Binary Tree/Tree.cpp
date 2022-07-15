#ifndef GRAP_CPP
#define GRAP_CPP

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include "Node.cpp"
using namespace std;


// Depth Breath Map(has table)
enum ALGORITHM {DFS,BFS,MAP,RECURSIVE};

struct TreeNode
{
	TreeNode(string Id, int Value)
	{
		id = Id;
		value = Value;
	}
	string id;
	int value;
};

class Tree
{
	private :
		map <string,shared_ptr<Node>> nodes;
		map <int,vector<string>> reverseMap;
		shared_ptr<Node> head;
		vector<shared_ptr<Node>> leafs;
	

		shared_ptr<Node> FindNodeMap(string id)
		{
			if(nodes.count(id) == 1)
				return nodes[id];
			else	
				return nullptr;
		}

		shared_ptr<Node> FindNodeBFS(string id)
		{
			vector<shared_ptr<Node>> quene;
			map<string,bool> visited;
			quene.push_back(head);	
			
			while(quene.size() != 0)
			{
				shared_ptr<Node> currentNode = quene[0];
				quene.erase(quene.begin());	
				
				if(visited[currentNode->GetId()])
					continue;

				if(currentNode->GetId() == id)
					return currentNode;
				
				Node::BothChild children = currentNode->GetBothChild();
				
				if(children.right != nullptr)
					quene.push_back(children.right);
			
				if(children.left != nullptr)
					quene.push_back(children.left);
				
				visited[currentNode->GetId()] = true;
			}
			return nullptr;

		}
		
	
		shared_ptr<Node> FindNodeRecursive(string id,shared_ptr<Node>node)
		{
			if(node->GetId() == id)
				return node;
		
			else
			{
				
			vector<shared_ptr<Node>>children =
			{node->GetRightNode(),node->GetLeftNode()};
				
			for(shared_ptr<Node> child:children){

					if(child != nullptr){
						shared_ptr<Node> otherNode= FindNodeRecursive(id,child);
						if(otherNode != nullptr && otherNode->GetId() == id)
							return  child;
					}
			}
			return  nullptr;
			}
		}	


		shared_ptr<Node> FindNodeDFS(string id)
		{
			vector<shared_ptr<Node>> stack;
			map<string,bool> visited;
			stack.push_back(head);
			
			while(stack.size() != 0)
			{
				shared_ptr<Node> currentNode = stack.back();
				stack.pop_back();	
				
				if(visited[currentNode->GetId()])
					continue;
				
				if(currentNode->GetId()==id)
					return currentNode;

				Node::BothChild children = currentNode->GetBothChild();
				
				if(children.right != nullptr)
					stack.push_back(children.right);
			
				if(children.left != nullptr)
					stack.push_back(children.left);
				
				visited[currentNode->GetId()] = true;
			}
			return nullptr;
		}
		
		void setMap(shared_ptr<Node> node)
		{
			nodes[node->GetId()] = node;
			if(reverseMap.count(node->GetValue()) == 1)
			{
				vector<string> currentIdes = reverseMap[node->GetValue()];
				currentIdes.push_back(node->GetId());
				reverseMap[node->GetValue()] = currentIdes;
			}
			else{
				vector<string> newVectorId= {node->GetId()};
				reverseMap[node->GetValue()] = newVectorId;
			}
		}
	
		void SetLeaf(shared_ptr<Node> Parnet,shared_ptr<Node> node)
		{
			int parnetIndex = -1;
			bool IsChildExists = false;
				for(int i =0 ; i < leafs.size(); i++)
				{
					if(leafs[i]->GetId() == node->GetId())
						IsChildExists = true;
					
					if(leafs[i]->GetId()==Parnet->GetId())
							parnetIndex = i;
				}

			if(!IsChildExists)
				leafs.push_back(node);
			if(parnetIndex != -1)
				leafs.erase(leafs.begin() + parnetIndex);
		}


		int RecursiveSum(shared_ptr<Node> node)
		{
			if(node == nullptr)
				return 0;
			return node->GetValue() + RecursiveSum(node->GetLeftNode())
				+ RecursiveSum(node->GetRightNode());
		}

		int MapSum()
		{
			int sum = 0;
			for(auto node=nodes.begin(); node != nodes.end() ;node++)	
			{
				if(node->second == nullptr)
					continue;
				sum += node->second->GetValue();
			}
			return sum;
		}

		int DFS_Sum(shared_ptr<Node> node)
		{
			
			int sum = 0;
			if(node == nullptr)
					return sum ;

			vector<shared_ptr<Node>> stack;
			map<string,bool> visited;
			stack.push_back(node);
			
			while(stack.size() != 0)
			{
				shared_ptr<Node> currentNode = stack.back();
				stack.pop_back();	
				
				if(visited[currentNode->GetId()])
					continue;
					
				sum += currentNode->GetValue();
				Node::BothChild children = currentNode->GetBothChild();
				
				if(children.right != nullptr)
					stack.push_back(children.right);
			
				if(children.left != nullptr)
					stack.push_back(children.left);
				
				visited[currentNode->GetId()] = true;
			}
			return sum;
		}

		int BFS_Sum(shared_ptr<Node> node)
		{
			
			int sum = 0;
			if(node == nullptr)
					return sum ;

			vector<shared_ptr<Node>> quene;
			map<string,bool> visited;
			quene.push_back(node);	
			
			while(quene.size() != 0)
			{
				shared_ptr<Node> currentNode = quene[0];
				quene.erase(quene.begin());	
				
				if(visited[currentNode->GetId()])
					continue;
			
				sum += currentNode->GetValue();
				Node::BothChild children = currentNode->GetBothChild();
				
				if(children.right != nullptr)
					quene.push_back(children.right);
			
				if(children.left != nullptr)
					quene.push_back(children.left);
				
				visited[currentNode->GetId()] = true;
			}
			return sum;
		}


	public : 
		Tree(TreeNode Head)
		{
			head = shared_ptr<Node>(new Node(Head.id,Head.value));
			setMap(head);
			leafs.push_back(head);
		}

				
		shared_ptr<Node> GetHead()
		{
			return head;
		}


		vector<shared_ptr<Node>> GetLeafs()
		{
			return leafs;
		}

	
		
		vector<string> GetIdWithValue(int Value)
		{
			if(reverseMap.count(Value)== 0)
				return vector<string>();
			return reverseMap[Value];
		}
		

		shared_ptr<Node> FindNodeWithId(string id  ,ALGORITHM algorithm=MAP)
		{
			shared_ptr<Node>node;
			switch(algorithm)
			{
				case DFS:
					node = FindNodeDFS(id);
				break;
				
				case BFS:
					node = FindNodeBFS(id);
				break;
				
				case RECURSIVE:
					node = FindNodeRecursive(id,head);
				break;
				
				case MAP:
					node = FindNodeMap(id);
				break;

				default:
					node = FindNodeMap(id);
				 break;
			}

			return node;
		}
		
		vector<string> FindNodeWithValue(int Value)
		{
			if(reverseMap.count(Value) > 0)
					return reverseMap[Value];
			
			return vector<string>();
		}

		void ChangeValueNode(string id , int newValue ,ALGORITHM algorithm=MAP)
		{
			shared_ptr<Node> node = FindNodeWithId(id,algorithm);	
			node->ChangeValue(newValue);
		}
		
		bool AddRightNode(string ParnetId,TreeNode RigthNode)
		{
			shared_ptr<Node> parnet = FindNodeWithId(ParnetId);
			if(parnet == nullptr)
				return false;

			shared_ptr<Node> rightNode =shared_ptr<Node>(new Node(RigthNode.id,RigthNode.value));
			parnet->SetRightNode(rightNode);
						
			setMap(rightNode);
			SetLeaf(parnet,rightNode);
			
			return true;
		};
	
		bool AddLeftNode(string ParnetId,TreeNode LeftNode)
		{
			shared_ptr<Node> parnet = FindNodeWithId(ParnetId);
			if(parnet == nullptr)
				return false;

			shared_ptr<Node> leftNode =shared_ptr<Node>(new Node(LeftNode.id,LeftNode.value));
			parnet->SetLeftNode(leftNode);
			
			setMap(leftNode);
			SetLeaf(parnet,leftNode);
			return true;
		};

		bool AddBothNode(string ParnetId,TreeNode LeftNode,TreeNode RigthNode)
		{
			shared_ptr<Node> parnet = FindNodeWithId(ParnetId);
			if(parnet == nullptr)
				return false;
			
			AddLeftNode(ParnetId,  LeftNode);
			AddRightNode(ParnetId,RigthNode);
	
			return true;
		};

		int SumAllNode(ALGORITHM algorithm=MAP)
		{
			int sum=0;
			switch(algorithm)
			{
				case DFS:
					sum = DFS_Sum(head);
				break;
				
				case BFS:
					sum = BFS_Sum(head);
				break;
				
				case RECURSIVE:
					sum = RecursiveSum(head);
				break;
				
				case MAP:
					sum = MapSum();
				break;

				default:
					sum = MapSum();
				 break;
			}

			return sum;
		}


};

#endif
