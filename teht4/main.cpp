#include <iostream>
#include "asunto.h"
#include "kerros.h"
#include "katutaso.h"
#include "kerrostalo.h"

using namespace std;

int main()
{
    kerrostalo k_talo;
    cout << "Maaritetaan kerrostalon kaikkien kerrosten asunnot" << endl;
    k_talo.kerros1.maaritaAsunnot();
    k_talo.kerros2.maaritaAsunnot();
    k_talo.kerros3.maaritaAsunnot();
    k_talo.laskeKulutus(1);

    return 0;
}
