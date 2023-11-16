#ifndef __MD2_PARSER_H
#define __MD2_PARSER_H
#ifdef __cplusplus
extern "C"{
#endif

#include "md2.h"

unsigned int parseMD2(struct MD2 *md2, char *buffer, unsigned int size);

#ifdef __cplusplus
}
#endif
#endif
