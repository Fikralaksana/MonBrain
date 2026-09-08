#include <vector>
#include <string>
#include "Ledger/ledger.h"
class CLIHandlers
{
private:
    Ledger ledger = Ledger();

public:
    int add(std::vector<std::string> &args);
};