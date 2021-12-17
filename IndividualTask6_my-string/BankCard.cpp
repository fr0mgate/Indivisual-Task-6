#include "BankCard.h"

BankCard::BankCard() :
    holderName_(""),
    holderSurname_(""),
    number_(""),
    validityPeriodMounth_(""),
    validityPeriodYear_("")
{}

BankCard::BankCard(const String& holderName, const String& holderSurname,
    const String& number, const String& validityPeriodMounth,
    const String& validityPeriodYear) :
    holderName_(holderName),
    holderSurname_(holderSurname),
    number_(number),
    validityPeriodMounth_(validityPeriodMounth),
    validityPeriodYear_(validityPeriodYear)
{}

const BankCard& BankCard::operator= (const BankCard& other) {
    if (this != &other) {
        holderName_ = other.holderName_;
        holderSurname_ = other.holderSurname_;
        number_ = other.number_;
        validityPeriodMounth_ = other.validityPeriodMounth_;
        validityPeriodYear_ = other.validityPeriodYear_;;
    }
    return *this;
}

void BankCard::setHolderName(const String& holderName)
{
    holderName_ = holderName;
}

String BankCard::getHolderName() const
{
    return holderName_;
}

void BankCard::setHolderSurname(const String& holderSurname)
{
    holderSurname_ = holderSurname;
}

String BankCard::getHolderSurname() const
{
    return holderSurname_;
}

void BankCard::setNumber(const String& number) {
    number_ = number;
}

String BankCard::getNumber() const {
    return number_;
}

char BankCard::getFinancialInstitutionTypeID() const {
    return number_[0];
}

void BankCard::setValidityPeriodMounth(const String& validityPeriodMounth) {
    validityPeriodMounth_ = validityPeriodMounth;
}

String BankCard::getValidityPeriodMounth() const {
    return validityPeriodMounth_;
}

void BankCard::setValidityPeriodYear(const String& validityPeriodYear) {
    validityPeriodYear_ = validityPeriodYear;
}

String BankCard::getValidityPeriodYear() const {
    return validityPeriodYear_;
}

std::ostream& operator<< (std::ostream& output, const BankCard& card) {
    output << card.holderName_ << ' ' << card.holderSurname_ << ' ' << card.number_
        << ' ' << card.validityPeriodMounth_ << '/' << card.validityPeriodYear_;

    return output;
}

bool BankCard::operator== (const BankCard& other) {
    return holderName_ == other.holderName_
        && holderSurname_ == other.holderSurname_
        && number_ == other.number_
        && validityPeriodMounth_ == other.validityPeriodMounth_
        && validityPeriodYear_ == other.validityPeriodYear_;
}

bool BankCard::operator!= (const BankCard& other) {
    return !(holderName_ == other.holderName_
        && holderSurname_ == other.holderSurname_
        && number_ == other.number_
        && validityPeriodMounth_ == other.validityPeriodMounth_
        && validityPeriodYear_ == other.validityPeriodYear_);
}

bool BankCard::operator< (const BankCard& other) {
    if (holderName_ != other.holderName_)
        return holderName_ < other.holderName_;
    if (holderSurname_ != other.holderSurname_)
        return holderSurname_ < other.holderSurname_;
    if (number_ != other.number_)
        return number_ < other.number_;
    if (validityPeriodMounth_ != other.validityPeriodMounth_)
        return validityPeriodMounth_ < other.validityPeriodMounth_;
    else
        return validityPeriodYear_ < other.validityPeriodYear_;
}

bool BankCard::operator> (const BankCard& other) {
    if (holderName_ != other.holderName_)
        return holderName_ > other.holderName_;
    if (holderSurname_ != other.holderSurname_)
        return holderSurname_ > other.holderSurname_;
    if (number_ != other.number_)
        return number_ > other.number_;
    if (validityPeriodMounth_ != other.validityPeriodMounth_)
        return validityPeriodMounth_ > other.validityPeriodMounth_;
    else
        return validityPeriodYear_ > other.validityPeriodYear_;
}

bool BankCard::operator<= (const BankCard& other) {
    if (holderName_ != other.holderName_)
        return holderName_ < other.holderName_;
    if (holderSurname_ != other.holderSurname_)
        return holderSurname_ < other.holderSurname_;
    if (number_ != other.number_)
        return number_ < other.number_;
    if (validityPeriodMounth_ != other.validityPeriodMounth_)
        return validityPeriodMounth_ < other.validityPeriodMounth_;
    if (validityPeriodYear_ != other.validityPeriodYear_)
        return validityPeriodYear_ < other.validityPeriodYear_;
    return true;
}

bool BankCard::operator>= (const BankCard& other) {
    if (holderName_ != other.holderName_)
        return holderName_ > other.holderName_;
    if (holderSurname_ != other.holderSurname_)
        return holderSurname_ > other.holderSurname_;
    if (number_ != other.number_)
        return number_ > other.number_;
    if (validityPeriodMounth_ != other.validityPeriodMounth_)
        return validityPeriodMounth_ > other.validityPeriodMounth_;
    if (validityPeriodYear_ != other.validityPeriodYear_)
        return validityPeriodYear_ > other.validityPeriodYear_;
    return true;
}