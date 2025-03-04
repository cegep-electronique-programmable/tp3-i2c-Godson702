/**

  @Nom du fichier
    main.c

  @Auteur
 Godson Lorvius
   
  @Sommaire
    Programme qui écrit à l?écran I2C et qui lit et ecrit a l'EEPROM

*/

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/i2c_master.h"
#define ADDRESSE_I2C_ECRAN  0x28    // adresse interne de l'ecran
#define ADDRESSE_I2C_EEPROM  0x50   // adresse interne de l'EEPROM
/*
    Début de l'application principale
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    //uint8_t message[4]={"test"};(pour la premiere partie du laboratoire)
    uint8_t tableau_ecriture[6];
    tableau_ecriture[0]=0x0E; //adresse HIgh
    tableau_ecriture[1]=0xCD; //adresse Low
    tableau_ecriture[2]='t';
    tableau_ecriture[3]='e';
    tableau_ecriture[4]='s';
    tableau_ecriture[5]='t';
    
    uint8_t tableau_lecture[6];
    tableau_lecture[0]=0x0E; //adresse HIgh
    tableau_lecture[1]=0xCD; //adresse Low
    while (1)
    {
        
        /*// Code qui écrit 3 caractères sur l'écran (premiere partie du laboratoire)
         
        while(I2C_Open(ADDRESSE_I2C_ECRAN) == I2C_BUSY);    //Passage de l'adresse
        I2C_SetBuffer(message, 4);                          //Passage des données
        I2C_MasterOperation(0);                             //Démarrer une opération d'écriture
        while (I2C_Close() == I2C_BUSY);                   	//Attendre que l'opération soit complète    

        __delay_ms(1000);
        
        */
        
        
        //Code qui lit 6 octets de la mémoire EEPROM
        
        // ÉCriture de deux octets de données à la EEPROM
        while(I2C_Open(ADDRESSE_I2C_EEPROM) == I2C_BUSY);   //passage de l?adresse I2C
        I2C_SetBuffer(tableau_ecriture,6);				//passage de l?adresse interne sur 2 octets
        I2C_MasterOperation(0);				//opération d?écriture pour l?adresse interne
        while (I2C_Close() == I2C_BUSY);
        __delay_ms(1000);

       // Lecture de 4 octets de la EEPROM
        while(I2C_Open(ADDRESSE_I2C_EEPROM) == I2C_BUSY);	//passage de l?adresse I2C
        I2C_SetBuffer(tableau_ecriture, 2);			//passage du tampon et du nombre de lectures à faire
        I2C_MasterOperation(0);		
        I2C_SetBuffer(tableau_lecture, 4);	
        I2C_MasterOperation(1);                     //opération de lecture
        while (I2C_Close() == I2C_BUSY);
        __delay_ms(5);
        
       while(I2C_Open(ADDRESSE_I2C_ECRAN) == I2C_BUSY);	//passage de l?adresse I2C
       I2C_SetBuffer(tableau_lecture, 4);			//passage du tampon et du nombre de lectures à faire
       I2C_MasterOperation(0);		//opération de lecture
       while (I2C_Close() == I2C_BUSY);
       __delay_ms(1000);

    }
    
}
