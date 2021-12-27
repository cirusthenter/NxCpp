#include <exception>
#include <string>

using namespace std;

class NxCppException : public exception {
    /*
    Base class for exceptions in NxCpp
    */
};

class NxCppError : NxCppException {
    /*
    Exception for a serious error in NxCpp
    */
};

class NxCppPointlessConcept : NxCppException {
    /*
    Raised when a null graph is provided as input to an algorithm
    that cannot use it.

    The null graph is sometimes considered a pointless concept [1]_,
    thus the name of the exception.

    References
    ----------
    .. [1] Harary, F. and Read, R. "Is the Null Graph a Pointless
       Concept?"  In Graphs and Combinatorics Conference, George
       Washington University.  New York: Springer-Verlag, 1973.
    */
};

class NxCppAlgorithmError : NxCppException {
    /*
    Exception for unexpected termination of algorithms.
    */
};

class NxCppUnfeasible : NxCppAlgorithmError {
    /*
    Exception raised by algorithms trying to solve a problem
    instance that has no feasible solution.
    */
};

class NxCppNoPath : NxCppUnfeasible {
    /*
    Exception for algorithms that should return a path when running
     on graphs where such a path does not exist.
    */
};

class NxCppNoCycle : NxCppUnfeasible {
    /*
    Exception for algorithms that should return a cycle when running
    on graphs where such a cycle does not exist.
    */
};

class HasACycle : NxCppException {
    /*
    Raised if a graph has a cycle when an algorithm expects that it
    will have no cycles.
    */
};

class NxCppUnbounded : NxCppAlgorithmError {
    /*
    Exception raised by algorithms trying to solve a maximization
    or a minimization problem instance that is unbounded.
    */
};

class NxCppNotImplemented : NxCppException {
    /*
    Exception raised by algorithms not implemented for a type of graph.
    */
};

class NodeNotFound : NxCppException {
    /*
    Exception raised if requested node is not present in the graph
    */
};

class AmbiguousSolution : NxCppException {
    /*
    Raised if more than one valid solution exists for an intermediary step
     of an algorithm.
     In the face of ambiguity, refuse the temptation to guess.
     This may occur, for example, when trying to determine the
     bipartite node sets in a disconnected bipartite graph when
     computing bipartite matchings.
    */
};

class ExceededMaxIterations : NxCppException {
    /*
    Raised if a loop iterates too many times without breaking.
     This may occur, for example, in an algorithm that computes
     progressively better approximations to a value but exceeds an
     iteration bound specified by the user.
    */
};

class NotImplementedException {
    /*
    Exception for yet implemented functions
    */
};

class PowerIterationFailedConvergence : ExceededMaxIterations {
    /*
    Raised when the power iteration method fails to converge within a
     specified iteration limit.
     `num_iterations` is the number of iterations that have been
     completed when this exception was raised.
    */

    PowerIterationFailedConvergence(int num_iterations)
    {
        NotImplementedException();
    }
};