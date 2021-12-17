#ifndef BANK_CARD_H
#define BANK_CARD_H

#include <string>
#include <ostream>

class BankCard
{
public:
    BankCard();
    BankCard(const std::string&, const std::string&, const std::string&,
        const std::string&, const std::string&);
    const BankCard& operator= (const BankCard&);

    void setHolderName(const std::string&);
    std::string getHolderName() const;
    void setHolderSurname(const std::string&);
    std::string getHolderSurname() const;

    void setNumber(const std::string&);
    std::string getNumber() const;
    char getFinancialInstitutionTypeID() const;

    void setValidityPeriodMounth(const std::string&);
    std::string getValidityPeriodMounth() const;
    void setValidityPeriodYear(const std::string&);
    std::string getValidityPeriodYear() const;

    friend std::ostream& operator<< (std::ostream&, const BankCard&);
    bool operator== (const BankCard&);
    bool operator< (const BankCard&);
    bool operator> (const BankCard&);
    bool operator<= (const BankCard&);
    bool operator>= (const BankCard&);

private:
    std::string holderName_;
    std::string holderSurname_;
    std::string number_;
    std::string validityPeriodMounth_;
    std::string validityPeriodYear_;
};

#endif // BANK_CARD_H
