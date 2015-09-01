#ifndef _SOUND_API_OSC_SINLUTS_
#define _SOUND_API_OSC_SINLUTS_

#ifndef LUT_PRECISION
#define LUT_PRECISION 128
#endif

// C0, freq = 261.700000
const u32 snd_osc_sine_C0[LUT_PRECISION] = {

	0x09060300, 0x14110F0C, 0x1B1A1816, 0x1F1E1E1D, 0x1E1E1F1F, 0x171A1B1D, 0x0D101215, 0x0205080A, 
	0xF6F8FBFE, 0xEBEEF0F3, 0xE4E5E7E9, 0xE1E1E2E3, 0xE3E2E2E1, 0xEAE8E6E5, 0xF4F1EFEC, 0x00FDFAF7, 
	0x0C090603, 0x17151210, 0x1D1C1B19, 0x1F1F1F1E, 0x1C1D1E1F, 0x1517191B, 0x090C1012, 0xFD000306, 
	0xF1F4F7FA, 0xE8EAECEF, 0xE2E3E5E6, 0xE1E1E1E2, 0xE5E4E3E2, 0xEEEBE9E7, 0xF8F6F3F0, 0x0502FEFB, 
	0x100D0A08, 0x1A171512, 0x1E1E1D1B, 0x1E1F1F1F, 0x1A1B1D1E, 0x11141618, 0x06090C0F, 0xF8FB0003, 
	0xEEF0F3F6, 0xE5E7E9EB, 0xE1E2E3E4, 0xE2E1E1E1, 0xE7E5E4E3, 0xF1EFECEA, 0xFDFAF7F4, 0x09060300, 
	0x14110F0C, 0x1B1A1816, 0x1F1E1E1D, 0x1D1E1F1F, 0x17191B1C, 0x0D101215, 0x0205080A, 0xF6F8FBFE, 
	0xEAECEFF3, 0xE3E5E6E8, 0xE1E1E2E2, 0xE3E2E2E1, 0xEAE8E6E5, 0xF4F1EFEC, 0x02FEFBF8, 0x0D0A0805, 
	0x17151210, 0x1D1C1B19, 0x1F1F1F1E, 0x1B1D1E1F, 0x1416181A, 0x090C0F11, 0xFD000306, 0xF1F4F7FA, 
	0xE8EAECEF, 0xE2E3E4E5, 0xE1E1E1E1, 0xE5E4E3E2, 0xEEEBE9E7, 0xF8F6F3F0, 0x0602FEFB, 0x110F0C09, 
	0x1A181614, 0x1E1E1D1B, 0x1E1F1F1F, 0x1A1B1D1E, 0x10121518, 0x05080A0D, 0xF8FBFE02, 0xEEF0F3F6, 
	0xE5E7E9EB, 0xE1E2E3E4, 0xE2E2E1E1, 0xE8E6E5E3, 0xF1EFECEA, 0xFDFAF7F4, 0x09060300, 0x15120F0C, 
	0x1C1B1917, 0x1F1F1E1D, 0x1D1E1F1F, 0x17191B1C, 0x0D101215, 0x0003060A, 0xF4F7FAFD, 0xEAECEFF1, 
	0xE3E5E6E8, 0xE1E1E2E2, 0xE4E2E2E1, 0xEBE9E7E5, 0xF6F3F0EE, 0x02FEFBF8, 0x0D0A0805, 0x17151210, 
	0x1E1D1B19, 0x1F1F1F1E, 0x1B1D1E1E, 0x1416181A, 0x090C0F11, 0xFD000306, 0xF0F3F6F8, 0xE7E9EBEE, 
	0xE2E3E4E5, 0xE1E1E1E1, 0xE5E4E3E2, 0xEFEBE9E7, 0xFAF7F4F1, 0x060300FD, 0x110F0C09, 0x1A181614, 
};

