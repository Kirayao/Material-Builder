
#include "Structure.h"

using namespace std;

int main(int argc, char **argv) {
    Structure test;

    test.initSubstrate();
    test.addCube(1,1,1,1);
    test.printSubstrate();


    return 0;
}
