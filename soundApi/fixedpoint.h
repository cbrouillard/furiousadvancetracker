/* 
 * File:   fixedpoint.h
 * Author: cyril
 *
 * Created on 14 décembre 2011, 17:09
 */

#ifndef FIXEDPOINT_H
#define	FIXEDPOINT_H

#include "hel2.h"

#define FIX_SHIFT 8
#define FIX_MASK 0x000000ff;

#ifdef	__cplusplus
extern "C" {
#endif

    typedef s32 FIXED; //! 32bit FIXED in 24.8 format

    // For other fixed formats, change FIX_SHIFT and the rest goes with it.


    //! Convert an integer to fixed-point

    inline FIXED int2fx(int d) {
        return d << FIX_SHIFT;
    }

    //! Convert a float to fixed-point
    //    inline FIXED float2fx(float f) {
    //        return (FIXED) (f * FIX_SCALEF);
    //    }


    //! Convert a fixed point value to an unsigned integer.
    inline u32 fx2uint(FIXED fx) {
        return fx >> FIX_SHIFT;
    }

    //! Get the unsigned fractional part of a fixed point value (orly?).
    inline u32 fx2ufrac(FIXED fx) {
        return fx&FIX_MASK;
    }

    //! Convert a FIXED point value to an signed integer.
    inline int fx2int(FIXED fx) {
        return fx / FIX_SCALE;
    }

    //! Convert a fixed point value to floating point.
    inline float fx2float(FIXED fx) {
        return fx / FIX_SCALEF;
    }





#ifdef	__cplusplus
}
#endif

#endif	/* FIXEDPOINT_H */

