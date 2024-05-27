#include "errors.h"

PurchaseException::PurchaseException(const std::string& message)
        : std::runtime_error(message) {}

InvalidInputException::InvalidInputException(const std::string& message)
        : PurchaseException("Invalid input error: " + message) {}

InsufficientPointsException::InsufficientPointsException(const std::string& message)
        : PurchaseException("Insufficient points error: " + message) {}

NegativePointsException::NegativePointsException(const std::string& message)
        : PurchaseException("Negative points: " + message) {}