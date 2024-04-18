#ifndef WORDLE_H
#define WORDLE_H

#ifndef RECCHECK
#include <set>
#include <string>
#include <vector>
#endif

/**
 * @brief Returns the list of all legal words in the provided dictionary
 *        that meet the criteria provided in the `in` and `floating`
 *        inputs.
 * 
 * @param [in] in - string of fixed, correct characters and `-`s to indicate
 *                  the length of string and locations that must be filled in
 * @param [in] floating  - Characters that must be used somewhere in the word
 * @param [in] dict - Dictionary of strings of legal words
 * @return std::set<std::string> - Set of all words that meet the criteria
 */
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict);
void word(const std::string& in,  const std::set<std::string>& dict, int ctr, std::vector<int> ind, std::set<std::string>& s, const std::string& floating, int over);

#endif