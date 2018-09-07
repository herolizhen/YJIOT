













#pragma once































 



 
 

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







 


 





OSStatus mfi_wac_http_server_start(void *inContext);

OSStatus mfi_wac_http_server_stop(void);
































 

#pragma once































 

#pragma once

















 

#pragma once






























 





  





 




 









  
typedef enum { 
  Soft_AP,   
  Station    
} wlanInterfaceTypedef; 

typedef uint8_t wlan_if_t;



  
enum wlan_sec_type_e{
   SECURITY_TYPE_NONE,         
   SECURITY_TYPE_WEP,          
   SECURITY_TYPE_WPA_TKIP,     
   SECURITY_TYPE_WPA_AES,      
   SECURITY_TYPE_WPA2_TKIP,    
   SECURITY_TYPE_WPA2_AES,     
   SECURITY_TYPE_WPA2_MIXED,   
   SECURITY_TYPE_AUTO,         
};

typedef uint8_t wlan_sec_type_t;



  
typedef struct {
  uint8_t dhcp;        
  char    ip[16];      
  char    gate[16];    
  char    mask[16];    
  char    dns[16];     
  char    mac[16];     
  char    broadcastip[16];
} IPStatusTypedef;
 


   
typedef  struct  _ScanResult_adv 
{ 
  char ApNum;        
  struct { 
    char ssid[32];   
    char ApPower;    
    char bssid[6];   
    char channel;    
    wlan_sec_type_t security;    
  } * ApList;
} ScanResult_adv; 



 
typedef  struct  _ScanResult 
{  
  char ApNum;        
  struct {  
    char ssid[32];   
    char ApPower;    
  } * ApList; 
} ScanResult;  



 
typedef struct _network_InitTypeDef_st 
{ 
  char wifi_mode;                
  char wifi_ssid[32];            
  char wifi_key[64];             
  char local_ip_addr[16];        
  char net_mask[16];             
  char gateway_ip_addr[16];      
  char dnsServer_ip_addr[16];    
  char dhcpMode;                 
  char reserved[32];            
  int  wifi_retry_interval;     
 
} network_InitTypeDef_st; 



 
typedef struct   
{ 
  char    ssid[32];     
  char    bssid[6];     
  uint8_t channel;     

 
  wlan_sec_type_t security;
}   apinfo_adv_t;



 
typedef struct _network_InitTypeDef_adv_st
{
  apinfo_adv_t ap_info;          
  char  key[64];                 
  int   key_len;                 
  char  local_ip_addr[16];       
  char  net_mask[16];            
  char  gateway_ip_addr[16];     
  char  dnsServer_ip_addr[16];   
  char  dhcpMode;                
  char  reserved[32]; 
  int   wifi_retry_interval;    
 
} network_InitTypeDef_adv_st;



 
typedef struct _linkStatus_t{
  int is_connected;        
  int wifi_strength;       
  uint8_t  ssid[32];       
  uint8_t  bssid[6];       
  int      channel;        
} LinkStatusTypeDef;


typedef struct {
    char bssid[6];
    char ssid[33];
    char key[65];
    int  user_data_len;
    char user_data[65];
} easylink_result_t;




 

void wlan_get_mac_address( uint8_t *mac );


















 
OSStatus StartNetwork(network_InitTypeDef_st* inNetworkInitPara);


















 
OSStatus StartAdvNetwork(network_InitTypeDef_adv_st* inNetworkInitParaAdv);










 
OSStatus getNetPara(IPStatusTypedef *outNetpara, wlanInterfaceTypedef inInterface);







 
OSStatus CheckNetLink(LinkStatusTypeDef *outStatus);







 
void mxchipStartScan(void);







 
void mxchipStartAdvScan(void);





 
OSStatus wifi_power_down(void);








 
OSStatus wifi_power_up(void);








 
OSStatus wlan_disconnect(void);








 
OSStatus sta_disconnect(void);





 
OSStatus uap_stop(void);


 




 




















 
OSStatus OpenEasylink2_withdata(int inTimeout);
















 

OSStatus OpenEasylink(int inTimeout);





 
OSStatus CloseEasylink2(void);
OSStatus CloseEasylink(void);



 






 







 
OSStatus OpenConfigmodeWPS(int inTimeout);





 
OSStatus CloseConfigmodeWPS(void);




 





 














 
OSStatus OpenAirkiss(int inTimeout);




 
OSStatus CloseAirkiss(void);


 




 







 

void ps_enable(void);





 
void ps_disable(void); 



 




 







 
void wifimgr_debug_enable(_Bool enable);

 




 
typedef void (*monitor_cb_t)(uint8_t*data, int len);
enum {
	WLAN_RX_BEACON,     
	WLAN_RX_PROBE_REQ,  
	WLAN_RX_PROBE_RES,  
	WLAN_RX_ACTION,     
	WLAN_RX_MANAGEMENT, 
	WLAN_RX_DATA,       
	WLAN_RX_MCAST_DATA, 

	WLAN_RX_ALL,        
};




 
int mico_wlan_monitor_rx_type(int type);





 
int mico_wlan_start_monitor(void);



 
int mico_wlan_stop_monitor(void);





 
int mico_wlan_set_channel(int channel);



 
void mico_wlan_register_monitor_cb(monitor_cb_t fn);









 
OSStatus mico_wlan_custom_ie_add(wlan_if_t wlan_if, uint8_t *custom_ie, uint32_t len);

