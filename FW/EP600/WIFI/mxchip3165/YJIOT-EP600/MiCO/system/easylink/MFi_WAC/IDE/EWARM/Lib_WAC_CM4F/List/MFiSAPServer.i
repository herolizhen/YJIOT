

















































 



















































 





 
































 



 
 

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







 


 







 

typedef struct MFiSAP *     MFiSAPRef;

OSStatus    MFiSAP_Create( MFiSAPRef *outRef, uint8_t inVersion );
void        MFiSAP_Delete( MFiSAPRef inRef );








 
OSStatus
    MFiSAP_Exchange( 
        MFiSAPRef       inRef, 
        const uint8_t * inInputPtr,
        unsigned int          inInputLen, 
        uint8_t **      outOutputPtr,
        unsigned int *        outOutputLen, 
        Boolean *       outDone );
OSStatus    MFiSAP_Encrypt( MFiSAPRef inRef, const void *inPlaintext,  unsigned int inLen, void *inCiphertextBuf );
OSStatus    MFiSAP_Decrypt( MFiSAPRef inRef, const void *inCiphertext, unsigned int inLen, void *inPlaintextBuf );




 
OSStatus
    MFiSAP_DeriveAESKey(
        MFiSAPRef       inRef, 
        const void *    inKeySaltPtr, 
        unsigned int          inKeySaltLen, 
        const void *    inIVSaltPtr, 
        unsigned int          inIVSaltLen, 
        uint8_t         outKey[ 16 ], 
        uint8_t         outIV[ 16 ] );


































 

































 













 




 









 
int memcmp_constant_time( const void *inA, const void *inB, unsigned int inLen );


 



 





































 

#pragma once



















































 



void curve25519_donna( unsigned char *outKey, const unsigned char *inSecret, const unsigned char *inBasePoint );




 
 



































 






























 

 
 





 










 



 
enum {
    shaSuccess = 0,
    shaNull,             
    shaInputTooLong,     
    shaStateError,       
    shaBadParam          
};




 
enum {
    SHA1_Message_Block_Size = 64, SHA224_Message_Block_Size = 64,
    SHA256_Message_Block_Size = 64, SHA384_Message_Block_Size = 128,
    SHA512_Message_Block_Size = 128,
    USHA_Max_Message_Block_Size = SHA512_Message_Block_Size,

    SHA1HashSize = 20, SHA224HashSize = 28, SHA256HashSize = 32,
    SHA384HashSize = 48, SHA512HashSize = 64,
    USHAMaxHashSize = SHA512HashSize,

    SHA1HashSizeBits = 160, SHA224HashSizeBits = 224,
    SHA256HashSizeBits = 256, SHA384HashSizeBits = 384,
    SHA512HashSizeBits = 512, USHAMaxHashSizeBits = SHA512HashSizeBits
};



 
typedef enum SHAversion {
    SHA1, SHA224, SHA256, SHA384, SHA512
} SHAversion;




 
typedef struct SHA1Context {
    uint32_t Intermediate_Hash[SHA1HashSize/4];  

    uint32_t Length_High;                
    uint32_t Length_Low;                 

    int_least16_t Message_Block_Index;   
                                         
    uint8_t Message_Block[SHA1_Message_Block_Size];

    int Computed;                    
    int Corrupted;                   
} SHA1Context;




 
typedef struct SHA256Context {
    uint32_t Intermediate_Hash[SHA256HashSize/4];  

    uint32_t Length_High;                
    uint32_t Length_Low;                 

    int_least16_t Message_Block_Index;   
                                         
    uint8_t Message_Block[SHA256_Message_Block_Size];

    int Computed;                    
    int Corrupted;                   
} SHA256Context;




 
typedef struct SHA512Context {
    uint64_t Intermediate_Hash[SHA512HashSize/8];  
    uint64_t Length_High, Length_Low;    

    int_least16_t Message_Block_Index;   
                                         
    uint8_t Message_Block[SHA512_Message_Block_Size];

    int Computed;                    
    int Corrupted;                   
} SHA512Context;




 
typedef struct SHA256Context SHA224Context;




 
typedef struct SHA512Context SHA384Context;




 
typedef struct USHAContext {
    SHAversion whichSha;                
    union {
      SHA1Context sha1Context;
      SHA224Context sha224Context; SHA256Context sha256Context;
      SHA384Context sha384Context; SHA512Context sha512Context;
    } ctx;

} USHAContext;




 
typedef struct HMACContext {
    SHAversion whichSha;         
    int hashSize;                
    int blockSize;               
    USHAContext shaContext;      
    unsigned char k_opad[USHA_Max_Message_Block_Size];
                         
    int Computed;                
    int Corrupted;               

} HMACContext;




 
typedef struct HKDFContext {
    SHAversion whichSha;          
    HMACContext hmacContext;
    int hashSize;                
    unsigned char prk[USHAMaxHashSize];
                         
    int Computed;                
    int Corrupted;               
} HKDFContext;



 

 
extern int SHA1Reset(SHA1Context *);
extern int SHA1Input(SHA1Context *, const uint8_t *bytes,
                     unsigned int bytecount);
