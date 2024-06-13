#include <iostream>
#include <string>
using namespace std;

class Node
{
  public:
    string info;
    Node* leftchild;
    Node* rightchild;

    // constructor for the node class
        Node(string i, Node* l ,Node* r){
            info = i;
            leftchild = l;
            rightchild = r;

        }
};

class BinaryTree
{
   public:
    Node* ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // initializing ROOT to null
    }

    void insert(string element) // inseret a node in the binary search tree
    {
            Node* newNode = new Node(element, nullptr,nullptr); //  allocate memory for the new node
            newNode->info = element; // assighn value to the data field of the new node
            newNode->leftchild = nullptr; // make the left child of the new node point to NULL
            newNode->rightchild = nullptr; // make the right child of the new node point to NULL

            Node* parent = nullptr;
            Node* currentNode = nullptr;
            search(element,parent,currentNode); // locate the node which will bw the parent of the node to ins

            if (parent == nullptr) // if the parent is NULL (tree is empty)
            {
                ROOT = newNode; // mark the new node as ROOT
                return; // exit
            }
            if (element < parent->info) // if the value in the data field of the new node is less than that of the
            {
                 parent->leftchild = newNode; // make the left child of the parent point to the new node
            }
            else if (element > parent->info) // if the value in the data field of the new node is greater than that
            {
                 parent->rightchild = newNode; // make the left child of the parent point to the new node
            }
      }

       void search(string element, Node*& parent , Node*& currentNode)
       {
          // this fungction search the currentNode of the specified Node as well the current Node of its pare
          currentNode = ROOT;
          parent = NULL;
          while ((currentNode !=NULL) && (currentNode->info != element))
          {
            parent = currentNode;
            if(element < currentNode ->info)
                currentNode =currentNode->leftchild;
                else
                currentNode = currentNode->rightchild;
          }
       }

       void inorder(Node* ptr)
       {
            if(ROOT == NULL)
            {
                cout << "tree is empty" << endl;
                return;
            }
            if (ptr != NULL)
            {
                inorder(ptr->leftchild); // left
                cout << ptr->info << " ";// root
                inorder(ptr->rightchild);//right
            }
       }

          void preorder(Node* ptr)
       {
            if(ROOT == NULL)
            {
                cout << "tree is empty" << endl;
                return;
            }
            if (ptr != NULL)
            {
                cout << ptr->info << " "; //ROOT
                preorder(ptr->leftchild); //LEFT
                preorder(ptr->rightchild); // RIGHT
            }
       }

           void closeorder(Node* ptr)
       {
            if(ROOT == NULL)
            {
                cout << "tree is empty" << endl;
                return;
            }
            if (ptr != NULL)
            {
                closeorder(ptr->leftchild); //LEFT
                closeorder(ptr->rightchild); // RIGHT
                cout << ptr->info << " "; //ROOT
            }
       }
};

int main()
{
    BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1.implement insert operation" << endl;
        cout << "2.perform inorder traversal" << endl;
        cout << "3.perform preorder traversal" << endl; 
        cout << "4.perform closeorder traversal" << endl; 
        cout << "5. Exit" << endl;
        cout << "\nElement your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
         case '1':
        {
           cout << "enter a word: ";
        string word;
        cin >> word;
        x.insert(word);
        break;
        }
         case '2':
         {
            x.inorder(x.ROOT);
            break;
         }
         case '3':
        {
            x.preorder(x.ROOT);
            break;
            
        }
        case '4': 
        {
             x.closeorder(x.ROOT);
            break;     
        }
        case '5':
        {
             return 0;
              default:
              {
                  cout << "invalid option" << endl;
                  break;
              }
        }
          
        }
    }  
};