#include <iostream>
#include <map>

using namespace std;

struct Trie
{
    map<char, Trie> children;
    int cnt = 0; // number of words that have current word as prefix
    int end = 0; // number of times this word was added to the trie

    void add(string &word, int i = 0)
    {
        cnt++;
        if (i < (int)word.size()) children[word[i]].add(word, i + 1);
        else end++;
    }

    void remove(string &word, int i = 0)
    {
        cnt--;
        if (i < (int)word.size()) children[word[i]].remove(word, i + 1);
        else end--;
    }

    int count_words_with_prefix(string &word, int i = 0)
    {
        if (i == (int)word.size())
            return cnt;
        
        if (children.count(word[i]))
            return children[word[i]].count_words_with_prefix(word, i + 1);
        
        return 0;
    }
};

int main()
{
    int n_queries, cmd;
    cin >> n_queries;

    Trie root;

    for (int i = 0; i < n_queries; i++)
    {
        string word;
        cin >> cmd >> word;

        switch (cmd)
        {
            case 1:
                root.add(word);
                break;
            case 2:
                root.remove(word);
                break;
            case 3:
                cout << root.count_words_with_prefix(word) << endl;
                break;
        }
    }
    
    return 0;
}