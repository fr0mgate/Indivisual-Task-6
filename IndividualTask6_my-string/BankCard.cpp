#include "BankCard.h"

BankCard::BankCard() :
    holderName_("Name"),
    holderSurname_("Surname"),
    number_("0000000000000000"),
    validityPeriodMounth_("01"),
    validityPeriodYear_("01")
{}

BankCard::BankCard(const std::string& holderName, const std::string& holderSurname,
    const std::string& number, const std::string& validityPeriodMounth,
    const std::string& validityPeriodYear) :
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

void BankCard::setHolderName(const std::string& holderName)
{
    holderName_ = holderName;
}

std::string BankCard::getHolderName() const
{
    return holderName_;
}

void BankCard::setHolderSurname(const std::string& holderSurname)
{
    holderSurname_ = holderSurname;
}

std::string BankCard::getHolderSurname() const
{
    return holderSurname_;
}

void BankCard::setNumber(const std::string& number) {
    number_ = number;
}

std::string BankCard::getNumber() const {
    return number_;
}

char BankCard::getFinancialInstitutionTypeID() const {
    return number_[0];
}

void BankCard::setValidityPeriodMounth(const std::string& validityPeriodMounth) {
    validityPeriodMounth_ = validityPeriodMounth;
}

std::string BankCard::getValidityPeriodMounth() const {
    return validityPeriodMounth_;
}

void BankCard::setValidityPeriodYear(const std::string& validityPeriodYear) {
    validityPeriodYear_ = validityPeriodYear;
}

std::string BankCard::getValidityPeriodYear() const {
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
    if (holderName_ == other.holderName_
        && holderSurname_ == other.holderSurname_
        && number_ == other.number_
        && validityPeriodMounth_ == other.validityPeriodMounth_
        && validityPeriodYear_ == other.validityPeriodYear_) {
        return true;
    }
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

bool BankCard::operator>= (const BankCard& other) {
    if (holderName_ == other.holderName_
        && holderSurname_ == other.holderSurname_
        && number_ == other.number_
        && validityPeriodMounth_ == other.validityPeriodMounth_
        && validityPeriodYear_ == other.validityPeriodYear_) {
        return true;
    }
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