extern int SHA1FinalBits(SHA1Context *, uint8_t bits,
                         unsigned int bit_count);
extern int SHA1Result(SHA1Context *,
                      uint8_t Message_Digest[SHA1HashSize]);
unsigned char * SHA1Direct(const uint8_t *message_array, unsigned length,
                           uint8_t Message_Digest[SHA1HashSize]);

 
extern int SHA224Reset(SHA224Context *);
extern int SHA224Input(SHA224Context *, const uint8_t *bytes,
                       unsigned int bytecount);
extern int SHA224FinalBits(SHA224Context *, uint8_t bits,
                           unsigned int bit_count);
extern int SHA224Result(SHA224Context *,
                        uint8_t Message_Digest[SHA224HashSize]);

 
extern int SHA256Reset(SHA256Context *);
extern int SHA256Input(SHA256Context *, const uint8_t *bytes,
                       unsigned int bytecount);
extern int SHA256FinalBits(SHA256Context *, uint8_t bits,
                           unsigned int bit_count);
extern int SHA256Result(SHA256Context *,
                        uint8_t Message_Digest[SHA256HashSize]);

 
extern int SHA384Reset(SHA384Context *);
extern int SHA384Input(SHA384Context *, const uint8_t *bytes,
                       unsigned int bytecount);
extern int SHA384FinalBits(SHA384Context *, uint8_t bits,
                           unsigned int bit_count);
extern int SHA384Result(SHA384Context *,
                        uint8_t Message_Digest[SHA384HashSize]);

 
extern int SHA512Reset(SHA512Context *);
extern int SHA512Input(SHA512Context *, const uint8_t *bytes,
                       unsigned int bytecount);
extern int SHA512FinalBits(SHA512Context *, uint8_t bits,
                           unsigned int bit_count);
extern int SHA512Result(SHA512Context *,
                        uint8_t Message_Digest[SHA512HashSize]);
unsigned char * SHA512Direct(const uint8_t *message_array, unsigned length,
                             uint8_t Message_Digest[SHA512HashSize]);

 
extern int USHAReset(USHAContext *context, SHAversion whichSha);
extern int USHAInput(USHAContext *context,
                     const uint8_t *bytes, unsigned int bytecount);
extern int USHAFinalBits(USHAContext *context,
                         uint8_t bits, unsigned int bit_count);
extern int USHAResult(USHAContext *context,
                      uint8_t Message_Digest[USHAMaxHashSize]);
extern int USHABlockSize(enum SHAversion whichSha);
extern int USHAHashSize(enum SHAversion whichSha);
extern int USHAHashSizeBits(enum SHAversion whichSha);
extern const char *USHAHashName(enum SHAversion whichSha);





 
extern int hmac(SHAversion whichSha,  
    const unsigned char *text,      
    int text_len,                   
    const unsigned char *key,       
    int key_len,                    
    uint8_t digest[USHAMaxHashSize]);  





 
