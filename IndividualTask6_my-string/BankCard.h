#ifndef BANK_CARD_H
#define BANK_CARD_H

#include <ostream>
#include "String.h"

class BankCard
{
public:
    BankCard();
    BankCard(const String&, const String&, const String&,
        const String&, const String&);
    const BankCard& operator= (const BankCard&);

    void setHolderName(const String&);
    String getHolderName() const;
    void setHolderSurname(const String&);
    String getHolderSurname() const;

    void setNumber(const String&);
    String getNumber() const;
    char getFinancialInstitutionTypeID() const;

    void setValidityPeriodMounth(const String&);
    String getValidityPeriodMounth() const;
    void setValidityPeriodYear(const String&);
    String getValidityPeriodYear() const;

    friend std::ostream& operator<< (std::ostream&, const BankCard&);
    bool operator== (const BankCard&);
    bool operator!= (const BankCard&);
    bool operator< (const BankCard&);
    bool operator> (const BankCard&);
    bool operator<= (const BankCard&);
    bool operator>= (const BankCard&);

private:
    String holderName_;
    String holderSurname_;
    String number_;
    String validityPeriodMounth_;
    String validityPeriodYear_;
};

#endif // BANK_CARD_H