// CS0, freq = 277.200000
const u32 snd_osc_sine_CS0[LUT_PRECISION] = {

	0x09060300, 0x15110F0C, 0x1C1B1917, 0x1F1F1E1D, 0x1C1E1E1F, 0x1517191B, 0x090C0F12, 0xFB000306, 
	0xF0F3F6F8, 0xE6E8EAEE, 0xE1E2E3E5, 0xE2E1E1E1, 0xE8E6E5E3, 0xF3EFECEA, 0xFEFBF8F6, 0x0C090602, 
	0x1714110F, 0x1D1C1B19, 0x1F1F1F1E, 0x1B1D1E1E, 0x12151719, 0x06090C10, 0xF8FD0003, 0xEEF0F3F6, 
	0xE5E6E8EB, 0xE1E2E2E3, 0xE3E2E1E1, 0xEAE8E6E4, 0xF6F1EFEC, 0x02FEFBF8, 0x0F0C0905, 0x19161411, 
	0x1E1D1C1B, 0x1E1F1F1F, 0x191B1D1E, 0x10121517, 0x0306090D, 0xF6FAFD00, 0xEBEEF0F3, 0xE3E5E6E9, 
	0xE1E1E2E2, 0xE4E3E2E1, 0xECEAE7E5, 0xF7F4F1EF, 0x0502FEFB, 0x110F0A08, 0x1A181614, 0x1F1E1D1C, 
	0x1E1E1F1F, 0x181A1B1D, 0x0D101215, 0x0003080A, 0xF4F7FAFD, 0xE9EBEEF0, 0xE2E3E5E7, 0xE1E1E1E2, 
	0xE5E4E3E2, 0xEFECE9E7, 0xFAF7F4F1, 0x080502FE, 0x14110D0A, 0x1B1A1816, 0x1F1F1E1D, 0x1D1E1F1F, 
	0x16181A1B, 0x0A0D1012, 0xFD000508, 0xF1F4F7FA, 0xE7E9EBEE, 0xE2E2E4E5, 0xE2E1E1E1, 0xE7E5E4E3, 
	0xF1EFEBE9, 0xFDFAF7F4, 0x0A080502, 0x1614100D, 0x1D1B1A18, 0x1F1F1F1E, 0x1B1D1E1F, 0x1416181A, 
	0x080A0D10, 0xFAFE0205, 0xEFF1F4F7, 0xE5E7E9EC, 0xE1E2E3E4, 0xE2E2E1E1, 0xE9E7E5E3, 0xF4F0EEEB, 
	0x00FDFAF7, 0x0D0A0803, 0x18151210, 0x1E1D1B1A, 0x1F1F1F1E, 0x1A1C1D1E, 0x11141618, 0x05080A0F, 
	0xF7FBFE02, 0xECEFF1F4, 0xE4E5E7EA, 0xE1E1E2E3, 0xE3E2E2E1, 0xEBE9E7E5, 0xF7F3F0EE, 0x0300FDFA, 
	0x100D0A06, 0x1A171512, 0x1E1E1D1B, 0x1E1F1F1F, 0x181B1C1D, 0x0F111416, 0x0205080C, 0xF4F8FBFE, 
	0xEAECEFF1, 0xE3E4E5E8, 0xE1E1E1E2, 0xE5E3E2E2, 0xEEEBE9E6, 0xFAF6F3F0, 0x060300FD, 0x12100D09, 
	0x1B191715, 0x1F1E1E1D, 0x1D1E1F1F, 0x17191B1C, 0x0C0F1114, 0xFE020609, 0xF3F6F8FB, 0xE8EAECEF, 
};

// D0, freq = 293.700000
const u32 snd_osc_sine_D0[LUT_PRECISION] = {

	0x09060300, 0x1612100D, 0x1D1B1A18, 0x1F1F1F1E, 0x1B1C1D1E, 0x11141619, 0x05080A0D, 0xF6FAFD00, 
	0xEAECF0F3, 0xE3E4E6E8, 0xE1E1E1E2, 0xE5E4E3E2, 0xF0ECEAE8, 0xFDF8F6F3, 0x0A080300, 0x1614100D, 
	0x1D1C1B18, 0x1F1F1F1E, 0x1A1C1D1E, 0x10141618, 0x03060A0D, 0xF6F8FB00, 0xEAECEFF3, 0xE3E4E5E7, 
	0xE1E1E1E2, 0xE6E5E3E2, 0xF0EEEAE8, 0xFDFAF7F3, 0x0A080500, 0x1714110F, 0x1E1C1B19, 0x1F1F1F1E, 
	0x1A1B1D1E, 0x10121518, 0x0306090C, 0xF4F8FBFE, 0xE9EBEFF1, 0xE2E3E5E7, 0xE1E1E1E2, 0xE6E5E3E2, 
	0xF1EEEBE9, 0xFEFAF7F4, 0x0C090502, 0x1715110F, 0x1E1D1B19, 0x1F1F1F1F, 0x191B1D1E, 0x0F121517, 
	0x0205090C, 0xF4F7FAFE, 0xE9EBEEF1, 0xE2E3E5E6, 0xE2E1E1E1, 0xE7E5E3E2, 0xF1EFEBE9, 0xFEFBF8F4, 
	0x0C090602, 0x18151210, 0x1E1D1B1A, 0x1E1F1F1F, 0x191B1D1E, 0x0F111417, 0x0205080A, 0xF3F7FAFD, 
	0xE8EBEEF0, 0xE2E3E5E6, 0xE2E1E1E1, 0xE7E5E4E2, 0xF1EFECEA, 0x00FBF8F6, 0x0D0A0603, 0x18161210, 
	0x1E1D1C1A, 0x1E1F1F1F, 0x181B1C1D, 0x0D111416, 0x0003080A, 0xF3F6F8FD, 0xE8EAECF0, 0xE2E3E4E5, 
	0xE2E1E1E1, 0xE8E6E4E3, 0xF3F0ECEA, 0x00FDFAF6, 0x0D0A0803, 0x19161411, 0x1E1D1C1B, 0x1E1F1F1F, 
	0x181A1C1D, 0x0D101216, 0x00030609, 0xF1F6F8FB, 0xE7EAECEF, 0xE2E2E4E5, 0xE2E1E1E1, 0xE8E6E5E3, 
	0xF3F0EEEB, 0x02FDFAF7, 0x0F0C0805, 0x19171411, 0x1E1E1D1B, 0x1E1F1F1F, 0x171A1B1D, 0x0C101215, 
	0xFE020609, 0xF1F4F8FB, 0xE7E9EBEF, 0xE2E2E3E5, 0xE2E1E1E1, 0xE9E7E5E3, 0xF4F1EEEB, 0x02FEFBF7, 
	0x0F0C0905, 0x1A171512, 0x1F1E1D1B, 0x1E1E1F1F, 0x17191B1D, 0x0C0F1115, 0xFE020508, 0xF0F4F7FA, 
	0xE6E9EBEE, 0xE1E2E3E5, 0xE2E2E1E1, 0xE9E7E5E3, 0xF4F1EFEC, 0x03FEFBF8, 0x100D0906, 0x1A181512, 
};

