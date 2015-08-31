#include <stdio.h>
#include <math.h>

#define SIN_LUT_SIZE 256
#define SAMPLERATE 16000

const char sinLUT[SIN_LUT_SIZE] = {
    	32,32,33,34,35,35,36,37,
	38,38,39,40,41,41,42,43,
	44,44,45,46,46,47,48,48,
	49,50,50,51,52,52,53,53,
	54,54,55,55,56,56,57,57,
	58,58,59,59,59,60,60,60,
	61,61,61,61,62,62,62,62,
	62,63,63,63,63,63,63,63,
	63,63,63,63,63,63,63,62,
	62,62,62,62,62,61,61,61,
	61,60,60,60,59,59,58,58,
	58,57,57,56,56,55,55,54,
	54,53,52,52,51,51,50,49,
	49,48,47,47,46,45,45,44,
	43,43,42,41,40,40,39,38,
	37,37,36,35,34,33,33,32,
	31,30,30,29,28,27,26,26,
	25,24,23,23,22,21,20,20,
	19,18,18,17,16,16,15,14,
	14,13,12,12,11,11,10,9,
	9,8,8,7,7,6,6,5,
	5,5,4,4,3,3,3,2,
	2,2,2,1,1,1,1,1,
	1,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,1,
	1,1,1,1,2,2,2,2,
	3,3,3,4,4,4,5,5,
	6,6,7,7,8,8,9,9,
	10,10,11,11,12,13,13,14,
	15,15,16,17,17,18,19,19,
	20,21,22,22,23,24,25,25,
	26,27,28,28,29,30,31,32
};

#define PRECISION 128

const char* notes[12] = {"C0", "CS0", "D0", "DS0", "E0", "F0", "FS0", "G0", "GS0", "A0", "AS0", "B0"};
const double freqs[12] = {261.7, 277.2, 293.7, 311.2, 329.7, 349.3, 370, 392, 415.3, 440, 466.2, 493.9};

void generate_sinLuts (){
    int ii;
    int jj;
    FILE *fp= fopen("osc_sinluts.h", "w");

    fprintf(fp, "#ifndef _SOUND_API_OSC_SINLUTS_\n");
    fprintf(fp, "#define _SOUND_API_OSC_SINLUTS_\n\n");

    fprintf(fp, "#ifndef LUT_PRECISION\n");
    fprintf(fp, "#define LUT_PRECISION %d\n", PRECISION);
    fprintf(fp, "#endif\n");

    int bufferOsc = 0;
    double phase = 0;
    double bufferFreq = 0;
    int val = 0;


    for (jj=0; jj< 12;jj++){

        // for each freq.
        fprintf(fp, "\n// %s, freq = %f\n", notes[jj], freqs[jj]);
        fprintf(fp, "const u32 snd_osc_sine_%s[LUT_PRECISION] = {\n", notes[jj]);

        bufferFreq = ((SIN_LUT_SIZE * freqs[jj]) / SAMPLERATE);
        phase = 0;
        for(ii=0; ii<PRECISION; ii++)
        {
            bufferOsc = 0;

	    val = 1 * sinLUT[lround(phase)];
            bufferOsc = val;
            phase = phase + bufferFreq;
            if (phase >= SIN_LUT_SIZE){
                phase = phase - SIN_LUT_SIZE;
            }
            

	    val = 1 * sinLUT[lround(phase)];
            bufferOsc |= (val << 8);
            phase = phase + bufferFreq;
            if (phase >= SIN_LUT_SIZE){
                phase = phase - SIN_LUT_SIZE;
            }
            

	    val = 1 * sinLUT[lround(phase)];
            bufferOsc |= (val << 16);
            phase = phase + bufferFreq;
            if (phase >= SIN_LUT_SIZE){
                phase = phase - SIN_LUT_SIZE;
            }
            
	    val = 1 * sinLUT[lround(phase)];
            bufferOsc |= (val << 24);
            phase = phase + bufferFreq;
            if (phase >= SIN_LUT_SIZE){
                phase = phase - SIN_LUT_SIZE;
            }
            

            if(ii%8 == 0) {
                fputs("\n\t", fp);
            }

            fprintf(fp, "0x%.8X, ", bufferOsc);
        }
        fputs("\n};\n", fp);

    }

    fprintf(fp, "#endif\n");
    fclose(fp);
}

void generate_squareLuts(){
    int ii;
    int jj;
    FILE *fp= fopen("osc_squareluts.h", "w");

    fprintf(fp, "#ifndef _SOUND_API_OSC_SQUARELUTS_\n");
    fprintf(fp, "#define _SOUND_API_OSC_SQUARELUTS_\n\n");

    fprintf(fp, "#ifndef LUT_PRECISION\n");
    fprintf(fp, "#define LUT_PRECISION %d\n\n", PRECISION);
    fprintf(fp, "#endif\n");

    int bufferOsc = 0;
    double phase = 0;
    double bufferFreq = 0;
    int val = 0;


    for (jj=0; jj< 12;jj++){

        // for each freq.
        fprintf(fp, "\n// %s, freq = %f\n", notes[jj], freqs[jj]);
        fprintf(fp, "const u32 snd_osc_square_%s[LUT_PRECISION] = {\n", notes[jj]);

        bufferFreq = ((SIN_LUT_SIZE * freqs[jj]) / SAMPLERATE);
        phase = 0;
        for(ii=0; ii<PRECISION; ii++)
        {
            bufferOsc = 0;

            phase = phase + bufferFreq;
            if (phase >= SIN_LUT_SIZE){
                phase = phase - SIN_LUT_SIZE;
            }
            if (phase < SIN_LUT_SIZE/2){
                val = 0;
            } else {
                val = 0xFF;
            }
            bufferOsc = val;

            phase = phase + bufferFreq;
            if (phase >= SIN_LUT_SIZE){
                phase = phase - SIN_LUT_SIZE;
            }
            if (phase < SIN_LUT_SIZE/2){
                val = 0;
            } else {
                val = 0xFF;
            }
            bufferOsc |= (val << 8);

            phase = phase + bufferFreq;
            if (phase >= SIN_LUT_SIZE){
                phase = phase - SIN_LUT_SIZE;
            }
            if (phase < SIN_LUT_SIZE/2){
                val = 0;
            } else {
                val = 0xFF;
            }
            bufferOsc |= (val << 16);

            phase = phase + bufferFreq;
            if (phase >= SIN_LUT_SIZE){
                phase = phase - SIN_LUT_SIZE;
            }
            if (phase < SIN_LUT_SIZE/2){
                val = 0;
            } else {
                val = 0xFF;
            }
            bufferOsc |= (val << 24);

            if(ii%8 == 0) {
                fputs("\n\t", fp);
            }

            fprintf(fp, "0x%.8X, ", bufferOsc);
        }
        fputs("\n};\n", fp);

    }

    fprintf(fp, "#endif\n");
    fclose(fp);
}

int main()
{
    generate_sinLuts();
    generate_squareLuts();

    return 0;
}
