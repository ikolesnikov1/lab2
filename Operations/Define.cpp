#include "Define.h"
#include "../Factory/OperationMaker.h"

OPERATION(Define, DEFINE);

void Define::execute(std::list<std::string> &args, Context &ctx) const {
    if (args.size() < 2) {
        throw WrongInput();
    }

    std::string id = args.front();
    std::string numberToDefine = args.back();

    bool wrongId = false;
    for (char i : id) {
        if (isdigit(i)) {
            wrongId = true;
            break;
        }
    }

    bool wrongNumber = false;
    for (char i : numberToDefine) {
        if (!isdigit(i)) {
            wrongNumber = true;
            break;
        }
    }

    if (wrongId) {
        throw WrongIdentifier();
    }

    if (wrongNumber) {
        throw WrongNumber();
    }

    ctx.defines[id] = atof(numberToDefine.c_str());
}
