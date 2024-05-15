
#ifndef OOP_ERORRS_H
#define OOP_ERORRS_H

#include <stdexcept>

class PurchaseException : public std::runtime_error {
public:
    explicit PurchaseException(const std::string& message = "Purchase Exception") : std::runtime_error(message) {}

};


class InvalidInputException : public std::invalid_argument {
public:
    explicit InvalidInputException(const std::string& message) : std::invalid_argument(message) {}
};

class InsufficientPointsException : public PurchaseException {
public:
    explicit InsufficientPointsException(const std::string& message) : PurchaseException(message) {}
};



#endif //OOP_ERORRS_H
