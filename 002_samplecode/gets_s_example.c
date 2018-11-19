#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include "libsafec/safe_lib.h"

int main(void)
{
    char buf[16];

<<<<<<< HEAD
    puts( "Please, enter your name\n" );
=======
    puts( "please, enter your name\n" );
>>>>>>> 9032e578526e854442d439227adffaacaede886f
    gets_s( buf, sizeof(buf) );
    puts( buf );

    return 0;
}

