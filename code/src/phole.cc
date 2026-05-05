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

CNFFormula at_most_seq_count(VariableAllocator& va, std::vector<Lit>& x, unsigned k) {
    CNFFormula f;
    unsigned** s = va.allocate(x.size()-1, k);

    f.readClause({ ~x[0], Lit(s[0][0]) });
    for (unsigned i = 1; i < k; i++) {
        f.readClause({ ~Lit(s[0][i]) });
    }
    for (unsigned i = 1; i < x.size()-1; i++) {
        f.readClause({ ~x[i], Lit(s[i][0]) });
        f.readClause({ ~Lit(s[i-1][0]), Lit(s[i][0]) });
        for (unsigned j = 1; j < k; j++) {
            f.readClause({ ~x[i], ~Lit(s[i-1][j-1]), Lit(s[i][j]) });
            f.readClause({ ~Lit(s[i-1][j]), Lit(s[i][j]) });
        }
        f.readClause({ ~x[i], ~Lit(s[i-1][k-1]) });
    }
    f.readClause({ ~x[x.size()-1], ~Lit(s[x.size()-2][k-1]) });

    return f;
}

CNFFormula encode_pigeonhole_optimized(unsigned m, unsigned n) {
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
        std::vector<Lit> pigeonsInHoleJ;
        for (unsigned i = 0; i < m; i++) { // for each pigeon
            pigeonsInHoleJ.push_back(Lit(vars[i][j]));
        }
        CNFFormula atMostOnePigeonInHoleJ = at_most_seq_count(va, pigeonsInHoleJ, 1);
        f.append(atMostOnePigeonInHoleJ);
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
    // CNFFormula f = encode_pigeonhole(m, n);
    CNFFormula f = encode_pigeonhole_optimized(m, n);

    // Print the resulting CNF formula in DIMACS format
    f.printDimacs(std::cout);

    return 0;
}