#include <iostream>
#include <vector>

using namespace std;

vector<int> found_pattern_index;

void kmp_pre_process(int *b, string pattern, int pattern_size)
{
    b[0] = -1;

    int i = 0, j = -1;
    while (i < pattern_size)
    {
        while (j >= 0 && pattern[i] != pattern[j]) j = b[j];

        i++; j++;
        b[i] = j;
    }
}

void kmp_search(int *b, string pattern, string text, int pat_size, int text_size)
{
    int i = 0, j = 0;
    while (i < text_size)
    {
        while (j >= 0 && text[i] != pattern[j]) j = b[j];
        
        i++; j++;

        if (j == pat_size)
        {
            found_pattern_index.push_back(i - j + 1);
            j = b[j];
        }
    }
}

void test_case()
{
    found_pattern_index.clear();

    string text, pattern;
    cin >> text >> pattern;

    int b_size = pattern.size();
    int b[b_size];

    kmp_pre_process(b, pattern, pattern.size());
    kmp_search(b, pattern, text, pattern.size(), text.size());

    if (found_pattern_index.empty())
    {
        cout << "Not Found\r\n\r\n";
    }
    else
    {
        cout << found_pattern_index.size() << "\r\n";
        for (int i : found_pattern_index) cout << i << " ";
        cout << "\r\n\r\n";
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) test_case();

    return 0;
}