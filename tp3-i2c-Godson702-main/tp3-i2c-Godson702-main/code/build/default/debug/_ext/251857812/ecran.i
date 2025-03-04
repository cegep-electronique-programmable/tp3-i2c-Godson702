# 1 "../../../tp2_b.X/ecran.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "../../../tp2_b.X/ecran.c" 2








# 1 "../../../tp2_b.X/ecran.h" 1
# 15 "../../../tp2_b.X/ecran.h"
void ecranAllume(void);

void ecranEteint(void);

void curseurposition(int Position);

void ecrireCaractere(char caractere);

void videEcran(void);
# 9 "../../../tp2_b.X/ecran.c" 2




void ecranAllume(void)
{

    EUSART1_Write(0x41);
}

void ecranEteint(void)
{

    EUSART1_Write(0x42);
}

void curseurposition(int Position)
{

    EUSART1_Write(0x45);
    EUSART1_Write(Position);


}

void ecrireCaractere(char caractere)
{

    EUSART1_Write(caractere);

}

void videEcran(void)
{
    EUSART1_Write(0xFE);
    EUSART1_Write(0x51);


}
