#include "utils.h"

/**
 * @brief Split a string separated by space into a vector.
 *
 * @param string Text input to be splited.
 *
 * @return std::vector<std::string> A list of string represented as a vector.
 *
 * @details
 *  1. Loop into each character
 *  2. If character is space, push a string in word variable into vector.
 *  3. If character is last character, add the caracter into word variable, push word into args, then cleanup word.
 *  4. Else, add character into a word.
 *  5. Add index on every loop.
 *
 * @code
 * std::vector<std::string>  v = splitText("Hello World"); // return {"Hello","World"}
 */
std::vector<std::string> splitText(std::string text)
{
    int index = 0;
    std::vector<std::string> args;
    std::string word;

    for (char c : text)
    {
        if (c == ' ')
        {
            args.push_back(word);
            word = "";
        }
        else if (index + 1 == text.size())
        {
            word += c;
            args.push_back(word);
            word = "";
        }
        else
        {
            word += c;
        }
        index++;
    }

    return args;
}