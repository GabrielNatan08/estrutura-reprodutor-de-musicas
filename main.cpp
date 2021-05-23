#include <string.h>
#include <locale.h>
#include "funcoes.h"
#include "visor.h"

int main() {

    setlocale(LC_ALL, "portuguese");

    visor();

    return 0;
}
