#include "mbed.h" // Definiciones de las clases utiles. En este caso particular nos interesa DigitalIn y DigitalOut 
#include "arm_book_lib.h"

/**
* @note:
* Viendo la definicion de la clase DigitalIn se observa:
*  - Tiene un atributo protegido llamado gpio que es el tipo gpio_t
*  - Los metodos son en su mayoria publicos, por lo que se pueden usar.
**/

int main()
{
   /**
   * @note: Se crea un objeto del tipo DigitalIn mediante el constructor DigitalIn(PinName pin) : gpio()
   * Se crea un DigitalIn conectado al pin especificado.
   * El constructor de esta clase esta sobrecargado y tiene otra implementacion que recibe como segundo armguemto
   * En dicha impementacion se crea un gpio_t que sera usado dentro del constructor de DigitalIn.
   * Hereda este metodo de 'gpio object'
   */ 
   DigitalIn gasDetector(D2);
   DigitalIn overTempDetector(D3);
   
   /**
   * @note: Se crea un objeto del tipo DigitalOut mediante el constructor DigitalOut(PinName pin) : gpio()
   * Crea un DigitalOut conectado al pin especificado.
   * El constructor de esta clase esta sobrecargado y tiene otra implementacion que recibe como segundo armguemto
   * En dicha impementacion se crea un gpio_t que sera usado dentro del constructor de DigitalOut.
   * Hereda este metodo de 'gpio object'
   */
   DigitalOut alarmLed(LED1);
   
   /**
   * @note; Seteo los modos de los DigitalIn.
   */
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
         printf("gasDetector: %d\n", gasDetector.read());
         alarmLed = OFF;
         printf("alarmLed: %d\n", alarmLed.read());
      }
   }
}