#define UNUSED(x) (void)(x)

#include <stdio.h>
#include "signal_handlers.hpp"

void wc_detect(int sig)
{
    UNUSED(sig);
    printf("Я СЛЕЖУ ЗА ТОБОЙ, ТЫ ИЗМЕНИЛ РАЗМЕР ОКНА.\n");
}

