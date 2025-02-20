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
    BitWriter(std::ostream& os) : out(os), buffer(0), bitCount(0) {}
    void writeBit(bool bit) {
        buffer = (buffer << 1) | (bit ? 1 : 0);
        bitCount++;
        if (bitCount == 8) {
            out.put(buffer);
            bitCount = 0;
            buffer = 0;
        }
    }
    void flush() {
        if (bitCount > 0) {
            buffer = buffer << (8 - bitCount);
            out.put(buffer);
            bitCount = 0;
            buffer = 0;
        }
    }
};
#endif