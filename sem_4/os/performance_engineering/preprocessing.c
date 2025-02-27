#include <stdio.h>
// It is a macro that replaces all occurences of ONE with 1
#define ONE 1

// Macros can also behave like inline functions
#define MIN(a, b) (((a) > (b)) ? (b) : (a))
// The brackets are provided to preserve order of operations

int main()
{
    int c = ONE, d = ONE + 3;
    int e = MIN(c, d);

#ifndef DEBUG
    // This code will be compiled only when
    // the macro DEBUG is not defined.
    // Recall that if gcc is passed -DDEBUG on the command line,
    // then DEBUG will be defined.
    if (e == c)
    {
        printf("Debug: e is equal to c\n");
    }
#endif
    return 0;
}