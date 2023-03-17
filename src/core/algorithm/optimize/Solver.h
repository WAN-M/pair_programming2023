//
// Created by DELL on 2023/3/17.
//

#ifndef CORE_SOLVER_H
#define CORE_SOLVER_H

namespace OPTIMIZE {
    class Solver {
    private:
        static int allWordlist(char **result);

        static int longestWords(char **result);

        static int longestAlphas(char **result);
    public:
        static int solve(char *result[]);
    };
}



#endif //CORE_SOLVER_H
