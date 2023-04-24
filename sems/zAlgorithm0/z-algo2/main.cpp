// Exercise #2: Code a program that finds all distinct words in a file.
// Then, sort all the words in ascendant order according to their frequency by using ONLY some of the sorting algorithms we coded in previous seminars.
// You cannot use ordered containers to save distinct words. You can use unordered containers such as std::unordered_map, std::unordered_set, std::vector.

#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
//#include <utility>

typedef std::vector<std::string> VecStr;
typedef std::vector<std::pair<std::string, int>> pairsVec;

// words[s] = n where "n" is the number of ocurrences of word "s"
std::unordered_map<std::string,int> words;

void findDistinctWords(std::ifstream& file)
{
    std::string line, token;

    while(std::getline(file, line)) // reading line-by-line
    {
        std::istringstream ss(line);

        std::vector<std::string> lineAsVector;

        while(std::getline(ss,token,(char)0x20)) // read words separated by space character
            lineAsVector.push_back(token);

        for (int i = 0; i != lineAsVector.size(); ++i)
        {
            std::unordered_map<std::string, int>::const_iterator it = words.find(lineAsVector[i]);

            if (it != words.end())
                words[lineAsVector[i]] += 1;

            else
                words.insert({lineAsVector[i], 1});
        }
    }
}

int partition (pairsVec& someVec, int lowBound, int highBound)
{
    int pivot = someVec[highBound].second;
    int i = (lowBound - 1);

    for (int j = lowBound; j <= highBound - 1; j++)
    {

        if (someVec[j].second < pivot)
        {
            i++;
            swap(someVec[i], someVec[j]);
        }
    }

    swap(someVec[i + 1], someVec[highBound]);
    return (i + 1);
}

void quickSort(pairsVec& someVec, int l, int r)
{
    if (l < r)
    {

        int ind = partition(someVec, l, r);


        quickSort(someVec, l, ind - 1);
        quickSort(someVec, ind + 1, r);
    }
}

pairsVec sort(std::unordered_map<std::string,int> unsortMap)
{
    pairsVec vecOfPairs;

    for (const std::pair<std::string, int>& anotherPair : words)
        vecOfPairs.push_back(anotherPair);

    quickSort(vecOfPairs,  0, vecOfPairs.size());

    return vecOfPairs;
}

void printVec(const pairsVec& someVec)
{
    std::cout << "{ ";

    for (const std::pair<std::string, int>& anotherPair : someVec)
        std::cout << '(' + anotherPair.first + ',' << anotherPair.second + ')' + ", " << std::endl;

   std::cout << '}';
}



int main()
{
    std::ifstream file("/Users/ilyasuchkov/Desktop/z-algo2/alice.txt");

    findDistinctWords(file);

    file.close();

    printVec(sort(words));

    // Your container of words should look like: { (will,1), (dear,1), (croquet,2), (pig,6), (replied,1), (Alice,25), (Queen,2) }

    // Step 2. Now, you need to sort by frequency (in ascendant order) all the words into another container "v"


    // Step 3. Print in the console the sorted container together with the frequency of each word
}
