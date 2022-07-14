#ifndef NODE_CPP
#define NODE_CPP

#include <memory>
#include <vector>
#include <iostream>
#include <string>
using namespace std;


class ID
{	
	private:
		char charecters[36] = { 'a','b','c','d','e','f','g','h','i'
			,'j','k','l','m','n','o','p','q','r','s','t','u','v','w'
			,'x','y','z','0','1','2','3','4','5','6','7','8','9' }; 
	
		vector<string> ides;
		
		bool IsIdExit(string id) 
		{
			for(string exitsId:ides)
				if(exitsId == id)
					return true;
			return false;
		}

	public:
	 string GenrateId(string name) 
	{
		if(name != "" && !IsIdExit(name)){
			ides.push_back(name);
			return name;
		}
		string id;
		do{
			id="";
			for(int i=0;i <10 ;i++)
			{
				int index = (rand() % 35);
				id.push_back(charecters[index]);	
			}
		}while(IsIdExit(id));
		
		ides.push_back(id);
		return  id;
	}
};

ID ID_Contorller = ID();

class Node: public enable_shared_from_this<Node>
{
	private:
	string id;
	int value;

	shared_ptr<Node> parnet;
	shared_ptr<Node> right;
	shared_ptr<Node> left;		

	public:
		Node(string name,int Value)
		{
			value = Value;
			id = ID_Contorller.GenrateId(name);
		}
		
		struct BothChild
		{
			BothChild(shared_ptr<Node>Right,shared_ptr<Node> Left)
			{
				right = Right;
				left = Left;
			}
				shared_ptr<Node> right;
				shared_ptr<Node> left;
		};
			

		string GetId()
		{
			return id;
		}

		int GetValue()
		{
			return value; 	
		}	
	
		shared_ptr<Node> GetParent()
		{
			return parnet;
		}

		shared_ptr<Node>GetLeftNode()
		{
			return  left;
		}

		shared_ptr<Node>GetRightNode()
		{
			return  right;
		}
		
		BothChild GetBothChild()
		{
			return BothChild(right,left);
		}
	
	
		void SetParent(shared_ptr<Node> Parnet)
		{
			parnet = Parnet;
		}

		void SetRightNode(shared_ptr<Node> node)
		{
			right = node;
			right->SetParent(shared_from_this());	
		}

		void SetLeftNode(shared_ptr<Node> node)
		{
			left = node;
			left->SetParent(shared_from_this());
		}	

		void ChangeValue(int Value)
		{
			value = Value;
		}

		void DebugLog()
		{
			string show = "{\n";
			show += "   id:"+ id+ "\n";
			show += "   value:"+to_string(value)+ "\n";
			if(right == nullptr)
				show += "   right: nullptr \n";
			else
			{
				show += "   right:{ \n";
				show += "      id:"+right->id+ "\n";
				show += "      value:"+to_string(right->value)+"\n";
				show += "   }\n";
			}

			if(left == nullptr)
				show += "   left: nullptr \n";
			else
			{
				show += "   left:{\n";
				show += "      id:"+ left->id + "\n";
				show += "      value:"+to_string(left->value)+"\n";
				show  += "   }\n";
			}
			show += "}\n";
			cout << show;
		}
};

#endif 

