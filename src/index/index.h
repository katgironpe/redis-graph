#ifndef __INDEX_H__
#define __INDEX_H__

#include <assert.h>
#include "../redismodule.h"
#include "../graph/graph_entity.h"
#include "../stores/store.h"
#include "../util/skiplist.h"
#include "../parser/ast.h"
#include "../graph/node.h"
#include "../filter_tree/filter_tree.h"
#include "../parser/grammar.h" // required for the definition of filter operations (LT, GT, etc)
#include "../arithmetic/tuples_iter.h"

#define INDEX_PREFIX "redis_graph_INDEX"

#define Index_DEPLETED (GrB_Index)SKIPLIST_DEPLETED

typedef skiplistIterator IndexIter;

typedef struct {
  char *label;
  char *property;
  skiplist *string_sl;
  skiplist *numeric_sl;
} Index;

void Index_Delete(RedisModuleCtx *ctx, const char *graphName, const char *label, const char *prop);
void Index_Create(RedisModuleCtx *ctx, const char *graphName, Graph *g, const char *label, const char *prop_str);

/* Select an Index and range based on filters associated with Node */
IndexIter* Index_IntersectFilters(RedisModuleCtx *ctx, const char *graphName, Vector *filters, const char *label);

char* Index_OpPrint(AST_IndexNode *indexNode);

GrB_Matrix IndexIter_BuildMatrix(IndexIter *iter, size_t node_count);

void* IndexIter_Next(IndexIter *iter);
void IndexIter_Free(IndexIter *iter);
void IndexIter_Free(IndexIter *iter);

void Index_Free(Index *idx);

#endif