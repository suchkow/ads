#include <vector>
#include <queue>
#include <stack>
#include <iostream>

class BSTree
{
public:

    class Node
    {
    public:
        Node(){}
        Node(int key) : key(key), right(nullptr), left(nullptr){}
        int   key;
        Node* right;
        Node* left;
    };

    BSTree() : _root(nullptr)
    {}

    ~BSTree()
    {
        destruct(_root);
    }

    void destruct(Node* currentNode)
    {
        
    }

    Node* getRoot()
    {
        return _root;
    }

    void insert(int key)
    {
        Node* it = _root;

        Node* newNode = new Node(key); //  new node
        Node* parent = nullptr;      // new node's parent

        while(it != nullptr)
        {
            parent = it; // keep trail of the parent
            it = newNode->key < it->key ? it->left : it->right;
        }

        if(!parent)
        {
            _root = newNode; // tree was empty
        }
        else if(newNode->key < parent->key)
        {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    // search for node with key k in the BST
    //Node* search(int k){}
    //int size(){}

private:

    Node* _root;
};

// Walking the tree...

void inorder(BSTree::Node* currentNode)
{
    if(currentNode)
    {
        inorder(currentNode->left);
        std::cout << currentNode->key << ' ';
        inorder(currentNode->right);
    }
}

void preorder(BSTree::Node* currentNode)
{
    if(currentNode)
    {
        std::cout << currentNode->key << ' ';
        preorder(currentNode->left);
        preorder(currentNode->right);
    }
}

void postorder(BSTree::Node* currentNode)
{
    if(currentNode)
    {
        postorder(currentNode->left);
        postorder(currentNode->right);
        std::cout << currentNode->key << ' ';
    }

}

int main()
{
    BSTree myTree;

    std::vector<int> data = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for(int i = 0; i < data.size(); i++)
        myTree.insert(data[i]);

    preorder(myTree.getRoot());
    std::cout << std::endl;

    postorder(myTree.getRoot());
    std::cout << std::endl;

    return 0;
}
