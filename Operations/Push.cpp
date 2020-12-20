#include "Push.h"
#include "../Factory/OperationMaker.h"

OPERATION(Push, PUSH);

void Push::execute(std::list<std::string> &args, Context &ctx) const {
    if (args.empty()) {
        throw WrongInput();
    }

    std::string id = args.front();
    bool isNumber = false;
    for (char i : id) {
        if (isdigit(i)) {
            isNumber = true;
            break;
        }
    }

    if (isNumber) {
        ctx.operands.push(atof(id.c_str()));
        return;
    } else if (ctx.defines.find(id) != ctx.defines.end()) {
        ctx.operands.push(ctx.defines[id]);
        return;
    }

    throw WrongInput();
}
