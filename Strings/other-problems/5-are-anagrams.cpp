#include <iostream>
#include <unordered_map>

bool are_anagrams(std::string S1, std::string S2)
{
    int len_S1 = S1.length();
    int len_S2 = S2.length();

    if (len_S1 != len_S2)
        return false;

    std::unordered_map<char, int> lookup_S1;

    for (int i = 0; i < len_S1; ++i)
    {
        ++lookup_S1[S1[i]];
    }

    std::unordered_map<char, int> lookup_S2;

    for (int i = 0; i < len_S2; ++i)
    {
        ++lookup_S2[S2[i]];
    }

    for (auto itr = lookup_S1.begin(); itr != lookup_S1.end(); ++itr)
    {
        // match frequency in both maps
        if (itr->second == lookup_S2[itr->first])
            continue;
        else
            return false;
    }

    return true;
}

int main()
{
    std::string S1 = "anagrams";
    std::string S2 = "anagrams";
    std::string S3 = "nope";

    if (are_anagrams(S1, S2))
        std::cout << "Yes\n";
    else
        std::cout << "No\n";

    return 0;
}