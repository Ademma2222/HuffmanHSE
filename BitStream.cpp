#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <iostream>
#include <istream>
#include <ostream>

class BitWriter {
public:
    std::ostream& out;
    unsigned char buffer;
    int bitCount;
    BitWriter(std::ostream& os);
    void writeBit(bool bit);
    void flush();
};
#endif