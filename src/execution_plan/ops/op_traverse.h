#ifndef __OP_TRAVERSE_H
#define __OP_TRAVERSE_H

#include "op.h"
#include "../../rmutil/sds.h"
#include "../../parser/ast.h"
#include "../../arithmetic/algebraic_expression.h"
#include "../../rmutil/vector.h"
#include "../../arithmetic/tuples_iter.h"

/* OP Traverse */
typedef struct {
    OpBase op;
    Graph *graph;
    AlgebraicExpression *algebraic_expression;
    AlgebraicExpressionResult *algebraic_results;
    TuplesIter *it;
} Traverse;

/* Creates a new Traverse operation */
OpBase* NewTraverseOp(Graph *g, QueryGraph* qg, AlgebraicExpression *ae);
Traverse* NewTraverse(Graph *g, QueryGraph* qg, AlgebraicExpression *ae);

/* TraverseConsume next operation 
 * each call will update the graph
 * returns OP_DEPLETED when no additional updates are available */
OpResult TraverseConsume(OpBase *opBase, QueryGraph* graph);

/* Restart iterator */
OpResult TraverseReset(OpBase *ctx);

/* Frees Traverse*/
void TraverseFree(OpBase *ctx);

#endif