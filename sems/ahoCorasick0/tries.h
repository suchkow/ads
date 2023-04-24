#ifndef TRIES_H
#define TRIES_H

#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <string>

class Trie
{
    public:

        class Node
        {
            public:
                Node(char c) : c(c), endOfWord(false)
                {
                    for(int i = 0; i < 26; i++)
                        children[i] = nullptr;
                }

                Node*   children[26];
                char  	c;
                bool 	endOfWord;

                bool hasChildren()
                {
                    bool flag = false;

                    for(int i = 0; i < 26; i++)
                    {
                        if(children[i] != nullptr)
                        {
                            flag = true;
                            break;
                        }
                    }

                    return flag;
                }
        };

        Trie() : _root(new Node('_')){ }

        ~Trie()
        {
            destruct(_root);
        }

        void destruct(Node* currentNode)
        {
            if(currentNode)
            {
                for(int i = 0; i < 26; i++)
                    destruct(currentNode->children[i]);
                delete currentNode;
            }
        }

        void insert(std::string key)
        {
            Node* it = _root;

            for(int i = 0; i < key.size(); i++)
            {
                int index = key[i] - 97;
                if(it->children[index] == nullptr)
                    it->children[index] = new Node(key[i]);
                it = it->children[index];
            }

            it->endOfWord = true;
        }

        bool search(std::string key)
        {
            Node* it = _root;

            for(int i = 0; i < key.size(); i++)
            {
                int index = key[i] - 97;
                if(it->children[index] == nullptr)
                    return false;

                it = it->children[index];
            }

            return it->endOfWord;
        }

        void retrieve(std::string prefix)
        {
            Node *it = _root;

            for(int i = 0; i < prefix.size(); i++)
            {
                int index = prefix[i] - 97;
                if(it->children[index] == nullptr)
                    return;

                it = it->children[index];
            }

            visit(it, prefix);

        }

        void visit(Node* it, std::string word)
        {
            for(int i = 0; i < 26; i++)
            {
                if(it->children[i] != nullptr)
                {
                    std::string tmp = word;
                    tmp.push_back(it->children[i]->c);
                    if(it->children[i]->endOfWord)
                        std::cout << tmp << std::endl;
                    visit(it->children[i], tmp);
                }
            }
        }

        void erase(std::string key)
        {
            _root = erase(_root, key, 0);
        }

        protected:

            Node* erase(Node* node, std::string key, int i)
            {
                if(node == nullptr)
                    return node;

                if(i == key.size())
                {
                    if(node->endOfWord)
                        node->endOfWord = false;

                    if(!node->hasChildren()) // this key is not part of another key
                    {
                        delete node;
                        node = nullptr;
                    }

                    return node;
                }

                int index = key[i] - 97;
                node->children[index] = erase(node->children[index], key, i);

                // this key is not part of another key, and it is not end of a word
                if(node->hasChildren() == false && node->endOfWord == false)
                {
                    delete node;
                    node = nullptr;
                }

                return node;
            }

            Node* _root;
};

#endif // TRIES_H
