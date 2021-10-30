#define f_cpu 16000000UL
#define baudrate 9600
#define Baud_prescale ((f_cpu/(baudrate*8UL))-1)

void setup() {
  // put your setup code here, to run once:
  UCSR0A |= B00000010 ;
  UCSR0B |= B10011000 ;         /* Enable USART transmitter and receiver */
  UCSR0C |= B00000110; /* Write USCRC for 8 bit data and 1 stop bit */ 
  UBRR0L = Baud_prescale;              /* Load UBRRL with lower 8 bit of prescale value */
  UBRR0H = (Baud_prescale >> 8); 
  sei();
  DDRB |= B00100000 ;
}

ISR(USART_RX_vect) {
  char temp;
  temp = UDR0 ;
  UDR0 = temp;
  if (temp == '2')
  {
    PORTB |= B00100000; 
  }
  else
  {
    PORTB &= B11011111;
  }

}

void loop() {
  // put your main code here, to run repeatedly:
}