enum custom_ie_delete_op_e
{
  CUSTOM_IE_DELETE_ALL = 0,
  CUSTOM_IE_DELETE_BY_OUI = 1,
};
typedef uint8_t custom_ie_delete_op_t;










 
OSStatus mico_wlan_custom_ie_delete(wlan_if_t wlan_if, custom_ie_delete_op_t op, uint8_t *option_data, uint32_t len);







 
void mico_wlan_get_mac_address_by_interface( wlan_if_t wlan_if, uint8_t *mac );


 




 



 



































  

#pragma once





 



 


 

  
 



 



 



 


 


 


 


 





 
 
  
 



 

 


 

 


 


 






 




 








 

typedef enum
{
  eState_Normal,
  eState_Software_Reset,
  eState_Wlan_Powerdown,
  eState_Restore_default,
  eState_Standby,
} system_state_t;

enum  config_state_type_e{
  
 
  unConfigured,
  


                 
  wLanUnConfigured,
  
 
  allConfigured,
  
 
  mfgConfigured,
  
 
  unConfigured2
};
typedef uint8_t config_state_type_t;

 
typedef struct  _boot_table_t {
  uint32_t start_address; 
  uint32_t length; 
  uint8_t version[8];
  uint8_t type; 
  uint8_t upgrade_type; 
  uint16_t crc;
  uint8_t reserved[4];
}boot_table_t;

typedef struct _mico_sys_config_t
{
   
  char            name[32];

   
  char            ssid[32];
  char            user_key[64]; 
  int             user_keyLength;
  char            key[64]; 
  int             keyLength;
  char            bssid[6];
  int             channel;
  wlan_sec_type_t security;

   
  _Bool            rfPowerSaveEnable;
  _Bool            mcuPowerSaveEnable;

   
  _Bool            dhcpEnable;
  char            localIp[16];
  char            netMask[16];
  char            gateWay[16];
  char            dnsServer[16];

   
  config_state_type_t   configured;
  uint8_t               easyLinkByPass;
  uint32_t              reserved;

   
  uint32_t        magic_number;

   
  int32_t         seed;
} mico_sys_config_t;




typedef struct {

   
  boot_table_t             bootTable;

   
  mico_sys_config_t        micoSystemConfig;

} system_config_t;

typedef struct
{
  system_state_t        current_sys_state;
  mico_semaphore_t      sys_state_change_sem;
   
  char                  localIp[16];
  char                  netMask[16];
  char                  gateWay[16];
  char                  dnsServer[16];
  char                  mac[18];
  char                  rf_version[50];
} system_status_wlan_t;


typedef enum {
  NOTIFY_STATION_UP = 1,
  NOTIFY_STATION_DOWN,

  NOTIFY_AP_UP,
  NOTIFY_AP_DOWN,
} notify_wlan_t; 











 


 
struct cli_command {
	 
	const char *name;
	 
	const char *help;
	 
	void (*function) (char *pcWriteBuffer, int xWriteBufferLen, int argc, char **argv);
};












 
int cli_register_command(const struct cli_command *command);








 
int cli_unregister_command(const struct cli_command *command);








 
int cli_stop(void);









 
int cli_register_commands(const struct cli_command *commands, int num_commands);







 
int cli_unregister_commands(const struct cli_command *commands,
			    int num_commands);










 
int cli_getchar(char *inbuf);






 
int cli_printf(const char *buff, ...);



void wifistate_Command(char *pcWriteBuffer, int xWriteBufferLen, int argc, char * *argv);
void wifidebug_Command(char *pcWriteBuffer, int xWriteBufferLen, int argc, char * *argv);
void wifiscan_Command(char *pcWriteBuffer, int xWriteBufferLen, int argc, char * *argv);
void ifconfig_Command(char *pcWriteBuffer, int xWriteBufferLen, int argc, char * *argv);
void arp_Command(char *pcWriteBuffer, int xWriteBufferLen, int argc, char * *argv);
void ping_Command(char *pcWriteBuffer, int xWriteBufferLen, int argc, char * *argv);
void dns_Command(char *pcWriteBuffer, int xWriteBufferLen, int argc, char * *argv);
void socket_show_Command(char *pcWriteBuffer, int xWriteBufferLen, int argc, char * *argv);
void memory_show_Command(char *pcWriteBuffer, int xWriteBufferLen, int argc, char * *argv);
void memory_dump_Command(char *pcWriteBuffer, int xWriteBufferLen, int argc, char * *argv);
void memory_set_Command(char *pcWriteBuffer, int xWriteBufferLen, int argc, char * *argv);
void memp_dump_Command(char *pcWriteBuffer, int xWriteBufferLen, int argc, char * *argv);
void driver_state_Command(char *pcWriteBuffer, int xWriteBufferLen, int argc, char * *argv);












 












 
















 



extern void mc_set_debug(int debug);
extern int mc_get_debug(void);

extern void mc_set_syslog(int syslog);
extern void mc_abort(const char *msg, ...);
extern void mc_debug(const char *msg, ...);
extern void mc_error(const char *msg, ...);
extern void mc_info(const char *msg, ...);













 
 




 



 



 

struct lh_entry;



 
typedef void (lh_entry_free_fn) (struct lh_entry *e);


 
typedef unsigned long (lh_hash_fn) (const void *k);


 
typedef int (lh_equal_fn) (const void *k1, const void *k2);



 
struct lh_entry {
	

 
	void *k;
	

 
	const void *v;
	

 
	struct lh_entry *next;
	

 
	struct lh_entry *prev;
};




 
struct lh_table {
	

 
	unsigned char size;
	

 
	unsigned char count;

	

 
	struct lh_entry *head;

	

 
	struct lh_entry *tail;

