#include "Push.h"
#include "../Factory/OperationMaker.h"

OPERATION(Push, PUSH);

void Push::execute(std::list<std::string> &args, Context &ctx) const {
    if (args.empty()) {
        throw WrongInput();
    }

    std::string number = args.front();
    bool isNumber = false;
    for (char i : number) {
        if (isdigit(i)) {
            isNumber = true;
            break;
        }
    }

    if (isNumber) {
        try {
            ctx.operands.push(stof(number));
        } catch (std::invalid_argument &ex) {
            throw WrongInput();
            }
        } else if (ctx.defines.find(number) != ctx.defines.end()) {
            ctx.operands.push(ctx.defines[number]);
    }
}
