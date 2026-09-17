#ifndef INPUT_H
#define INPUT_H
#include <stdbool.h>
#include "types.h"

bool selpos(char sel[8]);
bool charpos(const char sel[8], pos *out);

#endif
