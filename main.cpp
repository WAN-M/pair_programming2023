#include "input/Scanner.h"
#include "var/Parameter.h"
#include "algorithm/Solver.h"
using namespace std;

int main(int argc,char *argv[]) {
    Scanner scanner(argc, argv);
    Parameter parameter;
    Solver solver;

    scanner.setParas(parameter);
    scanner.readFile(solver);
    solver.solve();

    return 0;
}
