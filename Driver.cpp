#include "Aux.h"

int main(int argc, char *argv[]) {
    bool doExit;
    AlgRater algRater;
    greeting();
    do {
	doExit = doOneCommand(algRater);
    } while (!doExit);
}
