#include <stdio.h>
#include <math.h>

#define SAMPLERATE 16384
#define LUT_SIZE  64

char myLut[LUT_SIZE];

#define PRECISION 64

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
    char val = 0;
    float phase = 0;
    float bufferFreq = 0;


    for (jj=0; jj< 12;jj++){

        // for each freq.
        fprintf(fp, "\n// %s, freq = %f\n", notes[jj], freqs[jj]);
        fprintf(fp, "const u32 snd_osc_sine_%s[LUT_PRECISION] = {\n", notes[jj]);

        bufferFreq = ((LUT_SIZE * freqs[jj]) / SAMPLERATE) + jj;
        //printf("Delta = %f\n", bufferFreq);
        //printf ("----\n");
        phase = 0;
        for(ii=0; ii < PRECISION; ii++)
        {
            bufferOsc = 0;

	        val = 1 * myLut[(int)phase];
            bufferOsc |= val;
            //printf("%.8X (p=%f) (lut=%x), ", bufferOsc, phase, myLut[(int)phase]);
            phase += bufferFreq;
            if (phase >= LUT_SIZE){
                phase = phase - LUT_SIZE;
            }
            bufferOsc &= 0x000000ff;

	        val = 1 * myLut[(int)phase];
            bufferOsc |= (val << 8);
            //printf("%.8X (p=%f) (lut=%x), ", bufferOsc, phase, myLut[(int)phase]);
            phase += bufferFreq;
            if (phase >= LUT_SIZE){
                phase = phase - LUT_SIZE;
            }
            bufferOsc &= 0x0000ffff;

            val = 1 * myLut[(int)phase];
            bufferOsc |= (val << 16);
            //printf("%.8X (p=%f) (lut=%x), ", bufferOsc, phase, myLut[(int)phase]);
            phase += bufferFreq;
            if (phase >= LUT_SIZE){
                phase = phase - LUT_SIZE;
            }
            bufferOsc &= 0x00ffffff;


	        val = 1 * myLut[(int)phase];
            bufferOsc |= (val << 24);
            //printf("%.8X (p=%f) (lut=%x)\n", bufferOsc, phase, myLut[(int)phase]);
            phase += bufferFreq;
            if (phase >= LUT_SIZE){
                phase = phase - LUT_SIZE;
            }

            if(ii%8 == 0) {
                fputs("\n\t", fp);
            }

            fprintf(fp, "0x%.8X, ", bufferOsc);
        }
        fputs("\n};\n", fp);

    }

    fprintf(fp, "\n// pointers\n");
    fprintf(fp, "const u32* snd_osc_sine[%d] = {", 12);
        for (jj=0; jj< 12;jj++) {
            if(jj%4 == 0) {
                fputs("\n\t", fp);
            }
            fprintf(fp, "snd_osc_sine_%s, ", notes[jj]);
        }
    fputs("\n};\n", fp);

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

        bufferFreq = ((LUT_SIZE * freqs[jj]) / SAMPLERATE);
        phase = 0;
        for(ii=0; ii<PRECISION; ii++)
        {
            bufferOsc = 0;

            phase = phase + bufferFreq;
            if (phase >= LUT_SIZE){
                phase = phase - LUT_SIZE;
            }
            if (phase < LUT_SIZE/2){
                val = 63;
            } else {
                val = -63;
            }
            bufferOsc |= val;
            bufferOsc &= 0x000000ff;

            phase = phase + bufferFreq;
            if (phase >= LUT_SIZE){
                phase = phase - LUT_SIZE;
            }
            if (phase < LUT_SIZE/2){
                val = 63;
            } else {
                val = -63;
            }
            bufferOsc |= (val << 8);
            bufferOsc &= 0x0000ffff;

            phase = phase + bufferFreq;
            if (phase >= LUT_SIZE){
                phase = phase - LUT_SIZE;
            }
            if (phase < LUT_SIZE/2){
                val = 63;
            } else {
                val = -63;
            }
            bufferOsc |= (val << 16);
            bufferOsc &= 0x00ffffff;

            phase = phase + bufferFreq;
            if (phase >= LUT_SIZE){
                phase = phase - LUT_SIZE;
            }
            if (phase < LUT_SIZE/2){
                val = 63;
            } else {
                val = -63;
            }
            bufferOsc |= (val << 24);

            if(ii%8 == 0) {
                fputs("\n\t", fp);
            }

            fprintf(fp, "0x%.8X, ", bufferOsc);
        }
        fputs("\n};\n", fp);

    }

    fprintf(fp, "\n// pointers\n");
    fprintf(fp, "const u32* snd_osc_square[%d] = {", 12);
        for (jj=0; jj< 12;jj++) {
            if(jj%4 == 0) {
                fputs("\n\t", fp);
            }
            fprintf(fp, "snd_osc_square_%s, ", notes[jj]);
        }
    fputs("\n};\n", fp);

    fprintf(fp, "#endif\n");
    fclose(fp);
}

int main()
{
    int i;
    for (i = 0; i < LUT_SIZE; ++i) {
        myLut[i] = (char) roundf(63 * sinf(2.0f * M_PI * (float)i / LUT_SIZE));
        printf ("%d,", myLut[i]);
    }
    printf("\n");

    generate_squareLuts();
    generate_sinLuts();

    return 0;
}
