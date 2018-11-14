//
//  bitArray.h
//  
//
//  Created by Jacob W. Unwin on 03/08/2013.
//
//

#ifndef _bitArray_h
#define _bitArray_h

#include "Arduino.h"

class bitArray {
    byte data;
public:
    bitArray();
    bitArray (byte one, byte two, byte three, byte four, byte five, byte six, byte seven, byte eight);
    void writeBit (byte location, byte data);
    byte readBit (byte location);
};


#endif