extern int hmacReset(HMACContext *context, enum SHAversion whichSha,
                     const unsigned char *key, int key_len);
extern int hmacInput(HMACContext *context, const unsigned char *text,
                     int text_len);
extern int hmacFinalBits(HMACContext *context, uint8_t bits,
                         unsigned int bit_count);
extern int hmacResult(HMACContext *context,
                      uint8_t digest[USHAMaxHashSize]);




 
extern int hkdf(SHAversion whichSha, const unsigned char *salt,
                int salt_len, const unsigned char *ikm, int ikm_len,
                const unsigned char *info, int info_len,
                uint8_t okm[ ], int okm_len);
extern int hkdfExtract(SHAversion whichSha, const unsigned char *salt,
                       int salt_len, const unsigned char *ikm,
                       int ikm_len, uint8_t prk[USHAMaxHashSize]);
extern int hkdfExpand(SHAversion whichSha, const uint8_t prk[ ],
                      int prk_len, const unsigned char *info,
                      int info_len, uint8_t okm[ ], int okm_len);





 
extern int hkdfReset(HKDFContext *context, enum SHAversion whichSha,
                     const unsigned char *salt, int salt_len);
extern int hkdfInput(HKDFContext *context, const unsigned char *ikm,
                     int ikm_len);
extern int hkdfFinalBits(HKDFContext *context, uint8_t ikm_bits,
                         unsigned int ikm_bit_count);
extern int hkdfResult(HKDFContext *context,
                      uint8_t prk[USHAMaxHashSize],
                      const unsigned char *info, int info_len,
                      uint8_t okm[USHAMaxHashSize], int okm_len);

 
 





 





























 








 



 




 





 

typedef struct
{
  uint8_t crc;
} CRC8_Context;







 
void CRC8_Init( CRC8_Context *inContext );










 
void CRC8_Update( CRC8_Context *inContext, const void *inSrc, unsigned int inLen );









 
void CRC8_Final( CRC8_Context *inContext, uint8_t *outResult );


 








 




 








 


typedef struct
{
  uint16_t crc;
} CRC16_Context;







 
void CRC16_Init( CRC16_Context *inContext );










 
void CRC16_Update( CRC16_Context *inContext, const void *inSrc, unsigned int inLen );









 
void CRC16_Final( CRC16_Context*inContext, uint16_t *outResult );



 



 






 



 




 

