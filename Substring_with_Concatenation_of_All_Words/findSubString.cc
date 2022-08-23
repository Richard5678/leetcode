class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength = words[0].length();
        vector<int> indeces;
        if (wordLength * words.size() > s.length())
        {
            return indeces;
        }
        
        for (int j = 0; j < wordLength; j++)
        {
            // wordsCopy keeps track of all the words needed to match a substring of s
            // removedWords contains all the words that have been removed from wordsCopy
            vector<string> wordsCopy = words;
            vector<string> removedWords;
            for (int i = 0; i < s.length() / wordLength; i++)
            {   
                string substring = s.substr(i * wordLength + j, wordLength);
                auto itr = find(wordsCopy.begin(), wordsCopy.end(), substring);
                if (itr != wordsCopy.end())
                {
                    removedWords.push_back(*itr);
                    wordsCopy.erase(itr);
                }
                else 
                {
                    auto it = find(removedWords.begin(), removedWords.end(), substring);
                    // If input word has not been removed, then we reset and start matching again
                    if (it == removedWords.end())
                    {
                        wordsCopy = words;
                        removedWords.clear();
                        continue;
                    }
                    // If input word has been removed, than we need to reparse all word
                    //      before it and move the input word from the front of removedWords to the end
                    wordsCopy.insert(wordsCopy.end(), removedWords.begin(), it);
                    removedWords.erase(removedWords.begin(), it + 1);
                    removedWords.push_back(substring);
                }

                if (wordsCopy.size() == 0)
                {
                    indeces.push_back((i + 1 - words.size()) * wordLength + j);
                    wordsCopy.push_back(removedWords[0]);
                    removedWords.erase(removedWords.begin());
                }
            }
        }
        
        sort(indeces.begin(), indeces.end());
        return indeces;
    }
};