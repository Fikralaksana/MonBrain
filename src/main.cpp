#include <iostream>
#include <ctime>
#include <string>
#include "Ledger/ledger.h"

/*
This is main executable.
In here this system should be able track new transaction.
A transaction can be a debit or credit

Debit is when the assets increase after transaction. 
We can say that, any funds that coming in into an account vault debit.

Credit is when the assets decrease after transaction.
We can say that, any funds that coming out from an account vault is credit.

*/ 


int main()
{


    std::cout << "Hello World";
    Ledger ledger=Ledger();
    ledger.showRecentEntries();

    return 0;
}