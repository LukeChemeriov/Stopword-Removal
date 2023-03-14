// © Luke Chemeriov, 2023
// It is prohibited to use this library and remove this copyright notice.

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

class SWR
{
public:
    SWR();
    ~SWR();

    std::string RemoveStopWords(std::string);

private:
    std::vector<std::string> Split(std::string);
    std::string Join(std::vector<std::string>);
};


std::string SWR::RemoveStopWords(std::string sentence)
{
    // Load the list of stop words
    // They must ALL have a single space after them
    std::vector<std::string> stop_words = {"a ", "an ", "and ", "are ", "as ", "at ", "be ", "by ", "for ", "from ", "has ", "he ", "in ", "is ", "it ", "its ", "of ", "on ", "that ", "the ", "to ", "was ", "were ", "will ", "with "};

    // Split the sentence into words
    std::vector<std::string> words = Split(sentence);
    
    words.shrink_to_fit();

    // Remove the stop words from the list of words
    std::vector<std::string> filtered_words;

    for (int i = 0; i <= (int) words.size() - 1; i++)
    {
        if (!(std::find(stop_words.begin(), stop_words.end(), words[i]) != stop_words.end()))
        {
            filtered_words.push_back(words[i]);
        }
    }

    // Join the filtered words back into a sentence
    std::string filtered_sentence = Join(filtered_words);

    // Return the filtered sentence
    return filtered_sentence;

}


std::string SWR::Join(std::vector<std::string> words)
{
    std::ostringstream os;
    words.shrink_to_fit();
    std::copy( words.begin(), words.end(), std::ostream_iterator<std::string>( os ) );
    return os.str();
}
std::vector<std::string> SWR::Split(std::string sentence)
{
    std::string tmp; 
    std::stringstream ss(sentence);
    std::vector<std::string> words;

    while(getline(ss, tmp, ' '))
    {
        words.push_back(tmp + ' ');
    }
    return words;
}
SWR::SWR(){}

SWR::~SWR(){}
