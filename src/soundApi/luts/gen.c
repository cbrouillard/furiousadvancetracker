#include <stdio.h>
#include <math.h>

#define SAMPLERATE 16384
#define LUT_SIZE  128
#define MAX_AMPLITUDE 31
#define NBNOTES_PERSHAPE 72

float myLut[LUT_SIZE];

#define PRECISION 128

const char* notes[NBNOTES_PERSHAPE] = {
    "C3", "CS3", "D3", "DS3", "E3", "F3", "FS3", "G3", "GS3", "A3", "AS3", "B3",
    "C4", "CS4", "D4", "DS4", "E4", "F4", "FS4", "G4", "GS4", "A4", "AS4", "B4",
    "C5", "CS5", "D5", "DS5", "E5", "F5", "FS5", "G5", "GS5", "A5", "AS5", "B5",
    "C6", "CS6", "D6", "DS6", "E6", "F6", "FS6", "G6", "GS6", "A6", "AS6", "B6",
    "C7", "CS7", "D7", "DS7", "E7", "F7", "FS7", "G7", "GS7", "A7", "AS7", "B7",
    "C8", "CS8", "D8", "DS8", "E8", "F8", "FS8", "G8", "GS8", "A8", "AS8", "B8"
    };
const double freqs[NBNOTES_PERSHAPE] = {
    130.8, 138.6, 146.8, 155.6, 164.8, 174.6, 185.0, 196.0, 207.7, 220.0, 233.1, 246.9,
    261.6, 277.2, 293.7, 311.1, 329.6, 349.3, 370, 392, 415.3, 440, 466.2, 493.9,
    523.3, 554.4, 587.3, 622.3, 659.3, 698.5, 740.0, 784.0, 830.6, 880.0, 932.3, 987.8,
    1047, 1109, 1175, 1245, 1319, 1397, 1480, 1568, 1661, 1760, 1865, 1976,
    2093, 2217, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729, 3951,
    4186, 4435, 4699, 4978, 5274, 5588, 5920, 6272, 6645, 7040, 7459, 7902
};

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


    for (jj=0; jj< NBNOTES_PERSHAPE;jj++){

        // for each freq.
        fprintf(fp, "\n// %s, freq = %f\n", notes[jj], freqs[jj]);
        fprintf(fp, "const u32 snd_osc_sine_%s[LUT_PRECISION] = {\n", notes[jj]);

        bufferFreq = ((LUT_SIZE * freqs[jj]) / SAMPLERATE);
        //printf("Delta = %f\n", bufferFreq);
        //printf ("----\n");
        phase = 0;
        for(ii=0; ii < PRECISION; ii++)
        {
            bufferOsc = 0;

	        val = roundf (myLut[lround(phase)]);
            bufferOsc |= val;
            //printf("%.8X (p=%f) (lut=%x), ", bufferOsc, phase, myLut[(int)phase]);
            phase += bufferFreq;
            if (phase >= LUT_SIZE){
                phase = phase - LUT_SIZE;
            }
            bufferOsc &= 0x000000ff;

	        val = roundf (myLut[lround(phase)]);
            bufferOsc |= (val << 8);
            //printf("%.8X (p=%f) (lut=%x), ", bufferOsc, phase, myLut[(int)phase]);
            phase += bufferFreq;
            if (phase >= LUT_SIZE){
                phase = phase - LUT_SIZE;
            }
            bufferOsc &= 0x0000ffff;

            val = roundf (myLut[lround(phase)]);
            bufferOsc |= (val << 16);
            //printf("%.8X (p=%f) (lut=%x), ", bufferOsc, phase, myLut[(int)phase]);
            phase += bufferFreq;
            if (phase >= LUT_SIZE){
                phase = phase - LUT_SIZE;
            }
            bufferOsc &= 0x00ffffff;


	        val = roundf (myLut[lround(phase)]);
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
    fprintf(fp, "const u32* snd_osc_sine[%d] = {", NBNOTES_PERSHAPE);
        for (jj=0; jj< NBNOTES_PERSHAPE;jj++) {
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
    fprintf(fp, "#define LUT_PRECISION %d\n", PRECISION);
    fprintf(fp, "#endif\n");

    int bufferOsc = 0;
    double phase = 0;
    double bufferFreq = 0;
    int val = 0;


    for (jj=0; jj< NBNOTES_PERSHAPE;jj++){

        // for each freq.
        fprintf(fp, "\n// %s, freq = %f\n", notes[jj], freqs[jj]);
        fprintf(fp, "const u32 snd_osc_square_%s[LUT_PRECISION] = {\n", notes[jj]);

        bufferFreq = ((LUT_SIZE * freqs[jj]) / SAMPLERATE);
        phase = 0;
        for(ii=0; ii<PRECISION; ii++)
        {
            bufferOsc = 0;

            if (phase < LUT_SIZE/2){
                val = MAX_AMPLITUDE;
            } else {
                val = -MAX_AMPLITUDE;
            }
            bufferOsc |= val;
            bufferOsc &= 0x000000ff;
            phase = phase + bufferFreq;
			if (phase >= LUT_SIZE){
				phase = phase - LUT_SIZE;
			}

            if (phase < LUT_SIZE/2){
                val = MAX_AMPLITUDE;
            } else {
                val = -MAX_AMPLITUDE;
            }
            bufferOsc |= (val << 8);
            bufferOsc &= 0x0000ffff;
            phase = phase + bufferFreq;
			if (phase >= LUT_SIZE){
				phase = phase - LUT_SIZE;
			}

            if (phase < LUT_SIZE/2){
                val = MAX_AMPLITUDE;
            } else {
                val = -MAX_AMPLITUDE;
            }
            bufferOsc |= (val << 16);
            bufferOsc &= 0x00ffffff;
            phase = phase + bufferFreq;
			if (phase >= LUT_SIZE){
				phase = phase - LUT_SIZE;
			}

            if (phase < LUT_SIZE/2){
                val = MAX_AMPLITUDE;
            } else {
                val = -MAX_AMPLITUDE;
            }
            bufferOsc |= (val << 24);
            phase = phase + bufferFreq;
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
    fprintf(fp, "const u32* snd_osc_square[%d] = {", NBNOTES_PERSHAPE);
        for (jj=0; jj< NBNOTES_PERSHAPE;jj++) {
            if(jj%4 == 0) {
                fputs("\n\t", fp);
            }
            fprintf(fp, "snd_osc_square_%s, ", notes[jj]);
        }
    fputs("\n};\n", fp);

    fprintf(fp, "#endif\n");
    fclose(fp);
}

void generate_triangeLuts () {
    int ii;
    int jj;
    FILE *fp= fopen("osc_triangleluts.h", "w");

    fprintf(fp, "#ifndef _SOUND_API_OSC_TRIANGLELUTS_\n");
    fprintf(fp, "#define _SOUND_API_OSC_TRIANGLELUTS_\n\n");

    fprintf(fp, "#ifndef LUT_PRECISION\n");
    fprintf(fp, "#define LUT_PRECISION %d\n", PRECISION);
    fprintf(fp, "#endif\n");

    int bufferOsc = 0;
    double phase = 0;
    double bufferFreq = 0;
    int val = 0;


    for (jj=0; jj< NBNOTES_PERSHAPE;jj++){

        // for each freq.
        fprintf(fp, "\n// %s, freq = %f\n", notes[jj], freqs[jj]);
        fprintf(fp, "const u32 snd_osc_triangle_%s[LUT_PRECISION] = {\n", notes[jj]);

        bufferFreq = ((2 * M_PI * freqs[jj]) / SAMPLERATE);
        phase = 0;
        for(ii=0; ii<PRECISION; ii++)
        {
            bufferOsc = 0;

            if (phase < M_PI){
                val = lround ( (-MAX_AMPLITUDE + (2 * MAX_AMPLITUDE / M_PI) * phase));
            } else {
                val = lround ( (3*MAX_AMPLITUDE - (2 * MAX_AMPLITUDE / M_PI) * phase));
            }
            bufferOsc |= val;
            bufferOsc &= 0x000000ff;
            phase = phase + bufferFreq;
            if (phase >= 2*M_PI){
                phase = phase - 2*M_PI;
            }

            if (phase < M_PI){
                val = lround ( (-MAX_AMPLITUDE + (2 * MAX_AMPLITUDE / M_PI) * phase));
            } else {
                val = lround ( (3*MAX_AMPLITUDE - (2 * MAX_AMPLITUDE / M_PI) * phase));
            }
            bufferOsc |= (val << 8);
            bufferOsc &= 0x0000ffff;
            phase = phase + bufferFreq;
            if (phase >= 2*M_PI){
                phase = phase - 2*M_PI;
            }

            if (phase < M_PI){
                val = lround ( (-MAX_AMPLITUDE + (2 * MAX_AMPLITUDE / M_PI) * phase));
            } else {
                val = lround ( (3*MAX_AMPLITUDE - (2 * MAX_AMPLITUDE / M_PI) * phase));
            }
            bufferOsc |= (val << 16);
            bufferOsc &= 0x00ffffff;
            phase = phase + bufferFreq;
            if (phase >= 2*M_PI){
                phase = phase - 2*M_PI;
            }

            if (phase < M_PI){
                val = lround ( (-MAX_AMPLITUDE + (2 * MAX_AMPLITUDE / M_PI) * phase));
            } else {
                val = lround ( (3*MAX_AMPLITUDE - (2 * MAX_AMPLITUDE / M_PI) * phase));
            }
            bufferOsc |= (val << 24);
            phase = phase + bufferFreq;
            if (phase >= 2*M_PI){
                phase = phase - 2*M_PI;
            }

            if(ii%8 == 0) {
                fputs("\n\t", fp);
            }

            fprintf(fp, "0x%.8X, ", bufferOsc);
        }
        fputs("\n};\n", fp);

    }

    fprintf(fp, "\n// pointers\n");
    fprintf(fp, "const u32* snd_osc_triangle[%d] = {", NBNOTES_PERSHAPE);
        for (jj=0; jj< NBNOTES_PERSHAPE;jj++) {
            if(jj%4 == 0) {
                fputs("\n\t", fp);
            }
            fprintf(fp, "snd_osc_triangle_%s, ", notes[jj]);
        }
    fputs("\n};\n", fp);

    fprintf(fp, "#endif\n");
    fclose(fp);
}

void generate_sawLuts (){
    int ii;
    int jj;
    FILE *fp= fopen("osc_sawluts.h", "w");

    fprintf(fp, "#ifndef _SOUND_API_OSC_SAWLUTS_\n");
    fprintf(fp, "#define _SOUND_API_OSC_SAWLUTS_\n\n");

    fprintf(fp, "#ifndef LUT_PRECISION\n");
    fprintf(fp, "#define LUT_PRECISION %d\n", PRECISION);
    fprintf(fp, "#endif\n");

    int bufferOsc = 0;
    double phase = 0;
    double bufferFreq = 0;
    int val = 0;

    for (jj=0; jj< NBNOTES_PERSHAPE;jj++){

        // for each freq.
        fprintf(fp, "\n// %s, freq = %f\n", notes[jj], freqs[jj]);
        fprintf(fp, "const u32 snd_osc_saw_%s[LUT_PRECISION] = {\n", notes[jj]);

        bufferFreq = ((2*M_PI * freqs[jj]) / SAMPLERATE);
        phase = 0;
        for(ii=0; ii<PRECISION; ii++)
        {
            bufferOsc = 0;

            val = MAX_AMPLITUDE - (MAX_AMPLITUDE / M_PI * phase);
            bufferOsc |= val;
            bufferOsc &= 0x000000ff;
            phase = phase + bufferFreq;
            if (phase >= 2*M_PI){
                phase = phase - 2*M_PI;
            }

            val = MAX_AMPLITUDE - (MAX_AMPLITUDE / M_PI * phase);
            bufferOsc |= (val << 8);
            bufferOsc &= 0x0000ffff;
            phase = phase + bufferFreq;
            if (phase >= 2*M_PI){
                phase = phase - 2*M_PI;
            }

            val = MAX_AMPLITUDE - (MAX_AMPLITUDE / M_PI * phase);
            bufferOsc |= (val << 16);
            bufferOsc &= 0x00ffffff;
            phase = phase + bufferFreq;
            if (phase >= 2*M_PI){
                phase = phase - 2*M_PI;
            }

            val = MAX_AMPLITUDE - (MAX_AMPLITUDE / M_PI * phase);
            bufferOsc |= (val << 24);
            phase = phase + bufferFreq;
            if (phase >= 2*M_PI){
                phase = phase - 2*M_PI;
            }

            if(ii%8 == 0) {
                fputs("\n\t", fp);
            }

            fprintf(fp, "0x%.8X, ", bufferOsc);
        }
        fputs("\n};\n", fp);

    }

    fprintf(fp, "\n// pointers\n");
    fprintf(fp, "const u32* snd_osc_saw[%d] = {", NBNOTES_PERSHAPE);
        for (jj=0; jj< NBNOTES_PERSHAPE;jj++) {
            if(jj%4 == 0) {
                fputs("\n\t", fp);
            }
            fprintf(fp, "snd_osc_saw_%s, ", notes[jj]);
        }
    fputs("\n};\n", fp);

    fprintf(fp, "#endif\n");
    fclose(fp);

}

int main()
{
    int i;
    for (i = 0; i < LUT_SIZE; ++i) {
        myLut[i] = (float) MAX_AMPLITUDE * sinf(2.0f * M_PI * (float)i / LUT_SIZE);
        printf ("%f,", myLut[i]);
    }
    printf("\n");

    generate_squareLuts();
    generate_sinLuts();
    generate_triangeLuts ();
    generate_sawLuts ();

    return 0;
}