	struct lh_entry *table;

	

 
	lh_entry_free_fn *free_fn;
	lh_hash_fn *hash_fn;
	lh_equal_fn *equal_fn;
};




 
extern unsigned long lh_ptr_hash(const void *k);
extern int lh_ptr_equal(const void *k1, const void *k2);

extern unsigned long lh_char_hash(const void *k);
extern int lh_char_equal(const void *k1, const void *k2);




 



 



















 
extern struct lh_table* lh_table_new(int size, const char *name,
				     lh_entry_free_fn *free_fn,
				     lh_hash_fn *hash_fn,
				     lh_equal_fn *equal_fn);








 
extern struct lh_table* lh_kchar_table_new(int size, const char *name,
					   lh_entry_free_fn *free_fn);









 
extern struct lh_table* lh_kptr_table_new(int size, const char *name,
					  lh_entry_free_fn *free_fn);







 
extern void lh_table_free(struct lh_table *t);







 
extern int lh_table_insert(struct lh_table *t, void *k, const void *v);







 
extern struct lh_entry* lh_table_lookup_entry(struct lh_table *t, const void *k);






 
extern const void* lh_table_lookup(struct lh_table *t, const void *k);










 
extern int lh_table_delete_entry(struct lh_table *t, struct lh_entry *e);










 
extern int lh_table_delete(struct lh_table *t, const void *k);


void lh_abort(const char *msg, ...);
void lh_table_resize(struct lh_table *t, int new_size);












 




typedef void (array_list_free_fn) (void *data);

struct array_list
{
  void **array;
  int length;
  int size;
  array_list_free_fn *free_fn;
};

extern struct array_list*
array_list_new(array_list_free_fn *free_fn);

extern void
array_list_free(struct array_list *al);

extern void*
array_list_get_idx(struct array_list *al, int i);

extern int
array_list_put_idx(struct array_list *al, int i, void *data);

extern int
array_list_add(struct array_list *al, void *data);

extern int
array_list_length(struct array_list *al);













 











 















 




struct printbuf {
  char *buf;
  int bpos;
  int size;
};

extern struct printbuf*
printbuf_new(void);







 
extern int
printbuf_memappend(struct printbuf *p, const char *buf, int size);


extern int
sprintbuf(struct printbuf *p, const char *msg, ...);

extern void
printbuf_reset(struct printbuf *p);

extern void
printbuf_free(struct printbuf *p);









extern const char *json_number_chars;
extern const char *json_hex_chars;




 




 


 
struct json_object_iter
{
	char *key;
	struct json_object *val;
	struct lh_entry *entry;
};

 
typedef int boolean;
typedef struct printbuf printbuf;
typedef struct lh_table lh_table;
typedef struct array_list array_list;
typedef struct json_object json_object;
typedef struct json_object_iter json_object_iter;
typedef struct json_tokener json_tokener;

 

typedef enum json_type {
   
  json_type_null,
  json_type_boolean,
  json_type_double,
  json_type_int,
  json_type_object,
  json_type_array,
  json_type_string,
} json_type;

 





 







 
extern struct json_object* json_object_get(struct json_object *obj);







 
extern void json_object_put(struct json_object *obj);












 
extern int json_object_is_type(struct json_object *obj, enum json_type type);













 
extern enum json_type json_object_get_type(struct json_object *obj);








 
extern const char* json_object_to_json_string(struct json_object *obj);


 





 





 
extern struct json_object* json_object_new_object(void);





 
extern struct lh_table* json_object_get_object(struct json_object *obj);













 
extern void json_object_object_add(struct json_object* obj, const char *key,
				   struct json_object *val);






 
extern struct json_object* json_object_object_get(struct json_object* obj,
						  const char *key);








 
extern void json_object_object_del(struct json_object* obj, const char *key);






 







 

 

 





 




 
extern struct json_object* json_object_new_array(void);





 
extern struct array_list* json_object_get_array(struct json_object *obj);





 
extern int json_object_array_length(struct json_object *obj);










 
extern int json_object_array_add(struct json_object *obj,
				 struct json_object *val);
















 
extern int json_object_array_put_idx(struct json_object *obj, int idx,
				     struct json_object *val);





 
extern struct json_object* json_object_array_get_idx(struct json_object *obj,int idx);
 

 





 						     




 
extern struct json_object* json_object_new_boolean(boolean b);











 
extern boolean json_object_get_boolean(struct json_object *obj);

 

 





 	






 
extern struct json_object* json_object_new_int(int32_t i);





 
extern struct json_object* json_object_new_int64(int64_t i);














 
extern int32_t json_object_get_int(struct json_object *obj);









 
extern int64_t json_object_get_int64(struct json_object *obj);

 

 





 	





 
extern struct json_object* json_object_new_double(double d);









 
extern double json_object_get_double(struct json_object *obj);

 

 





 	







 
extern struct json_object* json_object_new_string(const char *s);

extern struct json_object* json_object_new_string_len(const char *s, int len);











 
extern const char* json_object_get_string(struct json_object *obj);
extern struct printbuf * json_object_to_json_string_ex(struct json_object *jso);









 
extern int json_object_get_string_len(struct json_object *obj);

 

 



 




 







 
extern struct json_object* json_object_from_file(const char *filename);
extern int json_object_to_file(char *filename, struct json_object *obj);
extern int json_parse_int64(const char *buf, int64_t *retval);




 
extern const char *json_type_to_name(enum json_type o_type);












 


 
 






 


