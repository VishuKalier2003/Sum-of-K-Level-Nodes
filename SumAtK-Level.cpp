/* Implementation of Binary Trees... A Binary Tree Node can have maximum Two Child Nodes...
The Maximum Nodes with level x is 2^x... The Maximum Nodes in Tree of Height h is 2^h - 1... For x
Nodes the minimum possible level is log(x + 1)... A Binary tree with n leaves has atleast 
log(n + 1) + 1 number of levels */
#include <iostream>
#include <queue>
using namespace std;
class Node                    // Node class created for each Tree Node creation
{
    public:
    int data;         // Data member
    Node* left;      // Left Node pointer
    Node* right;     // Right Node pointer
    Node* root;      // Root Node pointer
    public:
    Node (int val)    // Parametrized Constructor
    {
        data = val;
        left = NULL;
        right = NULL;
        root = NULL;
    }
};
class BinaryTree     //  Class created for Binary Tree Implementation ( Non-Linear Data Structure )
{
    public:
    Node* InsertNodeInTree(Node* root, int val)   // Inserting Node recursively.. O(log n) time
    {
        if(root == NULL)               // If No root node is there, create one
            return new Node(val);
        if(val <= root -> data)   // If data is lesser than or equal to parent store in left subtree
            root -> left = InsertNodeInTree(root -> left, val);
        else         // If data is greater than the parent stor it in right subtree
            root -> right = InsertNodeInTree(root -> right, val);
        return root;
    }
    void ShowTree(Node* root)   // Displaying tree with Node.. O(log n) time
    {
        Node* temp = root;
        if(temp == NULL)    // If Tree is empty nothing to show
            return;                            // Control moves out of the function
        ShowTree(temp -> left);     // Recursive Call
        cout << "Node: " << endl;
        if(temp -> left != NULL)    // If left subtree is not empty
            cout << "\t" << temp -> data << " ---> " << temp -> left -> data << "\t Left ( Occupied )" << endl;
        else      // If left subtree is empty
            cout << "\t" << temp -> data << "\t\t Left ( Empty )" << endl;
        if(temp -> right != NULL)   // If right subtree is not empty
            cout << "\t" << temp -> data << " ---> " << temp -> right -> data << "\t Right ( Occupied ) " << endl;
        else     // If right subtree is empty
            cout << "\t" << temp -> data << "\t\t Right ( Empty )" << endl;
        ShowTree(temp -> right);     // Recursive Call
    }
    int SumOfKthLevel(Node* root, int k)   // Evaluating Sum using Iterative Deepening Search
    {
        if(root == NULL)    // If the root is empty
        {
            cout << "The Tree Is Empty hence garbage value is provided !!" << endl;
            return -1;     //  Return a truncated value
        }
        queue<Node*> Queue;    // Queue of Node class for pointers created
        Queue.push(root);      // Enqueuing Root Node
        Queue.push(NULL);      // Enqueuing Null pointer
        int level = 0;
        int sum = 0;
        while(!Queue.empty())   // Checking if Queue is not empty
        {
            Node* node = Queue.front();    // Front pointer called 
            Queue.pop();      // Dequeing First Node
            if(node != NULL)
            {
                if(level == k)    // If required Level is reached
                {
                    sum = sum + node -> data;    // Sum value added
                }
                if(node -> left)     // If there is Left node of the parent node
                    Queue.push(node -> left);
                if(node -> right)    // If there is Right node of the parent node
                    Queue.push(node -> right);
            }
            else if(!Queue.empty())
            {
                Queue.push(NULL);    // If Queue is not empty after a level traversal
                level = level + 1;         // Increment Level pointer
            }
        }
        return sum;    // Return statement to get the sum
    }
};
int main()
{
    Node* root = NULL;      // Root node initialization
    BinaryTree binarytree;      // Object creation of Binary Tree
    int s, x;
    cout << "Enter root Node value : ";
    cin >> x;
    root = binarytree.InsertNodeInTree(root, x);    // Root Node created
    cout << "Enter the number of Nodes to Insert in the Binary Search Tree : ";
    cin >> s;
    for(int i = 1; i <= s; i++)   // Loop begins
    {
        cout << "Enter the New Node value : ";
        cin >> x;
        binarytree.InsertNodeInTree(root, x);   // Calling Insert Tree function
    }
    cout << "Enter the level of which Sum is to be evaluated ( begins from 0 ) : ";
    cin >> s;
    x = binarytree.SumOfKthLevel(root, s);    // Calling function
    cout << "The Sum at " << s << " level is : " << x <<endl;
    binarytree.ShowTree(root);    // Displaying binary tree with Nodes
    return 0;          // End of Program
}