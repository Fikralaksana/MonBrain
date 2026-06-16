#include "utils.h"
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

/**
 * @brief Compose a given vector of string into a formatted row
 *
 * This function join a given vector into a single string that formatted into a column
 *
 * @param columns The given vector of string.
 *
 * @return a single formatted string
 *
 * @details
 *  1. set default column width
 *  2. set row as empty string
 *  3. loop each items in columns vector
 *  4. add column item into row
 *  5. add extra space needed to made up to column width
 *  6. after all loop complete add extra new line (mark the row is completed)
 *
 * @usage
 * std::vector<std::string>  v = {"column1","column2"};
 * int row = composeRow(v); // result will be "column1             column1             "
 */
std::string composeRow(std::vector<std::string>& columns){
    int columnWidth=20;
    std::string row;
    for (std::string column:columns){
        int remainingSpace = getRemainingSpaceForRenderingColumn(column,columnWidth);
        row += column+std::string(remainingSpace,' ');
    }
    row += "\n";
    return row;
}