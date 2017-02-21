# 1 "src/sprites/cursors.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "src/sprites/cursors.c"
# 17 "src/sprites/cursors.c"
# 1 "/home/cyril/Coding/GBA/ham/include/hel2.h" 1
# 43 "/home/cyril/Coding/GBA/ham/include/hel2.h"
# 1 "/home/cyril/Coding/GBA/ham/include/mygba.h" 1
# 141 "/home/cyril/Coding/GBA/ham/include/mygba.h"
# 1 "/home/cyril/Coding/GBA/ham/include/krawall.h" 1
# 18 "/home/cyril/Coding/GBA/ham/include/krawall.h"
# 1 "/home/cyril/Coding/GBA/ham/include/mtypes.h" 1
# 15 "/home/cyril/Coding/GBA/ham/include/mtypes.h"
typedef __attribute__ ((packed)) struct {
        unsigned long loopLength;
        unsigned long end;
        unsigned short c2Freq;
        unsigned char volDefault;
        unsigned char looped;
        unsigned char hq;
        signed char data[1];
} Sample;

typedef __attribute__ ((packed)) struct {
        unsigned short index[ 16 ];
        unsigned char data[1];
} Pattern;

typedef __attribute__ ((packed)) struct {
        unsigned char numOrders;
        unsigned char order[ 256 ];

        unsigned char channels;
        signed char channelPan[ 32 ];

        unsigned char songIndex[ 64 ];

        unsigned char volGlobal;

        unsigned char initSpeed;
        unsigned char initTempo;

        unsigned char flagVolOpt;
        unsigned char flagVolSlides;
        unsigned char flagAmigaLimits;

        const Pattern* patterns[1];
} Module;

extern const Sample* const samples[];
# 19 "/home/cyril/Coding/GBA/ham/include/krawall.h" 2

typedef unsigned int chandle;
# 43 "/home/cyril/Coding/GBA/ham/include/krawall.h"
void kragInit( int stereo );
# 57 "/home/cyril/Coding/GBA/ham/include/krawall.h"
void krapPlay( const Module *m, int mode, int song );
# 67 "/home/cyril/Coding/GBA/ham/include/krawall.h"
void krapStop();
# 83 "/home/cyril/Coding/GBA/ham/include/krawall.h"
void krapCallback( void (*func)( int, int ) );
# 97 "/home/cyril/Coding/GBA/ham/include/krawall.h"
void krapPause( int sfx );






void krapUnpause();
# 113 "/home/cyril/Coding/GBA/ham/include/krawall.h"
int krapIsPaused();
# 128 "/home/cyril/Coding/GBA/ham/include/krawall.h"
void krapSetMusicVol( unsigned int vol, int fade );
# 138 "/home/cyril/Coding/GBA/ham/include/krawall.h"
int kramWorker() __attribute__ ((long_call));






int kramGetActiveChannels();







void kramQualityMode( int );
# 167 "/home/cyril/Coding/GBA/ham/include/krawall.h"
chandle kramPlay( const Sample *s, int sfx, chandle c ) __attribute__ ((long_call));
# 181 "/home/cyril/Coding/GBA/ham/include/krawall.h"
chandle kramPlayExt( const Sample *s, int sfx, chandle c, unsigned int freq, unsigned int vol, int pan ) __attribute__ ((long_call));
# 190 "/home/cyril/Coding/GBA/ham/include/krawall.h"
int kramStop( chandle c ) __attribute__ ((long_call));
# 200 "/home/cyril/Coding/GBA/ham/include/krawall.h"
int kramSetFreq( chandle c, unsigned int freq ) __attribute__ ((long_call));
# 210 "/home/cyril/Coding/GBA/ham/include/krawall.h"
int kramSetVol( chandle c, unsigned int vol ) __attribute__ ((long_call));
# 220 "/home/cyril/Coding/GBA/ham/include/krawall.h"
int kramSetPan( chandle c, int pan ) __attribute__ ((long_call));
# 234 "/home/cyril/Coding/GBA/ham/include/krawall.h"
int kramSetPos( chandle c, unsigned int pos ) __attribute__ ((long_call));






void kramSetSFXVol( unsigned int vol );







void kramSetMasterVol( unsigned int vol );






void kradInterrupt();





void kradActivate();







void kradDeactivate();
# 142 "/home/cyril/Coding/GBA/ham/include/mygba.h" 2
# 196 "/home/cyril/Coding/GBA/ham/include/mygba.h"
# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/lib/gcc-lib/arm-thumb-elf/3.2.2/include/stdarg.h" 1 3 4
# 43 "/home/cyril/Coding/GBA/ham/gcc-arm/lib/gcc-lib/arm-thumb-elf/3.2.2/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 110 "/home/cyril/Coding/GBA/ham/gcc-arm/lib/gcc-lib/arm-thumb-elf/3.2.2/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;
# 197 "/home/cyril/Coding/GBA/ham/include/mygba.h" 2
# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdlib.h" 1 3
# 10 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdlib.h" 3
# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/_ansi.h" 1 3
# 15 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/_ansi.h" 3
# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/newlib.h" 1 3
# 16 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/_ansi.h" 2 3
# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/config.h" 1 3



# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/machine/ieeefp.h" 1 3
# 5 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/config.h" 2 3
# 17 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/_ansi.h" 2 3
# 11 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdlib.h" 2 3



# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/lib/gcc-lib/arm-thumb-elf/3.2.2/include/stddef.h" 1 3 4
# 213 "/home/cyril/Coding/GBA/ham/gcc-arm/lib/gcc-lib/arm-thumb-elf/3.2.2/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 325 "/home/cyril/Coding/GBA/ham/gcc-arm/lib/gcc-lib/arm-thumb-elf/3.2.2/include/stddef.h" 3 4
typedef int wchar_t;
# 15 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdlib.h" 2 3

# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/reent.h" 1 3
# 14 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/reent.h" 3
# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/_types.h" 1 3
# 12 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/_types.h" 3
typedef long _off_t;
__extension__ typedef long long _off64_t;


typedef int _ssize_t;





# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/lib/gcc-lib/arm-thumb-elf/3.2.2/include/stddef.h" 1 3 4
# 354 "/home/cyril/Coding/GBA/ham/gcc-arm/lib/gcc-lib/arm-thumb-elf/3.2.2/include/stddef.h" 3 4
typedef unsigned int wint_t;
# 23 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/_types.h" 2 3


typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    unsigned char __wchb[4];
  } __value;
} _mbstate_t;

typedef int _flock_t;
# 15 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/reent.h" 2 3




typedef unsigned long __ULong;
# 40 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/reent.h" 3
struct _Bigint
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};


struct __tm
{
  int __tm_sec;
  int __tm_min;
  int __tm_hour;
  int __tm_mday;
  int __tm_mon;
  int __tm_year;
  int __tm_wday;
  int __tm_yday;
  int __tm_isdst;
};
# 68 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/reent.h" 3
struct _atexit {
        struct _atexit *_next;
        int _ind;
        void (*_fns[32])(void);
        void *_fnargs[32];
        __ULong _fntypes;
};
# 91 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/reent.h" 3
struct __sbuf {
        unsigned char *_base;
        int _size;
};






typedef long _fpos_t;
# 156 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/reent.h" 3
struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;






  void * _cookie;

  int (*_read) (void * _cookie, char *_buf, int _n);
  int (*_write) (void * _cookie, const char *_buf, int _n);

  _fpos_t (*_seek) (void * _cookie, _fpos_t _offset, int _whence);
  int (*_close) (void * _cookie);


  struct __sbuf _ub;
  unsigned char *_up;
  int _ur;


  unsigned char _ubuf[3];
  unsigned char _nbuf[1];


  struct __sbuf _lb;


  int _blksize;
  int _offset;


  struct _reent *_data;



  _flock_t _lock;

};
# 249 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/reent.h" 3
typedef struct __sFILE __FILE;


struct _glue
{
  struct _glue *_next;
  int _niobs;
  __FILE *_iobs;
};
# 280 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/reent.h" 3
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;




};
# 532 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/reent.h" 3
struct _reent
{
  int _errno;




  __FILE *_stdin, *_stdout, *_stderr;

  int _inc;
  char _emergency[25];

  int _current_category;
  const char *_current_locale;

  int __sdidinit;

  void (*__cleanup) (struct _reent *);


  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;


  int _cvtlen;
  char *_cvtbuf;

  union
    {
      struct
        {
          unsigned int _unused_rand;
          char * _strtok_last;
          char _asctime_buf[26];
          struct __tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;
          struct _rand48 _r48;
          _mbstate_t _mblen_state;
          _mbstate_t _mbtowc_state;
          _mbstate_t _wctomb_state;
          char _l64a_buf[8];
          char _signal_buf[24];
          int _getdate_err;
          _mbstate_t _mbrlen_state;
          _mbstate_t _mbrtowc_state;
          _mbstate_t _mbsrtowcs_state;
          _mbstate_t _wcrtomb_state;
          _mbstate_t _wcsrtombs_state;
        } _reent;



      struct
        {

          unsigned char * _nextf[30];
          unsigned int _nmalloc[30];
        } _unused;
    } _new;


  struct _atexit *_atexit;
  struct _atexit _atexit0;


  void (**(_sig_func))(int);




  struct _glue __sglue;
  __FILE __sf[3];
};
# 728 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/reent.h" 3
extern struct _reent *_impure_ptr ;

void _reclaim_reent (struct _reent *);
# 17 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdlib.h" 2 3
# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/machine/stdlib.h" 1 3
# 18 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdlib.h" 2 3

# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/alloca.h" 1 3
# 20 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdlib.h" 2 3




typedef struct
{
  int quot;
  int rem;
} div_t;

typedef struct
{
  long quot;
  long rem;
} ldiv_t;
# 45 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdlib.h" 3
extern int __mb_cur_max;



void abort (void) __attribute__ ((noreturn));
int abs (int);
int atexit (void (*__func)(void));
double atof (const char *__nptr);

float atoff (const char *__nptr);

int atoi (const char *__nptr);
long atol (const char *__nptr);
void * bsearch (const void * __key, const void * __base, size_t __nmemb, size_t __size, int (* _compar) (const void *, const void *));




void * calloc (size_t __nmemb, size_t __size);
div_t div (int __numer, int __denom);
void exit (int __status) __attribute__ ((noreturn));
void free (void *);
char * getenv (const char *__string);
char * _getenv_r (struct _reent *, const char *__string);
char * _findenv (const char *, int *);
char * _findenv_r (struct _reent *, const char *, int *);
long labs (long);
ldiv_t ldiv (long __numer, long __denom);
void * malloc (size_t __size);
int mblen (const char *, size_t);
int _mblen_r (struct _reent *, const char *, size_t, _mbstate_t *);
int mbtowc (wchar_t *, const char *, size_t);
int _mbtowc_r (struct _reent *, wchar_t *, const char *, size_t, _mbstate_t *);
int wctomb (char *, wchar_t);
int _wctomb_r (struct _reent *, char *, wchar_t, _mbstate_t *);
size_t mbstowcs (wchar_t *, const char *, size_t);
size_t _mbstowcs_r (struct _reent *, wchar_t *, const char *, size_t, _mbstate_t *);
size_t wcstombs (char *, const wchar_t *, size_t);
size_t _wcstombs_r (struct _reent *, char *, const wchar_t *, size_t, _mbstate_t *);


int mkstemp (char *);
char * mktemp (char *);


void qsort (void * __base, size_t __nmemb, size_t __size, int(*_compar)(const void *, const void *));
int rand (void);
void * realloc (void * __r, size_t __size);
void srand (unsigned __seed);
double strtod (const char *__n, char **__end_PTR);
double _strtod_r (struct _reent *,const char *__n, char **__end_PTR);
float strtof (const char *__n, char **__end_PTR);






long strtol (const char *__n, char **__end_PTR, int __base);
long _strtol_r (struct _reent *,const char *__n, char **__end_PTR, int __base);
unsigned long strtoul (const char *__n, char **__end_PTR, int __base);
unsigned long _strtoul_r (struct _reent *,const char *__n, char **__end_PTR, int __base);

int system (const char *__string);


long a64l (const char *__input);
char * l64a (long __input);
char * _l64a_r (struct _reent *,long __input);
int on_exit (void (*__func)(int, void *),void * __arg);
void _Exit (int __status) __attribute__ ((noreturn));
int putenv (const char *__string);
int _putenv_r (struct _reent *, const char *__string);
int setenv (const char *__string, const char *__value, int __overwrite);
int _setenv_r (struct _reent *, const char *__string, const char *__value, int __overwrite);

char * gcvt (double,int,char *);
char * gcvtf (float,int,char *);
char * fcvt (double,int,int *,int *);
char * fcvtf (float,int,int *,int *);
char * ecvt (double,int,int *,int *);
char * ecvtbuf (double, int, int*, int*, char *);
char * fcvtbuf (double, int, int*, int*, char *);
char * ecvtf (float,int,int *,int *);
char * dtoa (double, int, int, int *, int*, char**);
int rand_r (unsigned *__seed);

double drand48 (void);
double _drand48_r (struct _reent *);
double erand48 (unsigned short [3]);
double _erand48_r (struct _reent *, unsigned short [3]);
long jrand48 (unsigned short [3]);
long _jrand48_r (struct _reent *, unsigned short [3]);
void lcong48 (unsigned short [7]);
void _lcong48_r (struct _reent *, unsigned short [7]);
long lrand48 (void);
long _lrand48_r (struct _reent *);
long mrand48 (void);
long _mrand48_r (struct _reent *);
long nrand48 (unsigned short [3]);
long _nrand48_r (struct _reent *, unsigned short [3]);
unsigned short *
       seed48 (unsigned short [3]);
unsigned short *
       _seed48_r (struct _reent *, unsigned short [3]);
void srand48 (long);
void _srand48_r (struct _reent *, long);
long long strtoll (const char *__n, char **__end_PTR, int __base);
long long _strtoll_r (struct _reent *, const char *__n, char **__end_PTR, int __base);
unsigned long long strtoull (const char *__n, char **__end_PTR, int __base);
unsigned long long _strtoull_r (struct _reent *, const char *__n, char **__end_PTR, int __base);


void cfree (void *);
# 172 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdlib.h" 3
char * _dtoa_r (struct _reent *, double, int, int, int *, int*, char**);

void * _malloc_r (struct _reent *, size_t);
void * _calloc_r (struct _reent *, size_t, size_t);
void _free_r (struct _reent *, void *);
void * _realloc_r (struct _reent *, void *, size_t);
void _mstats_r (struct _reent *, char *);

int _system_r (struct _reent *, const char *);

void __eprintf (const char *, const char *, unsigned int, const char *);
# 213 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdlib.h" 3

# 198 "/home/cyril/Coding/GBA/ham/include/mygba.h" 2
# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/string.h" 1 3
# 14 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/string.h" 3
# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/lib/gcc-lib/arm-thumb-elf/3.2.2/include/stddef.h" 1 3 4
# 15 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/string.h" 2 3







void * memchr (const void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void * memcpy (void *, const void *, size_t);
void * memmove (void *, const void *, size_t);
void * memset (void *, int, size_t);
char *strcat (char *, const char *);
char *strchr (const char *, int);
int strcmp (const char *, const char *);
int strcoll (const char *, const char *);
char *strcpy (char *, const char *);
size_t strcspn (const char *, const char *);
char *strerror (int);
size_t strlen (const char *);
char *strncat (char *, const char *, size_t);
int strncmp (const char *, const char *, size_t);
char *strncpy (char *, const char *, size_t);
char *strpbrk (const char *, const char *);
char *strrchr (const char *, int);
size_t strspn (const char *, const char *);
char *strstr (const char *, const char *);


char *strtok (char *, const char *);


size_t strxfrm (char *, const char *, size_t);


char *strtok_r (char *, const char *, char **);

int bcmp (const void *, const void *, size_t);
void bcopy (const void *, void *, size_t);
void bzero (void *, size_t);
int ffs (int);
char *index (const char *, int);
void * memccpy (void *, const void *, int, size_t);
void * mempcpy (void *, const void *, size_t);
char *rindex (const char *, int);
int strcasecmp (const char *, const char *);
char *strdup (const char *);
char *_strdup_r (struct _reent *, const char *);
char *strndup (const char *, size_t);
char *_strndup_r (struct _reent *, const char *, size_t);
char *strerror_r (int, char *, size_t);
size_t strlcat (char *, const char *, size_t);
size_t strlcpy (char *, const char *, size_t);
int strncasecmp (const char *, const char *, size_t);
size_t strnlen (const char *, size_t);
char *strsep (char **, const char *);
char *strlwr (char *);
char *strupr (char *);
# 98 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/string.h" 3

# 199 "/home/cyril/Coding/GBA/ham/include/mygba.h" 2
# 294 "/home/cyril/Coding/GBA/ham/include/mygba.h"
typedef unsigned char bool;

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long long int u64;

typedef signed char s8;
typedef signed short int s16;
typedef signed int s32;
typedef signed long long int s64;

typedef volatile unsigned char vu8;
typedef volatile unsigned short int vu16;
typedef volatile unsigned int vu32;
typedef volatile unsigned long long int vu64;

typedef volatile signed char vs8;
typedef volatile signed short int vs16;
typedef volatile signed int vs32;
typedef volatile signed long long int vs64;



typedef s16 sfp16;
typedef s32 sfp32;
typedef u16 ufp16;
typedef u32 ufp32;
# 442 "/home/cyril/Coding/GBA/ham/include/mygba.h"
extern u32 IntrTable[];
# 3511 "/home/cyril/Coding/GBA/ham/include/mygba.h"
extern volatile u8 _hamlib_intset;
# 3630 "/home/cyril/Coding/GBA/ham/include/mygba.h"
extern int dsprintf(char *,const char*, ...);
extern void __PrintStr(char *);

extern unsigned char __outstr[];
extern unsigned char __finstr[];
extern unsigned char __kinstr[];
extern int finptr;
extern int foutptr;
extern int kinptr;
extern int koutptr;
# 3661 "/home/cyril/Coding/GBA/ham/include/mygba.h"
extern int dgetch (void);


extern u8 _hamlib_assert_to_dbgshow;
# 3679 "/home/cyril/Coding/GBA/ham/include/mygba.h"
extern void dbg_Show(char*);
# 3709 "/home/cyril/Coding/GBA/ham/include/mygba.h"
typedef struct tile_info_typ
{
    u16 col_mode;
        u8 first_block;
    u8 offset_from_cbb;
    u8 cbb;
} tile_info,*tile_info_ptr;

typedef struct map_info_typ
{
    u8 first_block;
    u8 map_rot;
    u16 map_size;
        u16 map_x;
        u16 map_y;
} map_info,*map_info_ptr;

typedef struct map_fragment_info_typ
{
    u16* src;
    u16* src_ofs;
    u8 map_rot;
        u16 map_total_x;
        u16 map_total_y;
        u16 map_ofs_x;
        u16 map_ofs_y;
        u16 map_tiles_x;
        u16 map_tiles_y;
        u16 map_line_ofs;

} map_fragment_info,*map_fragment_info_ptr;





extern tile_info_ptr ham_InitTileSet(void* src,u16 size_u16,u8 col_mode,u8 cbb_only_mode);
extern tile_info_ptr ham_InitTileEmptySet(u16 num_tiles, u8 col_mode, u8 cbb_only_mode);
extern map_info_ptr ham_InitMapEmptySet(u8 map_size,u8 map_rot);
extern map_info_ptr ham_InitMapSet(void* src,u16 size_u16,u8 map_size,u8 map_rot);
extern void ham_SetMapTile(u8 bgno,u32 x,u32 y,u32 tileno);
extern void ham_SetMapTileEx(u8 bgno,u32 x,u32 y,u32 tileno,u32 hflip, u32 vflip, u32 palno);
extern u16 ham_GetMapTile(u8 bgno,u8 x,u8 y);
extern void ham_ReloadTileGfx(tile_info_ptr ti, u16* src,u16 target_tileno,u16 num_tiles);
extern map_fragment_info_ptr ham_InitMapFragment(void* src,
                                                                                  u16 map_total_x,u16 map_total_y,
                                          u16 map_ofs_x, u16 map_ofs_y,
                                          u8 map_tiles_x,u8 map_tiles_y,
                                          u8 map_rot);
extern void ham_InsertMapFragment(map_fragment_info_ptr mfi,u8 bgno,u8 x,u8 y);
extern void ham_DeInitTileSet(tile_info_ptr ti);
extern void ham_DeInitMapSet(map_info_ptr mi);
extern void ham_DeInitMapFragment(map_fragment_info_ptr mfi);





extern void ham_SetFxMode(u16 source_layer, u16 target_layer, u16 fx_mode);
extern void ham_SetFxAlphaLevel(u16 source_intensity,u16 target_intensity);
extern void ham_SetFxBrightnessLevel(u16 intensity);
# 3780 "/home/cyril/Coding/GBA/ham/include/mygba.h"
typedef struct obj_info_typ
{
        u8 taken;
    u8 active;
        u16 objatr0;
        u16 objatr1;
        u16 objatr2;
        u8 prev_obj;
        u8 next_obj;
} obj_info,*obj_info_ptr;




extern obj_info ham_obj[];
extern u8 ham_obj_first;




extern void ham_InitObj(void);
extern void ham_ResetObj(void);
extern void ham_DeleteObj(u8 entryno);
extern u8 ham_CreateObj(void* src,u16 obj_shape,u16 obj_size,u16 obj_mode,u16 col_mode,u16 pal_no ,u16 mosaic,u16 hflip,u16 vflip,u16 prio, u16 dbl_size, u16 x, u16 y);
extern u8 ham_CreateObjFromGfxSlot(u16 slot,u16 obj_shape,u16 obj_size,u16 obj_mode,u16 col_mode,u16 pal_no ,u16 mosaic,u16 hflip,u16 vflip,u16 prio, u16 dbl_size, u16 x, u16 y);
extern u8 ham_CreateObjFromBg(u8 bgno, u32 bg_tileno_x, u32 bg_tileno_y, u16 obj_shape,u16 obj_size, u32 erase_bg, u32 tileno_filler);
extern u16 ham_CreateObjGfx(void* src,u16 obj_shape,u16 obj_size,u16 col_mode);
extern void ham_DeleteObjGfx(u16 slotno);
extern u8 ham_CloneObj(u8 objno, u16 x, u16 y);
extern void ham_SetObjMode(u8 objno,u16 obj_mode);
extern void ham_SetObjX(u8 objno,u16 x);
extern void ham_SetObjY(u8 objno,u16 y);
extern void ham_SetObjXY(u8 objno,u16 x,u16 y);
extern void ham_SetObjMosaic(u8 objno,u8 val);
extern void ham_SetObjDblSize(u8 objno,u8 val);
extern void ham_SetObjHFlip(u8 objno,u8 val);
extern void ham_SetObjVFlip(u8 objno,u8 val);
extern void ham_SetObjPrio(u8 objno,u8 val);
extern void ham_SetObjVisible(u8 objno,u8 val);
extern void ham_SetObjRotEnable(u8 objno,u8 val);
extern void ham_SetObjRotSetSelect(u8 objno,u8 val);
extern void ham_UpdateObjGfx(u8 objno,void* src);
extern u16 ham_GetObjGfxSlot(u8 objno);
extern u8 ham_GetObjPal16(u8 objno);
extern void ham_SetObjGfxSlot(u8 objno,u16 slotno,u8 palno);
extern void ham_UpdateObjPal16(u8 objno,u8 pal_no);
extern void ham_SetObjBefore(u8 objno,u8 objno_target);
extern void ham_CopyObjToOAM(void);
extern u32 ham_GetObjAvailable(void);
# 3837 "/home/cyril/Coding/GBA/ham/include/mygba.h"
typedef struct bg_info_typ
{
        map_info_ptr mi;
        tile_info_ptr ti;
    u16 mosaic;
    u16 active;
    u16 prio;
        u8 is_rot_bg;
        s16 x_scroll;
        s16 y_scroll;
} bg_info,*bg_info_ptr;




extern bg_info ham_bg[];




extern void ham_InitBg( u16 bgno, u16 active, u16 prio, u16 mosaic);
extern void ham_ResetBg(void);
extern u8 ham_GetBgType(u8 bgno);
extern void ham_SetBgMode(u8 bgmode);
extern void ham_SetBgVisible(u32 bgno,u32 active);
extern void ham_DeInitBg( u16 bgno);
extern void ham_SetBgXY(u16 bgno,u16 x, u16 y);







extern void ham_PutPixel(u32 x,u32 y,u32 col_value);
extern void ham_PutLine(s16 x1, s16 y1, s16 x2, s16 y2, u16 col_value);
extern void ham_LoadBitmap(void* src);
extern void ham_ClearBackBuffer(u32 col_value);
extern void ham_FlipBGBuffer(void);
extern u8 ham_GetBGBuffer(void);
# 3886 "/home/cyril/Coding/GBA/ham/include/mygba.h"
typedef struct win_info_typ
{
    u32 x1;
    u32 y1;
    u32 x2;
    u32 y2;
    u32 inside_on_for;

    u32 outside_on_for;

    u32 fx_on;
} win_info,*win_info_ptr;




extern win_info ham_win[];




extern void ham_InitWin(void);
extern void ham_CopyWinToHW(void);
extern void ham_CreateWin(u32 winno,u32 x1,u32 y1,u32 x2,u32 y2,u32 inside_on_for,u32 outside_on_for,u32 fx_on);
extern void ham_DeleteWin(u32 winno);






extern const s32 SIN_SFP32[];
extern const s32 COS_SFP32[];



extern void ham_RotBg(u8 bgno,u16 angle,s32 center_x,s32 center_y, s32 zoom);
extern void ham_RotBgEx(u8 bgno,u16 angle,s32 center_x,s32 center_y, u16 x_scroll, u16 y_scroll, s32 zoom_x, s32 zoom_y);
extern void ham_RotObjDefineSet(u8 rotset,u16 angle, s32 zoom_x, s32 zoom_y);







extern char* HexToChar(u32 hexval);
extern int CharToHex(char* thestr);
# 3944 "/home/cyril/Coding/GBA/ham/include/mygba.h"
typedef struct text_info_typ
{
    bg_info_ptr bg;
        map_info_ptr mi;
        tile_info_ptr ti;
        u8 front_col;
        u8 back_col;
        u8 bgno;
} text_info,*text_info_ptr;




extern text_info_ptr ham_text;
# 3971 "/home/cyril/Coding/GBA/ham/include/mygba.h"
extern void ham_InitText(u8 bgno);
extern void ham_DeInitText(void);
extern void ham_VBAText(char*, ...);
extern void ham_DrawText(u8 x, u8 y,char*, ...);
extern void ham_SetTextCol(u8 front_col,u8 back_col);
# 3984 "/home/cyril/Coding/GBA/ham/include/mygba.h"
extern int vsprintf(char *buf, const char *fmt, va_list args);
# 3994 "/home/cyril/Coding/GBA/ham/include/mygba.h"
extern void ham_Init(void);
extern u32 ham_GetHAMlibVersion(void);
extern void ham_ResetAll(void);
extern int atexit(void (*)(void));
# 4008 "/home/cyril/Coding/GBA/ham/include/mygba.h"
extern u8 ham_memvram_alloctable[];
extern u8 ham_memobj_alloctable[];
extern u8 ham_memobj_refcnt[];





extern void ham_InitMemVram(void);
extern void ham_InitMemObj(void);
extern void ham_InitMemSRAM(void);
extern u32 ham_AllocMemSRAM(u32 bytes_needed);
extern void ham_DeAllocMemSRAM(u32 blockno);
extern u8 ham_AllocMemVram(u16 size_u16,u8 cbb_only_mode);
extern u16 ham_AllocMemObj(u8 obj_shape,u8 obj_size,u8 col_mode);
extern void ham_DeAllocMemVram(u8 first_block);
extern void ham_DeAllocMemObj(u16 first_block);
extern void ham_ReAllocMemObj(u16 first_block);
# 4036 "/home/cyril/Coding/GBA/ham/include/mygba.h"
extern void ham_LoadBGPal(void* src,u16 size_u16s);
extern void ham_LoadBGPal16(void* src,u8 pal_no);
extern void ham_LoadBGPal256(void* src);
extern void ham_LoadObjPal(void* src,u16 size_u16s);
extern void ham_LoadObjPal16(void* src,u8 pal_no);
extern void ham_LoadObjPal256(void* src);
extern void ham_FadePal(u8 palno,s8 delta_per_call);
extern u8 ham_FadePalCol(u16 colno,s8 delta_per_call);
extern void ham_SetBgPalCol(u8 color_number, u16 rgb_value);
extern void ham_SetBgPalColRGB(u8 color_number, u8 r, u8 g, u8 b);
extern void ham_SetObjPalCol(u8 color_number, u16 rgb_value);
extern void ham_SetObjPalColRGB(u8 color_number, u8 r, u8 g, u8 b);
# 4059 "/home/cyril/Coding/GBA/ham/include/mygba.h"
extern void ham_EmptyInt();
extern void ham_InitIntrTable();
extern void ham_StartIntHandler(u8 intno,void* fp);
extern void ham_StopIntHandler(u8 intno);






typedef struct sample_info_typ sample_info ;

struct sample_info_typ
{
    u32 length;
        u8* data;
        u16 bitrate;
        u8 pre_divide_ratio;
        u16 divide_ratio;
        u16 mix_buf_size;
        u32 current_pos;
        u8 playing;
        struct sample_info_typ *next;
        struct sample_info_typ *prev;
};


typedef struct {
    u16 type;
    u16 stat;
    u32 freq;
    u32 loop;
    u32 size;
    s8 data[1];
} WaveData;


typedef struct mixer_info_typ
{
        u16 bitrate;

        u8* mix_buf[2];

        u16 mix_buf_size;
        u16 mix_buf_cycles;
        s8 buf_no;

        struct sample_info_typ *first_sample;
        struct sample_info_typ *last_sample;

}mixer_info,*mixer_info_ptr;


extern mixer_info ham_mixer;




extern void ham_InitSound(void);
extern void ham_InitDSound(void);
extern void ham_DeInitDSound(void);
extern void ham_InitMixer(u16 bitrate);
extern void ham_DeInitMixer(void);
extern void ham_SyncMixer(void) __attribute__ ((section (".iwram"), long_call));
extern void ham_UpdateMixer(void) __attribute__ ((section (".iwram"), long_call));
extern void ham_PlaySample(sample_info *sample);
extern void ham_ChangeSampleBitrate(sample_info* sample,u16 bitrate);
extern sample_info *ham_InitSample(u8* data,u32 length,u16 bitrate);
extern void ham_DeInitSample(sample_info *sample);
extern void ham_KillSample(sample_info *sample);
# 4138 "/home/cyril/Coding/GBA/ham/include/mygba.h"
typedef struct ramdata_info_typ
{
    u16 length_blocks;
    u32 length_bytes;
    u16 info_blockno;
    u16 data_blockno;
    u32 next_ramdata;
    u32 small_data_store;






    char ident[46];

} ramdata_info,*ramdata_info_ptr;


typedef struct ram_info_typ
{
    u32 ram_mode;




    u32 ham_config_found;


    void* saveRAM_start;

    u32 rootblk;

} ram_info,*ram_info_ptr;




extern void ham_ResetRAM(void);
extern u32 ham_InitRAM(u32 ram_type);
extern void ham_LoadRAMInfo(u32 blockno,ramdata_info_ptr pramdat);
extern void ham_SaveRAMInfo(ramdata_info_ptr pramdat);
extern void ham_SaveIntToRAM(char* ident_string,int the_number);
extern u32 ham_LoadIntFromRAM(char* ident_string, int* target_int);
extern void ham_SaveRawToRAM(char* ident_string,void* data, u32 length_in_bytes);
extern u32 ham_LoadRawFromRAM(char* ident_string, void* target_data);
# 4243 "/home/cyril/Coding/GBA/ham/include/mygba.h"
# 1 "/home/cyril/Coding/GBA/ham/include/gba.h" 1
# 4244 "/home/cyril/Coding/GBA/ham/include/mygba.h" 2
# 44 "/home/cyril/Coding/GBA/ham/include/hel2.h" 2
# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdio.h" 1 3
# 34 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdio.h" 3
# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/lib/gcc-lib/arm-thumb-elf/3.2.2/include/stddef.h" 1 3 4
# 35 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdio.h" 2 3
# 46 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdio.h" 3
# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/types.h" 1 3
# 24 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/types.h" 3
typedef short int __int16_t;
typedef unsigned short int __uint16_t;





typedef int __int32_t;
typedef unsigned int __uint32_t;






__extension__ typedef long long __int64_t;
__extension__ typedef unsigned long long __uint64_t;
# 59 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/types.h" 3
# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/lib/gcc-lib/arm-thumb-elf/3.2.2/include/stddef.h" 1 3 4
# 151 "/home/cyril/Coding/GBA/ham/gcc-arm/lib/gcc-lib/arm-thumb-elf/3.2.2/include/stddef.h" 3 4
typedef long int ptrdiff_t;
# 60 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/types.h" 2 3
# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/machine/types.h" 1 3
# 36 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/machine/types.h" 3
typedef long int __off_t;
typedef int __pid_t;

__extension__ typedef long long int __loff_t;
# 61 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/types.h" 2 3
# 82 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/types.h" 3
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;



typedef unsigned short ushort;
typedef unsigned int uint;



typedef unsigned long clock_t;




typedef long time_t;




struct timespec {
  time_t tv_sec;
  long tv_nsec;
};

struct itimerspec {
  struct timespec it_interval;
  struct timespec it_value;
};


typedef long daddr_t;
typedef char * caddr_t;







typedef unsigned short ino_t;
# 158 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/types.h" 3
typedef short dev_t;




typedef long off_t;

typedef unsigned short uid_t;
typedef unsigned short gid_t;


typedef int pid_t;
typedef long key_t;
typedef _ssize_t ssize_t;
# 184 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/types.h" 3
typedef unsigned int mode_t __attribute__ ((__mode__ (__SI__)));



typedef unsigned short nlink_t;
# 210 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/types.h" 3
typedef long fd_mask;







typedef struct _types_fd_set {
        fd_mask fds_bits[(((64)+(((sizeof (fd_mask) * 8))-1))/((sizeof (fd_mask) * 8)))];
} _types_fd_set;
# 47 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdio.h" 2 3



typedef _fpos_t fpos_t;
typedef __FILE FILE;





# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/sys/stdio.h" 1 3
# 58 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdio.h" 2 3
# 162 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdio.h" 3
FILE * tmpfile (void);
char * tmpnam (char *);
int fclose (FILE *);
int fflush (FILE *);
FILE * freopen (const char *, const char *, FILE *);
void setbuf (FILE *, char *);
int setvbuf (FILE *, char *, int, size_t);
int fprintf (FILE *, const char *, ...);
int fscanf (FILE *, const char *, ...);
int printf (const char *, ...);
int scanf (const char *, ...);
int sscanf (const char *, const char *, ...);
int vfprintf (FILE *, const char *, __gnuc_va_list);
int vprintf (const char *, __gnuc_va_list);
int vsprintf (char *, const char *, __gnuc_va_list);
int fgetc (FILE *);
char * fgets (char *, int, FILE *);
int fputc (int, FILE *);
int fputs (const char *, FILE *);
int getc (FILE *);
int getchar (void);
char * gets (char *);
int putc (int, FILE *);
int putchar (int);
int puts (const char *);
int ungetc (int, FILE *);
size_t fread (void *, size_t _size, size_t _n, FILE *);
size_t fwrite (const void * , size_t _size, size_t _n, FILE *);
int fgetpos (FILE *, fpos_t *);
int fseek (FILE *, long, int);
int fsetpos (FILE *, const fpos_t *);
long ftell ( FILE *);
void rewind (FILE *);
void clearerr (FILE *);
int feof (FILE *);
int ferror (FILE *);
void perror (const char *);

FILE * fopen (const char *_name, const char *_type);
int sprintf (char *, const char *, ...);
int remove (const char *);
int rename (const char *, const char *);


int asprintf (char **, const char *, ...);
int fseeko (FILE *, off_t, int);
off_t ftello ( FILE *);
int vfiprintf (FILE *, const char *, __gnuc_va_list);
int iprintf (const char *, ...);
int fiprintf (FILE *, const char *, ...);
int siprintf (char *, const char *, ...);
char * tempnam (const char *, const char *);
int vasprintf (char **, const char *, __gnuc_va_list);
int vsnprintf (char *, size_t, const char *, __gnuc_va_list);
int vfscanf (FILE *, const char *, __gnuc_va_list);
int vscanf (const char *, __gnuc_va_list);
int vsscanf (const char *, const char *, __gnuc_va_list);

int fcloseall (void);
int snprintf (char *, size_t, const char *, ...);
# 231 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdio.h" 3
FILE * fdopen (int, const char *);

int fileno (FILE *);
int getw (FILE *);
int pclose (FILE *);
FILE * popen (const char *, const char *);
int putw (int, FILE *);
void setbuffer (FILE *, char *, int);
int setlinebuf (FILE *);
int getc_unlocked (FILE *);
int getchar_unlocked (void);
void flockfile (FILE *);
int ftrylockfile (FILE *);
void funlockfile (FILE *);
int putc_unlocked (int, FILE *);
int putchar_unlocked (int);






int _asprintf_r (struct _reent *, char **, const char *, ...);
int _fcloseall_r (struct _reent *);
FILE * _fdopen_r (struct _reent *, int, const char *);
FILE * _fopen_r (struct _reent *, const char *, const char *);
int _fscanf_r (struct _reent *, FILE *, const char *, ...);
int _getchar_r (struct _reent *);
char * _gets_r (struct _reent *, char *);
int _iprintf_r (struct _reent *, const char *, ...);
int _mkstemp_r (struct _reent *, char *);
char * _mktemp_r (struct _reent *, char *);
void _perror_r (struct _reent *, const char *);
int _printf_r (struct _reent *, const char *, ...);
int _putchar_r (struct _reent *, int);
int _puts_r (struct _reent *, const char *);
int _remove_r (struct _reent *, const char *);
int _rename_r (struct _reent *, const char *_old, const char *_new);

int _scanf_r (struct _reent *, const char *, ...);
int _sprintf_r (struct _reent *, char *, const char *, ...);
int _snprintf_r (struct _reent *, char *, size_t, const char *, ...);
int _sscanf_r (struct _reent *, const char *, const char *, ...);
char * _tempnam_r (struct _reent *, const char *, const char *);
FILE * _tmpfile_r (struct _reent *);
char * _tmpnam_r (struct _reent *, char *);
int _vasprintf_r (struct _reent *, char **, const char *, __gnuc_va_list);
int _vfprintf_r (struct _reent *, FILE *, const char *, __gnuc_va_list);
int _vprintf_r (struct _reent *, const char *, __gnuc_va_list);
int _vsprintf_r (struct _reent *, char *, const char *, __gnuc_va_list);
int _vsnprintf_r (struct _reent *, char *, size_t, const char *, __gnuc_va_list);
int _vfscanf_r (struct _reent *, FILE *, const char *, __gnuc_va_list);
int _vscanf_r (struct _reent *, const char *, __gnuc_va_list);
int _vsscanf_r (struct _reent *, const char *, const char *, __gnuc_va_list);

ssize_t __getdelim (char **, size_t *, int, FILE *);
ssize_t __getline (char **, size_t *, FILE *);
# 309 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdio.h" 3
int __srget (FILE *);
int __swbuf (int, FILE *);






FILE *funopen (const void * _cookie, int (*readfn)(void * _cookie, char *_buf, int _n), int (*writefn)(void * _cookie, const char *_buf, int _n), fpos_t (*seekfn)(void * _cookie, fpos_t _off, int _whence), int (*closefn)(void * _cookie));
# 416 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/stdio.h" 3

# 45 "/home/cyril/Coding/GBA/ham/include/hel2.h" 2

# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/malloc.h" 1 3
# 10 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/malloc.h" 3
# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/lib/gcc-lib/arm-thumb-elf/3.2.2/include/stddef.h" 1 3 4
# 11 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/malloc.h" 2 3


# 1 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/machine/malloc.h" 1 3
# 14 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/malloc.h" 2 3
# 22 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/malloc.h" 3
struct mallinfo {
  int arena;
  int ordblks;
  int smblks;
  int hblks;
  int hblkhd;
  int usmblks;
  int fsmblks;
  int uordblks;
  int fordblks;
  int keepcost;
};



extern void * malloc (size_t);




extern void * _malloc_r (struct _reent *, size_t);


extern void free (void *);




extern void _free_r (struct _reent *, void *);


extern void * realloc (void *, size_t);




extern void * _realloc_r (struct _reent *, void *, size_t);


extern void * calloc (size_t, size_t);




extern void * _calloc_r (struct _reent *, size_t, size_t);


extern void * memalign (size_t, size_t);




extern void * _memalign_r (struct _reent *, size_t, size_t);


extern struct mallinfo mallinfo (void);




extern struct mallinfo _mallinfo_r (struct _reent *);


extern void malloc_stats (void);




extern void _malloc_stats_r (struct _reent *);


extern int mallopt (int, int);




extern int _mallopt_r (struct _reent *, int, int);


extern size_t malloc_usable_size (void *);




extern size_t _malloc_usable_size_r (struct _reent *, void *);





extern void * valloc (size_t);




extern void * _valloc_r (struct _reent *, size_t);


extern void * pvalloc (size_t);




extern void * _pvalloc_r (struct _reent *, size_t);


extern int malloc_trim (size_t);




extern int _malloc_trim_r (struct _reent *, size_t);




extern void mstats (char *);




extern void _mstats_r (struct _reent *, char *);
# 162 "/home/cyril/Coding/GBA/ham/gcc-arm/arm-thumb-elf/include/malloc.h" 3
extern void cfree (void *);
# 47 "/home/cyril/Coding/GBA/ham/include/hel2.h" 2
# 195 "/home/cyril/Coding/GBA/ham/include/hel2.h"
typedef struct _TPoint8
{
        s8 X;
        s8 Y;
}TPoint8, *PPoint8;

typedef struct _TPointU8
{
        u8 X;
        u8 Y;
}TPointU8, *PPointU8;

typedef struct _TPoint16
{
        s16 X;
        s16 Y;
}TPoint16, *PPoint16;

typedef struct _TPointU16
{
        u16 X;
        u16 Y;
}TPointU16, *PPointU16;

typedef struct _TPoint32
{
        s32 X;
        s32 Y;
}TPoint32, *PPoint32;

typedef struct _TPointU32
{
        u32 X;
        u32 Y;
}TPointU32, *PPointU32;

typedef struct _TPointSfp16
{
        sfp16 X;
        sfp16 Y;
}TPointSfp16, *PPointSfp16;

typedef struct _TPointSfp32
{
        sfp32 X;
        sfp32 Y;
}TPointSfp32, *PPointSfp32;


typedef struct _TRect8
{
        s8 Left;
        s8 Top;
        s8 Right;
        s8 Bottom;
}TRect8, *PRect8;

typedef struct _TRect16
{
        s16 Left;
        s16 Top;
        s16 Right;
        s16 Bottom;
}TRect16, *PRect16;

typedef struct _TRect32
{
        s32 Left;
        s32 Top;
        s32 Right;
        s32 Bottom;
}TRect32, *PRect32;

typedef struct _TRectSfp16
{
        sfp16 Left;
        sfp16 Top;
        sfp16 Right;
        sfp16 Bottom;
}TRectSfp16, *PRectSfp16;

typedef struct _TRectSfp32
{
        sfp32 Left;
        sfp32 Top;
        sfp32 Right;
        sfp32 Bottom;
}TRectSfp32, *PRectSfp32;


typedef u8 THandle;
# 851 "/home/cyril/Coding/GBA/ham/include/hel2.h"
struct _TMapInfo;
struct _TMapDrawInfo;

typedef void (*PMapDrawFunc)(struct _TMapInfo *pMapInfo, struct _TMapDrawInfo *pMapColumnDrawInfo);




typedef struct _TMapDrawInfo
{
        void *pSourceCurrentDataAddr;
        u32 TargetColumn;
        u32 TargetRow;
        u32 TargetScreenBlockBase;
        u32 TargetCharacterBlockBase;
        u32 Quantity;
        u32 Flags;
        TPointU32 Size;
}TMapDrawInfo, *PMapDrawInfo;
# 879 "/home/cyril/Coding/GBA/ham/include/hel2.h"
typedef struct _TMapBoundsInfo
{
        sfp32 Left;
        sfp32 Top;
        sfp32 Right;
        sfp32 Bottom;
        u32 Flags;
}TMapBoundsInfo;
typedef TMapBoundsInfo* PMapBoundsInfo;
# 897 "/home/cyril/Coding/GBA/ham/include/hel2.h"
typedef struct _TMapSizeInfo
{
        u32 X;
        u32 Y;
        u32 Flags;





} TMapSizeInfo;
typedef TMapSizeInfo* PMapSizeInfo;




typedef struct _TMapInfo
{
        u32 BgNo;
        TMapSizeInfo Size;
        void *pData;
        u32 DataTypeSize;
        TPointSfp32 Position;
        u32 Flags;
        PMapDrawFunc pColumnDrawer;
        PMapDrawFunc pRowDrawer;
        TPointU32 UpdateQuantity;
        TMapBoundsInfo Bounds;
}TMapInfo;
typedef TMapInfo* PMapInfo;
# 936 "/home/cyril/Coding/GBA/ham/include/hel2.h"
typedef struct _TMapCreateIndirectDesc
{
        u8 BgNo;
        TMapSizeInfo Size;
        const void* pData;
        u8 DataTypeSize;
        TPointSfp32 Position;
        u32 Flags;
        PMapDrawFunc pColumnDrawer;
        PMapDrawFunc pRowDrawer;
        TMapBoundsInfo Bounds;
} TMapCreateIndirectDesc;
typedef TMapCreateIndirectDesc* PMapCreateIndirectDesc;



extern void hel_MapInit(void *pBuffer);
extern void hel_MapQuit(void);
extern void hel_MapCreate(u32 BgNo, u32 Width, u32 Height, const void *pData, u32 DataTypeSize, u32 Flags);
extern void hel_MapCreateIndirect(const TMapCreateIndirectDesc* pDesc);
extern void hel_MapDelete(u32 BgNo);
extern void hel_MapSetPosition(u32 BgNo, sfp32 X, sfp32 Y);
extern void hel_MapGetPosition(u32 BgNo, sfp32 *pX, sfp32 *pY);
extern void hel_MapSetFlags(u32 BgNo, u32 Flags);
extern u32 hel_MapGetFlags(u32 BgNo);
extern void hel_MapRedraw(u32 BgNo);
extern u32 hel_MapScroll(u32 BgNo, sfp32 DeltaX, sfp32 DeltaY);
extern void hel_MapTransmit(void);
extern void hel_MapJumpTo(u32 BgNo, u32 JumpToFlag);
extern void hel_MapSetBounds(u32 BgNo, sfp32 Left, sfp32 Top, sfp32 Right, sfp32 Bottom, u32 Flags);
extern const void *hel_MapGetTilePtrAt(u32 BgNo, sfp32 X, sfp32 Y);
extern u32 hel_MapExists(u32 BgNo);
extern void hel_MapConvertPositionToTiles(u32 BgNo, sfp32 X, sfp32 Y, int *pOutX, int *pOutY);
# 991 "/home/cyril/Coding/GBA/ham/include/hel2.h"
typedef struct _TTileInfo
{
        u8 *pTileData;
        u32 NumTilesRom;
        u16 *pRomToRam;
        u32 NumTilesRam;
        u16 *pRamToRom;
        u16 *pRefCount;
        u16 *pTileSlot;
        u32 SlotCounter;
        tile_info *ti;
        u32 RefCount;
        u32 CbbAddr;
        u32 TileSizeShiftFactor;
        u32 TileSizeInBytes;
        u32 TileSizeInHalfWords;
        u32 TileSizeInWords;
}TTileInfo, *PTileInfo;

typedef struct _TTileSystemInfo
{
        u32 BgNo;
        u32 PalNo;
        TTileInfo *pTileInfo;
        u32 _pad;
}TTileSystemInfo, *PTileSystemInfo;
# 1054 "/home/cyril/Coding/GBA/ham/include/hel2.h"
extern void hel_TileInit(void *pBuffer);
extern void hel_TileQuit(void);
extern void hel_TileCreate(u32 BgNo, const u8 *pTileData, u16 NumTilesRom, u16 *pBufferA, u16 NumTilesRam, u16 *pBufferB, u8 ColMode, u8 PalNo, u8 CbbOnlyMode);
extern void hel_TileDelete(u32 BgNo);
extern void hel_TileShare(u32 TargetBgNo, u32 SourceBgNo, u8 PalNo);
extern void hel_TileReloadGraphic(u32 BgNo, u32 RomTileNo, const u8* pSource);
extern void hel_TilePreloadGraphic(u32 BgNo, u32 RomTileNo);
extern void hel_TileReleaseGraphic(u32 BgNo, u32 RomTileNo);



extern TTileInfo* __hel_TileInfo;
extern TTileSystemInfo* __hel_TileSystemInfo;


extern void __attribute__ ((section (".iwram"), long_call)) __hel_TileFreeMapTileImplementation(TTileInfo *pTileInfo, u16 *pRamTileNo);


extern void __attribute__ ((section (".iwram"), long_call)) __hel_TileAllocMapTileImplementation(TTileSystemInfo* pTileSystem, u16 *pDest, const void *pSource);
# 1085 "/home/cyril/Coding/GBA/ham/include/hel2.h"
typedef void (*PPrintCharFunc)(u32 BgNo, u32 X, u32 Y, u32 Character);

typedef struct _TBgTextInfo
{
        u8 CharW;
        u8 CharH;
        const void *pMap;
        const void *pData;
        u32 Flags;
        PPrintCharFunc pPrintCharFunc;
}TBgTextInfo, *PBgTextInfo;


extern void hel_BgTextInit(void *pBuffer);
extern void hel_BgTextQuit(void);
extern void hel_BgTextCreate(u32 BgNo, u32 CharW, u32 CharH, const void *pMap, const char *pszCharOrder, void *pCharLUT, u32 Flags);
extern void hel_BgTextDelete(u32 BgNo);
extern void hel_BgTextPrint(u32 BgNo, u32 X, u32 Y, u32 Flags, const char *pszString);
extern void hel_BgTextPrintF(u32 BgNo, u32 X, u32 Y, u32 Flags, const char *pszString, ...);
# 1130 "/home/cyril/Coding/GBA/ham/include/hel2.h"
typedef struct __attribute__ ((packed)) _TPadButtons
{
        union
        {
                struct
                {
                        u8 A:1;
                        u8 B:1;
                        u8 Select:1;
                        u8 Start:1;
                        u8 Right:1;
                        u8 Left:1;
                        u8 Up:1;
                        u8 Down:1;
                        u8 R:1;
                        u8 L:1;
                };

                u16 States;
        };

        u8 Data[10*4];
}TPadButtons, *PPadButtons;

typedef struct _TPad
{
   TPadButtons Pressed;
   TPadButtons Held;
   u8 Mode;
}TPad, *PPad;
# 1171 "/home/cyril/Coding/GBA/ham/include/hel2.h"
extern void hel_PadInit(void);
extern void hel_PadQuit(void);
extern void hel_PadCapture(void);
extern void hel_PadSetMode(u32 Mode);
extern void hel_PadSetRepeatDelay(u32 Buttons, u8 Value);
extern void hel_PadSetRepeatRate(u32 Buttons, u8 Value);
extern u32 hel_PadGetTicks(u32 Button);



extern TPad __hel_Pad;
# 1302 "/home/cyril/Coding/GBA/ham/include/hel2.h"
extern void hel_PalInvert(void *pPaletteMemory, u32 Count);
extern void hel_PalBlend(u16 *pTarget, const u16 *pPaletteA, const u16 *pPaletteB, u32 Step, u32 Count);
extern void hel_PalFade(void *pPaletteMemory, const void *pSource, u32 Count, u32 Color, u32 Step);
# 1511 "/home/cyril/Coding/GBA/ham/include/hel2.h"
typedef struct _TObjInfo
{
        u16 Attr[3];
        THandle Next;
        THandle Prev;
        u32 Flags;
        const void* pSrc;
} TObjInfo, *PObjInfo;
# 1782 "/home/cyril/Coding/GBA/ham/include/hel2.h"
extern void hel_ObjInit(void *pBuffer);
extern void hel_ObjQuit(void);
extern void hel_ObjSetVisibleAll(u32 Show);
extern inline void hel_ObjSetMosaicSize(u32 HSize, u32 VSize);
extern void hel_ObjSetRotScale(THandle Handle, u32 Value);
extern void hel_ObjSetDblSize(THandle Handle, u32 Value);
extern void hel_ObjSetBefore(THandle Handle, THandle TargetHandle);
extern void hel_ObjSetBehind(THandle Handle, THandle TargetHandle);
extern void hel_ObjBackup(void *pDest, u32 Flags);
extern void hel_ObjRestore(const void *pSource, u32 Flags);


extern void hel_ObjTransmit(void);


extern void hel_ObjClearOAM(void);


extern THandle __attribute__ ((section (".iwram"), long_call)) hel_ObjCreateEx(const void *pSrc, u32 Attr0, u32 Attr1, u32 Attr2);
extern THandle __attribute__ ((section (".iwram"), long_call)) hel_ObjClone(THandle Handle, s32 X, s32 Y);
extern void __attribute__ ((section (".iwram"), long_call)) hel_ObjDelete(THandle Handle);



extern u32 __hel_ObjFirst;
extern u32 __hel_ObjLast;
extern u32 __hel_ObjCount;
extern TObjInfo *__hel_ObjInfo;




extern const u32 HEL_OBJ_SHAPESIZE_TO_WIDTH[4][4];
extern const u32 HEL_OBJ_SHAPESIZE_TO_HEIGHT[4][4];
extern const u32 HEL_OBJ_SHAPESIZE_TO_HALFWORD[2][4][4];
# 1826 "/home/cyril/Coding/GBA/ham/include/hel2.h"
typedef struct __attribute__ ((packed)) _TObjRotScaleInfo
{
        s16 ScaleX;
        s16 ScaleY;
        u16 Angle;
} __attribute__ ((packed)) TObjRotScaleInfo, *PObjRotScaleInfo;

extern void hel_ObjRotScaleInit(void *pBuffer);
extern void hel_ObjRotScaleQuit(void);
extern void hel_ObjRotScaleBackup(void *pDest, u32 Flags);
extern void hel_ObjRotScaleRestore(const void *pSource, u32 Flags);
extern THandle hel_ObjRotScaleCreate(u32 Angle, s32 ScaleX, s32 ScaleY);
extern THandle hel_ObjRotScaleClone(THandle Handle);
extern void hel_ObjRotScaleDelete(THandle Handle);
extern void hel_ObjRotScaleUpdate(THandle Handle, u32 Angle, s32 ScaleX, s32 ScaleY);
extern void hel_ObjRotScaleTransmit(void);
extern inline u32 hel_ObjRotScaleGetFreeSlots(void);
extern u32 hel_ObjRotScaleExists(THandle Handle);
# 1863 "/home/cyril/Coding/GBA/ham/include/hel2.h"
extern void hel_BgSetMosaic(u32 BgNo, u32 Value);
extern void hel_BgSetMosaicSize(u32 HSize, u32 VSize);
extern void hel_BgSetPrio(u32 BgNo, u32 Prio);
# 1893 "/home/cyril/Coding/GBA/ham/include/hel2.h"
extern void hel_DmaCopy16(void *pDest, const void *pSrc, u32 SizeIn16BitWords);
extern void hel_DmaCopy32(void *pDest, const void *pSrc, u32 SizeIn32BitWords);
extern void hel_DmaSet16(void *pDest, volatile u16 SrcValue, u32 SizeIn16BitWords);
extern void hel_DmaCopy16VBL(void *pDest, const void *pSrc, u32 SizeIn16BitWords);
extern void hel_DmaSet8(void *pDest, u8 SrcValue, u32 SizeInBytes);
extern void hel_DmaSet32(void *pDest, volatile u32 SrcValue, u32 SizeIn32BitWords);
# 2123 "/home/cyril/Coding/GBA/ham/include/hel2.h"
extern void hel_SplashInit(void *pBuffer);
extern void hel_SplashQuit();
extern void hel_Splash(const void *pBitmap, const u16 *pPalette, u16 InBlendColor, u16 OutBlendColor, u32 BlendDelay, u32 DisplayDelay, u32 ContinueDelay, u32 CompressionType, u32 Flags);
# 2136 "/home/cyril/Coding/GBA/ham/include/hel2.h"
typedef void (*PInterruptProc)(void);
# 2146 "/home/cyril/Coding/GBA/ham/include/hel2.h"
extern void hel_IntrStartHandler(u32 InterruptType, void *pInterruptHandler);
extern void hel_IntrStopHandler(u32 InterruptType);
extern void hel_IntrUpdateHandler(u32 InterruptType, void *pInterruptHandler);
extern void hel_IntrStopAll(void);
extern u32 hel_IntrIsEnabled(u32 InterruptType);
extern u32 hel_IntrGetType(void *pInterruptProc);
# 2179 "/home/cyril/Coding/GBA/ham/include/hel2.h"
extern void hel_BmpClear(u16 Color);
extern void hel_BmpLoad(const void *pSrc);
extern void hel_BmpLoadUnComp(const void *pSrc, u32 CompressionType);
# 2210 "/home/cyril/Coding/GBA/ham/include/hel2.h"
typedef struct _TDebugAssertInfo
{
        const char *pExpression;
        const char *pFilename;
        const char *pFunctionName;
        u32 LineNo;
        const char *pMessage;
        u32 nCallStack;
        const char **ppCallStack;
}TDebugAssertInfo, *PDebugAssertInfo;

typedef void (*PDebugAssertFunc)(const TDebugAssertInfo *pInfo);
typedef int (*PDebugMessageFunc)(const char *pText);
# 2407 "/home/cyril/Coding/GBA/ham/include/hel2.h"
extern void hel_SysSetPrefetch(u32 Value);
extern void hel_SysSetWaitState0(u32 FirstAccess, u32 SecondAccess);
extern void hel_SysSetWaitState1(u32 FirstAccess, u32 SecondAccess);
extern void hel_SysSetWaitState2(u32 FirstAccess, u32 SecondAccess);
# 2433 "/home/cyril/Coding/GBA/ham/include/hel2.h"
typedef struct _TWinInfo
{
        u16 WinH[2];
        u16 WinV[2];
        u16 WinIn;
        u16 WinOut;
}TWinInfo, *PWinInfo;
# 2472 "/home/cyril/Coding/GBA/ham/include/hel2.h"
extern void hel_WinInit(void);
extern void hel_WinQuit(void);
extern void hel_WinCreateEx(u8 WinNo, u8 Left, u8 Top, u8 Right, u8 Bottom, u8 InsideFlags, u8 OutsideFlags, u8 SkipOutsideFlags);
extern inline void hel_WinTransmit(void);


extern TWinInfo __hel_WinInfo;
# 2498 "/home/cyril/Coding/GBA/ham/include/hel2.h"
typedef struct __attribute__ ((packed)) _TEffectInfo
{
        u16 Control;
        u16 Alpha;
        u16 Brightness;
} TEffectInfo, *PEffectInfo;
# 2529 "/home/cyril/Coding/GBA/ham/include/hel2.h"
extern void hel_FxInit(void);
extern void hel_FxQuit(void);



extern TEffectInfo __hel_EffectInfo;
# 2550 "/home/cyril/Coding/GBA/ham/include/hel2.h"
typedef void (*PDecompressFunc)(void *pSrc, void *pDst);
# 2578 "/home/cyril/Coding/GBA/ham/include/hel2.h"
extern s32 __attribute__ ((noinline)) __attribute__ ((no_instrument_function)) hel_SwiMod(s32 Number, s32 Denom);
extern s32 __attribute__ ((noinline)) __attribute__ ((no_instrument_function)) hel_SwiDiv(s32 Number, s32 Denom);
extern s32 __attribute__ ((noinline)) __attribute__ ((no_instrument_function)) hel_SwiDivSafe(s32 Number, s32 Denom);
extern void __attribute__ ((noinline)) __attribute__ ((no_instrument_function)) hel_SwiVBlankIntrWait(void);
extern void __attribute__ ((noinline)) __attribute__ ((no_instrument_function)) hel_SwiHalt(void);
extern void __attribute__ ((noinline)) __attribute__ ((no_instrument_function)) hel_SwiSoftReset(u32 ReturnAddr);






extern const PDecompressFunc __helSwiDecompressJumpTable[];
extern void __attribute__ ((noinline)) __hel_SwiLZ77UnCompVramImplementation(void *pSrc, void *pDst);
extern void __attribute__ ((noinline)) __hel_SwiLZ77UnCompWramImplementation(void *pSrc, void *pDst);
extern void __attribute__ ((noinline)) __hel_RLUnCompVramImplementation(void *pSrc, void *pDst);
extern void __attribute__ ((noinline)) __hel_RLUnCompWramImplementation(void *pSrc, void *pDst);
extern void __attribute__ ((noinline)) __attribute__ ((no_instrument_function)) __hel_SwiCpuFastCopyImplementation(const void* pSrc, void *pDst, u32 LengthInWords);
# 2605 "/home/cyril/Coding/GBA/ham/include/hel2.h"
extern void hel_MathExtractDigits(u32 Value, u8 *pOut, u32 nDigits);
# 18 "src/sprites/cursors.c" 2


# 1 "src/soundApi/soundApi.h" 1
# 32 "src/soundApi/soundApi.h"
# 1 "src/soundApi/register.h" 1
# 33 "src/soundApi/soundApi.h" 2
# 1 "src/soundApi/gbfs.h" 1
# 49 "src/soundApi/gbfs.h"
typedef struct GBFS_FILE
{
  char magic[16];
  u32 total_len;
  u16 dir_off;
  u16 dir_nmemb;
  char reserved[8];
} GBFS_FILE;

typedef struct GBFS_ENTRY
{
  char name[24];
  u32 len;
  u32 data_offset;
} GBFS_ENTRY;


const GBFS_FILE *find_first_gbfs_file(const void *start);
const void *skip_gbfs_file(const GBFS_FILE *file);
const void *gbfs_get_obj(const GBFS_FILE *file,
                         const char *name,
                         u32 *len);
const void *gbfs_get_nth_obj(const GBFS_FILE *file,
                             size_t n,
                             char *name,
                             u32 *len);
void *gbfs_copy_obj(void *dst,
                    const GBFS_FILE *file,
                    const char *name);
size_t gbfs_count_objs(const GBFS_FILE *file);
# 34 "src/soundApi/soundApi.h" 2

typedef const GBFS_FILE kit;




void snd_init_soundApi();




void snd_init_kits();
# 64 "src/soundApi/soundApi.h"
void snd_playSoundOnChannel1(
        u16 sweeptime, u16 sweepdir, u16 sweepshifts, u16 volume,
        u16 envdir, u16 envsteptime, u16 waveduty, u16 soundlength,
        u16 loopmode, u8 output, u8 sfreq, u8 transpose);
# 81 "src/soundApi/soundApi.h"
void snd_simple_playSoundOnChannel1(u8 sweep, u16 envelope, u8 mode,
        u8 length, u16 noteFreq, u8 transpose);
# 97 "src/soundApi/soundApi.h"
void snd_playSoundOnChannel2(u16 volume,
        u16 envdir, u16 envsteptime, u16 waveduty, u16 soundlength,
        u16 loopmode, u8 output, u8 sfreq, u8 transpose);
# 110 "src/soundApi/soundApi.h"
void snd_simple_playSoundOnChannel2(u16 envelope,
        u8 mode, u8 length, u8 noteFreq, u8 transpose);
# 126 "src/soundApi/soundApi.h"
void snd_playSoundOnChannel3(u16 volume, u16 soundLength, u16 loopmode, u16 voice,
        u16 bank, u16 bankMode, u8 output, u8 freq, u8 transpose);




void snd_simple_playSoundOnChannel3();
# 148 "src/soundApi/soundApi.h"
void snd_playSoundOnChannel4(u16 volume, u16 envdir, u16 envsteptime, u16 soundlength,
        u16 loopmode, u8 output, u16 shiftFreq, u16 stepping, u8 freqRatio, u8 transpose);




void snd_simple_playSoundOnChannel4(u16 envelope, u8 mode, u8 length);




void snd_stopAllSounds();
# 169 "src/soundApi/soundApi.h"
void snd_tryToApplyEffect(u8 channelId, u8 effectNumber, u8 effectValue);






kit* snd_loadKit(u8 numKit);







const u8 snd_countAvailableKits();






u8 snd_countSamplesInKit(kit* dat);







void snd_playSampleOnChannelA(kit* dat, u8 sampleNumber);
void snd_playSampleOnChannelAById(u8 kitId, u8 sampleNumber);
# 215 "src/soundApi/soundApi.h"
void snd_playChannelASample(u8 kitId, u8 sampleNumber, u8 volume, u8 speed, u8 looping, u8 timedMode, u8 length, u8 offset, u8 output);
# 225 "src/soundApi/soundApi.h"
void snd_playOscillatorA (u8 shape, u8 freqN, u8 loopmode, u8 soundlength);
# 235 "src/soundApi/soundApi.h"
void snd_playOscillatorB (u8 shape, u8 freqN, u8 loopmode, u8 soundlength);







void snd_playSampleOnChannelB(kit* dat, u8 sampleNumber);
void snd_playSampleOnChannelBById(u8 kitId, u8 sampleNumber);
# 259 "src/soundApi/soundApi.h"
void snd_playChannelBSample(u8 kitId, u8 sampleNumber, u8 volume, u8 speed, u8 looping, u8 timedMode, u8 length, u8 offset, u8 output);





char* snd_getKitNameById(u8 kitId);






char* snd_getSampleNameById(u8 kitId, u8 sampleId);






u8 snd_countSamplesInKitById(u8 kitId);

void snd_effect_kill(u8 channelId, u8 value);
# 21 "src/sprites/cursors.c" 2
# 1 "src/headers/fat.h" 1
# 63 "src/headers/fat.h"
u8 FAT_currentScreen = 3;


u8 isHelpActivated = 0;



void FAT_initSpritePalette();
void FAT_initScreenPalette();
void FAT_switchToScreen(u8 screenId, u8 fromId);
void FAT_showHelp(u8 screenId);
void FAT_reinitScreen();
void FAT_forceClearTextLayer();
void FAT_waitVSync();
void FAT_blockCPU(u16 time);

void VBLInterruptHandler(void) {
    hel_ObjTransmit();

    do { *(volatile u16 *)(0x04000000 + 0x202) |= (1 << (0)); *((volatile u16*)0x3fffff8) |= (1 << (0)); } while(0);
}

# 1 "src/gfx/ResourceData.h" 1
# 774 "src/gfx/ResourceData.h"
extern const unsigned char __ResourceData__[];
# 86 "src/headers/fat.h" 2

# 1 "src/headers/data.h" 1
# 199 "src/headers/data.h"
const char* noteName[12] = {"C ", "C#", "D ", "D#", "E ", "F ", "F#", "G ", "G#", "A ", "A#", "B "};



const char* noteEffectName[5] = {"HO", "KL", "OU", "SW", "VO"};




const u8 noteEffectNum[5] = {0, 1, 2, 3, 4};



const char* blockEffectName[1] = {"K "};
# 223 "src/headers/data.h"
void FAT_data_initInstrumentIfNeeded(u8 instId, u8 channel);
u8 FAT_data_smartAllocateSequence(u8 channelId, u8 line);
u8 FAT_data_smartAllocateBlock(u8 sequence, u8 blockLine);







typedef struct EFFECT {
    u8 name;


    u8 value;
} effect;




effect __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) FAT_data_lastEffectWritten;







typedef struct TABLE {
    effect effects[16];
} table;





typedef struct NOTE {
    u8 note;




    u8 freq;
    u8 instrument;
    effect effect;
} note;




note __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) FAT_data_lastNoteWritten;



note __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) FAT_data_simulator;



note __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) FAT_data_noteClipboard;





typedef struct COMPOSER {
    note notes[8];
    u8 channels[8];
    u8 transpose;
    u8 keyRepeat;
} composer;





typedef struct BLOCK {
    note notes[16];
    effect effect;
} block;



u8 __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) FAT_data_lastBlockWritten;



u8 __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) FAT_data_blockClipboard;





typedef struct SEQUENCE {
    u8 blocks[16];
    u8 transpose[16];





} sequence;



u8 __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) FAT_data_lastSequenceWritten;



u8 __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) FAT_data_sequenceClipboard;





typedef struct CHANNEL {
    u8 sequences[0x40];
} channel;
# 348 "src/headers/data.h"
typedef struct VOICE {
    unsigned long value[8];
} voice;






typedef struct INSTRUMENT {
    u8 type;
    u8 sweep;



    u8 envelope;





    u8 wavedutyOrPolynomialStep;

    u8 soundlength;
    u8 loopmode;







    u8 voiceAndBank;
# 389 "src/headers/data.h"
    u8 volumeRatio;
    u8 output;

    u8 table;

    u8 kitNumber;
    u8 offset;




    u8 speedOrLooping;

    u8 voice;
} instrument;





typedef struct LIVE {
    u8 liveMode;
    u8 volume[6];
    u8 transpose[6];
} livedata;







typedef struct FAT {
    char songName[9];
    u8 nbWork;
    u8 tempo;
    u8 transpose;
    u8 keyRepeat;
    u8 previewEnable;
    u8 greedPlay;
    u8 bufferChangeInLive;
    channel channels[6];
    sequence allSequences [64];
    block allBlocks [0x70];
    instrument allInstruments[0x3f];
    composer composer;
    voice voices[16];
    table tables[0xF];
    livedata liveData;
} tracker;





typedef struct PLAYERBUFFER {
    note* note;
    u8 transpose;
    u8 haveToPlay;
    u8 volume;
    u8 sweep;
    u8 output;
} bufferPlayer;







tracker __attribute__ ((aligned(8))) __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) FAT_tracker;
# 468 "src/headers/data.h"
tracker __attribute__ ((aligned(8))) __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) FAT_compressed_tracker;




u8 __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) FAT_nextAvailableSequenceId = 0;



u8 __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) FAT_nextAvailableBlockId = 0;



u8 __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) FAT_nextAvailableInstrumentId = 0;



u8 __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) FAT_lastUsedInstrumentId = 0;


void FAT_player_playNote(note* note, u8 channel, u8 forceVolume);




u8 FAT_isCurrentlySimulating = 0;




void FAT_data_initData() {

    memset(&FAT_tracker, 0xff, sizeof (tracker));

    FAT_tracker.tempo = 128;
    FAT_tracker.transpose = 0;
    FAT_tracker.keyRepeat = 10;
    FAT_tracker.greedPlay = 0;
    FAT_tracker.nbWork = 0;
    FAT_tracker.bufferChangeInLive = 1;
    strcpy(FAT_tracker.songName, "FATSONG!\0");


    FAT_tracker.composer.transpose = 0;
    FAT_tracker.composer.keyRepeat = 0;


    FAT_data_lastNoteWritten.freq = 0;
    FAT_data_lastNoteWritten.instrument = 0;
    FAT_data_lastNoteWritten.note = 0x03;
    FAT_data_lastNoteWritten.effect.name = 0xff;
    FAT_data_simulator.freq = 0;
    FAT_data_simulator.instrument = 0;
    FAT_data_simulator.note = 0x03;
    FAT_data_simulator.effect.name = 0xff;


    FAT_data_lastBlockWritten = 0;
    FAT_data_lastSequenceWritten = 0;

    FAT_data_sequenceClipboard = 0xff;
    FAT_data_blockClipboard = 0xff;
    memset(&FAT_data_noteClipboard, 0xff, sizeof (note));
    memset(&FAT_data_lastEffectWritten, 0xff, sizeof (effect));

    memset(&FAT_tracker.liveData.volume, 0xff, sizeof (u8)*6);
    memset(&FAT_tracker.liveData.transpose, 0, sizeof (u8)*6);

    u8 i;
    for (i = 0; i < 64; i++){
        memset(&(FAT_tracker.allSequences[i].transpose), 0, sizeof (u8)*16);
    }

}






u8 FAT_data_isPreviewEnabled() {
    return FAT_tracker.previewEnable != 0;
}
# 560 "src/headers/data.h"
void FAT_data_cutSequence(u8 channelId, u8 line) {
    FAT_data_sequenceClipboard = FAT_tracker.channels[channelId].sequences[line];
    FAT_tracker.channels[channelId].sequences[line] = 0xff;
}







void FAT_data_pasteSequence(u8 channelId, u8 line) {
    FAT_tracker.channels[channelId].sequences[line] = FAT_data_sequenceClipboard;
}
# 584 "src/headers/data.h"
void FAT_data_cloneSequence(u8 channelId, u8 line) {
    u8 seqIdTemp = FAT_tracker.channels[channelId].sequences[line];
    if (FAT_data_smartAllocateSequence(channelId, line) && seqIdTemp != 0xff) {

        memcpy(& (FAT_tracker.allSequences[FAT_tracker.channels[channelId].sequences[line]]),
                & (FAT_tracker.allSequences[seqIdTemp]), sizeof (sequence));
    }
}
# 601 "src/headers/data.h"
void FAT_data_pasteSequenceWithNewNumber(u8 channelId, u8 line) {
    if (FAT_data_smartAllocateSequence(channelId, line) && FAT_data_sequenceClipboard != 0xff) {

        memcpy(& (FAT_tracker.allSequences[FAT_tracker.channels[channelId].sequences[line]]),
                & (FAT_tracker.allSequences[FAT_data_sequenceClipboard]), sizeof (sequence));
    }
}
# 618 "src/headers/data.h"
void FAT_data_cutBlock(u8 sequence, u8 blockLine) {
    FAT_data_blockClipboard = FAT_tracker.allSequences[sequence].blocks[blockLine];
    FAT_tracker.allSequences[sequence].blocks[blockLine] = 0xff;
}







void FAT_data_pasteBlock(u8 sequence, u8 blockLine) {
    FAT_tracker.allSequences[sequence].blocks[blockLine] = FAT_data_blockClipboard;
}
# 642 "src/headers/data.h"
void FAT_data_cloneBlock(u8 sequence, u8 blockLine) {
    u8 blockIdTemp = FAT_tracker.allSequences[sequence].blocks[blockLine];
    if (FAT_data_smartAllocateBlock(sequence, blockLine) && blockIdTemp != 0xff) {

        memcpy(& (FAT_tracker.allBlocks[FAT_tracker.allSequences[sequence].blocks[blockLine]]),
                & (FAT_tracker.allBlocks[blockIdTemp]), sizeof (block));
    }
}
# 659 "src/headers/data.h"
void FAT_data_pasteBlockWithNewNumber(u8 sequence, u8 blockLine) {
    if (FAT_data_smartAllocateBlock(sequence, blockLine) && FAT_data_blockClipboard != 0xff) {

        memcpy(& (FAT_tracker.allBlocks[FAT_tracker.allSequences[sequence].blocks[blockLine]]),
                & (FAT_tracker.allBlocks[FAT_data_blockClipboard]), sizeof (block));
    }
}







void FAT_data_removeBlockTranspose(u8 sequence, u8 blockLine) {
    FAT_tracker.allSequences[sequence].transpose[blockLine] = 0xff;
}
# 685 "src/headers/data.h"
void FAT_data_cutNote(u8 block, u8 noteLine) {
    memcpy(&FAT_data_noteClipboard, &(FAT_tracker.allBlocks[block].notes[noteLine]), sizeof (note));
    FAT_tracker.allBlocks[block].notes[noteLine].freq = 0xff;
}
# 697 "src/headers/data.h"
void FAT_data_composer_cutNote(u8 line) {
    memcpy(&FAT_data_noteClipboard, &(FAT_tracker.composer.notes[line]), sizeof (note));
    FAT_tracker.composer.notes[line].freq = 0xff;
}







void FAT_data_pasteNote(u8 block, u8 noteLine) {
    memcpy(&(FAT_tracker.allBlocks[block].notes[noteLine]), &FAT_data_noteClipboard, sizeof (note));
}






void FAT_data_composer_pasteNote(u8 line) {
    memcpy(&(FAT_tracker.composer.notes[line]), &FAT_data_noteClipboard, sizeof (note));
}
# 728 "src/headers/data.h"
u8 FAT_data_isSequenceAllocatable(u8 channelId, u8 line) {
    return FAT_tracker.channels[channelId].sequences[line] == 0xff;
}
# 739 "src/headers/data.h"
u8 FAT_data_isBlockAllocatable(u8 sequence, u8 blockLine) {
    return FAT_tracker.allSequences[sequence].blocks[blockLine] == 0xff;
}
# 750 "src/headers/data.h"
u8 FAT_data_isNoteEmpty(u8 block, u8 noteLine) {
    return FAT_tracker.allBlocks[block].notes[noteLine].freq == 0xff;
}
# 761 "src/headers/data.h"
u8 FAT_data_getSequence(u8 channelId, u8 sequenceLine) {
    return FAT_tracker.channels[channelId].sequences[sequenceLine];
}
# 772 "src/headers/data.h"
u8 FAT_data_getBlock(u8 sequence, u8 blockLine) {
    return FAT_tracker.allSequences[sequence].blocks[blockLine];
}
# 786 "src/headers/data.h"
note* FAT_data_getNote(u8 block, u8 noteLine) {
    return &FAT_tracker.allBlocks[block].notes[noteLine];
}
# 799 "src/headers/data.h"
void FAT_data_allocateSequenceToNextAvailableId(u8 channelId, u8 line) {
    if (FAT_nextAvailableSequenceId < 64) {
        FAT_tracker.channels[channelId].sequences[line] = FAT_nextAvailableSequenceId;
        FAT_nextAvailableSequenceId++;
    }
}
# 816 "src/headers/data.h"
u8 FAT_data_allocateSequence(u8 channelId, u8 line) {
    if (FAT_data_isSequenceAllocatable(channelId, line)) {
        FAT_tracker.channels[channelId].sequences[line] = FAT_data_lastSequenceWritten;
        return 1;
    }

    return 0;
}
# 834 "src/headers/data.h"
void FAT_data_allocateBlockToNextAvailableId(u8 sequence, u8 blockLine) {
    if (FAT_nextAvailableBlockId < 0x70) {
        FAT_tracker.allSequences[sequence].blocks[blockLine] = FAT_nextAvailableBlockId;
        FAT_nextAvailableBlockId++;
    }
}
# 851 "src/headers/data.h"
u8 FAT_data_allocateBlock(u8 sequence, u8 blockLine) {
    if (FAT_data_isBlockAllocatable(sequence, blockLine)) {
        FAT_tracker.allSequences[sequence].blocks[blockLine] = FAT_data_lastBlockWritten;
        return 1;
    }

    return 0;
}







u8 FAT_data_isBlockEmpty(u8 blockId) {
    u8 note = 0;
    while (note < 16) {
        if (FAT_tracker.allBlocks[blockId].notes[note].freq != 0xff) {
            return 0;
        }
        note++;
    }

    return 1;
}
# 885 "src/headers/data.h"
u8 FAT_data_block_isTransposeEmpty(u8 sequence, u8 line) {
    return FAT_tracker.allSequences[sequence].transpose[line] == 0;
}
# 896 "src/headers/data.h"
u8 FAT_data_block_getTranspose(u8 sequence, u8 line) {
    return FAT_tracker.allSequences[sequence].transpose[line];
}







void FAT_data_block_allocateTranspose(u8 sequence, u8 line) {
    if (FAT_data_block_isTransposeEmpty(sequence, line)) {
        FAT_tracker.allSequences[sequence].transpose[line] = 0;
    }
}







u8 FAT_data_isSequenceEmpty(u8 sequenceId) {
    u8 block = 0;
    while (block < 16) {
        if (FAT_tracker.allSequences[sequenceId].blocks[block] != 0xff) {
            return 0;
        }
        block++;
    }

    return 1;
}







u8 FAT_data_isInstrumentFree(u8 inst) {
    return FAT_tracker.allInstruments[inst].sweep == 0xff;
}







u8 FAT_data_getInstrumentType(u8 inst) {
    return FAT_tracker.allInstruments[inst].type;
}
# 957 "src/headers/data.h"
u8 FAT_data_smartAllocateBlock(u8 sequence, u8 blockLine) {
    u8 block = FAT_data_lastBlockWritten + 1;
    while (block < 0x70) {

        if (FAT_data_isBlockEmpty(block)) {
            FAT_tracker.allSequences[sequence].blocks[blockLine] = block;
            FAT_data_lastBlockWritten = block;
            return 1;
        }
        block++;
    }
    return 0;
}
# 978 "src/headers/data.h"
u8 FAT_data_smartAllocateSequence(u8 channelId, u8 line) {

    u8 seq = FAT_data_lastSequenceWritten + 1;
    while (seq < 64) {
        if (FAT_data_isSequenceEmpty(seq)) {
            FAT_tracker.channels[channelId].sequences[line] = seq;
            FAT_data_lastSequenceWritten = seq;
            return 1;
        }
        seq++;
    }

    return 0;
}







void FAT_data_addDefaultNote(u8 block, u8 noteLine, u8 channel) {
    FAT_data_initInstrumentIfNeeded(FAT_data_lastNoteWritten.instrument, channel);

    if (channel >= 4) {
        u8 nbAvailableSamples = snd_countSamplesInKitById(FAT_tracker.allInstruments[FAT_data_lastNoteWritten.instrument].kitNumber);
        if (FAT_data_lastNoteWritten.freq >= nbAvailableSamples) {
            FAT_data_lastNoteWritten.freq = nbAvailableSamples - 1;
        }
    }

    FAT_tracker.allBlocks[block].notes[noteLine].freq = FAT_data_lastNoteWritten.freq;
    FAT_tracker.allBlocks[block].notes[noteLine].instrument = FAT_data_lastNoteWritten.instrument;
    FAT_tracker.allBlocks[block].notes[noteLine].note = FAT_data_lastNoteWritten.note;

}
# 1023 "src/headers/data.h"
void FAT_data_initInstrumentIfNeeded(u8 instId, u8 channel) {
    if (FAT_tracker.allInstruments[instId].sweep == 0xff) {
        FAT_tracker.allInstruments[instId].sweep = 0;
        FAT_tracker.allInstruments[instId].envelope = 0x0a;
        FAT_tracker.allInstruments[instId].volumeRatio = 0x13;
        FAT_tracker.allInstruments[instId].wavedutyOrPolynomialStep = 0;
        FAT_tracker.allInstruments[instId].soundlength = 0;
        FAT_tracker.allInstruments[instId].loopmode = 0;
        FAT_tracker.allInstruments[instId].voiceAndBank = 0;
        FAT_tracker.allInstruments[instId].output = 3;
        FAT_tracker.allInstruments[instId].voice = 0xff;

        FAT_tracker.allInstruments[instId].kitNumber = 0;
        FAT_tracker.allInstruments[instId].offset = 0;
        FAT_tracker.allInstruments[instId].speedOrLooping = 0x01;

        FAT_tracker.allInstruments[instId].table = 0;

        FAT_tracker.allInstruments[instId].type = channel;
    }
}
# 1054 "src/headers/data.h"
void FAT_data_sequence_changeValue(u8 channelId, u8 line, s8 addedValue) {
    if (
            (addedValue < 0 && FAT_tracker.channels[channelId].sequences[line] > (-addedValue - 1)) ||
            (addedValue > 0 && FAT_tracker.channels[channelId].sequences[line] < 64 - addedValue)
            ) {
        FAT_tracker.channels[channelId].sequences[line] += addedValue;
        FAT_data_lastSequenceWritten = FAT_tracker.channels[channelId].sequences[line];
    }
}
# 1071 "src/headers/data.h"
void FAT_data_block_changeTransposeValue(u8 sequence, u8 line, s8 addedValue) {
    FAT_tracker.allSequences[sequence].transpose[line] += addedValue;
}
# 1084 "src/headers/data.h"
void FAT_data_block_changeValue(u8 sequence, u8 blockLine, s8 addedValue) {
    if (
            (addedValue < 0 && FAT_tracker.allSequences[sequence].blocks[blockLine] > (-addedValue - 1)) ||
            (addedValue > 0 && FAT_tracker.allSequences[sequence].blocks[blockLine] < 0x70 - addedValue)
            ) {
        FAT_tracker.allSequences[sequence].blocks[blockLine] += addedValue;
        FAT_data_lastBlockWritten = FAT_tracker.allSequences[sequence].blocks[blockLine];
    }
}







u8 FAT_data_block_isEffectEmpty(u8 sequence, u8 blockLine) {

    return 1;
}
# 1112 "src/headers/data.h"
effect* FAT_data_block_getEffect(u8 sequence, u8 line) {

    return 0;
}







void FAT_data_note_previewNote(u8 block, u8 line) {
    u8 instId = FAT_tracker.allBlocks[block].notes[line].instrument;
    FAT_player_playNote(&FAT_tracker.allBlocks[block].notes[line],
                                        FAT_tracker.allInstruments[instId].type,
                                                                        0xff);
}
# 1142 "src/headers/data.h"
void FAT_data_note_changeValue(u8 channel, u8 block, u8 noteLine, s8 addedValue) {
    u8 noteName = FAT_tracker.allBlocks[block].notes[noteLine].note >> 4;
    u8 noteOctave = FAT_tracker.allBlocks[block].notes[noteLine].note & 0x0f;

    instrument* inst = &(FAT_tracker.allInstruments[FAT_tracker.allBlocks[block].notes[noteLine].instrument]);
    if (channel >= 4) {
        if (inst->type > 5){

                if ((addedValue > 0 && FAT_tracker.allBlocks[block].notes[noteLine].freq < 72 - 1) ||
                                        (addedValue < 0 && FAT_tracker.allBlocks[block].notes[noteLine].freq > 0)) {
                                FAT_tracker.allBlocks[block].notes[noteLine].freq += addedValue;
                        }
        } else {

                        u8 nbMaxSample = snd_countSamplesInKitById(inst->kitNumber);




                        if ((addedValue > 0 && FAT_tracker.allBlocks[block].notes[noteLine].freq < nbMaxSample - 1) ||
                                        (addedValue < 0 && FAT_tracker.allBlocks[block].notes[noteLine].freq > 0)) {
                                FAT_tracker.allBlocks[block].notes[noteLine].freq += addedValue;
                        }
        }
    } else {

        if (addedValue < 0) {

            if (noteName > 0) {

                noteName += addedValue;

            } else if (noteOctave > 3) {


                noteName = 12 - 1;
                noteOctave -= 1;
            }

            if (FAT_tracker.allBlocks[block].notes[noteLine].freq > 0) {
                FAT_tracker.allBlocks[block].notes[noteLine].freq += addedValue;
            }

        } else if (addedValue > 0) {
            if (noteName < 12 - 1) {

                noteName += addedValue;

            } else if (noteOctave < 8) {


                noteName = 0;
                noteOctave += 1;
            }

            if (FAT_tracker.allBlocks[block].notes[noteLine].freq < 72) {
                FAT_tracker.allBlocks[block].notes[noteLine].freq += addedValue;
            }
        }
    }

    FAT_tracker.allBlocks[block].notes[noteLine].note = (noteName << 4) + noteOctave;

    FAT_data_lastNoteWritten.freq = FAT_tracker.allBlocks[block].notes[noteLine].freq;
    FAT_data_lastNoteWritten.note = FAT_tracker.allBlocks[block].notes[noteLine].note;

};
# 1221 "src/headers/data.h"
void FAT_data_note_changeOctave(u8 block, u8 noteLine, s8 addedValue) {
    u8 noteOctave = FAT_tracker.allBlocks[block].notes[noteLine].note & 0x0f;
    if (
            (addedValue < 0 && noteOctave > 3) ||
            (addedValue > 0 && noteOctave < 8)

            ) {
        FAT_tracker.allBlocks[block].notes[noteLine].freq += addedValue * 12;
        FAT_tracker.allBlocks[block].notes[noteLine].note += addedValue;

        FAT_data_lastNoteWritten.freq = FAT_tracker.allBlocks[block].notes[noteLine].freq;
        FAT_data_lastNoteWritten.note = FAT_tracker.allBlocks[block].notes[noteLine].note;
    }
}
# 1243 "src/headers/data.h"
void FAT_data_note_changeInstrument(u8 currentChannel, u8 block, u8 noteLine, s8 addedValue) {
    if (
            FAT_tracker.allBlocks[block].notes[noteLine].instrument != 0xff &&
            (
            (addedValue < 0 && FAT_tracker.allBlocks[block].notes[noteLine].instrument > (-addedValue - 1)) ||
            (addedValue > 0 && FAT_tracker.allBlocks[block].notes[noteLine].instrument <= 0x3f - addedValue)
            )
            ) {
        FAT_tracker.allBlocks[block].notes[noteLine].instrument += addedValue;
        FAT_data_lastNoteWritten.instrument = FAT_tracker.allBlocks[block].notes[noteLine].instrument;

        FAT_data_initInstrumentIfNeeded(FAT_tracker.allBlocks[block].notes[noteLine].instrument,
                currentChannel);
    } else if (addedValue < 0 && FAT_tracker.allBlocks[block].notes[noteLine].instrument != 0xff){
        FAT_data_note_changeInstrument (currentChannel, block, noteLine, -FAT_tracker.allBlocks[block].notes[noteLine].instrument);
    } else if (addedValue > 0 && FAT_tracker.allBlocks[block].notes[noteLine].instrument != 0xff){
        FAT_data_note_changeInstrument (currentChannel, block, noteLine, 0x3f -FAT_tracker.allBlocks[block].notes[noteLine].instrument);
    }
}






void FAT_data_note_filterEffectValue (effect* effect) {
    u8 effectName = (effect->name & 0xfe) >> 1;
    switch (effectName){
        case 1:

            break;
        case 2:

            if (effect->value > 3) {
                effect->value = 3;
                FAT_data_lastEffectWritten.value = effect->value;
            }
            break;
        case 3:

            break;
        case 4:

            if (effect->value > 0xF) {
                effect->value = 0xF;
                FAT_data_lastEffectWritten.value = effect->value;
            }
            break;
        case 0:

            break;
    }
}
# 1304 "src/headers/data.h"
void FAT_data_note_changeEffectName(u8 block, u8 line, s8 addedValue) {
    u8 effectName = (FAT_tracker.allBlocks[block].notes[line].effect.name & 0xfe) >> 1;
    if (
            (addedValue < 0 && effectName > (-addedValue - 1)) ||
            (addedValue > 0 && effectName < 5 - addedValue)

            ) {
        effectName += addedValue;
        FAT_tracker.allBlocks[block].notes[line].effect.name = (effectName << 1) | 1;
        FAT_data_lastEffectWritten.name = FAT_tracker.allBlocks[block].notes[line].effect.name;


        FAT_data_note_filterEffectValue (&(FAT_tracker.allBlocks[block].notes[line].effect));
    }
}
# 1327 "src/headers/data.h"
void FAT_data_note_changeEffectValue_limited (effect* effect, s8 addedValue, u8 limit){
    if (
            (addedValue < 0 && effect->value > (-addedValue - 1)) ||
            (addedValue > 0 && effect->value <= limit - addedValue)

            ) {
        effect->value += addedValue;
        FAT_data_lastEffectWritten.value = effect->value;
    }else if (addedValue < 0){
        FAT_data_note_changeEffectValue_limited (effect, -(effect->value), limit);
    } else if (addedValue > 0){
        FAT_data_note_changeEffectValue_limited (effect, limit - (effect->value), limit);
    }
}







void FAT_data_note_changeEffectValue_generic (effect* effect, s8 addedValue){
    FAT_data_note_changeEffectValue_limited (effect, addedValue, 0xff);
}
# 1359 "src/headers/data.h"
void FAT_data_note_changeEffectValue(u8 block, u8 line, s8 addedValue) {
    u8 effectName = (FAT_tracker.allBlocks[block].notes[line].effect.name & 0xfe) >> 1;
    switch (effectName){
        case 1:
            FAT_data_note_changeEffectValue_generic (&(FAT_tracker.allBlocks[block].notes[line].effect), addedValue);
            break;
        case 2:

            FAT_data_note_changeEffectValue_limited (&(FAT_tracker.allBlocks[block].notes[line].effect), addedValue, 3);
            break;
        case 3:
            FAT_data_note_changeEffectValue_generic (&(FAT_tracker.allBlocks[block].notes[line].effect), addedValue);
            break;
        case 4:

            FAT_data_note_changeEffectValue_limited (&(FAT_tracker.allBlocks[block].notes[line].effect), addedValue, 0xf);
            break;
        case 0:

            FAT_data_note_changeEffectValue_limited (&(FAT_tracker.allBlocks[block].notes[line].effect), addedValue, 0xf);
            break;
    }
}







void FAT_data_note_pasteEffect(u8 block, u8 line) {
    FAT_tracker.allBlocks[block].notes[line].effect.name = ((FAT_data_lastEffectWritten.name & 0xfe) >> 1) | 1;
    FAT_tracker.allBlocks[block].notes[line].effect.value = FAT_data_lastEffectWritten.value;
}







void FAT_data_note_cutEffect(u8 block, u8 line) {
    FAT_data_lastEffectWritten.name = FAT_tracker.allBlocks[block].notes[line].effect.name;
    FAT_data_lastEffectWritten.value = FAT_tracker.allBlocks[block].notes[line].effect.value;
    memset(&FAT_tracker.allBlocks[block].notes[line].effect, 0xff, sizeof (effect));
}
# 1414 "src/headers/data.h"
u8 FAT_data_note_smartChangeInstrument(u8 currentChannel, u8 block, u8 noteLine) {
    u8 inst = 0;
    while (inst < 0x3f) {
        if (FAT_data_isInstrumentFree(inst)) {
            FAT_tracker.allBlocks[block].notes[noteLine].instrument = inst;
            FAT_data_lastNoteWritten.instrument = inst;

            FAT_data_initInstrumentIfNeeded(inst,
                    currentChannel);

            return 1;
        }
        inst++;
    }

    return 0;
}
# 1439 "src/headers/data.h"
u8 FAT_data_note_isEffectEmpty(u8 block, u8 line) {
    return FAT_tracker.allBlocks[block].notes[line].effect.name == 0xff;
}
# 1450 "src/headers/data.h"
effect* FAT_data_note_getEffect(u8 block, u8 line) {
    return &(FAT_tracker.allBlocks[block].notes[line].effect);
}







void FAT_data_note_addDefaultEffect(u8 block, u8 line) {
    if (FAT_data_lastEffectWritten.name == 0xff) {
        FAT_data_lastEffectWritten.name = 1;
        FAT_data_lastEffectWritten.value = 0;
    }

    FAT_tracker.allBlocks[block].notes[line].effect.name = FAT_data_lastEffectWritten.name;
    FAT_tracker.allBlocks[block].notes[line].effect.value = FAT_data_lastEffectWritten.value;
}







void FAT_data_instrument_changeType(u8 instrumentId, u8 newType) {
    FAT_tracker.allInstruments[instrumentId].type = newType;
}






void FAT_data_instrument_changeSimulator(u8 inst, s8 addedValue) {
    FAT_data_simulator.instrument = inst;

    u8 noteName = (FAT_data_simulator.note & 0xf0) >> 4;
    u8 noteOctave = FAT_data_simulator.note & 0x0f;
    if (addedValue == 16 || addedValue == -16) {

        if (addedValue == 16) addedValue = 1;
        if (addedValue == -16) addedValue = -1;
        if (
                (addedValue < 0 && noteOctave > 3) ||
                (addedValue > 0 && noteOctave < 8)

                ) {
            FAT_data_simulator.freq += addedValue * 12;
            FAT_data_simulator.note += addedValue;
        }
    } else {

        if (
                (addedValue < 0 && noteName > 0) ||
                (addedValue > 0 && noteName < 12 - 1)

                ) {
            FAT_data_simulator.freq += addedValue;
            noteName += addedValue;
            FAT_data_simulator.note = (noteName << 4) + noteOctave;
        }
    }
}

void FAT_data_instrument_setCurrentlySimulating (u8 val){
    FAT_isCurrentlySimulating = val;
}

u8 FAT_data_instrument_isCurrentlySimulating (){
    return FAT_isCurrentlySimulating;
}






void FAT_data_instrument_playSimulator(u8 inst) {
    FAT_player_playNote(&FAT_data_simulator, FAT_tracker.allInstruments[inst].type,
            0xff);
    FAT_data_instrument_setCurrentlySimulating (1);
}







void FAT_data_instrumentPulse_changeVolume(u8 instrumentId, s8 value) {
    u8 volume = FAT_tracker.allInstruments[instrumentId].envelope & 0x0f;
    u8 steptime = (FAT_tracker.allInstruments[instrumentId].envelope & 0xE0);
    u8 dir = (FAT_tracker.allInstruments[instrumentId].envelope & 0x10);
    if (
            (value < 0 && volume > (-value - 1)) ||
            (value > 0 && volume < 16 - value)

            ) {
        volume += value;
        FAT_tracker.allInstruments[instrumentId].envelope = steptime | dir | volume;
    }
}







void FAT_data_instrumentNoise_changeVolume(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeVolume(instrumentId, value);
}







void FAT_data_instrumentWave_changeVolume(u8 instrumentId, s8 value) {
    u8 volumeRatio = FAT_tracker.allInstruments[instrumentId].volumeRatio & 0x0f;
    u8 sampleRatio = (FAT_tracker.allInstruments[instrumentId].volumeRatio & 0xf0);
    if (
            (value < 0 && volumeRatio > (-value - 1)) ||
            (value > 0 && volumeRatio < 5 - value)

            ) {
        volumeRatio += value;
        FAT_tracker.allInstruments[instrumentId].volumeRatio = sampleRatio | volumeRatio;
    }
}







void FAT_data_instrumentSample_changeKitNumber(u8 instrumentId, s8 value) {
    u8 kitNumber = FAT_tracker.allInstruments[instrumentId].kitNumber;
    u8 nbKits = snd_countAvailableKits();

    if (
            (value < 0 && kitNumber > (-value - 1)) ||
            (value > 0 && kitNumber < nbKits - value)

            ) {
        kitNumber += value;
        FAT_tracker.allInstruments[instrumentId].kitNumber = kitNumber;
    }

}







void FAT_data_instrumentSample_changeVolume(u8 instrumentId, s8 value) {
    u8 volumeRatio = (FAT_tracker.allInstruments[instrumentId].volumeRatio & 0xf0) >> 4;
    u8 waveRatio = FAT_tracker.allInstruments[instrumentId].volumeRatio & 0x0f;

    if (
            (value < 0 && volumeRatio > (-value - 1)) ||
            (value > 0 && volumeRatio < 2 - value)

            ) {
        volumeRatio += value;
        FAT_tracker.allInstruments[instrumentId].volumeRatio = (volumeRatio << 4) | waveRatio;
    }
}







void FAT_data_instrumentPulse_changeEnvelopeDirection(u8 instrumentId, s8 value) {
    u8 volume = FAT_tracker.allInstruments[instrumentId].envelope & 0x0f;
    u8 steptime = (FAT_tracker.allInstruments[instrumentId].envelope & 0xE0);
    u8 dir = (FAT_tracker.allInstruments[instrumentId].envelope & 0x10) >> 4;
    if (value < 0) {
        dir = 0;
    } else if (value > 0) {
        dir = 1;
    }
    FAT_tracker.allInstruments[instrumentId].envelope = steptime | (dir << 4) | volume;
}







void FAT_data_instrumentNoise_changeEnvelopeDirection(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeEnvelopeDirection(instrumentId, value);
}







void FAT_data_instrumentPulse_changeSteptime(u8 instrumentId, s8 value) {
    u8 volume = FAT_tracker.allInstruments[instrumentId].envelope & 0x0f;
    u8 steptime = (FAT_tracker.allInstruments[instrumentId].envelope & 0xE0) >> 5;
    u8 dir = (FAT_tracker.allInstruments[instrumentId].envelope & 0x10);
    if (
            (value < 0 && steptime > (-value - 1)) ||
            (value > 0 && steptime < 8 - value)

            ) {
        steptime += value;
        FAT_tracker.allInstruments[instrumentId].envelope = (steptime << 5) | dir | volume;
    }
}







void FAT_data_instrumentNoise_changeSteptime(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeSteptime(instrumentId, value);
}







void FAT_data_instrumentPulse_changeWaveduty(u8 instrumentId, s8 value) {
    if (
            (value < 0 && FAT_tracker.allInstruments[instrumentId].wavedutyOrPolynomialStep > (-value - 1)) ||
            (value > 0 && FAT_tracker.allInstruments[instrumentId].wavedutyOrPolynomialStep < 4 - value)

            ) {
        FAT_tracker.allInstruments[instrumentId].wavedutyOrPolynomialStep += value;
    }
}




void FAT_data_instrumentOsc_changeShape (u8 instrumentId, s8 value){
    FAT_data_instrumentPulse_changeWaveduty (instrumentId, value);
}
# 1714 "src/headers/data.h"
void FAT_data_instrumentNoise_changePolystep(u8 instrumentId, s8 value) {
    if (value < 0) {
        FAT_tracker.allInstruments[instrumentId].wavedutyOrPolynomialStep = 0;
    } else if (value > 0) {
        FAT_tracker.allInstruments[instrumentId].wavedutyOrPolynomialStep = 1;
    }
}







void FAT_data_instrumentPulse_changeOutput(u8 instrumentId, s8 value) {
    switch (value) {
        case -1:
            FAT_tracker.allInstruments[instrumentId].output = 1;
            break;
        case 1:
            FAT_tracker.allInstruments[instrumentId].output = 2;
            break;
        case -16:
            FAT_tracker.allInstruments[instrumentId].output = 0;
            break;
        case 16:
            FAT_tracker.allInstruments[instrumentId].output = 3;
            break;
    }
}







void FAT_data_instrumentNoise_changeOutput(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeOutput(instrumentId, value);
}







void FAT_data_instrumentWave_changeOutput(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeOutput(instrumentId, value);
}







void FAT_data_instrumentSample_changeOutput(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeOutput(instrumentId, value);
}







void FAT_data_instrumentPulse_changeSoundLength(u8 instrumentId, s8 value) {

    if (FAT_tracker.allInstruments[instrumentId].soundlength > 64){
        FAT_tracker.allInstruments[instrumentId].soundlength = 64 -1;

    } else if (
            (value < 0 && FAT_tracker.allInstruments[instrumentId].soundlength > (-value - 1)) ||
            (value > 0 && FAT_tracker.allInstruments[instrumentId].soundlength < 64 - value)

            ) {
        FAT_tracker.allInstruments[instrumentId].soundlength += value;
    } else if (value < 0){
        FAT_data_instrumentPulse_changeSoundLength (instrumentId, -FAT_tracker.allInstruments[instrumentId].soundlength);
    } else if (value > 0){
        FAT_data_instrumentPulse_changeSoundLength (instrumentId, 64 - FAT_tracker.allInstruments[instrumentId].soundlength-1);
    }
}







void FAT_data_instrumentNoise_changeSoundLength(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeSoundLength(instrumentId, value);
}

void FAT_data_instrumentOsc_changeSoundLength (u8 instrumentId, s8 value) {
   if (
               (value < 0 && FAT_tracker.allInstruments[instrumentId].soundlength > (-value - 1)) ||
               (value > 0 && FAT_tracker.allInstruments[instrumentId].soundlength < 255 - value)
               ) {
       FAT_tracker.allInstruments[instrumentId].soundlength += value;
   } else if (value < 0){
       FAT_tracker.allInstruments[instrumentId].soundlength = 0;
   } else if (value > 0){
       FAT_tracker.allInstruments[instrumentId].soundlength = 255;
   }
}







void FAT_data_instrumentWave_changeSoundLength(u8 instrumentId, s8 value) {
    if (
            (value < 0 && FAT_tracker.allInstruments[instrumentId].soundlength > (-value - 1)) ||
            (value > 0 && FAT_tracker.allInstruments[instrumentId].soundlength < 256 - value)

            ) {
        FAT_tracker.allInstruments[instrumentId].soundlength += value;
    } else if (value < 0){
        FAT_data_instrumentWave_changeSoundLength (instrumentId, -FAT_tracker.allInstruments[instrumentId].soundlength);
    } else if (value > 0){
        FAT_data_instrumentWave_changeSoundLength (instrumentId, 256 -FAT_tracker.allInstruments[instrumentId].soundlength-1);
    }
}







void FAT_data_instrumentSample_changeSoundLength(u8 instrumentId, s8 value) {
    if (
            (value < 0 && FAT_tracker.allInstruments[instrumentId].soundlength > (-value - 1)) ||
            (value > 0 && FAT_tracker.allInstruments[instrumentId].soundlength < 100 - value)

            ) {
        FAT_tracker.allInstruments[instrumentId].soundlength += value;
    } else if (value < 0){
        FAT_data_instrumentWave_changeSoundLength (instrumentId, -FAT_tracker.allInstruments[instrumentId].soundlength);
    } else if (value > 0){
        FAT_data_instrumentWave_changeSoundLength (instrumentId, 100-FAT_tracker.allInstruments[instrumentId].soundlength);
    }
}







void FAT_data_instrumentPulse_changeSweep(u8 instrumentId, s8 value) {
    if (
            (value < 0 && FAT_tracker.allInstruments[instrumentId].sweep > (-value - 1)) ||
            (value > 0 && FAT_tracker.allInstruments[instrumentId].sweep < 128 - value)

            ) {
        FAT_tracker.allInstruments[instrumentId].sweep += value;
    } else if (value < 0){
        FAT_data_instrumentPulse_changeSweep (instrumentId, -FAT_tracker.allInstruments[instrumentId].sweep);
    } else if (value > 0){
        FAT_data_instrumentPulse_changeSweep (instrumentId, 128 - FAT_tracker.allInstruments[instrumentId].sweep - 1);
    }
}
# 1890 "src/headers/data.h"
void FAT_data_instrumentPulse_changeLoopmode(u8 instrumentId, s8 value) {
    if (value < 0) {
        FAT_tracker.allInstruments[instrumentId].loopmode = 0;
    } else if (value > 0) {
        FAT_tracker.allInstruments[instrumentId].loopmode = 1;
    }
}
# 1906 "src/headers/data.h"
void FAT_data_instrumentWave_changeLoopmode(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeLoopmode(instrumentId, value);
}
# 1918 "src/headers/data.h"
void FAT_data_instrumentNoise_changeLoopmode(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeLoopmode(instrumentId, value);
}

void FAT_data_instrumentOsc_changeLoopmode (u8 instrumentId, s8 value) {
   FAT_data_instrumentPulse_changeLoopmode(instrumentId, value);
}







void FAT_data_instrumentSample_changeLoopmode(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeLoopmode(instrumentId, value);
}
# 1943 "src/headers/data.h"
void FAT_data_instrumentWave_changeVoice(u8 instrumentId, s8 value) {
    u8 voice = FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x1f;
    u8 bank = (FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x20);
    u8 bankMode = (FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x40);
    if (
            (value < 0 && voice > (-value - 1)) ||
            (value > 0 && voice < 0x18 - value)

            ) {
        voice += value;
        FAT_tracker.allInstruments[instrumentId].voiceAndBank = bankMode | bank | voice;
    } else if (value < 0){
        FAT_data_instrumentWave_changeVoice (instrumentId, -FAT_tracker.allInstruments[instrumentId].voiceAndBank);
    } else if (value > 0){
        FAT_data_instrumentWave_changeVoice (instrumentId, 0x18 -FAT_tracker.allInstruments[instrumentId].voiceAndBank-1);
    }
}
# 1968 "src/headers/data.h"
void FAT_data_instrumentWave_changeBank(u8 instrumentId, s8 value) {
    u8 voice = FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x1f;
    u8 bank = (FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x20) >> 5;
    u8 bankMode = (FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x40);
    if (value < 0) {
        bank = 0;
    } else if (value > 0) {
        bank = 1;
    }
    FAT_tracker.allInstruments[instrumentId].voiceAndBank = bankMode | (bank << 5) | voice;
}
# 1987 "src/headers/data.h"
void FAT_data_instrumentWave_changeBankmode(u8 instrumentId, s8 value) {
    u8 voice = FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x1f;
    u8 bank = (FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x20);
    u8 bankMode = (FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x40) >> 6;
    if (value < 0) {
        bankMode = 0;
    } else if (value > 0) {
        bankMode = 1;
    }

    FAT_tracker.allInstruments[instrumentId].voiceAndBank = (bankMode << 6) | bank | voice;
}







void FAT_data_instrumentSample_changeSpeed(u8 instrumentId, s8 value) {
    u8 speed = FAT_tracker.allInstruments[instrumentId].speedOrLooping & 0x0f;
    u8 looping = FAT_tracker.allInstruments[instrumentId].speedOrLooping & 0xf0;
    if (
            (value < 0 && speed > 1) ||
            (value > 0 && speed < 16 - value)

            ) {
        speed += value;
        FAT_tracker.allInstruments[instrumentId].speedOrLooping = looping | speed;
    }
}
# 2026 "src/headers/data.h"
void FAT_data_instrumentSample_changeLooping(u8 instrumentId, s8 value) {
    u8 speed = FAT_tracker.allInstruments[instrumentId].speedOrLooping & 0x0f;
    u8 looping = FAT_tracker.allInstruments[instrumentId].speedOrLooping >> 4;

    if (value < 0) {
        looping = 0;
    } else if (value > 0) {
        looping = 1;
    }

    FAT_tracker.allInstruments[instrumentId].speedOrLooping = (looping << 4) | speed;
}







void FAT_data_instrumentSample_changeOffset(u8 instrumentId, s8 value) {
    if (
            (value < 0 && FAT_tracker.allInstruments[instrumentId].offset > (-value - 1)) ||
            (value > 0 && FAT_tracker.allInstruments[instrumentId].offset < 100 - value)

            ) {
        FAT_tracker.allInstruments[instrumentId].offset += value;
    } else if (value < 0){
        FAT_data_instrumentSample_changeOffset (instrumentId, -FAT_tracker.allInstruments[instrumentId].offset);
    } else if (value > 0){
        FAT_data_instrumentSample_changeOffset (instrumentId, 100 - FAT_tracker.allInstruments[instrumentId].offset-1);
    }
}






void FAT_data_project_changeTempo(s8 addedValue) {
    if (
            (addedValue > 0 && FAT_tracker.tempo <= 255 - addedValue) ||
            (addedValue < 0 && FAT_tracker.tempo > (-addedValue - 1))) {
        FAT_tracker.tempo += addedValue;
    } else if (addedValue < 0){
        FAT_data_project_changeTempo (-FAT_tracker.tempo);
    } else if (addedValue > 0){
        FAT_data_project_changeTempo (255 - FAT_tracker.tempo);
    }
}






void FAT_data_project_changeTranspose(s8 addedValue) {
    if (
            (addedValue > 0 && FAT_tracker.transpose < 256 - addedValue) ||
            (addedValue < 0 && FAT_tracker.transpose > (-addedValue - 1))) {
        FAT_tracker.transpose += addedValue;
    }else if (addedValue < 0){
        FAT_data_project_changeTranspose (-FAT_tracker.transpose);
    } else if (addedValue > 0){
        FAT_data_project_changeTranspose (256 - FAT_tracker.transpose - 1);
    }
}







u8 FAT_data_composer_isNoteEmpty(u8 line) {
    return FAT_tracker.composer.notes[line].freq == 0xff;
}






void FAT_data_composer_previewNote(u8 line) {
    FAT_player_playNote(&FAT_tracker.composer.notes[line], FAT_tracker.composer.channels[line], 0xff);
    FAT_data_instrument_setCurrentlySimulating (1);
}






void FAT_data_composer_addDefaultNote(u8 line) {

    FAT_tracker.composer.notes[line].freq = FAT_data_lastNoteWritten.freq;

    FAT_tracker.composer.notes[line].instrument = FAT_data_lastNoteWritten.instrument;
    FAT_tracker.composer.notes[line].note = FAT_data_lastNoteWritten.note;



    FAT_data_initInstrumentIfNeeded(FAT_tracker.composer.notes[line].instrument, 0);
    FAT_tracker.composer.channels[line] = FAT_tracker.allInstruments[FAT_tracker.composer.notes[line].instrument].type;
    if (FAT_tracker.composer.channels[line] > 5){
        FAT_tracker.composer.channels[line] -= 2;
    }

}







note* FAT_data_composer_getNote(u8 line) {
    return & (FAT_tracker.composer.notes[line]);
}







u8 FAT_data_composer_getChannel(u8 line) {
    return FAT_tracker.composer.channels[line];
}
# 2168 "src/headers/data.h"
void FAT_data_composer_changeValue(u8 line, s8 addedValue) {
    u8 noteName = (FAT_tracker.composer.notes[line].note & 0xf0) >> 4;
    u8 noteOctave = FAT_tracker.composer.notes[line].note & 0x0f;

    u8 channel = FAT_data_composer_getChannel(line);
    instrument* inst = &(FAT_tracker.allInstruments[FAT_tracker.composer.notes[line].instrument]);

    if (channel >= 4) {
        u8 nbMaxSample = snd_countSamplesInKitById(inst->kitNumber);
        if (FAT_tracker.composer.notes[line].freq >= nbMaxSample) {
            FAT_tracker.composer.notes[line].freq = nbMaxSample - 1;

        }
        if ((addedValue > 0 && FAT_tracker.composer.notes[line].freq < nbMaxSample - 1) ||
                (addedValue < 0 && FAT_tracker.composer.notes[line].freq > 0)) {
            FAT_tracker.composer.notes[line].freq += addedValue;
        }
    } else {

        if (addedValue < 0) {

            if (noteName > 0) {

                noteName += addedValue;

            } else if (noteOctave > 3) {


                noteName = 12 - 1;
                noteOctave -= 1;
            }

            if (FAT_tracker.composer.notes[line].freq > 0) {
                FAT_tracker.composer.notes[line].freq += addedValue;
            }

        } else if (addedValue > 0) {
            if (noteName < 12 - 1) {

                noteName += addedValue;

            } else if (noteOctave < 8) {


                noteName = 0;
                noteOctave += 1;
            }

            if (FAT_tracker.composer.notes[line].freq < 72) {
                FAT_tracker.composer.notes[line].freq += addedValue;
            }
        }

    }

    FAT_tracker.composer.notes[line].note = (noteName << 4) + noteOctave;

    FAT_data_lastNoteWritten.freq = FAT_tracker.composer.notes[line].freq;
    FAT_data_lastNoteWritten.note = FAT_tracker.composer.notes[line].note;
}
# 2239 "src/headers/data.h"
void FAT_data_composer_changeOctave(u8 line, s8 addedValue) {
    u8 noteOctave = FAT_tracker.composer.notes[line].note & 0x0f;
    if (
            (addedValue < 0 && noteOctave > 3) ||
            (addedValue > 0 && noteOctave < 8)

            ) {
        FAT_tracker.composer.notes[line].freq += addedValue * 12;
        FAT_tracker.composer.notes[line].note += addedValue;

        FAT_data_lastNoteWritten.freq = FAT_tracker.composer.notes[line].freq;
        FAT_data_lastNoteWritten.note = FAT_tracker.composer.notes[line].note;
    }
}
# 2261 "src/headers/data.h"
u8 FAT_data_composer_smartChangeInstrument(u8 line) {
    u8 inst = 0;
    while (inst < 0x3f) {
        if (FAT_data_isInstrumentFree(inst)) {
            FAT_tracker.composer.notes[line].instrument = inst;
            FAT_data_lastNoteWritten.instrument = inst;

            FAT_data_initInstrumentIfNeeded(inst,
                    0);
            FAT_tracker.composer.channels[line] =
                    FAT_tracker.allInstruments[FAT_tracker.composer.notes[line].instrument].type;

            return 1;
        }
        inst++;
    }

    return 0;
}







void FAT_data_composer_changeInstrument(u8 line, s8 addedValue) {
    if (
            (addedValue < 0 && FAT_tracker.composer.notes[line].instrument > (-addedValue - 1)) ||
            (addedValue > 0 && FAT_tracker.composer.notes[line].instrument < 0x3f - addedValue)

            ) {
        FAT_tracker.composer.notes[line].instrument += addedValue;
        FAT_data_lastNoteWritten.instrument = FAT_tracker.composer.notes[line].instrument;

        FAT_data_initInstrumentIfNeeded(FAT_tracker.composer.notes[line].instrument,
                0);
        FAT_tracker.composer.channels[line] =
                FAT_tracker.allInstruments[FAT_tracker.composer.notes[line].instrument].type;
    }
}







void FAT_data_composer_changeTranspose(u8 composer, s8 value) {
    if (
            (value < 0 && FAT_tracker.composer.transpose > (-value - 1)) ||
            (value > 0 && FAT_tracker.composer.transpose < 256 - value)

            ) {
        FAT_tracker.composer.transpose += value;
    } else if (value < 0){
        FAT_data_composer_changeTranspose (composer, -FAT_tracker.composer.transpose);
    } else if (value > 0){
        FAT_data_composer_changeTranspose (composer, 256 - FAT_tracker.composer.transpose - 1);
    }
}







void FAT_data_composer_changeKeyRepeat(u8 composer, s8 value) {
    if (
            (value < 0 && FAT_tracker.composer.keyRepeat > (-value - 1)) ||
            (value > 0 && FAT_tracker.composer.keyRepeat < 256 - value)

            ) {
        FAT_tracker.composer.keyRepeat += value;
    }else if (value < 0){
        FAT_data_composer_changeKeyRepeat (composer, -FAT_tracker.composer.keyRepeat);
    } else if (value > 0){
        FAT_data_composer_changeKeyRepeat (composer, 256 - FAT_tracker.composer.keyRepeat - 1);
    }
}







void FAT_data_composer_resetAffectedChannel(u8 line) {
    FAT_tracker.composer.channels[line] =
            FAT_tracker.allInstruments[FAT_tracker.composer.notes[line].instrument].type;
}
# 2361 "src/headers/data.h"
void FAT_data_composer_changeAffectedChannelValue(u8 line, s8 addedValue) {
    if (
            (addedValue < 0 && FAT_tracker.composer.channels[line] > (-addedValue - 1)) ||
            (addedValue > 0 && FAT_tracker.composer.channels[line] < 6 - addedValue)

            ) {
        FAT_tracker.composer.channels[line] += addedValue;
    }
}






void FAT_data_project_changeKeyRepeat(s8 addedValue) {
    if (
            (addedValue < 0 && FAT_tracker.keyRepeat > (-addedValue - 1)) ||
            (addedValue > 0 && FAT_tracker.keyRepeat < 256 - addedValue)

            ) {
        FAT_tracker.keyRepeat += addedValue;
        hel_PadSetRepeatRate(0x0020 | 0x0010 | 0x0040 | 0x0080, FAT_tracker.keyRepeat);
        hel_PadSetRepeatDelay(0x0100 | 0x0200 | 0x0020 | 0x0010 | 0x0040 | 0x0080 | 0x0001 | 0x0002 | 0x0008, FAT_tracker.keyRepeat > 9 ? FAT_tracker.keyRepeat - 9 : 1);
    } else if (addedValue < 0){
        FAT_data_project_changeKeyRepeat (-FAT_tracker.keyRepeat);
    } else if (addedValue > 0){
        FAT_data_project_changeKeyRepeat (256 - FAT_tracker.keyRepeat - 1);
    }
}






void FAT_data_project_changePreview(s8 addedValue) {
    if (addedValue < 0) {
        FAT_tracker.previewEnable = 0;
    } else if (addedValue > 0) {
        FAT_tracker.previewEnable = 1;
    }
}

void FAT_data_project_changeGreedPlay (s8 addedValue){
    if (addedValue < 0) {
        FAT_tracker.greedPlay = 0;
    } else if (addedValue > 0) {
        FAT_tracker.greedPlay = 1;
    }
}

void FAT_data_project_changeBufferingInLive (s8 addedValue){
    if (addedValue < 0) {
        FAT_tracker.bufferChangeInLive = 0;
    } else if (addedValue > 0) {
        FAT_tracker.bufferChangeInLive = 1;
    }
}
# 88 "src/headers/fat.h" 2
# 1 "src/headers/filesystem.h" 1
# 27 "src/headers/filesystem.h"
u8 *gamepak = ((u8*)0x0E000000);






void FAT_filesystem_checkFs();
void FAT_filesystem_saveTrack(u8 trackNumber);
void FAT_filesystem_loadTrack(u8 trackNumber);
void FAT_filesystem_setTrackOffset(u8 trackNumber, u16 offset);
u16 FAT_filesystem_getTrackOffset(u8 trackNumber);
void FAT_filesystem_setTrackSize(u8 trackNumber, u16 size);
u16 FAT_filesystem_getTrackSize(u8 trackNumber);
void old_FAT_filesystem_saveRaw(u8 trackNumber);
void old_FAT_filesystem_loadRaw(u8 trackNumber);
u16 FAT_filesystem_findFirstFreeOffset();
void FAT_filesystem_setFirstFreeOffsetValue(u16 value);


const char* emptyName = "EMPTY   ";

char songNameBuffer[9] = "FATSONG!\0";




void FAT_filesystem_checkFs() {
    u8 track = 0;
    u16 offset, size;
    while (track < 16) {

        offset = FAT_filesystem_getTrackOffset(track);
        size = FAT_filesystem_getTrackSize(track);

        if ((offset == 0xFFFF)
                || (offset == 0x0000)) {
            FAT_filesystem_setTrackOffset(track, (track * 4));
            FAT_filesystem_setTrackSize(track, 0);
        }

        track++;
    }


    u16 firstFreeOffset = FAT_filesystem_findFirstFreeOffset();
    if (firstFreeOffset == 0x0000 || firstFreeOffset == 0xFFFF){
        FAT_filesystem_setFirstFreeOffsetValue((16*4)+16);
    }
}







char* FAT_filesystem_getTrackName(u8 trackNumber) {
    u16 offset = FAT_filesystem_getTrackOffset(trackNumber);

    if (offset == (trackNumber*4)) {
        return (char*) emptyName;
    }

    offset += 3;


    u8 cpt = 0;
    u8 writerCpt = 0;
    u8 rleCount, car;
    while (cpt < 8){
        rleCount = gamepak[offset];
        car = gamepak[offset+1];
        writerCpt = 0;
        while (writerCpt < rleCount){
            songNameBuffer[cpt] = car;
            writerCpt++;
            cpt++;
        }
        offset+=2;
    }
    songNameBuffer[8] = '\0';

    return (char*)&songNameBuffer;
}







u8 FAT_filesystem_getTrackNbWork(u8 trackNumber) {
    u16 offset = FAT_filesystem_getTrackOffset(trackNumber);

    if (offset == (trackNumber*4)) {
        return 0;
    }

    offset += 3;


    u8 cpt = 0;
    while (cpt < 8){
        cpt += gamepak[offset];
        offset += 2;
    }

    offset += 3;

    return gamepak[offset];
}







u16 FAT_filesystem_findFirstFreeOffset() {
    u16 firstPart = gamepak[ (16 * 4)];
    u8 secondPart = gamepak[ (16 * 4) + 1];

    return (firstPart << 8) | secondPart;
}




void FAT_filesystem_setFirstFreeOffsetValue(u16 value){
    gamepak[ (16 * 4)] = value >> 8;
    gamepak[ (16 * 4) + 1] = value & 0x00ff;
}







u16 FAT_filesystem_findRawTrackOffset(u8 trackNumber) {
    return (16 * 4) + (sizeof (FAT_tracker) * trackNumber);
}
# 178 "src/headers/filesystem.h"
u16 FAT_filesystem_hasJumpToApply (u16 offset, u8 saveMode) {

    if (gamepak[offset] == 'L'){

        if (gamepak[offset + 1] == 'N' && gamepak[offset + 2] == 'K'){
            if (gamepak[offset +5] == 0x5a &&
                gamepak[offset +6] == 'S' &&
                gamepak[offset +7] == 'N' &&
                gamepak[offset +8] == 'G'){


                    u16 jump = (gamepak[offset +3] << 8) | gamepak[offset +4];
                    if (jump == 0xFFFF && saveMode){

                        jump = FAT_filesystem_findFirstFreeOffset ();

                        gamepak[offset +3] = jump >> 8;
                        gamepak[offset +4] = jump & 0x00ff;
                    }
                    offset = jump;

                    if (saveMode){
                        gamepak[offset] = 'F';
                        gamepak[offset+1] = 'O';
                        gamepak[offset+2] = 'L';
                    }
                    offset += 3;
            }
        }
    }
    return offset;
}






void FAT_filesystem_saveTrack(u8 trackNumber) {
    FAT_tracker.nbWork++;

    u8* tracker = (u8*) &FAT_tracker;
    u8* buffer = (u8*) &FAT_compressed_tracker;

    u32 totalSize = (sizeof(FAT_tracker));
    u8 currentByte = 0;
    u8 previousByte = tracker[0];
    int cpt = 1; int rleCpt = 1; int bufferOffset = 0;
    while (cpt < totalSize){
        currentByte = tracker[cpt];
        if (currentByte != previousByte || rleCpt >= 0xff){
            buffer[bufferOffset] = rleCpt;
            buffer[bufferOffset + 1] = previousByte;

            bufferOffset += 2;
            previousByte = currentByte;
            rleCpt = 1;
        } else {
            rleCpt ++;
        }

        cpt++;
    }
    buffer[bufferOffset] = rleCpt;
    buffer[bufferOffset + 1] = previousByte;
    bufferOffset += 2;


    u32 trackSize = bufferOffset;


    u16 offset = FAT_filesystem_getTrackOffset(trackNumber);

    if (offset == (trackNumber * 4)) {

        offset = FAT_filesystem_findFirstFreeOffset ();
        FAT_filesystem_setTrackOffset(trackNumber, offset);
    }


    gamepak[offset] = 'S';
    gamepak[offset+1] = 'N';
    gamepak[offset+2] = 'G';
    offset += 3;

    int counter = 0;
    while (counter < trackSize) {


        offset = FAT_filesystem_hasJumpToApply (offset, 1);

        gamepak[offset] = buffer[counter];
        counter++;
        offset++;
    }

    FAT_filesystem_setTrackSize(trackNumber, trackSize);
    gamepak[offset] = 'L';
    gamepak[offset +1] = 'N';
    gamepak[offset +2] = 'K';
    gamepak[offset +3] = 0xff;
    gamepak[offset +4] = 0xff;
    gamepak[offset +5] = 0x5a;

    FAT_filesystem_setFirstFreeOffsetValue(offset +6);
}






void FAT_filesystem_loadTrack(u8 trackNumber) {

    u8* tracker = (u8*) &FAT_tracker;
    u8* buffer = (u8*) &FAT_compressed_tracker;

    u32 trackSize = FAT_filesystem_getTrackSize(trackNumber);
    u16 offset = FAT_filesystem_getTrackOffset(trackNumber) + 3;


    FAT_data_initData();

    if (offset != (trackNumber * 4)) {
        int counter = 0;


        while (counter < trackSize) {


            offset = FAT_filesystem_hasJumpToApply(offset, 0);

            buffer[counter] = gamepak[offset];
            counter++;
            offset++;
        }


        counter = 0;
        u8 currentRLE = 0;
        u8 currentByte = 0;
        u8 dataCpt = 0;
        u32 writerCpt = 0;
        while (counter < trackSize){

            currentRLE = buffer[counter];
            currentByte = buffer[counter +1];
            dataCpt = 0;
            while (dataCpt < currentRLE){
                tracker[writerCpt] = currentByte;
                dataCpt ++;
                writerCpt ++;
            }

            counter += 2;
        }
    }
}







void FAT_filesystem_setTrackOffset(u8 trackNumber, u16 offset) {
    gamepak[ trackNumber * 4 ] = offset >> 8;
    gamepak[ (trackNumber * 4) + 1 ] = offset & 0x00ff;
}







u16 FAT_filesystem_getTrackOffset(u8 trackNumber) {
    u16 firstPart = gamepak[ trackNumber * 4 ];
    u8 secondPart = gamepak[ (trackNumber * 4) + 1 ];

    return (firstPart << 8) | secondPart;
}







void FAT_filesystem_setTrackSize(u8 trackNumber, u16 size) {
    gamepak[ (trackNumber * 4) + 2 ] = size >> 8;
    gamepak[ (trackNumber * 4) + 3 ] = size & 0x00ff;
}







u16 FAT_filesystem_getTrackSize(u8 trackNumber) {
    u16 firstPart = gamepak[ (trackNumber * 4) + 2];
    u8 secondPart = gamepak[ (trackNumber * 4) + 3];

    return (firstPart << 8) | secondPart;
}
# 392 "src/headers/filesystem.h"
u16 old_FAT_filesystem_getTrackSizeChecked(u8 trackNumber) {
    u16 size = FAT_filesystem_getTrackSize(trackNumber);
    if (size == 0xFFFF) {
        return 0;
    }

    return size;
}





void old_FAT_filesystem_saveRaw(u8 trackNumber) {
    FAT_tracker.nbWork++;

    u8* tracker = (u8*) & FAT_tracker;


    u32 trackSize = (sizeof(FAT_tracker));


    u16 offset = FAT_filesystem_getTrackOffset(trackNumber);

    if (offset == (trackNumber * 4)) {


        offset = FAT_filesystem_findRawTrackOffset(trackNumber);
        FAT_filesystem_setTrackOffset(trackNumber, offset);
    }

    int counter = 0;
    while (counter < trackSize) {
        gamepak[offset + counter] = tracker[counter];
        counter++;
    }

    FAT_filesystem_setTrackSize(trackNumber, trackSize);

    gamepak[offset + counter] = 0x5a;
}





void old_FAT_filesystem_loadRaw(u8 trackNumber) {
    u8* tracker = (u8*) & FAT_tracker;
    u32 trackSize = FAT_filesystem_getTrackSize(trackNumber);
    u16 offset = FAT_filesystem_getTrackOffset(trackNumber);

    if (offset == (trackNumber * 4)) {


        FAT_data_initData();
    } else {
        int counter = 0;
        while (counter < trackSize) {
            tracker[counter] = gamepak[offset + counter];
            counter++;
        }
    }
}
# 89 "src/headers/fat.h" 2
# 1 "src/headers/cursors.h" 1
# 23 "src/headers/cursors.h"
THandle FAT_cursor1_obj;



THandle FAT_cursor2_obj;



THandle FAT_cursor3_obj;



THandle FAT_cursor8_obj;



THandle FAT_cursorChange_obj;

THandle FAT_cursorKeyboard_obj;
THandle FAT_cursorKeyboard_select_obj;


THandle FAT_cursor_player3_obj;

THandle FAT_cursor_player2_obj;

THandle FAT_cursor_playerSequences_obj[6];

THandle FAT_cursor_playerLiveWait_obj[6];

void FAT_initCursorsKeyboard (){
    FAT_cursorKeyboard_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[3744])), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((0x01)<<10) | ((0)<<9) | ((0) & 0x00FF), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((0)<<10) );
# 69 "src/headers/cursors.h"
    FAT_cursorKeyboard_select_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[3872])), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((0x01)<<10) | ((0)<<9) | ((0) & 0x00FF), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((0)<<10) );
# 84 "src/headers/cursors.h"
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursorKeyboard_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursorKeyboard_select_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);

}







void FAT_initCursor1() {
    FAT_cursor1_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[32])), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((0x01)<<10) | ((0)<<9) | ((0) & 0x00FF), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((1)<<10) );
# 111 "src/headers/cursors.h"
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor1_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}







void FAT_initCursor2() {
    FAT_cursor2_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[160])), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0x01)<<10) | ((0)<<9) | ((0) & 0x00FF), ((2)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((1)<<10) );
# 136 "src/headers/cursors.h"
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor2_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}







void FAT_initCursor3() {
    FAT_cursor3_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[928])), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0x01)<<10) | ((0)<<9) | ((0) & 0x00FF), ((2)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((1)<<10) );
# 161 "src/headers/cursors.h"
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor3_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}







void FAT_initCursor8() {
    FAT_cursor8_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[1440])), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0x01)<<10) | ((0)<<9) | ((0) & 0x00FF), ((3)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((1)<<10) );
# 186 "src/headers/cursors.h"
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor8_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}







void FAT_initCursorChange() {
    FAT_cursorChange_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[2464])), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0x01)<<10) | ((0)<<9) | ((0) & 0x00FF), ((2)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((1)<<10) );
# 211 "src/headers/cursors.h"
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursorChange_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}
# 221 "src/headers/cursors.h"
void FAT_cursors_showCursor1() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor1_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
}
# 232 "src/headers/cursors.h"
void FAT_cursors_showCursor2() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor2_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
}
# 243 "src/headers/cursors.h"
void FAT_cursors_showCursor3() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor3_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
}
# 254 "src/headers/cursors.h"
void FAT_cursors_showCursor8() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor8_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
}

void FAT_cursors_showCursorKeyboard() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursorKeyboard_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
}

void FAT_cursors_showCursorKeyboard_select() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursorKeyboard_select_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
}
# 274 "src/headers/cursors.h"
void FAT_cursors_hideCursor1() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor1_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}
# 285 "src/headers/cursors.h"
void FAT_cursors_hideCursor2() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor2_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}
# 296 "src/headers/cursors.h"
void FAT_cursors_hideCursor3() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor3_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}
# 307 "src/headers/cursors.h"
void FAT_cursors_hideCursor8() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor8_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}

void FAT_cursors_hideCursorKeyboard() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursorKeyboard_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}

void FAT_cursors_hideCursorKeyboard_select() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursorKeyboard_select_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}
# 327 "src/headers/cursors.h"
void FAT_cursors_showCursorChange() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursorChange_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
}
# 339 "src/headers/cursors.h"
void FAT_cursors_hideCursorChange() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursorChange_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}







void FAT_cursors_moveCursorChange(u8 x, u8 y) {
    do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursorChange_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((x)&511) << 16) | (((y)&255)); } while(0);
}







void FAT_cursors_moveCursor1(u8 x, u8 y) {
    do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor1_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((x)&511) << 16) | (((y)&255)); } while(0);
}







void FAT_cursors_moveCursor2(u8 x, u8 y) {
    do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((x)&511) << 16) | (((y)&255)); } while(0);
}







void FAT_cursors_moveCursor3(u8 x, u8 y) {
    do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((x)&511) << 16) | (((y)&255)); } while(0);
}

void FAT_cursors_moveCursorKeyboard(u8 x, u8 y) {
    do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursorKeyboard_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((x)&511) << 16) | (((y)&255)); } while(0);
}

void FAT_cursors_moveCursorKeyboard_select(u8 x, u8 y) {
    do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursorKeyboard_select_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((x)&511) << 16) | (((y)&255)); } while(0);
}




void FAT_cursors_hideAllCursors(){
    FAT_cursors_hideCursor1();
    FAT_cursors_hideCursor2();
    FAT_cursors_hideCursor3();
    FAT_cursors_hideCursor8();
    FAT_cursors_hideCursorChange();
    FAT_cursors_hideCursorKeyboard();
    FAT_cursors_hideCursorKeyboard_select();
}
# 90 "src/headers/fat.h" 2



void FAT_player_startPlayerFromSequences(u8 startLine);

void FAT_player_startPlayerFromBlocks(u8 sequenceId, u8 startLine, u8 channel);

void FAT_player_startPlayerFromNotes(u8 blockId, u8 startLine, u8 channel);

void FAT_player_stopPlayer();

void FAT_player_playComposerNote(u8 noteLine);

void FAT_player_startPlayerFromLive_oneChannel(u8 line, u8 channel);

void FAT_player_stopPlayer_onlyOneColumn(u8 channel);
u8 FAT_isChannelCurrentlyPlaying (u8 channel);

void FAT_player_moveOrHideCursor(u8 channel);
void FAT_player_hideAllCursors();




u8 FAT_isCurrentlyPlaying = 0;
u8 FAT_live_nbChannelPlaying = 0;


u8 actualSequencesForChannel[6];




const char* outputText [4] = {"  ", "L ", " R", "LR"};

# 1 "src/headers/popup.h" 1
# 47 "src/headers/popup.h"
THandle FAT_popup_cursorSelectionObj;

THandle FAT_popup_cursorActualScreenObj;

u8 FAT_popup_cursorSelectionX;

u8 FAT_popup_cursorSelectionY;

u8 FAT_popup_cursorActualScreenX;

u8 FAT_popup_cursorActualScreenY;


u8 FAT_popup_selectedIcon = 3;


void FAT_popup_init();
void FAT_popup_show();
void FAT_popup_hide();
void FAT_popup_initCursors();
void FAT_popup_hideCursors();
void FAT_popup_showCursors();
void FAT_popup_checkButtons();
void FAT_popup_moveSelectionCursorRight();
void FAT_popup_moveSelectionCursorLeft();
void FAT_popup_commitSelectionCursorMove();
u8 FAT_popup_getSelectedIcon();
# 82 "src/headers/popup.h"
u8 FAT_popup_getSelectedIcon() {
    return FAT_popup_selectedIcon;
}







void FAT_popup_moveSelectedScreenCursor() {
    FAT_popup_cursorActualScreenX = FAT_popup_cursorSelectionX + (24 / 2) - 2;
    do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_popup_cursorActualScreenObj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_popup_cursorActualScreenX)&511) << 16) | (((FAT_popup_cursorActualScreenY)&255)); } while(0);
}




void FAT_popup_checkButtons() {
    if (((TPad*)(&__hel_Pad))->Pressed.Right) {
        FAT_popup_moveSelectionCursorRight();
    }

    if (((TPad*)(&__hel_Pad))->Pressed.Left) {
        FAT_popup_moveSelectionCursorLeft();
    }

    if (((TPad*)(&__hel_Pad))->Pressed.Up){
        FAT_showHelp(FAT_popup_selectedIcon);
    }

    FAT_popup_commitSelectionCursorMove();
}







void FAT_popup_initCursors() {
    FAT_popup_cursorSelectionX = 94;
    FAT_popup_cursorSelectionY = 64;

    FAT_popup_cursorActualScreenX = 103;
    FAT_popup_cursorActualScreenY = 60;

    FAT_popup_cursorSelectionObj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[4000])), ((2)<<14) | ((0)<<13) | ((0)<<12) | ((0x01)<<10) | ((0)<<9) | ((FAT_popup_cursorSelectionY) & 0x00FF), ((3)<<14) | ((0)<<13) | ((0)<<12) | ((FAT_popup_cursorSelectionX) & 0x01FF), ((0)<<12) | ((0)<<10) );
# 144 "src/headers/popup.h"
    FAT_popup_cursorActualScreenObj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[0])), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((0x00)<<10) | ((0)<<9) | ((FAT_popup_cursorActualScreenY) & 0x00FF), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((FAT_popup_cursorActualScreenX) & 0x01FF), ((0)<<12) | ((0)<<10) );
# 160 "src/headers/popup.h"
    FAT_popup_hideCursors();
}




void FAT_popup_hideCursors() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_popup_cursorSelectionObj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_popup_cursorActualScreenObj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}




void FAT_popup_showCursors() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_popup_cursorSelectionObj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_popup_cursorActualScreenObj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
}




void FAT_popup_show() {
    ham_SetBgVisible(0, 1);
    FAT_popup_showCursors();
}




void FAT_popup_hide() {
    FAT_popup_hideCursors();
    ham_SetBgVisible(0, 0);
}
# 202 "src/headers/popup.h"
void FAT_popup_moveSelectionCursorRight() {
    if (!(FAT_popup_cursorSelectionX >= 206 - 1)) {
        FAT_popup_cursorSelectionX += 24 + 4;
        FAT_popup_selectedIcon++;
    }
}
# 216 "src/headers/popup.h"
void FAT_popup_moveSelectionCursorLeft() {
    if (!(FAT_popup_cursorSelectionX <= 11)) {
        FAT_popup_cursorSelectionX -= 24 + 4;
        FAT_popup_selectedIcon--;
    }
}





void FAT_popup_commitSelectionCursorMove() {
    do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_popup_cursorSelectionObj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_popup_cursorSelectionX)&511) << 16) | (((FAT_popup_cursorSelectionY)&255)); } while(0);
}
# 126 "src/headers/fat.h" 2
# 1 "src/headers/yesno_dialog.h" 1
# 28 "src/headers/yesno_dialog.h"
void FAT_yesno_close();


u8 param1;




void FAT_yesno_dialogSave_mainFunc() {
    hel_ObjTransmit();

    hel_PadCapture();
    if (((TPad*)(&__hel_Pad))->Pressed.L || ((TPad*)(&__hel_Pad))->Pressed.Select) {
        FAT_yesno_close();
        hel_BgTextPrint(1, 24, 16, 0, "Cancel");
    } else if (((TPad*)(&__hel_Pad))->Pressed.R || ((TPad*)(&__hel_Pad))->Pressed.Start) {
        FAT_filesystem_saveTrack(param1);
        FAT_yesno_close();
        hel_BgTextPrint(1, 24, 16, 0, "Saved ");
    }
}




void FAT_yesno_dialogLoad_mainFunc() {
    hel_ObjTransmit();

    hel_PadCapture();
    if (((TPad*)(&__hel_Pad))->Pressed.L || ((TPad*)(&__hel_Pad))->Pressed.Select) {
        FAT_yesno_close();
        hel_BgTextPrint(1, 24, 16, 0, "Cancel");
    } else if (((TPad*)(&__hel_Pad))->Pressed.R || ((TPad*)(&__hel_Pad))->Pressed.Start) {
        FAT_player_stopPlayer();
        FAT_filesystem_loadTrack(param1);
        FAT_currentScreen = 0;
        FAT_yesno_close();
        hel_BgTextPrint(1, 24, 16, 0, "Loaded");
    }
}




void FAT_yesno_dialogNewProject_mainFunc() {
    hel_ObjTransmit();

    hel_PadCapture();
    if (((TPad*)(&__hel_Pad))->Pressed.L || ((TPad*)(&__hel_Pad))->Pressed.Select) {
        FAT_yesno_close();
        hel_BgTextPrint(1, 24, 16, 0, "Cancel");
    } else if (((TPad*)(&__hel_Pad))->Pressed.R || ((TPad*)(&__hel_Pad))->Pressed.Start) {
        FAT_player_stopPlayer();


        FAT_popup_moveSelectionCursorRight();
        FAT_popup_moveSelectionCursorRight();
        FAT_popup_moveSelectionCursorRight();
        FAT_popup_selectedIcon = 3;

        FAT_data_initData();
        FAT_currentScreen = 3;
        FAT_yesno_close();
        hel_BgTextPrint(1, 22, 16, 0, "Created");
    }
}




void FAT_onlyyes_dialog_mainFunc() {
    hel_ObjTransmit();
    hel_PadCapture();
    if (((TPad*)(&__hel_Pad))->Pressed.R) {
        FAT_yesno_close();
    }
}




void FAT_yesno_close() {
    FAT_popup_init();
    hel_IntrUpdateHandler(0, (void*) &VBLInterruptHandler);
    FAT_switchToScreen(FAT_currentScreen, 100);
}




void FAT_yesno_dialogSave() {

    ham_bg[0].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[79008]), 4928, 1, 1);
    ham_bg[0].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[77728]), 640, 0, 0);
    ham_InitBg(0, 1, 0, 0);

    hel_IntrUpdateHandler(0, (void*) &FAT_yesno_dialogSave_mainFunc);

}




void FAT_yesno_dialogLoad() {

    ham_bg[0].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[66592]), 2272, 1, 1);
    ham_bg[0].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[65312]), 640, 0, 0);
    ham_InitBg(0, 1, 0, 0);

    hel_IntrUpdateHandler(0, (void*) &FAT_yesno_dialogLoad_mainFunc);


}





void FAT_yesno_dialogNewProject() {
    ham_bg[0].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[72416]), 2656, 1, 1);
    ham_bg[0].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[71136]), 640, 0, 0);
    ham_InitBg(0, 1, 0, 0);

    hel_IntrUpdateHandler(0, (void*) &FAT_yesno_dialogNewProject_mainFunc);
}






void FAT_yesno_show(u8 idDialog, ...) {

    va_list params;
    __builtin_stdarg_start((params),idDialog);

    if (ham_bg[0].ti) {
        ham_DeInitTileSet(ham_bg[0].ti);
        ham_DeInitMapSet(ham_bg[0].mi);
    }

    switch (idDialog) {
        case 0:
            param1 = __builtin_va_arg(params, int);
            FAT_yesno_dialogSave();
            break;
        case 1:
            param1 = __builtin_va_arg(params, int);
            FAT_yesno_dialogLoad();
            break;
        case 4:
            FAT_yesno_dialogNewProject();
            break;
    }

    __builtin_va_end(params);
}
# 127 "src/headers/fat.h" 2
# 1 "src/headers/dialog_keyboard.h" 1
# 29 "src/headers/dialog_keyboard.h"
u8 keyboard_actualSelectedLetter = 0;
u8 keyboard_actualCol = 0;
u8 keyboard_actualLine = 0;
u8 willSaveTrackNumber = 0;
# 42 "src/headers/dialog_keyboard.h"
void FAT_dialog_close() {
    FAT_popup_init();
    hel_IntrUpdateHandler(0, (void*) &VBLInterruptHandler);
    FAT_switchToScreen(FAT_currentScreen, 100);
}

void FAT_dialog_keyboardSelectorCursor (){
    FAT_cursors_moveCursorKeyboard_select(
        22 + (keyboard_actualCol*16),
        38 + (keyboard_actualLine*16));

    FAT_cursors_moveCursorKeyboard( 110 + (keyboard_actualSelectedLetter * 8),
                                    22);
}

void FAT_dialog_keyboardPrintActualName (){
    hel_BgTextPrintF(1, 14, 3, 0, "%.8s", songNameBuffer);
}




 void FAT_dialog_keyboardMainFunc() {
     hel_ObjTransmit();

     hel_PadCapture();

     if (((TPad*)(&__hel_Pad))->Pressed.L || ((TPad*)(&__hel_Pad))->Pressed.Select) {
         FAT_dialog_close();
         hel_BgTextPrint(1, 24, 16, 0, "Cancel");
     } else if (((TPad*)(&__hel_Pad))->Pressed.R || ((TPad*)(&__hel_Pad))->Pressed.Start) {

         songNameBuffer[9] = '\0';
         strcpy (FAT_tracker.songName, songNameBuffer);


         FAT_cursors_hideAllCursors();
         hel_IntrUpdateHandler(0, (void*) &VBLInterruptHandler);


         FAT_yesno_show(0, willSaveTrackNumber);
     }

     if (((TPad*)(&__hel_Pad))->Pressed.Right) {
        if (keyboard_actualCol < 12 && ! (keyboard_actualLine > 1 && keyboard_actualCol > 8)){
            keyboard_actualCol ++;
            FAT_dialog_keyboardSelectorCursor ();
        }
     }

     if (((TPad*)(&__hel_Pad))->Pressed.Left) {
        if (keyboard_actualCol > 0){
            keyboard_actualCol --;
            FAT_dialog_keyboardSelectorCursor ();
        }
     }

     if (((TPad*)(&__hel_Pad))->Pressed.Down) {
        if (keyboard_actualLine < 3){
            if (keyboard_actualCol > 9 && keyboard_actualLine >= 1){
                keyboard_actualCol = 9;
            }

            keyboard_actualLine ++;
            FAT_dialog_keyboardSelectorCursor ();
        }
     }

     if (((TPad*)(&__hel_Pad))->Pressed.Up) {
        if (keyboard_actualLine > 0){
            keyboard_actualLine --;
            FAT_dialog_keyboardSelectorCursor ();
        }
     }

     if (((TPad*)(&__hel_Pad))->Pressed.B){
        songNameBuffer[keyboard_actualSelectedLetter] = ' ';
        if (keyboard_actualSelectedLetter > 0){
            keyboard_actualSelectedLetter --;
        }
        FAT_dialog_keyboardPrintActualName();
        FAT_dialog_keyboardSelectorCursor ();
     }

     if (((TPad*)(&__hel_Pad))->Pressed.A){

        if (keyboard_actualLine < 2){

            songNameBuffer[keyboard_actualSelectedLetter] = 65 + ( (keyboard_actualLine*13) + keyboard_actualCol );
            keyboard_actualSelectedLetter ++;

        } else if (keyboard_actualLine == 2){

            songNameBuffer[keyboard_actualSelectedLetter] = 48 + keyboard_actualCol;
            keyboard_actualSelectedLetter ++;

        } else {


            switch (keyboard_actualCol){
                case 0:
                    songNameBuffer[keyboard_actualSelectedLetter] = 40;
                    break;
                case 1:
                    songNameBuffer[keyboard_actualSelectedLetter] = ')';
                    break;
                case 2:
                    songNameBuffer[keyboard_actualSelectedLetter] = '\"';
                    break;
                case 3:
                    songNameBuffer[keyboard_actualSelectedLetter] = '-';
                    break;
                case 4:
                    songNameBuffer[keyboard_actualSelectedLetter] = '/';
                    break;
                case 5:
                    songNameBuffer[keyboard_actualSelectedLetter] = '!';
                    break;
                case 6:
                    songNameBuffer[keyboard_actualSelectedLetter] = '?';
                    break;
                case 7:
                    songNameBuffer[keyboard_actualSelectedLetter] = '.';
                    break;
                case 8:
                    songNameBuffer[keyboard_actualSelectedLetter] = '$';
                    break;
                case 9:
                    songNameBuffer[keyboard_actualSelectedLetter] = ' ';
                    break;
            }
            keyboard_actualSelectedLetter ++;
        }

        if (keyboard_actualSelectedLetter >= 8){
            keyboard_actualSelectedLetter = 0;
        }
        FAT_dialog_keyboardPrintActualName();
        FAT_dialog_keyboardSelectorCursor ();
     }
 }





 void FAT_dialog_cheat_printLineColumns() {
     u8 y = 2;
     int c;
     for (c = 0; c < (16); c++) {
         hel_BgTextPrintF(1, 0, y, 0, "%.2x", c);
         y += 1;
     }
 }




 void FAT_dialog_cheat_printLastTracksName() {
     u8 track = 14;
     u8 y = 2 + 14;
     while (track < 16) {
         hel_BgTextPrintF(1, 3, y, 0, "%.8s %.2x", FAT_filesystem_getTrackName(track),
                 FAT_filesystem_getTrackNbWork(track));
         track++;
         y++;
     }

 }

void FAT_dialog_keyboardShow (u8 fromTrackNum){
    willSaveTrackNumber = fromTrackNum;

    FAT_forceClearTextLayer();

    if (ham_bg[0].ti) {
        ham_DeInitTileSet(ham_bg[0].ti);
        ham_DeInitMapSet(ham_bg[0].mi);
    }

    FAT_cursors_hideAllCursors();

    ham_bg[0].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[57376]), 3968, 1, 1);
    ham_bg[0].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[56096]), 640, 0, 0);
    ham_InitBg(0, 1, 1, 0);

    hel_IntrUpdateHandler(0, (void*) &FAT_dialog_keyboardMainFunc);

    keyboard_actualSelectedLetter = 0;
    keyboard_actualCol = 0;
    keyboard_actualLine = 0;


    FAT_dialog_keyboardSelectorCursor ();
    FAT_cursors_showCursorKeyboard_select();
    FAT_cursors_showCursorKeyboard();

    FAT_dialog_keyboardPrintActualName();


    FAT_dialog_cheat_printLineColumns();
    FAT_dialog_cheat_printLastTracksName();

}
# 128 "src/headers/fat.h" 2
# 1 "src/headers/screen_song.h" 1
# 32 "src/headers/screen_song.h"
u8 FAT_screenSong_currentStartLine = 0;




u8 FAT_screenSong_isPopuped = 0;


void FAT_screenSong_init();
void FAT_screenSong_checkButtons();
void FAT_screenSong_printLineColumns();
void FAT_screenSong_printAllScreenText();
void FAT_screenSong_printInfos();
void FAT_screenSong_pressOrHeldA();
void FAT_screenSong_pressB();


# 1 "src/headers/screen_song_cursor.h" 1
# 39 "src/headers/screen_song_cursor.h"
u8 FAT_screenSong_cursorX;

u8 FAT_screenSong_cursorY;

u8 FAT_screenSong_currentSelectedLine;

u8 FAT_screenSong_currentSelectedColumn;


void FAT_screenSong_initCursor();
void FAT_screenSong_moveCursorRight();
void FAT_screenSong_moveCursorLeft();
void FAT_screenSong_moveCursorDown();
void FAT_screenSong_moveCursorUp();
void FAT_screenSong_commitCursorMove();





void FAT_screenSong_initCursor() {
    FAT_screenSong_cursorX = 24 - 1;
    FAT_screenSong_cursorY = 16 - 1;
    FAT_screenSong_currentSelectedLine = 0;
    FAT_screenSong_currentStartLine = 0;
    FAT_screenSong_currentSelectedColumn = 0;

};




void FAT_screenSong_moveCursorRight() {
    if (!(FAT_screenSong_cursorX >= 143 - 1)) {
        FAT_screenSong_cursorX += 16 + 8;
        FAT_screenSong_currentSelectedColumn++;
        FAT_screenSong_printInfos();
    }
}




void FAT_screenSong_moveCursorLeft() {
    if (!(FAT_screenSong_cursorX <= 24)) {
        FAT_screenSong_cursorX -= 16 + 8;
        FAT_screenSong_currentSelectedColumn--;
        FAT_screenSong_printInfos();
    }
}




void FAT_screenSong_movePageDown() {
    if (FAT_screenSong_currentSelectedLine < 0x40 - 16) {
        FAT_screenSong_currentStartLine += 16;
        FAT_screenSong_currentSelectedLine += 16;
        FAT_screenSong_printAllScreenText();
    }
}




void FAT_screenSong_moveCursorAllDown() {
    FAT_screenSong_cursorY = 135;
    FAT_screenSong_currentStartLine = 0x40 - 16;
    FAT_screenSong_currentSelectedLine = 0x40 - 1;
    FAT_screenSong_printAllScreenText();
}




void FAT_screenSong_moveCursorDown() {
    if (FAT_screenSong_currentSelectedLine < 0x40) {
        if (FAT_screenSong_cursorY >= 135 - 1) {
            if (FAT_screenSong_currentStartLine < 0x40 - 16) {

                FAT_screenSong_currentStartLine++;
                FAT_screenSong_currentSelectedLine++;
                FAT_screenSong_printAllScreenText();
            }
        } else {
            FAT_screenSong_cursorY += 8;
            FAT_screenSong_currentSelectedLine++;
            FAT_screenSong_printInfos();
        }
    }
}




void FAT_screenSong_movePageUp() {
    if (FAT_screenSong_currentSelectedLine >= 16
            && FAT_screenSong_currentStartLine >= 16) {
        FAT_screenSong_currentStartLine -= 16;
        FAT_screenSong_currentSelectedLine -= 16;
        FAT_screenSong_printAllScreenText();
    }
}




void FAT_screenSong_moveCursorAllUp() {
    FAT_screenSong_cursorY = 16 -1;
    FAT_screenSong_currentStartLine = 0;
    FAT_screenSong_currentSelectedLine = 0;
    FAT_screenSong_printAllScreenText();
}




void FAT_screenSong_moveCursorUp() {

    if (FAT_screenSong_currentSelectedLine > 0) {
        if (FAT_screenSong_cursorY <= 16 - 1) {
            if (FAT_screenSong_currentStartLine > 0) {

                FAT_screenSong_currentStartLine--;
                FAT_screenSong_currentSelectedLine--;
                FAT_screenSong_printAllScreenText();
            }
        } else {
            FAT_screenSong_cursorY -= 8;
            FAT_screenSong_currentSelectedLine--;
            FAT_screenSong_printInfos();
        }
    }

}




void FAT_screenSong_commitCursorMove() {
    do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenSong_cursorX)&511) << 16) | (((FAT_screenSong_cursorY)&255)); } while(0);
}
# 50 "src/headers/screen_song.h" 2


const char* CHANNEL_NAME[6] = {"PU1\0", "PU2\0", "WAV\0", "NOI\0", "SNA\0", "SNB\0"};




void FAT_screenSong_init() {

    FAT_reinitScreen();

    ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[374432]), 5088, 1, 1);
    ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[373152]), 640, 0, 0);
    ham_InitBg(3, 1, 3, 0);


    FAT_screenSong_printAllScreenText();





    FAT_cursors_hideCursor2();
    FAT_screenSong_commitCursorMove();
    FAT_cursors_showCursor2();

    u8 i;
    for (i = 0;i<6;i++){
        FAT_player_moveOrHideCursor(i);
    }
}





void FAT_screenSong_printInfos() {
    hel_BgTextPrintF(1, 21, 3, 0, "%s\nChan %s\nLine  %.2x", FAT_tracker.songName, CHANNEL_NAME[FAT_screenSong_currentSelectedColumn], FAT_screenSong_currentSelectedLine);
    hel_BgTextPrintF(1, 21, 6, 0, "TSP   %2.x\nTmpo %.3d", FAT_tracker.transpose, FAT_tracker.tempo);
}






void FAT_screenSong_printLineColumns() {
    u8 y = 2;
    int c;
    for (c = FAT_screenSong_currentStartLine; c < (16 + FAT_screenSong_currentStartLine); c++) {
        hel_BgTextPrintF(1, 0, y, 0, "%.2x", c);
        y += 1;
    }
}




void FAT_screenSong_printSequences() {
    u8 c;
    u8 v;
    for (v = 0; v < 16; v++) {

        for (c = 0; c < 6; c++) {
            if (FAT_tracker.channels[c].sequences[v + FAT_screenSong_currentStartLine] == 0xff) {
                hel_BgTextPrint(1, 3 + (c * 3),
                        v + 2, 0, "  ");
            } else {
                hel_BgTextPrintF(1, 3 + (c * 3),
                        v + 2, 0, "%.2x ",
                        FAT_tracker.channels[c].sequences[v + FAT_screenSong_currentStartLine]);
            }
        }

    }
}
# 134 "src/headers/screen_song.h"
void FAT_screenSong_printSequence(u8 channel, u8 lineOnScreen, u8 realLine) {
    if (FAT_tracker.channels[channel].sequences[realLine] != 0xff) {
        hel_BgTextPrintF(1, 3 + (3 * channel),
                lineOnScreen + 2, 0,
                "%.2x\0", FAT_tracker.channels[channel].sequences[realLine]);
    } else {
        hel_BgTextPrint(1, 3 + (3 * channel),
                lineOnScreen + 2, 0, "  ");
    }
}




void FAT_screenSong_printAllScreenText() {
    FAT_screenSong_printLineColumns();
    FAT_screenSong_printSequences();
    FAT_screenSong_printInfos();
}




void FAT_screenSong_checkButtons() {

    hel_PadCapture();

    if (((TPad*)(&__hel_Pad))->Held.Select) {
        if (!FAT_screenSong_isPopuped) {
            FAT_cursors_hideCursor2();
            FAT_popup_show();
            FAT_screenSong_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenSong_isPopuped) {
            FAT_popup_hide();
            FAT_cursors_showCursor2();
            FAT_screenSong_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != 3) {
                FAT_cursors_hideCursor2();
                FAT_switchToScreen(FAT_popup_getSelectedIcon(), 3);
            }
        }

        if (((TPad*)(&__hel_Pad))->Pressed.A || ((TPad*)(&__hel_Pad))->Held.A) {

            FAT_screenSong_pressOrHeldA();

        } else {

            if (((TPad*)(&__hel_Pad))->Pressed.Start) {
                if (!FAT_isCurrentlyPlaying) {
                    FAT_player_startPlayerFromSequences(FAT_screenSong_currentSelectedLine);
                } else {
                    FAT_player_stopPlayer();
                }
            }

            if (((TPad*)(&__hel_Pad))->Pressed.R && ((TPad*)(&__hel_Pad))->Pressed.L) {
                FAT_showHelp(3);
            }

            if (((TPad*)(&__hel_Pad))->Pressed.B) {
                FAT_screenSong_pressB();
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                FAT_screenSong_moveCursorRight();
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                FAT_screenSong_moveCursorLeft();
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                if (((TPad*)(&__hel_Pad))->Held.R) {
                    FAT_screenSong_movePageDown();
                } else if (((TPad*)(&__hel_Pad))->Held.L) {
                    FAT_screenSong_moveCursorAllDown();
                } else {
                    FAT_screenSong_moveCursorDown();
                }
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                if (((TPad*)(&__hel_Pad))->Held.R) {
                    FAT_screenSong_movePageUp();
                } else if (((TPad*)(&__hel_Pad))->Held.L) {
                    FAT_screenSong_moveCursorAllUp();
                } else {
                    FAT_screenSong_moveCursorUp();
                }
            }
            FAT_screenSong_commitCursorMove();
        }

    }

}




void FAT_screenSong_pressB() {
    if (((TPad*)(&__hel_Pad))->Held.L) {

        if (FAT_data_isSequenceAllocatable(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine)) {

            FAT_data_pasteSequenceWithNewNumber(FAT_screenSong_currentSelectedColumn, FAT_screenSong_currentSelectedLine);
        } else {
            FAT_data_cloneSequence(FAT_screenSong_currentSelectedColumn, FAT_screenSong_currentSelectedLine);
        }

    } else {

        if (FAT_data_isSequenceAllocatable(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine)) {

            FAT_data_pasteSequence(FAT_screenSong_currentSelectedColumn, FAT_screenSong_currentSelectedLine);
        } else {
            FAT_data_cutSequence(FAT_screenSong_currentSelectedColumn, FAT_screenSong_currentSelectedLine);
        }
    }

    FAT_screenSong_printSequence(FAT_screenSong_currentSelectedColumn, FAT_screenSong_currentSelectedLine - FAT_screenSong_currentStartLine, FAT_screenSong_currentSelectedLine);
}




void FAT_screenSong_pressOrHeldA() {
    if (((TPad*)(&__hel_Pad))->Pressed.L) {
        FAT_data_smartAllocateSequence(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine);
    } else {
        FAT_data_allocateSequence(
                FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine);
    }

    if (((TPad*)(&__hel_Pad))->Pressed.Right) {
        FAT_data_sequence_changeValue(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine, 1);
    }

    if (((TPad*)(&__hel_Pad))->Pressed.Left) {
        FAT_data_sequence_changeValue(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine, -1);
    }

    if (((TPad*)(&__hel_Pad))->Pressed.Up) {
        FAT_data_sequence_changeValue(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine, 16);
    }

    if (((TPad*)(&__hel_Pad))->Pressed.Down) {
        FAT_data_sequence_changeValue(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine, -16);
    }

    FAT_screenSong_printSequence(
            FAT_screenSong_currentSelectedColumn,
            FAT_screenSong_currentSelectedLine - FAT_screenSong_currentStartLine,
            FAT_screenSong_currentSelectedLine);
}
# 129 "src/headers/fat.h" 2
# 1 "src/headers/screen_filesystem.h" 1
# 33 "src/headers/screen_filesystem.h"
u8 FAT_screenFilesystem_isPopuped = 0;

u8 FAT_filesystem_actualMode = 0;


const char* modes[2] = {"SAVE", "LOAD"};


void FAT_screenFilesystem_init();
void FAT_screenFilesystem_checkButtons();
void FAT_screenFilesystem_printInfos();
void FAT_screenFilesystem_pressOrHeldA();

# 1 "src/headers/screen_filesystem_cursor.h" 1
# 34 "src/headers/screen_filesystem_cursor.h"
u8 FAT_screenFilesystem_action_cursorX;

u8 FAT_screenFilesystem_cursorY;

u8 FAT_screenFilesystem_currentSelectedLine;


void FAT_screenFilesystem_initCursor();
void FAT_screenFilesystem_moveCursorDown();
void FAT_screenFilesystem_moveCursorUp();
void FAT_screenFilesystem_commitCursorMove();





void FAT_screenFilesystem_initCursor() {
    FAT_screenFilesystem_cursorY = 16 - 1;
    FAT_screenFilesystem_currentSelectedLine = 0;
}




void FAT_screenFilesystem_commitCursorMove() {
    do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor8_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((24)&511) << 16) | (((FAT_screenFilesystem_cursorY+1)&255)); } while(0);
    do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((95)&511) << 16) | (((FAT_screenFilesystem_cursorY)&255)); } while(0);
}




void FAT_screenFilesystem_moveCursorDown() {
    if (FAT_screenFilesystem_currentSelectedLine < 16 - 1) {
        if (!(FAT_screenFilesystem_cursorY >= 135 - 1)) {
            FAT_screenFilesystem_cursorY += 8;
            FAT_screenFilesystem_currentSelectedLine++;
            FAT_screenFilesystem_printInfos();
        }
    } else {
        FAT_screenFilesystem_cursorY = 16 - 1;
        FAT_screenFilesystem_currentSelectedLine = 0;
        FAT_screenFilesystem_printInfos();
    }
}




void FAT_screenFilesystem_moveCursorUp() {

    if (FAT_screenFilesystem_currentSelectedLine > 0) {
        if (!(FAT_screenFilesystem_cursorY <= 16 - 1)) {
            FAT_screenFilesystem_cursorY -= 8;
            FAT_screenFilesystem_currentSelectedLine--;
            FAT_screenFilesystem_printInfos();
        }
    } else {
        FAT_screenFilesystem_cursorY = (16 - 1) + (8 *15);
        FAT_screenFilesystem_currentSelectedLine = 0xf;
        FAT_screenFilesystem_printInfos();
    }

}
# 47 "src/headers/screen_filesystem.h" 2






void FAT_screenFilesystem_setMode(u8 modeId) {
    FAT_filesystem_actualMode = modeId;
}




void FAT_screenFilesystem_printMode() {
    hel_BgTextPrintF(1, 16, 3, 0, "Mode %s", modes[FAT_filesystem_actualMode]);
}





void FAT_screenFilesystem_printLineColumns() {
    u8 y = 2;
    int c;
    for (c = 0; c < (16); c++) {
        hel_BgTextPrintF(1, 0, y, 0, "%.2x", c);
        y += 1;
    }
}




void FAT_screenFilesystem_printAllTracksName() {
    u8 track = 0;
    u8 y = 2;
    while (track < 16) {
        hel_BgTextPrintF(1, 3, y, 0, "%.8s %.2x", FAT_filesystem_getTrackName(track),
                FAT_filesystem_getTrackNbWork(track));
        track++;
        y++;
    }

}





void FAT_screenFilesystem_printInfos() {
    hel_BgTextPrintF(1, 16, 5, 0, "Line %.2x", FAT_screenFilesystem_currentSelectedLine);
    hel_BgTextPrintF(1, 16, 6, 0, "Name %.8s", FAT_filesystem_getTrackName(FAT_screenFilesystem_currentSelectedLine));
    hel_BgTextPrintF(1, 16, 7, 0, "Size %.5d B", FAT_filesystem_getTrackSize(FAT_screenFilesystem_currentSelectedLine));
    hel_BgTextPrintF(1, 16, 8, 0, "Work %.2x", FAT_filesystem_getTrackNbWork(FAT_screenFilesystem_currentSelectedLine));
}




void FAT_screenFilesystem_init() {
    FAT_reinitScreen();


    ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[101280]), 5664, 1, 1);
    ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[100000]), 640, 0, 0);
    ham_InitBg(3, 1, 3, 0);


    FAT_screenFilesystem_printLineColumns();
    FAT_screenFilesystem_printAllTracksName();
    FAT_screenFilesystem_printMode();
    FAT_screenFilesystem_printInfos();


    FAT_cursors_hideAllCursors();
    FAT_cursors_showCursor8();
    FAT_cursors_showCursor2();
    FAT_screenFilesystem_commitCursorMove();
}




void FAT_screenFilesystem_checkButtons() {
    hel_PadCapture();

    if (((TPad*)(&__hel_Pad))->Held.Select) {
        if (!FAT_screenFilesystem_isPopuped) {
            FAT_cursors_hideCursor8();
            FAT_cursors_hideCursor2();
            FAT_popup_show();
            FAT_screenFilesystem_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenFilesystem_isPopuped) {
            FAT_popup_hide();
            FAT_cursors_showCursor8();
            FAT_cursors_showCursor2();
            FAT_screenFilesystem_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != 8) {

                FAT_cursors_hideCursor8();
                FAT_cursors_hideCursor2();
                FAT_switchToScreen(FAT_popup_getSelectedIcon(), 8);
            }
        }

        if (((TPad*)(&__hel_Pad))->Pressed.R && ((TPad*)(&__hel_Pad))->Pressed.L) {
            FAT_showHelp(8);
        }

        if (((TPad*)(&__hel_Pad))->Pressed.Right) {
        }

        if (((TPad*)(&__hel_Pad))->Pressed.Left) {
        }

        if (((TPad*)(&__hel_Pad))->Pressed.Down) {
            FAT_screenFilesystem_moveCursorDown();
        }

        if (((TPad*)(&__hel_Pad))->Pressed.Up) {
            FAT_screenFilesystem_moveCursorUp();
        }

        if (((TPad*)(&__hel_Pad))->Pressed.A) {
            FAT_screenFilesystem_pressOrHeldA();
        }

        FAT_screenFilesystem_commitCursorMove();
    }
}




void FAT_screenFilesystem_pressOrHeldA() {
    switch (FAT_filesystem_actualMode) {
        case 1:
            FAT_yesno_show(1, FAT_screenFilesystem_currentSelectedLine);
            break;

        case 0:
            FAT_dialog_keyboardShow (FAT_screenFilesystem_currentSelectedLine);
            break;
    }

}
# 130 "src/headers/fat.h" 2
# 1 "src/headers/screen_project.h" 1
# 21 "src/headers/screen_project.h"
# 1 "src/headers/screen_project_cursor.h" 1
# 31 "src/headers/screen_project_cursor.h"
u8 FAT_screenProject_cursorX;

u8 FAT_screenProject_cursorY;

u8 FAT_screenProject_currentSelectedLine;

u8 FAT_screenProject_currentSelectedColumn;




const u8 PROJECT_PULSE_BLOCK_Y[9] = {31, 39, 63, 71, 79, 103, 111, 119, 63};




void FAT_screenProject_commitCursorMove() {
    switch (FAT_screenProject_currentSelectedLine) {
        case 0:
        case 3:
        case 4:
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenProject_cursorX)&511) << 16) | (((FAT_screenProject_cursorY)&255)); } while(0);
            break;
        case 8:
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= ((((88 -1) + 120)&511) << 16) | (((FAT_screenProject_cursorY)&255)); } while(0);
            break;
        case 1:
        case 2:
        case 5:
        case 6:
        case 7:
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenProject_cursorX)&511) << 16) | (((FAT_screenProject_cursorY)&255)); } while(0);
            break;
    }
}




void FAT_screenProject_displayGoodCursor() {
    switch (FAT_screenProject_currentSelectedLine) {
        case 0:
        case 3:
        case 4:
        case 8:
            FAT_cursors_hideCursor2();
            FAT_cursors_showCursor3();
            break;
        case 1:
        case 2:
        case 5:
        case 6:
        case 7:
            FAT_cursors_hideCursor3();
            FAT_cursors_showCursor2();
            break;

    }
}





void FAT_screenProject_initCursor() {

    FAT_screenProject_cursorX = 88 - 1;
    FAT_screenProject_cursorY = 32 - 1;

    FAT_screenProject_currentSelectedLine = 0;
    FAT_screenProject_currentSelectedColumn = 0;

    FAT_screenProject_commitCursorMove();
}




void FAT_screenProject_moveCursorRight() {
    FAT_screenProject_currentSelectedLine = 8;
    FAT_screenProject_cursorY = PROJECT_PULSE_BLOCK_Y[FAT_screenProject_currentSelectedLine];
    FAT_screenProject_displayGoodCursor();
}




void FAT_screenProject_moveCursorLeft() {
    FAT_screenProject_currentSelectedLine = 2;
    FAT_screenProject_cursorY = PROJECT_PULSE_BLOCK_Y[FAT_screenProject_currentSelectedLine];
    FAT_screenProject_displayGoodCursor();
}




void FAT_screenProject_moveCursorDown() {

    if (FAT_screenProject_currentSelectedLine < 9 - 2) {
        if (!(FAT_screenProject_cursorY >= 136 - 1)) {
            FAT_screenProject_currentSelectedLine++;
            FAT_screenProject_cursorY = PROJECT_PULSE_BLOCK_Y[FAT_screenProject_currentSelectedLine];
        }
    } else {
        FAT_screenProject_currentSelectedLine = 0;
        FAT_screenProject_cursorY = PROJECT_PULSE_BLOCK_Y[FAT_screenProject_currentSelectedLine];
    }
    FAT_screenProject_displayGoodCursor();

}




void FAT_screenProject_moveCursorUp() {
    if (FAT_screenProject_currentSelectedLine > 0) {
        if (!(FAT_screenProject_cursorY <= 32 - 1)) {
            FAT_screenProject_currentSelectedLine--;
            FAT_screenProject_cursorY = PROJECT_PULSE_BLOCK_Y[FAT_screenProject_currentSelectedLine];
        }
    }else {
        FAT_screenProject_currentSelectedLine = 9 - 2;
        FAT_screenProject_cursorY = PROJECT_PULSE_BLOCK_Y[FAT_screenProject_currentSelectedLine];
    }
    FAT_screenProject_displayGoodCursor();
}
# 22 "src/headers/screen_project.h" 2


const char* yesOrNo[2] = {"NOP\0", "YES\0"};




u8 FAT_screenProject_isPopuped = 0;


void FAT_screenProject_checkButtons();
void FAT_screenProject_pressOrHeldA();




void FAT_screenProject_printInfos() {
    hel_BgTextPrintF(1, 1, 4, 0, "Tempo     %3d", FAT_tracker.tempo);
    hel_BgTextPrintF(1, 1, 5, 0, "Transpose %.2x", FAT_tracker.transpose);
    hel_BgTextPrintF(1, 1, 8, 0, "KeyRepeat %.2x   Buffering %.3s", FAT_tracker.keyRepeat, yesOrNo[FAT_tracker.bufferChangeInLive != 0]);
    hel_BgTextPrintF(1, 1, 9, 0, "Preview   %.3s", yesOrNo[FAT_tracker.previewEnable != 0]);
    hel_BgTextPrintF(1, 1, 10, 0, "GreedPlay %.3s", yesOrNo[FAT_tracker.greedPlay != 0]);
    hel_BgTextPrintF(1, 1, 13, 0, "New  Prj  OK");
    hel_BgTextPrintF(1, 1, 14, 0, "Save Prj  OK");
    hel_BgTextPrintF(1, 1, 15, 0, "Load Prj  OK");

    hel_BgTextPrintF(1, 1, 1, 0, "FAT project v%s", "1.1.0");
}





void FAT_screenProject_printProject() {
    hel_BgTextPrintF(1, 16, 3, 0, "Name %.8s", FAT_tracker.songName);
    hel_BgTextPrintF(1, 16, 4, 0, "Mem  %.d B", sizeof (FAT_tracker));
    hel_BgTextPrintF(1, 16, 5, 0, "Work %.2x", FAT_tracker.nbWork);

}




void FAT_screenProject_init() {
    FAT_reinitScreen();


    ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[359968]), 6592, 1, 1);
    ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[358688]), 640, 0, 0);
    ham_InitBg(3, 1, 3, 0);


    FAT_screenProject_printInfos();
    FAT_screenProject_printProject();


    FAT_cursors_hideCursor8();


    FAT_player_hideAllCursors ();
    FAT_screenProject_initCursor();
    FAT_screenProject_displayGoodCursor();
}




void FAT_screenProject_checkButtons() {
    hel_PadCapture();

    if (((TPad*)(&__hel_Pad))->Held.Select) {
        if (!FAT_screenProject_isPopuped) {
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            FAT_popup_show();
            FAT_screenProject_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenProject_isPopuped) {
            FAT_popup_hide();
            FAT_screenProject_displayGoodCursor();
            FAT_screenProject_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != 0) {
                FAT_cursors_hideCursor2();
                FAT_cursors_hideCursor3();
                FAT_switchToScreen(FAT_popup_getSelectedIcon(), 0);
            }
        }

        if (((TPad*)(&__hel_Pad))->Held.A || ((TPad*)(&__hel_Pad))->Pressed.A) {
            FAT_screenProject_pressOrHeldA();
        } else {

            if (((TPad*)(&__hel_Pad))->Pressed.Start) {
                if (!FAT_isCurrentlyPlaying) {
                    FAT_player_startPlayerFromSequences(FAT_screenSong_currentSelectedLine);
                } else {
                    FAT_player_stopPlayer();
                }
            }

            if (((TPad*)(&__hel_Pad))->Pressed.R && ((TPad*)(&__hel_Pad))->Pressed.L) {
                FAT_showHelp(0);
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                FAT_screenProject_moveCursorRight();
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                FAT_screenProject_moveCursorLeft();
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                FAT_screenProject_moveCursorDown();
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                FAT_screenProject_moveCursorUp();
            }

            FAT_screenProject_commitCursorMove();
        }
    }
}




void FAT_screenProject_pressOrHeldA() {
    s8 addedValue = 0;
    if (((TPad*)(&__hel_Pad))->Pressed.Left) {
        addedValue = -1;
    }

    if (((TPad*)(&__hel_Pad))->Pressed.Right) {
        addedValue = 1;
    }

    if (((TPad*)(&__hel_Pad))->Pressed.Up) {
        addedValue = 16;
    }

    if (((TPad*)(&__hel_Pad))->Pressed.Down) {
        addedValue = -16;
    }

    switch (FAT_screenProject_currentSelectedLine) {
        case 0:
            FAT_data_project_changeTempo(addedValue);
            FAT_screenProject_printInfos();
            break;
        case 1:
            FAT_data_project_changeTranspose(addedValue);
            FAT_screenProject_printInfos();
            break;
        case 2:
            FAT_data_project_changeKeyRepeat(addedValue);
            FAT_screenProject_printInfos();
            break;
        case 3:
            FAT_data_project_changePreview(addedValue);
            FAT_screenProject_printInfos();
            break;
        case 4:
            FAT_data_project_changeGreedPlay(addedValue);
            FAT_screenProject_printInfos();
            break;
        case 5:
            FAT_yesno_show(4);
            break;
        case 6:
            FAT_cursors_hideCursor3();
            FAT_cursors_hideCursor2();
            FAT_screenFilesystem_setMode(0);
            FAT_switchToScreen(8, 0);
            break;
        case 7:
            FAT_cursors_hideCursor3();
            FAT_cursors_hideCursor2();
            FAT_screenFilesystem_setMode(1);
            FAT_switchToScreen(8, 0);
            break;
        case 8:
            FAT_data_project_changeBufferingInLive(addedValue);
            FAT_screenProject_printInfos();
            break;


    }

}
# 131 "src/headers/fat.h" 2
# 1 "src/headers/screen_live.h" 1
# 32 "src/headers/screen_live.h"
u8 FAT_screenLive_isPopuped = 0;


void FAT_screenLive_init();
void FAT_screenLive_checkButtons();
void FAT_screenLive_printInfos();
void FAT_screenLive_printAllScreenText();
void FAT_screenLive_pressOrHeldA_inSequencer();
void FAT_screenLive_pressOrHeldA_inDataTable();

u8 FAT_screenLive_isCursorInSequencer = 1;


u8 FAT_screenLive_currentStartLine = 0;


u8 FAT_screenLive_bufferTempo;
u8 FAT_screenLive_bufferVolume[6];
u8 FAT_screenLive_bufferTranspose[6];
u8 FAT_screenLive_haveToApplyBuffer = 0;
void FAT_screenLive_applyBufferIfNeeded();

void FAT_screenLive_changeVolume (u8 channel, s8 addedValue);
void FAT_screenLive_changeTranspose (u8 channel, s8 addedValue);
void FAT_screenLive_changeAllVolumes (s8 addedValue);
void FAT_screenLive_changeAllTransposes (s8 addedValue);
void FAT_screenLive_setAllVolumes (u8 value);

# 1 "src/headers/screen_live_cursor.h" 1
# 22 "src/headers/screen_live_cursor.h"
u8 FAT_screenLive_cursorX;

u8 FAT_screenLive_cursorY;

u8 FAT_screenLive_currentSelectedLine;

u8 FAT_screenLive_currentSelectedColumn;

u8 FAT_screenLive_currentTableSelectedLine;

# 1 "src/headers/screen_live.h" 1
# 33 "src/headers/screen_live_cursor.h" 2
# 58 "src/headers/screen_live_cursor.h"
void FAT_screenLive_initCursor();
void FAT_screenLive_moveCursorRight();
void FAT_screenLive_moveCursorLeft();
void FAT_screenLive_moveCursorDown();
void FAT_screenLive_moveCursorUp();
void FAT_screenLive_commitCursorMove();





void FAT_screenLive_initCursor() {
    FAT_screenLive_cursorX = 24 - 1;
    FAT_screenLive_cursorY = 16 - 1;
    FAT_screenLive_currentSelectedLine = 0;
    FAT_screenLive_currentStartLine = 0;
    FAT_screenLive_currentSelectedColumn = 0;
    FAT_screenLive_currentTableSelectedLine = 0;

};




void FAT_screenLive_moveCursorRight() {
    if (!(FAT_screenLive_cursorX >= 143 - 1)) {

        if (!FAT_screenLive_isCursorInSequencer && FAT_screenLive_currentTableSelectedLine == 2){
            if (FAT_screenLive_currentSelectedColumn == 1){
                FAT_screenLive_cursorX = 120 - 1;
                FAT_screenLive_currentSelectedColumn = 4;
            }
        }else {
            FAT_screenLive_cursorX += 16 + 8;
            FAT_screenLive_currentSelectedColumn++;

        }
        FAT_screenLive_printInfos();
    }
}




void FAT_screenLive_moveCursorLeft() {
    if (!(FAT_screenLive_cursorX <= 24)) {

        if (!FAT_screenLive_isCursorInSequencer && FAT_screenLive_currentTableSelectedLine == 2){
            if (FAT_screenLive_currentSelectedColumn == 4){
                FAT_screenLive_cursorX = 48 - 1;
                FAT_screenLive_currentSelectedColumn = 1;
            }
        }else{
            FAT_screenLive_cursorX -= 16 + 8;
            FAT_screenLive_currentSelectedColumn--;
        }
        FAT_screenLive_printInfos();
    }
}




void FAT_screenLive_movePageDown() {
    if (FAT_screenLive_currentSelectedLine < 0x40 - 10) {
        FAT_screenLive_currentStartLine += 10;
        FAT_screenLive_currentSelectedLine += 10;
        FAT_screenLive_printAllScreenText();
    }
}




void FAT_screenLive_moveCursorAllDown() {
    FAT_screenLive_cursorY = 87;
    FAT_screenLive_currentStartLine = 0x40 - 10;
    FAT_screenLive_currentSelectedLine = 0x40 - 1;
    FAT_screenLive_printAllScreenText();
}




void FAT_screenLive_moveCursorDown() {
    if (FAT_screenLive_isCursorInSequencer){
        if (FAT_screenLive_currentSelectedLine < 0x40) {
            if (FAT_screenLive_cursorY >= 87 - 1) {
                if (FAT_screenLive_currentStartLine < 0x40 - 10) {

                    FAT_screenLive_currentStartLine++;
                    FAT_screenLive_currentSelectedLine++;
                    FAT_screenLive_printAllScreenText();
                }
            } else {
                FAT_screenLive_cursorY += 8;
                FAT_screenLive_currentSelectedLine++;
                FAT_screenLive_printInfos();
            }
        }
    } else {
        if (FAT_screenLive_currentTableSelectedLine < 2){
            FAT_screenLive_currentTableSelectedLine ++;
            if (FAT_screenLive_currentTableSelectedLine == 2){
                FAT_cursors_hideCursor2();
                FAT_cursors_showCursor3();

                FAT_screenLive_cursorY += 8 * 2;

                if (FAT_screenLive_currentSelectedColumn<3){
                    FAT_screenLive_cursorX = 48 - 1;
                    FAT_screenLive_currentSelectedColumn = 1;
                } else {
                    FAT_screenLive_cursorX = 120 - 1;
                    FAT_screenLive_currentSelectedColumn = 4;
                }


                FAT_screenLive_printInfos();

            }else{
                FAT_screenLive_cursorY += 8;
            }
        }
    }
}




void FAT_screenLive_movePageUp() {
    if (FAT_screenLive_currentSelectedLine >= 10
            && FAT_screenLive_currentStartLine >= 10) {
        FAT_screenLive_currentStartLine -= 10;
        FAT_screenLive_currentSelectedLine -= 10;
        FAT_screenLive_printAllScreenText();
    }
}




void FAT_screenLive_moveCursorAllUp() {
    FAT_screenLive_cursorY = 16 - 1;
    FAT_screenLive_currentStartLine = 0;
    FAT_screenLive_currentSelectedLine = 0;
    FAT_screenLive_printAllScreenText();
}




void FAT_screenLive_moveCursorUp() {
    if (FAT_screenLive_isCursorInSequencer){
        if (FAT_screenLive_currentSelectedLine > 0) {
            if (FAT_screenLive_cursorY <= 16 - 1) {
                if (FAT_screenLive_currentStartLine > 0) {

                    FAT_screenLive_currentStartLine--;
                    FAT_screenLive_currentSelectedLine--;
                    FAT_screenLive_printAllScreenText();
                }
            } else {
                FAT_screenLive_cursorY -= 8;
                FAT_screenLive_currentSelectedLine--;
                FAT_screenLive_printInfos();
            }
        }
    } else {
        if (FAT_screenLive_currentTableSelectedLine > 0){
            if (FAT_screenLive_currentTableSelectedLine == 2){

                FAT_cursors_hideCursor3();
                FAT_cursors_showCursor2();

                FAT_screenLive_cursorY -= 8 * 2;

            }else{
                FAT_screenLive_cursorY -= 8;
            }
            FAT_screenLive_currentTableSelectedLine --;
        }
    }

}





void FAT_screenLive_switchCursorToPart (u8 part){
    FAT_cursors_hideCursor3();
    FAT_cursors_showCursor2();
    if (part == 1){

        FAT_screenLive_cursorY = 16 - 1 + (8* (FAT_screenLive_currentSelectedLine-FAT_screenLive_currentStartLine));
    } else {

        FAT_screenLive_cursorY = 104 - 1;
    }
    return;
}




void FAT_screenLive_commitCursorMove() {
    if (FAT_screenLive_isCursorInSequencer){
        do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenLive_cursorX)&511) << 16) | (((FAT_screenLive_cursorY)&255)); } while(0);
    } else {
        if (FAT_screenLive_currentTableSelectedLine == 2) {
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenLive_cursorX)&511) << 16) | (((FAT_screenLive_cursorY)&255)); } while(0);
        }else {
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenLive_cursorX)&511) << 16) | (((FAT_screenLive_cursorY)&255)); } while(0);
        }
    }
}
# 61 "src/headers/screen_live.h" 2





void FAT_screenLive_printTempo() {
    hel_BgTextPrintF(1, 15, 16, 0, "%3d", FAT_screenLive_bufferTempo);
    hel_BgTextPrintF(1, 21, 7, 0, "Tmpo %.3d", FAT_tracker.tempo);
}




void FAT_screenLive_printTranspose() {
    hel_BgTextPrintF(1, 10, 16, 0, "%.2x", FAT_tracker.transpose);
}




void FAT_screenLive_printLiveMode() {
    if (FAT_tracker.liveData.liveMode) {
        hel_BgTextPrint(1, 6, 16, 0, "MAN");
    } else {
        hel_BgTextPrintF(1, 6, 16, 0, "AUT");
    }
}

void FAT_screenLive_printVolumes() {
    hel_BgTextPrintF(1, 2, 13, 0, " %.2x %.2x %.2x %.2x %.2x %.2x",
            FAT_screenLive_bufferVolume[0] != 0xff ? FAT_screenLive_bufferVolume[0] : 0xdf,
            FAT_screenLive_bufferVolume[1] != 0xff ? FAT_screenLive_bufferVolume[1] : 0xdf,
            FAT_screenLive_bufferVolume[2] != 0xff ? FAT_screenLive_bufferVolume[2] : 0xdf,
            FAT_screenLive_bufferVolume[3] != 0xff ? FAT_screenLive_bufferVolume[3] : 0xdf,
            FAT_screenLive_bufferVolume[4] != 0xff ? FAT_screenLive_bufferVolume[4] : 0xdf,
            FAT_screenLive_bufferVolume[5] != 0xff ? FAT_screenLive_bufferVolume[5] : 0xdf);
}

void FAT_screenLive_printTransposes() {
    hel_BgTextPrintF(1, 2, 14, 0, " %.2x %.2x %.2x %.2x %.2x %.2x",
            FAT_screenLive_bufferTranspose[0],
            FAT_screenLive_bufferTranspose[1],
            FAT_screenLive_bufferTranspose[2],
            FAT_screenLive_bufferTranspose[3],
            FAT_screenLive_bufferTranspose[4],
            FAT_screenLive_bufferTranspose[5]);
}






void FAT_screenLive_printLineColumns() {
    u8 y = 2;
    int c;
    for (c = FAT_screenLive_currentStartLine; c < (10 + FAT_screenLive_currentStartLine); c++) {
        hel_BgTextPrintF(1, 0, y, 0, "%.2x", c);
        y += 1;
    }
}





void FAT_screenLive_printInfos() {
    hel_BgTextPrintF(1, 21, 3, 0, "%s", FAT_tracker.songName);
    hel_BgTextPrintF(1, 21, 4, 0, "Chan %s", CHANNEL_NAME[FAT_screenLive_currentSelectedColumn]);
    hel_BgTextPrintF(1, 21, 5, 0, "Line  %.2x", FAT_screenLive_currentSelectedLine);
    hel_BgTextPrintF(1, 21, 6, 0, "TSP   %2.x", FAT_tracker.transpose);

    FAT_screenLive_printLiveMode();
    FAT_screenLive_printTempo();
}
# 144 "src/headers/screen_live.h"
void FAT_screenLive_printSequence(u8 channel, u8 lineOnScreen, u8 realLine) {
    if (FAT_tracker.channels[channel].sequences[realLine] != 0xff) {
        hel_BgTextPrintF(1, 3 + (3 * channel),
                lineOnScreen + 2, 0,
                "%.2x\0", FAT_tracker.channels[channel].sequences[realLine]);
    } else {
        hel_BgTextPrint(1, 3 + (3 * channel),
                lineOnScreen + 2, 0, "  ");
    }
}




void FAT_screenLive_printSequences() {
    u8 c;
    u8 v;
    for (v = 0; v < 10; v++) {

        for (c = 0; c < 6; c++) {
            if (FAT_tracker.channels[c].sequences[v + FAT_screenLive_currentStartLine] == 0xff) {
                hel_BgTextPrint(1, 3 + (c * 3),
                        v + 2, 0, "  ");
            } else {
                hel_BgTextPrintF(1, 3 + (c * 3),
                        v + 2, 0, "%.2x ",
                        FAT_tracker.channels[c].sequences[v + FAT_screenLive_currentStartLine]);
            }
        }

    }
}




void FAT_screenLive_printAllScreenText() {
    FAT_screenLive_printLineColumns();
    FAT_screenLive_printSequences();
    FAT_screenLive_printInfos();
}




void FAT_screenLive_init() {
    FAT_reinitScreen();


    ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[323936]), 6112, 1, 1);
    ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[322656]), 640, 0, 0);
    ham_InitBg(3, 1, 3, 0);


    FAT_cursors_hideCursor2();
    FAT_screenLive_commitCursorMove();
    FAT_cursors_showCursor2();

    FAT_screenLive_bufferTempo = FAT_tracker.tempo;

    u8 i;
    for (i = 0;i<6;i++){
        FAT_player_moveOrHideCursor(i);
        FAT_screenLive_bufferVolume[i] = FAT_tracker.liveData.volume[i];
        FAT_screenLive_bufferTranspose[i] = FAT_tracker.liveData.transpose[i];
    }

    FAT_screenLive_printAllScreenText();
    FAT_screenLive_printVolumes();
    FAT_screenLive_printTransposes();
}






void FAT_screenLive_applyBufferIfNeeded(){
    if (FAT_screenLive_haveToApplyBuffer){
        FAT_tracker.tempo = FAT_screenLive_bufferTempo;

        u8 i;
        for (i = 0;i<6;i++){
            FAT_tracker.liveData.volume[i] = FAT_screenLive_bufferVolume[i];
            FAT_tracker.liveData.transpose[i] = FAT_screenLive_bufferTranspose[i];
        }

        FAT_screenLive_haveToApplyBuffer = 0;
        hel_BgTextPrintF(1, 21, 7, 0, "Tmpo %.3d", FAT_tracker.tempo);
    }
}





void FAT_screenLive_switchActivePart(u8 part) {
    FAT_screenLive_isCursorInSequencer = part;
    FAT_screenLive_currentTableSelectedLine = 0;
    FAT_screenLive_switchCursorToPart(part);
    FAT_screenLive_commitCursorMove();
}




void FAT_screenLive_checkButtons() {
    hel_PadCapture();

    if (((TPad*)(&__hel_Pad))->Held.Select) {
        if (!FAT_screenLive_isPopuped) {
            FAT_cursors_hideCursor2();
            FAT_popup_show();
            FAT_screenLive_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenLive_isPopuped) {
            FAT_popup_hide();
            FAT_cursors_showCursor2();
            FAT_screenLive_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != 1) {

                FAT_switchToScreen(FAT_popup_getSelectedIcon(), 1);
            }
        }

        if (((TPad*)(&__hel_Pad))->Pressed.R && ((TPad*)(&__hel_Pad))->Pressed.L) {
            FAT_showHelp(1);
        }

        if (((TPad*)(&__hel_Pad))->Pressed.A || ((TPad*)(&__hel_Pad))->Held.A) {
            if (FAT_screenLive_isCursorInSequencer){
                FAT_screenLive_pressOrHeldA_inSequencer();
            } else {
                FAT_screenLive_pressOrHeldA_inDataTable();
            }
        } else {

            FAT_screenLive_applyBufferIfNeeded ();

            if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                FAT_screenLive_moveCursorRight();
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                FAT_screenLive_moveCursorLeft();
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                if (((TPad*)(&__hel_Pad))->Held.R) {

                    FAT_screenLive_switchActivePart(0);

                } else if (((TPad*)(&__hel_Pad))->Held.L) {
                    FAT_screenLive_moveCursorAllDown();
                } else {
                    FAT_screenLive_moveCursorDown();
                }
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                if (((TPad*)(&__hel_Pad))->Held.R) {

                    FAT_screenLive_switchActivePart(1);

                } else if (((TPad*)(&__hel_Pad))->Held.L) {
                    FAT_screenLive_switchActivePart(1);
                    FAT_screenLive_moveCursorAllUp();
                } else {
                    FAT_screenLive_moveCursorUp();
                }
            }
        }

        if (((TPad*)(&__hel_Pad))->Pressed.Start) {
            if(((TPad*)(&__hel_Pad))->Held.R){

                if (!FAT_isCurrentlyPlaying) {
                    FAT_player_startPlayerFromSequences(FAT_screenLive_currentSelectedLine);
                } else {
                    FAT_player_stopPlayer();
                }
            }else {
                if (!FAT_isCurrentlyPlaying) {

                    FAT_player_startPlayerFromLive_oneChannel(FAT_screenLive_currentSelectedLine, FAT_screenLive_currentSelectedColumn);
                } else {

                    if (FAT_isChannelCurrentlyPlaying (FAT_screenLive_currentSelectedColumn)){
                        FAT_player_stopPlayer_onlyOneColumn(FAT_screenLive_currentSelectedColumn);
                    } else {

                        FAT_player_startPlayerFromLive_oneChannel(FAT_screenLive_currentSelectedLine, FAT_screenLive_currentSelectedColumn);
                    }
                }
            }
        }

        if (!FAT_tracker.bufferChangeInLive){
            FAT_screenLive_applyBufferIfNeeded();
        }

        FAT_screenLive_commitCursorMove();
    }
}

void FAT_screenLive_pressOrHeldA_inSequencer(){

}

void FAT_screenLive_pressOrHeldA_inDataTable(){

    switch (FAT_screenLive_currentTableSelectedLine){
        case 0:

            if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                if (((TPad*)(&__hel_Pad))->Pressed.L || ((TPad*)(&__hel_Pad))->Held.L){
                    FAT_screenLive_changeAllVolumes (1);
                } else{
                    FAT_screenLive_changeVolume (FAT_screenLive_currentSelectedColumn, 1);
                }
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                if (((TPad*)(&__hel_Pad))->Pressed.L || ((TPad*)(&__hel_Pad))->Held.L){
                    FAT_screenLive_changeAllVolumes (-1);
                } else{
                    FAT_screenLive_changeVolume (FAT_screenLive_currentSelectedColumn, -1);
                }

            }

            if (((TPad*)(&__hel_Pad))->Pressed.Up){
                if (((TPad*)(&__hel_Pad))->Pressed.L || ((TPad*)(&__hel_Pad))->Held.L){
                    FAT_screenLive_setAllVolumes (0xf);
                } else {
                    FAT_screenLive_changeVolume (FAT_screenLive_currentSelectedColumn, 0xff - FAT_screenLive_bufferVolume[FAT_screenLive_currentSelectedColumn]);
                }
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Down){
                if (((TPad*)(&__hel_Pad))->Pressed.L || ((TPad*)(&__hel_Pad))->Held.L){
                    FAT_screenLive_setAllVolumes (0);
                }else{
                    FAT_screenLive_changeVolume (FAT_screenLive_currentSelectedColumn, -FAT_screenLive_bufferVolume[FAT_screenLive_currentSelectedColumn]);
                }

            }

            FAT_screenLive_printVolumes();
            break;
        case 1:

            if (((TPad*)(&__hel_Pad))->Pressed.Right ) {
                if (((TPad*)(&__hel_Pad))->Pressed.L || ((TPad*)(&__hel_Pad))->Held.L){
                    FAT_screenLive_changeAllTransposes (1);
                } else {
                    FAT_screenLive_changeTranspose (FAT_screenLive_currentSelectedColumn, 1);
                }
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Left ) {
                if (((TPad*)(&__hel_Pad))->Pressed.L || ((TPad*)(&__hel_Pad))->Held.L){
                    FAT_screenLive_changeAllTransposes (-1);
                } else {
                    FAT_screenLive_changeTranspose (FAT_screenLive_currentSelectedColumn, -1);
                }
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                if (((TPad*)(&__hel_Pad))->Pressed.L || ((TPad*)(&__hel_Pad))->Held.L){
                    FAT_screenLive_changeAllTransposes (12);
                } else {
                    FAT_screenLive_changeTranspose (FAT_screenLive_currentSelectedColumn, 12);
                }
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                if (((TPad*)(&__hel_Pad))->Pressed.L || ((TPad*)(&__hel_Pad))->Held.L){
                    FAT_screenLive_changeAllTransposes (-12);
                } else {
                    FAT_screenLive_changeTranspose (FAT_screenLive_currentSelectedColumn, -12);
                }
            }

            FAT_screenLive_printTransposes();
            break;
        case 2:

            if (FAT_screenLive_currentSelectedColumn == 1){
                if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                    FAT_tracker.liveData.liveMode = 0;
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                    FAT_tracker.liveData.liveMode = 1;
                }

                FAT_screenLive_printLiveMode();
            } else if (FAT_screenLive_currentSelectedColumn == 4){
                if (((TPad*)(&__hel_Pad))->Pressed.Right && FAT_screenLive_bufferTempo < 255) {
                    FAT_screenLive_bufferTempo ++;
                    FAT_screenLive_haveToApplyBuffer = (!0);
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Left && FAT_screenLive_bufferTempo > 0x00) {
                    FAT_screenLive_bufferTempo --;
                    FAT_screenLive_haveToApplyBuffer = (!0);
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Up ) {
                    if (FAT_screenLive_bufferTempo < 255 -10){
                        FAT_screenLive_bufferTempo += 10;
                    } else {
                        FAT_screenLive_bufferTempo = 255;
                    }

                    FAT_screenLive_haveToApplyBuffer = (!0);
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                    if (FAT_screenLive_bufferTempo > 10){
                        FAT_screenLive_bufferTempo -= 10;
                    } else {
                        FAT_screenLive_bufferTempo = 0;
                    }

                    FAT_screenLive_haveToApplyBuffer = (!0);
                }

                FAT_screenLive_printTempo();
            }
            break;
    }
}

void FAT_screenLive_changeVolume (u8 channel, s8 addedValue){
    if (addedValue > 0 && FAT_screenLive_bufferVolume[channel] < 0xff){

        FAT_screenLive_bufferVolume[channel] += addedValue;

        if ( (channel != 2 && FAT_screenLive_bufferVolume[channel] > 0xf)
                            || (channel == 2 && FAT_screenLive_bufferVolume[channel] > 0x4) ){
            FAT_screenLive_bufferVolume[channel] = 0xff;
        }

        FAT_screenLive_haveToApplyBuffer = (!0);

    } else if (addedValue < 0 && FAT_screenLive_bufferVolume[channel] > 0){

        FAT_screenLive_bufferVolume[channel] += addedValue;

        if ( (channel != 2 && FAT_screenLive_bufferVolume[channel] > 0xf) ){
            FAT_screenLive_bufferVolume[channel] = 0x0f;
        } else if ((channel == 2 && FAT_screenLive_bufferVolume[channel] > 0x4)){
            FAT_screenLive_bufferVolume[channel] = 0x04;
        }

        FAT_screenLive_haveToApplyBuffer = (!0);
    }
}

void FAT_screenLive_changeTranspose (u8 channel, s8 addedValue){
    FAT_screenLive_bufferTranspose[channel] += addedValue;
    FAT_screenLive_haveToApplyBuffer = (!0);
}

void FAT_screenLive_changeAllVolumes (s8 addedValue){
    u8 i;
    for (i = 0; i < 6; i++){
        FAT_screenLive_changeVolume (i, addedValue);
    }
}

void FAT_screenLive_changeAllTransposes (s8 addedValue){
    u8 i;
    for (i = 0; i < 6; i++){
        FAT_screenLive_changeTranspose (i, addedValue);
    }
}

void FAT_screenLive_setAllVolumes (u8 value){
    u8 i;
    for (i = 0; i < 6; i++){
        FAT_screenLive_bufferVolume[i] = value;
        if (i == 2){
            if (FAT_screenLive_bufferVolume[i] > 0x4){
                FAT_screenLive_bufferVolume[i] = 0x04;
            }
        }
    }
    FAT_screenLive_haveToApplyBuffer = (!0);
}
# 132 "src/headers/fat.h" 2
# 1 "src/headers/screen_composer.h" 1
# 57 "src/headers/screen_composer.h"
u8 FAT_screenComposer_isPopuped = 0;

u8 FAT_screenComposer_isLocked = 0;


void FAT_screenComposer_init();
void FAT_screenComposer_checkButtons();
void FAT_screenComposer_printInfos();
void FAT_screenComposer_printAllScreenText();
void FAT_screenComposer_printColumns();
void FAT_screenComposer_pressOrHeldA();
void FAT_screenComposer_pressB();
void FAT_screenComposer_switchLocking();
void FAT_screenComposer_playAffectedNotes();

# 1 "src/headers/screen_composer_cursor.h" 1
# 20 "src/headers/screen_composer_cursor.h"
# 1 "src/headers/screen_composer.h" 1
# 21 "src/headers/screen_composer_cursor.h" 2


u8 FAT_screenComposer_cursorX;

u8 FAT_screenComposer_cursorY;

u8 FAT_screenComposer_currentSelectedLine;

u8 FAT_screenComposer_currentSelectedColumn;
# 54 "src/headers/screen_composer_cursor.h"
void FAT_screenComposer_initCursor();
void FAT_screenComposer_moveCursorRight();
void FAT_screenComposer_moveCursorLeft();
void FAT_screenComposer_moveCursorDown();
void FAT_screenComposer_moveCursorUp();
void FAT_screenComposer_commitCursorMove();

const u8 screenComposer_parametersCursorsPositions [2] = {23, 31};




void FAT_screenComposer_initCursor() {
    FAT_screenComposer_cursorX = 80 - 1;
    FAT_screenComposer_cursorY = 56 - 1;

    FAT_screenComposer_currentSelectedLine = 2;
    FAT_screenComposer_currentSelectedColumn = 0;
}




void FAT_screenComposer_commitCursorMove() {
    if (FAT_screenComposer_currentSelectedLine < 2) {

        do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((95)&511) << 16) | (((FAT_screenComposer_cursorY)&255)); } while(0);
    } else {

        if (FAT_screenComposer_currentSelectedColumn == 0) {
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenComposer_cursorX)&511) << 16) | (((FAT_screenComposer_cursorY)&255)); } while(0);
        } else if (FAT_screenComposer_currentSelectedColumn == 4) {
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor1_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenComposer_cursorX)&511) << 16) | (((FAT_screenComposer_cursorY)&255)); } while(0);
        } else {
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenComposer_cursorX)&511) << 16) | (((FAT_screenComposer_cursorY)&255)); } while(0);
        }
    }
}






void FAT_screenComposer_moveCursorDown() {
    if (FAT_screenComposer_currentSelectedLine < 8 + 2) {
        if (FAT_screenComposer_currentSelectedLine >= 1) {
            if (FAT_screenComposer_currentSelectedLine == 1
                    && FAT_screenComposer_currentSelectedColumn == 0) {
                FAT_cursors_hideCursor2();
                FAT_cursors_showCursor3();
            }

            if (!(FAT_screenComposer_cursorY >= 111 - 1)) {
                FAT_screenComposer_currentSelectedLine++;
            } else {
                FAT_screenComposer_currentSelectedLine = 2;
            }
            FAT_screenComposer_cursorY =
                    (56 - 1) +
                    ((FAT_screenComposer_currentSelectedLine - 2) * 8);
            FAT_screenComposer_printInfos();
        } else {

            if (FAT_screenComposer_currentSelectedLine < 2) {
                FAT_screenComposer_currentSelectedLine++;
                FAT_screenComposer_printInfos();
                FAT_screenComposer_cursorY =
                        screenComposer_parametersCursorsPositions[FAT_screenComposer_currentSelectedLine];

                if (FAT_screenComposer_currentSelectedLine < 2) {
                    FAT_cursors_hideCursor3();
                    FAT_cursors_showCursor2();
                } else {
                    FAT_cursors_hideCursor2();
                    FAT_cursors_showCursor3();
                }
            }

        }
    }
}






void FAT_screenComposer_moveCursorUp() {

    if (FAT_screenComposer_currentSelectedLine > 2) {
        if (!(FAT_screenComposer_cursorY <= 56 - 1)) {
            FAT_screenComposer_cursorY -= 8;
            FAT_screenComposer_currentSelectedLine--;
            FAT_screenComposer_printInfos();
        }
    } else {

        if (FAT_screenComposer_currentSelectedLine > 0) {
            FAT_screenComposer_currentSelectedLine--;
            FAT_screenComposer_printInfos();
            FAT_screenComposer_cursorY =
                    screenComposer_parametersCursorsPositions[FAT_screenComposer_currentSelectedLine];
            FAT_cursors_hideCursor3();
            FAT_cursors_showCursor2();
        } else {
            FAT_screenComposer_currentSelectedLine = 8 + 2 - 1;
            FAT_screenComposer_cursorY = (56 - 1) +
                                ((FAT_screenComposer_currentSelectedLine - 2) * 8);
            FAT_screenComposer_printInfos();
            FAT_cursors_hideCursor2();
            FAT_cursors_showCursor3();
        }
    }

}






void FAT_screenComposer_moveCursorRight() {
    if (FAT_screenComposer_currentSelectedLine >= 2) {
        if (FAT_screenComposer_currentSelectedColumn == 0) {

            FAT_screenComposer_cursorX += 24 + 8;
            FAT_screenComposer_currentSelectedColumn = 1;
            FAT_cursors_hideCursor3();
            FAT_cursors_showCursor2();

        } else if (FAT_screenComposer_currentSelectedColumn == 1) {

            FAT_screenComposer_cursorX += 16 + 8;
            FAT_screenComposer_currentSelectedColumn = 2;

        } else if (FAT_screenComposer_currentSelectedColumn == 2) {

            FAT_screenComposer_cursorX += 16;
            FAT_screenComposer_currentSelectedColumn = 3;
        } else if (FAT_screenComposer_currentSelectedColumn == 3) {
            FAT_screenComposer_cursorX += 16 + 8;
            FAT_screenComposer_currentSelectedColumn = 4;
            FAT_cursors_hideCursor2();
            FAT_cursors_showCursor1();
        }
    }

}






void FAT_screenComposer_moveCursorLeft() {
    if (FAT_screenComposer_currentSelectedLine >= 2) {
        if (FAT_screenComposer_currentSelectedColumn == 1) {

            FAT_screenComposer_cursorX -= 24 + 8;
            FAT_screenComposer_currentSelectedColumn = 0;
            FAT_cursors_hideCursor2();
            FAT_cursors_showCursor3();

        } else if (FAT_screenComposer_currentSelectedColumn == 2) {

            FAT_screenComposer_cursorX -= 16 + 8;
            FAT_screenComposer_currentSelectedColumn = 1;

        } else if (FAT_screenComposer_currentSelectedColumn == 3) {
            FAT_screenComposer_cursorX -= 16;
            FAT_screenComposer_currentSelectedColumn = 2;

        } else if (FAT_screenComposer_currentSelectedColumn == 4) {

            FAT_screenComposer_cursorX -= 16 + 8;
            FAT_screenComposer_currentSelectedColumn = 3;
            FAT_cursors_hideCursor1();
            FAT_cursors_showCursor2();
        }
    }
}
# 73 "src/headers/screen_composer.h" 2




void FAT_screenComposer_printInfos() {
    hel_BgTextPrintF(1, 18, 3, 0, "Composer  %.1x", 0);
    hel_BgTextPrintF(1, 18, 4, 0, "Line     %.2x",
            FAT_screenComposer_currentSelectedLine);

    hel_BgTextPrintF(1, 1, 3, 0, "Transpose  %.2x", FAT_tracker.composer.transpose);
    hel_BgTextPrintF(1, 1, 4, 0, "Key Repeat %.2x", FAT_tracker.composer.keyRepeat);
}






void FAT_screenComposer_printNote(u8 line) {
    if (!FAT_data_composer_isNoteEmpty(line)) {
        note* actualNote = FAT_data_composer_getNote(line);

        if (FAT_data_composer_getChannel(line) > 3) {

            hel_BgTextPrintF(1, 10,
                    line + 7, 0,
                    "S%.2x %.2x      %.1x\0",
                    actualNote->freq, actualNote->instrument,
                    FAT_tracker.composer.channels[line] + 1
                    );

        } else {

            hel_BgTextPrintF(1, 10,
                    line + 7, 0,
                    "%s%1x %.2x      %.1x\0",
                    noteName[(actualNote->note & 0xf0) >> 4], actualNote->note & 0x0f, actualNote->instrument,
                    FAT_tracker.composer.channels[line] + 1
                    );
        }
    } else {
        hel_BgTextPrint(1, 10,
                line + 7, 0, "             ");
    }
}




void FAT_screenComposer_printAllNote() {
    u8 b;
    for (b = 0; b < 8; b++) {
        FAT_screenComposer_printNote(b);
    }
}





void FAT_screenComposer_printLocking() {
    if (FAT_screenComposer_isLocked) {
        hel_BgTextPrint(1, 7, 16, 0, "MODE   LOCKED");
    } else {
        hel_BgTextPrint(1, 7, 16, 0, "MODE UNLOCKED");
    }
}




void FAT_screenComposer_printAllScreenText() {
    FAT_screenComposer_printInfos();
    FAT_screenComposer_printAllNote();
}




void FAT_screenComposer_printColumns() {
    hel_BgTextPrint(1, 7, 7, 0, " L");
    hel_BgTextPrint(1, 7, 8, 0, " R");
    hel_BgTextPrint(1, 7, 9, 0, " A");
    hel_BgTextPrint(1, 7, 10, 0, " B");
    hel_BgTextPrint(1, 7, 11, 0, "UP");
    hel_BgTextPrint(1, 7, 12, 0, "RT");
    hel_BgTextPrint(1, 7, 13, 0, "DW");
    hel_BgTextPrint(1, 7, 14, 0, "LF");
}




void FAT_screenComposer_init() {
    FAT_reinitScreen();


    ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[45728]), 5184, 1, 1);
    ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[44448]), 640, 0, 0);
    ham_InitBg(3, 1, 3, 0);

    FAT_screenComposer_isLocked = 0;


    FAT_screenComposer_printColumns();
    FAT_screenComposer_printAllScreenText();
    FAT_screenComposer_printLocking();





    FAT_player_hideAllCursors ();
    FAT_cursors_hideCursor2();
    FAT_cursors_hideCursor3();
    FAT_cursors_hideCursor1();
    if (FAT_screenComposer_currentSelectedColumn == 0 && FAT_screenComposer_currentSelectedLine > 1) {
        FAT_cursors_showCursor3();
    } else if (FAT_screenComposer_currentSelectedColumn == 4 && FAT_screenComposer_currentSelectedLine > 1) {
        FAT_cursors_showCursor1();
    } else {
        FAT_cursors_showCursor2();
    }
    FAT_screenComposer_commitCursorMove();
}




void FAT_screenComposer_checkButtons() {
    hel_PadCapture();

    if ( FAT_isCurrentlySimulating == 1 && !FAT_isCurrentlyPlaying && (
                        ((TPad*)(&__hel_Pad))->Pressed.Start ||
                        ((TPad*)(&__hel_Pad))->Pressed.Select ||
                        ((TPad*)(&__hel_Pad))->Pressed.A ||
                        ((TPad*)(&__hel_Pad))->Pressed.B ||
                        ((TPad*)(&__hel_Pad))->Pressed.Up ||
                        ((TPad*)(&__hel_Pad))->Pressed.Down ||
                        ((TPad*)(&__hel_Pad))->Pressed.Right ||
                        ((TPad*)(&__hel_Pad))->Pressed.Left ||
                        ((TPad*)(&__hel_Pad))->Pressed.R ||
                        ((TPad*)(&__hel_Pad))->Pressed.L)
                        ) {
        FAT_player_stopPlayer();
        FAT_data_instrument_setCurrentlySimulating (0);
    }

    if (((TPad*)(&__hel_Pad))->Held.Select) {
        if (!FAT_screenComposer_isPopuped) {
            FAT_cursors_hideCursor3();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor1();
            FAT_popup_show();
            FAT_screenComposer_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenComposer_isPopuped) {
            FAT_popup_hide();
            if (!FAT_screenComposer_isLocked) {
                if (FAT_screenComposer_currentSelectedColumn == 0) {
                    FAT_cursors_showCursor3();
                } else if (FAT_screenComposer_currentSelectedColumn == 4) {
                    FAT_cursors_showCursor1();
                } else {
                    FAT_cursors_showCursor2();
                }

            }
            FAT_screenComposer_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != 2) {
                FAT_cursors_hideCursor3();
                FAT_cursors_hideCursor2();
                FAT_cursors_hideCursor1();
                FAT_switchToScreen(FAT_popup_getSelectedIcon(), 2);
            }
        }

        if (FAT_screenComposer_isLocked) {

            FAT_screenComposer_playAffectedNotes();

        } else {
            if (((TPad*)(&__hel_Pad))->Held.A || ((TPad*)(&__hel_Pad))->Pressed.A) {
                FAT_screenComposer_pressOrHeldA();
            } else {

                if (((TPad*)(&__hel_Pad))->Pressed.B) {
                    FAT_screenComposer_pressB();
                }

                if (((TPad*)(&__hel_Pad))->Pressed.R && ((TPad*)(&__hel_Pad))->Pressed.L) {
                    FAT_showHelp(2);
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Start) {

                    FAT_screenComposer_switchLocking();
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                    FAT_screenComposer_moveCursorRight();
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                    FAT_screenComposer_moveCursorLeft();
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                    FAT_screenComposer_moveCursorDown();
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                    FAT_screenComposer_moveCursorUp();

                }
                FAT_screenComposer_commitCursorMove();
            }

        }
    }
}




void FAT_screenComposer_pressOrHeldA() {

    if (FAT_screenComposer_currentSelectedLine >= 2) {
        u8 realLine = FAT_screenComposer_currentSelectedLine - 2;
        switch (FAT_screenComposer_currentSelectedColumn) {
            case 0:
                if (FAT_data_composer_isNoteEmpty(realLine)) {

                    FAT_data_composer_addDefaultNote(realLine);
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                    FAT_data_composer_changeValue(realLine, 1);

                    if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                        FAT_data_composer_previewNote(realLine);
                    }
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                    FAT_data_composer_changeValue(realLine, -1);

                    if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                        FAT_data_composer_previewNote(realLine);
                    }
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                                        if (FAT_data_composer_getChannel(realLine) <= 3){
                        FAT_data_composer_changeOctave(realLine, 1);
                        if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                            FAT_data_composer_previewNote(realLine);
                        }
                                        }
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                                        if (FAT_data_composer_getChannel(realLine) <= 3) {
                        FAT_data_composer_changeOctave(realLine, -1);
                        if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                            FAT_data_composer_previewNote(realLine);
                        }
                                        }
                }

                if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying && ((TPad*)(&__hel_Pad))->Pressed.A) {
                    FAT_data_composer_previewNote(realLine);
                }

                break;
            case 1:
                if (((TPad*)(&__hel_Pad))->Held.L) {
                    FAT_data_composer_smartChangeInstrument(realLine);
                } else {

                    if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                        FAT_data_composer_changeInstrument(realLine, 1);
                    }

                    if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                        FAT_data_composer_changeInstrument(realLine, -1);
                    }

                    if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                        FAT_data_composer_changeInstrument(realLine, 16);
                    }

                    if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                        FAT_data_composer_changeInstrument(realLine, -16);
                    }

                    if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying && ((TPad*)(&__hel_Pad))->Pressed.A) {
                        FAT_data_composer_previewNote(realLine);
                    }
                }
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                if (((TPad*)(&__hel_Pad))->Held.L) {
                    FAT_data_composer_resetAffectedChannel(realLine);
                } else {

                    if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                        FAT_data_composer_changeAffectedChannelValue(realLine, 1);
                    }

                    if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                        FAT_data_composer_changeAffectedChannelValue(realLine, -1);
                    }
                }

                if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying && ((TPad*)(&__hel_Pad))->Pressed.A) {
                    FAT_data_composer_previewNote(realLine);
                }

                break;

        }

        FAT_screenComposer_printNote(realLine);
    } else {

        switch (FAT_screenComposer_currentSelectedLine) {
            case 0:
                if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                    FAT_data_composer_changeTranspose(0, 1);
                }
                if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                    FAT_data_composer_changeTranspose(0, 16);
                }
                if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                    FAT_data_composer_changeTranspose(0, -1);
                }
                if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                    FAT_data_composer_changeTranspose(0, -16);
                }
                break;
            case 1:
                if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                    FAT_data_composer_changeKeyRepeat(0, 1);
                }
                if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                    FAT_data_composer_changeKeyRepeat(0, 16);
                }
                if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                    FAT_data_composer_changeKeyRepeat(0, -1);
                }
                if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                    FAT_data_composer_changeKeyRepeat(0, -16);
                }
                break;
        }

        FAT_screenComposer_printInfos();
    }
}




void FAT_screenComposer_pressB() {
    if (FAT_screenComposer_currentSelectedLine >= 2) {
        u8 realLine = FAT_screenComposer_currentSelectedLine - 2;
        if (FAT_data_composer_isNoteEmpty(realLine)) {
            FAT_data_composer_pasteNote(realLine);
        } else {
            FAT_data_composer_cutNote(realLine);
        }

        FAT_screenComposer_printNote(realLine);
    }
}




void FAT_screenComposer_switchLocking() {
    FAT_screenComposer_isLocked ^= 1;
    FAT_screenComposer_printLocking();

    if (FAT_screenComposer_isLocked) {
        FAT_cursors_hideCursor2();
        FAT_cursors_hideCursor3();
        FAT_cursors_hideCursor1();
    } else {
        if (FAT_screenComposer_currentSelectedColumn == 0) {
            FAT_cursors_showCursor3();
        } else if (FAT_screenComposer_currentSelectedColumn == 4) {
            FAT_cursors_showCursor1();
        } else {
            FAT_cursors_showCursor2();
        }
    }
}





void FAT_screenComposer_playAffectedNotes() {
    if (((TPad*)(&__hel_Pad))->Pressed.Start) {
        FAT_screenComposer_switchLocking();
    }

    if (((TPad*)(&__hel_Pad))->Pressed.A) {
        FAT_player_playComposerNote(2);
    }

    if (((TPad*)(&__hel_Pad))->Pressed.B) {
        FAT_player_playComposerNote(3);
    }

    if (((TPad*)(&__hel_Pad))->Pressed.R) {
        FAT_player_playComposerNote(1);
    }

    if (((TPad*)(&__hel_Pad))->Pressed.L) {
        FAT_player_playComposerNote(0);
    }

    if (((TPad*)(&__hel_Pad))->Pressed.Up) {
        FAT_player_playComposerNote(4);
    }

    if (((TPad*)(&__hel_Pad))->Pressed.Right) {
        FAT_player_playComposerNote(5);
    }

    if (((TPad*)(&__hel_Pad))->Pressed.Down) {
        FAT_player_playComposerNote(6);
    }

    if (((TPad*)(&__hel_Pad))->Pressed.Left) {
        FAT_player_playComposerNote(7);
    }
}
# 133 "src/headers/fat.h" 2
# 1 "src/headers/screen_blocks.h" 1
# 48 "src/headers/screen_blocks.h"
u8 FAT_screenBlocks_isPopuped = 0;




u8 FAT_screenBlocks_currentSequenceId = 0xff;


void FAT_screenBlocks_init(u8 fromScreenId);
void FAT_screenBlocks_checkButtons();
void FAT_screenBlocks_printInfos();
void FAT_screenBlocks_pressOrHeldA();
void FAT_screenBlocks_pressB();

# 1 "src/headers/screen_blocks_cursor.h" 1
# 21 "src/headers/screen_blocks_cursor.h"
u8 FAT_screenBlocks_cursorX;

u8 FAT_screenBlocks_cursorY;




u8 FAT_screenBlocks_currentSelectedLine;



u8 FAT_screenBlocks_currentSelectedColumn;
# 53 "src/headers/screen_blocks_cursor.h"
void FAT_screenBlocks_initCursor();
void FAT_screenBlocks_moveCursorRight();
void FAT_screenBlocks_moveCursorLeft();
void FAT_screenBlocks_moveCursorDown();
void FAT_screenBlocks_moveCursorUp();
void FAT_screenBlocks_commitCursorMove();




void FAT_screenBlocks_initCursor() {
    FAT_screenBlocks_cursorX = 24 - 1;
    FAT_screenBlocks_cursorY = 16 - 1;

    FAT_screenBlocks_currentSelectedLine = 0;
    FAT_screenBlocks_currentSelectedColumn = 0;
}




void FAT_screenBlocks_commitCursorMove() {
    do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenBlocks_cursorX)&511) << 16) | (((FAT_screenBlocks_cursorY)&255)); } while(0);
}






void FAT_screenBlocks_moveCursorDown() {
    if (FAT_screenBlocks_currentSelectedLine < 16 - 1) {
        if (!(FAT_screenBlocks_cursorY >= 135 - 1)) {
            FAT_screenBlocks_cursorY += 8;
            FAT_screenBlocks_currentSelectedLine++;
            FAT_screenBlocks_printInfos();
        }
    } else {
        FAT_screenBlocks_cursorY = 16 - 1;
        FAT_screenBlocks_currentSelectedLine = 0;
        FAT_screenBlocks_printInfos();
    }
}






void FAT_screenBlocks_moveCursorUp() {

    if (FAT_screenBlocks_currentSelectedLine > 0) {
        if (!(FAT_screenBlocks_cursorY <= 16 - 1)) {
            FAT_screenBlocks_cursorY -= 8;
            FAT_screenBlocks_currentSelectedLine--;
            FAT_screenBlocks_printInfos();
        }
    } else {
        FAT_screenBlocks_currentSelectedLine = 16 - 1;
        FAT_screenBlocks_cursorY = (16 - 1) + (8 * 15);
        FAT_screenBlocks_printInfos();
    }

}






void FAT_screenBlocks_moveCursorAllUp (){
    FAT_screenBlocks_currentSelectedLine = 0;
    FAT_screenBlocks_cursorY = 16 - 1;
    FAT_screenBlocks_printInfos();
}






void FAT_screenBlocks_moveCursorAllDown (){
    FAT_screenBlocks_currentSelectedLine = 16 - 1;
    FAT_screenBlocks_cursorY = 135;
    FAT_screenBlocks_printInfos();
}






void FAT_screenBlocks_moveCursorRight(){

    if (FAT_screenBlocks_currentSelectedColumn == 0){

        FAT_screenBlocks_cursorX += 16 + 8;
        FAT_screenBlocks_currentSelectedColumn = 1;

    } else if (FAT_screenBlocks_currentSelectedColumn == 1){

        FAT_screenBlocks_cursorX += 16 + 8;
        FAT_screenBlocks_currentSelectedColumn = 2;

    } else if (FAT_screenBlocks_currentSelectedColumn == 2){

        FAT_screenBlocks_cursorX += 16;
        FAT_screenBlocks_currentSelectedColumn = 3;
    }

}






void FAT_screenBlocks_moveCursorLeft(){
    if (FAT_screenBlocks_currentSelectedColumn == 1){

        FAT_screenBlocks_cursorX -= 16 + 8;
        FAT_screenBlocks_currentSelectedColumn = 0;

    } else if (FAT_screenBlocks_currentSelectedColumn == 2){

        FAT_screenBlocks_cursorX -= 16 + 8;
        FAT_screenBlocks_currentSelectedColumn = 1;

    } else if (FAT_screenBlocks_currentSelectedColumn == 3){
        FAT_screenBlocks_cursorX -= 16;
        FAT_screenBlocks_currentSelectedColumn = 2;
    }
}
# 63 "src/headers/screen_blocks.h" 2




void FAT_screenBlocks_printLineColumns() {
    u8 y = 2;
    int c;
    for (c = 0; c < (16); c++) {
        hel_BgTextPrintF(1, 0, y, 0, "%.2x", c);
        y += 1;
    }
}







void FAT_screenBlocks_printInfos() {
    hel_BgTextPrintF(1, 18, 4, 0, "Line     %.2x", FAT_screenBlocks_currentSelectedLine);
}







void FAT_screenBlocks_printSequenceNumber() {
    hel_BgTextPrintF(1, 18, 3, 0, "Sequence %.2x", FAT_screenBlocks_currentSequenceId);
}






void FAT_screenBlocks_printBlock(u8 line) {
    if (FAT_data_getBlock(FAT_screenBlocks_currentSequenceId, line) != 0xff) {
        hel_BgTextPrintF(1, 3,
                line + 2, 0,
                "%.2x\0", FAT_data_getBlock(FAT_screenBlocks_currentSequenceId, line));
    } else {
        hel_BgTextPrint(1, 3,
                line + 2, 0, "  ");
    }
}






void FAT_screenBlocks_printTranspose(u8 line) {
    if (!FAT_data_block_isTransposeEmpty(FAT_screenBlocks_currentSequenceId, line)) {
        hel_BgTextPrintF(1, 6, line + 2, 0,
                "%.2x\0", FAT_data_block_getTranspose(FAT_screenBlocks_currentSequenceId, line));
    } else {
        hel_BgTextPrint(1, 6, line + 2, 0,
                "00");
    }
}






void FAT_screenBlocks_printEffect(u8 line) {
    if (!FAT_data_block_isEffectEmpty(FAT_screenBlocks_currentSequenceId, line)) {

        effect* effect = FAT_data_block_getEffect(FAT_screenBlocks_currentSequenceId, line);

        hel_BgTextPrintF(1, 8, line + 2, 0,
                "%s%.2x\0", blockEffectName[(effect->name & 0xfe) >> 1], effect->value);
    } else {
        hel_BgTextPrint(1, 8, line + 2, 0,
                "    ");
    }
}




void FAT_screenBlocks_printAllBlocks() {
    u8 b;
    for (b = 0; b < 16; b++) {
        FAT_screenBlocks_printBlock(b);
        FAT_screenBlocks_printTranspose(b);
        FAT_screenBlocks_printEffect(b);
    }
}




void FAT_screenBlocks_printAllScreenText() {
    FAT_screenBlocks_printLineColumns();
    FAT_screenBlocks_printAllBlocks();

    FAT_screenBlocks_printInfos();
    hel_BgTextPrintF(1, 18, 6, 0, "Tsp-Proj %2.x\nTempo   %.3d", FAT_tracker.transpose, FAT_tracker.tempo);
}







void FAT_screenBlocks_init(u8 fromScreenId) {
    FAT_reinitScreen();


    ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[32992]), 5728, 1, 1);
    ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[31712]), 640, 0, 0);
    ham_InitBg(3, 1, 3, 0);



    switch (fromScreenId){
        case 3:
            FAT_screenBlocks_currentSequenceId = FAT_data_getSequence(FAT_screenSong_currentSelectedColumn, FAT_screenSong_currentSelectedLine);
            break;
        case 1:
            FAT_screenBlocks_currentSequenceId = FAT_data_getSequence(FAT_screenLive_currentSelectedColumn, FAT_screenLive_currentSelectedLine);
            break;
    }
    if (FAT_screenBlocks_currentSequenceId == 0xff) {
        FAT_screenBlocks_currentSequenceId = 0;
    }
    FAT_screenBlocks_printSequenceNumber();
    FAT_screenBlocks_printAllScreenText();


    FAT_player_hideAllCursors ();
    FAT_cursors_hideCursor2();
    FAT_screenBlocks_commitCursorMove();
    FAT_cursors_showCursor2();
    FAT_cursors_moveCursorChange(216, 24);
}






void FAT_screenBlocks_checkButtons() {
    hel_PadCapture();

    if (((TPad*)(&__hel_Pad))->Held.Select) {
        if (!FAT_screenBlocks_isPopuped) {
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursorChange();
            FAT_popup_show();
            FAT_screenBlocks_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenBlocks_isPopuped) {
            FAT_popup_hide();
            FAT_cursors_showCursor2();
            FAT_screenBlocks_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != 4) {
                FAT_cursors_hideCursor2();
                FAT_switchToScreen(FAT_popup_getSelectedIcon(), 4);
            }
        }

        if (((TPad*)(&__hel_Pad))->Held.A || ((TPad*)(&__hel_Pad))->Pressed.A) {

            FAT_screenBlocks_pressOrHeldA();

        } else {

            if (((TPad*)(&__hel_Pad))->Held.R) {
                FAT_cursors_showCursorChange();

                if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                    if (FAT_screenBlocks_currentSequenceId < 64 - 1) {
                        FAT_screenBlocks_currentSequenceId++;
                        FAT_screenBlocks_printSequenceNumber();
                        FAT_screenBlocks_printAllScreenText();
                    }
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                    if (FAT_screenBlocks_currentSequenceId > 0) {
                        FAT_screenBlocks_currentSequenceId--;
                        FAT_screenBlocks_printSequenceNumber();
                        FAT_screenBlocks_printAllScreenText();
                    }
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Down) {

                }

                if (((TPad*)(&__hel_Pad))->Pressed.Up) {

                }

            } else {
                FAT_cursors_hideCursorChange();

                if (((TPad*)(&__hel_Pad))->Pressed.Start) {
                    if (!FAT_isCurrentlyPlaying) {
                        FAT_player_startPlayerFromBlocks(FAT_screenBlocks_currentSequenceId,
                                FAT_screenBlocks_currentSelectedLine, FAT_screenSong_currentSelectedColumn);
                    } else {
                        FAT_player_stopPlayer();
                    }
                }

                if (((TPad*)(&__hel_Pad))->Pressed.B) {
                    FAT_screenBlocks_pressB();
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                    FAT_screenBlocks_moveCursorRight();
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                    FAT_screenBlocks_moveCursorLeft();
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                    if (((TPad*)(&__hel_Pad))->Held.L) {
                        FAT_screenBlocks_moveCursorAllDown();
                    } else {
                        FAT_screenBlocks_moveCursorDown();
                    }

                }

                if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                    if (((TPad*)(&__hel_Pad))->Held.L) {
                        FAT_screenBlocks_moveCursorAllUp();
                    } else {
                        FAT_screenBlocks_moveCursorUp();
                    }
                }

                FAT_screenBlocks_commitCursorMove();
            }

            if (((TPad*)(&__hel_Pad))->Pressed.R && ((TPad*)(&__hel_Pad))->Pressed.L) {
                FAT_showHelp(4);
            }

        }
    }

}




void FAT_screenBlocks_pressB() {
    switch (FAT_screenBlocks_currentSelectedColumn) {
        case 0:
            if (((TPad*)(&__hel_Pad))->Held.L) {
                if (FAT_data_isBlockAllocatable(FAT_screenBlocks_currentSequenceId,
                        FAT_screenBlocks_currentSelectedLine)) {

                    FAT_data_pasteBlockWithNewNumber(FAT_screenBlocks_currentSequenceId,
                            FAT_screenBlocks_currentSelectedLine);
                } else {
                    FAT_data_cloneBlock(FAT_screenBlocks_currentSequenceId,
                            FAT_screenBlocks_currentSelectedLine);
                }

            } else {
                if (FAT_data_isBlockAllocatable(FAT_screenBlocks_currentSequenceId,
                        FAT_screenBlocks_currentSelectedLine)) {

                    FAT_data_pasteBlock(FAT_screenBlocks_currentSequenceId,
                            FAT_screenBlocks_currentSelectedLine);
                } else {
                    FAT_data_cutBlock(FAT_screenBlocks_currentSequenceId,
                            FAT_screenBlocks_currentSelectedLine);
                }

            }

            FAT_screenBlocks_printBlock(FAT_screenBlocks_currentSelectedLine);
            break;
        case 1:
            FAT_data_removeBlockTranspose(FAT_screenBlocks_currentSequenceId,
                    FAT_screenBlocks_currentSelectedLine);

            FAT_screenBlocks_printTranspose(FAT_screenBlocks_currentSelectedLine);
            break;
    }
}




void FAT_screenBlocks_pressOrHeldA() {
    switch (FAT_screenBlocks_currentSelectedColumn) {
        case 0:

            if (((TPad*)(&__hel_Pad))->Pressed.L) {
                FAT_data_smartAllocateBlock(FAT_screenBlocks_currentSequenceId,
                        FAT_screenBlocks_currentSelectedLine);
            } else {
                FAT_data_allocateBlock(FAT_screenBlocks_currentSequenceId,
                        FAT_screenBlocks_currentSelectedLine);
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                FAT_data_block_changeValue(FAT_screenBlocks_currentSequenceId,
                        FAT_screenBlocks_currentSelectedLine, 1);
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                FAT_data_block_changeValue(FAT_screenBlocks_currentSequenceId,
                        FAT_screenBlocks_currentSelectedLine, -1);
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                FAT_data_block_changeValue(FAT_screenBlocks_currentSequenceId,
                        FAT_screenBlocks_currentSelectedLine, 16);
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                FAT_data_block_changeValue(FAT_screenBlocks_currentSequenceId,
                        FAT_screenBlocks_currentSelectedLine, -16);
            }

            FAT_screenBlocks_printBlock(FAT_screenBlocks_currentSelectedLine);
            break;

        case 1:
            FAT_data_block_allocateTranspose(FAT_screenBlocks_currentSequenceId,
                    FAT_screenBlocks_currentSelectedLine);

            if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                FAT_data_block_changeTransposeValue(FAT_screenBlocks_currentSequenceId,
                        FAT_screenBlocks_currentSelectedLine, -1);
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                FAT_data_block_changeTransposeValue(FAT_screenBlocks_currentSequenceId,
                        FAT_screenBlocks_currentSelectedLine, 1);
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                FAT_data_block_changeTransposeValue(FAT_screenBlocks_currentSequenceId,
                        FAT_screenBlocks_currentSelectedLine, -16);
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                FAT_data_block_changeTransposeValue(FAT_screenBlocks_currentSequenceId,
                        FAT_screenBlocks_currentSelectedLine, 16);
            }

            FAT_screenBlocks_printTranspose(FAT_screenBlocks_currentSelectedLine);
            break;

    }
}
# 134 "src/headers/fat.h" 2
# 1 "src/headers/screen_notes.h" 1
# 44 "src/headers/screen_notes.h"
void FAT_screenNotes_init(u8 fromScreenId);
void FAT_screenNotes_checkButtons();
void FAT_screenNotes_printLineColumns();
void FAT_screenNotes_pressOrHeldA();
void FAT_screenNotes_pressB();
void FAT_screenNotes_printInfos();


u8 FAT_screenNotes_isPopuped = 0;

u8 FAT_screenNotes_currentBlockId = 0xff;

# 1 "src/headers/screen_notes_cursor.h" 1
# 21 "src/headers/screen_notes_cursor.h"
u8 FAT_screenNotes_cursorX;

u8 FAT_screenNotes_cursorY;

u8 FAT_screenNotes_currentSelectedLine;

u8 FAT_screenNotes_currentSelectedColumn;
# 49 "src/headers/screen_notes_cursor.h"
void FAT_screenNotes_initCursor();
void FAT_screenNotes_moveCursorRight();
void FAT_screenNotes_moveCursorLeft();
void FAT_screenNotes_moveCursorDown();
void FAT_screenNotes_moveCursorUp();
void FAT_screenNotes_commitCursorMove();





void FAT_screenNotes_initCursor() {
    FAT_screenNotes_cursorX = 24 - 1;
    FAT_screenNotes_cursorY = 16 - 1;

    FAT_screenNotes_currentSelectedLine = 0;
    FAT_screenNotes_currentSelectedColumn = 0;
}




void FAT_screenNotes_commitCursorMove() {
    if (FAT_screenNotes_currentSelectedColumn == 0) {
        do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenNotes_cursorX)&511) << 16) | (((FAT_screenNotes_cursorY)&255)); } while(0);
    } else {
        do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenNotes_cursorX)&511) << 16) | (((FAT_screenNotes_cursorY)&255)); } while(0);
    }
}




void FAT_screenNotes_moveCursorDown() {
    if (FAT_screenNotes_currentSelectedLine < 16 - 1) {
        if (!(FAT_screenNotes_cursorY >= 135 - 1)) {
            FAT_screenNotes_cursorY += 8;
            FAT_screenNotes_currentSelectedLine++;
            FAT_screenNotes_printInfos();
        }
    } else {
        FAT_screenNotes_currentSelectedLine = 0;
        FAT_screenNotes_cursorY = (16 - 1);
        FAT_screenNotes_printInfos();
    }
}




void FAT_screenNotes_moveCursorUp() {

    if (FAT_screenNotes_currentSelectedLine > 0) {
        if (!(FAT_screenNotes_cursorY <= 16 - 1)) {
            FAT_screenNotes_cursorY -= 8;
            FAT_screenNotes_currentSelectedLine--;
            FAT_screenNotes_printInfos();
        }
    } else {
        FAT_screenNotes_currentSelectedLine = 16 - 1;
        FAT_screenNotes_cursorY = (16 - 1) + (8 * 15);
        FAT_screenNotes_printInfos();
    }

}




void FAT_screenNotes_moveCursorRight(){

    if (FAT_screenNotes_currentSelectedColumn == 0){

        FAT_screenNotes_cursorX += 24 + 8;
        FAT_screenNotes_currentSelectedColumn = 1;
        FAT_cursors_hideCursor3();
        FAT_cursors_showCursor2();

    } else if (FAT_screenNotes_currentSelectedColumn == 1){

        FAT_screenNotes_cursorX += 16 + 8;
        FAT_screenNotes_currentSelectedColumn = 2;

    } else if (FAT_screenNotes_currentSelectedColumn == 2){

        FAT_screenNotes_cursorX += 16;
        FAT_screenNotes_currentSelectedColumn = 3;
    }

}




void FAT_screenNotes_moveCursorLeft(){
    if (FAT_screenNotes_currentSelectedColumn == 1){

        FAT_screenNotes_cursorX -= 24 + 8;
        FAT_screenNotes_currentSelectedColumn = 0;
        FAT_cursors_hideCursor2();
        FAT_cursors_showCursor3();

    } else if (FAT_screenNotes_currentSelectedColumn == 2){

        FAT_screenNotes_cursorX -= 16 + 8;
        FAT_screenNotes_currentSelectedColumn = 1;

    } else if (FAT_screenNotes_currentSelectedColumn == 3){
        FAT_screenNotes_cursorX -= 16;
        FAT_screenNotes_currentSelectedColumn = 2;
    }
}






void FAT_screenNotes_moveCursorAllUp (){
    FAT_screenNotes_currentSelectedLine = 0;
    FAT_screenNotes_cursorY = 16 - 1;
    FAT_screenNotes_printInfos();
}






void FAT_screenNotes_moveCursorAllDown (){
    FAT_screenNotes_currentSelectedLine = 16 - 1;
    FAT_screenNotes_cursorY = 135;
    FAT_screenNotes_printInfos();
}
# 57 "src/headers/screen_notes.h" 2





void FAT_screenNotes_printLineColumns() {
    u8 y = 2;
    int c;
    for (c = 0; c < (16); c++) {
        hel_BgTextPrintF(1, 0, y, 0, "%.2x", c);
        y += 1;
    }
}





void FAT_screenNotes_printInfos() {
    hel_BgTextPrintF(1, 18, 4, 0, "Line     %.2x", FAT_screenNotes_currentSelectedLine);

}







void FAT_screenNotes_printNote(u8 line) {
    if (!FAT_data_isNoteEmpty(FAT_screenNotes_currentBlockId, line)) {
        note* actualNote = FAT_data_getNote(FAT_screenNotes_currentBlockId, line);

        if (FAT_screenSong_currentSelectedColumn < 4) {

            hel_BgTextPrintF(1, 3,
                    line + 2, 0,
                    "%s%1x %.2x\0", noteName[(actualNote->note & 0xf0) >> 4], actualNote->note & 0x0f, actualNote->instrument);
        } else {
            hel_BgTextPrintF(1, 3,
                    line + 2, 0,
                    "#%.2x %.2x\0", actualNote->freq, actualNote->instrument);
        }
    } else {
        hel_BgTextPrint(1, 3,
                line + 2, 0, "      ");
    }
}







void FAT_screenNotes_printEffect(u8 line) {
    if (!FAT_data_note_isEffectEmpty(FAT_screenNotes_currentBlockId, line)) {

        effect* effect = FAT_data_note_getEffect(FAT_screenNotes_currentBlockId, line);
        u8 effectName = (effect->name & 0xfe) >> 1;
        switch (effectName){
            case 1:
                hel_BgTextPrintF(1, 10, line + 2, 0,
                                                "%.2s--\0", noteEffectName[effectName]);
                break;
            case 2:

                hel_BgTextPrintF(1, 10, line + 2, 0,
                                                "%.2s%s\0", noteEffectName[effectName], outputText[effect->value]);
                break;
            case 3:
                hel_BgTextPrintF(1, 10, line + 2, 0,
                                "%.2s%.2x\0", noteEffectName[effectName], effect->value);
                break;
            case 4:

                hel_BgTextPrintF(1, 10, line + 2, 0,
                                "%.2s%.2x\0", noteEffectName[effectName], effect->value);
                break;
            case 0:

                hel_BgTextPrintF(1, 10, line + 2, 0,
                                                "%.2s%.2x\0", noteEffectName[effectName], effect->value);
                break;
        }

    } else {
        hel_BgTextPrint(1, 10, line + 2, 0,
                "    ");
    }
}




void FAT_screenNotes_printAllNotes() {
    u8 b;
    for (b = 0; b < 16; b++) {
        FAT_screenNotes_printNote(b);
        FAT_screenNotes_printEffect(b);
    }
}




void FAT_screenNotes_printBlockNumber() {
    hel_BgTextPrintF(1, 18, 3, 0, "Block    %.2x", FAT_screenNotes_currentBlockId);
}




void FAT_screenNotes_printAllScreenText() {
    FAT_screenNotes_printLineColumns();
    FAT_screenNotes_printAllNotes();
    FAT_screenNotes_printInfos();
    hel_BgTextPrintF(1, 18, 6, 0, "Tsp-Proj %2.x\nTempo   %.3d", FAT_tracker.transpose, FAT_tracker.tempo);
}




void FAT_screenNotes_init(u8 fromScreenId) {
    FAT_reinitScreen();


    ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[337440]), 5792, 1, 1);
    ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[336160]), 640, 0, 0);
    ham_InitBg(3, 1, 3, 0);


    switch (fromScreenId){
        case 4:
            FAT_screenNotes_currentBlockId = FAT_data_getBlock(FAT_screenBlocks_currentSequenceId, FAT_screenBlocks_currentSelectedLine);
            break;
    }
    if (FAT_screenNotes_currentBlockId == 0xff) {
        FAT_screenNotes_currentBlockId = 0;
    }
    FAT_screenNotes_printBlockNumber();
    FAT_screenNotes_printAllScreenText();


    FAT_player_hideAllCursors ();
    FAT_cursors_hideCursor2();
    FAT_cursors_hideCursor3();
    FAT_screenNotes_commitCursorMove();
    if (FAT_screenNotes_currentSelectedColumn == 0) {
        FAT_cursors_showCursor3();
    } else {
        FAT_cursors_showCursor2();
    }
    FAT_cursors_moveCursorChange(216, 24);
}




void FAT_screenNotes_checkButtons() {
    hel_PadCapture();

    if (((TPad*)(&__hel_Pad))->Held.Select) {
        if (!FAT_screenNotes_isPopuped) {
            FAT_cursors_hideCursor3();
            FAT_cursors_hideCursor2();
            FAT_popup_show();
            FAT_screenNotes_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenNotes_isPopuped) {
            FAT_popup_hide();
            if (FAT_screenNotes_currentSelectedColumn == 0) {
                FAT_cursors_showCursor3();
            } else {
                FAT_cursors_showCursor2();
            }
            FAT_screenNotes_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != 5) {
                FAT_cursors_hideCursor3();
                FAT_cursors_hideCursor2();
                FAT_switchToScreen(FAT_popup_getSelectedIcon(), 5);
            }
        }


        if (((TPad*)(&__hel_Pad))->Held.A || ((TPad*)(&__hel_Pad))->Pressed.A) {
            FAT_screenNotes_pressOrHeldA();

        } else {

            if (((TPad*)(&__hel_Pad))->Held.R) {
                FAT_cursors_showCursorChange();

                if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                    if (FAT_screenNotes_currentBlockId < 0x70 - 1) {
                        FAT_screenNotes_currentBlockId++;
                        FAT_screenNotes_printBlockNumber();
                        FAT_screenNotes_printAllScreenText();
                    }
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                    if (FAT_screenNotes_currentBlockId > 0) {
                        FAT_screenNotes_currentBlockId--;
                        FAT_screenNotes_printBlockNumber();
                        FAT_screenNotes_printAllScreenText();
                    }
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Down) {

                }

                if (((TPad*)(&__hel_Pad))->Pressed.Up) {

                }

            } else {

                FAT_cursors_hideCursorChange();

                if (((TPad*)(&__hel_Pad))->Pressed.B) {
                    FAT_screenNotes_pressB();
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Start) {
                    if (!FAT_isCurrentlyPlaying) {
                        FAT_player_startPlayerFromNotes(FAT_screenNotes_currentBlockId,
                                0, FAT_screenSong_currentSelectedColumn);
                    } else {
                        FAT_player_stopPlayer();
                    }
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                    FAT_screenNotes_moveCursorRight();
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                    FAT_screenNotes_moveCursorLeft();
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                    if (((TPad*)(&__hel_Pad))->Held.L) {
                        FAT_screenNotes_moveCursorAllDown();
                    } else {
                        FAT_screenNotes_moveCursorDown();
                    }
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                    if (((TPad*)(&__hel_Pad))->Held.L) {
                        FAT_screenNotes_moveCursorAllUp();
                    } else {
                        FAT_screenNotes_moveCursorUp();
                    }
                }

                FAT_screenNotes_commitCursorMove();
            }

            if (((TPad*)(&__hel_Pad))->Pressed.R && ((TPad*)(&__hel_Pad))->Pressed.L) {
                FAT_showHelp(5);
            }
        }
    }
}




void FAT_screenNotes_pressB() {
    switch (FAT_screenNotes_currentSelectedColumn) {
        case 0:
        case 1:
            if (FAT_data_isNoteEmpty(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine)) {
                FAT_data_pasteNote(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine);
            } else {
                FAT_data_cutNote(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine);
            }
            FAT_screenNotes_printNote(FAT_screenNotes_currentSelectedLine);
            break;
        case 2:
        case 3:
            if (FAT_data_note_isEffectEmpty(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine)) {
                FAT_data_note_pasteEffect(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine);
            } else {
                FAT_data_note_cutEffect(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine);
            }
            FAT_screenNotes_printEffect(FAT_screenNotes_currentSelectedLine);
            break;
    }
}




void FAT_screenNotes_pressOrHeldA() {
    switch (FAT_screenNotes_currentSelectedColumn) {
        case 0:
            if (FAT_data_isNoteEmpty(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine)) {

                FAT_data_addDefaultNote(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, FAT_screenSong_currentSelectedColumn);

            }

            if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                FAT_data_note_changeValue(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, 1);

                if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                    FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                    FAT_screenNotes_currentSelectedLine);
                }
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                FAT_data_note_changeValue(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, -1);

                if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                    FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                    FAT_screenNotes_currentSelectedLine);
                }
            }


            if (((TPad*)(&__hel_Pad))->Pressed.Up && (FAT_screenSong_currentSelectedColumn < 4)) {
                FAT_data_note_changeOctave(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, 1);

                if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                    FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                    FAT_screenNotes_currentSelectedLine);
                }
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Down && (FAT_screenSong_currentSelectedColumn < 4)) {
                FAT_data_note_changeOctave(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, -1);

                if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                    FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                    FAT_screenNotes_currentSelectedLine);
                }
            }

            if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying && ((TPad*)(&__hel_Pad))->Pressed.A) {
                FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);
            }

            break;

        case 1:

            if (((TPad*)(&__hel_Pad))->Held.L) {
                FAT_data_note_smartChangeInstrument(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);
            } else {

                if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                    FAT_data_note_changeInstrument(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                            FAT_screenNotes_currentSelectedLine, 1);

                    if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                                    FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                                    FAT_screenNotes_currentSelectedLine);
                    }
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                    FAT_data_note_changeInstrument(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                            FAT_screenNotes_currentSelectedLine, -1);

                    if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                        FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);
                    }
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                    FAT_data_note_changeInstrument(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                            FAT_screenNotes_currentSelectedLine, 16);

                    if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                        FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);
                    }
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                    FAT_data_note_changeInstrument(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                            FAT_screenNotes_currentSelectedLine, -16);

                    if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                        FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);
                    }
                }
            }

            if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying && ((TPad*)(&__hel_Pad))->Pressed.A) {
                FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);
            }

            break;

        case 2:

            if (FAT_data_note_isEffectEmpty(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine)) {

                FAT_data_note_addDefaultEffect(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);

            }

            if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                FAT_data_note_changeEffectName(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, 1);
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                FAT_data_note_changeEffectName(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, -1);
            }

            break;

        case 3:

            if (FAT_data_note_isEffectEmpty(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine)) {

                FAT_data_note_addDefaultEffect(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);

            }

            if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                FAT_data_note_changeEffectValue(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, 1);
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                FAT_data_note_changeEffectValue(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, -1);
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                FAT_data_note_changeEffectValue(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, 16);
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                FAT_data_note_changeEffectValue(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, -16);
            }

            break;
    }

    FAT_screenNotes_printNote(FAT_screenNotes_currentSelectedLine);
    FAT_screenNotes_printEffect(FAT_screenNotes_currentSelectedLine);

}
# 135 "src/headers/fat.h" 2
# 1 "src/headers/screen_instrument.h" 1
# 22 "src/headers/screen_instrument.h"
u8 FAT_screenInstrument_isPopuped = 0;

u8 FAT_screenInstrument_isTabulating = 0;



u8 FAT_screenInstrument_currentInstrumentId;



THandle FAT_instrument_envdir0_obj;

THandle FAT_instrument_envdir1_obj;

THandle FAT_instrument_waveduty0_obj;

THandle FAT_instrument_waveduty1_obj;

THandle FAT_instrument_waveduty2_obj;

THandle FAT_instrument_waveduty3_obj;

THandle FAT_instrument_oscForm_sin_obj;
THandle FAT_instrument_oscForm_square_obj;
THandle FAT_instrument_oscForm_triangle_obj;
THandle FAT_instrument_oscForm_saw_obj;

# 1 "src/headers/screen_instrument_cursor.h" 1
# 53 "src/headers/screen_instrument_cursor.h"
u8 FAT_screenInstrument_cursorX;

u8 FAT_screenInstrument_cursorY;

s8 FAT_screenInstruments_currentSelectedLine;

u8 FAT_screenInstruments_currentSelectedColumn;


u8 FAT_screenInstrument_tabCursorX;

u8 FAT_screenInstrument_tabCursorY;

THandle FAT_screenInstrument_tabCursorObj;


const u8 INST_PULSE_BLOCK_Y[9] = {31, 39, 47, 55, 79, 87, 95, 103, 127};

const u8 INST_NOISE_BLOCK_Y[8] = {31, 39, 47, 55, 79, 87, 95, 127};

const u8 INST_WAVE_BLOCK_Y[8] = {31, 55, 63, 71, 79, 87, 95, 119};

const u8 INST_SAMPLE_BLOCK_Y[9] = {31, 55, 79, 87, 95, 103, 111, 119, 95};

const u8 INST_OSC_BLOCK_Y[5] = {31, 39, 63, 71, 95};




void FAT_screenInstrument_hideTabulationCursor() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_screenInstrument_tabCursorObj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}




void FAT_screenInstrument_showTabulationCursor() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_screenInstrument_tabCursorObj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
}







void FAT_screenInstrument_moveTabulationCursor(u8 instrumentType) {
    switch (instrumentType) {
        case 0:
        case 1:
            FAT_screenInstrument_tabCursorX = 3;
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_screenInstrument_tabCursorObj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_tabCursorX)&511) << 16) | (((FAT_screenInstrument_tabCursorY)&255)); } while(0);
            break;
        case 2:
            FAT_screenInstrument_tabCursorX = 47;
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_screenInstrument_tabCursorObj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_tabCursorX)&511) << 16) | (((FAT_screenInstrument_tabCursorY)&255)); } while(0);
            break;
        case 3:
            FAT_screenInstrument_tabCursorX = 91;
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_screenInstrument_tabCursorObj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_tabCursorX)&511) << 16) | (((FAT_screenInstrument_tabCursorY)&255)); } while(0);
            break;
        case 4:
        case 5:
            FAT_screenInstrument_tabCursorX = 135;
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_screenInstrument_tabCursorObj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_tabCursorX)&511) << 16) | (((FAT_screenInstrument_tabCursorY)&255)); } while(0);
            break;
        case 6:
        case 7:
            FAT_screenInstrument_tabCursorX = 179;
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_screenInstrument_tabCursorObj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_tabCursorX)&511) << 16) | (((FAT_screenInstrument_tabCursorY)&255)); } while(0);
            break;
    }
}






void FAT_screenInstrument_tabCursorInit() {
    FAT_screenInstrument_tabCursorX = 5;
    FAT_screenInstrument_tabCursorY = 5;

    FAT_screenInstrument_tabCursorObj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[2720])), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0x01)<<10) | ((0)<<9) | ((FAT_screenInstrument_tabCursorY) & 0x00FF), ((3)<<14) | ((0)<<13) | ((0)<<12) | ((FAT_screenInstrument_tabCursorX) & 0x01FF), ((0)<<12) | ((1)<<10) );
# 150 "src/headers/screen_instrument_cursor.h"
    FAT_screenInstrument_hideTabulationCursor();
}




void FAT_screenInstrument_pulse_commitCursorMove() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
        case 1:
        case 2:
        case 4:
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor1_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_cursorX)&511) << 16) | (((FAT_screenInstrument_cursorY)&255)); } while(0);
            break;

        case 3:
        case 5:
        case 6:
        case 7:
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_cursorX)&511) << 16) | (((FAT_screenInstrument_cursorY)&255)); } while(0);
            break;
        case 8:
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_cursorX)&511) << 16) | (((FAT_screenInstrument_cursorY)&255)); } while(0);
            break;
    }
}




void FAT_screenInstrument_wave_commitCursorMove() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
        case 1:
        case 4:
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor1_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_cursorX)&511) << 16) | (((FAT_screenInstrument_cursorY)&255)); } while(0);
            break;

        case 2:
        case 3:
        case 6:
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_cursorX)&511) << 16) | (((FAT_screenInstrument_cursorY)&255)); } while(0);
            break;
        case 5:
        case 7:
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_cursorX)&511) << 16) | (((FAT_screenInstrument_cursorY)&255)); } while(0);
            break;
    }
}




void FAT_screenInstrument_noise_commitCursorMove() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor1_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_cursorX)&511) << 16) | (((FAT_screenInstrument_cursorY)&255)); } while(0);
            break;

        case 5:
        case 6:
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_cursorX)&511) << 16) | (((FAT_screenInstrument_cursorY)&255)); } while(0);
            break;
        case 7:
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_cursorX)&511) << 16) | (((FAT_screenInstrument_cursorY)&255)); } while(0);
            break;
    }
}





void FAT_screenInstrument_sample_commitCursorMove() {
    if (FAT_screenInstruments_currentSelectedColumn == 0){
        switch (FAT_screenInstruments_currentSelectedLine) {
            case 0:
                do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor8_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((48)&511) << 16) | (((FAT_screenInstrument_cursorY + 1)&255)); } while(0);
                break;
            case 1:
            case 4:
                do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor1_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_cursorX)&511) << 16) | (((FAT_screenInstrument_cursorY)&255)); } while(0);
                break;

            case 2:
            case 6:
            case 7:
                do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_cursorX)&511) << 16) | (((FAT_screenInstrument_cursorY)&255)); } while(0);
                break;

            case 3:
            case 5:
                do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_cursorX)&511) << 16) | (((FAT_screenInstrument_cursorY)&255)); } while(0);
                break;
        }
    } else {
        do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_cursorX)&511) << 16) | (((FAT_screenInstrument_cursorY)&255)); } while(0);
    }
}

void FAT_screenInstrument_osc_commitCursorMove () {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
        case 1:
        case 3:
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_cursorX)&511) << 16) | (((FAT_screenInstrument_cursorY)&255)); } while(0);
            break;
        case 2:
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor1_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_cursorX)&511) << 16) | (((FAT_screenInstrument_cursorY)&255)); } while(0);
            break;
        case 4:
            do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((FAT_screenInstrument_cursorX)&511) << 16) | (((FAT_screenInstrument_cursorY)&255)); } while(0);
            break;
    }
}






void FAT_screenInstrument_commitCursorMove(u8 type) {
    switch (type) {
        case 0:
        case 1:

            FAT_screenInstrument_pulse_commitCursorMove();

            break;
        case 2:

            FAT_screenInstrument_wave_commitCursorMove();

            break;
        case 3:

            FAT_screenInstrument_noise_commitCursorMove();

            break;
        case 4:
        case 5:

            FAT_screenInstrument_sample_commitCursorMove();

            break;
        case 6:
        case 7:
            FAT_screenInstrument_osc_commitCursorMove();

            break;
    }
}




void FAT_screenInstrument_pulse_displayGoodCursor() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case -1:
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;
        case 0:
        case 1:
        case 2:
        case 4:
            FAT_cursors_showCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;
        case 3:
        case 5:
        case 6:
        case 7:
            FAT_cursors_showCursor2();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor3();
            break;
        case 8:
            FAT_cursors_showCursor3();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            break;
    }
}




void FAT_screenInstrument_noise_displayGoodCursor() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case -1:
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            FAT_cursors_showCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;
        case 5:
        case 6:
            FAT_cursors_showCursor2();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor3();
            break;
        case 7:
            FAT_cursors_showCursor3();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            break;
    }
}




void FAT_screenInstrument_wave_displayGoodCursor() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case -1:
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;
        case 0:
        case 1:
        case 4:
            FAT_cursors_showCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;

        case 2:
        case 3:
        case 6:
            FAT_cursors_showCursor2();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor3();
            break;
        case 5:
        case 7:
            FAT_cursors_showCursor3();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            break;
    }
}




void FAT_screenInstrument_sample_displayGoodCursor() {

    if (FAT_screenInstruments_currentSelectedColumn == 0){
        switch (FAT_screenInstruments_currentSelectedLine) {
            case -1:
                FAT_cursors_hideCursor1();
                FAT_cursors_hideCursor2();
                FAT_cursors_hideCursor3();
                FAT_cursors_hideCursor8();
                break;
            case 0:
                FAT_cursors_showCursor8();
                FAT_cursors_hideCursor1();
                FAT_cursors_hideCursor2();
                FAT_cursors_hideCursor3();
                break;
            case 1:
            case 4:
                FAT_cursors_showCursor1();
                FAT_cursors_hideCursor8();
                FAT_cursors_hideCursor2();
                FAT_cursors_hideCursor3();
                break;
            case 2:
            case 6:
            case 7:
                FAT_cursors_showCursor2();
                FAT_cursors_hideCursor8();
                FAT_cursors_hideCursor1();
                FAT_cursors_hideCursor3();
                break;
            case 3:
            case 5:
                FAT_cursors_showCursor3();
                FAT_cursors_hideCursor1();
                FAT_cursors_hideCursor2();
                FAT_cursors_hideCursor8();
                break;
        }
    } else {
        FAT_cursors_showCursor3();
        FAT_cursors_hideCursor8();
        FAT_cursors_hideCursor1();
        FAT_cursors_hideCursor2();
    }
}

void FAT_screenInstrument_osc_displayGoodCursor() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case -1:
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;
        case 0:
        case 1:
        case 3:
            FAT_cursors_showCursor2();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor3();
            break;
        case 2:
            FAT_cursors_showCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;
        case 4:
            FAT_cursors_showCursor3();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            break;

    }
}





void FAT_screenInstrument_displayGoodCursor(u8 type) {
    switch (type) {
        case 0:
        case 1:
            FAT_screenInstrument_pulse_displayGoodCursor();
            break;
        case 2:
            FAT_screenInstrument_wave_displayGoodCursor();
            break;
        case 3:
            FAT_screenInstrument_noise_displayGoodCursor();
            break;
        case 4:
        case 5:
            FAT_screenInstrument_sample_displayGoodCursor();
            break;
        case 6:
        case 7:
            FAT_screenInstrument_osc_displayGoodCursor();
            break;
    }
}





void FAT_screenInstrument_initCursor(u8 instrumentType) {

    FAT_screenInstrument_moveTabulationCursor(instrumentType);
    FAT_screenInstrument_hideTabulationCursor();

    FAT_screenInstrument_cursorX = 88 - 1;
    FAT_screenInstrument_cursorY = 32 - 1;

    FAT_screenInstruments_currentSelectedLine = 0;
    FAT_screenInstruments_currentSelectedColumn = 0;

    FAT_screenInstrument_commitCursorMove(instrumentType);
}





void FAT_screenInstrument_moveCursorDown(u8 type) {
    if (FAT_screenInstruments_currentSelectedLine == -1){

            FAT_screenInstruments_currentSelectedLine = 0;
    } else {

        switch (type) {
            case 0:
            case 1:

                if (FAT_screenInstruments_currentSelectedLine < 9 - 1) {
                    if (!(FAT_screenInstrument_cursorY >= 120 - 1)) {
                        FAT_screenInstruments_currentSelectedLine++;
                        FAT_screenInstrument_cursorY = INST_PULSE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                } else {
                    FAT_screenInstruments_currentSelectedLine = 0;
                    FAT_screenInstrument_cursorY = INST_PULSE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;
            case 2:

                if (FAT_screenInstruments_currentSelectedLine < 8 - 1) {
                    if (!(FAT_screenInstrument_cursorY >= 120 - 1)) {
                        FAT_screenInstruments_currentSelectedLine++;
                        FAT_screenInstrument_cursorY = INST_WAVE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                } else {
                    FAT_screenInstruments_currentSelectedLine = 0;
                    FAT_screenInstrument_cursorY = INST_WAVE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;
            case 3:

                if (FAT_screenInstruments_currentSelectedLine < 8 - 1) {
                    if (!(FAT_screenInstrument_cursorY >= 120 - 1)) {
                        FAT_screenInstruments_currentSelectedLine++;
                        FAT_screenInstrument_cursorY = INST_NOISE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                } else {
                    FAT_screenInstruments_currentSelectedLine = 0;
                    FAT_screenInstrument_cursorY = INST_NOISE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;
            case 4:
            case 5:

                if (FAT_screenInstruments_currentSelectedColumn == 0){
                    if (FAT_screenInstruments_currentSelectedLine < 9 - 2) {
                        if (!(FAT_screenInstrument_cursorY >= 120 - 1)) {
                            FAT_screenInstruments_currentSelectedLine++;
                            FAT_screenInstrument_cursorY = INST_SAMPLE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                        }
                    } else {
                        FAT_screenInstruments_currentSelectedLine = 0;
                        FAT_screenInstrument_cursorY = INST_SAMPLE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                }

                FAT_screenInstrument_displayGoodCursor(type);
                break;

            case 6:
            case 7:
                if (FAT_screenInstruments_currentSelectedLine < 5 - 1) {
                    if (!(FAT_screenInstrument_cursorY >= 120 - 1)) {
                        FAT_screenInstruments_currentSelectedLine++;
                        FAT_screenInstrument_cursorY = INST_OSC_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                } else {
                    FAT_screenInstruments_currentSelectedLine = 0;
                    FAT_screenInstrument_cursorY = INST_OSC_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;
        }
    }
}





void FAT_screenInstrument_moveCursorUp(u8 type) {

    if (FAT_screenInstruments_currentSelectedLine == 0){

        FAT_screenInstruments_currentSelectedLine = -1;
        FAT_screenInstrument_displayGoodCursor(type);
    } else {

        if (FAT_screenInstruments_currentSelectedLine == -1){
            FAT_screenInstruments_currentSelectedLine = 0;
        }

        switch (type) {
            case 0:
            case 1:

                if (FAT_screenInstruments_currentSelectedLine > 0) {
                    if (!(FAT_screenInstrument_cursorY <= 32 - 1)) {
                        FAT_screenInstruments_currentSelectedLine--;
                        FAT_screenInstrument_cursorY = INST_PULSE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                } else {
                    FAT_screenInstruments_currentSelectedLine = 9 -1;
                    FAT_screenInstrument_cursorY = INST_PULSE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;
            case 2:

                if (FAT_screenInstruments_currentSelectedLine > 0) {
                    if (!(FAT_screenInstrument_cursorY <= 32 - 1)) {
                        FAT_screenInstruments_currentSelectedLine--;
                        FAT_screenInstrument_cursorY = INST_WAVE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                } else {
                    FAT_screenInstruments_currentSelectedLine = 8 -1;
                    FAT_screenInstrument_cursorY = INST_WAVE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;
            case 3:

                if (FAT_screenInstruments_currentSelectedLine > 0) {
                    if (!(FAT_screenInstrument_cursorY <= 32 - 1)) {
                        FAT_screenInstruments_currentSelectedLine--;
                        FAT_screenInstrument_cursorY = INST_NOISE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                } else {
                    FAT_screenInstruments_currentSelectedLine = 8 -1;
                    FAT_screenInstrument_cursorY = INST_NOISE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;
            case 4:
            case 5:

                if (FAT_screenInstruments_currentSelectedColumn == 0){
                    if (FAT_screenInstruments_currentSelectedLine > 0) {
                        if (!(FAT_screenInstrument_cursorY <= 32 - 1)) {
                            FAT_screenInstruments_currentSelectedLine--;
                            FAT_screenInstrument_cursorY = INST_SAMPLE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                        }
                    } else {
                        FAT_screenInstruments_currentSelectedLine = 9 -2;
                        FAT_screenInstrument_cursorY = INST_SAMPLE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;

            case 6:
            case 7:
                if (FAT_screenInstruments_currentSelectedLine > 0) {
                    if (!(FAT_screenInstrument_cursorY <= 32 - 1)) {
                        FAT_screenInstruments_currentSelectedLine--;
                        FAT_screenInstrument_cursorY = INST_OSC_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                } else {
                    FAT_screenInstruments_currentSelectedLine = 5 -1;
                    FAT_screenInstrument_cursorY = INST_OSC_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;
        }
    }
}





void FAT_screenInstrument_moveCursorRight(u8 type) {
    switch (type) {
        case 0:
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
        case 5:
            FAT_screenInstruments_currentSelectedColumn = 1;
            FAT_screenInstrument_cursorY = INST_SAMPLE_BLOCK_Y[8];
            FAT_screenInstrument_cursorX = 207;

            FAT_screenInstrument_displayGoodCursor(type);
            break;
        case 6:
        case 7:
            break;
    }
}





void FAT_screenInstrument_moveCursorLeft(u8 type) {
    switch (type) {
        case 0:
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
        case 5:
            FAT_screenInstruments_currentSelectedColumn = 0;
            FAT_screenInstrument_cursorY = INST_SAMPLE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
            FAT_screenInstrument_cursorX = 88 - 1;

            FAT_screenInstrument_displayGoodCursor(type);
            break;
        case 6:
        case 7:
            break;
    }
}

void FAT_screenInstrument_showSimulatorCursor (u8 type){
    switch (type) {
       case 0:
       case 1:
           do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor_player3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((88 - 1)&511) << 16) | (((INST_PULSE_BLOCK_Y[9 - 1])&255)); } while(0);
           break;
       case 2:
           do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor_player3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((88 - 1)&511) << 16) | (((INST_WAVE_BLOCK_Y[8 - 1])&255)); } while(0);
           break;
       case 3:
           do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor_player3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((88 - 1)&511) << 16) | (((INST_NOISE_BLOCK_Y[8 - 1])&255)); } while(0);
           break;
       case 4:
       case 5:
           do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor_player3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((207)&511) << 16) | (((INST_SAMPLE_BLOCK_Y[9 - 1])&255)); } while(0);
           break;
       case 6:
       case 7:
           do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor_player3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((88 - 1)&511) << 16) | (((INST_OSC_BLOCK_Y[5 - 1])&255)); } while(0);
           break;
    }

    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_player3_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
}

void FAT_screenInstrument_hideSimulatorCursor (){
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_player3_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}
# 50 "src/headers/screen_instrument.h" 2



void FAT_screenInstrument_init();
void FAT_screenInstrument_checkButtons();
void FAT_screenInstrument_switchScreen(u8 type);
void FAT_screenInstrument_pressOrHeldA();
void FAT_screenInstrument_showOutput(u8 x, u8 y, u8 output);
void FAT_screenInstrument_showWaveduty(u8 wavedutyValue, u8 spriteX, u8 spriteY);
void FAT_screenInstrument_showOscForm (u8 oscForm, u8 spriteX, u8 spriteY);
void FAT_screenInstrument_showEnvdir(u8 envdirValue, u8 spriteX, u8 spriteY);
void FAT_screenInstrument_hideAllEnvdirSprites();
void FAT_screenInstrument_hideAllWavedutySprite();
void FAT_screenInstrument_hideAllOscSprite();
s8 FAT_screenInstrument_giveMeAddedValue();




void FAT_screenInstrument_printInstrumentNumber() {
    hel_BgTextPrintF(1, 16, 3, 0, "Instrument %.2x", FAT_screenInstrument_currentInstrumentId);
}






void FAT_screenInstrument_printAllText(u8 type) {
    switch (type) {
        case 0:
        case 1:
            hel_BgTextPrintF(1, 1, 4, 0, "Volume    %.1x", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].envelope & 0x0f);
            hel_BgTextPrint(1, 1, 5, 0, "Direction");
            FAT_screenInstrument_showEnvdir((FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].envelope & 0x10) >> 4,
                    88, 40);
            hel_BgTextPrintF(1, 1, 6, 0, "Steptime  %.1x", (FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].envelope & 0xe0) >> 5);
            hel_BgTextPrint(1, 1, 7, 0, "Wave");
            FAT_screenInstrument_showWaveduty(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].wavedutyOrPolynomialStep,
                    88, 56);
            hel_BgTextPrintF(1, 1, 10, 0, "Timed     %.1x", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode);
            if (FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode) {
                hel_BgTextPrintF(1, 1, 11, 0, "Length    %.2x", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].soundlength);
            } else {
                hel_BgTextPrint(1, 1, 11, 0, "Length    NA");
            }
            FAT_screenInstrument_showOutput(1, 12, FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].output);
            hel_BgTextPrintF(1, 1, 13, 0, "Sweep     %.2x", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].sweep);
            hel_BgTextPrintF(1, 1, 16, 0, "Test it!  %s%1x\0",
                    noteName[(FAT_data_simulator.note & 0xf0) >> 4], FAT_data_simulator.note & 0x0f);
            break;
        case 2:
            hel_BgTextPrintF(1, 1, 4, 0, "Volume    %.1x", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].volumeRatio & 0x0f);
            hel_BgTextPrintF(1, 1, 7, 0, "Timed     %.1x", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode);
            if (FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode) {
                hel_BgTextPrintF(1, 1, 8, 0, "Length    %.2x", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].soundlength);
            } else {
                hel_BgTextPrint(1, 1, 8, 0, "Length    NA");
            }

            hel_BgTextPrintF(1, 1, 9, 0, "Voice     %.2x", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].voiceAndBank & 0x1f);
            hel_BgTextPrintF(1, 1, 10, 0, "Bank      %.1x", (FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].voiceAndBank & 0x20) >> 5);

            if ((FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].voiceAndBank & 0x40) >> 6 == 0) {
                hel_BgTextPrint(1, 1, 11, 0, "Bankmode  SIN");
            } else {
                hel_BgTextPrintF(1, 1, 11, 0, "Bankmode  DUA");
            }
            FAT_screenInstrument_showOutput(1, 12, FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].output);
            hel_BgTextPrintF(1, 1, 15, 0, "Test it!  %s%1x\0",
                    noteName[(FAT_data_simulator.note & 0xf0) >> 4], FAT_data_simulator.note & 0x0f);
            break;
        case 3:
            hel_BgTextPrintF(1, 1, 4, 0, "Volume    %.1x", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].envelope & 0x0f);
            hel_BgTextPrint(1, 1, 5, 0, "Direction");
            FAT_screenInstrument_showEnvdir((FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].envelope & 0x10) >> 4,
                    88, 40);
            hel_BgTextPrintF(1, 1, 6, 0, "Steptime  %.1x", (FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].envelope & 0xe0) >> 5);
            hel_BgTextPrintF(1, 1, 7, 0, "Polystep  %.1x", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].wavedutyOrPolynomialStep);

            hel_BgTextPrintF(1, 1, 10, 0, "Timed     %.1x", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode);
            if (FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode) {
                hel_BgTextPrintF(1, 1, 11, 0, "Length    %.2x", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].soundlength);
            } else {
                hel_BgTextPrint(1, 1, 11, 0, "Length    NA");
            }
            FAT_screenInstrument_showOutput(1, 12, FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].output);
            hel_BgTextPrintF(1, 1, 16, 0, "Test it!  %s%1x\0",
                    noteName[(FAT_data_simulator.note & 0xf0) >> 4], FAT_data_simulator.note & 0x0f);
            break;
        case 4:
        case 5:
            hel_BgTextPrintF(1, 16, 4, 0, "Nb samples %.2x", snd_countSamplesInKitById(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].kitNumber));


            hel_BgTextPrintF(1, 1, 4, 0, "Name %s", snd_getKitNameById(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].kitNumber));
            hel_BgTextPrintF(1, 1, 7, 0, "Volume    %.1x", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].volumeRatio >> 4);
            hel_BgTextPrintF(1, 1, 10, 0, "Speed     %.1xx", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].speedOrLooping & 0x0f);
            if (FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].speedOrLooping >> 4) {
                hel_BgTextPrintF(1, 1, 11, 0, "Loop      %s", "YES");
            } else {
                hel_BgTextPrintF(1, 1, 11, 0, "Loop      %s", "NOP");
            }
            hel_BgTextPrintF(1, 1, 12, 0, "Timed     %.1x", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode);
            if (FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode) {
                hel_BgTextPrintF(1, 1, 13, 0, "Length(%) %.3d", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].soundlength);
            } else {
                hel_BgTextPrint(1, 1, 13, 0, "Length    N/A");
            }
            hel_BgTextPrintF(1, 1, 14, 0, "Offset(%) %.2d", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].offset);
            FAT_screenInstrument_showOutput(1, 15, FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].output);

            hel_BgTextPrintF(1, 16, 12, 0, "Test it!  #%.2x\0", FAT_data_simulator.freq);

            break;

        case 6:
        case 7:
            hel_BgTextPrintF(1, 1, 4, 0, "OSC Shape");
            FAT_screenInstrument_showOscForm (FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].wavedutyOrPolynomialStep,
                                                                  88, 32);
            hel_BgTextPrintF(1, 1, 5, 0, "Amplitude NA");
            hel_BgTextPrintF(1, 1, 8, 0, "Timed     %.1x", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode);
            if (FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode) {
                hel_BgTextPrintF(1, 1, 9, 0, "Length    %.2x", FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].soundlength);
            } else {
                hel_BgTextPrint(1, 1, 9, 0, "Length    NA");
            }

            hel_BgTextPrintF(1, 1, 12, 0, "Test it!  #%.2x\0", FAT_data_simulator.freq);
            break;
    }
}




void FAT_screenInstrument_init() {

    note* FAT_screenInstrument_currentNote = FAT_data_getNote(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine);
    FAT_screenInstrument_currentInstrumentId = FAT_screenInstrument_currentNote->instrument;
    if (FAT_screenInstrument_currentInstrumentId == 0xff) {

        FAT_screenInstrument_currentInstrumentId = 0;
    }
    FAT_data_initInstrumentIfNeeded(FAT_screenInstrument_currentInstrumentId, FAT_screenSong_currentSelectedColumn);


    FAT_screenInstrument_initCursor(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);


    FAT_screenInstrument_switchScreen(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);


    FAT_cursors_moveCursorChange(216, 24);

    FAT_player_hideAllCursors ();
}







void FAT_screenInstrument_switchScreen(u8 type) {
    FAT_reinitScreen();

    FAT_cursors_hideAllCursors();
    FAT_screenInstrument_hideAllEnvdirSprites();
    FAT_screenInstrument_hideAllWavedutySprite();
    FAT_screenInstrument_hideAllOscSprite ();

    switch (type) {
        case 0:
        case 1:
            ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[295520]), 3968, 1, 1);
            ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[294240]), 640, 0, 0);
            FAT_screenInstrument_printInstrumentNumber();
            FAT_screenInstrument_printAllText(type);
            FAT_screenInstrument_initCursor(type);
            FAT_screenInstrument_displayGoodCursor(type);
            break;
        case 2:
            ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[314656]), 4000, 1, 1);
            ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[313376]), 640, 0, 0);
            FAT_screenInstrument_printInstrumentNumber();
            FAT_screenInstrument_printAllText(type);
            FAT_screenInstrument_initCursor(type);
            FAT_screenInstrument_displayGoodCursor(type);
            break;
        case 3:
            ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[277088]), 4032, 1, 1);
            ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[275808]), 640, 0, 0);
            FAT_screenInstrument_printInstrumentNumber();
            FAT_screenInstrument_printAllText(type);
            FAT_screenInstrument_initCursor(type);
            FAT_screenInstrument_displayGoodCursor(type);
            break;
        case 4:
        case 5:
            ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[304736]), 4320, 1, 1);
            ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[303456]), 640, 0, 0);
            FAT_screenInstrument_printInstrumentNumber();
            FAT_screenInstrument_printAllText(type);
            FAT_screenInstrument_initCursor(type);
            FAT_screenInstrument_displayGoodCursor(type);

            break;
        case 6:
        case 7:
            ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[286432]), 3904, 1, 1);
            ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[285152]), 640, 0, 0);
            FAT_screenInstrument_printInstrumentNumber();
            FAT_screenInstrument_printAllText(type);
            FAT_screenInstrument_initCursor(type);
            FAT_screenInstrument_displayGoodCursor(type);
            break;
    }
    ham_InitBg(3, 1, 3, 0);
}







void FAT_screenInstrument_changeInstrumentType(s8 move) {
    u8 currentType = FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type;

    switch (currentType) {
        case 0:
        case 1:
            if (move > 0) {
                FAT_data_instrument_changeType(FAT_screenInstrument_currentInstrumentId, 2);
            }
            break;
        case 2:
            if (move > 0) {
                FAT_data_instrument_changeType(FAT_screenInstrument_currentInstrumentId, 3);
            } else {
                FAT_data_instrument_changeType(FAT_screenInstrument_currentInstrumentId, 0);
            }
            break;
        case 3:
            if (move > 0) {
                FAT_data_instrument_changeType(FAT_screenInstrument_currentInstrumentId, 4);
            } else {
                FAT_data_instrument_changeType(FAT_screenInstrument_currentInstrumentId, 2);
            }
            break;
        case 4:
        case 5:
            if (move > 0){
                FAT_data_instrument_changeType(FAT_screenInstrument_currentInstrumentId, 6);
            }else {
                FAT_data_instrument_changeType(FAT_screenInstrument_currentInstrumentId, 3);
            }
            break;
        case 6:
        case 7:
            if (move < 0){
                FAT_data_instrument_changeType(FAT_screenInstrument_currentInstrumentId, 4);
            }
            break;
    }

    FAT_screenInstrument_moveTabulationCursor(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
}






void FAT_screenInstrument_checkButtons() {
    hel_PadCapture();

    if ( FAT_isCurrentlySimulating == 1 && !FAT_isCurrentlyPlaying && (
                    ((TPad*)(&__hel_Pad))->Pressed.Start ||
                    ((TPad*)(&__hel_Pad))->Pressed.Select ||
                    ((TPad*)(&__hel_Pad))->Pressed.A ||
                    ((TPad*)(&__hel_Pad))->Pressed.Up ||
                    ((TPad*)(&__hel_Pad))->Pressed.Down ||
                    ((TPad*)(&__hel_Pad))->Pressed.Right ||
                    ((TPad*)(&__hel_Pad))->Pressed.Left ||
                    ((TPad*)(&__hel_Pad))->Pressed.R ||
                    ((TPad*)(&__hel_Pad))->Pressed.L)
                    ) {
        FAT_player_stopPlayer();
        FAT_data_instrument_setCurrentlySimulating (0);
    }

    if (((TPad*)(&__hel_Pad))->Held.Select) {
        if (!FAT_screenInstrument_isPopuped) {
            FAT_screenInstrument_hideAllWavedutySprite();
            FAT_cursors_hideAllCursors();
            FAT_popup_show();
            FAT_screenInstrument_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenInstrument_isPopuped) {
            FAT_popup_hide();
            FAT_screenInstrument_displayGoodCursor(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
            FAT_screenInstrument_printAllText(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
            FAT_screenInstrument_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != 6) {
                FAT_screenInstrument_hideAllEnvdirSprites();
                FAT_screenInstrument_hideAllWavedutySprite();
                FAT_screenInstrument_hideAllOscSprite ();
                FAT_cursors_hideAllCursors();
                FAT_switchToScreen(FAT_popup_getSelectedIcon(), 6);
            }
        }

        if (((TPad*)(&__hel_Pad))->Held.L || FAT_screenInstruments_currentSelectedLine == -1) {
            if (!FAT_screenInstrument_isTabulating) {
                FAT_screenInstrument_isTabulating = 1;
                FAT_screenInstrument_showTabulationCursor();
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                FAT_screenInstrument_changeInstrumentType(-1);
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                FAT_screenInstrument_changeInstrumentType(1);
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                FAT_screenInstrument_moveCursorDown(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
            }

            if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                FAT_screenInstrument_moveCursorUp(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
            }

        } else {
            if (FAT_screenInstrument_isTabulating && FAT_screenInstruments_currentSelectedLine == 0) {

                FAT_screenInstrument_isTabulating = 0;
                FAT_screenInstrument_switchScreen(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                FAT_screenInstrument_hideTabulationCursor();
            }

            if (((TPad*)(&__hel_Pad))->Held.R) {
                FAT_cursors_showCursorChange();

                if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                    if (FAT_screenInstrument_currentInstrumentId < 0x3f - 1) {
                        u8 type = FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type;
                        FAT_screenInstrument_currentInstrumentId++;
                        FAT_data_initInstrumentIfNeeded(FAT_screenInstrument_currentInstrumentId, type);
                        FAT_screenInstrument_switchScreen(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                        FAT_screenInstrument_printInstrumentNumber();
                        FAT_screenInstrument_printAllText(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                    }
                }

                if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                    if (FAT_screenInstrument_currentInstrumentId > 0) {
                        u8 type = FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type;
                        FAT_screenInstrument_currentInstrumentId--;
                        FAT_data_initInstrumentIfNeeded(FAT_screenInstrument_currentInstrumentId, type);
                        FAT_screenInstrument_switchScreen(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                        FAT_screenInstrument_printInstrumentNumber();
                        FAT_screenInstrument_printAllText(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                    }
                }

            } else {

                FAT_cursors_hideCursorChange();

                if (((TPad*)(&__hel_Pad))->Pressed.A || ((TPad*)(&__hel_Pad))->Held.A) {
                    FAT_screenInstrument_pressOrHeldA();

                } else {

                    if (((TPad*)(&__hel_Pad))->Pressed.Start) {
                        if (!FAT_isCurrentlyPlaying) {
                            FAT_player_startPlayerFromNotes(FAT_screenNotes_currentBlockId,
                                    0, FAT_screenSong_currentSelectedColumn);
                        } else {
                            FAT_player_stopPlayer();
                        }
                    }

                    if (((TPad*)(&__hel_Pad))->Pressed.B) {
                        FAT_data_instrument_playSimulator(FAT_screenInstrument_currentInstrumentId);
                    }
                    if (((TPad*)(&__hel_Pad))->Held.B) {
                        FAT_screenInstrument_showSimulatorCursor (FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                        s8 addedValue = FAT_screenInstrument_giveMeAddedValue();
                        FAT_data_instrument_changeSimulator(FAT_screenInstrument_currentInstrumentId, addedValue);
                        FAT_screenInstrument_printAllText(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                    } else {
                        FAT_screenInstrument_hideSimulatorCursor ();

                        if (((TPad*)(&__hel_Pad))->Pressed.Right) {
                            FAT_screenInstrument_moveCursorRight(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                        }

                        if (((TPad*)(&__hel_Pad))->Pressed.Left) {
                            FAT_screenInstrument_moveCursorLeft(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                        }

                        if (((TPad*)(&__hel_Pad))->Pressed.Down) {
                            FAT_screenInstrument_moveCursorDown(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                        }

                        if (((TPad*)(&__hel_Pad))->Pressed.Up) {
                            FAT_screenInstrument_moveCursorUp(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                        }
                    }
                }
            }
        }

        if (((TPad*)(&__hel_Pad))->Pressed.R && ((TPad*)(&__hel_Pad))->Pressed.L) {
            FAT_screenInstrument_hideTabulationCursor();
            FAT_showHelp(6);
        }

        FAT_screenInstrument_commitCursorMove(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
    }
}






void FAT_screenInstrument_initSpritesForInstrument() {

    FAT_instrument_envdir0_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[5024])), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((0x00)<<10) | ((0)<<9) | ((0) & 0x00FF), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((0)<<10) );
# 505 "src/headers/screen_instrument.h"
    FAT_instrument_envdir1_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[5056])), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((0x00)<<10) | ((0)<<9) | ((0) & 0x00FF), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((0)<<10) );
# 520 "src/headers/screen_instrument.h"
    FAT_instrument_waveduty0_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[390976])), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0x00)<<10) | ((0)<<9) | ((0) & 0x00FF), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((0)<<10) );
# 535 "src/headers/screen_instrument.h"
    FAT_instrument_waveduty1_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[391040])), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0x00)<<10) | ((0)<<9) | ((0) & 0x00FF), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((0)<<10) );
# 550 "src/headers/screen_instrument.h"
    FAT_instrument_waveduty2_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[391104])), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0x00)<<10) | ((0)<<9) | ((0) & 0x00FF), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((0)<<10) );
# 565 "src/headers/screen_instrument.h"
    FAT_instrument_waveduty3_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[391168])), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0x00)<<10) | ((0)<<9) | ((0) & 0x00FF), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((0)<<10) );
# 579 "src/headers/screen_instrument.h"
    FAT_instrument_oscForm_sin_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[31008])), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0x00)<<10) | ((0)<<9) | ((0) & 0x00FF), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((0)<<10) );
# 594 "src/headers/screen_instrument.h"
    FAT_instrument_oscForm_square_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[31072])), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0x00)<<10) | ((0)<<9) | ((0) & 0x00FF), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((0)<<10) );
# 609 "src/headers/screen_instrument.h"
    FAT_instrument_oscForm_triangle_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[31136])), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0x00)<<10) | ((0)<<9) | ((0) & 0x00FF), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((0)<<10) );
# 624 "src/headers/screen_instrument.h"
    FAT_instrument_oscForm_saw_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[30944])), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0x00)<<10) | ((0)<<9) | ((0) & 0x00FF), ((0)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((0)<<10) );
# 639 "src/headers/screen_instrument.h"
    FAT_screenInstrument_hideAllEnvdirSprites();
    FAT_screenInstrument_hideAllWavedutySprite();
    FAT_screenInstrument_hideAllOscSprite();
}




void FAT_screenInstrument_hideAllEnvdirSprites() {

    do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_envdir0_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_envdir1_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}




void FAT_screenInstrument_hideAllWavedutySprite() {

    do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_waveduty0_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_waveduty1_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_waveduty2_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_waveduty3_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}

void FAT_screenInstrument_hideAllOscSprite(){
    do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_oscForm_sin_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_oscForm_square_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_oscForm_triangle_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_oscForm_saw_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}
# 678 "src/headers/screen_instrument.h"
void FAT_screenInstrument_showEnvdir(u8 envdirValue, u8 spriteX, u8 spriteY) {
    FAT_screenInstrument_hideAllEnvdirSprites();
    if (envdirValue == 1) {
        do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_instrument_envdir1_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((spriteX)&511) << 16) | (((spriteY)&255)); } while(0);
        do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_envdir1_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
    } else {

        do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_instrument_envdir0_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((spriteX)&511) << 16) | (((spriteY)&255)); } while(0);
        do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_envdir0_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
    }

}
# 698 "src/headers/screen_instrument.h"
void FAT_screenInstrument_showOutput(u8 x, u8 y, u8 output) {

    hel_BgTextPrintF(1, x, y, 0, "Output    %.2s", outputText[output]);
}
# 710 "src/headers/screen_instrument.h"
void FAT_screenInstrument_showWaveduty(u8 wavedutyValue, u8 spriteX, u8 spriteY) {
    FAT_screenInstrument_hideAllWavedutySprite();

    if (wavedutyValue == 0) {
        do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_instrument_waveduty0_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((spriteX)&511) << 16) | (((spriteY)&255)); } while(0);
        do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_waveduty0_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
    } else if (wavedutyValue == 1) {
        do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_instrument_waveduty1_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((spriteX)&511) << 16) | (((spriteY)&255)); } while(0);
        do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_waveduty1_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
    } else if (wavedutyValue == 2) {
        do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_instrument_waveduty2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((spriteX)&511) << 16) | (((spriteY)&255)); } while(0);
        do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_waveduty2_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
    } else if (wavedutyValue == 3) {
        do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_instrument_waveduty3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((spriteX)&511) << 16) | (((spriteY)&255)); } while(0);
        do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_waveduty3_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
    }
}
# 735 "src/headers/screen_instrument.h"
void FAT_screenInstrument_showOscForm(u8 oscFormValue, u8 spriteX, u8 spriteY) {
    FAT_screenInstrument_hideAllOscSprite();

    if (oscFormValue == 0) {
        do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_instrument_oscForm_sin_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((spriteX)&511) << 16) | (((spriteY)&255)); } while(0);
        do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_oscForm_sin_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
    } else if (oscFormValue == 1) {
        do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_instrument_oscForm_square_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((spriteX)&511) << 16) | (((spriteY)&255)); } while(0);
        do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_oscForm_square_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
    } else if (oscFormValue == 2) {
        do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_instrument_oscForm_triangle_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((spriteX)&511) << 16) | (((spriteY)&255)); } while(0);
        do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_oscForm_triangle_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
    } else if (oscFormValue == 3) {
        do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_instrument_oscForm_saw_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((spriteX)&511) << 16) | (((spriteY)&255)); } while(0);
        do { u32 *pFlags = &__hel_ObjInfo[FAT_instrument_oscForm_saw_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
    }
}






s8 FAT_screenInstrument_giveMeAddedValue() {
    s8 addedValue = 0;
    if (((TPad*)(&__hel_Pad))->Pressed.Right) {
        addedValue = 1;
    }

    if (((TPad*)(&__hel_Pad))->Pressed.Left) {
        addedValue = -1;
    }

    if (((TPad*)(&__hel_Pad))->Pressed.Up) {
        addedValue = 16;
    }

    if (((TPad*)(&__hel_Pad))->Pressed.Down) {
        addedValue = -16;
    }

    return addedValue;
}




void FAT_screenInstrument_pulse_pressA() {

    s8 addedValue = FAT_screenInstrument_giveMeAddedValue();

    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
            FAT_data_instrumentPulse_changeVolume(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 1:
            FAT_data_instrumentPulse_changeEnvelopeDirection(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 2:
            FAT_data_instrumentPulse_changeSteptime(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 3:
            FAT_data_instrumentPulse_changeWaveduty(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 4:
            FAT_data_instrumentPulse_changeLoopmode(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 5:
            FAT_data_instrumentPulse_changeSoundLength(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 6:
            FAT_data_instrumentPulse_changeOutput(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 7:
            FAT_data_instrumentPulse_changeSweep(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 8:
            FAT_data_instrument_changeSimulator(FAT_screenInstrument_currentInstrumentId, addedValue);
            if (((TPad*)(&__hel_Pad))->Pressed.A){
                FAT_data_instrument_playSimulator(FAT_screenInstrument_currentInstrumentId);
            }

            break;
    }

    FAT_screenInstrument_printAllText(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
}




void FAT_screenInstrument_wave_pressA() {
    s8 addedValue = FAT_screenInstrument_giveMeAddedValue();

    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
            FAT_data_instrumentWave_changeVolume(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 1:
            FAT_data_instrumentWave_changeLoopmode(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 2:
            FAT_data_instrumentWave_changeSoundLength(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 3:
            FAT_data_instrumentWave_changeVoice(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 4:
            FAT_data_instrumentWave_changeBank(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 5:
            FAT_data_instrumentWave_changeBankmode(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 6:
            FAT_data_instrumentWave_changeOutput(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 7:
            FAT_data_instrument_changeSimulator(FAT_screenInstrument_currentInstrumentId, addedValue);
            if (((TPad*)(&__hel_Pad))->Pressed.A){
                FAT_data_instrument_playSimulator(FAT_screenInstrument_currentInstrumentId);
            }

            break;
    }

    FAT_screenInstrument_printAllText(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
}




void FAT_screenInstrument_noise_pressA() {
    s8 addedValue = FAT_screenInstrument_giveMeAddedValue();

    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
            FAT_data_instrumentNoise_changeVolume(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 1:
            FAT_data_instrumentNoise_changeEnvelopeDirection(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 2:
            FAT_data_instrumentNoise_changeSteptime(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 3:
            FAT_data_instrumentNoise_changePolystep(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 4:
            FAT_data_instrumentNoise_changeLoopmode(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 5:
            FAT_data_instrumentNoise_changeSoundLength(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 6:
            FAT_data_instrumentNoise_changeOutput(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 7:
            FAT_data_instrument_changeSimulator(FAT_screenInstrument_currentInstrumentId, addedValue);
            if (((TPad*)(&__hel_Pad))->Pressed.A){
                FAT_data_instrument_playSimulator(FAT_screenInstrument_currentInstrumentId);
            }

            break;
    }

    FAT_screenInstrument_printAllText(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
}




void FAT_screenInstrument_sample_pressA() {
    s8 addedValue = FAT_screenInstrument_giveMeAddedValue();

    if (FAT_screenInstruments_currentSelectedColumn == 0){
        switch (FAT_screenInstruments_currentSelectedLine) {
            case 0:
                FAT_data_instrumentSample_changeKitNumber(FAT_screenInstrument_currentInstrumentId, addedValue);
                break;
            case 1:
                FAT_data_instrumentSample_changeVolume(FAT_screenInstrument_currentInstrumentId, addedValue);
                break;
            case 2:
                FAT_data_instrumentSample_changeSpeed(FAT_screenInstrument_currentInstrumentId, addedValue);
                break;
            case 3:
                FAT_data_instrumentSample_changeLooping(FAT_screenInstrument_currentInstrumentId, addedValue);
                break;
            case 4:
                FAT_data_instrumentSample_changeLoopmode(FAT_screenInstrument_currentInstrumentId, addedValue);
                break;
            case 5:
                FAT_data_instrumentSample_changeSoundLength(FAT_screenInstrument_currentInstrumentId, addedValue);
                break;
            case 6:
                FAT_data_instrumentSample_changeOffset(FAT_screenInstrument_currentInstrumentId, addedValue);
                break;
            case 7:
                FAT_data_instrumentSample_changeOutput(FAT_screenInstrument_currentInstrumentId, addedValue);
                break;
        }
    } else{
        FAT_data_instrument_changeSimulator(FAT_screenInstrument_currentInstrumentId, addedValue);
        if (((TPad*)(&__hel_Pad))->Pressed.A){
            FAT_data_instrument_playSimulator(FAT_screenInstrument_currentInstrumentId);
        }
    }

    FAT_screenInstrument_printAllText(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
}

void FAT_screenInstrument_osc_pressA() {
    s8 addedValue = FAT_screenInstrument_giveMeAddedValue();
    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
            FAT_data_instrumentOsc_changeShape(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 1:
            break;
        case 2:
            FAT_data_instrumentOsc_changeLoopmode(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 3:
            FAT_data_instrumentOsc_changeSoundLength(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 4:
            FAT_data_instrument_changeSimulator(FAT_screenInstrument_currentInstrumentId, addedValue);
            if (((TPad*)(&__hel_Pad))->Pressed.A){
                FAT_data_instrument_playSimulator(FAT_screenInstrument_currentInstrumentId);
            }
            break;
    }

    FAT_screenInstrument_printAllText(FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type);
}




void FAT_screenInstrument_pressOrHeldA() {
    u8 currentType = FAT_tracker.allInstruments[FAT_screenInstrument_currentInstrumentId].type;

    switch (currentType) {
        case 0:
        case 1:
            FAT_screenInstrument_pulse_pressA();
            break;
        case 2:
            FAT_screenInstrument_wave_pressA();
            break;
        case 3:
            FAT_screenInstrument_noise_pressA();
            break;
        case 4:
        case 5:
            FAT_screenInstrument_sample_pressA();
            break;
        case 6:
        case 7:
            FAT_screenInstrument_osc_pressA();
            break;
    }

}
# 136 "src/headers/fat.h" 2
# 1 "src/headers/screen_effects.h" 1
# 23 "src/headers/screen_effects.h"
u8 FAT_screenEffects_isPopuped = 0;


void FAT_screenEffects_init();
void FAT_screenEffects_checkButtons();




void FAT_screenEffects_init() {
    FAT_reinitScreen();


    ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[90144]), 4928, 1, 1);
    ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[88864]), 640, 0, 0);
    ham_InitBg(3, 1, 3, 0);




    FAT_player_hideAllCursors ();


}




void FAT_screenEffects_checkButtons() {
    hel_PadCapture();

    if (((TPad*)(&__hel_Pad))->Held.Select) {
        if (!FAT_screenEffects_isPopuped) {

            FAT_popup_show();
            FAT_screenEffects_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenEffects_isPopuped) {
            FAT_popup_hide();

            FAT_screenEffects_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != 7) {

                FAT_switchToScreen(FAT_popup_getSelectedIcon(), 7);
            }
        }

        if (((TPad*)(&__hel_Pad))->Pressed.Right) {
        }

        if (((TPad*)(&__hel_Pad))->Pressed.Left) {
        }

        if (((TPad*)(&__hel_Pad))->Pressed.Down) {
        }

        if (((TPad*)(&__hel_Pad))->Pressed.Up) {
        }

        if (((TPad*)(&__hel_Pad))->Pressed.A || ((TPad*)(&__hel_Pad))->Held.A) {
        }


    }
}
# 137 "src/headers/fat.h" 2
# 1 "src/headers/screen_help.h" 1
# 21 "src/headers/screen_help.h"
# 1 "src/headers/fat.h" 1
# 22 "src/headers/screen_help.h" 2



u8 FAT_screenHelp_isPopuped = 0;


u8 FAT_help_fromScreenId;


void FAT_screenHelp_init(u8 screenIdForHelp);
void FAT_screenHelp_checkButtons();




void FAT_screenHelp_init(u8 screenIdForHelp) {
    FAT_reinitScreen();


    switch (screenIdForHelp) {
        case 0:
            ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[239072]), 9984, 1, 1);
            ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[237792]), 640, 0, 0);
            break;
        case 3:
            ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[260320]), 7744, 1, 1);
            ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[259040]), 640, 0, 0);
            break;
        case 4:
            ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[113888]), 10080, 1, 1);
            ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[112608]), 640, 0, 0);
            break;
        case 5:
            ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[217504]), 10144, 1, 1);
            ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[216224]), 640, 0, 0);
            break;
        case 7:
            ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[153440]), 1760, 1, 1);
            ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[152160]), 640, 0, 0);
            break;
        case 2:
            ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[135328]), 8416, 1, 1);
            ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[134048]), 640, 0, 0);
            break;
        case 6:
            ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[175584]), 10432, 1, 1);
            ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[174304]), 640, 0, 0);
            break;
        case 8:
            ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[158240]), 8032, 1, 1);
            ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[156960]), 640, 0, 0);
            break;
        case 1:
            ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[197728]), 9248, 1, 1);
            ham_bg[3].mi = ham_InitMapSet((void*)((const void*)&__ResourceData__[196448]), 640, 0, 0);
            break;
    }
    ham_InitBg(3, 1, 3, 0);

    FAT_player_hideAllCursors ();
    FAT_cursors_hideAllCursors();

    isHelpActivated = 1;
    FAT_currentScreen = 9;
    FAT_help_fromScreenId = screenIdForHelp;

    FAT_popup_hide();
}




void FAT_screenHelp_checkButtons() {
    hel_PadCapture();

    if (((TPad*)(&__hel_Pad))->Pressed.B) {
        isHelpActivated = 0;
        FAT_switchToScreen(FAT_help_fromScreenId, 9);
    }

}
# 138 "src/headers/fat.h" 2

# 1 "src/headers/player.h" 1
# 36 "src/headers/player.h"
u8 actualBlocksForChannel[6];

u8 actualNotesForChannel[6];

u8 FAT_currentPlayedSequence = 0xff;

u8 FAT_currentPlayedChannel = 0xff;

u8 FAT_currentPlayedBlock = 0xff;

bufferPlayer FAT_player_buffer[6];
u8 firstAvailableSequenceForChannel[6];
# 56 "src/headers/player.h"
volatile int tempoReach = (60000 / 128) * 4;




volatile int tickCounter = (60000 / 100) * 4;




u8 FAT_player_isPlayingFrom;




u8 FAT_live_waitForOtherChannel[6];




void FAT_player_playFromSequences();



void FAT_player_playFromBlocks();



void FAT_player_playFromNotes();

void FAT_player_playNote(note* note, u8 channel, u8 forceVolume);
void FAT_player_playNoteWithCustomParams(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output);


void FAT_player_playNoteWithCustomParams_chan1(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output);
void FAT_player_playNoteWithCustomParams_chan2(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output);
void FAT_player_playNoteWithCustomParams_chan3(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output);
void FAT_player_playNoteWithCustomParams_chan4(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output);
void FAT_player_playNoteWithCustomParams_chan5(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output);
void FAT_player_playNoteWithCustomParams_chan6(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output);

void (*FAT_player_playNoteWithCustomParams_chanX[6]) (note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output);


void FAT_player_timerFunc();
void FAT_resetTempo ();
void FAT_player_firstInit ();

# 1 "src/headers/player_cursors.h" 1
# 14 "src/headers/player_cursors.h"
void FAT_player_initCursors();
void FAT_player_live_showOrHideCursorWait(u8 channel);
void FAT_player_hideWaitCursors ();
void FAT_player_hideSequencesCursors();
void FAT_player_hideBlockCursor();
void FAT_player_hideNoteCursor();






void FAT_player_initCursors() {

    FAT_cursor_player3_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[1184])), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0x01)<<10) | ((0)<<9) | ((0) & 0x00FF), ((2)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((3)<<10) );
# 43 "src/headers/player_cursors.h"
    FAT_cursor_player2_obj = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[416])), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0x01)<<10) | ((0)<<9) | ((0) & 0x00FF), ((2)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((3)<<10) );
# 58 "src/headers/player_cursors.h"
    FAT_cursor_playerLiveWait_obj[0] = hel_ObjCreateEx ( (void*)(((const void*)&__ResourceData__[672])), ((1)<<14) | ((0)<<13) | ((0)<<12) | ((0x01)<<10) | ((0)<<9) | ((0) & 0x00FF), ((2)<<14) | ((0)<<13) | ((0)<<12) | ((0) & 0x01FF), ((0)<<12) | ((3)<<10) );
# 73 "src/headers/player_cursors.h"
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_player3_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_player2_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerLiveWait_obj[0]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);


    u8 i;
    for (i = 0; i < 6; i++) {
        FAT_cursor_playerSequences_obj[i] = hel_ObjClone(FAT_cursor_player2_obj, 0, 0);
        do { u16 *pAttr = &__hel_ObjInfo[FAT_cursor_playerSequences_obj[i]].Attr[2]; *pAttr &= 0xF3FF; *pAttr |= ((3) << 10); } while(0);
    }

    for (i = 1; i < 6; i++) {
        FAT_cursor_playerLiveWait_obj[i] = hel_ObjClone(FAT_cursor_playerLiveWait_obj[0], 0, 0);
        do { u16 *pAttr = &__hel_ObjInfo[FAT_cursor_playerLiveWait_obj[i]].Attr[2]; *pAttr &= 0xF3FF; *pAttr |= ((3) << 10); } while(0);
    }
}




void FAT_player_hideAllCursors() {
    FAT_player_hideNoteCursor();
    FAT_player_hideBlockCursor();
    FAT_player_hideWaitCursors ();
    FAT_player_hideSequencesCursors();
}




void FAT_player_hideSequencesCursors() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerSequences_obj[0]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerSequences_obj[1]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerSequences_obj[2]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerSequences_obj[3]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerSequences_obj[4]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerSequences_obj[5]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}

void FAT_player_hideWaitCursors (){
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerLiveWait_obj[0]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerLiveWait_obj[1]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerLiveWait_obj[2]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerLiveWait_obj[3]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerLiveWait_obj[4]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerLiveWait_obj[5]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}




void FAT_player_hideBlockCursor() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_player2_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}




void FAT_player_hideNoteCursor() {
    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_player3_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
}


void FAT_player_live_showOrHideCursorWait(u8 channel){
    if (FAT_currentScreen == 1){
        if (FAT_isChannelCurrentlyPlaying(channel) && actualSequencesForChannel[channel] < 64
            && actualSequencesForChannel[channel] >= FAT_screenLive_currentStartLine && !isHelpActivated
            && FAT_live_waitForOtherChannel[channel] == 1){

            u8 yPosition = 15 + ((actualSequencesForChannel[channel] - FAT_screenSong_currentStartLine)*8);
            if (yPosition < 140){
                do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor_playerLiveWait_obj[channel]]; *pAttr &= 0xfe00ff00; *pAttr |= (((23 + (channel * (8 + 16)))&511) << 16) | (((yPosition)&255)); } while(0);


                do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerLiveWait_obj[channel]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
            } else {
                do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerLiveWait_obj[channel]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
            }
        } else {
            do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerLiveWait_obj[channel]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
        }

    }
}






void FAT_player_moveOrHideCursor(u8 channel) {

    switch (FAT_currentScreen) {
        case 3:
            FAT_player_hideBlockCursor();
            FAT_player_hideNoteCursor();
            if (actualSequencesForChannel[channel] != 0xff && actualSequencesForChannel[channel] < 64
                    && actualSequencesForChannel[channel] >= FAT_screenSong_currentStartLine && !isHelpActivated) {


                u8 yPosition = 15 + ((actualSequencesForChannel[channel] - FAT_screenSong_currentStartLine)*8);
                if (yPosition < 140){
                    do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor_playerSequences_obj[channel]]; *pAttr &= 0xfe00ff00; *pAttr |= (((23 + (channel * (8 + 16)))&511) << 16) | (((yPosition)&255)); } while(0);


                    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerSequences_obj[channel]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
                } else {
                    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerSequences_obj[channel]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
                }

            } else {
                do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerSequences_obj[channel]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
            }


            break;
        case 1:

            FAT_player_hideBlockCursor();
            FAT_player_hideNoteCursor();
            if (actualSequencesForChannel[channel] != 0xff && actualSequencesForChannel[channel] < 64
                    && actualSequencesForChannel[channel] >= FAT_screenLive_currentStartLine && !isHelpActivated) {


                u8 yPosition = 15 + ((actualSequencesForChannel[channel] - FAT_screenSong_currentStartLine)*8);

                if (yPosition < 90){
                    do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor_playerSequences_obj[channel]]; *pAttr &= 0xfe00ff00; *pAttr |= (((23 + (channel * (8 + 16)))&511) << 16) | (((15 + ((actualSequencesForChannel[channel] - FAT_screenLive_currentStartLine)*8))&255)); } while(0);



                    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerSequences_obj[channel]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
                } else {
                    do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerSequences_obj[channel]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
                }

            } else {
                do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerSequences_obj[channel]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
            }
            break;
        case 4:
            FAT_player_hideSequencesCursors();
            FAT_player_hideNoteCursor();
            if (actualBlocksForChannel[channel] != 0xff &&
                    FAT_currentPlayedSequence == FAT_screenBlocks_currentSequenceId && !isHelpActivated) {
                do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor_player2_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((23)&511) << 16) | (((15 + (actualBlocksForChannel[channel]*8))&255)); } while(0);
                do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_player2_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
            } else {
                FAT_player_hideBlockCursor();
            }

            break;
        case 5:
            FAT_player_hideSequencesCursors();
            FAT_player_hideBlockCursor();
            if (actualNotesForChannel[channel] != 0xff
                    && FAT_currentPlayedBlock == FAT_screenNotes_currentBlockId && !isHelpActivated) {
                do { u32 *pAttr = (u32*)&__hel_ObjInfo[FAT_cursor_player3_obj]; *pAttr &= 0xfe00ff00; *pAttr |= (((23)&511) << 16) | (((15 + (actualNotesForChannel[channel]*8))&255)); } while(0);
                do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_player3_obj].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((1)<<9); } while(0);
            } else {
                FAT_player_hideNoteCursor();
            }
            break;
        default:
            FAT_player_hideAllCursors();
            break;
    }

}
# 105 "src/headers/player.h" 2

void FAT_player_firstInit (){
    u8 i;
    *(volatile u16 *)(0x04000000 + 0x10E) = 0x0003;

    memset(actualSequencesForChannel, 0xff, sizeof (u8)*6);
    memset(actualBlocksForChannel, 0, sizeof (u8)*6);
    memset(actualNotesForChannel, 0, sizeof (u8)*6);
    memset(firstAvailableSequenceForChannel, 0, sizeof (u8)*6);
    memset(FAT_live_waitForOtherChannel, 0, sizeof (u8)*6);
    memset(FAT_player_buffer, 0, sizeof(bufferPlayer)*6);
    for (i=0;i<6;i++){
        FAT_player_buffer[i].volume = 0xff;
        FAT_player_buffer[i].sweep = 0xff;
        FAT_player_buffer[i].output = 0xff;
    }

    FAT_player_playNoteWithCustomParams_chanX[0] = FAT_player_playNoteWithCustomParams_chan1;
    FAT_player_playNoteWithCustomParams_chanX[1] = FAT_player_playNoteWithCustomParams_chan2;
    FAT_player_playNoteWithCustomParams_chanX[2] = FAT_player_playNoteWithCustomParams_chan3;
    FAT_player_playNoteWithCustomParams_chanX[3] = FAT_player_playNoteWithCustomParams_chan4;
    FAT_player_playNoteWithCustomParams_chanX[4] = FAT_player_playNoteWithCustomParams_chan5;
    FAT_player_playNoteWithCustomParams_chanX[5] = FAT_player_playNoteWithCustomParams_chan6;

    FAT_player_initCursors();
    FAT_resetTempo();
}






void FAT_player_playComposerNote(u8 noteLine) {
    note* note = &(FAT_tracker.composer.notes[noteLine]);

    if (note->freq != 0xff) {

        FAT_player_playNoteWithCustomParams( note,
                                                FAT_tracker.composer.channels[noteLine],
                                                FAT_tracker.composer.transpose + FAT_tracker.transpose,
                                                0xff, 0xff, 0xff);
    }
}
# 158 "src/headers/player.h"
void FAT_player_playNote(note* note, u8 channel, u8 forceVolume) {

        if (channel > 5){
                channel -= 2;
        }
    FAT_player_playNoteWithCustomParams(note, channel, FAT_tracker.transpose, forceVolume, 0xff, 0xff);
}

void FAT_player_playNoteWithCustomParams_chan1(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output){

    instrument* inst = &(FAT_tracker.allInstruments[note->instrument]);

    u8 sweepValue = sweep != 0xff ? sweep : inst->sweep;
    u16 sweepshifts = (sweepValue & 0x70) >> 4;
    u16 sweeptime = (sweepValue & 0x0F);
    u16 sweepdir = 1;
    if (sweeptime > 7) {
        sweeptime -= 8;
        sweepdir = 0;
    }

    snd_playSoundOnChannel1(
        sweeptime, sweepdir, sweepshifts,
        volume != 0xff ? volume : inst->envelope & 0x0f, (inst->envelope & 0x10) >> 4, (inst->envelope & 0xe0) >> 5, inst->wavedutyOrPolynomialStep,
        inst->soundlength, inst->loopmode,
        output,
        note->freq, transpose + FAT_tracker.transpose);

}
void FAT_player_playNoteWithCustomParams_chan2(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output){

    instrument* inst = &(FAT_tracker.allInstruments[note->instrument]);

    snd_playSoundOnChannel2(
        volume != 0xff ? volume : inst->envelope & 0x0f, (inst->envelope & 0x10) >> 4, (inst->envelope & 0xe0) >> 5,
        inst->wavedutyOrPolynomialStep,
        inst->soundlength, inst->loopmode,
        output,
        note->freq, transpose + FAT_tracker.transpose);

}
void FAT_player_playNoteWithCustomParams_chan3(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output){

    instrument* inst = &(FAT_tracker.allInstruments[note->instrument]);
    volume = (volume > 0x4) ? 0xff : volume;

    snd_playSoundOnChannel3(
        volume != 0xff ? volume : inst->volumeRatio & 0x0f, inst->soundlength, inst->loopmode, inst->voiceAndBank & 0x1f,
        (inst->voiceAndBank & 0x20) >> 5, (inst->voiceAndBank & 0x40) >> 6,
        output, note->freq, transpose + FAT_tracker.transpose);

}
void FAT_player_playNoteWithCustomParams_chan4(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output){

    instrument* inst = &(FAT_tracker.allInstruments[note->instrument]);

    snd_playSoundOnChannel4(
        volume != 0xff ? volume : inst->envelope & 0x0f, (inst->envelope & 0x10) >> 4, (inst->envelope & 0xe0) >> 5, inst->soundlength,
        inst->loopmode, output, note->note & 0x0f, inst->wavedutyOrPolynomialStep,
        note->freq / 72, transpose + FAT_tracker.transpose);

}
void FAT_player_playNoteWithCustomParams_chan5(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output){
    instrument* inst = &(FAT_tracker.allInstruments[note->instrument]);

    if (inst->type > 5){

        snd_playOscillatorA (inst->wavedutyOrPolynomialStep, note->freq, inst->loopmode, inst->soundlength);
    } else {
        snd_playChannelASample(
            inst->kitNumber, note->freq, inst->volumeRatio >> 4,
            inst->speedOrLooping & 0x0f, inst->speedOrLooping >> 4,
            inst->loopmode, inst->soundlength, inst->offset, output);
    }
}
void FAT_player_playNoteWithCustomParams_chan6(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output){
    instrument* inst = &(FAT_tracker.allInstruments[note->instrument]);

    if (inst->type > 5){

        snd_playOscillatorB (inst->wavedutyOrPolynomialStep, note->freq, inst->loopmode, inst->soundlength);
    } else {
        snd_playChannelBSample(
            inst->kitNumber, note->freq, inst->volumeRatio >> 4,
            inst->speedOrLooping & 0x0f, inst->speedOrLooping >> 4,
            inst->loopmode, inst->soundlength, inst->offset, output);
    }
}
# 254 "src/headers/player.h"
void FAT_player_playNoteWithCustomParams(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output) {
    if (note->freq != 0xff) {
        instrument* inst = &(FAT_tracker.allInstruments[note->instrument]);
        u8 outputValue = output != 0xff ? output : inst->output;


        (*FAT_player_playNoteWithCustomParams_chanX[channel]) (note,channel,transpose,volume,sweep,outputValue);
    }

    if (note->effect.name != 0xff) {
        snd_tryToApplyEffect(channel, noteEffectNum[note->effect.name >> 1], note->effect.value);
    }
}

u8 FAT_player_searchFirstAvailableSequenceForChannel_returnLine (u8 channel, u8 startingLine){
    s8 i = startingLine;
    u8 firstLine = 0xff;


    while (i < 0x40){
        if (FAT_tracker.channels[channel].sequences[i] != 0xff){
            firstLine = i;
            break;
        }
        i++;
    }


    if (firstLine == 0xff){
        i = 0;
        while (i < startingLine){
            if (FAT_tracker.channels[channel].sequences[i] != 0xff){
                firstLine = i;
                break;
            }
            i++;
        }
    }



    if (FAT_tracker.greedPlay){
        if (firstLine != 0xff){
            i = firstLine;
            while (i >= 0){
                if (FAT_tracker.channels[channel].sequences[i] == 0xff){
                    break;
                }
                firstLine = i;
                i--;
            }
        }
    }

    return firstLine;
}




void FAT_player_startPlayerFromSequences(u8 startLine) {


    memset(actualSequencesForChannel, 0xff, sizeof (u8)*6);
    memset(actualBlocksForChannel, 0, sizeof (u8)*6);
    memset(actualNotesForChannel, 0, sizeof (u8)*6);
    memset(firstAvailableSequenceForChannel, 0, sizeof (u8)*6);

    FAT_resetTempo ();
    FAT_isCurrentlyPlaying = 1;
    FAT_live_nbChannelPlaying = 0;
    FAT_player_isPlayingFrom = 3;


    u8 i;
    for (i = 0; i<6; i++){
        firstAvailableSequenceForChannel[i] = FAT_player_searchFirstAvailableSequenceForChannel_returnLine(i, startLine);
        actualSequencesForChannel[i] = firstAvailableSequenceForChannel[i];
        if (actualSequencesForChannel[i]!=0xff){
            FAT_live_nbChannelPlaying++;
        }
        FAT_player_moveOrHideCursor(i);
    }

    *(volatile u16 *)(0x04000000 + 0x10C) = 0xffff;
    hel_IntrStartHandler(6, (void*) &FAT_player_timerFunc);
    *(volatile u16 *)(0x04000000 + 0x10E) = 0x00C3;
}

void FAT_player_startPlayerFromLive_oneChannel(u8 line, u8 channel){

    if (!FAT_isCurrentlyPlaying){
        memset(actualSequencesForChannel, 0xff, sizeof (u8)*6);
        memset(actualBlocksForChannel, 0, sizeof (u8)*6);
        memset(actualNotesForChannel, 0, sizeof (u8)*6);
        memset(firstAvailableSequenceForChannel, 0, sizeof (u8)*6);


        memset (FAT_live_waitForOtherChannel, 1, sizeof(u8)*6);
        FAT_live_waitForOtherChannel[channel] = 0;

        FAT_resetTempo ();

        FAT_isCurrentlyPlaying = 1;
        FAT_live_nbChannelPlaying = 0;
    }

    FAT_player_isPlayingFrom = 1;


    firstAvailableSequenceForChannel[channel] = FAT_player_searchFirstAvailableSequenceForChannel_returnLine(channel, line);
    actualSequencesForChannel[channel] = firstAvailableSequenceForChannel[channel];
    actualBlocksForChannel[channel] = 0;
    actualNotesForChannel[channel] = 0;
    FAT_live_nbChannelPlaying ++;

    if (FAT_live_waitForOtherChannel[channel] == 0){
        FAT_player_moveOrHideCursor(channel);

        *(volatile u16 *)(0x04000000 + 0x10C) = 0xffff;
        hel_IntrStartHandler(6, (void*) &FAT_player_timerFunc);
        *(volatile u16 *)(0x04000000 + 0x10E) = 0x00C3;
    }
}
# 386 "src/headers/player.h"
void FAT_player_startPlayerFromBlocks(u8 sequenceId, u8 startLine, u8 channel) {


    memset(actualSequencesForChannel, 0xff, sizeof (u8)*6);
    memset(actualBlocksForChannel, 0, sizeof (u8)*6);
    memset(actualNotesForChannel, 0, sizeof (u8)*6);
    actualBlocksForChannel[channel] = startLine;
    FAT_currentPlayedSequence = sequenceId;
    FAT_currentPlayedChannel = channel;

    FAT_resetTempo ();
    FAT_isCurrentlyPlaying = 1;
    FAT_player_isPlayingFrom = 4;

    *(volatile u16 *)(0x04000000 + 0x10C) = 0xffff;
    hel_IntrStartHandler(6, (void*) &FAT_player_timerFunc);
    *(volatile u16 *)(0x04000000 + 0x10E) = 0x00C3;

}
# 413 "src/headers/player.h"
void FAT_player_startPlayerFromNotes(u8 blockId, u8 startLine, u8 channel) {

    memset(actualSequencesForChannel, 0xff, sizeof (u8)*6);
    memset(actualBlocksForChannel, 0xff, sizeof (u8)*6);
    memset(actualNotesForChannel, 0, sizeof (u8)*6);
    actualNotesForChannel[channel] = startLine;
    FAT_currentPlayedBlock = blockId;
    FAT_currentPlayedChannel = channel;

    FAT_resetTempo ();
    FAT_isCurrentlyPlaying = 1;
    FAT_player_isPlayingFrom = 5;

    *(volatile u16 *)(0x04000000 + 0x10C) = 0xffff;
    hel_IntrStartHandler(6, (void*) &FAT_player_timerFunc);
    *(volatile u16 *)(0x04000000 + 0x10E) = 0x00C3;

}

void __attribute__ ((section (".iwram"), long_call)) FAT_player_timerFunc() {
    if (tempoReach > 0) {
        tempoReach--;
    }
    tickCounter--;
}

void FAT_player_progressInSong(u8 channel, sequence* seq){
    actualNotesForChannel[channel]++;
    if (actualNotesForChannel[channel] >= 16) {
        actualNotesForChannel[channel] = 0;
        actualBlocksForChannel[channel]++;
        if (actualBlocksForChannel[channel] >= 16
                || seq->blocks[actualBlocksForChannel[channel]] == 0xff) {
            actualBlocksForChannel[channel] = 0;

            actualSequencesForChannel[channel]++;
            if (actualSequencesForChannel[channel] > 64
                    || FAT_tracker.channels[channel].sequences[actualSequencesForChannel[channel]] == 0xff
                    || FAT_data_isSequenceEmpty(FAT_tracker.channels[channel].sequences[actualSequencesForChannel[channel]])) {

                actualSequencesForChannel[channel] = firstAvailableSequenceForChannel[channel];
            }
        }
    }
}

void FAT_player_progressInSequence (sequence* seq){
    actualNotesForChannel[FAT_currentPlayedChannel]++;
    if (actualNotesForChannel[FAT_currentPlayedChannel] >= 16) {
        actualNotesForChannel[FAT_currentPlayedChannel] = 0;

        actualBlocksForChannel[FAT_currentPlayedChannel]++;
        if (actualBlocksForChannel[FAT_currentPlayedChannel] >= 16
                || seq->blocks[actualBlocksForChannel[FAT_currentPlayedChannel]] == 0xff) {
            actualBlocksForChannel[FAT_currentPlayedChannel] = 0;
        }
    }
}

void FAT_player_progressInBlock (){
    actualNotesForChannel[FAT_currentPlayedChannel]++;
    if (actualNotesForChannel[FAT_currentPlayedChannel] >= 16) {
        actualNotesForChannel[FAT_currentPlayedChannel] = 0;
    }
}


void FAT_player_playFromSequences() {



    if (tempoReach <= 0) {
        tempoReach = 0;
        hel_BgTextPrintF(1, 26, 16, 0, "TICK");
        u8 i;
        for (i = 0; i < 6; i++) {
            FAT_player_buffer[i].haveToPlay = 0;
            FAT_player_buffer[i].volume = 0xff;
            FAT_player_buffer[i].sweep = 0xff;
            FAT_player_buffer[i].output = 0xff;
            if (FAT_isChannelCurrentlyPlaying(i) && actualSequencesForChannel[i] < 64){
                FAT_currentPlayedSequence = FAT_tracker.channels[i].sequences[actualSequencesForChannel[i]];
                if (FAT_currentPlayedSequence != 0xff) {

                    sequence* seq = &(FAT_tracker.allSequences[FAT_currentPlayedSequence]);

                    FAT_currentPlayedBlock = seq->blocks[actualBlocksForChannel[i]];
                    if (FAT_currentPlayedBlock != 0xff) {
                        block* block = &(FAT_tracker.allBlocks[FAT_currentPlayedBlock]);

                        effect* effect = FAT_data_note_getEffect(FAT_currentPlayedBlock, actualNotesForChannel[i]);
                        if (effect){
                            switch (((effect->name & 0xfe) >> 1)){
                                case 4:
                                    FAT_player_buffer[i].volume = effect->value;
                                    break;
                                case 3:
                                    FAT_player_buffer[i].sweep = effect->value;
                                    break;
                                case 2:
                                    FAT_player_buffer[i].output = effect->value;
                                    break;
                                case 0:

                                    actualNotesForChannel[i] = effect->value;
                                    actualBlocksForChannel[i]++;
                                    if (actualBlocksForChannel[i] >= 16
                                            || seq->blocks[actualBlocksForChannel[i]] == 0xff) {
                                        actualBlocksForChannel[i] = 0;

                                        actualSequencesForChannel[i]++;
                                        if (actualSequencesForChannel[i] > 64
                                                || FAT_tracker.channels[i].sequences[actualSequencesForChannel[i]] == 0xff
                                                || FAT_data_isSequenceEmpty(FAT_tracker.channels[i].sequences[actualSequencesForChannel[i]])) {

                                            actualSequencesForChannel[i] = firstAvailableSequenceForChannel[i];
                                        }
                                    }

                                    FAT_currentPlayedBlock = seq->blocks[actualBlocksForChannel[i]];
                                    block = &(FAT_tracker.allBlocks[FAT_currentPlayedBlock]);
                                    break;
                            }
                        }

                        FAT_player_buffer[i].note = &(block->notes[actualNotesForChannel[i]]);
                        FAT_player_buffer[i].transpose = seq->transpose[actualBlocksForChannel[i]];
                        FAT_player_buffer[i].haveToPlay = 1;

                        FAT_player_progressInSong (i, seq);


                        FAT_player_moveOrHideCursor(i);

                    } else {
                        actualBlocksForChannel[i] = 0;
                        actualSequencesForChannel[i]++;
                        if (actualSequencesForChannel[i] > 64) {
                            actualSequencesForChannel[i] = firstAvailableSequenceForChannel[i];
                        }
                        FAT_player_moveOrHideCursor(i);
                    }

                } else {
                    actualSequencesForChannel[i] = firstAvailableSequenceForChannel[i];
                    FAT_player_moveOrHideCursor(i);
                }
            }

        }

        for (i = 0; i < 6; i++) {
            if (FAT_player_buffer[i].haveToPlay){
                FAT_player_playNoteWithCustomParams(
                   FAT_player_buffer[i].note , i,
                   FAT_player_buffer[i].transpose,
                   FAT_player_buffer[i].volume,
                   FAT_player_buffer[i].sweep,
                   FAT_player_buffer[i].output);
            }
        }
        FAT_resetTempo ();
    }else {hel_BgTextPrintF(1, 26, 16, 0, "    ");}
}

void FAT_player_liveSynchro(){
    u8 j;
    for (j=0;j<6;j++){
        if(FAT_isChannelCurrentlyPlaying(j)){
            FAT_live_waitForOtherChannel[j] = 0;
            FAT_player_moveOrHideCursor(j);
        }
    }
}

void FAT_player_playFromLive(){



    if (tempoReach <= 0) {
        tempoReach = 0;
        hel_BgTextPrintF(1, 26, 16, 0, "TICK");
        u8 willHaveToSyncAfterNote = 0;
        u8 i;
        for (i = 0; i < 6; i++) {
            FAT_player_buffer[i].haveToPlay = 0;
            FAT_player_buffer[i].volume = 0xff;
            FAT_player_buffer[i].sweep = 0xff;
            FAT_player_buffer[i].output = 0xff;
            if (FAT_isChannelCurrentlyPlaying(i) && actualSequencesForChannel[i] < 64 && FAT_live_waitForOtherChannel[i] == 0){

                FAT_currentPlayedSequence = FAT_tracker.channels[i].sequences[actualSequencesForChannel[i]];

                if (FAT_currentPlayedSequence != 0xff) {

                    sequence* seq = &(FAT_tracker.allSequences[FAT_currentPlayedSequence]);

                    FAT_currentPlayedBlock = seq->blocks[actualBlocksForChannel[i]];
                    if (FAT_currentPlayedBlock != 0xff) {
                        block* block = &(FAT_tracker.allBlocks[FAT_currentPlayedBlock]);

                        effect* effect = FAT_data_note_getEffect(FAT_currentPlayedBlock, actualNotesForChannel[i]);
                        if (effect){
                            switch (((effect->name & 0xfe) >> 1)){
                                case 4:
                                    FAT_player_buffer[i].volume = effect->value;
                                    break;
                                case 3:
                                    FAT_player_buffer[i].sweep = effect->value;
                                    break;
                                case 2:
                                    FAT_player_buffer[i].output = effect->value;
                                    break;
                                case 0:

                                    actualNotesForChannel[i] = effect->value;
                                    actualBlocksForChannel[i]++;
                                    if (actualBlocksForChannel[i] >= 16
                                            || seq->blocks[actualBlocksForChannel[i]] == 0xff) {
                                        actualBlocksForChannel[i] = 0;

                                        if (!FAT_tracker.liveData.liveMode){
                                            actualSequencesForChannel[i]++;
                                            if (actualSequencesForChannel[i] > 64
                                                    || FAT_tracker.channels[i].sequences[actualSequencesForChannel[i]] == 0xff
                                                    || FAT_data_isSequenceEmpty(FAT_tracker.channels[i].sequences[actualSequencesForChannel[i]])) {

                                                actualSequencesForChannel[i] = firstAvailableSequenceForChannel[i];

                                            }
                                        }
                                        willHaveToSyncAfterNote = 1;

                                        FAT_player_moveOrHideCursor(i);
                                    }

                                    FAT_currentPlayedBlock = seq->blocks[actualBlocksForChannel[i]];
                                    block = &(FAT_tracker.allBlocks[FAT_currentPlayedBlock]);
                                    break;
                            }
                        }

                        FAT_player_buffer[i].note = &(block->notes[actualNotesForChannel[i]]);
                        FAT_player_buffer[i].transpose = seq->transpose[actualBlocksForChannel[i]];
                        FAT_player_buffer[i].haveToPlay = 1;

                        actualNotesForChannel[i]++;
                        if (actualNotesForChannel[i] >= 16) {
                            actualNotesForChannel[i] = 0;
                            actualBlocksForChannel[i]++;
                            if (actualBlocksForChannel[i] >= 16
                                    || seq->blocks[actualBlocksForChannel[i]] == 0xff) {
                                actualBlocksForChannel[i] = 0;

                                if (!FAT_tracker.liveData.liveMode){
                                    actualSequencesForChannel[i]++;
                                    if (actualSequencesForChannel[i] > 64
                                            || FAT_tracker.channels[i].sequences[actualSequencesForChannel[i]] == 0xff
                                            || FAT_data_isSequenceEmpty(FAT_tracker.channels[i].sequences[actualSequencesForChannel[i]])) {

                                        actualSequencesForChannel[i] = firstAvailableSequenceForChannel[i];

                                    }
                                }
                                willHaveToSyncAfterNote = 1;

                                FAT_player_moveOrHideCursor(i);
                            }
                        }
                    } else {
                        actualBlocksForChannel[i] = 0;

                        if (!FAT_tracker.liveData.liveMode){
                            actualSequencesForChannel[i]++;
                            if (actualSequencesForChannel[i] > 64) {
                                actualSequencesForChannel[i] = firstAvailableSequenceForChannel[i];
                            }
                            FAT_player_moveOrHideCursor(i);
                        }

                        willHaveToSyncAfterNote = 1;
                    }

                } else if (!FAT_tracker.liveData.liveMode){
                    actualSequencesForChannel[i] = firstAvailableSequenceForChannel[i];
                    willHaveToSyncAfterNote = 1;
                    FAT_player_moveOrHideCursor(i);
                }
            }

            FAT_player_live_showOrHideCursorWait (i);

        }

        u8 volume = 0xff;
        for (i = 0; i < 6; i++) {
            if (FAT_player_buffer[i].haveToPlay){


                if (FAT_tracker.liveData.volume[i] == 0xff){
                    volume = FAT_player_buffer[i].volume;
                } else if (FAT_player_buffer[i].volume == 0xff){
                    volume = FAT_tracker.liveData.volume[i];
                } else {
                    volume = (FAT_player_buffer[i].volume + FAT_tracker.liveData.volume[i])/2;
                }

                FAT_player_playNoteWithCustomParams(
                   FAT_player_buffer[i].note , i,
                   FAT_player_buffer[i].transpose + FAT_tracker.liveData.transpose[i],
                   volume, FAT_player_buffer[i].sweep, FAT_player_buffer[i].output);
            }
        }

        if (willHaveToSyncAfterNote){
            FAT_player_liveSynchro();
        }

        FAT_resetTempo ();
    }else {hel_BgTextPrintF(1, 26, 16, 0, "    ");}
}


void FAT_player_playFromBlocks() {



    u8 volume=0xff;
    u8 sweep = 0xff;
    u8 output = 0xff;
    if (tempoReach <= 0) {
        tempoReach = 0;
        hel_BgTextPrintF(1, 26, 16, 0, "TICK");
        if (FAT_currentPlayedSequence != 0xff) {

            sequence* seq = &(FAT_tracker.allSequences[FAT_currentPlayedSequence]);

            FAT_currentPlayedBlock = seq->blocks[actualBlocksForChannel[FAT_currentPlayedChannel]];
            if (FAT_currentPlayedBlock != 0xff) {
                block* block = &(FAT_tracker.allBlocks[FAT_currentPlayedBlock]);


                FAT_player_moveOrHideCursor(FAT_currentPlayedChannel);

                effect* effect = FAT_data_note_getEffect(FAT_currentPlayedBlock, actualNotesForChannel[FAT_currentPlayedChannel]);
                volume = 0xff; sweep = 0xff; output = 0xff;
                if (effect){
                    switch (((effect->name & 0xfe) >> 1)){
                        case 4:
                            volume = effect->value;
                            break;
                        case 3:
                            sweep = effect->value;
                            break;
                        case 2:
                            output = effect->value;
                            break;
                        case 0:

                            actualNotesForChannel[FAT_currentPlayedChannel] = effect->value;
                            actualBlocksForChannel[FAT_currentPlayedChannel]++;
                            if (actualBlocksForChannel[FAT_currentPlayedChannel] >= 16
                                    || seq->blocks[actualBlocksForChannel[FAT_currentPlayedChannel]] == 0xff) {
                                actualBlocksForChannel[FAT_currentPlayedChannel] = 0;
                            }
                            FAT_currentPlayedBlock = seq->blocks[actualBlocksForChannel[FAT_currentPlayedChannel]];
                            block = &(FAT_tracker.allBlocks[FAT_currentPlayedBlock]);
                            break;
                    }
                }

                FAT_player_playNoteWithCustomParams(&(block->notes[actualNotesForChannel[FAT_currentPlayedChannel]]), FAT_currentPlayedChannel,
                        seq->transpose[actualBlocksForChannel[FAT_currentPlayedChannel]], volume, sweep, output);

                FAT_player_progressInSequence (seq);
            } else {
                actualBlocksForChannel[FAT_currentPlayedChannel] = 0;
            }

        }

        FAT_resetTempo ();
    }else {hel_BgTextPrintF(1, 26, 16, 0, "    ");}

}




void FAT_player_playFromNotes() {



    u8 volume=0xff;
    u8 sweep = 0xff;
    u8 output = 0xff;
    if (tempoReach <= 0) {
        tempoReach = 0;
        hel_BgTextPrintF(1, 26, 16, 0, "TICK");
        if (FAT_currentPlayedBlock != 0xff) {
            block* block = &(FAT_tracker.allBlocks[FAT_currentPlayedBlock]);


            FAT_player_moveOrHideCursor(FAT_currentPlayedChannel);

            effect* effect = FAT_data_note_getEffect(FAT_currentPlayedBlock, actualNotesForChannel[FAT_currentPlayedChannel]);
            volume = 0xff; sweep = 0xff; output = 0xff;
            if (effect){
                switch (((effect->name & 0xfe) >> 1)){
                    case 4:
                        volume = effect->value;
                        break;
                    case 3:
                        sweep = effect->value;
                        break;
                    case 2:
                        output = effect->value;
                        break;
                    case 0:

                        actualNotesForChannel[FAT_currentPlayedChannel] = effect->value;
                        break;
                }
            }

            FAT_player_playNoteWithCustomParams(&(block->notes[actualNotesForChannel[FAT_currentPlayedChannel]]),
                    FAT_currentPlayedChannel, 0, volume, sweep, output);

            FAT_player_progressInBlock ();
        }

        FAT_resetTempo ();

    }else {hel_BgTextPrintF(1, 26, 16, 0, "    ");}

}

void FAT_player_continueToPlay() {
    switch (FAT_player_isPlayingFrom) {
        case 3:
            FAT_player_playFromSequences();
            break;
        case 1:
            FAT_player_playFromLive();
            break;
        case 4:
            FAT_player_playFromBlocks();
            break;
        case 5:
            FAT_player_playFromNotes();
            break;
    }
}




void FAT_player_stopPlayer_onlyOneColumn(u8 channel){
    actualSequencesForChannel[channel] = 0xff;
    actualBlocksForChannel[channel] = 0;
    actualNotesForChannel[channel] = 0;
    firstAvailableSequenceForChannel[channel] = 0;
    FAT_live_waitForOtherChannel[channel] = 1;

    FAT_live_nbChannelPlaying --;


    if (FAT_live_nbChannelPlaying == 0){
        FAT_player_stopPlayer();
    } else {
        memset(&FAT_player_buffer[channel], 0, sizeof(bufferPlayer));
        FAT_player_buffer[channel].volume = 0xff;
        snd_effect_kill (channel, 0x00);
        do { u32 *pFlags = &__hel_ObjInfo[FAT_cursor_playerSequences_obj[channel]].Flags; *pFlags &= ~(1<<(9)); *pFlags |= ((0)<<9); } while(0);
    }
}

u8 FAT_isChannelCurrentlyPlaying (u8 channel){
    return actualSequencesForChannel[channel] != 0xff;
}




void FAT_player_stopPlayer() {


    hel_IntrStopHandler(6);


    snd_stopAllSounds();


    FAT_player_hideAllCursors();


    FAT_isCurrentlyPlaying = 0;
    FAT_player_isPlayingFrom = 0;
    FAT_live_nbChannelPlaying = 0;


    memset(actualSequencesForChannel, 0xff, sizeof (u8)*6);
    memset (FAT_live_waitForOtherChannel, 0, sizeof(u8)*6);
    memset(FAT_player_buffer, 0, sizeof(bufferPlayer)*6);

    hel_BgTextPrintF(1, 26, 16, 0, "    ");

    u8 i;
    for (i=0;i<6;i++){
        FAT_player_buffer[i].volume = 0xff;
    }
}

void FAT_resetTempo (){
    tempoReach = (60000 / FAT_tracker.tempo) * 4;
}
# 140 "src/headers/fat.h" 2

u8 __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) __attribute__ ((aligned(4))) g_BgTextSystemMemory[((sizeof(TBgTextInfo)*4) + (sizeof(u32)*2))];
u16 __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) g_CharLUT[256];

const unsigned char CHARORDER[] =
        " BCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmn" "opqrstuvwxyz0123456789,.-;:A#^+*@" "!\"~$%&/()=?|\\<>[]{}¹²³°";



u8 __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) __attribute__ ((aligned(4))) g_ObjSystemBuffer[((sizeof(TObjInfo)*128) + (sizeof(u8)*128) + (sizeof(u16)*1024) + (sizeof(u32)*4))];






u8 __attribute__ ((section(".ewram"))) __attribute__ ((nocommon)) __attribute__ ((aligned(4))) g_MapSystemBuffer[((sizeof(TMapInfo)*5) + sizeof(TMapDrawInfo) + (sizeof(u32)*2))];

void FAT_init ();
void FAT_initSpritePalette();
void FAT_initScreenPalette();





void FAT_showIntro() {

    ham_bg[3].ti = ham_InitTileSet((void*)((const void*)&__ResourceData__[6368]), 12288, 1, 1);

    hel_MapCreate(3,
                  32,
                  20,
                  ((const void*)&__ResourceData__[5088]),
                  sizeof(u16),
                  (0x0020 | 0x0040 | 0x0080 | 0x0100 | 0x0200 | 0x2000));

    ham_InitBg(3, 1, 3, 0);

    hel_BgTextPrintF(1, 23, 16, 0, "%.3dkits", snd_countAvailableKits());

    for (;;) {

        hel_PadCapture();

        if (((TPad*)(&__hel_Pad))->Pressed.Start ||
                ((TPad*)(&__hel_Pad))->Pressed.Select ||
                ((TPad*)(&__hel_Pad))->Pressed.A ||
                ((TPad*)(&__hel_Pad))->Pressed.B ||
                ((TPad*)(&__hel_Pad))->Pressed.Up ||
                ((TPad*)(&__hel_Pad))->Pressed.Down ||
                ((TPad*)(&__hel_Pad))->Pressed.Right ||
                ((TPad*)(&__hel_Pad))->Pressed.Left ||
                ((TPad*)(&__hel_Pad))->Pressed.R ||
                ((TPad*)(&__hel_Pad))->Pressed.L
                ) {
            break;
        }


        hel_SwiVBlankIntrWait();
    }
}






void FAT_reinitScreen() {
    if (ham_bg[3].ti) {
        ham_DeInitTileSet(ham_bg[3].ti);
        ham_DeInitMapSet(ham_bg[3].mi);
        FAT_forceClearTextLayer();
    }
}






void FAT_forceClearTextLayer() {
    if (ham_bg[1].ti) {

        ham_DeInitTileSet(ham_bg[1].ti);
        ham_DeInitMapSet(ham_bg[1].mi);

        ham_bg[1].ti = ham_InitTileSet((void*) ((const void*)&__ResourceData__[384960]), 3008, 1, 1);
        ham_bg[1].mi = ham_InitMapEmptySet((u8) 1024, 0);
    }

}

void FAT_allScreen_singleCheckButtons() {
    switch (FAT_currentScreen) {
        case 0:
            FAT_screenProject_checkButtons();
            break;
        case 1:
            FAT_screenLive_checkButtons();
            break;
        case 3:
            FAT_screenSong_checkButtons();
            break;
        case 4:
            FAT_screenBlocks_checkButtons();
            break;
        case 5:
            FAT_screenNotes_checkButtons();
            break;
        case 7:
            FAT_screenEffects_checkButtons();
            break;
        case 2:
            FAT_screenComposer_checkButtons();
            break;
        case 6:
            FAT_screenInstrument_checkButtons();
            break;
        case 8:
            FAT_screenFilesystem_checkButtons();
            break;
        case 9:
            FAT_screenHelp_checkButtons();

            break;
    }
}

void FAT_mainLoop() {
    for (;;) {

        if (FAT_isCurrentlyPlaying) {

            FAT_player_continueToPlay();
        }

        FAT_allScreen_singleCheckButtons();

        hel_SwiVBlankIntrWait();

    }
}






void FAT_switchToScreen(u8 screenId, u8 fromId) {
    FAT_currentScreen = screenId;
    switch (screenId) {
        case 0:
            FAT_screenProject_init();
            break;
        case 1:
            FAT_screenLive_init();
            break;
        case 3:
            FAT_screenSong_init();
            break;
        case 4:
            FAT_screenBlocks_init(fromId);
            break;
        case 5:
            FAT_screenNotes_init(fromId);
            break;
        case 7:
            FAT_screenEffects_init();
            break;
        case 2:
            FAT_screenComposer_init();
            break;
        case 6:
            FAT_screenInstrument_init();
            break;
        case 8:
            FAT_screenFilesystem_init();
            break;
    }

    FAT_popup_moveSelectedScreenCursor();
}





void FAT_showHelp(u8 screenId) {
    FAT_screenHelp_init(screenId);
}





void FAT_waitVSync() {
    while (*(volatile u16 *)(0x04000000 + 0x06) < 160) {
    }
}






void FAT_wait(u32 nbFrames) {
    u32 i = 0;

    while (i++ < nbFrames)
        FAT_waitVSync();
}
# 363 "src/headers/fat.h"
void FAT_blockCPU(u16 time) {
    u16 i = 0;
    while (i++ < time) {

    }
}
# 22 "src/sprites/cursors.c" 2
