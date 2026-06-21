#include "../Database/base.h"
class LedgerModel : public BaseMigration {
    public:
        LedgerModel(){
            upgradeSQL = "CREATE TABLE IF NOT EXISTS ledger (\n"
                         "id     UUID PRIMARY KEY DEFAULT gen_random_uuid(),\n"
                         "groupId UUID DEFAULT gen_random_uuid(),\n"
                         "timestamp TIMESTAMPTZ,\n"
                         "accountID UUID DEFAULT gen_random_uuid(),\n" // TODO: change to foreignkey of account
                         "debit DOUBLE PRECISION,\n"
                         "credit DOUBLE PRECISION,\n"
                         "description VARCHAR(255)\n"
                         ");";

        }
};