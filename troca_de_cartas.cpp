#include <iostream>
using namespace std;

int main()
{
    int A, B, carta;
    bool cartasAlice[100000], cartasBeatriz[100000];

    while(cin >> A && A != 0 && cin >> B && B != 0)
    {
        int cartasTrocadasAlice = 0;
        int cartasTrocadasBeatriz = 0;

        for(int i = 0; i < 100000; i++)
        {
            cartasAlice[i] = cartasBeatriz[i] = false;
        }

        for(int i = 0; i < A; i++)
        {
            cin >> carta;
            cartasAlice[carta - 1] = true;
        }

        for(int i = 0; i < B; i++)
        {
            cin >> carta;
            cartasBeatriz[carta - 1] = true;
        }

        for(int i = 0; i < 100000; i++)
        {
            if(cartasAlice[i] == true && cartasBeatriz[i] == false)
            cartasTrocadasAlice += 1;

            if(cartasBeatriz[i] == true && cartasAlice[i] == false)
            cartasTrocadasBeatriz += 1;
        }

        int maxCartasTrocadas = cartasTrocadasAlice < cartasTrocadasBeatriz ? cartasTrocadasAlice : cartasTrocadasBeatriz;

        cout << maxCartasTrocadas << "\n";
    }

    return 0;
}
