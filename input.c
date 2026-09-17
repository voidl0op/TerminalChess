#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "types.h"
#include "input.h"

bool selpos(char sel[8]) {
    printf("Square (e.g. e2): ");
    return scanf("%7s", sel) == 1;
}

bool charpos(const char sel[8], pos *out) {
    if (strlen(sel) != 2) return false;

    char file = (char)tolower((unsigned char)sel[0]);
    char rank = sel[1];

    if (file < 'a' || file > 'h') return false;
    if (rank < '1' || rank > '8') return false;

    out->y = file - 'a';
    out->x = rank - '1';
    return true;
}