// DS0, freq = 311.200000
const u32 snd_osc_sine_DS0[LUT_PRECISION] = {

	0x0A060300, 0x1714110D, 0x1E1D1B19, 0x1E1F1F1F, 0x181B1C1E, 0x0D101216, 0xFE020609, 0xF0F4F7FA, 
	0xE5E8EAEE, 0xE1E2E3E4, 0xE3E2E1E1, 0xECE9E7E5, 0xF8F6F3EF, 0x080500FD, 0x15120F0C, 0x1D1B1A17, 
	0x1F1F1F1E, 0x1A1B1D1E, 0x0F121517, 0x0005080C, 0xF3F6FAFD, 0xE7E9ECEF, 0xE1E2E3E5, 0xE2E2E1E1, 
	0xEAE8E5E4, 0xF7F3F0EE, 0x0602FEFA, 0x12100D09, 0x1C1B1816, 0x1F1F1E1E, 0x1B1D1E1F, 0x11141719, 
	0x03060A0D, 0xF4F8FB00, 0xE9EBEEF1, 0xE2E3E5E6, 0xE2E1E1E1, 0xE9E6E5E3, 0xF4F1EEEB, 0x0300FBF8, 
	0x110D0A08, 0x1B191714, 0x1F1F1E1D, 0x1C1D1E1F, 0x1216181B, 0x06090C10, 0xF7FAFE02, 0xEAEEF0F3, 
	0xE2E4E5E8, 0xE1E1E1E2, 0xE7E5E3E2, 0xF3EFECE9, 0x00FDFAF6, 0x0F0C0805, 0x1A181512, 0x1F1E1D1B, 
	0x1D1E1F1F, 0x15171A1B, 0x080C0F11, 0xF8FD0005, 0xECEFF3F6, 0xE3E5E7E9, 0xE1E1E1E2, 0xE5E4E3E2, 
	0xF0EEEAE8, 0xFEFAF7F4, 0x0D090602, 0x18161410, 0x1E1E1C1B, 0x1E1F1F1F, 0x16191B1D, 0x0A0D1114, 
	0xFBFE0306, 0xEEF1F4F8, 0xE5E6E8EB, 0xE1E1E2E3, 0xE5E3E2E1, 0xEFEBE9E6, 0xFBF8F4F1, 0x0A080300, 
	0x1714110F, 0x1E1D1B19, 0x1E1F1F1F, 0x181A1C1D, 0x0C101216, 0xFE020509, 0xF0F3F7FA, 0xE5E8EAEC, 
	0xE1E2E2E4, 0xE3E2E1E1, 0xECEAE7E5, 0xFAF6F3EF, 0x080502FD, 0x15120F0C, 0x1D1C1A18, 0x1F1F1F1E, 
	0x1A1B1D1E, 0x0F111517, 0x0005080A, 0xF1F6F8FD, 0xE7E9ECEF, 0xE1E2E3E5, 0xE3E2E1E1, 0xEAE8E6E4, 
	0xF7F4F0EE, 0x0602FEFB, 0x14100D09, 0x1C1B1916, 0x1F1F1E1E, 0x1B1D1E1E, 0x10141619, 0x03060A0D, 
	0xF4F7FBFE, 0xE8EBEEF1, 0xE2E3E4E6, 0xE2E1E1E1, 0xE9E6E5E3, 0xF6F1EFEB, 0x0300FBF8, 0x110F0A08, 
	0x1B191715, 0x1F1F1E1D, 0x1C1D1E1F, 0x1215181A, 0x05090C10, 0xF7FAFD02, 0xEAECF0F3, 0xE2E4E5E7, 
};

// E0, freq = 329.700000
const u32 snd_osc_sine_E0[LUT_PRECISION] = {

	0x0A080300, 0x1815110F, 0x1E1D1C1A, 0x1E1E1F1F, 0x16181B1C, 0x080C0F12, 0xF8FD0005, 0xEBEEF1F4, 
	0xE2E4E5E8, 0xE2E1E1E2, 0xE8E6E4E3, 0xF6F1EEEB, 0x0500FDF8, 0x12100C08, 0x1C1B1816, 0x1F1F1F1E, 
	0x1A1B1D1E, 0x0F111517, 0xFE03060A, 0xF0F4F7FB, 0xE5E7EAEC, 0xE1E1E2E3, 0xE5E3E2E1, 0xEFECE9E6, 
	0xFEFAF6F3, 0x0D090602, 0x19171410, 0x1F1E1D1B, 0x1D1E1F1F, 0x1417191B, 0x06090D10, 0xF6FAFE02, 
	0xE9ECEFF3, 0xE2E3E5E6, 0xE2E1E1E1, 0xEAE7E5E3, 0xF7F4F0EC, 0x0603FEFB, 0x15110F0A, 0x1D1B1A17, 
	0x1F1F1F1E, 0x181B1C1E, 0x0C101216, 0xFD000508, 0xEEF1F6F8, 0xE4E6E8EB, 0xE1E1E2E3, 0xE5E4E2E2, 
	0xF1EEEBE8, 0x00FDF8F4, 0x0F0C0805, 0x1B181612, 0x1F1E1E1C, 0x1C1D1E1F, 0x1115181A, 0x03080A0F, 
	0xF4F7FB00, 0xE7EAEEF0, 0xE1E2E3E5, 0xE3E2E1E1, 0xEBE9E6E5, 0xFAF6F3EF, 0x090502FD, 0x1614100D, 
	0x1E1D1B19, 0x1E1F1F1F, 0x17191B1D, 0x090D1114, 0xFAFE0206, 0xECEFF3F7, 0xE3E5E7E9, 0xE1E1E1E2, 
	0xE7E5E3E2, 0xF3F0ECEA, 0x03FEFBF7, 0x110D0A06, 0x1B1A1715, 0x1F1F1E1D, 0x1B1D1E1F, 0x10121619, 
	0x0205090C, 0xF1F6F8FD, 0xE6E8EBEF, 0xE1E2E3E4, 0xE4E2E2E1, 0xEEEAE8E5, 0xFBF8F4F1, 0x0C080300, 
	0x1815120F, 0x1E1E1C1A, 0x1D1E1F1F, 0x15181A1C, 0x080A0F12, 0xF8FB0003, 0xEAEEF0F4, 0xE2E4E5E8, 
	0xE2E1E1E1, 0xE9E6E4E3, 0xF6F1EFEB, 0x0502FDFA, 0x14100C09, 0x1D1B1916, 0x1F1F1F1E, 0x1A1B1D1E, 
	0x0D111417, 0xFE03060A, 0xF0F3F7FA, 0xE5E7E9EC, 0xE1E1E2E3, 0xE5E3E2E1, 0xF0ECE9E7, 0xFEFAF7F3, 
	0x0D0A0602, 0x19171411, 0x1F1E1D1B, 0x1D1E1F1F, 0x1416191B, 0x05090C10, 0xF6FAFD02, 0xE9EBEFF1, 
	0xE2E3E5E6, 0xE2E1E1E1, 0xEAE8E5E3, 0xF8F4F0EE, 0x080300FB, 0x15120F0A, 0x1D1C1A18, 0x1E1F1F1E, 
};

