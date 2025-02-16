#include "helper.h"

bool *Helper::convertToBoolArray(unsigned long num, int *size)
{
    // Jeśli num jest 0, chociaż pętla naturalnie wygeneruje 1 bit,
    // to chcemy mieć zawsze 4 bity (dla spójności z użyciem w main.cpp)
    int bitsCount = 0;
    unsigned long temp = num;
    if (temp == 0)
    {
        bitsCount = 1;
    }
    else
    {
        while (temp > 0)
        {
            ++bitsCount;
            temp >>= 1;
        }
    }
    // Dla liczb mniejszych niż 16 chcemy zawsze 4 bity
    if (bitsCount < 4)
    {
        bitsCount = 4;
    }
    if (size)
    {
        *size = bitsCount;
    }

    // Alokacja pamięci
    bool *bits = new bool[bitsCount];

    // Wypełnienie tablicy – zaznaczamy, że wynikiem ma być 4-bitowa reprezentacja.
    // Jeśli num ma mniej niż 4 bitów, wiodące bity ustawiamy na false.
    for (int i = bitsCount - 1; i >= 0; --i)
    {
        bits[i] = (num & 0x1);
        num >>= 1;
    }

    return bits;
}