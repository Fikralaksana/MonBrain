#include "utils.h"
#include <iostream>

/**
 * @brief Split a string separated by space into a vector.
 *
 * @param text Text input to be splitted.
 *
 * @return std::vector<std::string> A list of string represented as a vector.
 *
 * @details
 *  1. Loop into each character
 *  2. If character is space, push a string in word variable into vector.
 *  3. If character is last character, add the character into word variable, push word into args, then cleanup word.
 *  4. Else, add character into a word.
 *  5. Add index on every loop.
 *
 * @code
 * std::vector<std::string>  v = splitText("Hello World"); // return {"Hello","World"}
 *
 * TODO:
 * 1. Text is copied from caller, can used alias/reference.
 * 2. Word is creating new object everytime there is a changes.
 *    Use text.substr to cut text and directly push to vector
 * 3.
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