// F0, freq = 349.300000
const u32 snd_osc_sine_F0[LUT_PRECISION] = {

	0x0C080300, 0x1916120F, 0x1F1E1D1B, 0x1D1E1F1F, 0x1215181B, 0x03060A0F, 0xF3F7FAFE, 0xE6E9EBEF, 
	0xE1E2E2E4, 0xE5E3E2E1, 0xF0ECE9E7, 0x00FBF7F4, 0x100C0803, 0x1B191612, 0x1F1F1E1D, 0x1B1C1E1F, 
	0x0F111518, 0xFE02060A, 0xEFF3F6FA, 0xE4E6E8EB, 0xE1E1E1E2, 0xE7E5E3E2, 0xF4F0ECEA, 0x0500FBF8, 
	0x14100C08, 0x1D1B1916, 0x1F1F1F1E, 0x181A1C1E, 0x0A0D1115, 0xFAFD0206, 0xEBEFF1F6, 0xE2E4E5E8, 
	0xE2E1E1E1, 0xEAE7E5E3, 0xF8F4F0EE, 0x090500FD, 0x1714100C, 0x1E1D1B19, 0x1E1E1F1F, 0x15171A1C, 
	0x06090D11, 0xF6FAFD02, 0xE8EBEEF1, 0xE1E2E3E5, 0xE3E2E1E1, 0xEEEAE7E5, 0xFDF8F4F1, 0x0D090502, 
	0x1A171410, 0x1F1E1D1B, 0x1C1D1E1F, 0x1114171A, 0x0205090D, 0xF1F6F8FD, 0xE5E8EAEE, 0xE1E1E2E3, 
	0xE5E3E2E1, 0xF1EEEAE8, 0x02FDF8F6, 0x110D0906, 0x1C1A1714, 0x1F1F1E1D, 0x1A1B1D1E, 0x0D101417, 
	0xFD000509, 0xEEF1F4F8, 0xE3E5E7EA, 0xE1E1E1E2, 0xE8E5E3E2, 0xF6F1EEEB, 0x0602FDFA, 0x15110D0A, 
	0x1E1C1A17, 0x1E1F1F1E, 0x17191B1D, 0x090C1014, 0xF8FB0005, 0xEAEEF0F4, 0xE2E3E5E7, 0xE2E1E1E1, 
	0xEBE8E5E4, 0xFAF6F1EF, 0x0A0602FE, 0x1815110D, 0x1F1E1C1A, 0x1D1E1F1F, 0x1416191B, 0x05080C10, 
	0xF4F7FB00, 0xE7EAECF0, 0xE1E2E3E5, 0xE4E2E2E1, 0xEFEBE8E6, 0xFEFAF6F3, 0x0F0A0603, 0x1B181511, 
	0x1F1F1E1C, 0x1B1D1E1F, 0x10121619, 0x0003080C, 0xF0F3F7FB, 0xE5E7E9EC, 0xE1E1E2E3, 0xE6E4E3E2, 
	0xF3EFEBE9, 0x03FEFAF7, 0x120F0A08, 0x1D1B1815, 0x1F1F1F1E, 0x191B1D1E, 0x0C0F1216, 0xFBFE0308, 
	0xECEFF3F7, 0xE3E5E6E9, 0xE2E1E1E2, 0xE9E6E5E3, 0xF7F3EFEC, 0x0803FEFB, 0x16120F0C, 0x1E1D1B18, 
	0x1E1F1F1F, 0x16181B1D, 0x080A0F12, 0xF7FAFE03, 0xE9ECEFF3, 0xE2E3E4E6, 0xE3E2E1E1, 0xECE9E7E5, 
};

