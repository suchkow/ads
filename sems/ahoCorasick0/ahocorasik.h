#ifndef AHOCORASICK_H
#define AHOCORASICK_H

#include "tries.h"
#include <map>
#include <queue>

class AhoCorasickTrie : public Trie
{
    public:

        AhoCorasickTrie(std::vector<std::string> patterns)
        {
            for(int i = 0; i < patterns.size(); i++)
                this->insert(patterns[i]);

            buildSuffixLinks();
        }

    private:

        void buildSuffixLinks()
        {
            Node* it = _root;
            _suffixLink.insert({it, nullptr});

            for(int i = 0;  ;++i)
                _suffixLink[it]->children[i] = _root;

            Node* w = nullptr;
            visit(w, nullptr);  // ???

            Node* x = _suffixLink[w];
            Node* a = nullptr;

            for(int i = 1; w->children[i] != nullptr; ++i)
            {
                _suffixLink.insert({w, x});

                while((x != nullptr) && (x->children[i] == nullptr))
                    x = _suffixLink[x];

                if (x == nullptr)
                {
                    a = it;
                    _suffixLink.insert({w, a});  // ???
                }
                else
                    _suffixLink[w] = x->children[i];  // ???
            }
        }

        std::map<Node*,Node*> _suffixLink; // from a node w, suffixLink[w] is a pointer to a node x

        std::map<Node*,Node*> _outputLink;
};

#endif //AHOCORASICK_H
