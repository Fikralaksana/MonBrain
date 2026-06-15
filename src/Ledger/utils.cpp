#include <string>
/**
 * @brief get remaining space of given text and column width
 *
 * This function computes the remaining space character
 * that should be added to render a column.
 *
 * @param text The given text.
 * @param columnWidth The expected column width.
 *
 * @return positive integer if there are remaining space should be given. -1 otherwise
 *
 * @details
 *  1. Get column width
 *  2. Get text size
 *  3. Remaining space is column width - text size
 *  4. If text size is greater than width (negative result) return -1
 *  5. -1 value is invalid remaining space, the caller should handle it.
 *
 *  @example example.cpp
 *
 * @usage
 * int result = getRemainingSpaceForRenderingColumn("hallo", 10); // result will be 5
 */
int getRemainingSpaceForRenderingColumn(std::string text, int columnWidth){
    /* Algorithm
    1. Get column width
    2. Get text size
    3. Remaining space is column width - text size
    4. If text size is greater than width (negative result) return -1
    5. -1 value is invalid remaining space, the caller should handle it.
    */
    int remainingSpace = columnWidth - text.size();
    if (remainingSpace<0){
        return -1;
    }
    return remainingSpace;
};