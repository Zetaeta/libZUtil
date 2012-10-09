
#include <iostream>
#include <stdlib.h>

#include "Endian.h"

bool isBigEndian() {
    unsigned char endianTest[] = {1, 0};
    short x = *(reinterpret_cast<short *>(endianTest));
    if (x == 256) {
        return true;
    }
    else if (x == 1) {
        return false;
    }
    else {
        std::cerr << "Error: invalid endian: x = " << x << ", must be 256 or 1";
        exit(1);
    }
}

extern const bool bigEndian = isBigEndian();

void swapEndian(int16_t &data) {
    uint8_t b1, b2;
    b1 = data & 0xFF;
    b2 = (data >> 8) & 0xFF;
    data = (b1 << 8) | b2;
}

void swapEndian(uint16_t &data) {
    uint8_t b1, b2;
    b1 = data & 0xFF;
    b2 = (data >> 8) & 0xFF;
    data = (b1 << 8) | b2;
}

void swapEndian(int32_t &data) {
    uint8_t b1, b2, b3, b4;
    b1 = data & 0xFF;
    b2 = (data >> 8) & 0xFF;
    b3 = (data >> 16) & 0xFF;
    b4 = (data >> 24) & 0xFF;
    data = (b1 << 24) | (b2 << 16) | (b3 << 8) | b4;
}

void swapEndian(uint32_t &data) {
    uint8_t b1, b2, b3, b4;
    b1 = data & 0xFF;
    b2 = (data >> 8) & 0xFF;
    b3 = (data >> 16) & 0xFF;
    b4 = (data >> 24) & 0xFF;
    data = (b1 << 24) | (b2 << 16) | (b3 << 8) | b4;
}

void swapEndian(uint64_t &data) {
    uint64_t b[8];
    b[0] = data & 0xFF;
    b[1] = (data >> 8) & 0xFF;
    b[2] = (data >> 16) & 0xFF;
    b[3] = (data >> 24) & 0xFF;
    b[4] = (data >> 32) & 0xFF;
    b[5] = (data >> 40) & 0xFF;
    b[6] = (data >> 48) & 0xFF;
    b[7] = (data >> 56) & 0xFF;
    data = (b[0] << 56) | (b[1] << 48) | (b[2] << 40) | (b[3] << 32) | (b[4] << 24) | (b[5] << 16) | (b[6] << 8) | b[7];
}

void swapEndian(int64_t &data) {
    uint64_t b[8];
    b[0] = data & 0xFF;
    b[1] = (data >> 8) & 0xFF;
    b[2] = (data >> 16) & 0xFF;
    b[3] = (data >> 24) & 0xFF;
    b[4] = (data >> 32) & 0xFF;
    b[5] = (data >> 40) & 0xFF;
    b[6] = (data >> 48) & 0xFF;
    b[7] = (data >> 56) & 0xFF;
    data = (b[0] << 56) | (b[1] << 48) | (b[2] << 40) | (b[3] << 32) | (b[4] << 24) | (b[5] << 16) | (b[6] << 8) | b[7];
}

void swapEndian(float &data) {
    union {
        float f;
        unsigned char b[4];
    } dat1, dat2;
    dat1.f = data;
    dat2.b[0] = dat1.b[3];
    dat2.b[1] = dat1.b[2];
    dat2.b[2] = dat1.b[1];
    dat2.b[3] = dat1.b[0];
    data = dat2.f;
}

void swapEndian(double &data) {
    union {
        double d;
        unsigned char b[8];
    } dat1, dat2;
    dat1.d = data;
    dat2.b[0] = dat1.b[7];
    dat2.b[1] = dat1.b[6];
    dat2.b[2] = dat1.b[5];
    dat2.b[3] = dat1.b[4];
    dat2.b[4] = dat1.b[3];
    dat2.b[5] = dat1.b[2];
    dat2.b[6] = dat1.b[1];
    dat2.b[7] = dat1.b[0];
    data = dat2.d;
}

void swapEndian(long double &data) {
    union {
        long double d;
        unsigned char b[16];
    } dat1, dat2;
    dat1.d = data;
    dat2.b[0] = dat1.b[15];
    dat2.b[1] = dat1.b[14];
    dat2.b[2] = dat1.b[13];
    dat2.b[3] = dat1.b[12];
    dat2.b[4] = dat1.b[11];
    dat2.b[5] = dat1.b[10];
    dat2.b[6] = dat1.b[9];
    dat2.b[7] = dat1.b[8];
    dat2.b[8] = dat1.b[7];
    dat2.b[9] = dat1.b[6];
    dat2.b[10] = dat1.b[5];
    dat2.b[11] = dat1.b[4];
    dat2.b[12] = dat1.b[3];
    dat2.b[13] = dat1.b[2];
    dat2.b[14] = dat1.b[1];
    dat2.b[15] = dat1.b[0];
    data = dat2.d;
}