typedef unsigned char         byte;
typedef unsigned short      word16;
typedef unsigned int        word32;
typedef unsigned long long  word64;



 
enum {
  MD5             =  0,       
  MD5_BLOCK_SIZE  = 64,
  MD5_DIGEST_SIZE = 16,
  MD5_PAD_SIZE    = 56
};



 
typedef struct {
  uint32_t state[4];         
  uint32_t count[2];         
  uint32_t buffer[64];       
} md5_context;






 
void InitMd5(md5_context *ctx);








 
void Md5Update(md5_context *ctx, unsigned char *input, int ilen);







 
void Md5Final(md5_context *ctx, unsigned char output[16]);



 





 



 
enum{
  HMAC_BLOCK_SIZE = 64,
  INNER_HASH_SIZE = 128, 
};



 
typedef union {
  md5_context md5;
} Hash;



 
typedef struct Hmac {
  Hash    hash;
  word32  ipad[HMAC_BLOCK_SIZE  / sizeof(word32)];   
  word32  opad[HMAC_BLOCK_SIZE  / sizeof(word32)];
  word32  innerHash[INNER_HASH_SIZE / sizeof(word32)];  
  byte    macType;                                      
  byte    innerHashKeyed;                               
} Hmac;









 
void HmacSetKey(Hmac* hmac, int type, const byte* key, word32 keySz);
  

  







 
void HmacUpdate(Hmac* hmac, const byte* input, word32 inLen);
  







    
void HmacFinal(Hmac* hmac, byte* output);



 





 




 
enum {
  DES_ENC_TYPE    = 2,      
  DES3_ENC_TYPE   = 3,      
  DES_BLOCK_SIZE  = 8,
  DES_KS_SIZE     = 32,
  DES_ENCRYPTION  = 0,
  DES_DECRYPTION  = 1
};


 
typedef struct Des {
  word32 key[DES_KS_SIZE];
  word32 reg[DES_BLOCK_SIZE / sizeof(word32)];       
  word32 tmp[DES_BLOCK_SIZE / sizeof(word32)];       
} Des;



 
typedef struct Des3 {
  word32 key[3][DES_KS_SIZE];
  word32 reg[DES_BLOCK_SIZE / sizeof(word32)];       
  word32 tmp[DES_BLOCK_SIZE / sizeof(word32)];       
} Des3;









 
void Des_SetKey(Des* des, const byte* key, const byte* iv, int dir);












 














 
void Des_CbcDecrypt(Des* des, byte* output, const byte* input, word32 sz);










 
void Des3_SetKey(Des3* des, const byte* key, const byte* iv,int dir);












 
void Des3_CbcEncrypt(Des3* des, byte* output, const byte* input,word32 sz);













 
void Des3_CbcDecrypt(Des3* des, byte* output, const byte* input,word32 sz);


 






 


 
enum {
  AES_ENC_TYPE   = 1,    
  AES_ENCRYPTION = 0,
  AES_DECRYPTION = 1,
  AES_BLOCK_SIZE = 16
};



 
typedef struct Aes {
     
  word32 key[60];
  word32  rounds;
  word32 reg[AES_BLOCK_SIZE / sizeof(word32)];      
  word32 tmp[AES_BLOCK_SIZE / sizeof(word32)];
} Aes;










 
int  AesSetKey(Aes* aes, const byte* key, word32 ilen, const byte* iv,int dir);












 
int  AesCbcEncrypt(Aes* aes, byte* output, const byte* input, word32 sz);












 
int  AesCbcDecrypt(Aes* aes, byte* output, const byte* input, word32 sz);










 
word32 AesCbcEncryptPkcs5Padding(Aes* aes, byte* output, const byte* input, word32 sz);










 
word32 AesCbcDecryptPkcs5Padding(Aes* aes, byte* output, const byte* input, word32 sz);











 
int  AesSetKeyDirect(Aes* aes, const byte* key, word32 ilen,const byte* out, int dir);
               











 
void AesEncryptDirect(Aes* aes, byte* out, const byte* in);












 
void AesDecryptDirect(Aes* aes, byte* out, const byte* in);


 





 



 
enum {
  ARC4_ENC_TYPE   = 4,     
  ARC4_STATE_SIZE = 256
};


 
typedef struct Arc4 {
  byte x;
  byte y;
  byte state[ARC4_STATE_SIZE];
} Arc4;










 
void Arc4SetKey(Arc4 *arc4, const byte *key, word32 keylen );











 
void Arc4Process(Arc4 *arc4, byte *output, const byte *input, word32 outlen);


 





 



 
enum {
  RABBIT_ENC_TYPE  = 5      
};




 
typedef struct RabbitCtx {
  word32 x[8];
  word32 c[8];
  word32 carry;
} RabbitCtx;
    


 
typedef struct Rabbit {
    RabbitCtx masterCtx;
    RabbitCtx workCtx;
} Rabbit;








 
int RabbitSetKey(Rabbit* rabbit, const byte* key, const byte* iv);












 
int RabbitProcess(Rabbit* rabbit, byte* output, const byte* input, word32 sz);


 






 



 
enum {
    RSA_PUBLIC   = 0,
    RSA_PRIVATE  = 1
};


 
typedef struct OS_Seed {
  int fd;
} OS_Seed;




 
typedef struct  {
    int used, alloc, sign;
    unsigned short *dp;
} mp_int;



 
typedef struct RsaKey {
    mp_int n, e, d, p, q, dP, dQ, u;
    int   type;                                
    void* heap;                                
} RsaKey;




 
enum {
    SHA256_BLOCK_SIZE   = 64,
    SHA256_DIGEST_SIZE  = 32,
    SHA256_PAD_SIZE     = 56
};



 
typedef struct Sha256 {
    word32  buffLen;    
    word32  loLen;      
    word32  hiLen;      
    word32  digest[SHA256_DIGEST_SIZE / sizeof(word32)];
    word32  buffer[SHA256_BLOCK_SIZE  / sizeof(word32)];
} Sha256;



 
typedef struct CyaSSL_RNG {
  OS_Seed seed;
  Sha256 sha;
  byte digest[SHA256_DIGEST_SIZE];
  byte V[(440/8)];
  byte C[(440/8)];
  word64 reseed_ctr;
} CyaSSL_RNG;









 
void InitRsaKey(RsaKey* key, void*);








 
void FreeRsaKey(RsaKey* key);








 
int  InitRng(CyaSSL_RNG *);













 
int  RsaPublicEncrypt(const byte* in, word32 inLen, byte* out,
                      word32 outLen, RsaKey* key, CyaSSL_RNG* rng);













 
