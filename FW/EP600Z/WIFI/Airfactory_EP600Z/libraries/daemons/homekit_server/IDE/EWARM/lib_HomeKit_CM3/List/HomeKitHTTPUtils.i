



















  































 
































 
































 



 
 

  #pragma system_include

 
 

 

  #pragma system_include






 















 












 






 
 


  #pragma system_include

 
 

 

  #pragma system_include






 















 





                 



  

                 













 

   



                 



























 


  #pragma system_include

 
 
 


  #pragma system_include

 

 

 

 

   

 

   #pragma system_include






 




 

 


 


 

 

 

 

 

 

 

 

 

 














 












 




















 










 




















































































































 


 










 





















 















 













 








 












 











 










 









 











 









 









 









 









 














 














 
















 












 








 











 










 









 









 









 









 









 









 









 









 







 




 









 




 





 
















































 













 






 


   

  







 





 





 




 



 





 




 



 












 
   






 
  #pragma language = save 
  #pragma language = extended
  #pragma language = restore






 





 




 





 








                 




















 


                 

 

 
 

 

 

 

 



                 






 
 


  #pragma system_include

 
 

 

  #pragma system_include






 















 




 
 





 

                                 













                 

                 

                 

                 
                 



                 
                                 


  #pragma language=save
  #pragma language=extended
  typedef long long _Longlong;
  typedef unsigned long long _ULonglong;
  #pragma language=restore

  typedef unsigned short int _Wchart;
  typedef unsigned short int _Wintt;



                 

typedef signed int  _Ptrdifft;
typedef unsigned int     _Sizet;

 

                 
  typedef _VA_LIST __Va_list;


__intrinsic __nounwind void __iar_Atexit(void (*)(void));


  typedef struct
  {        
    unsigned int _Wchar;
    unsigned int _State;
  } _Mbstatet;



  typedef struct __FILE _Filet;