// FS0, freq = 370.000000
const u32 snd_osc_sine_FS0[LUT_PRECISION] = {

	0x0C080300, 0x1A171410, 0x1F1E1E1C, 0x1B1D1E1F, 0x0F111518, 0xFD02060A, 0xECF0F4F8, 0xE3E5E7EA, 
	0xE2E1E1E2, 0xEAE7E5E3, 0xFAF6F1EE, 0x0A0603FE, 0x1916120F, 0x1F1E1D1B, 0x1B1D1E1F, 0x0F121619, 
	0xFE03080A, 0xEEF1F6FA, 0xE3E5E7EA, 0xE2E1E1E2, 0xE9E7E5E3, 0xF8F4F0EC, 0x0A0602FD, 0x1815110D, 
	0x1F1E1D1B, 0x1C1E1F1F, 0x1014171A, 0x0005080C, 0xEFF3F7FB, 0xE4E5E8EB, 0xE1E1E1E2, 0xE9E6E4E2, 
	0xF7F3EFEC, 0x090500FB, 0x1714110D, 0x1F1E1C1A, 0x1D1E1F1F, 0x1115181B, 0x0005090D, 0xF0F4F8FD, 
	0xE4E6E9EC, 0xE1E1E2E2, 0xE8E5E3E2, 0xF6F1EFEB, 0x0803FEFA, 0x1614100C, 0x1E1D1B19, 0x1D1E1F1F, 
	0x1216191B, 0x02060A0F, 0xF1F6F8FD, 0xE5E7EAEE, 0xE1E1E2E3, 0xE7E5E3E2, 0xF6F1EEEA, 0x0602FDF8, 
	0x16120F0A, 0x1E1D1B19, 0x1D1E1F1F, 0x1417191B, 0x03080C10, 0xF3F6FAFE, 0xE5E8EBEF, 0xE1E1E2E3, 
	0xE6E4E2E2, 0xF4F0ECE9, 0x0500FDF8, 0x15110D09, 0x1E1D1B18, 0x1E1F1F1F, 0x14171A1C, 0x05090D11, 
	0xF3F7FB00, 0xE6E9ECEF, 0xE1E1E2E4, 0xE5E3E2E1, 0xF3EFEBE8, 0x0300FBF7, 0x14100C08, 0x1E1C1A17, 
	0x1E1F1F1F, 0x15181B1D, 0x060A0D11, 0xF4F8FD02, 0xE7E9ECF0, 0xE1E2E3E5, 0xE5E3E2E1, 0xF1EEEAE7, 
	0x03FEFAF6, 0x120F0A08, 0x1D1B1916, 0x1E1F1F1E, 0x16191B1D, 0x080A0F12, 0xF6FAFE03, 0xE7EAEEF1, 
	0xE1E2E3E5, 0xE5E3E2E1, 0xF0ECEAE7, 0x02FDF8F4, 0x110F0A06, 0x1D1B1815, 0x1E1F1F1E, 0x171A1C1E, 
	0x080C1014, 0xF7FB0003, 0xE8EBEFF3, 0xE1E2E3E5, 0xE4E2E1E1, 0xEFECE9E6, 0x00FBF7F3, 0x110D0905, 
	0x1C1A1715, 0x1F1F1F1E, 0x181B1C1E, 0x090D1115, 0xF8FB0005, 0xE9ECF0F4, 0xE1E2E4E6, 0xE3E2E1E1, 
	0xEFEBE8E5, 0xFEFAF6F3, 0x100C0803, 0x1B191714, 0x1F1F1E1D, 0x191B1D1E, 0x0A0F1216, 0xF8FD0206, 
};

// G0, freq = 392.000000
const u32 snd_osc_sine_G0[LUT_PRECISION] = {

	0x0D090500, 0x1B181511, 0x1F1F1E1D, 0x191B1D1E, 0x090D1115, 0xF7FB0005, 0xE8EBEFF3, 0xE1E2E3E5, 
	0xE5E3E2E1, 0xF3EFEBE8, 0x0500FBF7, 0x15110D09, 0x1E1D1B19, 0x1D1E1F1F, 0x1115181B, 0x0005090D, 
	0xEEF1F6FA, 0xE3E5E7EA, 0xE2E1E1E2, 0xEBE8E5E3, 0xFDF8F4F0, 0x0F0A0602, 0x1B191612, 0x1F1F1E1D, 
	0x171A1C1E, 0x080C1014, 0xF6FAFE03, 0xE7EAEEF1, 0xE1E1E2E4, 0xE6E4E2E1, 0xF4F0ECE9, 0x0602FDF8, 
	0x1714100C, 0x1F1E1C1A, 0x1C1E1F1F, 0x1014171A, 0xFD02060A, 0xECF0F4F8, 0xE2E4E6E9, 0xE2E1E1E1, 
	0xEEEAE7E5, 0xFEFAF6F1, 0x100C0803, 0x1C1A1714, 0x1E1F1F1E, 0x16191B1D, 0x060A0F12, 0xF4F8FD02, 
	0xE5E8EBEF, 0xE1E1E2E3, 0xE7E5E3E2, 0xF6F1EEEA, 0x090500FB, 0x1815110D, 0x1F1E1D1B, 0x1B1D1E1F, 
	0x0D111518, 0xFB000509, 0xEBEFF3F7, 0xE2E3E5E8, 0xE3E2E1E1, 0xEFEBE8E5, 0x00FBF7F3, 0x110D0905, 
	0x1D1B1916, 0x1E1F1F1E, 0x15181B1D, 0x05090D11, 0xF1F6FAFE, 0xE5E7EAEE, 0xE1E1E2E3, 0xE8E5E3E2, 
	0xF8F4F0EC, 0x0A0602FD, 0x1916120F, 0x1F1E1D1B, 0x1A1C1E1F, 0x0C101417, 0xFAFE0308, 0xEAEEF1F6, 
	0xE1E2E4E6, 0xE4E2E1E1, 0xF0ECE9E6, 0x02FDF8F4, 0x14100C08, 0x1E1C1A17, 0x1E1F1F1F, 0x14171A1C, 
	0x02060A0F, 0xF0F4F8FD, 0xE4E6E9EC, 0xE1E1E1E2, 0xEAE7E5E3, 0xFAF6F1EE, 0x0C0803FE, 0x1A171410, 
	0x1F1F1E1D, 0x191B1D1E, 0x0A0F1216, 0xF8FD0206, 0xE8EBEFF3, 0xE1E2E3E5, 0xE5E3E2E1, 0xF1EEEAE7, 
	0x0500FBF7, 0x15110D09, 0x1E1D1B18, 0x1D1E1F1F, 0x1115181B, 0x0005090D, 0xEFF3F7FB, 0xE3E5E8EB, 
	0xE2E1E1E2, 0xEBE8E5E3, 0xFBF7F3EF, 0x0D090500, 0x1B191612, 0x1F1F1E1D, 0x181B1D1E, 0x090D1115, 
	0xF6FAFE03, 0xE7EAEEF1, 0xE1E2E3E5, 0xE5E3E2E1, 0xF4F0ECE9, 0x0602FDF8, 0x16120F0A, 0x1E1D1B19, 
};

