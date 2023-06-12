
// PIC12F683 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTOSCCLK // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Detect (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define DATA GP4
#define CLOK GP5
#define LOAD GP2

int main(void){
    void maxBright();
}

void regInput(){
    uint8_t data;
    for(data=0x2; data<=4; data<<1){
        CLOK=0;
        DATA=data & 0b1;
        CLOK=1;
    }
    CLOK=0;
    
    return;
}

void datOutput(uint8_t data, unsigned int n){
    for(unsigned int i=0; i<n; i++, data>>1){
        CLOK=0;
        DATA=data & 0b1;
        CLOK=1;
    }
    CLOK=0;
    
    return;
}

void maxBright(void){
    regInput();
    datOutput(0x00, 4);
    datOutput(0x0f, 8);
    
    return;
}