#ifndef __OP_INDEX_SCAN_H
#define __OP_INDEX_SCAN_H

#include "op.h"
#include "../../graph/graph.h"
#include "../../graph/node.h"
#include "../../index/index.h"


typedef struct {
    OpBase op;
    Node **node;            /* node being scanned */
    Node *_node;
    Graph *g;
    GrB_Matrix M;
    TuplesIter *iter;
} IndexScan;

/* Creates a new IndexScan operation */
OpBase *NewIndexScanOp(QueryGraph *qg, Graph *g, Node **node, IndexIter *iter);
IndexScan* NewIndexScan(QueryGraph *qg, Graph *g, Node **node, IndexIter *iter);

/* IndexScan next operation
 * called each time a new node is required */
OpResult IndexScanConsume(OpBase *opBase, QueryGraph* graph);

/* Restart iterator */
OpResult IndexScanReset(OpBase *ctx);

/* Frees IndexScan */
void IndexScanFree(OpBase *ctx);

#endif