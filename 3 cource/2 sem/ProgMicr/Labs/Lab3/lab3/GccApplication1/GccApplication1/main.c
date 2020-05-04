/*
 * GccApplication1.c
 *
 * Created: 26.03.2020 14:41:51
 * Author : Админ
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int i = 0;

int up = 1;

int k1 = 0;
int k2 = 0;
int k3 = 0;

ISR(PCINT_vect){
	//если нажата кнопка1, то включить/выключить гирлянду
	if (PINE & (1 << PINE0)){
		if (k1 == 0) k1 = 1; else k1 = 0;
	}
	
	//если  нажата кнопка2, то изменить режим
	if (PINE & (1 << PINE1)){
		if ( k2 == 3) k2 = 0; else k2++;
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
	}
}

void Speed(int k3){
	switch(k3){
		case 0: _delay_ms(100); break;
		case 1: _delay_ms(250); break;
		case 2: _delay_ms(500); break;
	}
}


int main(void)
{
	    DDRH = 0xFF;

	PCMSK0 = (1 << PCINT0) | (1 << PCINT1) | (1 << PCINT2);
	
	EIMSK = 0x11110001;
	
	sei();
	
    while (1) 
    {
		//выключить все
		if (!k1) {
			PORTH = 0;
			_delay_ms(200);
		}
		
		//первый режим
		if (k1 && (k2 == 0)){
			PORTH = (1 << i);
			Speed(k3);
			if (i == 7) i = 0; else i++;
		}
		
		//второй режим
		if (k1 && (k2 == 1)){
			PORTH = 0b01010101;
			Speed(k3);
			PORTH = 0b10101010;
			Speed(k3);
		}
		
		//третий режим
		if (k1 && (k2 == 2)){
			PORTH = ~PORTH;
			Speed(k3);
		}
    }
}

