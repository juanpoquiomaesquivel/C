#ifndef JXINPUT_H_INCLUDED
#define JXINPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef JXI_DATA_TYPES
#define JXI_INTEGER 0
#define JXI_FLOAT 1
#define JXI_DOUBLE 2
#define JXI_CHARACTER 3
#define JXI_STRING 4
#endif

void *jxi_read(const char *fmt, const char *msg);

#endif // JXINPUT_H_INCLUDED