typedef struct
{        
  _Longlong _Off;     
  _Mbstatet _Wstate;
} _Fpost;




                 














 


  #pragma system_include





 






















































































 

 


  
 

   


  





  #pragma language=save 
  #pragma language=extended
  __intrinsic __nounwind void __iar_dlib_perthread_initialize(void  *);
  __intrinsic __nounwind void  *__iar_dlib_perthread_allocate(void);
  __intrinsic __nounwind void __iar_dlib_perthread_destroy(void);
  __intrinsic __nounwind void __iar_dlib_perthread_deallocate(void  *);



  #pragma segment = "__DLIB_PERTHREAD" 
  #pragma segment = "__DLIB_PERTHREAD_init" 









   
  void  *__iar_dlib_perthread_access(void  *);
  #pragma language=restore








     
  



   
    __intrinsic __nounwind void __iar_Locale_lconv_init(void);

  


  
  typedef void *__iar_Rmtx;
  
  
  __intrinsic __nounwind void __iar_system_Mtxinit(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_system_Mtxdst(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_system_Mtxlock(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_system_Mtxunlock(__iar_Rmtx *m);

  __intrinsic __nounwind void __iar_file_Mtxinit(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_file_Mtxdst(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_file_Mtxlock(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_file_Mtxunlock(__iar_Rmtx *m);

  
 
  __intrinsic __nounwind void __iar_clearlocks(void);



  



  


  typedef unsigned _Once_t;

  








                 


                 
  
  
    
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Locale(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Malloc(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Stream(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Debug(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_StaticGuard(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock(unsigned int);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Locale(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Malloc(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Stream(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Debug(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_StaticGuard(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock(unsigned int);

  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Initdynamicfilelock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Dstdynamicfilelock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Lockdynamicfilelock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlockdynamicfilelock(__iar_Rmtx *);
  
  

                 


                 







 


 
  typedef signed char   int8_t;
  typedef unsigned char uint8_t;

  typedef signed short int   int16_t;
  typedef unsigned short int uint16_t;

  typedef signed int   int32_t;
  typedef unsigned int uint32_t;

  #pragma language=save
  #pragma language=extended
  typedef signed long long int   int64_t;
  typedef unsigned long long int uint64_t;
  #pragma language=restore


 
typedef signed char   int_least8_t;
typedef unsigned char uint_least8_t;

typedef signed short int   int_least16_t;
typedef unsigned short int uint_least16_t;

typedef signed int   int_least32_t;
typedef unsigned int uint_least32_t;

 
  #pragma language=save
  #pragma language=extended
  typedef signed long long int int_least64_t;
  #pragma language=restore
  #pragma language=save
  #pragma language=extended
  typedef unsigned long long int uint_least64_t;
  #pragma language=restore



 
typedef signed int   int_fast8_t;
typedef unsigned int uint_fast8_t;

typedef signed int   int_fast16_t;
typedef unsigned int uint_fast16_t;

typedef signed int   int_fast32_t;
typedef unsigned int uint_fast32_t;

  #pragma language=save
  #pragma language=extended
  typedef signed long long int int_fast64_t;
  #pragma language=restore
  #pragma language=save
  #pragma language=extended
  typedef unsigned long long int uint_fast64_t;
  #pragma language=restore

 
#pragma language=save
#pragma language=extended
typedef signed long long int   intmax_t;
typedef unsigned long long int uintmax_t;
#pragma language=restore


 
typedef signed long int   intptr_t;
typedef unsigned long int uintptr_t;

 
typedef int __data_intptr_t; typedef unsigned int __data_uintptr_t;

 

























 














 
 
 

 


  #pragma system_include










 
 
 


  #pragma system_include

 
 

 

  #pragma system_include






 















 




 
 


  #pragma system_include

 
 

 

  #pragma system_include






 















 






                 
typedef _Sizet size_t;

typedef unsigned int __data_size_t;





 
#pragma rtmodel="__dlib_full_locale_support",   "1"




extern int __aeabi_MB_CUR_MAX(void);





                 



                 
  typedef _Wchart wchar_t;

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

    #pragma language=save
    #pragma language=extended
    typedef struct
    {      
      _Longlong quot;
      _Longlong rem;
    } lldiv_t;
    #pragma language=restore

                 
  
__intrinsic __nounwind int atexit(void (*)(void));
  __intrinsic __noreturn __nounwind void _Exit(int) ;
__intrinsic __noreturn __nounwind void exit(int) ;
__intrinsic __nounwind char * getenv(const char *);
__intrinsic __nounwind int system(const char *);



             __intrinsic __noreturn __nounwind void abort(void) ;
_Pragma("function_effects = no_state, no_errno")     __intrinsic __nounwind int abs(int);
             __intrinsic __nounwind void * calloc(size_t, size_t);
_Pragma("function_effects = no_state, no_errno")     __intrinsic __nounwind div_t div(int, int);
             __intrinsic __nounwind void free(void *);
_Pragma("function_effects = no_state, no_errno")     __intrinsic __nounwind long labs(long);
_Pragma("function_effects = no_state, no_errno")     __intrinsic __nounwind ldiv_t ldiv(long, long);
    #pragma language=save
    #pragma language=extended
    _Pragma("function_effects = no_state, no_errno") __intrinsic __nounwind long long llabs(long long);
    _Pragma("function_effects = no_state, no_errno") __intrinsic __nounwind lldiv_t lldiv(long long, long long);
    #pragma language=restore
             __intrinsic __nounwind void * malloc(size_t);
_Pragma("function_effects = no_write(1)")    __intrinsic __nounwind int mblen(const char *, size_t);
_Pragma("function_effects = no_read(1), no_write(2)") __intrinsic __nounwind size_t mbstowcs(wchar_t *, 
                                          const char *, size_t);
_Pragma("function_effects = no_read(1), no_write(2)") __intrinsic __nounwind int mbtowc(wchar_t *, const char *, 
                                     size_t);
             __intrinsic __nounwind int rand(void);
             __intrinsic __nounwind void srand(unsigned int);
             __intrinsic __nounwind void * realloc(void *, size_t);
_Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind long strtol(const char *, 
                                      char **, int);
_Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind unsigned long strtoul(const char *, char **, int);
_Pragma("function_effects = no_read(1), no_write(2)") __intrinsic __nounwind size_t wcstombs(char *, 
                                          const wchar_t *, size_t);
_Pragma("function_effects = no_read(1)")    __intrinsic __nounwind int wctomb(char *, wchar_t);
    #pragma language=save
    #pragma language=extended
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind long long strtoll(const char *, char **, int);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind unsigned long long strtoull(const char *, 
                                                          char **, int);
    #pragma language=restore




    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind unsigned long __iar_Stoul(const char *, char **, 
                                                        int);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind float         __iar_Stof(const char *, char **, long);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind double        __iar_Stod(const char *, char **, long);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind long double   __iar_Stold(const char *, char **, 
                                                          long);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind long          __iar_Stolx(const char *, char **, int, 
                                                        int *);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind unsigned long __iar_Stoulx(const char *, char **,
                                                         int, int *);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind float         __iar_Stofx(const char *, char **, 
                                                        long, int *);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind double        __iar_Stodx(const char *, char **, 
                                                        long, int *);
    _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind long double   __iar_Stoldx(const char *, char **, 
                                                         long, int *);
      #pragma language=save
      #pragma language=extended
      _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind _Longlong   __iar_Stoll(const char *, char **, 
                                                        int);
      _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind _ULonglong   __iar_Stoull(const char *, char **, 
                                                          int);
      _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind _Longlong    __iar_Stollx(const char *, char **, 
                                                          int, int *);
      _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind _ULonglong   __iar_Stoullx(const char *, char **, 
                                                           int, int *);
      #pragma language=restore





typedef int _Cmpfun(const void *, const void *);

_Pragma("function_effects = no_write(1,2)") __intrinsic void * bsearch(const void *, 
                                                   const void *, size_t,
                                                   size_t, _Cmpfun *);
             __intrinsic void qsort(void *, size_t, size_t, 
                                               _Cmpfun *);
             __intrinsic void __qsortbbl(void *, size_t, size_t, 
                                                    _Cmpfun *);
_Pragma("function_effects = no_write(1)")    __intrinsic __nounwind double atof(const char *);
_Pragma("function_effects = no_write(1)")    __intrinsic __nounwind int atoi(const char *);
_Pragma("function_effects = no_write(1)")    __intrinsic __nounwind long atol(const char *);
    #pragma language=save
    #pragma language=extended
    _Pragma("function_effects = no_write(1)") __intrinsic __nounwind long long atoll(const char *);
    #pragma language=restore
  _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind float strtof(const char *, 
                                         char **);
  _Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind long double strtold(const char *, char **);
_Pragma("function_effects = no_write(1), no_read(2)") __intrinsic __nounwind double strtod(const char *, 
                                        char **);
                                        
                                        
               __intrinsic __nounwind size_t __iar_Mbcurmax(void);

  _Pragma("function_effects = no_state, no_errno")     __intrinsic __nounwind int __iar_DLib_library_version(void);
  




  
  typedef void _Atexfun(void);
  

                 
    #pragma inline=no_body
    double atof(const char *_S)
    {       
      return (__iar_Stod(_S, 0, 0));
    }

    #pragma inline=no_body
    int atoi(const char *_S)
    {       
      return ((int)__iar_Stoul(_S, 0, 10));
    }

    #pragma inline=no_body
    long atol(const char *_S)
    {       
      return ((long)__iar_Stoul(_S, 0, 10));
    }

        #pragma language=save
        #pragma language=extended
        #pragma inline=no_body
        long long atoll(const char *_S)
        {       
            return ((long long)__iar_Stoull(_S, 0, 10));
        }
        #pragma language=restore

    #pragma inline=no_body
    double strtod(const char * _S, char ** _Endptr)
    {       
      return (__iar_Stod(_S, _Endptr, 0));
    }

      #pragma inline=no_body
      float strtof(const char * _S, char ** _Endptr)
      {       
        return (__iar_Stof(_S, _Endptr, 0));
      }

      #pragma inline=no_body
      long double strtold(const char * _S, char ** _Endptr)
      {       
        return (__iar_Stold(_S, _Endptr, 0));
      }

    #pragma inline=no_body
    long strtol(const char * _S, char ** _Endptr, 
                int _Base)
    {       
      return (__iar_Stolx(_S, _Endptr, _Base, 0));
    }

    #pragma inline=no_body
    unsigned long strtoul(const char * _S, char ** _Endptr, 
                          int _Base)
    {       
      return (__iar_Stoul(_S, _Endptr, _Base));
    }

        #pragma language=save
        #pragma language=extended
        #pragma inline=no_body
        long long strtoll(const char * _S, char ** _Endptr,
                          int _Base)
        {       
            return (__iar_Stoll(_S, _Endptr, _Base));
        }

        #pragma inline=no_body
        unsigned long long strtoull(const char * _S, 
                                    char ** _Endptr, int _Base)
        {       
            return (__iar_Stoull(_S, _Endptr, _Base));
        }
        #pragma language=restore


  #pragma inline=no_body
  int abs(int i)
  {       
    return (i < 0 ? -i : i);
  }

  #pragma inline=no_body
  long labs(long i)
  {       
    return (i < 0 ? -i : i);
  }

      #pragma language=save
      #pragma language=extended
      #pragma inline=no_body
      long long llabs(long long i)
      {       
        return (i < 0 ? -i : i);
      }
      #pragma language=restore








 
 
 

  #pragma system_include

 
 

 

  #pragma system_include






 















 




 
 



 
 

  #pragma system_include






    struct __FILE
    {        
      unsigned short _Mode;
      unsigned char _Lockno;
      signed char _Handle;

       
       
       
      unsigned char *_Buf, *_Bend, *_Next;
       
       
      
  
      unsigned char *_Rend, *_Wend, *_Rback;

      
  
      _Wchart *_WRback, _WBack[2];

       
       
       
      unsigned char *_Rsave, *_WRend, *_WWend;

      _Mbstatet _Wstate;
      char *_Tmpnam;
      unsigned char _Back[1], _Cbuf;
    };

    
  

 

__intrinsic __nounwind int remove(const char *);
__intrinsic __nounwind int rename(const char *, const char *);









 



 
#pragma rtmodel="__dlib_file_descriptor","1"

                 

  typedef _Filet FILE;


      
      extern  FILE __iar_Stdin;
      extern  FILE __iar_Stdout;
      extern  FILE __iar_Stderr;
      






                 
typedef _Fpost fpos_t;

                 
#pragma language=save
#pragma language=extended


                 
  

  __intrinsic __nounwind void clearerr(FILE *);
  __intrinsic __nounwind int fclose(FILE *);
  __intrinsic __nounwind int feof(FILE *);
  __intrinsic __nounwind int ferror(FILE *);
  __intrinsic __nounwind int fflush(FILE *);
  __intrinsic __nounwind int fgetc(FILE *);
  __intrinsic __nounwind int fgetpos(FILE *, fpos_t *);
  __intrinsic __nounwind char * fgets(char *, int, FILE *);
  __intrinsic __nounwind FILE * fopen(const char *, const char *);
  _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int fprintf(FILE *, const char *, 
                                      ...);
  __intrinsic __nounwind int fputc(int, FILE *);
  __intrinsic __nounwind int fputs(const char *, FILE *);
  __intrinsic __nounwind size_t fread(void *, size_t, size_t, FILE *);
  __intrinsic __nounwind FILE * freopen(const char *, const char *,
                              FILE *);
  _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown") __intrinsic __nounwind int fscanf(FILE *, const char *, 
                                    ...);
  __intrinsic __nounwind int fseek(FILE *, long, int);
  __intrinsic __nounwind int fsetpos(FILE *, const fpos_t *);
  __intrinsic __nounwind long ftell(FILE *);
  __intrinsic __nounwind size_t fwrite(const void *, size_t, size_t, 
                             FILE *);

  __intrinsic __nounwind void rewind(FILE *);
  __intrinsic __nounwind void setbuf(FILE *, char *);
  __intrinsic __nounwind int setvbuf(FILE *, char *, int, size_t);
  __intrinsic __nounwind FILE * tmpfile(void);
  __intrinsic __nounwind int ungetc(int, FILE *);
  _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int vfprintf(FILE *, 
                                       const char *, __Va_list);
    _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown")  __intrinsic __nounwind int vfscanf(FILE *, const char *,
                                        __Va_list);

    __intrinsic __nounwind FILE * fdopen(signed char, const char *);
    __intrinsic __nounwind signed char fileno(FILE *);
    __intrinsic __nounwind int getw(FILE *);
    __intrinsic __nounwind int putw(int, FILE *);

  __intrinsic __nounwind int getc(FILE *);
  __intrinsic __nounwind int putc(int, FILE *);
  


              
_Pragma("function_effects = no_read(1)")    __intrinsic __nounwind char * __gets(char *, int);
_Pragma("function_effects = no_read(1)")    __intrinsic __nounwind char * gets(char *);
_Pragma("function_effects = no_write(1)")    __intrinsic __nounwind void perror(const char *);
_Pragma("function_effects = no_write(1)")    _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int printf(const char *, ...);
_Pragma("function_effects = no_write(1)")    __intrinsic __nounwind int puts(const char *);
_Pragma("function_effects = no_write(1)")    _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown")  __intrinsic __nounwind int scanf(const char *, ...);
_Pragma("function_effects = no_read(1), no_write(2)") _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int sprintf(char *, 
                                                 const char *, ...);
_Pragma("function_effects = no_write(1,2)") _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown")  __intrinsic __nounwind int sscanf(const char *, 
                                                const char *, ...);
             __intrinsic __nounwind char * tmpnam(char *);
              
             __intrinsic __nounwind int __ungetchar(int);
_Pragma("function_effects = no_write(1)")    _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int vprintf(const char *,
                                                 __Va_list);
  _Pragma("function_effects = no_write(1)")    _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown")  __intrinsic __nounwind int vscanf(const char *, 
                                                  __Va_list);
  _Pragma("function_effects = no_write(1,2)") _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown")  __intrinsic __nounwind int vsscanf(const char *, 
                                                   const char *, 
                                                   __Va_list);
_Pragma("function_effects = no_read(1), no_write(2)")  _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int vsprintf(char *, 
                                                   const char *,
                                                   __Va_list);
               
_Pragma("function_effects = no_write(1)")      __intrinsic __nounwind size_t __write_array(const void *, size_t, size_t);
  _Pragma("function_effects = no_read(1), no_write(3)") _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int snprintf(char *, size_t, 
                                                    const char *, ...);
  _Pragma("function_effects = no_read(1), no_write(3)") _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int vsnprintf(char *, size_t,
                                                     const char *, 
                                                     __Va_list);

              __intrinsic __nounwind int getchar(void);
              __intrinsic __nounwind int putchar(int);



#pragma language=restore

             
  #pragma inline
  int (getc)(FILE *_Str)
  {
    return fgetc(_Str);
  }

  #pragma inline
  int (putc)(int _C, FILE *_Str)
  {
    return fputc(_C, _Str);
  }







 
 
 

  #pragma system_include

 
 

 

  #pragma system_include






 















 




 
 












 


  #pragma system_include


  
  

  





 


  




 




  


 

  #pragma inline=forced_no_body
  __intrinsic __nounwind void * memcpy(void * _D, const void * _S, size_t _N)
  {
    __aeabi_memcpy(_D, _S, _N);
    return _D;
  }

  #pragma inline=forced_no_body
  __intrinsic __nounwind void * memmove(void * _D, const void * _S, size_t _N)
  {
    __aeabi_memmove(_D, _S, _N);
    return _D;
  }

  #pragma inline=forced_no_body
  __intrinsic __nounwind void * memset(void * _D, int _C, size_t _N)
  {
    __aeabi_memset(_D, _N, _C);
    return _D;
  }

  
  




                 

                 

_Pragma("function_effects = no_state, no_errno, no_write(1,2)")   __intrinsic __nounwind int        memcmp(const void *, const void *,
                                                size_t);
_Pragma("function_effects = no_state, no_errno, no_read(1), no_write(2), returns 1") __intrinsic __nounwind void *     memcpy(void *, 
                                                const void *, size_t);
_Pragma("function_effects = no_state, no_errno, no_read(1), no_write(2), returns 1") __intrinsic __nounwind void *     memmove(void *, const void *, size_t);
_Pragma("function_effects = no_state, no_errno, no_read(1), returns 1")    __intrinsic __nounwind void *     memset(void *, int, size_t);
_Pragma("function_effects = no_state, no_errno, no_write(2), returns 1")    __intrinsic __nounwind char *     strcat(char *, 
                                                const char *);
_Pragma("function_effects = no_state, no_errno, no_write(1,2)")   __intrinsic __nounwind int        strcmp(const char *, const char *);
_Pragma("function_effects = no_write(1,2)")     __intrinsic __nounwind int        strcoll(const char *, const char *);
_Pragma("function_effects = no_state, no_errno, no_read(1), no_write(2), returns 1") __intrinsic __nounwind char *     strcpy(char *, 
                                                const char *);
_Pragma("function_effects = no_state, no_errno, no_write(1,2)")   __intrinsic __nounwind size_t     strcspn(const char *, const char *);
                 __intrinsic __nounwind char *     strerror(int);
_Pragma("function_effects = no_state, no_errno, no_write(1)")      __intrinsic __nounwind size_t     strlen(const char *);
_Pragma("function_effects = no_state, no_errno, no_write(2), returns 1")    __intrinsic __nounwind char *     strncat(char *, 
                                                 const char *, size_t);
_Pragma("function_effects = no_state, no_errno, no_write(1,2)")   __intrinsic __nounwind int        strncmp(const char *, const char *, 
                                                 size_t);
_Pragma("function_effects = no_state, no_errno, no_read(1), no_write(2), returns 1") __intrinsic __nounwind char *     strncpy(char *, 
                                                 const char *, size_t);
_Pragma("function_effects = no_state, no_errno, no_write(1,2)")   __intrinsic __nounwind size_t     strspn(const char *, const char *);
_Pragma("function_effects = no_write(2)")        __intrinsic __nounwind char *     strtok(char *, 
                                                const char *);
_Pragma("function_effects = no_write(2)")        __intrinsic __nounwind size_t     strxfrm(char *, 
                                                 const char *, size_t);

  _Pragma("function_effects = no_write(1)")      __intrinsic __nounwind char *   strdup(const char *);
  _Pragma("function_effects = no_write(1,2)")   __intrinsic __nounwind int      strcasecmp(const char *, const char *);
  _Pragma("function_effects = no_write(1,2)")   __intrinsic __nounwind int      strncasecmp(const char *, const char *, 
                                                   size_t);
  _Pragma("function_effects = no_state, no_errno, no_write(2)")    __intrinsic __nounwind char *   strtok_r(char *, const char *, char **);
  _Pragma("function_effects = no_state, no_errno, no_write(1)")    __intrinsic __nounwind size_t   strnlen(char const *, size_t);



  _Pragma("function_effects = no_state, no_errno, no_write(1)")    __intrinsic __nounwind void *memchr(const void *_S, int _C, size_t _N);
  _Pragma("function_effects = no_state, no_errno, no_write(1)")    __intrinsic __nounwind char *strchr(const char *_S, int _C);
  _Pragma("function_effects = no_state, no_errno, no_write(1,2)") __intrinsic __nounwind char *strpbrk(const char *_S, const char *_P);
  _Pragma("function_effects = no_state, no_errno, no_write(1)")    __intrinsic __nounwind char *strrchr(const char *_S, int _C);
  _Pragma("function_effects = no_state, no_errno, no_write(1,2)") __intrinsic __nounwind char *strstr(const char *_S, const char *_P);


                 

                 

_Pragma("function_effects = no_state, no_errno, no_write(1)")    __intrinsic __nounwind void *__iar_Memchr(const void *, int, size_t);
_Pragma("function_effects = no_state, no_errno, no_write(1)")    __intrinsic __nounwind char *__iar_Strchr(const char *, int);
               __intrinsic __nounwind char *__iar_Strerror(int, char *);
_Pragma("function_effects = no_state, no_errno, no_write(1,2)") __intrinsic __nounwind char *__iar_Strpbrk(const char *, const char *);
_Pragma("function_effects = no_state, no_errno, no_write(1)")    __intrinsic __nounwind char *__iar_Strrchr(const char *, int);
_Pragma("function_effects = no_state, no_errno, no_write(1,2)") __intrinsic __nounwind char *__iar_Strstr(const char *, const char *);


                 
                 
    #pragma inline
    void *memchr(const void *_S, int _C, size_t _N)
    {
      return (__iar_Memchr(_S, _C, _N));
    }

    #pragma inline
    char *strchr(const char *_S, int _C)
    {
      return (__iar_Strchr(_S, _C));
    }

    #pragma inline
    char *strpbrk(const char *_S, const char *_P)
    {
      return (__iar_Strpbrk(_S, _P));
    }

    #pragma inline
    char *strrchr(const char *_S, int _C)
    {
      return (__iar_Strrchr(_S, _C));
    }

    #pragma inline
    char *strstr(const char *_S, const char *_P)
    {
      return (__iar_Strstr(_S, _P));
    }

  #pragma inline
  char *strerror(int _Err)
  {
    return (__iar_Strerror(_Err, 0));
  }









 
 
 

  #pragma system_include

 
 

 

  #pragma system_include






 















 






 
 


  #pragma system_include

 
 

 

  #pragma system_include






 















 





 
 

  #pragma system_include

 
 

  #pragma system_include

 
 

 

  #pragma system_include






 















 





 
 






 







 

 
#pragma diag_suppress = Pe076


__intrinsic __nounwind int __iar_Atthreadexit(void (*)(void));
__intrinsic __nounwind void __iar_Destroytls(void);














 


 
 

  #pragma system_include

 
 

 

  #pragma system_include






 















 




 
 






 

 
#pragma rtmodel="__dlib_file_descriptor","1"

 


                 



                 
typedef _Mbstatet mbstate_t;
struct tm;


  typedef _Wintt wint_t;


                 
  __intrinsic __nounwind wint_t fgetwc(_Filet *);
  __intrinsic __nounwind wchar_t * fgetws(wchar_t *, int, _Filet *);
  __intrinsic __nounwind wint_t fputwc(wchar_t, _Filet *);
  __intrinsic __nounwind int fputws(const wchar_t *, _Filet *);
  __intrinsic __nounwind int fwide(_Filet *, int);
  __intrinsic __nounwind int fwprintf(_Filet *, const wchar_t *, ...);
  __intrinsic __nounwind int fwscanf(_Filet *, const wchar_t *, ...);
  __intrinsic __nounwind wint_t getwc(_Filet *);
  __intrinsic __nounwind wint_t putwc(wchar_t, _Filet *);
  __intrinsic __nounwind wint_t ungetwc(wint_t, _Filet *);
  __intrinsic __nounwind int vfwprintf(_Filet *, const wchar_t *,
                             __Va_list);
    __intrinsic __nounwind int vfwscanf(_Filet *, const wchar_t *,
                              __Va_list);


__intrinsic __nounwind wint_t getwchar(void);
__intrinsic __nounwind wint_t __ungetwchar(wint_t);
__intrinsic __nounwind wint_t putwchar(wchar_t);
__intrinsic __nounwind int swprintf(wchar_t *, size_t, 
                          const wchar_t *, ...);
__intrinsic __nounwind int swscanf(const wchar_t *,
                         const wchar_t *, ...);
__intrinsic __nounwind int vswprintf(wchar_t *, size_t,
                           const wchar_t *, __Va_list);
__intrinsic __nounwind int vwprintf(const wchar_t *, __Va_list);
  __intrinsic __nounwind int vswscanf(const wchar_t *, const wchar_t *,
                            __Va_list);
  __intrinsic __nounwind int vwscanf(const wchar_t *, __Va_list);
__intrinsic __nounwind int wprintf(const wchar_t *, ...);
__intrinsic __nounwind int wscanf(const wchar_t *, ...);

                 
__intrinsic __nounwind size_t mbrlen(const char *, size_t,
                           mbstate_t *);
__intrinsic __nounwind size_t mbrtowc(wchar_t *, const char *, size_t,
                            mbstate_t *);
__intrinsic __nounwind size_t mbsrtowcs(wchar_t *, const char **,
                              size_t, mbstate_t *);
__intrinsic __nounwind int mbsinit(const mbstate_t *);
__intrinsic __nounwind size_t wcrtomb(char *, wchar_t, mbstate_t *);
__intrinsic __nounwind size_t wcsrtombs(char *, const wchar_t **,
                              size_t, mbstate_t *);
__intrinsic __nounwind long wcstol(const wchar_t *, wchar_t **, int);
__intrinsic __nounwind unsigned long wcstoul(const wchar_t *,
                                   wchar_t **, int);

    #pragma language=save
    #pragma language=extended
    __intrinsic __nounwind _Longlong wcstoll(const wchar_t *, 
                                   wchar_t **, int);
    __intrinsic __nounwind _ULonglong wcstoull(const wchar_t *, 
                                     wchar_t **, int);
    #pragma language=restore

                 
__intrinsic __nounwind wchar_t * wcscat(wchar_t *, const wchar_t *);
__intrinsic __nounwind int wcscmp(const wchar_t *, const wchar_t *);
__intrinsic __nounwind int wcscoll(const wchar_t *, const wchar_t *);
__intrinsic __nounwind wchar_t * wcscpy(wchar_t *, const wchar_t *);
__intrinsic __nounwind size_t wcscspn(const wchar_t *, const wchar_t *);
__intrinsic __nounwind size_t wcslen(const wchar_t *);
__intrinsic __nounwind wchar_t * wcsncat(wchar_t *, const wchar_t *, 
                               size_t);
__intrinsic __nounwind int wcsncmp(const wchar_t *, const wchar_t *, size_t);
__intrinsic __nounwind wchar_t * wcsncpy(wchar_t *, const wchar_t *,
                               size_t);
__intrinsic __nounwind size_t wcsspn(const wchar_t *, const wchar_t *);
__intrinsic __nounwind wchar_t * wcstok(wchar_t *, const wchar_t *,
                              wchar_t **);
__intrinsic __nounwind size_t wcsxfrm(wchar_t *, const wchar_t *, 
                            size_t);
__intrinsic __nounwind int wmemcmp(const wchar_t *, const wchar_t *, size_t);
__intrinsic __nounwind wchar_t * wmemcpy(wchar_t *, const wchar_t *, 
                               size_t);
__intrinsic __nounwind wchar_t * wmemmove(wchar_t *, const wchar_t *, size_t);
__intrinsic __nounwind wchar_t * wmemset(wchar_t *, wchar_t, size_t);

                 
__intrinsic __nounwind size_t wcsftime(wchar_t *, size_t,
                             const wchar_t *, 
                             const struct tm *);


__intrinsic __nounwind wint_t btowc(int);
  __intrinsic __nounwind float wcstof(const wchar_t *, wchar_t **);
  __intrinsic __nounwind long double wcstold(const wchar_t *,
                                   wchar_t **);
__intrinsic __nounwind double wcstod(const wchar_t *, wchar_t **);
__intrinsic __nounwind int wctob(wint_t);


  __intrinsic __nounwind wint_t __iar_Btowc(int);
  __intrinsic __nounwind int __iar_Wctob(wint_t);
  __intrinsic __nounwind double __iar_WStod(const wchar_t *, wchar_t **, long);
  __intrinsic __nounwind float __iar_WStof(const wchar_t *, wchar_t **, long);
  __intrinsic __nounwind long double __iar_WStold(const wchar_t *, wchar_t **, long);
  __intrinsic __nounwind unsigned long __iar_WStoul(const wchar_t *, wchar_t **, int);
  __intrinsic __nounwind _Longlong __iar_WStoll(const wchar_t *, wchar_t **, int);
  __intrinsic __nounwind _ULonglong __iar_WStoull(const wchar_t *, wchar_t **, int);

  __intrinsic __nounwind wchar_t * __iar_Wmemchr(const wchar_t *, wchar_t, size_t);
  __intrinsic __nounwind wchar_t * __iar_Wcschr(const wchar_t *, wchar_t);
  __intrinsic __nounwind wchar_t * __iar_Wcspbrk(const wchar_t *, const wchar_t *);
  __intrinsic __nounwind wchar_t * __iar_Wcsrchr(const wchar_t *, wchar_t);
  __intrinsic __nounwind wchar_t * __iar_Wcsstr(const wchar_t *, const wchar_t *);
  
  


 

  __intrinsic __nounwind wchar_t * wmemchr(const wchar_t *, wchar_t, size_t);
  __intrinsic __nounwind wchar_t * wcschr(const wchar_t *, wchar_t);
  __intrinsic __nounwind wchar_t * wcspbrk(const wchar_t *, const wchar_t *);
  __intrinsic __nounwind wchar_t * wcsrchr(const wchar_t *, wchar_t);
  __intrinsic __nounwind wchar_t * wcsstr(const wchar_t *, const wchar_t *);

    #pragma inline
    wchar_t * wmemchr(const wchar_t *_S, wchar_t _C, size_t _N)
    {
      return (__iar_Wmemchr(_S, _C, _N));
    }

    #pragma inline
    wchar_t * wcschr(const wchar_t *_S, wchar_t _C)
    {
      return (__iar_Wcschr(_S, _C));
    }

    #pragma inline
    wchar_t * wcspbrk(const wchar_t *_S, const wchar_t *_P)
    {
      return (__iar_Wcspbrk(_S, _P));
    }

    #pragma inline
    wchar_t * wcsrchr(const wchar_t *_S, wchar_t _C)
    {
      return (__iar_Wcsrchr(_S, _C));
    }

    #pragma inline
    wchar_t * wcsstr(const wchar_t *_S, const wchar_t *_P)
    {
      return (__iar_Wcsstr(_S, _P));
    }

  #pragma inline
  wint_t btowc(int _C)
  {        
    return (__iar_Btowc(_C));
  }

    #pragma inline
    float wcstof(const wchar_t *_S,
                 wchar_t **_Endptr)
    {        
      return (__iar_WStof(_S, _Endptr, 0));
    }

    #pragma inline
    long double wcstold(const wchar_t *_S,
                        wchar_t **_Endptr)
    {        
      return (__iar_WStold(_S, _Endptr, 0));
    }

      #pragma language=save
      #pragma language=extended
      #pragma inline
       _Longlong wcstoll(const wchar_t * _S, 
                         wchar_t ** _Endptr, int _Base)
       {
	return (__iar_WStoll(_S, _Endptr, _Base));
       }

      #pragma inline
      _ULonglong wcstoull(const wchar_t * _S, 
                          wchar_t ** _Endptr, int _Base)
      {
	return (__iar_WStoull(_S, _Endptr, _Base));
      }
      #pragma language=restore


  #pragma inline
  double wcstod(const wchar_t *_S,
                wchar_t **_Endptr)
  {        
    return (__iar_WStod(_S, _Endptr, 0));
  }


  #pragma inline
  unsigned long wcstoul(const wchar_t *_S,
                        wchar_t **_Endptr, int _Base)
  {        
    return (__iar_WStoul(_S, _Endptr, _Base));
  }

  #pragma inline
  int wctob(wint_t _Wc)
  {        
    return (__iar_Wctob(_Wc));
  }








 
 
 

  #pragma system_include

 
 

 

  #pragma system_include






 















 








 
#pragma rtmodel="__dlib_full_locale_support",   "1"

                 


                 
                 

                 





                 




                 

                 


 
 

  #pragma system_include

struct lconv
{        
   
  char *currency_symbol;
  char *int_curr_symbol;
  char *mon_decimal_point;
  char *mon_grouping;
  char *mon_thousands_sep;
  char *negative_sign;
  char *positive_sign;

  char frac_digits;
  char n_cs_precedes;
  char n_sep_by_space;
  char n_sign_posn;
  char p_cs_precedes;
  char p_sep_by_space;
  char p_sign_posn;

  char int_frac_digits;

   
  char *decimal_point;
  char *grouping;
  char *thousands_sep;
  char *_Frac_grouping;
  char *_Frac_sep;
  char *_False;
  char *_True;

   
  char *_No;
  char *_Yes;

   
  char int_n_cs_precedes;
  char int_n_sep_by_space;
  char int_n_sign_posn;
  char int_p_cs_precedes;
  char int_p_sep_by_space;
  char int_p_sign_posn;
};



                 

__intrinsic __nounwind struct __aeabi_lconv *__aeabi_localeconv(void);
__intrinsic __nounwind struct lconv *localeconv(void);
  __intrinsic __nounwind char *setlocale(int, const char *);








 
  



 


  

  



 

   






 


  #pragma system_include
































































































































































  

 


  enum
  {
    _LocaleC_id,
    _LocaleCount  
  };



  
  extern int _LocaleC_toupper(int);
  extern int _LocaleC_tolower(int);
  extern int _LocaleC_isalpha(int);
  extern int _LocaleC_iscntrl(int);
  extern int _LocaleC_islower(int);
  extern int _LocaleC_ispunct(int);
  extern int _LocaleC_isspace(int);
  extern int _LocaleC_isupper(int);
  extern wint_t _LocaleC_towupper(wint_t);
  extern wint_t _LocaleC_towlower(wint_t);
  extern int _LocaleC_iswalpha(wint_t);
  extern int _LocaleC_iswcntrl(wint_t);
  extern int _LocaleC_iswlower(wint_t);
  extern int _LocaleC_iswpunct(wint_t);
  extern int _LocaleC_iswspace(wint_t);
  extern int _LocaleC_iswupper(wint_t);
  extern int _LocaleC_iswdigit(wint_t);
  extern int _LocaleC_iswxdigit(wint_t);
  

  





 
#pragma rtmodel="__dlib_full_locale_support",   "1"




         __intrinsic __nounwind int isalnum(int);
         __intrinsic __nounwind int isalpha(int);
         __intrinsic __nounwind int isblank(int);
         __intrinsic __nounwind int iscntrl(int);
_Pragma("function_effects = no_state, no_errno") __intrinsic __nounwind int isdigit(int);
         __intrinsic __nounwind int isgraph(int);
         __intrinsic __nounwind int islower(int);
         __intrinsic __nounwind int isprint(int);
         __intrinsic __nounwind int ispunct(int);
         __intrinsic __nounwind int isspace(int);
         __intrinsic __nounwind int isupper(int);
_Pragma("function_effects = no_state, no_errno") __intrinsic __nounwind int isxdigit(int);
         __intrinsic __nounwind int tolower(int);
         __intrinsic __nounwind int toupper(int);


 

      #pragma inline=no_body
      int isblank(int _C)
      {
        return (   _C == ' '
                || _C == '\t'
                || isspace(_C));
      }

    #pragma inline=no_body
    int isdigit(int _C)
    {
      return _C >= '0' && _C <= '9';
    }

    #pragma inline=no_body
    int isxdigit(int _C)
    {
      return (   (_C >= 'a' && _C <= 'f')
              || (_C >= 'A' && _C <= 'F')
              || isdigit(_C));
    }

    #pragma inline=no_body
    int isalnum(int _C)
    {
      return (   isalpha(_C)
              || isdigit(_C));
    }

    #pragma inline=no_body
    int isprint(int _C)
    {
      return (   (_C >= ' ' && _C <= '\x7e')
              || isalpha(_C)
              || ispunct(_C));
    }

    #pragma inline=no_body
    int isgraph(int _C)
    {
      return (   _C != ' '
              && isprint(_C));
    }





      
 



  
  






 









 


 
 

  #pragma system_include

 
 

 

  #pragma system_include






 















 




 
 






                 


                 
  typedef _Ptrdifft ptrdiff_t;








 




 


  




 



 



 



 



 



 

void *memrchr( const void *s, int c, size_t n );
void iar_set_msp(void*);
















 




typedef uint8_t         Boolean;
typedef uint8_t         mico_bool_t;







typedef uint32_t  mico_time_t;         
typedef uint32_t  mico_utc_time_t;     
typedef uint64_t  mico_utc_time_ms_t;  


typedef int         OSStatus;




















 












 




 
























































 




 















 

 

 









 
static inline  char nibble_to_hexchar( uint8_t nibble )
{
    if (nibble > 9)
    {
        return (char)('A' + (nibble - 10));
    }
    else
    {
        return (char) ('0' + nibble);
    }
}









 
static inline  char hexchar_to_nibble( char hexchar, uint8_t* nibble )
{
    if ( ( hexchar >= '0' ) && ( hexchar <= '9' ) )
    {
        *nibble = (uint8_t)( hexchar - '0' );
        return 0;
    }
    else if ( ( hexchar >= 'A' ) && ( hexchar <= 'F' ) )
    {
        *nibble = (uint8_t) ( hexchar - 'A' + 10 );
        return 0;
    }
    else if ( ( hexchar >= 'a' ) && ( hexchar <= 'f' ) )
    {
        *nibble = (uint8_t) ( hexchar - 'a' + 10 );
        return 0;
    }
    return -1;
}







 




 





typedef enum
{
    WAIT_FOR_ANY_EVENT,
    WAIT_FOR_ALL_EVENTS,
} mico_event_flags_wait_option_t;

typedef uint32_t  mico_event_flags_t;
typedef void * mico_semaphore_t;
typedef void * mico_mutex_t;
typedef void * mico_thread_t;
typedef void * mico_queue_t;
typedef void * mico_event_t;
typedef void (*timer_handler_t)( void* arg );
typedef OSStatus (*event_handler_t)( void* arg );

typedef struct
{
    void *          handle;
    timer_handler_t function;
    void *          arg;
}mico_timer_t;

typedef struct
{
    mico_thread_t thread;
    mico_queue_t  event_queue;
} mico_worker_thread_t;

typedef struct
{
    event_handler_t        function;
    void*                  arg;
    mico_timer_t           timer;
    mico_worker_thread_t*  thread;
} mico_timed_event_t;

typedef uint32_t mico_thread_arg_t;
typedef void (*mico_thread_function_t)( mico_thread_arg_t arg );

extern mico_worker_thread_t mico_hardware_io_worker_thread;
extern mico_worker_thread_t mico_worker_thread;

 



 



 





 




 
void mico_rtos_enter_critical( void );




 
void mico_rtos_exit_critical( void );



 























 













 
OSStatus mico_rtos_create_thread( mico_thread_t* thread, uint8_t priority, const char* name, mico_thread_function_t function, uint32_t stack_size, mico_thread_arg_t arg );







 
OSStatus mico_rtos_delete_thread( mico_thread_t* thread );














 
OSStatus mico_rtos_create_worker_thread( mico_worker_thread_t* worker_thread, uint8_t priority, uint32_t stack_size, uint32_t event_queue_size );








 
OSStatus mico_rtos_delete_worker_thread( mico_worker_thread_t* worker_thread );








 
void mico_rtos_suspend_thread(mico_thread_t* thread);








 
void mico_rtos_suspend_all_thread(void);







 
long mico_rtos_resume_all_thread(void);












 
OSStatus mico_rtos_thread_join( mico_thread_t* thread );












 
OSStatus mico_rtos_thread_force_awake( mico_thread_t* thread );











 
_Bool mico_rtos_is_current_thread( mico_thread_t* thread );




 
mico_thread_t* mico_rtos_get_current_thread( void );






 
void mico_rtos_thread_sleep(uint32_t seconds);






 
void mico_rtos_thread_msleep(uint32_t milliseconds);






 
OSStatus mico_rtos_delay_milliseconds( uint32_t num_ms );








 
OSStatus mico_rtos_print_thread_status( char* buffer, int length );



 




 








 
OSStatus mico_rtos_init_semaphore( mico_semaphore_t* semaphore, int count );








 
OSStatus mico_rtos_set_semaphore( mico_semaphore_t* semaphore );













 
OSStatus mico_rtos_get_semaphore( mico_semaphore_t* semaphore, uint32_t timeout_ms );










 
OSStatus mico_rtos_deinit_semaphore( mico_semaphore_t* semaphore );


 




 











 
OSStatus mico_rtos_init_mutex( mico_mutex_t* mutex );












 
OSStatus mico_rtos_lock_mutex( mico_mutex_t* mutex );











 
OSStatus mico_rtos_unlock_mutex( mico_mutex_t* mutex );










 
OSStatus mico_rtos_deinit_mutex( mico_mutex_t* mutex );


 




 










 
OSStatus mico_rtos_init_queue( mico_queue_t* queue, const char* name, uint32_t message_size, uint32_t number_of_messages );











 
OSStatus mico_rtos_push_to_queue( mico_queue_t* queue, void* message, uint32_t timeout_ms );














 
OSStatus mico_rtos_pop_from_queue( mico_queue_t* queue, void* message, uint32_t timeout_ms );








 
OSStatus mico_rtos_deinit_queue( mico_queue_t* queue );








 
_Bool mico_rtos_is_queue_empty( mico_queue_t* queue );








 
_Bool mico_rtos_is_queue_full( mico_queue_t* queue );



 




 










 
OSStatus mico_rtos_send_asynchronous_event( mico_worker_thread_t* worker_thread, event_handler_t function, void* arg );

















 
OSStatus mico_rtos_register_timed_event( mico_timed_event_t* event_object, mico_worker_thread_t* worker_thread, event_handler_t function, uint32_t time_ms, void* arg );











 
OSStatus mico_rtos_deregister_timed_event( mico_timed_event_t* event_object );




 




 







 
uint32_t mico_rtos_get_time(void);















 
OSStatus mico_init_timer( mico_timer_t* timer, uint32_t time_ms, timer_handler_t function, void* arg );










 
OSStatus mico_start_timer( mico_timer_t* timer );










 
OSStatus mico_stop_timer( mico_timer_t* timer );











 
OSStatus mico_reload_timer( mico_timer_t* timer );










 
OSStatus mico_deinit_timer( mico_timer_t* timer );








 
_Bool mico_is_timer_running( mico_timer_t* timer );

int SetTimer(unsigned long ms, void (*psysTimerHandler)(void));
int SetTimer_uniq(unsigned long ms, void (*psysTimerHandler)(void));
int UnSetTimer(void (*psysTimerHandler)(void));








 
int mico_create_event_fd(mico_event_t event_handle);






 
int mico_delete_event_fd(int fd);



 




 



 















 

#pragma once



 



 









 



 



 



 



 




    








    










 

              









 









 









 








 









 










 










 








 









 








 









 










 








 




   





 






typedef struct
{
    int num_of_chunks;  
    int total_memory;  
    int allocted_memory;  
    int free_memory;  
} micoMemInfo_t;








 
micoMemInfo_t* mico_memory_info( void );







 


 
























  




 


 

 
typedef struct _hk_server_status_t {
   
  uint32_t          statusNumber;
  _Bool              useMFiAuth;
  uint16_t          server_port;

} hk_server_status_t;

OSStatus hk_bonjour_start( int ci, int config_number, char *model );
OSStatus hk_bonjour_update_state_number( void );
OSStatus hk_bonjour_update_config_number( int config_number );
OSStatus hk_bonjour_update_status_flag( void );

























  


































 
































 






























 










extern int errno;










 




 

 
struct in_addr {
    uint32_t s_addr;
};

 
 
 
 

 
struct sockaddr_in {
    uint8_t sin_len;
    uint8_t sin_family;
    uint16_t sin_port;
    struct in_addr sin_addr;
    char sin_zero[8];
};

struct sockaddr {
    uint8_t sa_len;
    uint8_t sa_family;
    uint8_t sa_data[14];
};


struct hostent {
    char  *h_name;       
    char **h_aliases;   
 
    int    h_addrtype;   
    int    h_length;     
    char **h_addr_list; 
 
};


struct addrinfo {
    int               ai_flags;       
    int               ai_family;      
    int               ai_socktype;    
    int               ai_protocol;    
    uint32_t         ai_addrlen;     
    struct sockaddr  *ai_addr;        
    char             *ai_canonname;   
    struct addrinfo  *ai_next;        
};

 






 

typedef struct ip_mreq {
    struct in_addr imr_multiaddr;  
    struct in_addr imr_interface;  
} ip_mreq;




 
typedef enum {
    SO_DEBUG              = 0x0001,      
    SO_ACCEPTCONN         = 0x0002,      
    SO_REUSEADDR          = 0x0004,      
    SO_KEEPALIVE          = 0x0008,      
    SO_DONTROUTE          = 0x0010,      
    SO_BROADCAST          = 0x0020,      
    SO_USELOOPBACK        = 0x0040,      
    SO_LINGER             = 0x0080,      
    SO_OOBINLINE          = 0x0100,      
    SO_REUSEPORT          = 0x0200,      
    SO_BLOCKMODE          = 0x1000,     
 
    SO_SNDBUF             = 0x1001,
    SO_SNDTIMEO           = 0x1005,      
    SO_RCVTIMEO           = 0x1006,      
    SO_ERROR              = 0x1007,      
    SO_TYPE               = 0x1008,      
    SO_NO_CHECK           = 0x100a       

} SOCK_OPT_VAL;

struct pollfd {
	int fd;  
	short events;  
	short revents;  
};




 
typedef enum {
    IP_ADD_MEMBERSHIP       = 0x0003,      
    IP_DROP_MEMBERSHIP      = 0x0004,      
    IP_MULTICAST_TTL        = 0x0005,
    IP_MULTICAST_IF         = 0x0006,
    IP_MULTICAST_LOOP       = 0x0007
} IP_OPT_VAL;



 
typedef enum {
	TCP_NODELAY             = 0x0001,
	TCP_KEEPALIVE           = 0x0002,
    TCP_CONN_NUM            = 0x0006,      
    TCP_MAX_CONN_NUM        = 0x0007,      
    TCP_KEEPIDLE            = 0x0003,      
    TCP_KEEPINTVL           = 0x0004,      
    TCP_KEEPCNT             = 0x0005,      
} TCP_OPT_VAL;


                                        
 




typedef void* mico_ssl_t;



 
enum ssl_version_type_e
{
  SSL_V3_MODE   = 1,
  TLS_V1_0_MODE = 2,
  TLS_V1_1_MODE = 3,
  TLS_V1_2_MODE = 4,
};
typedef uint8_t ssl_version_type_t;


struct timeval {
    long      tv_sec;      
    long      tv_usec;     
};




typedef struct fd_set {
  unsigned long   fds_bits[(((64) + (((sizeof(unsigned long) * 8)) - 1)) / ((sizeof(unsigned long) * 8)))];
} fd_set;









 





















 
int socket(int domain, int type, int protocol);











 
int setsockopt (int socket, int level, int optname, void *optval, uint32_t optlen);













 
int getsockopt (int socket, int level, int optname, void *optval, uint32_t *optlen_ptr);










 
int bind (int socket, struct sockaddr *addr, uint32_t length);










 
int connect (int socket, struct sockaddr *addr, uint32_t length);












 
int listen (int socket, int n);















 
int accept (int socket, struct sockaddr *addr, uint32_t *length_ptr);


























 
int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);

int poll(struct pollfd *fds, int nfds, int timeout);


















 
int send (int socket, const void *buffer, unsigned int size, int flags);





 
int write (int filedes, const void *buffer, unsigned int size);


















 
int sendto (int socket, const void *buffer, unsigned int size, int flags, const struct sockaddr *addr, uint32_t length);




















 
int recv (int socket, void *buffer, unsigned int size, int flags);





 
int read (int filedes, void *buffer, unsigned int size);





























 
int recvfrom (int socket, void *buffer, unsigned int size, int flags, struct sockaddr *addr, uint32_t *length_ptr);
 








 
int close (int filedes);

int shutdown(int s, int how);
int ioctl(int s, long cmd, void *argp);



 





 







 
uint32_t inet_addr (const char *name);











 
extern char *inet_ntoa (struct in_addr addr);


















 
struct hostent* gethostbyname(const char *name);
int getaddrinfo(const char *nodename,
       const char *servname,
       const struct addrinfo *hints,
       struct addrinfo **res);
void freeaddrinfo(struct addrinfo *ai);
int getpeername (int s, struct sockaddr *name, uint32_t *namelen);
int getsockname (int s, struct sockaddr *name, uint32_t *namelen);


















 
void set_tcp_keepalive(int inMaxErrNum, int inSeconds);









 
void get_tcp_keepalive(int *outMaxErrNum, int *outSeconds);


 








 
void ssl_set_client_version( ssl_version_type_t version );









 
int ssl_socket( mico_ssl_t ssl );












 
void ssl_set_cert(const char *_cert_pem, const char *private_key_pem);













 
mico_ssl_t ssl_connect(int fd, int calen, char*ca, int *errno);






 
mico_ssl_t ssl_accept(int fd);










 
int ssl_send(mico_ssl_t ssl, void* data, unsigned int len);









 
int ssl_recv(mico_ssl_t ssl, void* data, unsigned int len);






 
int ssl_close(mico_ssl_t ssl);


int ssl_pending(void*ssl);
int ssl_get_error(void* ssl, int ret);
void ssl_set_using_nonblock(void* ssl, int nonblock);




 






 



 


































 





 




 


typedef struct
{
    const char *    schemePtr;
    unsigned int          schemeLen;
    const char *    userPtr;
    unsigned int          userLen;
    const char *    passwordPtr;
    unsigned int          passwordLen;
    const char *    hostPtr;
    unsigned int          hostLen;
    const char *    pathPtr;
    unsigned int          pathLen;
    const char *    queryPtr;
    unsigned int          queryLen;
    const char *    fragmentPtr;
    unsigned int          fragmentLen;
    
    const char *    segmentPtr; 
    const char *    segmentEnd; 
    
} URLComponents;












 
int URLParseComponents( const char *inSrc, const char *inEnd, URLComponents *outComponents, const char **outSrc );









 
void PrintURL( URLComponents *inURL );




 



 




      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      






typedef struct _HTTPHeader_t
{
    char *              buf;                
    unsigned int              bufLen;             
    unsigned int              len;                
    char *              extraDataPtr;       
    char *              otaDataPtr;         
    unsigned int              extraDataLen;       

    const char *        methodPtr;          
    unsigned int              methodLen;          
    const char *        urlPtr;             
    unsigned int              urlLen;             
    URLComponents       url;                
    const char *        protocolPtr;        
    unsigned int              protocolLen;        
    int                 statusCode;         
    const char *        reasonPhrasePtr;    
    unsigned int              reasonPhraseLen;    

    uint8_t             channelID;          
    uint64_t            contentLength;      
    _Bool                persistent;         

    int                 firstErr;           

    _Bool                dataEndedbyClose;
    _Bool                chunkedData;        
    char *              chunkedDataBufferPtr;     
    unsigned int              chunkedDataBufferLen; 

    void *              userContext;
    _Bool                isCallbackSupported;
    OSStatus            (*onReceivedDataCallback) ( struct _HTTPHeader_t * , uint32_t, uint8_t *, unsigned int, void * ); 
    void                (*onClearCallback) ( struct _HTTPHeader_t * httpHeader, void * userContext );



} HTTPHeader_t;

typedef OSStatus (*onReceivedDataCallback) ( struct _HTTPHeader_t * httpHeader, uint32_t pos, uint8_t * data, unsigned int len, void * userContext );

typedef void (*onClearCallback) ( struct _HTTPHeader_t * httpHeader, void * userContext );

void PrintHTTPHeader( HTTPHeader_t *inHeader );

_Bool findHeader ( HTTPHeader_t *inHeader,  char **  outHeaderEnd);

int HTTPScanFHeaderValue( const char *inHeaderPtr, unsigned int inHeaderLen, const char *inName, const char *inFormat, ... );

int findCRLF( const char *inDataPtr , unsigned int inDataLen, char **  nextDataPtr );

int findChunkedDataLength( const char *inChunkPtr , unsigned int inChunkLen, char **  chunkedDataPtr, const char *inFormat, ... );

int SocketReadHTTPHeader( int inSock, HTTPHeader_t *inHeader );

int SocketReadHTTPBody( int inSock, HTTPHeader_t *inHeader );

int SocketReadHTTPSHeader( mico_ssl_t ssl, HTTPHeader_t *inHeader );

int SocketReadHTTPSBody( mico_ssl_t ssl, HTTPHeader_t *inHeader );

int HTTPHeaderParse( HTTPHeader_t *ioHeader );

int HTTPHeaderMatchMethod( HTTPHeader_t *inHeader, const char *method );

int HTTPHeaderMatchURL( HTTPHeader_t *inHeader, const char *url );

char* HTTPHeaderMatchPartialURL( HTTPHeader_t *inHeader, const char *url );


int HTTPGetHeaderField( const char *inHeaderPtr, 
                             unsigned int     inHeaderLen, 
                             const char *inName, 
                             const char **outNamePtr, 
                             unsigned int     *outNameLen, 
                             const char **outValuePtr, 
                             unsigned int     *outValueLen, 
                             const char **outNext );

HTTPHeader_t * HTTPHeaderCreate( unsigned int bufLen );

HTTPHeader_t * HTTPHeaderCreateWithCallback( unsigned int bufLen, onReceivedDataCallback , onClearCallback , void * context );

void HTTPHeaderClear( HTTPHeader_t *inHeader );

void HTTPHeaderDestory( HTTPHeader_t **inHeader );

int CreateSimpleHTTPOKMessage( uint8_t **outMessage, unsigned int *outMessageSize );

OSStatus CreateSimpleHTTPMessage      ( const char *contentType, uint8_t *inData, unsigned int inDataLen, uint8_t **outMessage, unsigned int *outMessageSize );
OSStatus CreateSimpleHTTPMessageNoCopy( const char *contentType, unsigned int inDataLen, uint8_t **outMessage, unsigned int *outMessageSize );

OSStatus CreateHTTPRespondMessageNoCopy( int status, const char *contentType, unsigned int inDataLen, uint8_t **outMessage, unsigned int *outMessageSize );


OSStatus CreateHTTPMessage( const char *methold, const char *url, const char *contentType, uint8_t *inData, unsigned int inDataLen, uint8_t **outMessage, unsigned int *outMessageSize );

OSStatus CreateHTTPMessageWithHost( const char *methold, const char *url,
                           const char* host, uint16_t port, 
                           const char *contentType, 
                           uint8_t *inData, unsigned int inDataLen, 
                           uint8_t **outMessage, unsigned int *outMessageSize );



typedef struct _security_session_t {
  _Bool          established;
  char          controllerIdentifier[64];
  uint8_t       OutputKey[32];
  uint8_t       InputKey[32];
  uint64_t      recvedDataLen;
  uint8_t*      recvedDataBuffer;
  uint64_t      outputSeqNo;
  uint64_t      inputSeqNo;
} security_session_t;

security_session_t *HKSNewSecuritySession(void);

int HKSecureSocketSend( int sockfd, void *buf, unsigned int len, security_session_t *session);

int HKSecureRead(security_session_t *session, int sockfd, void *buf, unsigned int len);

int HKSocketReadHTTPHeader( int inSock, HTTPHeader_t *inHeader, security_session_t *session );

int HKSocketReadHTTPBody  ( int inSock, HTTPHeader_t *inHeader, security_session_t *session );

OSStatus HKSendResponseMessage(int sockfd, int status, uint8_t *payload, int payloadLen, security_session_t *session );

OSStatus HKSendNotifyMessage( int sockfd, uint8_t *payload, int payloadLen, security_session_t *session );

































 


#include <stdarg.h>




 




 





 




 


void formatMACAddr(char *destAddr, char *srcAddr);











 
unsigned int str2hex(unsigned char *ibuf, unsigned char *obuf, unsigned int olen);








 
void Int2Str(uint8_t* str, int32_t intnum);










 
uint32_t Str2Int(uint8_t *inputstr, int32_t *intnum);








 
char *__strdup(const char *src);









 
char *__strdup_trans_dot(char *src);













 
int TextToHardwareAddress( const void *inText, unsigned int inTextSize, unsigned int inAddrSize, void *outAddr );











 
char* DataToCString( const uint8_t *inBuf, unsigned int inBufLen );









 
char* DataToHexString( const uint8_t *inBuf, unsigned int inBufLen );









 
char* DataToHexStringWithSpaces( const uint8_t *inBuf, unsigned int inBufLen );









 
char* DataToHexStringWithColons( const uint8_t *inBuf, unsigned int inBufLen );










 
int strnicmp_suffix( const void *inStr, unsigned int inMaxLen, const char *inSuffix );











 
int strnicmp( const char *inS1, const char *inS2, unsigned int inMax );










 
int strnicmpx( const void *inS1, unsigned int inN, const char *inS2 );










 
char * strnstr_suffix( const char *inStr, unsigned int inMaxLen, const char *inSuffix);










 
int VSNScanF( const void *inString, unsigned int inSize, const char *inFormat, va_list inArgs );










 
uint8_t unsigned_to_hex_string( uint32_t value, char* output, uint8_t min_length, uint8_t max_length );










 
uint8_t string_to_unsigned( const char* string, uint8_t str_length, uint32_t* value_out, uint8_t is_hex );











 
void *memmem(void *start, unsigned int s_len, void *find, unsigned int f_len);

uint8_t unsigned_to_decimal_string( uint32_t value, char* output, uint8_t min_length, uint8_t max_length );




 



 
































  

#pragma once





 



 


 

  
 



 



 



 


 


 


 


 





 
 
  
 



 

 


 

 


 


 






 




 





























 





 




 











 

OSStatus SocketSend( int fd, const uint8_t *inBuf, unsigned int inBufLen );








 
void SocketClose(int* fd);








 
void SocketCloseForOSEvent(int* fd);









 
void SocketAccept(int *plocalTcpClientsPool, int maxClientsNum, int newFd);




 



 
















int sodium_init(void);



 
 






 



unsigned int crypto_aead_chacha20poly1305_keybytes(void);


unsigned int crypto_aead_chacha20poly1305_nsecbytes(void);


unsigned int crypto_aead_chacha20poly1305_npubbytes(void);


unsigned int crypto_aead_chacha20poly1305_abytes(void);


int crypto_aead_chacha20poly1305_encrypt(unsigned char *c,
                                         unsigned long long *clen,
                                         const unsigned char *m,
                                         unsigned long long mlen,
                                         const unsigned char *ad,
                                         unsigned long long adlen,
                                         const unsigned char *nsec,
                                         const unsigned char *npub,
                                         const unsigned char *k);


int crypto_aead_chacha20poly1305_decrypt(unsigned char *m,
                                         unsigned long long *mlen,
                                         unsigned char *nsec,
                                         const unsigned char *c,
                                         unsigned long long clen,
                                         const unsigned char *ad,
                                         unsigned long long adlen,
                                         const unsigned char *npub,
                                         const unsigned char *k);



 
 






 


 
 






 

 
 






 

 
 






 
 
 





 
 
 






 



typedef struct crypto_hash_sha512_state {
    uint64_t      state[8];
    uint64_t      count[2];
    unsigned char buf[128];
} crypto_hash_sha512_state;


unsigned int crypto_hash_sha512_bytes(void);


int crypto_hash_sha512(unsigned char *out, const unsigned char *in,
                       unsigned long long inlen);


int crypto_hash_sha512_init(crypto_hash_sha512_state *state);


int crypto_hash_sha512_update(crypto_hash_sha512_state *state,
                              const unsigned char *in,
                              unsigned long long inlen);


int crypto_hash_sha512_final(crypto_hash_sha512_state *state,
                             unsigned char *out);




typedef struct crypto_auth_hmacsha512_state {
    crypto_hash_sha512_state ictx;
    crypto_hash_sha512_state octx;
} crypto_auth_hmacsha512_state;


unsigned int crypto_auth_hmacsha512_bytes(void);


unsigned int crypto_auth_hmacsha512_keybytes(void);


int crypto_auth_hmacsha512(unsigned char *out,
                           const unsigned char *in,
                           unsigned long long inlen,
                           const unsigned char *k);


int crypto_auth_hmacsha512_verify(const unsigned char *h,
                                  const unsigned char *in,
                                  unsigned long long inlen,
                                  const unsigned char *k);


int crypto_auth_hmacsha512_init(crypto_auth_hmacsha512_state *state,
                                const unsigned char *key,
                                unsigned int keylen);


int crypto_auth_hmacsha512_update(crypto_auth_hmacsha512_state *state,
                                  const unsigned char *in,
                                  unsigned long long inlen);


int crypto_auth_hmacsha512_final(crypto_auth_hmacsha512_state *state,
                                 unsigned char *out);




typedef struct crypto_auth_hmacsha512_state crypto_auth_hmacsha512256_state;


unsigned int crypto_auth_hmacsha512256_bytes(void);


unsigned int crypto_auth_hmacsha512256_keybytes(void);


int crypto_auth_hmacsha512256(unsigned char *out, const unsigned char *in,
                              unsigned long long inlen,const unsigned char *k);


int crypto_auth_hmacsha512256_verify(const unsigned char *h,
                                     const unsigned char *in,
                                     unsigned long long inlen,
                                     const unsigned char *k);


int crypto_auth_hmacsha512256_init(crypto_auth_hmacsha512256_state *state,
                                   const unsigned char *key,
                                   unsigned int keylen);


int crypto_auth_hmacsha512256_update(crypto_auth_hmacsha512256_state *state,
                                     const unsigned char *in,
                                     unsigned long long inlen);


int crypto_auth_hmacsha512256_final(crypto_auth_hmacsha512256_state *state,
                                    unsigned char *out);





unsigned int  crypto_auth_bytes(void);


unsigned int  crypto_auth_keybytes(void);


const char *crypto_auth_primitive(void);


int crypto_auth(unsigned char *out, const unsigned char *in,
                unsigned long long inlen, const unsigned char *k);


int crypto_auth_verify(const unsigned char *h, const unsigned char *in,
                       unsigned long long inlen, const unsigned char *k);


 
 






 

 
 






 
 
 





 
 
 






 



typedef struct crypto_hash_sha256_state {
    uint32_t      state[8];
    uint32_t      count[2];
    unsigned char buf[64];
} crypto_hash_sha256_state;


unsigned int crypto_hash_sha256_bytes(void);


int crypto_hash_sha256(unsigned char *out, const unsigned char *in,
                       unsigned long long inlen);


int crypto_hash_sha256_init(crypto_hash_sha256_state *state);


int crypto_hash_sha256_update(crypto_hash_sha256_state *state,
                              const unsigned char *in,
                              unsigned long long inlen);


int crypto_hash_sha256_final(crypto_hash_sha256_state *state,
                             unsigned char *out);




typedef struct crypto_auth_hmacsha256_state {
    crypto_hash_sha256_state ictx;
    crypto_hash_sha256_state octx;
} crypto_auth_hmacsha256_state;


unsigned int crypto_auth_hmacsha256_bytes(void);


unsigned int crypto_auth_hmacsha256_keybytes(void);


int crypto_auth_hmacsha256(unsigned char *out,
                           const unsigned char *in,
                           unsigned long long inlen,
                           const unsigned char *k);


int crypto_auth_hmacsha256_verify(const unsigned char *h,
                                  const unsigned char *in,
                                  unsigned long long inlen,
                                  const unsigned char *k);


int crypto_auth_hmacsha256_init(crypto_auth_hmacsha256_state *state,
                                const unsigned char *key,
                                unsigned int keylen);


int crypto_auth_hmacsha256_update(crypto_auth_hmacsha256_state *state,
                                  const unsigned char *in,
                                  unsigned long long inlen);


int crypto_auth_hmacsha256_final(crypto_auth_hmacsha256_state *state,
                                 unsigned char *out);








 

 
 






 


 
 






 



unsigned int crypto_box_curve25519xsalsa20poly1305_seedbytes(void);


unsigned int crypto_box_curve25519xsalsa20poly1305_publickeybytes(void);


unsigned int crypto_box_curve25519xsalsa20poly1305_secretkeybytes(void);


unsigned int crypto_box_curve25519xsalsa20poly1305_beforenmbytes(void);


unsigned int crypto_box_curve25519xsalsa20poly1305_noncebytes(void);


unsigned int crypto_box_curve25519xsalsa20poly1305_zerobytes(void);


unsigned int crypto_box_curve25519xsalsa20poly1305_boxzerobytes(void);


unsigned int crypto_box_curve25519xsalsa20poly1305_macbytes(void);


int crypto_box_curve25519xsalsa20poly1305(unsigned char *c,
                                          const unsigned char *m,
                                          unsigned long long mlen,
                                          const unsigned char *n,
                                          const unsigned char *pk,
                                          const unsigned char *sk);


int crypto_box_curve25519xsalsa20poly1305_open(unsigned char *m,
                                               const unsigned char *c,
                                               unsigned long long clen,
                                               const unsigned char *n,
                                               const unsigned char *pk,
                                               const unsigned char *sk);


int crypto_box_curve25519xsalsa20poly1305_seed_keypair(unsigned char *pk,
                                                       unsigned char *sk,
                                                       const unsigned char *seed);


int crypto_box_curve25519xsalsa20poly1305_keypair(unsigned char *pk,
                                                  unsigned char *sk);


int crypto_box_curve25519xsalsa20poly1305_beforenm(unsigned char *k,
                                                   const unsigned char *pk,
                                                   const unsigned char *sk);


int crypto_box_curve25519xsalsa20poly1305_afternm(unsigned char *c,
                                                  const unsigned char *m,
                                                  unsigned long long mlen,
                                                  const unsigned char *n,
                                                  const unsigned char *k);


int crypto_box_curve25519xsalsa20poly1305_open_afternm(unsigned char *m,
                                                       const unsigned char *c,
                                                       unsigned long long clen,
                                                       const unsigned char *n,
                                                       const unsigned char *k);





unsigned int  crypto_box_seedbytes(void);


unsigned int  crypto_box_publickeybytes(void);


unsigned int  crypto_box_secretkeybytes(void);


unsigned int  crypto_box_beforenmbytes(void);


unsigned int  crypto_box_noncebytes(void);


unsigned int  crypto_box_zerobytes(void);


unsigned int  crypto_box_boxzerobytes(void);


unsigned int  crypto_box_macbytes(void);


const char *crypto_box_primitive(void);


int crypto_box_seed_keypair(unsigned char *pk, unsigned char *sk,
                            const unsigned char *seed);


int crypto_box_keypair(unsigned char *pk, unsigned char *sk);


int crypto_box_beforenm(unsigned char *k, const unsigned char *pk,
                        const unsigned char *sk);


int crypto_box_afternm(unsigned char *c, const unsigned char *m,
                       unsigned long long mlen, const unsigned char *n,
                       const unsigned char *k);


int crypto_box_open_afternm(unsigned char *m, const unsigned char *c,
                            unsigned long long clen, const unsigned char *n,
                            const unsigned char *k);


int crypto_box(unsigned char *c, const unsigned char *m,
               unsigned long long mlen, const unsigned char *n,
               const unsigned char *pk, const unsigned char *sk);


int crypto_box_open(unsigned char *m, const unsigned char *c,
                    unsigned long long clen, const unsigned char *n,
                    const unsigned char *pk, const unsigned char *sk);


int crypto_box_easy(unsigned char *c, const unsigned char *m,
                    unsigned long long mlen, const unsigned char *n,
                    const unsigned char *pk, const unsigned char *sk);


int crypto_box_open_easy(unsigned char *m, const unsigned char *c,
                         unsigned long long clen, const unsigned char *n,
                         const unsigned char *pk, const unsigned char *sk);


int crypto_box_detached(unsigned char *c, unsigned char *mac,
                        const unsigned char *m, unsigned long long mlen,
                        const unsigned char *n, const unsigned char *pk,
                        const unsigned char *sk);


int crypto_box_open_detached(unsigned char *m, const unsigned char *c,
                             const unsigned char *mac,
                             unsigned long long clen,
                             const unsigned char *n,
                             const unsigned char *pk,
                             const unsigned char *sk);


 
 






 



unsigned int crypto_core_hsalsa20_outputbytes(void);


unsigned int crypto_core_hsalsa20_inputbytes(void);


unsigned int crypto_core_hsalsa20_keybytes(void);


unsigned int crypto_core_hsalsa20_constbytes(void);


int crypto_core_hsalsa20(unsigned char *out, const unsigned char *in,
                         const unsigned char *k, const unsigned char *c);



 
 






 



unsigned int crypto_core_salsa20_outputbytes(void);


unsigned int crypto_core_salsa20_inputbytes(void);


unsigned int crypto_core_salsa20_keybytes(void);


unsigned int crypto_core_salsa20_constbytes(void);


int crypto_core_salsa20(unsigned char *out, const unsigned char *in,
                        const unsigned char *k, const unsigned char *c);



 
 






 



unsigned int crypto_core_salsa2012_outputbytes(void);


unsigned int crypto_core_salsa2012_inputbytes(void);


unsigned int crypto_core_salsa2012_keybytes(void);


unsigned int crypto_core_salsa2012_constbytes(void);


int crypto_core_salsa2012(unsigned char *out, const unsigned char *in,
                          const unsigned char *k, const unsigned char *c);



 
 






 



unsigned int crypto_core_salsa208_outputbytes(void);


unsigned int crypto_core_salsa208_inputbytes(void);


unsigned int crypto_core_salsa208_keybytes(void);


unsigned int crypto_core_salsa208_constbytes(void);


int crypto_core_salsa208(unsigned char *out, const unsigned char *in,
                         const unsigned char *k, const unsigned char *c);



 
 






 


 
 






 
 
 





 
 
 






 




#pragma pack(push, 1)
 typedef struct crypto_generichash_blake2b_state {
    uint64_t h[8];
    uint64_t t[2];
    uint64_t f[2];
    uint8_t  buf[2 * 128];
    unsigned int   buflen;
    uint8_t  last_node;
} crypto_generichash_blake2b_state;
#pragma pack(pop)


unsigned int crypto_generichash_blake2b_bytes_min(void);


unsigned int crypto_generichash_blake2b_bytes_max(void);


unsigned int crypto_generichash_blake2b_bytes(void);


unsigned int crypto_generichash_blake2b_keybytes_min(void);


unsigned int crypto_generichash_blake2b_keybytes_max(void);


unsigned int crypto_generichash_blake2b_keybytes(void);


unsigned int crypto_generichash_blake2b_saltbytes(void);


unsigned int crypto_generichash_blake2b_personalbytes(void);


int crypto_generichash_blake2b(unsigned char *out, unsigned int outlen,
                               const unsigned char *in,
                               unsigned long long inlen,
                               const unsigned char *key, unsigned int keylen);


int crypto_generichash_blake2b_salt_personal(unsigned char *out, unsigned int outlen,
                                             const unsigned char *in,
                                             unsigned long long inlen,
                                             const unsigned char *key,
                                             unsigned int keylen,
                                             const unsigned char *salt,
                                             const unsigned char *personal);


int crypto_generichash_blake2b_init(crypto_generichash_blake2b_state *state,
                                    const unsigned char *key,
                                    const unsigned int keylen, const unsigned int outlen);


int crypto_generichash_blake2b_init_salt_personal(crypto_generichash_blake2b_state *state,
                                                  const unsigned char *key,
                                                  const unsigned int keylen, const unsigned int outlen,
                                                  const unsigned char *salt,
                                                  const unsigned char *personal);


int crypto_generichash_blake2b_update(crypto_generichash_blake2b_state *state,
                                      const unsigned char *in,
                                      unsigned long long inlen);


int crypto_generichash_blake2b_final(crypto_generichash_blake2b_state *state,
                                     unsigned char *out,
                                     const unsigned int outlen);





unsigned int  crypto_generichash_bytes_min(void);


unsigned int  crypto_generichash_bytes_max(void);


unsigned int  crypto_generichash_bytes(void);


unsigned int  crypto_generichash_keybytes_min(void);


unsigned int  crypto_generichash_keybytes_max(void);


unsigned int  crypto_generichash_keybytes(void);


const char *crypto_generichash_primitive(void);

typedef crypto_generichash_blake2b_state crypto_generichash_state;


int crypto_generichash(unsigned char *out, unsigned int outlen,
                       const unsigned char *in, unsigned long long inlen,
                       const unsigned char *key, unsigned int keylen);


int crypto_generichash_init(crypto_generichash_state *state,
                            const unsigned char *key,
                            const unsigned int keylen, const unsigned int outlen);


int crypto_generichash_update(crypto_generichash_state *state,
                              const unsigned char *in,
                              unsigned long long inlen);


int crypto_generichash_final(crypto_generichash_state *state,
                             unsigned char *out, const unsigned int outlen);



 
 






 




unsigned int crypto_hash_bytes(void);


int crypto_hash(unsigned char *out, const unsigned char *in,
                unsigned long long inlen);


const char *crypto_hash_primitive(void);



 
 






 


 
 






 


 
 





 
 
 





 

typedef struct crypto_onetimeauth_poly1305_state {
    unsigned long long aligner;
    unsigned char      opaque[136];
} crypto_onetimeauth_poly1305_state;

typedef struct crypto_onetimeauth_poly1305_implementation {
    const char *(*implementation_name)(void);
    int         (*onetimeauth)(unsigned char *out,
                               const unsigned char *in,
                               unsigned long long inlen,
                               const unsigned char *k);
    int         (*onetimeauth_verify)(const unsigned char *h,
                                      const unsigned char *in,
                                      unsigned long long inlen,
                                      const unsigned char *k);
    int         (*onetimeauth_init)(crypto_onetimeauth_poly1305_state *state,
                                    const unsigned char *key);
    int         (*onetimeauth_update)(crypto_onetimeauth_poly1305_state *state,
                                      const unsigned char *in,
                                      unsigned long long inlen);
    int         (*onetimeauth_final)(crypto_onetimeauth_poly1305_state *state,
                                     unsigned char *out);
} crypto_onetimeauth_poly1305_implementation;


unsigned int crypto_onetimeauth_poly1305_bytes(void);


unsigned int crypto_onetimeauth_poly1305_keybytes(void);


const char *crypto_onetimeauth_poly1305_implementation_name(void);


int crypto_onetimeauth_poly1305_set_implementation(crypto_onetimeauth_poly1305_implementation *impl);


crypto_onetimeauth_poly1305_implementation *
        crypto_onetimeauth_pick_best_implementation(void);


int crypto_onetimeauth_poly1305(unsigned char *out,
                                const unsigned char *in,
                                unsigned long long inlen,
                                const unsigned char *k);


int crypto_onetimeauth_poly1305_verify(const unsigned char *h,
                                       const unsigned char *in,
                                       unsigned long long inlen,
                                       const unsigned char *k);


int crypto_onetimeauth_poly1305_init(crypto_onetimeauth_poly1305_state *state,
                                     const unsigned char *key);


int crypto_onetimeauth_poly1305_update(crypto_onetimeauth_poly1305_state *state,
                                       const unsigned char *in,
                                       unsigned long long inlen);


int crypto_onetimeauth_poly1305_final(crypto_onetimeauth_poly1305_state *state,
                                      unsigned char *out);




typedef crypto_onetimeauth_poly1305_state crypto_onetimeauth_state;


unsigned int  crypto_onetimeauth_bytes(void);


unsigned int  crypto_onetimeauth_keybytes(void);


const char *crypto_onetimeauth_primitive(void);


int crypto_onetimeauth(unsigned char *out, const unsigned char *in,
                       unsigned long long inlen, const unsigned char *k);


int crypto_onetimeauth_verify(const unsigned char *h, const unsigned char *in,
                              unsigned long long inlen, const unsigned char *k);


int crypto_onetimeauth_init(crypto_onetimeauth_state *state,
                            const unsigned char *key);


int crypto_onetimeauth_update(crypto_onetimeauth_state *state,
                              const unsigned char *in,
                              unsigned long long inlen);


int crypto_onetimeauth_final(crypto_onetimeauth_state *state,
                             unsigned char *out);




 
 






 




unsigned int crypto_pwhash_scryptsalsa208sha256_saltbytes(void);


unsigned int crypto_pwhash_scryptsalsa208sha256_strbytes(void);


unsigned int crypto_pwhash_scryptsalsa208sha256_opslimit_interactive(void);


unsigned int crypto_pwhash_scryptsalsa208sha256_memlimit_interactive(void);


unsigned int crypto_pwhash_scryptsalsa208sha256_opslimit_sensitive(void);


unsigned int crypto_pwhash_scryptsalsa208sha256_memlimit_sensitive(void);


int crypto_pwhash_scryptsalsa208sha256(unsigned char * const out,
                                       unsigned long long outlen,
                                       const char * const passwd,
                                       unsigned long long passwdlen,
                                       const unsigned char * const salt,
                                       unsigned long long opslimit,
                                       unsigned int memlimit);


int crypto_pwhash_scryptsalsa208sha256_str(char out[102],
                                           const char * const passwd,
                                           unsigned long long passwdlen,
                                           unsigned long long opslimit,
                                           unsigned int memlimit);


int crypto_pwhash_scryptsalsa208sha256_str_verify(const char str[102],
                                                  const char * const passwd,
                                                  unsigned long long passwdlen);


int crypto_pwhash_scryptsalsa208sha256_ll(const uint8_t * passwd, unsigned int passwdlen,
                                          const uint8_t * salt, unsigned int saltlen,
                                          uint64_t N, uint32_t r, uint32_t p,
                                          uint8_t * buf, unsigned int buflen);


 



 
 






 


 
 






 




unsigned int crypto_scalarmult_curve25519_bytes(void);


unsigned int crypto_scalarmult_curve25519_scalarbytes(void);


int crypto_scalarmult_curve25519(unsigned char *q, const unsigned char *n,
                                 const unsigned char *p);


int crypto_scalarmult_curve25519_base(unsigned char *q, const unsigned char *n);





unsigned int  crypto_scalarmult_bytes(void);


unsigned int  crypto_scalarmult_scalarbytes(void);


const char *crypto_scalarmult_primitive(void);


int crypto_scalarmult_base(unsigned char *q, const unsigned char *n);


int crypto_scalarmult(unsigned char *q, const unsigned char *n,
                      const unsigned char *p);



 
 






 


 
 






 



unsigned int crypto_secretbox_xsalsa20poly1305_keybytes(void);


unsigned int crypto_secretbox_xsalsa20poly1305_noncebytes(void);


unsigned int crypto_secretbox_xsalsa20poly1305_zerobytes(void);


unsigned int crypto_secretbox_xsalsa20poly1305_boxzerobytes(void);


unsigned int crypto_secretbox_xsalsa20poly1305_macbytes(void);


int crypto_secretbox_xsalsa20poly1305(unsigned char *c,
                                      const unsigned char *m,
                                      unsigned long long mlen,
                                      const unsigned char *n,
                                      const unsigned char *k);


int crypto_secretbox_xsalsa20poly1305_open(unsigned char *m,
                                           const unsigned char *c,
                                           unsigned long long clen,
                                           const unsigned char *n,
                                           const unsigned char *k);





unsigned int  crypto_secretbox_keybytes(void);


unsigned int  crypto_secretbox_noncebytes(void);


unsigned int  crypto_secretbox_zerobytes(void);


unsigned int  crypto_secretbox_boxzerobytes(void);


unsigned int  crypto_secretbox_macbytes(void);


const char *crypto_secretbox_primitive(void);


int crypto_secretbox(unsigned char *c, const unsigned char *m,
                     unsigned long long mlen, const unsigned char *n,
                     const unsigned char *k);


int crypto_secretbox_open(unsigned char *m, const unsigned char *c,
                          unsigned long long clen, const unsigned char *n,
                          const unsigned char *k);


int crypto_secretbox_easy(unsigned char *c, const unsigned char *m,
                          unsigned long long mlen, const unsigned char *n,
                          const unsigned char *k);


int crypto_secretbox_open_easy(unsigned char *m, const unsigned char *c,
                               unsigned long long clen, const unsigned char *n,
                               const unsigned char *k);


int crypto_secretbox_detached(unsigned char *c, unsigned char *mac,
                              const unsigned char *m,
                              unsigned long long mlen,
                              const unsigned char *n,
                              const unsigned char *k);


int crypto_secretbox_open_detached(unsigned char *m,
                                   const unsigned char *c,
                                   const unsigned char *mac,
                                   unsigned long long clen,
                                   const unsigned char *n,
                                   const unsigned char *k);


 
 






 


 
 






 



unsigned int crypto_shorthash_siphash24_bytes(void);


unsigned int crypto_shorthash_siphash24_keybytes(void);


int crypto_shorthash_siphash24(unsigned char *out, const unsigned char *in,
                               unsigned long long inlen, const unsigned char *k);





unsigned int  crypto_shorthash_bytes(void);


unsigned int  crypto_shorthash_keybytes(void);


const char *crypto_shorthash_primitive(void);


int crypto_shorthash(unsigned char *out, const unsigned char *in,
                     unsigned long long inlen, const unsigned char *k);








 

 
 






 


 
 






 



unsigned int crypto_sign_ed25519_bytes(void);


unsigned int crypto_sign_ed25519_seedbytes(void);


unsigned int crypto_sign_ed25519_publickeybytes(void);


unsigned int crypto_sign_ed25519_secretkeybytes(void);


int crypto_sign_ed25519(unsigned char *sm, unsigned long long *smlen,
                        const unsigned char *m, unsigned long long mlen,
                        const unsigned char *sk);


int crypto_sign_ed25519_open(unsigned char *m, unsigned long long *mlen,
                             const unsigned char *sm, unsigned long long smlen,
                             const unsigned char *pk);


int crypto_sign_ed25519_keypair(unsigned char *pk, unsigned char *sk);


int crypto_sign_ed25519_seed_keypair(unsigned char *pk, unsigned char *sk,
                                     const unsigned char *seed);






unsigned int  crypto_sign_bytes(void);


unsigned int  crypto_sign_seedbytes(void);


unsigned int  crypto_sign_publickeybytes(void);


unsigned int  crypto_sign_secretkeybytes(void);


const char *crypto_sign_primitive(void);


int crypto_sign_seed_keypair(unsigned char *pk, unsigned char *sk,
                             const unsigned char *seed);


int crypto_sign_keypair(unsigned char *pk, unsigned char *sk);


int crypto_sign(unsigned char *sm, unsigned long long *smlen,
                const unsigned char *m, unsigned long long mlen,
                const unsigned char *sk);


int crypto_sign_open(unsigned char *m, unsigned long long *mlen,
                     const unsigned char *sm, unsigned long long smlen,
                     const unsigned char *pk);










 

 
 






 








 

 
 






 



unsigned int crypto_stream_xsalsa20_keybytes(void);


unsigned int crypto_stream_xsalsa20_noncebytes(void);


int crypto_stream_xsalsa20(unsigned char *c, unsigned long long clen,
                           const unsigned char *n, const unsigned char *k);


int crypto_stream_xsalsa20_xor(unsigned char *c, const unsigned char *m,
                               unsigned long long mlen, const unsigned char *n,
                               const unsigned char *k);






unsigned int  crypto_stream_keybytes(void);


unsigned int  crypto_stream_noncebytes(void);


const char *crypto_stream_primitive(void);


int crypto_stream(unsigned char *c, unsigned long long clen,
                  const unsigned char *n, const unsigned char *k);


int crypto_stream_xor(unsigned char *c, const unsigned char *m,
                      unsigned long long mlen, const unsigned char *n,
                      const unsigned char *k);










 

 
 






 



unsigned int crypto_stream_aes128ctr_keybytes(void);


unsigned int crypto_stream_aes128ctr_noncebytes(void);


unsigned int crypto_stream_aes128ctr_beforenmbytes(void);


int crypto_stream_aes128ctr(unsigned char *out, unsigned long long outlen,
                            const unsigned char *n, const unsigned char *k);


int crypto_stream_aes128ctr_xor(unsigned char *out, const unsigned char *in,
                                unsigned long long inlen, const unsigned char *n,
                                const unsigned char *k);


int crypto_stream_aes128ctr_beforenm(unsigned char *c, const unsigned char *k);


int crypto_stream_aes128ctr_afternm(unsigned char *out, unsigned long long len,
                                    const unsigned char *nonce, const unsigned char *c);


int crypto_stream_aes128ctr_xor_afternm(unsigned char *out, const unsigned char *in,
                                        unsigned long long len,
                                        const unsigned char *nonce,
                                        const unsigned char *c);










 

 
 






 



unsigned int crypto_stream_aes256estream_keybytes(void);


unsigned int crypto_stream_aes256estream_noncebytes(void);


unsigned int crypto_stream_aes256estream_beforenmbytes(void);


int crypto_stream_aes256estream(unsigned char *out, unsigned long long len,
                                const unsigned char *nonce, const unsigned char *c);


int crypto_stream_aes256estream_xor(unsigned char *out, const unsigned char *in,
                                    unsigned long long inlen, const unsigned char *n,
                                    const unsigned char *k);


int crypto_stream_aes256estream_beforenm(unsigned char *c, const unsigned char *k);


int crypto_stream_aes256estream_afternm(unsigned char *out, unsigned long long len,
                                        const unsigned char *nonce,
                                        const unsigned char *c);


int crypto_stream_aes256estream_xor_afternm(unsigned char *out, const unsigned char *in,
                                            unsigned long long len,
                                            const unsigned char *nonce,
                                            const unsigned char *c);









 

 
 






 
 
 





 



unsigned int crypto_stream_chacha20_keybytes(void);


unsigned int crypto_stream_chacha20_noncebytes(void);


int crypto_stream_chacha20(unsigned char *c, unsigned long long clen,
                           const unsigned char *n, const unsigned char *k);


int crypto_stream_chacha20_xor(unsigned char *c, const unsigned char *m,
                               unsigned long long mlen, const unsigned char *n,
                               const unsigned char *k);


int crypto_stream_chacha20_xor_ic(unsigned char *c, const unsigned char *m,
                                  unsigned long long mlen,
                                  const unsigned char *n, uint64_t ic,
                                  const unsigned char *k);









 

 
 






 
 
 





 



unsigned int crypto_stream_salsa20_keybytes(void);


unsigned int crypto_stream_salsa20_noncebytes(void);


int crypto_stream_salsa20(unsigned char *c, unsigned long long clen,
                          const unsigned char *n, const unsigned char *k);


int crypto_stream_salsa20_xor(unsigned char *c, const unsigned char *m,
                              unsigned long long mlen, const unsigned char *n,
                              const unsigned char *k);


int crypto_stream_salsa20_xor_ic(unsigned char *c, const unsigned char *m,
                                 unsigned long long mlen,
                                 const unsigned char *n, uint64_t ic,
                                 const unsigned char *k);








 

 
 






 



unsigned int crypto_stream_salsa2012_keybytes(void);


unsigned int crypto_stream_salsa2012_noncebytes(void);


int crypto_stream_salsa2012(unsigned char *c, unsigned long long clen,
                            const unsigned char *n, const unsigned char *k);


int crypto_stream_salsa2012_xor(unsigned char *c, const unsigned char *m,
                                unsigned long long mlen, const unsigned char *n,
                                const unsigned char *k);









 

 
 






 



unsigned int crypto_stream_salsa208_keybytes(void);


unsigned int crypto_stream_salsa208_noncebytes(void);


int crypto_stream_salsa208(unsigned char *c, unsigned long long clen,
                           const unsigned char *n, const unsigned char *k);


int crypto_stream_salsa208_xor(unsigned char *c, const unsigned char *m,
                               unsigned long long mlen, const unsigned char *n,
                               const unsigned char *k);



 
 






 



unsigned int crypto_verify_16_bytes(void);


int crypto_verify_16(const unsigned char *x, const unsigned char *y);




 
 






 



unsigned int crypto_verify_32_bytes(void);


int crypto_verify_32(const unsigned char *x, const unsigned char *y);



 
 






 



unsigned int crypto_verify_64_bytes(void);


int crypto_verify_64(const unsigned char *x, const unsigned char *y);




 
 






 
 
 





 



typedef struct randombytes_implementation {
    const char *(*implementation_name)(void);
    uint32_t    (*random)(void);
    void        (*stir)(void);
    uint32_t    (*uniform)(const uint32_t upper_bound);
    void        (*buf)(void * const buf, const unsigned int size);
    int         (*close)(void);
} randombytes_implementation;


int         randombytes_set_implementation(randombytes_implementation *impl);


void        randombytes(unsigned char * const buf, const unsigned long long buf_len);


const char *randombytes_implementation_name(void);


uint32_t    randombytes_random(void);


void        randombytes_stir(void);


uint32_t    randombytes_uniform(const uint32_t upper_bound);


void        randombytes_buf(void * const buf, const unsigned int size);


int         randombytes_close(void);








 

 
 






 
 
 





 




extern struct randombytes_implementation randombytes_salsa20_implementation;


const char *randombytes_salsa20_implementation_name(void);


uint32_t    randombytes_salsa20_random(void);


void        randombytes_salsa20_random_stir(void);


uint32_t    randombytes_salsa20_random_uniform(const uint32_t upper_bound);


void        randombytes_salsa20_random_buf(void * const buf, const unsigned int size);


int         randombytes_salsa20_random_close(void);








 

 
 






 
 
 





 




extern struct randombytes_implementation randombytes_sysrandom_implementation;


const char *randombytes_sysrandom_implementation_name(void);


uint32_t    randombytes_sysrandom(void);


void        randombytes_sysrandom_stir(void);


uint32_t    randombytes_sysrandom_uniform(const uint32_t upper_bound);


void        randombytes_sysrandom_buf(void * const buf, const unsigned int size);


int         randombytes_sysrandom_close(void);








int sodium_runtime_get_cpu_features(void);


int sodium_runtime_has_neon(void);


int sodium_runtime_has_sse2(void);


int sodium_runtime_has_sse3(void);




 
 






 




unsigned char *_sodium_alignedcalloc(unsigned char ** const unaligned_p,
                                     const unsigned int len);


void sodium_memzero(void * const pnt, const unsigned int len);


int sodium_memcmp(const void * const b1_, const void * const b2_, unsigned int len);


char *sodium_bin2hex(char * const hex, const unsigned int hex_maxlen,
                     const unsigned char * const bin, const unsigned int bin_len);


int sodium_hex2bin(unsigned char * const bin, const unsigned int bin_maxlen,
                   const char * const hex, const unsigned int hex_len,
                   const char * const ignore, unsigned int * const bin_len,
                   const char ** const hex_end);


int sodium_mlock(void * const addr, const unsigned int len);


int sodium_munlock(void * const addr, const unsigned int len);










const char *sodium_version_string(void);


int         sodium_library_version_major(void);


int         sodium_library_version_minor(void);







extern _Bool verify_otp(void);


static volatile uint32_t flashStorageAddress = 0x0;

security_session_t *HKSNewSecuritySession(void)
{
  security_session_t *session;
  session = calloc(1, sizeof(security_session_t));
  session->established = 0;
  return session;
}

int HKSecureSocketSend( int sockfd, void *buf, unsigned int len, security_session_t *session)
{
  OSStatus       err = 0;
  uint8_t*       encryptedData = 0;
  uint64_t       encryptedDataLen;

  if(session->established == 0)
    return SocketSend( sockfd, buf, len );

  encryptedData = malloc(len + 16U + sizeof(uint16_t));
  do { if( ! !(!(encryptedData)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
  *(uint16_t *)encryptedData = len;
  err =  crypto_aead_chacha20poly1305_encrypt(encryptedData + sizeof(uint16_t), &encryptedDataLen, (uint8_t *)buf, len,
                                              (const uint8_t *)encryptedData, sizeof(uint16_t), 
                                              0, (uint8_t *)(&session->outputSeqNo),
                                              (const unsigned char *)session->OutputKey);
  session->outputSeqNo++;
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  do { if( ! !(!(encryptedDataLen - 16U == len)) ) { ; goto exit; } } while( 1==0 );

  err = SocketSend( sockfd, encryptedData, encryptedDataLen + sizeof(uint16_t) );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

  exit:
    if(encryptedData) free(encryptedData);
    return err;
}

int HKSecureRead(security_session_t *session, int sockfd, void *buf, unsigned int len)
{
  OSStatus    err = 0;
  uint16_t         packageLength;
  int          length = 0;
  unsigned int         recvLength = 0;
  unsigned int         recvLengthTmp = 0;
  uint8_t*       *encryptedData = 0;

  fd_set      readfds;
  int         returnLength = 0;
  int         selectResult;
  struct      timeval t;
  t.tv_sec  =  20;
  t.tv_usec =  0;

  if(session->established == 1){
    if(session->recvedDataLen){
      returnLength += ((len) < (session->recvedDataLen) ? (len) : (session->recvedDataLen));
      memcpy(buf, session->recvedDataBuffer, returnLength);
      session->recvedDataLen -= returnLength;
      if(session->recvedDataLen)
        memmove(session->recvedDataBuffer, session->recvedDataBuffer+returnLength, session->recvedDataLen);
      else{
        free(session->recvedDataBuffer);
        session->recvedDataBuffer = 0;
      }
      goto exit;
    }else{
      while( recvLengthTmp < sizeof(uint16_t)){
        memset(&readfds, 0, sizeof(*(&readfds)));
        ((&readfds)->fds_bits[(sockfd)/(sizeof(unsigned long) * 8)] |= ((unsigned long)1 << ((sockfd) % (sizeof(unsigned long) * 8))));
        selectResult = select( sockfd + 1, &readfds, 0, 0, &t );
        do { if( ! !(!(selectResult >= 1)) ) { ; goto exit; } } while( 1==0 );
        length = read( sockfd, (uint8_t *)&packageLength + recvLengthTmp, sizeof(uint16_t) - recvLengthTmp);
        if( length > 0 ) recvLengthTmp += length;
        else { err = -6753; goto exit; }
      }

      recvLength = packageLength + 16U;
      recvLengthTmp = 0;

      encryptedData = malloc(recvLength);
      do { if( ! !(!(encryptedData)) ) { ; goto exit; } } while( 1==0 );

      while( recvLengthTmp < recvLength){
        memset(&readfds, 0, sizeof(*(&readfds)));
        ((&readfds)->fds_bits[(sockfd)/(sizeof(unsigned long) * 8)] |= ((unsigned long)1 << ((sockfd) % (sizeof(unsigned long) * 8))));
        selectResult = select( sockfd + 1, &readfds, 0, 0, &t );
        do { if( ! !(!(selectResult >= 1)) ) { ; goto exit; } } while( 1==0 );

        length = read( sockfd, encryptedData + recvLengthTmp, recvLength - recvLengthTmp );
        if( length > 0 ) recvLengthTmp += length;
        else { err = -6753; goto exit; }
      }

      session->recvedDataBuffer = malloc(packageLength);
      do { if( ! !(!(session->recvedDataBuffer)) ) { ; goto exit; } } while( 1==0 );


      err =  crypto_aead_chacha20poly1305_decrypt(session->recvedDataBuffer, &session->recvedDataLen, 0, 
                                                     (const unsigned char *)encryptedData, recvLength, (uint8_t *)&packageLength, 2,  
                                                     (uint8_t *)(&session->inputSeqNo), (const unsigned char *)session->InputKey);

      session->inputSeqNo++;

      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
      do { if( ! !(!(session->recvedDataLen == recvLength - 16U)) ) { ; goto exit; } } while( 1==0 );

      free(encryptedData);
      encryptedData = 0;

      returnLength += ((len) < (session->recvedDataLen) ? (len) : (session->recvedDataLen));
      memcpy(buf, session->recvedDataBuffer, returnLength);
      session->recvedDataLen -= returnLength;
      if(session->recvedDataLen)
        memmove(session->recvedDataBuffer, session->recvedDataBuffer+returnLength, session->recvedDataLen);
      else{
        free(session->recvedDataBuffer);
        session->recvedDataBuffer = 0;
      }

      goto exit;

    }

    exit:
      if(err == 0)
        return returnLength;
      else{
        if(encryptedData) free(encryptedData);
        if(session->recvedDataBuffer) {
          free(session->recvedDataBuffer);
          session->recvedDataBuffer = 0;
        }
        return 0;
      }
  }
  else
    return read( sockfd, buf, len);
}


int HKSocketReadHTTPHeader( int inSock, HTTPHeader_t *inHeader, security_session_t *session )
{
  int        err =0;
  char *          buf;
  char *          dst;
  char *          lim;
  char *          end;
  int          len;
  int         n;
  const char *    value;
  unsigned int          valueSize;
  
  
  buf = inHeader->buf;
  dst = buf + inHeader->len;
  lim = buf + inHeader->bufLen;
  for( ;; )
  {
    
    len = inHeader->extraDataLen;
    if( len > 0 )
    {
      do { if( ! !(!(len <= (unsigned int)( lim - dst ))) ) { ; { err = -6705; } goto exit; } } while( 1==0 );
      memmove( dst, inHeader->extraDataPtr, len );
      inHeader->extraDataLen = 0;
    }
    else
    {
      n = HKSecureRead( session, inSock, dst, (unsigned int)( lim - dst ) );
      if(      n  > 0 ) len = (unsigned int) n;
      else  { err = -6753; goto exit; }
    }
    dst += len;
    inHeader->len += len;
    
    if(findHeader( inHeader,  &end ))
      break ;
  }
  
  inHeader->len = (unsigned int)( end - buf );
  err = HTTPHeaderParse( inHeader );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  inHeader->extraDataLen = (unsigned int)( dst - end );
  if(inHeader->extraDataPtr) {
    free((uint8_t *)inHeader->extraDataPtr);
    inHeader->extraDataPtr = 0;
  }
  
  if(inHeader->otaDataPtr) {
    free((uint8_t *)inHeader->otaDataPtr);
    inHeader->otaDataPtr = 0;
  }
  
  err = HTTPGetHeaderField( inHeader->buf, inHeader->len, "Content-Type", 0, 0, &value, &valueSize, 0 );
  
  if( inHeader->contentLength != 0)
  {
      inHeader->extraDataPtr = calloc(inHeader->contentLength, sizeof(uint8_t));
      do { if( ! !(!(inHeader->extraDataPtr)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
      memcpy((uint8_t *)inHeader->extraDataPtr, end, inHeader->extraDataLen);
  }
  err = 0;
  
exit:   
  return err;
}



int HKSocketReadHTTPBody  ( int inSock, HTTPHeader_t *inHeader, security_session_t *session )
{
  OSStatus err = -6705;
  int readResult;
  int selectResult;
  fd_set readSet;
  const char *    value;
  unsigned int          valueSize;
  
  do { if( ! !(!(inHeader)) ) { ; goto exit; } } while( 1==0 );
  
  err = -6738;
  
  
  while ( inHeader->extraDataLen < inHeader->contentLength )
  {
    if(session->recvedDataLen == 0){
      memset(&readSet, 0, sizeof(*(&readSet)));
      ((&readSet)->fds_bits[(inSock)/(sizeof(unsigned long) * 8)] |= ((unsigned long)1 << ((inSock) % (sizeof(unsigned long) * 8))));
      selectResult = select( inSock + 1, &readSet, 0, 0, 0 );
      do { if( ! !(!(selectResult >= 1)) ) { ; goto exit; } } while( 1==0 );      
    }
    
    err = HTTPGetHeaderField( inHeader->buf, inHeader->len, "Content-Type", 0, 0, &value, &valueSize, 0 );
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

    readResult = HKSecureRead( session, inSock,
                              (uint8_t*)( inHeader->extraDataPtr + inHeader->extraDataLen ),
                              ( inHeader->contentLength - inHeader->extraDataLen ) );
      
    if( readResult  > 0 ) inHeader->extraDataLen += readResult;
    else if( readResult == 0 ) { err = -6753; goto exit; }
    else goto exit;
  }
  
  err = 0;
  
exit:
  if(inHeader->otaDataPtr) {
    free(inHeader->otaDataPtr);
    inHeader->otaDataPtr = 0;
  }
  return err;
}

OSStatus HKSendResponseMessage(int sockfd, int status, uint8_t *payload, int payloadLen, security_session_t *session )
{
  OSStatus err;
  uint8_t *httpResponse = 0;
  unsigned int httpResponseLen = 0;
  const char *buffer = 0;
  int bufferLen;

  buffer = (const char *)payload;
  bufferLen = payloadLen;

  err = CreateHTTPRespondMessageNoCopy( status, "application/hap+json", bufferLen, &httpResponse, &httpResponseLen );

  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  do { if( ! !(!(httpResponse)) ) { ; goto exit; } } while( 1==0 );

  err = HKSecureSocketSend( sockfd, httpResponse, httpResponseLen, session );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  if(bufferLen){
    err = HKSecureSocketSend( sockfd, (uint8_t *)buffer, bufferLen, session );
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 ); 
  }

exit:
  if(httpResponse) free(httpResponse);
  return err;
}

OSStatus HKSendNotifyMessage( int sockfd, uint8_t *payload, int payloadLen, security_session_t *session )
{
  OSStatus err = 0;
  uint8_t *httpResponse = 0;
  unsigned int httpResponseLen = 0;
  const char *buffer = 0;
  int bufferLen;
  do { if( ! !(!(session->established == 1)) ) { ; { err = -6754; } goto exit; } } while( 1==0 );

  buffer = (const char *)payload;
  bufferLen = payloadLen;
  
  do { if( ! !(!(bufferLen >= 0)) ) { ; goto exit; } } while( 1==0 );
  
  err = -6728;
  httpResponse = malloc( 200 );
  do { if( ! !(!(httpResponse)) ) { ; goto exit; } } while( 1==0 );
  
  
  if(bufferLen)
    snprintf( (char *)httpResponse, 200, 
            "%s %d %s%s%s %s%s%s %d%s",
            "EVENT/1.0", 200, "OK", "\r\n", 
            "Content-Type:", "application/hap+json", "\r\n",
            "Content-Length:", (int)payloadLen, "\r\n\r\n" );
  else
    snprintf( (char *)httpResponse, 200, 
        "%s %d %s%s",
        "EVENT/1.0", 200, "OK", "\r\n\r\n");
  
  httpResponseLen = strlen( (char*)httpResponse );

  err = HKSecureSocketSend( sockfd, httpResponse, httpResponseLen, session );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  if(bufferLen){
    err = HKSecureSocketSend( sockfd, (uint8_t *)buffer, bufferLen, session );
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 ); 
  }

exit:
  if(httpResponse) free(httpResponse);
  return err;
}





