#include <iostream>
#include < string>
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

           
       }
};