enum json_tokener_error {
  json_tokener_success,
  json_tokener_continue,
  json_tokener_error_depth,
  json_tokener_error_parse_eof,
  json_tokener_error_parse_unexpected,
  json_tokener_error_parse_null,
  json_tokener_error_parse_boolean,
  json_tokener_error_parse_number,
  json_tokener_error_parse_array,
  json_tokener_error_parse_object_key_name,
  json_tokener_error_parse_object_key_sep,
  json_tokener_error_parse_object_value_sep,
  json_tokener_error_parse_string,
  json_tokener_error_parse_comment
};

enum json_tokener_state {
  json_tokener_state_eatws,
  json_tokener_state_start,
  json_tokener_state_finish,
  json_tokener_state_null,
  json_tokener_state_comment_start,
  json_tokener_state_comment,
  json_tokener_state_comment_eol,
  json_tokener_state_comment_end,
  json_tokener_state_string,
  json_tokener_state_string_escape,
  json_tokener_state_escape_unicode,
  json_tokener_state_boolean,
  json_tokener_state_number,
  json_tokener_state_array,
  json_tokener_state_array_add,
  json_tokener_state_array_sep,
  json_tokener_state_object_field_start,
  json_tokener_state_object_field,
  json_tokener_state_object_field_end,
  json_tokener_state_object_value,
  json_tokener_state_object_value_add,
  json_tokener_state_object_sep
};

struct json_tokener_srec
{
  enum json_tokener_state state, saved_state;
  struct json_object *obj;
  struct json_object *current;
  char *obj_field_name;
};


struct json_tokener
{
  char *str;
  struct printbuf *pb;
  int depth, is_double, st_pos, char_offset;
  enum json_tokener_error err;
  unsigned int ucs_char;
  char quote_char;
  struct json_tokener_srec stack[32];
};

extern const char* json_tokener_errors[];

extern struct json_tokener* json_tokener_new(void);
extern void json_tokener_free(struct json_tokener *tok);
extern void json_tokener_reset(struct json_tokener *tok);
extern struct json_object* json_tokener_parse(const char *str);
extern struct json_object* json_tokener_parse_verbose(const char *str, enum json_tokener_error *error);
extern struct json_object* json_tokener_parse_ex(struct json_tokener *tok,
						 const char *str, int len);









typedef system_state_t          mico_system_state_t;
typedef system_config_t         mico_Context_t;
typedef system_status_wlan_t    mico_system_status_wlan_t;




 



 




 







 
void mico_sdk_version( uint8_t *major, uint8_t *minor, uint8_t *revision );






 
void mico_app_info(char *p_info, int len_info);

 





 

 
typedef enum
{
    PARA_BOOT_TABLE_SECTION,
    PARA_MICO_DATA_SECTION,
    PARA_SYS_END_SECTION,
    PARA_APP_DATA_SECTION,
    PARA_END_SECTION
} para_section_t;







 
void* mico_system_context_init( uint32_t size_of_user_data );





 
mico_Context_t* mico_system_context_get( void );





 
void* mico_system_context_get_user_data( mico_Context_t* const in_context );







 
OSStatus mico_system_context_restore( mico_Context_t* const in_context );








 
void appRestoreDefault_callback(void * const user_config_data, uint32_t size);





 
OSStatus mico_system_context_update( mico_Context_t* const in_context );

OSStatus mico_system_para_read(void** info_ptr, int section, uint32_t offset, uint32_t size);
OSStatus mico_system_para_write(const void* info_ptr, int section, uint32_t offset, uint32_t size);
OSStatus mico_system_para_read_release( void* info_ptr );

 




 






 
OSStatus mico_ota_switch_to_new_fw(int ota_data_len, uint16_t ota_data_crc);

 




 

  
typedef enum{
  CONFIG_BY_NONE,              
  CONFIG_BY_EASYLINK_V2,       
  CONFIG_BY_EASYLINK_PLUS,         
  CONFIG_BY_EASYLINK_MINUS,           
  CONFIG_BY_AIRKISS,              
  CONFIG_BY_SOFT_AP,           
  CONFIG_BY_WAC,               
  CONFIG_BY_USER,              
} mico_config_source_t;





 
OSStatus mico_system_init( mico_Context_t* const in_context );





 
OSStatus mico_system_wlan_get_status( mico_system_status_wlan_t** status );





 
OSStatus mico_system_wlan_start_autoconf( void );





 
void mico_system_delegate_config_will_start( void );





 
void mico_system_delegate_config_will_stop( void );





 
void mico_system_delegate_soft_ap_will_start( void );








 
void mico_system_delegate_config_recv_ssid ( char *ssid, char *key );







 
OSStatus mico_system_delegate_config_recv_auth_data( char * userInfo );







 
void mico_system_delegate_config_success( mico_config_source_t source );

 








 




 
typedef struct _mico_system_monitor_t
{
    uint32_t last_update;               
    uint32_t longest_permitted_delay;   
} mico_system_monitor_t;






 
OSStatus mico_system_monitor_daemen_start( void );






 
OSStatus mico_system_monitor_register( mico_system_monitor_t* system_monitor, uint32_t initial_permitted_delay );






 
OSStatus mico_system_monitor_update ( mico_system_monitor_t* system_monitor, uint32_t permitted_delay );




 





 







 
OSStatus mico_system_power_perform( mico_Context_t* const in_context, mico_system_state_t new_state );
 

 




 
 

