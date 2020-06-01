#include <avr/io.h>
#include <avr/interrupt.h>

int i = 0;

int up = 1;
int k1 = 0;
int k2 = 0;
int k3 = 0;

char i_LED = 0;

void Speed(){
	TCCR1B = 0x00;
	switch(k3){
		case 0: TCCR1B = 0x05; break;
		case 1: TCCR1B = 0x04; break;
		case 2: TCCR1B = 0x03; break;
	}
}

void Timers(){
	switch (k2){
		case 0:
		{
			DDRE = 0;
			DDRH = 0xFF;
			TCCR1B = 0x00;
			TIMSK1 = 1 << TOIE1;
			Speed();
			break;	
		}
		case 1:
		{
			DDRE = 0;
			DDRH = 0xFF;
			TCCR1B = 0x00;
			TIMSK1 = 1 << OCIE1A;
			OCR1A = 200;
			PORTH = 0b10101010;
			Speed();
			break;
		}
		case 2:
		{
			DDRH = 0;
			DDRB = 1 << 5;
			OCR1A = 200;
			TCCR1A = 1 << COM1A0;
			Speed();
			break;
		}
	}
	if (!k1){
		TCCR1B = 0x00;
		PORTH = 0;
		PORTE = 0;
	}
}

void Seting(){
	PCMSK0 = (1 << PCINT0) | (1 << PCINT1) | (1 << PCINT2);
	
	EIMSK = 1 << PCIE0;
	
	sei();
}

ISR(USART0_RX_vect)
{
	char rS = UDR0;
	
	switch (receivedSymbol)
	{
		case '1':
		{
			PORTC = 0xFF;	
			mainBtn = (mainBtn == 0) ? 1 : 0;
			TimersSettings();
			break;	
		}
		case '2':
		{
			if (modeOperating == 2)
			{
				modeOperating = 0;
			}
			else
			{
				modeOperating++;
			}
			
			TimersSettings();
			break;
		}
		case '3':
		{
			if (up)
			{
				modeSpeed++;
				up = (modeSpeed == 2) ? 0 : 1;
			}
			else
			{
				modeSpeed--;
				up = (modeSpeed == 0) ? 1 : 0;
			}
			
			ChangeSpeedMode();
			break;
		}
	}
}

ISR(PCINT0_vect){
	cli();

	//если нажата кнопка1, то включить/выключить гирлянду
	if (PINE & (1 << PINE0)){
		if (k1 == 0) k1 = 1; else k1 = 0;
		Timers();
	}
	
	//если  нажата кнопка2, то изменить режим
	if (PINE & (1 << PINE1)){
		if ( k2 == 3) k2 = 0; else k2++; 
		Timers();
	}
	
	//если нажата кнопка3, то изменить скорость
	if (PINE & (1 << PINE2)){
		if (up){
			k3++;
			if (k3 == 3) up = 0; else up = 1;
			}else {
			k3--;
			if (k3 == 0) up = 1; else up = 0;
		}
		Speed();
	}
	
	sei();
}

ISR (TIMER1_OVF_vect){
	PORTH  = 1 << i_LED;
	i_LED++;
	i_LED = i_LED % 8;
}

ISR (TIMER1_COMPA_vect){
	PORTH = ~PORTH;
	TCNT1 = 0;
}

int main(void)
{
	DDRH = 0xFF;
	DDRE = 0x00;
	
	Seting();

	//UBRR0 = 0x06;
	//UCSR0B = 1 << RXCIE0 | 1 << RXEN0;
	
	while (1) {
		//выключить все
		if (!k1) {
			PORTH = 0;
		}
	
		//первый режим
		if (k1 && (k2 == 0)){
			PORTH = (1 << i);
			Speed();
			if (i == 7) i = 0; else i++;
		}
	
		//второй режим
		if (k1 && (k2 == 1)){
			PORTH = 0b01010101;
			Speed();
			PORTH = 0b10101010;
			Speed();
		}
	
		//третий режим
		if (k1 && (k2 == 2)){
			PORTH = ~PORTH;
			Speed();
		}
	}
}


