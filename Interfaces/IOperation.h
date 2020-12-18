#pragma once
#include <list>
#include "../Context.h"
#include "../Exceptions/AllExceptions.h"

#define OPERATION(T, NAME) static OperationMaker<T> maker(#NAME)

class IOperation {
public:
    virtual void execute(std::list<std::string> &arg, Context & ctx) const = 0;

    virtual ~IOperation() = default;
};