int  RsaPrivateDecrypt(const byte* in, word32 inLen, byte* out,
                       word32 outLen, RsaKey* key);













 
int  RsaSSL_Sign(const byte* in, word32 inLen, byte* out,
                 word32 outLen, RsaKey* key, CyaSSL_RNG* rng);













 
int  RsaSSL_Verify(const byte* in, word32 inLen, byte* out,
                   word32 outLen, RsaKey* key);











 
int RsaPrivateKeyDecode(const byte* input, word32* inOutIdx, RsaKey* key,
                        word32 length);











 
int RsaPublicKeyDecode(const byte* input, word32* inOutIdx, RsaKey *key,word32);



 




 












 


typedef struct
{
    Aes                 ctx;
    uint8_t             ctr[ 16 ];   
    uint8_t             buf[ 16 ];   
    unsigned int              used;                   
    
    Boolean             legacy;                 
    
}   AES_CTR_Context;

OSStatus
    AES_CTR_Init( 
        AES_CTR_Context *   inContext, 
        const uint8_t       inKey[ 16 ], 
        const uint8_t       inNonce[ 16 ] );
OSStatus    AES_CTR_Update( AES_CTR_Context *inContext, const void *inSrc, unsigned int inSrcLen, void *inDst );
void        AES_CTR_Final( AES_CTR_Context *inContext );











 


typedef struct
{
    
    
    Aes                     ctx;
    int                     mode;
    uint8_t                 iv[ 16 ];   
    
}   AES_CBCFrame_Context;

OSStatus
    AES_CBCFrame_Init( 
        AES_CBCFrame_Context *  inContext, 
        const uint8_t           inKey[ 16 ], 
        const uint8_t           inIV[ 16 ], 
        Boolean                 inEncrypt );
OSStatus    AES_CBCFrame_Update( AES_CBCFrame_Context *inContext, const void *inSrc, unsigned int inSrcLen, void *inDst );
OSStatus
    AES_CBCFrame_Update2( 
        AES_CBCFrame_Context *  inContext, 
        const void *            inSrc1, 
        unsigned int                  inLen1, 
        const void *            inSrc2, 
        unsigned int                  inLen2, 
        void *                  inDst );
void    AES_CBCFrame_Final( AES_CBCFrame_Context *inContext );











 



typedef struct
{
    Aes                     ctx;
    uint32_t                mode;
    
}   AES_ECB_Context;

OSStatus    AES_ECB_Init( AES_ECB_Context *inContext, uint32_t inMode, const uint8_t inKey[ 16 ] );
OSStatus    AES_ECB_Update( AES_ECB_Context *inContext, const void *inSrc, unsigned int inLen, void *inDst );
void        AES_ECB_Final( AES_ECB_Context *inContext );

























 
































 


#pragma once





 




 



   




 




 

 

 
 










 
OSStatus MicoRandomNumberRead( void *inBuffer, int inByteCount );

 
 



































 


