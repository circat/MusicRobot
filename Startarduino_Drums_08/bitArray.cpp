#include "bitArray.h"

bitArray::bitArray(){} //this constructor allows the usor to create a variable without defining any inputs

//this constructor allows the usor to define each bit that they want to store. The bits are entered in reverse order, with the most important (leftmost) bit being entered first, in the same way as any other array works
bitArray::bitArray (byte one, byte two, byte three, byte four, byte five, byte six, byte seven, byte eight){ 
    bitWrite(data, 7, one); //we write byte one to the first (most significant) bit of our byte
    bitWrite(data, 6, two);
    bitWrite(data, 5, three);
    bitWrite(data, 4, four);
    bitWrite(data, 3, five);
    bitWrite(data, 2, six);
    bitWrite(data, 1, seven);
    bitWrite(data, 0, eight);
}

//Used to write a bit to the array
void bitArray::writeBit(byte location, byte input){
    location = 7 - location; //we convert the location so that we can use it with bitWrite
    bitWrite(data, location, input);
}

//used to read a bit from the array. The location is worked from the left (the most important bit will be at location 0
byte bitArray::readBit(byte location){
    location = 7 - location; //we convert the location so that we can use it with bitWrite
    return bitRead(data, location) ; //we return the bit using arduino's built in bitRead function
}
