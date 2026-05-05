// Encode pigeonhole principle as a SAT problem

#include <iostream>
#include <vector>
#include <string>

#include "util/VariableAllocator.h"
#include "util/CNFFormula.h"

CNFFormula encode_pigeonhole(unsigned m, unsigned n) {
    CNFFormula f;
    VariableAllocator va {};

    unsigned** vars = va.allocate(m, n);

    // Each pigeon is in *at least one* hole
    std::vector<Lit> clause;
    for (unsigned i = 0; i < m; i++) { // for each pigeon
        for (unsigned j = 0; j < n; j++) { // for each hole
            clause.push_back(Lit(vars[i][j]));
        }
        f.readClause(clause.begin(), clause.end());
        clause.clear();
    }

    // Each hole has *at most one* pigeon
    for (unsigned j = 0; j < n; j++) { // for each hole
        // at most one pigeon in hole j:
        for (unsigned i1 = 0; i1 < m; i1++) { // for each pigeon
            for (unsigned i2 = i1 + 1; i2 < m; i2++) { // for each other pigeon
                f.readClause({ ~Lit(vars[i1][j]), ~Lit(vars[i2][j]) }); 
            }
        }
    }

    return f;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <m> <n>" << std::endl;
        return 1;
    }

    // Read number of pigeons and holes from command line arguments
    int m = std::stoi(argv[1]);
    int n = std::stoi(argv[2]);

    // Encode the pigeonhole principle for m pigeons and n holes
    CNFFormula f = encode_pigeonhole(m, n);

    // Print the resulting CNF formula in DIMACS format
    f.printDimacs(std::cout);

    return 0;
}