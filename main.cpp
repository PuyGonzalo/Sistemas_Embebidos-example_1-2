#include "mbed.h" // Definiciones de las clases utiles. En este caso particular nos interesa DigitalIn y DigitalOut 
#include "arm_book_lib.h"

/**
Viendo la definicion de la clase DigitalIn se observa:
    - Tiene un atributo protegido llamado gpio que es el tipo gpio_t
    - Los metodos son en su mayoria publicos, por lo que se pueden usar.
**/

int main()
{
   DigitalIn gasDetector(D2);
   DigitalIn overTempDetector(D3);
   
   DigitalOut alarmLed(LED1);
   
   gasDetector.mode(PullDown);   
   overTempDetector.mode(PullDown);

   while (true) {
      
      if ( gasDetector || overTempDetector ) {
         printf("%s\n", "Se acciono el switch correspondiente a gasDetector O overTempDetector");
         printf("%s\n", " ");
         printf("gasDetector: %d\n", gasDetector.read());
         printf("%s\n", " ");
         alarmLed = ON;
         printf("alarmLed: %d\n", alarmLed.read());
      } else {
         printf("%s\n", "Nada accionado");
         printf("%s\n", " ");
         alarmLed = OFF;
         printf("alarmLed: %d\n", alarmLed.read());
      }
   }
}