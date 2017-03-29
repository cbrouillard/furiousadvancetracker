#ifndef _SOUND_API_SINLUT_
#define _SOUND_API_SINLUT_

#ifndef LUT_GENERIC_SIZE
#define LUT_GENERIC_SIZE 512
#endif

//
// Sine lut; 512 entries, 12 fixeds
//

const s8 snd_sin_lut[LUT_GENERIC_SIZE] = {

	0x0000, 0x0032, 0x0064, 0x0096, 0x00C8, 0x00FB, 0x012D, 0x015F,
	0x0191, 0x01C3, 0x01F5, 0x0227, 0x0259, 0x028A, 0x02BC, 0x02ED,
	0x031F, 0x0350, 0x0381, 0x03B2, 0x03E3, 0x0413, 0x0444, 0x0474,
	0x04A5, 0x04D5, 0x0504, 0x0534, 0x0563, 0x0593, 0x05C2, 0x05F0,
	0x061F, 0x064D, 0x067B, 0x06A9, 0x06D7, 0x0704, 0x0731, 0x075E,
	0x078A, 0x07B7, 0x07E2, 0x080E, 0x0839, 0x0864, 0x088F, 0x08B9,
	0x08E3, 0x090D, 0x0936, 0x095F, 0x0987, 0x09B0, 0x09D7, 0x09FF,
	0x0A26, 0x0A4D, 0x0A73, 0x0A99, 0x0ABE, 0x0AE3, 0x0B08, 0x0B2C,
	0x0B50, 0x0B73, 0x0B96, 0x0BB8, 0x0BDA, 0x0BFC, 0x0C1D, 0x0C3E,
	0x0C5E, 0x0C7D, 0x0C9D, 0x0CBB, 0x0CD9, 0x0CF7, 0x0D14, 0x0D31,
	0x0D4D, 0x0D69, 0x0D84, 0x0D9F, 0x0DB9, 0x0DD2, 0x0DEB, 0x0E04,
	0x0E1C, 0x0E33, 0x0E4A, 0x0E60, 0x0E76, 0x0E8B, 0x0EA0, 0x0EB4,
	0x0EC8, 0x0EDB, 0x0EED, 0x0EFF, 0x0F10, 0x0F21, 0x0F31, 0x0F40,
	0x0F4F, 0x0F5D, 0x0F6B, 0x0F78, 0x0F85, 0x0F91, 0x0F9C, 0x0FA7,
	0x0FB1, 0x0FBA, 0x0FC3, 0x0FCB, 0x0FD3, 0x0FDA, 0x0FE1, 0x0FE7,
	0x0FEC, 0x0FF0, 0x0FF4, 0x0FF8, 0x0FFB, 0x0FFD, 0x0FFE, 0x0FFF,
	0x1000, 0x0FFF, 0x0FFE, 0x0FFD, 0x0FFB, 0x0FF8, 0x0FF4, 0x0FF0,
	0x0FEC, 0x0FE7, 0x0FE1, 0x0FDA, 0x0FD3, 0x0FCB, 0x0FC3, 0x0FBA,
	0x0FB1, 0x0FA7, 0x0F9C, 0x0F91, 0x0F85, 0x0F78, 0x0F6B, 0x0F5D,
	0x0F4F, 0x0F40, 0x0F31, 0x0F21, 0x0F10, 0x0EFF, 0x0EED, 0x0EDB,
	0x0EC8, 0x0EB4, 0x0EA0, 0x0E8B, 0x0E76, 0x0E60, 0x0E4A, 0x0E33,
	0x0E1C, 0x0E04, 0x0DEB, 0x0DD2, 0x0DB9, 0x0D9F, 0x0D84, 0x0D69,
	0x0D4D, 0x0D31, 0x0D14, 0x0CF7, 0x0CD9, 0x0CBB, 0x0C9D, 0x0C7D,
	0x0C5E, 0x0C3E, 0x0C1D, 0x0BFC, 0x0BDA, 0x0BB8, 0x0B96, 0x0B73,
	0x0B50, 0x0B2C, 0x0B08, 0x0AE3, 0x0ABE, 0x0A99, 0x0A73, 0x0A4D,
	0x0A26, 0x09FF, 0x09D7, 0x09B0, 0x0987, 0x095F, 0x0936, 0x090D,
	0x08E3, 0x08B9, 0x088F, 0x0864, 0x0839, 0x080E, 0x07E2, 0x07B7,
	0x078A, 0x075E, 0x0731, 0x0704, 0x06D7, 0x06A9, 0x067B, 0x064D,
	0x061F, 0x05F0, 0x05C2, 0x0593, 0x0563, 0x0534, 0x0504, 0x04D5,
	0x04A5, 0x0474, 0x0444, 0x0413, 0x03E3, 0x03B2, 0x0381, 0x0350,
	0x031F, 0x02ED, 0x02BC, 0x028A, 0x0259, 0x0227, 0x01F5, 0x01C3,
	0x0191, 0x015F, 0x012D, 0x00FB, 0x00C8, 0x0096, 0x0064, 0x0032,
	0x0000, 0xFFCE, 0xFF9C, 0xFF6A, 0xFF38, 0xFF05, 0xFED3, 0xFEA1,
	0xFE6F, 0xFE3D, 0xFE0B, 0xFDD9, 0xFDA7, 0xFD76, 0xFD44, 0xFD13,
	0xFCE1, 0xFCB0, 0xFC7F, 0xFC4E, 0xFC1D, 0xFBED, 0xFBBC, 0xFB8C,
	0xFB5B, 0xFB2B, 0xFAFC, 0xFACC, 0xFA9D, 0xFA6D, 0xFA3E, 0xFA10,
	0xF9E1, 0xF9B3, 0xF985, 0xF957, 0xF929, 0xF8FC, 0xF8CF, 0xF8A2,
	0xF876, 0xF849, 0xF81E, 0xF7F2, 0xF7C7, 0xF79C, 0xF771, 0xF747,
	0xF71D, 0xF6F3, 0xF6CA, 0xF6A1, 0xF679, 0xF650, 0xF629, 0xF601,
	0xF5DA, 0xF5B3, 0xF58D, 0xF567, 0xF542, 0xF51D, 0xF4F8, 0xF4D4,
	0xF4B0, 0xF48D, 0xF46A, 0xF448, 0xF426, 0xF404, 0xF3E3, 0xF3C2,
	0xF3A2, 0xF383, 0xF363, 0xF345, 0xF327, 0xF309, 0xF2EC, 0xF2CF,
	0xF2B3, 0xF297, 0xF27C, 0xF261, 0xF247, 0xF22E, 0xF215, 0xF1FC,
	0xF1E4, 0xF1CD, 0xF1B6, 0xF1A0, 0xF18A, 0xF175, 0xF160, 0xF14C,
	0xF138, 0xF125, 0xF113, 0xF101, 0xF0F0, 0xF0DF, 0xF0CF, 0xF0C0,
	0xF0B1, 0xF0A3, 0xF095, 0xF088, 0xF07B, 0xF06F, 0xF064, 0xF059,
	0xF04F, 0xF046, 0xF03D, 0xF035, 0xF02D, 0xF026, 0xF01F, 0xF019,
	0xF014, 0xF010, 0xF00C, 0xF008, 0xF005, 0xF003, 0xF002, 0xF001,
	0xF000, 0xF001, 0xF002, 0xF003, 0xF005, 0xF008, 0xF00C, 0xF010,
	0xF014, 0xF019, 0xF01F, 0xF026, 0xF02D, 0xF035, 0xF03D, 0xF046,
	0xF04F, 0xF059, 0xF064, 0xF06F, 0xF07B, 0xF088, 0xF095, 0xF0A3,
	0xF0B1, 0xF0C0, 0xF0CF, 0xF0DF, 0xF0F0, 0xF101, 0xF113, 0xF125,
	0xF138, 0xF14C, 0xF160, 0xF175, 0xF18A, 0xF1A0, 0xF1B6, 0xF1CD,
	0xF1E4, 0xF1FC, 0xF215, 0xF22E, 0xF247, 0xF261, 0xF27C, 0xF297,
	0xF2B3, 0xF2CF, 0xF2EC, 0xF309, 0xF327, 0xF345, 0xF363, 0xF383,
	0xF3A2, 0xF3C2, 0xF3E3, 0xF404, 0xF426, 0xF448, 0xF46A, 0xF48D,
	0xF4B0, 0xF4D4, 0xF4F8, 0xF51D, 0xF542, 0xF567, 0xF58D, 0xF5B3,
	0xF5DA, 0xF601, 0xF629, 0xF650, 0xF679, 0xF6A1, 0xF6CA, 0xF6F3,
	0xF71D, 0xF747, 0xF771, 0xF79C, 0xF7C7, 0xF7F2, 0xF81E, 0xF849,
	0xF876, 0xF8A2, 0xF8CF, 0xF8FC, 0xF929, 0xF957, 0xF985, 0xF9B3,
	0xF9E1, 0xFA10, 0xFA3E, 0xFA6D, 0xFA9D, 0xFACC, 0xFAFC, 0xFB2B,
	0xFB5B, 0xFB8C, 0xFBBC, 0xFBED, 0xFC1D, 0xFC4E, 0xFC7F, 0xFCB0,
	0xFCE1, 0xFD13, 0xFD44, 0xFD76, 0xFDA7, 0xFDD9, 0xFE0B, 0xFE3D,
	0xFE6F, 0xFEA1, 0xFED3, 0xFF05, 0xFF38, 0xFF6A, 0xFF9C, 0xFFCE,
};

int lu_sin(u32 theta){return snd_sin_lut[(theta>>7)&0x1FF];}

//! Linear interpolator for 32bit LUTs.
/*! A lut is essentially the discrete form of a function, f(\i x).
*   You can get values for non-integer \i x via (linear)
*   interpolation between f(x) and f(x+1).
*   \param lut  The LUT to interpolate from.
*   \param x    Fixed point number to interpolate at.
*   \param shift    Number of fixed-point bits of \a x.
*/
int lu_lerp32(const s32 lut[], int x, const int shift)
{
    int xa, ya, yb;
    xa=x>>shift;
    ya= lut[xa]; yb= lut[xa+1];
    return ya + ((yb-ya)*(x-(xa<<shift))>>shift);
}

#endif