typedef notify_wlan_t WiFiEvent;

  
typedef enum{

  mico_notify_WIFI_SCAN_COMPLETED,           
  mico_notify_WIFI_STATUS_CHANGED,         
  mico_notify_WiFI_PARA_CHANGED,           
  mico_notify_DHCP_COMPLETED,              
  mico_notify_EASYLINK_WPS_COMPLETED,      
  mico_notify_EASYLINK_GET_EXTRA_DATA,     
  mico_notify_TCP_CLIENT_CONNECTED,        
  mico_notify_DNS_RESOLVE_COMPLETED,       
  mico_notify_SYS_WILL_POWER_OFF,          
  mico_notify_WIFI_CONNECT_FAILED,         
  mico_notify_WIFI_SCAN_ADV_COMPLETED,     
  mico_notify_WIFI_Fatal_ERROR,            
  mico_notify_Stack_Overflow_ERROR,        
 
} mico_notify_types_t;







 
OSStatus mico_system_notify_register( mico_notify_types_t notify_type, void* functionAddress, void* arg );






 
OSStatus mico_system_notify_remove( mico_notify_types_t notify_type, void *functionAddress );





 
OSStatus mico_system_notify_remove_all( mico_notify_types_t notify_type);


 





 








 
OSStatus config_server_start ( void );




 
OSStatus config_server_stop ( void );










 
void config_server_delegate_recv( const char *key, json_object *value, _Bool *need_reboot, mico_Context_t *in_context );









 
void config_server_delegate_report( json_object *config_cell_list, mico_Context_t *in_context );










 
OSStatus config_server_create_string_cell   (json_object* config_cell_list, char* const name, char* const content, char* const privilege, json_object* secectionArray);










 
OSStatus config_server_create_number_cell   (json_object* config_cell_list, char* const name, int content, char* const privilege, json_object* secectionArray);










 
OSStatus config_server_create_float_cell    (json_object* config_cell_list, char* const name, float content, char* const privilege, json_object* secectionArray);










 
OSStatus config_server_create_bool_cell     (json_object* config_cell_list, char* const name, boolean content, char* const privilege);







 
OSStatus config_server_create_sub_menu_cell (json_object* config_cell_list, char* const name, json_object* sub_menu_array);







 
OSStatus config_server_create_sector        (json_object* sub_menu_array, char* const name, json_object *config_cell_list);

 






 






 
int cli_init(void);

 







 



 

enum mdns_record_state_e{
    RECORD_REMOVED,      
    RECORD_UPDATE,       
    RECORD_REMOVE,      
 
    RECORD_SUSPEND,     
 
    RECORD_NORMAL,       
};
typedef uint8_t mdns_record_state_t;

typedef struct _mdns_init_t
{
  char *service_name;      
  char *host_name;         
  char *instance_name;     
  char *txt_record;       
 
  uint16_t service_port;   
} mdns_init_t;







 
OSStatus mdns_add_record( mdns_init_t record, wlanInterfaceTypedef interface, uint32_t time_to_live );







 
void mdns_suspend_record( char *service_name, wlanInterfaceTypedef interface, _Bool will_remove );






 
void mdns_resume_record( char *service_name, wlanInterfaceTypedef interface );








 
void mdns_update_txt_record( char *service_name, wlanInterfaceTypedef interface, char *txt_record );






 
mdns_record_state_t mdns_get_record_status( char *service_name, wlanInterfaceTypedef interface);

 




 




 
#pragma pack(1)

typedef struct
{
    char year[4];         
    char dash1;           
    char month[2];        
    char dash2;           
    char day[2];          
    char T;               
    char hour[2];         
    char colon1;          
    char minute[2];       
    char colon2;          
    char second[2];       
    char decimal;         
    char sub_second[6];   
    char Z;               
} iso8601_time_t;

#pragma pack()








 
OSStatus mico_time_get_time( mico_time_t* time );







 
OSStatus mico_time_set_time( const mico_time_t* time );









 
OSStatus mico_time_get_utc_time( mico_utc_time_t* utc_time );









 
OSStatus mico_time_get_utc_time_ms( mico_utc_time_ms_t* utc_time_ms );







 
OSStatus mico_time_set_utc_time_ms( const mico_utc_time_ms_t* utc_time_ms );










 
OSStatus mico_time_get_iso8601_time( iso8601_time_t* iso8601_time );









 
OSStatus mico_time_convert_utc_ms_to_iso8601( mico_utc_time_ms_t utc_time_ms, iso8601_time_t* iso8601_time );







 
void mico_nanosecond_delay( uint64_t delayus );




 
uint64_t mico_nanosecond_clock_value( void );




 
void mico_nanosecond_reset( void );




 
void mico_nanosecond_init( void );

 






 




 
void tftp_ota(void);

 

 

 































 

#pragma once





 



 
  

   


 






















































































































































 

typedef enum
{
    MICO_SYS_LED, 
    MICO_RF_LED, 
    BOOT_SEL, 
    MFG_SEL, 
    EasyLink_BUTTON, 
    STDIO_UART_RX,  
    STDIO_UART_TX,  
    FLASH_PIN_SPI_CS,
    FLASH_PIN_SPI_CLK,
    FLASH_PIN_SPI_MOSI,
    FLASH_PIN_SPI_MISO,
    
    MICO_GPIO_2,
    MICO_GPIO_8,
    MICO_GPIO_9,
    MICO_GPIO_12,
    MICO_GPIO_14,
    MICO_GPIO_16,
    MICO_GPIO_17,
    MICO_GPIO_18,
    MICO_GPIO_19,
    MICO_GPIO_27,  
    MICO_GPIO_29,
    MICO_GPIO_30,
    MICO_GPIO_31,
    MICO_GPIO_33,
    MICO_GPIO_34,
    MICO_GPIO_35,
    MICO_GPIO_36,
    MICO_GPIO_37,
    MICO_GPIO_38,
    MICO_GPIO_MAX,  
    MICO_GPIO_NONE,
} mico_gpio_t;

