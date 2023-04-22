#include "mbed.h"
#include "C12832.h"

// Initialize the C12832 display object
C12832 lcd(p5, p7, p6, p8, p11);

// Initialize the PwmOut object for the LED1 pin and the AnalogIn object for the potentiometer pin
PwmOut led1(LED1);
AnalogIn pot1(p19);

int main() {
    while(1) {
        // Set the duty cycle of the LED1 pin to the current potentiometer value
        led1 = pot1;

        // Clear the previous display output and set the cursor position for the first line
        lcd.cls();
        lcd.locate(0,0);

        // Print the potentiometer value with two decimal places on the first line
        lcd.printf("Pot value: %.2f", pot1.read());

        // Set the cursor position for the second line
        lcd.locate(0,10);

        // Print the potentiometer value in scientific notation with two decimal places on the second line
        lcd.printf("Pot value: %.2e", pot1.read());

        // Pause the program for 0.01 seconds before repeating the loop
        wait(0.01);
    }
}
