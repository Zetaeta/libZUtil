
#ifndef ENDIAN_H
#define ENDIAN_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const bool bigEndian;

void swapEndian16(int16_t *);

void swapEndianu16(uint16_t *);

void swapEndian32(int32_t *);

void swapEndianu32(uint32_t *);

void swapEndian64(int64_t *);

void swapEndianu64(uint64_t *);

void swapEndianf(float *);

void swapEndiand(double *);

void swapEndianld(long double *);


void toBigEndian16(int16_t *);

void toBigEndianu16(uint16_t *);

void toBigEndian32(int32_t *);

void toBigEndianu32(uint32_t *);

void toBigEndian64(int64_t *);

void toBigEndianu64(uint64_t *);

void toBigEndianf(float *);

void toBigEndiand(double *);

void toBigEndianld(long double *);


void toLittleEndian16(int16_t *);

void toLittleEndianu16(uint16_t *);

void toLittleEndian32(int32_t *);

void toLittleEndianu32(uint32_t *);

void toLittleEndian64(int64_t *);

void toLittleEndianu64(uint64_t *);

void toLittleEndianf(float *);

void toLittleEndiand(double *);

void toLittleEndianld(long double *);


void fromBigEndian16(int16_t *);

void fromBigEndianu16(uint16_t *);

void fromBigEndian32(int32_t *);

void fromBigEndianu32(uint32_t *);

void fromBigEndian64(int64_t *);

void fromBigEndianu64(uint64_t *);

void fromBigEndianf(float *);

void fromBigEndiand(double *);

void fromBigEndianld(long double *);


void fromLittleEndian16(int16_t *);

void fromLittleEndianu16(uint16_t *);

void fromLittleEndian32(int32_t *);

void fromLittleEndianu32(uint32_t *);

void fromLittleEndian64(int64_t *);

void fromLittleEndianu64(uint64_t *);

void fromLittleEndianf(float *);

void fromLittleEndiand(double *);

void fromLittleEndianld(long double *);

#ifdef __cplusplus
}


void swapEndian(uint16_t &);

void swapEndian(int16_t &);

void swapEndian(uint32_t &);

void swapEndian(int32_t &);

void swapEndian(uint64_t &);

void swapEndian(int64_t &);

void swapEndian(float &);

void swapEndian(double &);

void swapEndian(long double &);


void toBigEndian(int16_t &);

void toBigEndian(uint16_t &);

void toBigEndian(int32_t &);

void toBigEndian(uint32_t &);

void toBigEndian(int64_t &);

void toBigEndian(uint64_t &);

void toBigEndian(float &);

void toBigEndian(double &);

void toBigEndian(long double &);


void toLittleEndian(int16_t &);

void toLittleEndian(uint16_t &);

void toLittleEndian(int32_t &);

void toLittleEndian(uint32_t &);

void toLittleEndian(int64_t &);

void toLittleEndian(uint64_t &);

void toLittleEndian(float &);

void toLittleEndian(double &);

void toLittleEndian(long double &);


void fromBigEndian(int16_t &);

void fromBigEndian(uint16_t &);

void fromBigEndian(int32_t &);

void fromBigEndian(uint32_t &);

void fromBigEndian(int64_t &);

void fromBigEndian(uint64_t &);

void fromBigEndian(float &);

void fromBigEndian(double &);

void fromBigEndian(long double &);


void fromLittleEndian(int16_t &);

void fromLittleEndian(uint16_t &);

void fromLittleEndian(int32_t &);

void fromLittleEndian(uint32_t &);

void fromLittleEndian(int64_t &);

void fromLittleEndian(uint64_t &);

void fromLittleEndian(float &);

void fromLittleEndian(double &);

void fromLittleEndian(long double &);

#endif

#endif
