#include <REGX52.H>
sbit OneWire_DQ = P3^7;// data quality

unsigned char OneWire_Init(){
	unsigned char i;
	unsigned char ACKBit;
  OneWire_DQ =1;
  OneWire_DQ =0;
	i = 227;while (--i); //delay 500us
  OneWire_DQ =1;
  i = 29;while (--i);	//delay 70us
	ACKBit = OneWire_DQ;
	i = 227;while (--i); //delay 500us
	return ACKBit;
}

void OneWire_SendBit(unsigned char Bit){
	unsigned char i;
  OneWire_DQ = 0;
	i = 2;while (--i); //delay 10us
	OneWire_DQ = Bit;
	i = 20;while (--i);//delay 50us
	 OneWire_DQ = 1;
}

unsigned char OneWire_ReceiveBit(){
  unsigned char i,Bit;
	OneWire_DQ = 0;
	i = 2;while (--i); //delay 10us
  OneWire_DQ = 1;
	i = 2;while (--i); //delay 10us
	Bit = OneWire_DQ;
	i = 20;while (--i);//delay 50us
	return Bit;
}

void OneWire_SendByte(unsigned char Byte){
	unsigned char i;
	for(i =0; i < 8; i++){
		OneWire_SendBit(Byte&(0x01<<i));
	}
}

unsigned char OneWire_ReceiveByte(){
	unsigned char i,Byte = 0x00;
	for(i =0; i <8; i++){
		if(OneWire_ReceiveBit()){Byte |=( 0x01<<i);}
	}
	return Byte;
}