void toBigEndian(int16_t &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}

void toBigEndian(uint16_t &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}

void toBigEndian(int32_t &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}

void toBigEndian(uint32_t &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}

void toBigEndian(int64_t &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}

void toBigEndian(uint64_t &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}

void toBigEndian(float &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}

void toBigEndian(double &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}

void toBigEndian(long double &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}


void toLittleEndian(int16_t &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}

void toLittleEndian(uint16_t &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}

void toLittleEndian(int32_t &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}

void toLittleEndian(uint32_t &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}

void toLittleEndian(int64_t &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}

void toLittleEndian(uint64_t &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}

void toLittleEndian(float &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}

void toLittleEndian(double &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}

void toLittleEndian(long double &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}


void fromBigEndian(int16_t &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}

void fromBigEndian(uint16_t &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}

void fromBigEndian(int32_t &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}

void fromBigEndian(uint32_t &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}

void fromBigEndian(int64_t &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}

void fromBigEndian(uint64_t &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}

void fromBigEndian(float &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}

void fromBigEndian(double &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}

void fromBigEndian(long double &val) {
    if (!bigEndian) {
        swapEndian(val);
    }
}


void fromLittleEndian(int16_t &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}

void fromLittleEndian(uint16_t &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}

void fromLittleEndian(int32_t &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}

void fromLittleEndian(uint32_t &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}

void fromLittleEndian(int64_t &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}

void fromLittleEndian(uint64_t &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}

void fromLittleEndian(float &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}

void fromLittleEndian(double &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}

void fromLittleEndian(long double &val) {
    if (bigEndian) {
        swapEndian(val);
    }
}


void swapEndian16(int16_t *val) {
    swapEndian(*val);
}

void swapEndianu16(uint16_t *val) {
    swapEndian(*val);
}

void swapEndian32(int32_t *val) {
    swapEndian(*val);
}

void swapEndianu32(uint32_t *val) {
    swapEndian(*val);
}

void swapEndian64(int64_t *val) {
    swapEndian(*val);
}

void swapEndianu64(uint64_t *val) {
    swapEndian(*val);
}

void swapEndianf(float *val) {
    swapEndian(*val);
}

void swapEndiand(double *val) {
    swapEndian(*val);
}

void swapEndianld(long double *val) {
    swapEndian(*val);
}


void toBigEndian16(int16_t *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void toBigEndianu16(uint16_t *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void toBigEndian32(int32_t *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void toBigEndianu32(uint32_t *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void toBigEndian64(int64_t *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void toBigEndianu64(int64_t *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void toBigEndianf(float *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void toBigEndiand(double *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void toBigEndianld(long double *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void toLittleEndian16(int16_t *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}

void toLittleEndianu16(uint16_t *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}

void toLittleEndian32(int32_t *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}

void toLittleEndianu32(uint32_t *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}

void toLittleEndian64(int64_t *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}

void toLittleEndianu64(int64_t *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}

void toLittleEndianf(float *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}

void toLittleEndiand(double *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}

void toLittleEndianld(long double *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}


void fromBigEndian16(int16_t *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void fromBigEndianu16(uint16_t *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void fromBigEndian32(int32_t *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void fromBigEndianu32(uint32_t *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void fromBigEndian64(int64_t *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void fromBigEndianu64(int64_t *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void fromBigEndianf(float *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void fromBigEndiand(double *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}

void fromBigEndianld(long double *val) {
    if (!bigEndian) {
        swapEndian(*val);
    }
}


void fromLittleEndian16(int16_t *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}

void fromLittleEndianu16(uint16_t *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}

void fromLittleEndian32(int32_t *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}

void fromLittleEndianu32(uint32_t *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}

void fromLittleEndian64(int64_t *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}

void fromLittleEndianu64(int64_t *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}

void fromLittleEndianf(float *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}

void fromLittleEndiand(double *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}

void fromLittleEndianld(long double *val) {
    if (bigEndian) {
        swapEndian(*val);
    }
}
