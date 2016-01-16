#include "Aux.h"

int main(int argc, char *argv[]) {
    bool doExit;
    AlgRater algRater;

    do {
	doExit =doOneCommand(algRater);
    } while (!doExit);
}
