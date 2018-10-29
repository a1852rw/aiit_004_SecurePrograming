#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include "libsafec/safe_lib.h"

int main(void)
{
    char buf[16];

    puts( "‰½‚©“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B" );
    gets_s( buf, sizeof(buf) );
    puts( buf );

    return 0;
}

