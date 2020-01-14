//=============================================================================//
//       Leitura de dois canais do conversor A/D   PIC 16f1827                 //
// Autor: Eng. Bruno Samuel Luiz de Oliveira                                   //                                                
// Compilador: PCWHD v5.080      Início: 30/11/2016    TÉRMINO: 30/11/2016     //
// Status: Finalizado                                                          //
//Demostração da estrutura minima para utilização do conversor A/D com dois    //
//canais no  pic 16f1827 com clock interno.                                    //
//=============================================================================//
#include <16F1827.h>                               // Define uC;               //
#device ADC=10                                     // Define numero de bits do //
                                                   // conversor A/D;           //
#fuses INTRC_IO,NOWDT,NOPUT,NOPROTECT,NOCPD,NOMCLR // Define fusíveis;         //
#use delay(internal=4000000)                       // Define clock interno de  //
                                                   // 4mhz;                    //
#use FIXED_IO( B_outputs=PIN_B4 )                  // Porta B de acesso rapido;//               
int16 Valor_AD_0;                                  // Var. conversor A/D 0;    //
int16 Valor_AD_1;                                  // Var. conversor A/D 1;    //
void main()                                        // Função principal;        //
{                                                                              //
setup_adc_ports(ALL_ANALOG | VSS_VREF);            // Config. conversor A/D;   //
setup_adc(ADC_CLOCK_DIV_2);                        // Tempo de clock A/C;      //
delay_ms(1000);                                    // Espera 1s;               //
set_tris_B(0x41);                                  // Config. porta B          //
while(TRUE)                                        // Loop infinito            //
   {                                                                           //
   set_adc_channel(0);                             // Seta canal 0 (A0) do A/D;//    
   delay_us(12);                                   // Espera 12us;             //
   Valor_AD_0= read_adc();                         // Atribui valor do A/D p/ a//
                                                   // var. Valor_AD_0;         //
   delay_ms(12);                                   // Espera 12us;             //
   set_adc_channel(1);                             // Seta canal 2 do A/D;     //    
   delay_us(12);                                   // Espera 12us;             //
   Valor_AD_1=read_adc();                          // Atribui valor do A/D p/ a//
                                                   // var.  Valor_AD_01;       //
   delay_ms(12);                                   // Espera 12us;             //
  }                                                                            //                                                                              //
}                                                                              //
//=============================================================================//
//  FIM                                                                        //
//=============================================================================//