// GS0, freq = 415.300000
const u32 snd_osc_sine_GS0[LUT_PRECISION] = {

	0x0D090500, 0x1B191611, 0x1F1F1F1D, 0x16191B1E, 0x05090D12, 0xF1F6FA00, 0xE4E6E9EE, 0xE2E1E1E2, 
	0xEBE8E5E3, 0xFDF8F4EF, 0x100C0802, 0x1D1B1814, 0x1E1F1F1E, 0x14171B1D, 0x02060C10, 0xEFF3F8FD, 
	0xE3E5E8EB, 0xE2E1E1E2, 0xEEEAE6E4, 0x00FBF6F1, 0x120F0905, 0x1E1C1916, 0x1D1E1F1F, 0x1116191B, 
	0xFE05090D, 0xECF1F6FA, 0xE2E4E6E9, 0xE3E2E1E1, 0xF0EBE8E5, 0x03FDF8F4, 0x15100C08, 0x1E1D1B18, 
	0x1C1E1F1F, 0x0F14171A, 0xFD02060A, 0xEBEFF3F7, 0xE2E3E5E7, 0xE4E2E1E1, 0xF1EEEAE7, 0x0500FBF7, 
	0x16120F0A, 0x1F1E1C1A, 0x1B1D1E1F, 0x0D111518, 0xFAFE0308, 0xE9ECF0F4, 0xE1E2E3E6, 0xE5E3E2E1, 
	0xF4F0ECE8, 0x0803FEF8, 0x1815110C, 0x1F1E1D1B, 0x1A1C1E1F, 0x0A0F1217, 0xF7FB0006, 0xE7EAEEF3, 
	0xE1E1E2E5, 0xE7E5E2E1, 0xF7F3EEEA, 0x0A0600FB, 0x1A17120F, 0x1F1F1E1C, 0x181B1D1E, 0x080C1115, 
	0xF4F8FE03, 0xE5E8ECF0, 0xE1E1E2E3, 0xE9E6E3E2, 0xFAF6F0EC, 0x0D0803FE, 0x1B181511, 0x1F1F1E1D, 
	0x161A1C1E, 0x050A0F12, 0xF1F7FB00, 0xE4E7EAEE, 0xE2E1E1E2, 0xEBE7E5E3, 0xFDF7F3EF, 0x100A0602, 
	0x1C1A1714, 0x1E1F1F1E, 0x15181B1D, 0x03080C10, 0xF0F4F8FD, 0xE3E5E8EB, 0xE2E1E1E2, 0xECE9E6E4, 
	0xFEFAF6F1, 0x110D0905, 0x1D1B1916, 0x1E1F1F1F, 0x1216191C, 0x0005090F, 0xEEF1F6FB, 0xE2E4E6EA, 
	0xE3E2E1E1, 0xEFEBE8E5, 0x02FDF8F3, 0x14100C06, 0x1E1D1B17, 0x1D1E1F1F, 0x1014171B, 0xFD02080C, 
	0xEBEFF4F8, 0xE2E3E5E8, 0xE4E2E1E1, 0xF1EEE9E6, 0x0500FAF6, 0x16120D09, 0x1F1E1B19, 0x1B1D1F1F, 
	0x0D111619, 0xFAFE0509, 0xE9EEF1F6, 0xE1E2E4E6, 0xE5E3E2E1, 0xF4EFEBE8, 0x0802FDF8, 0x1814100C, 
	0x1F1E1D1B, 0x1A1D1E1F, 0x0A101417, 0xF7FD0206, 0xE7EBEFF3, 0xE1E2E3E5, 0xE6E4E2E1, 0xF6F1EEEA, 
};

