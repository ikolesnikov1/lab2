#include "StackCalculator.h"

int main(int argc, char** argv) {
    if (argc == 2) {
        try {
            std::ifstream fin(argv[1]);
            if (!fin) {
                throw NoSuchFile();
            }

            StackCalculator::evaluate(fin);
        } catch (NoSuchFile &ex) {
            std::cerr << ex.what() << std::endl;
            StackCalculator::evaluate(std::cin);
        }
    }

    StackCalculator::evaluate(std::cin);
    return 0;
}