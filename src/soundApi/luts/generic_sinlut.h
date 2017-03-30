#ifndef _SOUND_API_SINLUT_
#define _SOUND_API_SINLUT_

#ifndef LUT_GENERIC_SIZE
#define LUT_GENERIC_SIZE 512
#endif

//
// Sine lut; 512 entries, 12 fixeds
//

const u16 snd_sin_lut[LUT_GENERIC_SIZE] = {

	0, 50, 100, 150, 200, 251, 301, 351, 
	401, 451, 501, 551, 601, 650, 700, 749, 
	799, 848, 897, 946, 995, 1043, 1092, 1140, 
	1189, 1237, 1284, 1332, 1379, 1427, 1474, 1520, 
	1567, 1613, 1659, 1705, 1751, 1796, 1841, 1886, 
	1930, 1975, 2018, 2062, 2105, 2148, 2191, 2233, 
	2275, 2317, 2358, 2399, 2439, 2480, 2519, 2559, 
	2598, 2637, 2675, 2713, 2750, 2787, 2824, 2860, 
	2896, 2931, 2966, 3000, 3034, 3068, 3101, 3134, 
	3166, 3197, 3229, 3259, 3289, 3319, 3348, 3377, 
	3405, 3433, 3460, 3487, 3513, 3538, 3563, 3588, 
	3612, 3635, 3658, 3680, 3702, 3723, 3744, 3764, 
	3784, 3803, 3821, 3839, 3856, 3873, 3889, 3904, 
	3919, 3933, 3947, 3960, 3973, 3985, 3996, 4007, 
	4017, 4026, 4035, 4043, 4051, 4058, 4065, 4071, 
	4076, 4080, 4084, 4088, 4091, 4093, 4094, 4095, 
	4096, 4095, 4094, 4093, 4091, 4088, 4084, 4080, 
	4076, 4071, 4065, 4058, 4051, 4043, 4035, 4026, 
	4017, 4007, 3996, 3985, 3973, 3960, 3947, 3933, 
	3919, 3904, 3889, 3873, 3856, 3839, 3821, 3803, 
	3784, 3764, 3744, 3723, 3702, 3680, 3658, 3635, 
	3612, 3588, 3563, 3538, 3513, 3487, 3460, 3433, 
	3405, 3377, 3348, 3319, 3289, 3259, 3229, 3197, 
	3166, 3134, 3101, 3068, 3034, 3000, 2966, 2931, 
	2896, 2860, 2824, 2787, 2750, 2713, 2675, 2637, 
	2598, 2559, 2519, 2480, 2439, 2399, 2358, 2317, 
	2275, 2233, 2191, 2148, 2105, 2062, 2018, 1975, 
	1930, 1886, 1841, 1796, 1751, 1705, 1659, 1613, 
	1567, 1520, 1474, 1427, 1379, 1332, 1284, 1237, 
	1189, 1140, 1092, 1043, 995, 946, 897, 848, 
	799, 749, 700, 650, 601, 551, 501, 451, 
	401, 351, 301, 251, 200, 150, 100, 50, 
	0, 65486, 65436, 65386, 65336, 65285, 65235, 65185, 
	65135, 65085, 65035, 64985, 64935, 64886, 64836, 64787, 
	64737, 64688, 64639, 64590, 64541, 64493, 64444, 64396, 
	64347, 64299, 64252, 64204, 64157, 64109, 64062, 64016, 
	63969, 63923, 63877, 63831, 63785, 63740, 63695, 63650, 
	63606, 63561, 63518, 63474, 63431, 63388, 63345, 63303, 
	63261, 63219, 63178, 63137, 63097, 63056, 63017, 62977, 
	62938, 62899, 62861, 62823, 62786, 62749, 62712, 62676, 
	62640, 62605, 62570, 62536, 62502, 62468, 62435, 62402, 
	62370, 62339, 62307, 62277, 62247, 62217, 62188, 62159, 
	62131, 62103, 62076, 62049, 62023, 61998, 61973, 61948, 
	61924, 61901, 61878, 61856, 61834, 61813, 61792, 61772, 
	61752, 61733, 61715, 61697, 61680, 61663, 61647, 61632, 
	61617, 61603, 61589, 61576, 61563, 61551, 61540, 61529, 
	61519, 61510, 61501, 61493, 61485, 61478, 61471, 61465, 
	61460, 61456, 61452, 61448, 61445, 61443, 61442, 61441, 
	61440, 61441, 61442, 61443, 61445, 61448, 61452, 61456, 
	61460, 61465, 61471, 61478, 61485, 61493, 61501, 61510, 
	61519, 61529, 61540, 61551, 61563, 61576, 61589, 61603, 
	61617, 61632, 61647, 61663, 61680, 61697, 61715, 61733, 
	61752, 61772, 61792, 61813, 61834, 61856, 61878, 61901, 
	61924, 61948, 61973, 61998, 62023, 62049, 62076, 62103, 
	62131, 62159, 62188, 62217, 62247, 62277, 62307, 62339, 
	62370, 62402, 62435, 62468, 62502, 62536, 62570, 62605, 
	62640, 62676, 62712, 62749, 62786, 62823, 62861, 62899, 
	62938, 62977, 63017, 63056, 63097, 63137, 63178, 63219, 
	63261, 63303, 63345, 63388, 63431, 63474, 63518, 63561, 
	63606, 63650, 63695, 63740, 63785, 63831, 63877, 63923, 
	63969, 64016, 64062, 64109, 64157, 64204, 64252, 64299, 
	64347, 64396, 64444, 64493, 64541, 64590, 64639, 64688, 
	64737, 64787, 64836, 64886, 64935, 64985, 65035, 65085, 
	65135, 65185, 65235, 65285, 65336, 65386, 65436, 65486, 
};

int lu_sin(u32 theta){return snd_sin_lut[(theta>>7)&0x1FF];}
#endif
