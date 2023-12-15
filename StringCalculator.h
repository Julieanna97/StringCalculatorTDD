#ifndef __STRINGCALCULATOR_H_
#define __STRINGCALCULATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum
{
    RESULT_VALID,
    RESULT_EMPTY_STRING,
    RESULT_ONE_INPUT,
    RESULT_INVALID_NUMBER,

} CALCULATION_RESULT;

CALCULATION_RESULT Add(const char *sz);

#endif