// A0, freq = 440.000000
const u32 snd_osc_sine_A0[LUT_PRECISION] = {

	0x0F090500, 0x1D1A1712, 0x1E1F1F1E, 0x12161A1C, 0xFE05090D, 0xEBF0F4FA, 0xE2E3E5E8, 0xE5E3E1E1, 
	0xF4EFEBE8, 0x0903FEF8, 0x1916110D, 0x1F1F1E1C, 0x171B1D1E, 0x050A0F14, 0xF1F6FB00, 0xE3E5E9EC, 
	0xE2E1E1E2, 0xEFEAE7E4, 0x02FDF7F3, 0x15110C08, 0x1F1D1B19, 0x1B1D1E1F, 0x0C101518, 0xF7FB0206, 
	0xE6EAEEF1, 0xE1E1E2E4, 0xE9E6E3E2, 0xFBF7F1EE, 0x100A0602, 0x1D1B1814, 0x1E1F1F1E, 0x1115191B, 
	0xFD03080C, 0xEAEFF3F8, 0xE1E2E5E7, 0xE5E3E2E1, 0xF6F0ECE9, 0x0A0500FA, 0x1A17120F, 0x1F1F1E1D, 
	0x161A1C1E, 0x03090D12, 0xF0F4FAFE, 0xE3E5E8EB, 0xE3E1E1E1, 0xF0EBE8E5, 0x03FEF8F4, 0x16120D09, 
	0x1F1E1C1A, 0x1A1D1E1F, 0x0A0F1417, 0xF6FA0005, 0xE5E9ECF0, 0xE1E1E2E3, 0xEAE7E4E2, 0xFDF8F3EF, 
	0x110C0803, 0x1E1B1915, 0x1D1E1F1F, 0x1014181B, 0xFB02060A, 0xE9EEF1F7, 0xE1E2E4E6, 0xE6E4E2E1, 
	0xF7F1EEEA, 0x0C0602FB, 0x1B181410, 0x1F1F1E1D, 0x15191B1D, 0x02080C11, 0xEFF3F8FD, 0xE2E4E7EA, 
	0xE3E2E1E1, 0xF1ECE9E5, 0x0500FAF6, 0x17140F0A, 0x1F1E1D1B, 0x191C1E1F, 0x090D1216, 0xF4F8FE03, 
	0xE5E8EBEF, 0xE2E1E1E3, 0xEBE8E5E3, 0xFEFAF4F0, 0x120D0905, 0x1E1C1A16, 0x1D1E1F1F, 0x0F12171A, 
	0xFA000509, 0xE8ECF0F6, 0xE1E2E3E5, 0xE7E5E2E1, 0xF8F3EFEB, 0x0D0803FD, 0x1B191511, 0x1E1F1F1E, 
	0x14181B1D, 0x00060A10, 0xEEF1F7FB, 0xE2E3E6E9, 0xE4E2E1E1, 0xF3EEEAE6, 0x0602FBF7, 0x1815100C, 
	0x1F1E1D1B, 0x181B1D1F, 0x080C1115, 0xF3F7FD02, 0xE4E7EAEE, 0xE2E1E1E2, 0xECE9E5E3, 0x00FBF6F1, 
	0x140F0A06, 0x1E1D1B17, 0x1C1E1F1F, 0x0D111619, 0xF8FE0308, 0xE7EBEFF4, 0xE1E1E3E5, 0xE8E5E3E2, 
	0xFAF4F0EC, 0x0F0905FE, 0x1C1A1612, 0x1E1F1F1E, 0x12171A1C, 0xFE05090F, 0xECF0F6FA, 0xE2E3E5E8, 
};

// AS0, freq = 466.200000
const u32 snd_osc_sine_AS0[LUT_PRECISION] = {

	0x0F0A0500, 0x1D1B1814, 0x1D1E1F1F, 0x0F14171B, 0xF8FE0509, 0xE7EAEFF4, 0xE1E1E2E4, 0xEAE7E4E2, 
	0xFEF8F4EF, 0x140F0905, 0x1E1D1B17, 0x1B1D1F1F, 0x0A0F1418, 0xF4FAFE05, 0xE5E7EBF0, 0xE2E1E1E2, 
	0xEFEAE6E4, 0x03FDF8F3, 0x17120D09, 0x1F1E1D1A, 0x181B1D1F, 0x060A1015, 0xF0F6FA00, 0xE2E5E8EB, 
	0xE3E2E1E1, 0xF3EEE9E6, 0x0803FDF7, 0x1A16110D, 0x1F1F1E1C, 0x15191B1E, 0x02060C10, 0xECF1F6FB, 
	0xE1E3E5E8, 0xE5E3E2E1, 0xF7F1ECE9, 0x0C0802FB, 0x1C191611, 0x1E1F1F1E, 0x1116191C, 0xFB02080C, 
	0xE9ECF1F7, 0xE1E2E3E5, 0xE8E5E3E1, 0xFBF6F1EC, 0x100C0602, 0x1E1B1915, 0x1C1E1F1F, 0x0D11161A, 
	0xF7FD0308, 0xE6E9EEF3, 0xE1E1E2E3, 0xEBE8E5E3, 0x00FAF6F0, 0x15100A06, 0x1F1D1B18, 0x1A1D1E1F, 
	0x090D1217, 0xF3F8FD03, 0xE4E6EAEF, 0xE2E1E1E2, 0xF0EBE7E5, 0x05FEFAF4, 0x18140F0A, 0x1F1F1D1B, 
	0x171B1D1E, 0x05090F14, 0xEFF4F8FE, 0xE2E4E7EA, 0xE4E2E1E1, 0xF4EFEAE7, 0x0905FEF8, 0x1B17140F, 
	0x1F1F1E1D, 0x14181B1D, 0xFE050A0F, 0xEBF0F4FA, 0xE1E2E5E7, 0xE6E4E2E1, 0xF8F3EFEA, 0x0D0903FD, 
	0x1D1A1712, 0x1E1F1F1E, 0x1015181B, 0xFA00060A, 0xE8EBF0F6, 0xE1E1E3E5, 0xE9E6E3E2, 0xFDF7F3EE, 
	0x110D0803, 0x1E1C1A16, 0x1B1E1F1F, 0x0C101519, 0xF6FB0206, 0xE5E8ECF1, 0xE2E1E1E3, 0xECE9E5E3, 
	0x02FBF7F1, 0x16110C08, 0x1F1E1C19, 0x191C1E1F, 0x080C1116, 0xF1F7FB02, 0xE3E5E9EC, 0xE3E1E1E2, 
	0xF1ECE8E5, 0x0602FBF6, 0x1915100C, 0x1F1F1E1B, 0x161A1C1E, 0x03080D12, 0xEEF3F7FD, 0xE2E3E6E9, 
	0xE5E2E1E1, 0xF6F0EBE8, 0x0A0600FA, 0x1B181510, 0x1E1F1F1D, 0x12171A1D, 0xFD03090D, 0xEAEFF3F8, 
	0xE1E2E4E6, 0xE7E5E2E1, 0xFAF4F0EB, 0x0F0A05FE, 0x1D1B1814, 0x1D1E1F1F, 0x0F14171B, 0xF8FE0509, 
};

