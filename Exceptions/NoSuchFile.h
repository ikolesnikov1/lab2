#pragma once
#include "EvaluatorException.h"

class NoSuchFile : public EvaluatorException {
public:
    NoSuchFile() : EvaluatorException("No such file!"){};
};