#pragma once





























 

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



 



 




















 

















 





 



   



 



 



 





 











 
OSStatus MicoMFiAuthInitialize( mico_i2c_t i2c );











 
void MicoMFiAuthFinalize( void );















 
OSStatus MicoMFiAuthCreateSignature( const  void      *inDigestPtr,
                                            unsigned int     inDigestLen,
                                            uint8_t  **outSignaturePtr,
                                            unsigned int    *outSignatureLen );













 
OSStatus MicoMFiAuthCopyCertificate( uint8_t **outCertificatePtr, unsigned int *outCertificateLen );

 
 































 







 




 
















 

uint32_t TimeDifference(uint32_t inStart, uint32_t inEnd);









 
long long ElapsedTimeInMilliseconds(uint32_t inDiff);







 
long long ElapsedTimeInMicroseconds(uint32_t inDiff);








 
long long ElapsedTimeInNanoseconds(uint32_t inDiff);










 
uint64_t UpTicks( void );








 
uint64_t UpTicksPerSecond( void );








 
void SleepForUpTicks( uint64_t inTicks );




 



 











typedef uint8_t     MFiSAPState;










struct MFiSAP
{
    MFiSAPState         state;
    uint8_t             version;
    uint8_t             sharedSecret[ 32 ];
    AES_CTR_Context     aesMasterContext;
    Boolean             aesMasterValid;
};



static uint64_t         gMFiSAP_LastTicks       = 0;
static unsigned int     gMFiSAP_ThrottleCounter = 0;





static OSStatus
    __MFiSAP_Exchange_ServerM1( 
        MFiSAPRef       inRef, 
        const uint8_t * inInputPtr,
        unsigned int          inInputLen, 
        uint8_t **      outOutputPtr,
        unsigned int *        outOutputLen );





