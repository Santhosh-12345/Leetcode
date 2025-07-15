class Solution {
public:
    bool isVowel(char ch)
    {
        ch=tolower(ch);
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    bool isValid(string word) {
        if(word.size()<3)
        return false;
        bool vowel=false,consonant=false;
        for(char ch:word)
        {
            if(!isalnum(ch))
            return false;
            if(isalpha(ch)){
                 if(isVowel(ch))
                vowel=true;
                else
                consonant=true;
            }
           
        }
        return vowel && consonant;
    }
};