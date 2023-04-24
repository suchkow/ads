#include <iostream>
#include <vector>

#include "ahocorasik.h"

int main()
{
    std::vector<std::string> patterns = { "he", "his", "hers", "she" };

    AhoCorasickTrie myTrie(patterns);

    return 0;
}
