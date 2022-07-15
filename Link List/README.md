# Link List

## Class Node

### Variable

|    Name     |    Type     | Accessibility |  Description						           |
| :--------   | :---------  |  :--------    | :----------						             |
|    value    |    int      |    Public  	  | Store value. type can be different |
|    next     |  ptr Node   |	   Private    | Point to Node						           |


### Functions 

|    Name     | Accessibility |   Argument  |   Return    | Description                   |
| :--------   |  :--------    |   :------   |	 :--------  |:-------------                 |
|    Next     |	    Public 	  |      -      |   ptr Node  | Return Next Node	      		  |
|    Node     |     Public 	  |  int value  |   void      | Constructor Node              |
|   setNext   |     Public 	  |	  ptr Node  |	  void      | change next(private) Variable |


## Class LinkList

### Variable

|    Name     |    Type     | Accessibility |  Description   |
| :--------   | :---------  |  :--------    | :----------    |
|    counter  |    int      |    Private  	| number of Node |
|    head     |  ptr Node   |	   Private	  | first Node     |
|    tail     |  ptr Node   |	   Private	  | last Node      |

### Functions 

|    Name     | Accessibility |          Argument            |   Return        |   Description															                           |
|:------------|:--------------|:-----------------------------|:----------------|:----------------------------------------------------------------------|
|  AddElement |	    Public    |        int value             |     ptr Node    | Add new Values(Node) end of the List same as Insert with Defult index |
|   AtIndex   |     Public    |        int value             |     ptr Node    | Find Node by the index							    		                           |
| ChangeValue |     Public    |   int value <br /> int index |	      void     | Change Value of a Node by index									                     |
|    Count    |     Public    |	           -                 |	      int      | return number of Node exists in List								                	 |
|  DebugLog   |     Public    |	           -                 |	      void     | Print all Element of List , example => [1,2,3,...]				          	 |
|	 Find       |     Public    |	        int value            |	      int      | If value exsits in List return index of the value otherwise return -1 |
|  GetValues  |     Public    |	           -                 |      vector     | return vector (similar to array) All value(Not Node) in List			     |
|   InList    |     Public    |	        int value            |	      bool     | If value exists in List return true otherwise return false			       |
|   Insert    |     Public    | int value <br /> int index=-1|	      void     | Insert new Value(Node) in List by index. Defult add end of the list   |
|   Remove    |     Public    |	      int index=-1           |	      void     | Remove A node from List by the index. Defult Remove last Node		   	 |
|   Reverce   |     Public    |	             -               |	      void     | Reverce all Node in List											                      	 |
|    begin    |     Public    |	             -               |	    ptr Node   | return fist Node(Head) in List									                    	 |
|     end     |     Public    |	             -               |	    ptr Node   | return last Node(tail) in List									                     	 |