typedef enum
{
  MICO_SPI_1,
  MICO_SPI_MAX,  
  MICO_SPI_NONE,
} mico_spi_t;

typedef enum
{
    MICO_I2C_1,
    MICO_I2C_MAX,  
    MICO_I2C_NONE,
} mico_i2c_t;

typedef enum
{
    MICO_PWM_MAX,  
    MICO_PWM_NONE,
} mico_pwm_t;

typedef enum
{
    MICO_ADC_1,
    MICO_ADC_2,
    MICO_ADC_MAX,  
    MICO_ADC_NONE,
} mico_adc_t;

typedef enum
{
    MICO_UART_1,
    MICO_UART_2,
    MICO_UART_MAX,  
    MICO_UART_NONE,
} mico_uart_t;

typedef enum
{
  MICO_FLASH_EMBEDDED,
  MICO_FLASH_SPI,
  MICO_FLASH_MAX,
  MICO_FLASH_NONE,
} mico_flash_t;

typedef enum
{
  MICO_PARTITION_FILESYS,
  MICO_PARTITION_USER_MAX
} mico_user_partition_t;



 



 




















 




















 
typedef struct
{
    uint8_t macAddress[ 6 ];         
    
    _Bool    isUnconfigured;          
    _Bool    supportsAirPlay;         
    _Bool    supportsAirPrint;        
    _Bool    supports2_4GHzWiFi;      
    _Bool    supports5GHzWiFi;        
    _Bool    supportsWakeOnWireless;  
    
    char    *firmwareRevision;       
    char    *hardwareRevision;       
    char    *serialNumber;           
    
    char    *name;                   
    char    *model;                  
    char    *manufacturer;           
    
    char    **eaProtocols;           
    uint8_t numEAProtocols;          
    char    *eaBundleSeedID;         
    
} WACPlatformParameters_t;

OSStatus mfi_wac_start( mico_Context_t * const inContext, WACPlatformParameters_t *inWACPara, mico_i2c_t i2c, int timeOut );

OSStatus mfi_wac_start_with_debug( mico_Context_t * const inContext, WACPlatformParameters_t *inWACPara, mico_i2c_t i2c, int timeOut );

OSStatus mfi_wac_stop( void );






















































 





 




 


















































































 






































 


#pragma once



 





 



   



 



 



 





 











 
OSStatus MicoMFiAuthInitialize( mico_i2c_t i2c );











 
void MicoMFiAuthFinalize( void );















 
OSStatus MicoMFiAuthCreateSignature( const  void      *inDigestPtr,
                                            unsigned int     inDigestLen,
                                            uint8_t  **outSignaturePtr,
                                            unsigned int    *outSignatureLen );













 
OSStatus MicoMFiAuthCopyCertificate( uint8_t **outCertificatePtr, unsigned int *outCertificateLen );

 
 































 


#pragma once





 




 



   




 




 

 

 
 










 
OSStatus MicoRandomNumberRead( void *inBuffer, int inByteCount );

 
 

































 


#include <stdarg.h>




 




 





 




 


void formatMACAddr(char *destAddr, char *srcAddr);











 
unsigned int str2hex(unsigned char *ibuf, unsigned char *obuf, unsigned int olen);








 
void Int2Str(uint8_t* str, int32_t intnum);










 
uint32_t Str2Int(uint8_t *inputstr, int32_t *intnum);








 
char *__strdup(const char *src);









 
char *__strdup_trans_dot(char *src);













 
int TextToHardwareAddress( const void *inText, unsigned int inTextSize, unsigned int inAddrSize, void *outAddr );

unsigned int str2hex(unsigned char *ibuf, unsigned char *obuf, unsigned int olen);











 
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




 



 









 
WACPlatformParameters_t* WAC_Params = 0;


const uint8_t WAC_OUI_default[3] = {0x00, 0xB7, 0x43};
const uint8_t WAC_dWDS_default[2] = {0x00, 0x00};
const uint8_t WAC_BlueTooth_MAC_default[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };



 
typedef enum
{
    WICED_STA_INTERFACE     = 0,  
    WICED_AP_INTERFACE      = 1,  
    WICED_CONFIG_INTERFACE  = 3,  
} wiced_interface_t;



 
typedef enum
{
    WICED_ADD_CUSTOM_IE,      
    WICED_REMOVE_CUSTOM_IE    
} wiced_custom_ie_action_t;



 
typedef enum
{
    VENDOR_IE_BEACON         = 0x1,   
    VENDOR_IE_PROBE_RESPONSE = 0x2,   
    VENDOR_IE_ASSOC_RESPONSE = 0x4,   
    VENDOR_IE_AUTH_RESPONSE  = 0x8,   
    VENDOR_IE_PROBE_REQUEST  = 0x10,  
    VENDOR_IE_ASSOC_REQUEST  = 0x20,  
    VENDOR_IE_CUSTOM         = 0x100  
} wiced_ie_packet_flag_t;



 
typedef enum
{
    Element_ID_Flags            = 0x0,  
    Element_ID_Name             = 0x1,  
    Element_ID_Manufacturer     = 0x2,  
    Element_ID_Model            = 0x3,  
    Element_ID_OUI              = 0x4, 
    Element_ID_dWDS             = 0x5, 
    Element_ID_Bluetooth_MAC    = 0x6,
    Element_ID_Device_ID        = 0x7
} Element_ID_t;



 
static const uint8_t oui[3] = {0x00, 0xA0, 0x40};
static const uint8_t sub_type = 0x0;

