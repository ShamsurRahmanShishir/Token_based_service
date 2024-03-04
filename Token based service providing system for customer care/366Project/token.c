#include <mega32.h>
#include <delay.h>
#define data_ddr DRRC
#define data_port PORTC
#define control_ddr DDRD
#define control_port PORTD
#define data_ddr DRRA
#define data_port PORTA
#define control_ddr DDRB
#define control_port PORTB
 
interrupt [EXT_INT0] void ext_int0_isr(void)
{

char i=45,a=57,i1,i2,a1,a2,press=0;
 char digit_cathod[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
 char digit0,digit1,digit2,digit3;
 

void seperate_digits(void)
{

i1=i%10;
 i2=i/10;
 a1=a%10;
 a2=a/10;

}

void display_digits(void)
{
 PORTD=0b01111111;
 PORTC=digit_cathod[i1];
 delay_ms(10);
 PORTD=0b10111111;
 PORTC=digit_cathod[i2];
 delay_ms(10); 
 PORTD=0b11011111;
 PORTC=digit_cathod[a1];
 delay_ms(10);  
 PORTD=0b11101111;
 PORTC=digit_cathod[a2];
 delay_ms(10);
}

PORTC=0;
PORTD=0xF0;
}


interrupt [EXT_INT1] void ext_int1_isr(void)
{
char i=30,a=81,i1,i2,a1,a2,press=0;
 
 #asm("sei)

void seperate_digits(void)
{

i1=i%10;
 i2=i/10;
 a1=a%10;
 a2=a/10;
 
}

void display_digits(void)
{
 PORTB=0b01111111;
 PORTA=digit_cathod[i1];
 delay_ms(10);
 PORTB=0b10111111;
 PORTA=digit_cathod[i2];
 delay_ms(10); 
 PORTB=0b11011111;
 PORTA=digit_cathod[a1];
 delay_ms(10);  
 PORTB=0b11101111;
 PORTA=digit_cathod[a2];
 delay_ms(10);
}

PORTA=0;
PORTB=0xF0;
}
void main(void)
{

DDRA=0xFF;
DDRC=0xFF;
DDRD=0xF0;
DDRB=0xF0;
PORTA=0xFF;
PORTC=0xFF;
PORTB=0xF0;
PORTD=0xFO;
GICR|=(1<<INT1) | (1<<INT0) | (0<<INT2);
MCUCR=(1<<ISC11) | (0<<ISC10) | (1<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);
GIFR=(1<<INTF1) | (1<<INTF0) | (0<<INTF2);
#asm("sei")
while (1)
      {
       // Place your code here
      }
}