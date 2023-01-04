class Solution {
public:
    bool detectCapitalUse(string word) {
        string first = word , second = word;
        char a = word[0];
        string third (word.begin()+1,word.end());
        string temp = third ;
        transform (word.begin(),word.end(),first.begin(),::toupper);
        transform (word.begin(),word.end(),second.begin(),::tolower);
        transform (third.begin(),third.end(),third.begin(),::tolower);
        return first==word || second==word || (isupper (a) && third==temp);

    }
};