static mico_timer_t _wac_timeout_timer;

static void _wac_bonjour_init(wlanInterfaceTypedef interface, mico_Context_t * const inContext);

uint16_t _port;
uint8_t App_Available = 0;












 
extern OSStatus wiced_wifi_manage_custom_ie( wiced_interface_t interface, wiced_custom_ie_action_t action,   uint8_t* oui, uint8_t subtype, void* data, uint16_t length, uint16_t which_packets );

 
static void _mfi_wac_timeout_handler( void* arg )
{
  ( (void)(arg) );
  mfi_wac_stop( );
}

static void WACNotify_WifiStatusHandler(WiFiEvent event, mico_Context_t * const inContext)
{
  ;
  (void)inContext;
  switch (event) {
  case NOTIFY_AP_DOWN:
     
    mdns_suspend_record( "_mfi-config._tcp.local.", Soft_AP, 1 );
    break;
  default:
    break;
  }
  return;
}

static mico_i2c_t _i2c = MICO_I2C_NONE;

mico_i2c_t _mfi_wac_i2c( void )
{
  return _i2c;
}

OSStatus mfi_wac_start( mico_Context_t * const inContext, WACPlatformParameters_t *inWACPara, mico_i2c_t i2c, int timeOut )
{
  int i;
  uint8_t flag1=0, flag2=0;
  uint8_t *Elements = 0;
  uint8_t *ptemp = 0;
  uint16_t ElementsLength = 0;
  network_InitTypeDef_st WAC_NetConfig;
  IPStatusTypedef para;
  uint16_t random;
  OSStatus err = 0;
  uint16_t ie_len;
  uint8_t *ie = 0;
  _i2c = i2c;
  
  err =  MicoMFiAuthInitialize( i2c );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

  WAC_Params = calloc(1, sizeof(WACPlatformParameters_t));
  do { if( ! !(!(WAC_Params)) ) { ; goto exit; } } while( 1==0 );

  err = mico_system_notify_register( mico_notify_WIFI_STATUS_CHANGED, (void *)WACNotify_WifiStatusHandler, inContext );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

  memcpy(WAC_Params, inWACPara, sizeof(WACPlatformParameters_t));

  flag1 = WAC_Params->supportsAirPlay<<(7)|
          WAC_Params->isUnconfigured<<(6)|
          1<<(5)|
          WAC_Params->supportsWakeOnWireless<<(4)|
          0<<(3)|
          0<<(2)|
          1<<(1)|
          0<<(0);

  flag2 = WAC_Params->supportsAirPrint<<(3)|
          0<<(2)|
          WAC_Params->supports2_4GHzWiFi<<(1)|
          WAC_Params->supports5GHzWiFi<<(0);

  ElementsLength = 34+strlen(WAC_Params->name)+strlen(WAC_Params->manufacturer)+strlen(WAC_Params->model);

  if(flag2 != 0)
    ElementsLength ++;

  if((Elements = malloc(ElementsLength))==0)
    return -1;

  ptemp = Elements;

  for(i=0; i<8; i++){
    *ptemp = i;

    switch(i){
      case Element_ID_Flags:
        if(flag2 != 0)
          *(++ptemp) = 2;
        else
          *(++ptemp) = 1;

        *(++ptemp) = flag1;
        
        if(flag2 != 0)
          *(++ptemp) = flag2;

        ptemp++;
        break;
      case Element_ID_Name:
        *(++ptemp) = strlen(WAC_Params->name);
        memcpy(++ptemp, WAC_Params->name, strlen(WAC_Params->name));
        ptemp += strlen(WAC_Params->name);
        break;
      case Element_ID_Manufacturer:
        *(++ptemp) = strlen(WAC_Params->manufacturer);
        memcpy(++ptemp, WAC_Params->manufacturer, strlen(WAC_Params->manufacturer));
        ptemp += strlen(WAC_Params->manufacturer);
        break;
      case Element_ID_Model:
        *(++ptemp) = strlen(WAC_Params->model);
        memcpy(++ptemp, WAC_Params->model, strlen(WAC_Params->model));
        ptemp += strlen(WAC_Params->model);
        break;
      case Element_ID_OUI:
        *(++ptemp) = 3;
        memcpy(++ptemp, oui, 3);
        ptemp += 3;
        break;
      case Element_ID_dWDS:
        *(++ptemp) = 2;
        memcpy(++ptemp, WAC_dWDS_default, 2);
        ptemp += 2;
        break;
      case Element_ID_Bluetooth_MAC:
        *(++ptemp) = 6;
        memcpy(++ptemp, WAC_BlueTooth_MAC_default, 6);
        ptemp += 6;
        break;
      case Element_ID_Device_ID:
        *(++ptemp) = 6;
        getNetPara(&para, Soft_AP);
        str2hex((unsigned char *)para.mac, ++ptemp, 6);
        ptemp += 6;
        break;
    }
  }

  mico_system_delegate_config_will_start( ); 
  mico_system_delegate_soft_ap_will_start( );

  mico_init_timer( &_wac_timeout_timer, timeOut * 1000, _mfi_wac_timeout_handler, (void*)inContext );
  mico_start_timer( &_wac_timeout_timer );

  memset( &WAC_NetConfig, 0, sizeof(struct _network_InitTypeDef_st) );
  WAC_NetConfig.wifi_mode = Soft_AP;
  sprintf( WAC_NetConfig.wifi_ssid, "%s_%s", inContext->micoSystemConfig.name, &para.mac[6] );
  strcpy( (char*)WAC_NetConfig.wifi_key, "" );
  strcpy( (char*)WAC_NetConfig.local_ip_addr, "10.10.10.1" );
  strcpy( (char*)WAC_NetConfig.net_mask, "255.255.255.0" );
  strcpy( (char*)WAC_NetConfig.gateway_ip_addr, "10.10.10.1" );
  WAC_NetConfig.dhcpMode = (2);
  StartNetwork( &WAC_NetConfig );
  
  ie_len = 3 + 1 + ElementsLength;
  ie = malloc(ie_len);
  do { if( ! !(!(ie != 0)) ) { ; { err = -1; } goto exit; } } while( 1==0 );
  memcpy(ie, oui, 3);
  memcpy(&ie[3], &sub_type, 1);
  memcpy(&ie[4], Elements, ElementsLength);
  err = mico_wlan_custom_ie_add(Soft_AP, ie, ie_len);
  free(ie);
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

  App_Available = (inWACPara->numEAProtocols)? 1:0;
  
  
  MicoRandomNumberRead( &random, 2 );
  _port = 49000 + random%2000;

  _wac_bonjour_init( Soft_AP, inContext );

  err = mfi_wac_http_server_start( inContext );

exit:  
  if(Elements) free(Elements);
    return err;
}