OSStatus    MFiSAP_Create( MFiSAPRef *outRef, uint8_t inVersion )
{
    OSStatus        err;
    MFiSAPRef       obj;
    
    do { if( ! !(!(inVersion == 1)) ) { ; { err = -6715; } goto exit; } } while( 1==0 );
    
    obj = (MFiSAPRef) calloc( 1, sizeof( *obj ) );
    do { if( ! !(!(obj)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
    
    obj->state   = 1;
    obj->version = inVersion;
    
    *outRef = obj;
    err = 0;
    
exit:
    return( err );
}





void    MFiSAP_Delete( MFiSAPRef inRef )
{
    if( inRef->aesMasterValid )
    {
        AES_CTR_Final( &inRef->aesMasterContext );
    }
    memset( inRef, 0, sizeof( *inRef ) ); 
    free( inRef );
}





OSStatus
    MFiSAP_Exchange( 
        MFiSAPRef       inRef, 
        const uint8_t * inInputPtr,
        unsigned int          inInputLen, 
        uint8_t **      outOutputPtr,
        unsigned int *        outOutputLen, 
        Boolean *       outDone )
{
    OSStatus err;
    *outDone = 0;

    if( inRef->state == 1 )
    {
        inRef->state = ( inInputPtr == 0 ) ? 2 : 5;
    }

    if( inRef->state == 5 )
    {
        err = __MFiSAP_Exchange_ServerM1( inRef, inInputPtr, inInputLen, outOutputPtr, outOutputLen );
        do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
        *outDone = 1;
    }
    else
    {
        ;
        err = -6709;
        goto exit;
    }
    ++inRef->state;

exit:
    if( err ) inRef->state = 0; 
    return err;
}







static OSStatus
    __MFiSAP_Exchange_ServerM1( 
        MFiSAPRef       inRef, 
        const uint8_t * inInputPtr,
        unsigned int          inInputLen, 
        uint8_t **      outOutputPtr,
        unsigned int *        outOutputLen )
{
    OSStatus            err;
    const uint8_t *     inputEnd;
    const uint8_t *     clientECDHPublicKey;
    uint8_t             ourPrivateKey[ 32 ];
    uint8_t             ourPublicKey[ 32 ];
    SHA1Context             sha1Context;
    uint8_t             digest[ 20 ];
    uint8_t *           signaturePtr = 0;
    unsigned int              signatureLen;
    uint8_t *           certificatePtr = 0;
    unsigned int              certificateLen;
    uint8_t             aesMasterKey[ 16 ];
    uint8_t             aesMasterIV[ 16 ];
    uint8_t *           buf;
    uint8_t *           dst;
    unsigned int              len;

    if( ( UpTicks() - gMFiSAP_LastTicks ) < UpTicksPerSecond() )
    {
        if( gMFiSAP_ThrottleCounter < 4 ) ++gMFiSAP_ThrottleCounter;
        SleepForUpTicks( gMFiSAP_ThrottleCounter * UpTicksPerSecond() );
    }
    else
    {
        gMFiSAP_ThrottleCounter = 0;
    }
    gMFiSAP_LastTicks = UpTicks();

    

    inputEnd = inInputPtr + inInputLen;
    do { if( ! !(!(inputEnd > inInputPtr)) ) { ; { err = -6743; } goto exit; } } while( 1==0 ); 

    do { if( ! !(!(( inputEnd - inInputPtr ) >= 1)) ) { ; { err = -6743; } goto exit; } } while( 1==0 );
    inRef->version = *inInputPtr++;
    do { if( ! !(!(inRef->version == 1)) ) { ; { err = -6715; } goto exit; } } while( 1==0 );

    do { if( ! !(!(( inputEnd - inInputPtr ) >= 32)) ) { ; { err = -6743; } goto exit; } } while( 1==0 );
    clientECDHPublicKey = inInputPtr;
    inInputPtr += 32;

    do { if( ! !(!(inInputPtr == inputEnd)) ) { ; { err = -6743; } goto exit; } } while( 1==0 );

    

    err = MicoRandomNumberRead( ourPrivateKey, sizeof( ourPrivateKey ) );
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
    curve25519_donna( ourPublicKey, ourPrivateKey, 0 );

    
    
    

    curve25519_donna( inRef->sharedSecret, ourPrivateKey, clientECDHPublicKey );
    SHA1Reset( (&sha1Context) );
    SHA1Input( (&sha1Context), ((uint8_t *)"AES-KEY"), (( sizeof( "AES-KEY" ) - 1 )) );
    SHA1Input( (&sha1Context), (inRef->sharedSecret), (sizeof( inRef->sharedSecret )) );
    SHA1Result( (&sha1Context), (digest) );
    memcpy( aesMasterKey, digest, sizeof( aesMasterKey ) );

    SHA1Reset( (&sha1Context) );
    SHA1Input( (&sha1Context), ((uint8_t *)"AES-IV"), (( sizeof( "AES-IV" ) - 1 )) );
    SHA1Input( (&sha1Context), (inRef->sharedSecret), (sizeof( inRef->sharedSecret )) );
    SHA1Result( (&sha1Context), (digest) );
    memcpy( aesMasterIV, digest, sizeof( aesMasterIV ) );

    
    

    SHA1Reset( (&sha1Context) );
    SHA1Input( (&sha1Context), (ourPublicKey), (sizeof( ourPublicKey )) );
    SHA1Input( (&sha1Context), (clientECDHPublicKey), (32) );
    SHA1Result( (&sha1Context), (digest) );
    err = MicoMFiAuthCreateSignature( digest, sizeof( digest ), &signaturePtr, &signatureLen );
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

    err = MicoMFiAuthCopyCertificate( &certificatePtr, &certificateLen );
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

    
    
    err = AES_CTR_Init( &inRef->aesMasterContext, aesMasterKey, aesMasterIV );
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

    err = AES_CTR_Update( &inRef->aesMasterContext, signaturePtr, signatureLen, signaturePtr );
    if( err ) AES_CTR_Final( &inRef->aesMasterContext );
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

    inRef->aesMasterValid = 1;

    
    
    
    
    
    
    

    len = 32 + 4 + certificateLen + 4 + signatureLen;
    buf = (uint8_t *) malloc( len );
    do { if( ! !(!(buf)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
    dst = buf;

    memcpy( dst, ourPublicKey, sizeof( ourPublicKey ) );
    dst += sizeof( ourPublicKey );

    *dst++ = (uint8_t)( ( certificateLen >> 24 ) & 0xFF );
    *dst++ = (uint8_t)( ( certificateLen >> 16 ) & 0xFF );
    *dst++ = (uint8_t)( ( certificateLen >>  8 ) & 0xFF );
    *dst++ = (uint8_t)(   certificateLen         & 0xFF );
    memcpy( dst, certificatePtr, certificateLen );
    dst += certificateLen;

    *dst++ = (uint8_t)( ( signatureLen >> 24 ) & 0xFF );
    *dst++ = (uint8_t)( ( signatureLen >> 16 ) & 0xFF );
    *dst++ = (uint8_t)( ( signatureLen >>  8 ) & 0xFF );
    *dst++ = (uint8_t)(   signatureLen         & 0xFF );
    memcpy( dst, signaturePtr, signatureLen );
    dst += signatureLen;

    do { if( ! !(!(dst == ( buf + len ))) ) { ; } } while( 1==0 );
    *outOutputPtr = buf;
    *outOutputLen = (unsigned int)( dst - buf );

exit:
    if( certificatePtr )    free( certificatePtr );
    if( signaturePtr )      free( signaturePtr );
    return( err );
}





OSStatus    MFiSAP_Encrypt( MFiSAPRef inRef, const void *inPlaintext, unsigned int inLen, void *inCiphertextBuf )
{
    OSStatus        err;

    do { if( ! !(!(( inRef->state == 4 ) || ( inRef->state == 6 ))) ) { ; { err = -6709; } goto exit; } } while( 1==0 );

    err = AES_CTR_Update( &inRef->aesMasterContext, inPlaintext, inLen, inCiphertextBuf );
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

exit:
    return( err );
}





OSStatus    MFiSAP_Decrypt( MFiSAPRef inRef, const void *inCiphertext, unsigned int inLen, void *inPlaintextBuf )
{
    OSStatus        err;

    do { if( ! !(!(( inRef->state == 4 ) || ( inRef->state == 6 ))) ) { ; { err = -6709; } goto exit; } } while( 1==0 );

    err = AES_CTR_Update( &inRef->aesMasterContext, inCiphertext, inLen, inPlaintextBuf );
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

exit:
    return( err );
}





OSStatus
    MFiSAP_DeriveAESKey(
        MFiSAPRef       inRef, 
        const void *    inKeySaltPtr, 
        unsigned int          inKeySaltLen, 
        const void *    inIVSaltPtr, 
        unsigned int          inIVSaltLen, 
        uint8_t         outKey[ 16 ], 
        uint8_t         outIV[ 16 ] )
{
    OSStatus        err;
    SHA512Context      shaCtx;
    uint8_t         buf[ 64 ];

    do { if( ! !(!(( inRef->state == 4 ) || ( inRef->state == 6 ))) ) { ; { err = -6709; } goto exit; } } while( 1==0 );
    if( outKey )
    {
        SHA512Reset( (&shaCtx) );
        SHA512Input( (&shaCtx), (inKeySaltPtr), (inKeySaltLen) );
        SHA512Input( (&shaCtx), (inRef->sharedSecret), (32) );
        SHA512Result( (&shaCtx), (buf) );
        memcpy( outKey, buf, 16 );
    }
    if( outIV )
    {
        SHA512Reset( (&shaCtx) );
        SHA512Input( (&shaCtx), (inIVSaltPtr), (inIVSaltLen) );
        SHA512Input( (&shaCtx), (inRef->sharedSecret), (32) );
        SHA512Result( (&shaCtx), (buf) );
        memcpy( outIV, buf, 16 );
    }
    err = 0;

exit:
    return( err );
}


