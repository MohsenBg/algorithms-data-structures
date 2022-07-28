# Link List

## Class Node

### Variable

| Name  | Type                 | Accessibility | Description                        |
| :---- | :------------------- | :------------ | :--------------------------------- |
| value | int                  | Public        | Store value. type can be different |
| next  | shared_ptr<Node\<T>> | Private       | Point to Node                      |

### Functions

| Name    | Accessibility | Argument             | Return               | Description                   |
| :------ | :------------ | :------------------- | :------------------- | :---------------------------- |
| Next    | Public        | -                    | shared_ptr<Node\<T>> | Return Next Node              |
| Node    | Public        | T value              | void                 | Constructor Node              |
| setNext | Public        | shared_ptr<Node\<T>> | void                 | Change next(private) Variable |

## Class LinkList

### Variable

| Name    | Type                 | Accessibility | Description    |
| :------ | :------------------- | :------------ | :------------- |
| counter | int                  | Private       | Number of Node |
| head    | shared_ptr<Node\<T>> | Private       | First Node     |
| tail    | shared_ptr<Node\<T>> | Private       | Last Node      |

### Functions

| Name        | Accessibility | Argument                    | Return               | Description                                                           |
| :---------- | :------------ | :-------------------------- | :------------------- | :-------------------------------------------------------------------- |
| AddElement  | Public        | T value                     | shared_ptr<Node\<T>> | Add new Values(Node) end of the List same as Insert with Defult index |
| AtIndex     | Public        | T value                     | shared_ptr<Node\<T>> | Find Node by the index                                                |
| ChangeValue | Public        | T value <br /> int index    | void                 | Change Value of a Node by index                                       |
| Count       | Public        | -                           | int                  | Return number of Node exists in List                                  |
| DebugLog    | Public        | -                           | void                 | Print all Element of List , example => [1,2,3,...]                    |
| Find        | Public        | T value                     | int                  | If value exsits in List return index of the value otherwise return -1 |
| GetValues   | Public        | -                           | vector<T>            | Return vector (similar to array) All value(Not Node) in List          |
| InList      | Public        | T value                     | bool                 | If value exists in List return true otherwise return false            |
| Insert      | Public        | T value <br /> int index=-1 | void                 | Insert new Value(Node) in List by index. Defult add end of the list   |
| Remove      | Public        | int index=-1                | void                 | Remove A node from List by the index. Defult Remove last Node         |
| Reverce     | Public        | -                           | void                 | Reverce all Node in List                                              |
| begin       | Public        | -                           | shared_ptr<Node\<T>> | Return fist Node(Head) in List                                        |
| end         | Public        | -                           | shared_ptr<Node\<T>> | Return last Node(tail) in List                                        |
