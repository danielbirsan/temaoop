
#ifndef OOP_ERORRS_H
#define OOP_ERORRS_H

#include <stdexcept>

#include <stdexcept>
#include <string>

class PurchaseException : public std::runtime_error {
public:
    explicit PurchaseException(const std::string& message);
};

class InvalidInputException : public PurchaseException {
public:
    explicit InvalidInputException(const std::string& message);
};

class InsufficientPointsException : public PurchaseException {
public:
    explicit InsufficientPointsException(const std::string& message);
};

class NegativePointsException : public PurchaseException {
public:
    explicit NegativePointsException(const std::string& message);
};

#endif //OOP_ERORRS_H