OSStatus mfi_wac_stop( void )
{  
  uap_stop( );
  mico_system_delegate_config_will_stop( );

  mico_stop_timer( &_wac_timeout_timer );
  mico_deinit_timer( &_wac_timeout_timer );

  mico_system_notify_remove( mico_notify_WIFI_STATUS_CHANGED, (void *)WACNotify_WifiStatusHandler );

  if( WAC_Params ) free( WAC_Params );
  
  mdns_suspend_record( "_mfi-config._tcp.local.", Station, 1 );
  mdns_suspend_record( "_mfi-config._tcp.local.", Soft_AP, 1 );

  return mfi_wac_http_server_stop( );
}

void mfi_wac_lib_version( uint8_t *major, uint8_t *minor, uint8_t *revision )
{
  if( major ) *major = (1);
  if( minor ) *minor = (4);
  if( revision ) *revision = (0);
}

OSStatus applyNewConfiguration(char* destinationSSID, char *destinationPSK, char *accessoryName, char *playPassword, mico_Context_t * const inContext)
{
  ;
  ( (void)(playPassword) ); 
  OSStatus err = 0;
  network_InitTypeDef_adv_st WAC_NetConfig;

  do { if( ! !(!(destinationSSID)) ) { ; { err = -6705; } goto exit; } } while( 1==0 );

  ;

  memset(&WAC_NetConfig, 0, sizeof(network_InitTypeDef_adv_st));
  strncpy((char*)WAC_NetConfig.ap_info.ssid, destinationSSID, 32);
  WAC_NetConfig.ap_info.security = SECURITY_TYPE_AUTO;
  memcpy(WAC_NetConfig.key, destinationPSK, 64);
  WAC_NetConfig.key_len = strlen(destinationPSK);
  WAC_NetConfig.dhcpMode = (1);
  WAC_NetConfig.wifi_retry_interval = 100;

  memcpy(inContext->micoSystemConfig.name, accessoryName, 32);
  inContext->micoSystemConfig.name[32-1] = 0x0;
  inContext->micoSystemConfig.dhcpEnable = 1;
  inContext->micoSystemConfig.seed ++;
    
  uap_stop();
  mico_rtos_thread_msleep(1000);

  StartAdvNetwork(&WAC_NetConfig);
  
  _wac_bonjour_init( Station, inContext );
exit:
  return err;  
}

static void _wac_bonjour_init(wlanInterfaceTypedef interface, mico_Context_t * const inContext)
{
  char temp_txt[100];
  mdns_init_t init;
  char *temp_txt2;
  IPStatusTypedef para;
  char  mac[18];

  memset(&init, 0x0, sizeof(mdns_init_t));

  init.service_name = "_mfi-config._tcp.local.";
  init.host_name = "MXCHIP_MFi.local.";
  init.instance_name = (char*)__strdup(inContext->micoSystemConfig.name);
  init.service_port = _port;

  ;
  
  getNetPara(&para, interface);
  formatMACAddr(mac, (char *)&para.mac);

  temp_txt2 = __strdup_trans_dot(mac);
  sprintf(temp_txt, "deviceid=%s.", temp_txt2);
  free(temp_txt2);

  sprintf(temp_txt, "%sfeatures=%x.", temp_txt, (1<<(2)) + 0);

  sprintf(temp_txt, "%sseed=%ld.", temp_txt, inContext->micoSystemConfig.seed);

  temp_txt2 = __strdup_trans_dot("1.0");
  sprintf(temp_txt, "%ssrcvers=%s.", temp_txt, temp_txt2);
  free(temp_txt2);

  init.txt_record = temp_txt;
  mdns_add_record(init, interface, 1500);
}




