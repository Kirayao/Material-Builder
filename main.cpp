
#include "Structure.h"

using namespace std;

int main(int argc, char **argv) {
    Structure test(3,3,3,10);

    test.addBall(1,1,1,1);
    test.printSubstratetoFile("test.txt");


    return 0;
}