// B0, freq = 493.900000
const u32 snd_osc_sine_B0[LUT_PRECISION] = {

	0x100A0500, 0x1E1C1915, 0x1B1E1F1F, 0x0A0F1418, 0xF3F8FE05, 0xE3E6E9EE, 0xE3E2E1E2, 0xF3EEE9E6, 
	0x0A05FEF8, 0x1B18140F, 0x1E1F1F1E, 0x1015191C, 0xFA00050A, 0xE6EAEFF4, 0xE1E1E2E3, 0xEEE9E5E3, 
	0x03FDF7F1, 0x17140F09, 0x1F1F1D1B, 0x161A1C1E, 0x00060C11, 0xEBF0F6FA, 0xE1E2E4E7, 0xE8E5E2E1, 
	0xFDF7F1EC, 0x120D0802, 0x1E1D1B17, 0x1A1D1E1F, 0x080D1116, 0xF0F6FB02, 0xE2E5E8EB, 0xE5E2E1E1, 
	0xF6F0EBE7, 0x0C0802FB, 0x1D1A1611, 0x1D1F1F1E, 0x0D12171B, 0xF7FD0308, 0xE5E8ECF1, 0xE2E1E1E3, 
	0xEFEBE7E4, 0x0600FAF4, 0x1915110C, 0x1F1F1E1C, 0x14181B1D, 0xFD03090F, 0xE9EEF3F8, 0xE1E1E3E5, 
	0xEAE6E3E2, 0xFEFAF4EF, 0x15100A05, 0x1F1E1C19, 0x181B1E1F, 0x050A1014, 0xEEF3F8FE, 0xE2E3E6EA, 
	0xE5E3E2E1, 0xF8F3EEE9, 0x0F0905FE, 0x1E1B1814, 0x1C1E1F1F, 0x0A101519, 0xF4FA0006, 0xE4E6EAEF, 
	0xE3E1E1E2, 0xF1ECE9E5, 0x0903FDF7, 0x1B17120F, 0x1E1F1F1D, 0x11161A1D, 0xFB00060C, 0xE7EBF0F6, 
	0xE1E1E2E4, 0xECE8E5E2, 0x02FBF7F1, 0x17120D08, 0x1F1E1D1B, 0x161A1D1E, 0x02080D12, 0xECF0F6FB, 
	0xE1E2E5E8, 0xE7E4E2E1, 0xFBF6F0EB, 0x110C0602, 0x1E1D1A16, 0x1B1D1F1F, 0x090D1217, 0xF1F7FD03, 
	0xE3E5E8EC, 0xE4E2E1E1, 0xF4EFEAE7, 0x0C0600FA, 0x1C191510, 0x1E1F1F1E, 0x0F14181B, 0xF8FE0309, 
	0xE5E9EEF3, 0xE2E1E2E3, 0xEFEAE6E3, 0x05FEF8F4, 0x1915100A, 0x1F1F1E1B, 0x15181B1E, 0xFE050A10, 
	0xEAEFF3F8, 0xE1E2E3E6, 0xE9E5E3E2, 0xFEF8F3EE, 0x140F0903, 0x1F1E1B18, 0x191C1E1F, 0x060C1015, 
	0xEFF4FA00, 0xE2E4E7EA, 0xE5E3E1E1, 0xF7F1ECE8, 0x0D0903FD, 0x1D1B1712, 0x1D1E1F1F, 0x0C11161A, 
	0xF6FB0206, 0xE4E7EBF0, 0xE2E1E1E2, 0xF1ECE8E5, 0x0802FBF6, 0x1A17120D, 0x1E1F1E1D, 0x12171A1D, 
};

// pointers
const u32* snd_osc_sine[12] = {
	snd_osc_sine_C0, snd_osc_sine_CS0, snd_osc_sine_D0, snd_osc_sine_DS0, 
	snd_osc_sine_E0, snd_osc_sine_F0, snd_osc_sine_FS0, snd_osc_sine_G0, 
	snd_osc_sine_GS0, snd_osc_sine_A0, snd_osc_sine_AS0, snd_osc_sine_B0, 
};
#endif
