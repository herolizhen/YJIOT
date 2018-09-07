





























 
































 
































 



 
 

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




 






 



 


































 

#pragma once

















 

#pragma once






























 





  





 




 









  
typedef enum { 
  Soft_AP,   
  Station    
} wlanInterfaceTypedef; 



  
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
void iperf_Command(char *pcWriteBuffer, int xWriteBufferLen, int argc, char * *argv);












 












 
















 



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





 
OSStatus mico_system_get_status_wlan( mico_system_status_wlan_t** status );





 
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

 
 































 


#pragma once





 




 



   




 




 

 

 
 










 
OSStatus MicoRandomNumberRead( void *inBuffer, int inByteCount );

 
 
























  




 


 

 
typedef struct _hk_server_status_t {
   
  uint32_t          statusNumber;
  _Bool              useMFiAuth;
  uint16_t          server_port;

} hk_server_status_t;

OSStatus hk_bonjour_start( int ci, int config_number, char *model );
OSStatus hk_bonjour_update_state_number( void );
OSStatus hk_bonjour_update_config_number( int config_number );
OSStatus hk_bonjour_update_status_flag( void );






















 


















 

#pragma once



 
typedef struct _pair_t {
  char             controllerName[64];
  uint8_t          controllerLTPK[32];
  int              permission;
} _pair_t;

typedef struct _pair_list_in_flash_t {
  _pair_t          pairInfo[16];
} pair_list_in_flash_t;

 


uint32_t HKPairInfoCount(void);

OSStatus HKPairInfoClear(void);

OSStatus HKPairInfoInsert(char controllerIdentifier[64], uint8_t controllerLTPK[32], _Bool admin);

OSStatus HKPairInfoFindByName(char controllerIdentifier[64], uint8_t foundControllerLTPK[32], _Bool *isAdmin );

OSStatus HKPairInfoFindByIndex(uint32_t index, char controllerIdentifier[64], uint8_t foundControllerLTPK[32], _Bool *isAdmin );

OSStatus HKPairInfoRemove(char controllerIdentifier[64]);



 

typedef int32_t         HkStatus;



enum hk_ci_e{
  CI_ORHER = 1,  
  CI_BRIDGE,
  CI_FAN,
  CI_GARAGE_DOOR_OPENER,    
  CI_LIGHTBULB,
  CI_DOOR_LOCK,
  CI_OUTLET,
  CI_SWITCH,
  CI_THERMOSTAT,
  CI_RESERVED,
} ;
typedef uint8_t hk_ci_t;

typedef enum _valueType{
  ValueType_bool,
  ValueType_int,
  ValueType_float,
  ValueType_string,
  ValueType_date,
  ValueType_tlv8,
  ValueType_data,
  ValueType_array,
  ValueType_dict,
  ValueType_null,
} valueType;

typedef union {
    _Bool        boolValue;
    int         intValue;
    double      floatValue;
    char        *stringValue;
    char        *dateValue;
    json_object *array;
    json_object *object;
  } value_union;


struct _hapCharacteristic_t {
  char   *type;

  _Bool   hasStaticValue;
  valueType valueType;
  value_union value;

  _Bool   secureRead;
  _Bool   secureWrite;
  _Bool   hasEvents;

  _Bool   hasMinimumValue;
  union {
    int         intValue;
    float       floatValue;
  }      minimumValue;

  _Bool   hasMaximumValue;
  union {
    int         intValue;
    float       floatValue;
  }      maximumValue;

  _Bool   hasMinimumStep;
  union {
    int         intValue;
    float       floatValue;
  }      minimumStep;

  _Bool   hasMaxLength;
  int    maxLength;

  _Bool   hasMaxDataLength;
  int    maxDataLength;

  char   *description;

  char   *format;
  
  char   *unit;
};

struct _hapService_t {
  char    *type;
  uint32_t num_of_characteristics;
  struct  _hapCharacteristic_t *characteristic;
};

struct _hapAccessory_t {
  uint32_t num_of_services;
  struct _hapService_t  *services;
};

struct _hapProduct_t {
  uint32_t num_of_accessories;
  struct _hapAccessory_t  *accessories;
};

typedef struct _hapProduct_t hapProduct_t;

typedef OSStatus (*hk_key_storage_cb)(unsigned char *pk, unsigned char *sk, _Bool write);

 
typedef struct _hk_init_t {
  hk_ci_t             ci;
  char *              model;
  int                 config_number;
  mico_i2c_t          mfi_cp_port;
  hapProduct_t *      hap_product;
  uint8_t *           password;
  int                 password_len;
  uint8_t *           verifier;
  int                 verifier_len;
  uint8_t *           salt;
  int                 salt_len;
  hk_key_storage_cb   key_storage;
} hk_init_t;

void hk_server_lib_version( uint8_t *major, uint8_t *minor, uint8_t *revision );

OSStatus hk_server_start( hk_init_t init );

OSStatus hk_server_update_attri_db( hapProduct_t *hap_product, int config_number );

OSStatus hk_server_notify_by_bonjour( void );

 
HkStatus HKReadCharacteristicValue(int accessoryID, int serviceID, int characteristicID, value_union *value );

void HKWriteCharacteristicValue(int accessoryID, int serviceID, int characteristicID, value_union value, _Bool moreComing );

HkStatus HKReadCharacteristicStatus(int accessoryID, int serviceID, int characteristicID );

HkStatus HKExcuteUnpairedIdentityRoutine( void );






























 


























 



struct SRPVerifier;


typedef enum
{
    SRP_NG_1024,
    SRP_NG_2048,
    SRP_NG_3072,
    SRP_NG_4096,
    SRP_NG_8192,
    SRP_NG_CUSTOM
} SRP_NGType;

typedef enum 
{
    SRP_SHA1, 
    SRP_SHA224, 
    SRP_SHA256,
    SRP_SHA384, 
    SRP_SHA512
} SRP_HashAlgorithm;

 
typedef struct _srp_server_t {
  SRP_HashAlgorithm alg;
  _Bool              authenticated;
  SRP_NGType        ng_type;
  const char        * n_hex;
  const char        * g_hex;
  char              *username;
  unsigned char     *bytes_s;
  int               len_s;
  unsigned char     *bytes_B;
  int               len_B;
  unsigned char     *bytes_b;
  int               len_b;  
  unsigned char     *bytes_v;
  int               len_v;
  unsigned char     *session_key;
  int               len_session_key;
  unsigned char     *bytes_M;
  int               len_M;
  unsigned char     *bytes_AMK;
  int               len_AMK;
} srp_server_t;









 
void srp_create_salted_verification_key( SRP_HashAlgorithm alg, 
                                         SRP_NGType ng_type, const char * username,
                                         const unsigned char * password, int len_password,
                                         const unsigned char ** bytes_s, int * len_s, 
                                         const unsigned char ** bytes_v, int * len_v,
                                         const unsigned char ** bytes_B, int * len_B,
                                         const unsigned char ** bytes_b, int * len_b,
                                         const char * n_hex, const char * g_hex );

srp_server_t* srp_server_setup( SRP_HashAlgorithm alg, 
                                SRP_NGType ng_type, const char * username,
                                const unsigned char * password, int len_password, 
                                const unsigned char * verifier, int len_verifier,
                                const unsigned char * salt, int len_salt, 
                                const char * n_hex, const char * g_hex );

OSStatus srp_server_generate_session_key( srp_server_t* server, const unsigned char * bytes_A, int len_A );

void srp_server_verify_session( srp_server_t* server, const unsigned char * user_M, const unsigned char ** bytes_HAMK );

void srp_server_delete( srp_server_t** server);








 
struct SRPVerifier *  srp_verifier_new( SRP_HashAlgorithm alg, SRP_NGType ng_type, const char * username,
                                        const unsigned char * bytes_s, int len_s, 
                                        const unsigned char * bytes_v, int len_v,
                                        const unsigned char * bytes_A, int len_A,
                                        const unsigned char * bytes_B, int len_B,
                                        const unsigned char * bytes_b, int len_b,
                                        const char * n_hex, const char * g_hex );


void                  srp_verifier_delete( struct SRPVerifier * ver );


int                   srp_verifier_is_authenticated( struct SRPVerifier * ver );


const char *          srp_verifier_get_username( struct SRPVerifier * ver );

 
const unsigned char * srp_verifier_get_session_key( struct SRPVerifier * ver, int * key_length );


int                   srp_verifier_get_session_key_length( struct SRPVerifier * ver );


 
void                  srp_verifier_verify_session( struct SRPVerifier * ver,
                                                   const unsigned char * user_M, 
                                                   const unsigned char ** bytes_HAMK );

































 

































 





 




 


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





 
typedef struct _pairInfo_t {
  char              *SRPUser;
  srp_server_t      *SRPServer;
  uint8_t           *SRPControllerPublicKey;
  int           SRPControllerPublicKeyLen;
  uint8_t           *SRPControllerProof;
  int           SRPControllerProofLen;
  uint8_t           *HKDF_Key;
  _Bool              pairListFull;
} pairInfo_t;


 
typedef struct _pairVerifyInfo_t {
  _Bool                      verifySuccess;
  int                       haPairVerifyState;
  uint8_t                   *pControllerLTPK;
  char                      *pControllerIdentifier;
  uint8_t                   *pControllerCurve25519PK;
  uint8_t                   *pAccessoryCurve25519PK;
  uint8_t                   *pAccessoryCurve25519SK;
  uint8_t                   *pSharedSecret;
  uint8_t                   *pHKDFKey;
  uint8_t                   *A2CKey;
  uint8_t                   *C2AKey;
} pairVerifyInfo_t;




OSStatus HKPairEngineInit( mico_i2c_t mfi_cp_port, hk_key_storage_cb key_storage_fun );

void HKSetPassword (uint8_t * password, unsigned int passwordLen);

void HKSetVerifier (uint8_t * verifier, unsigned int verifierLen, uint8_t * salt, unsigned int saltLen );

 

void HKCleanPairSetupInfo(pairInfo_t **info);

OSStatus HKPairSetupEngine( int inFd, HTTPHeader_t* inHeader, pairInfo_t** inInfo );

_Bool HKPairSetupEngineIsRunning( void );

 

pairVerifyInfo_t* HKCreatePairVerifyInfo(void);

void HKCleanPairVerifyInfo(pairVerifyInfo_t **verifyInfo);

OSStatus HKPairVerifyEngine( int inFd, HTTPHeader_t* inHeader, pairVerifyInfo_t* inInfo );

 

OSStatus HKPairAddRemoveEngine( int inFd, HTTPHeader_t* inHeader, security_session_t *session );






 
























    
    























































 

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

































 





 




 











 

OSStatus SocketSend( int fd, const uint8_t *inBuf, unsigned int inBufLen );








 
void SocketClose(int* fd);








 
void SocketCloseForOSEvent(int* fd);









 
void SocketAccept(int *plocalTcpClientsPool, int maxClientsNum, int newFd);




 



 


































 







 




 














 
OSStatus TLVGetNext( 
        const uint8_t *     inSrc, 
        const uint8_t *     inEnd, 
        uint8_t *           outID, 
        const uint8_t **    outData, 
        unsigned int *            outLen, 
        const uint8_t **    outNext );




 



 































 


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




 



 





typedef enum
{
  eState_M1_VerifyStartRequest      = 1,
  eState_M2_VerifyStartRespond      = 2,
  eState_M3_VerifyFinishRequest     = 3,
  eState_M4_VerifyFinishRespond     = 4,
} HKPairVerifyState_t;

typedef enum
{
  eState_M1_PairingRequest      = 1,
  eState_M2_PairingRespond      = 2,
} HKPairingState_t;

typedef enum
{
  Pair_Setup,
  Pair_MFi_Setup,
  Pair_Verify,
  Pair_Add,
  Pair_Remove,
  Pair_List,
  Pair_Unknown,
} HKPairMethold_t;

typedef enum
{
    eState_M1_SRPStartRequest      = 1,
    eState_M2_SRPStartRespond      = 2,
    eState_M3_SRPVerifyRequest     = 3,
    eState_M4_SRPVerifyRespond     = 4,
    eState_M5_ExchangeRequest      = 5,
    eState_M6_ExchangeRespond      = 6,
} HAPairSetupState_t;

const char * hkdfSetupSalt  =        "Pair-Setup-Encrypt-Salt";
const char * hkdfSetupInfo =         "Pair-Setup-Encrypt-Info";

const char * hkdfSetupCSignSalt  =    "Pair-Setup-Controller-Sign-Salt";
const char * hkdfSetupCSignInfo =     "Pair-Setup-Controller-Sign-Info";

const char * hkdfMFiSalt  =    "MFi-Pair-Setup-Salt";
const char * hkdfMFiInfo =     "MFi-Pair-Setup-Info";

const char * hkdfSetupASignSalt  =    "Pair-Setup-Accessory-Sign-Salt";
const char * hkdfSetupASignInfo =     "Pair-Setup-Accessory-Sign-Info";

const char * hkdfVerifySalt =        "Pair-Verify-Encrypt-Salt";
const char * hkdfVerifyInfo =        "Pair-Verify-Encrypt-Info";

const char * hkdfC2AKeySalt =        "Control-Salt";
const char * hkdfC2AInfo =           "Control-Write-Encryption-Key";

const char * hkdfA2CKeySalt =        "Control-Salt";
const char * hkdfA2CInfo =           "Control-Read-Encryption-Key";

const char * AEAD_Nonce_Setup04 =   "PS-Msg04";
const char * AEAD_Nonce_Setup05 =   "PS-Msg05";
const char * AEAD_Nonce_Setup06 =   "PS-Msg06";
const char * AEAD_Nonce_Verify02 =  "PV-Msg02";
const char * AEAD_Nonce_Verify03 =  "PV-Msg03";

const char *stateDescription[7] = {"", "kTLVType_State = M1", "kTLVType_State = M2", "kTLVType_State = M3",
                                   "kTLVType_State = M4", "kTLVType_State = M5", "kTLVType_State = M6"};

static uint8_t  pairErrorNum = 0;

static uint8_t  *_password = 0;
static unsigned int         _len_password = 0;

static uint8_t  *_verifier = 0;
static unsigned int         _len_verifier = 0;

static uint8_t  *_salt = 0;
static unsigned int         _len_salt = 0;

static HAPairSetupState_t haPairSetupState = eState_M1_SRPStartRequest;
const char* hkSRPUser = "Pair-Setup";

static _Bool _haPairSetupRunning = 0;
static _Bool _haUseMFiAuth = 0;
static mico_i2c_t _mfi_cp_port = MICO_I2C_NONE;

static hk_key_storage_cb  _key_storage;

OSStatus _HandleState_WaitingForSRPStartRequest ( HTTPHeader_t* inHeader, pairInfo_t** inInfo );
OSStatus _HandleState_HandleSRPStartRespond     ( int inFd, pairInfo_t* inInfo );
OSStatus _HandleState_WaitingForSRPVerifyRequest( HTTPHeader_t* inHeader, pairInfo_t* inInfo );
OSStatus _HandleState_HandleSRPVerifyRespond    ( int inFd, pairInfo_t* inInfo );
OSStatus _HandleState_WaitingForExchangeRequest ( HTTPHeader_t* inHeader, pairInfo_t* inInfo );
OSStatus _HandleState_HandleExchangeRespond     ( int inFd, pairInfo_t** inInfo );

OSStatus _HandleState_WaitingForVerifyStartRequest  ( HTTPHeader_t* inHeader, pairVerifyInfo_t* inInfo );
OSStatus _HandleState_WaitingForVerifyStartRespond  ( int inFd, pairVerifyInfo_t* inInfo );
OSStatus _HandleState_WaitingForVerifyFinishRequest ( HTTPHeader_t* inHeader, pairVerifyInfo_t* inInfo );
OSStatus _HandleState_WaitingForVerifyFinishRespond ( int inFd, pairVerifyInfo_t* inInfo );

void HKSetPassword ( uint8_t * password,  unsigned int passwordLen)
{
  _password = password;
  _len_password = passwordLen;
}

void HKSetVerifier ( uint8_t * verifier, unsigned int verifierLen, uint8_t * salt, unsigned int saltLen )
{
  _verifier = verifier;
  _len_verifier = verifierLen;
  _salt = salt;
  _len_salt = saltLen;
}

OSStatus HKPairEngineInit( mico_i2c_t mfi_cp_port, hk_key_storage_cb key_storage_fun )
{
  _mfi_cp_port = mfi_cp_port;

  if( 0 == MicoMFiAuthInitialize( _mfi_cp_port ) )
    _haUseMFiAuth = 1;
  else
    _haUseMFiAuth = 0;

  _haPairSetupRunning = 0;

  _key_storage = key_storage_fun;
  
  return 0;
}

_Bool HKPairSetupEngineIsRunning( void )
{
  return _haPairSetupRunning;
}

void HKCleanPairSetupInfo( pairInfo_t **info ){
  if(*info){
    if(_haPairSetupRunning == 1){
      haPairSetupState = eState_M1_SRPStartRequest;
      _haPairSetupRunning = 0;
    }
      
    srp_server_delete(&(*info)->SRPServer );
    
    if((*info)->SRPControllerPublicKey) free((*info)->SRPControllerPublicKey);
    if((*info)->SRPControllerProof) free((*info)->SRPControllerProof);
    if((*info)->HKDF_Key) free((*info)->HKDF_Key);
    free((*info));   
    *info = 0; 
  }
}

pairVerifyInfo_t* HKCreatePairVerifyInfo(void)
{
  pairVerifyInfo_t *pairVerifyInfo = 0;
  pairVerifyInfo = calloc(1, sizeof( pairVerifyInfo_t ) );
  do { if( ! !(!(pairVerifyInfo)) ) { ; goto exit; } } while( 1==0 );
  pairVerifyInfo->haPairVerifyState = eState_M1_VerifyStartRequest;
  pairVerifyInfo->pControllerLTPK = malloc(32);
exit:
  return pairVerifyInfo;
}

void HKCleanPairVerifyInfo(pairVerifyInfo_t **verifyInfo){
    if(*verifyInfo){
    if((*verifyInfo)->pControllerLTPK) free((*verifyInfo)->pControllerLTPK);
    if((*verifyInfo)->pControllerCurve25519PK) free((*verifyInfo)->pControllerCurve25519PK);
    if((*verifyInfo)->pAccessoryCurve25519PK) free((*verifyInfo)->pAccessoryCurve25519PK);
    if((*verifyInfo)->pAccessoryCurve25519SK) free((*verifyInfo)->pAccessoryCurve25519SK);
    if((*verifyInfo)->pSharedSecret) free((*verifyInfo)->pSharedSecret);
    if((*verifyInfo)->pHKDFKey) free((*verifyInfo)->pHKDFKey);
    if((*verifyInfo)->A2CKey) free((*verifyInfo)->A2CKey);
    if((*verifyInfo)->C2AKey) free((*verifyInfo)->C2AKey);
    if((*verifyInfo)->pControllerIdentifier) free((*verifyInfo)->pControllerIdentifier);
    
    free((*verifyInfo));   
    *verifyInfo = 0; 
  }
}

OSStatus HKPairSetupEngine( int inFd, HTTPHeader_t* inHeader, pairInfo_t** inInfo )
{
  OSStatus err = 0;

  uint8_t *outTLVResponse = 0;
  unsigned int outTLVResponseLen = 0;
  uint8_t *tlvPtr;

  uint8_t *httpResponse = 0;
  unsigned int httpResponseLen = 0;

  if(pairErrorNum>=10){
    outTLVResponse = 0;

     
    outTLVResponseLen = 0;
    outTLVResponseLen += sizeof(uint8_t) + 2;
    outTLVResponseLen += sizeof(uint8_t) + 2;

    outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
    do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

    tlvPtr = outTLVResponse;
    *tlvPtr++ = 0x06;
    *tlvPtr++ = sizeof(uint8_t);
    *tlvPtr++ = eState_M2_SRPStartRespond;

    *tlvPtr++ = 0x07;
    *tlvPtr++ = sizeof(uint8_t);
    *tlvPtr++ = 0x05;

    haPairSetupState = eState_M1_SRPStartRequest;

    err =  CreateSimpleHTTPMessageNoCopy( "application/pairing+tlv8", outTLVResponseLen, &httpResponse, &httpResponseLen );
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
    err = SocketSend( inFd, httpResponse, httpResponseLen );
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
    err = SocketSend(inFd, outTLVResponse, outTLVResponseLen);
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
    goto exit;
  }

  switch ( haPairSetupState ){
    case eState_M1_SRPStartRequest:
      err = _HandleState_WaitingForSRPStartRequest( inHeader, inInfo );
      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; { haPairSetupState = eState_M1_SRPStartRequest; } goto exit; } } while( 1==0 );
      err =  _HandleState_HandleSRPStartRespond( inFd , *inInfo );
      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; { haPairSetupState = eState_M1_SRPStartRequest; } goto exit; } } while( 1==0 );
      break;

    case eState_M3_SRPVerifyRequest:
      err = _HandleState_WaitingForSRPVerifyRequest( inHeader, *inInfo );
      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; { haPairSetupState = eState_M1_SRPStartRequest; } goto exit; } } while( 1==0 );
      err = _HandleState_HandleSRPVerifyRespond(inFd , *inInfo);
      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; { haPairSetupState = eState_M1_SRPStartRequest; } goto exit; } } while( 1==0 );
      break;

    case eState_M5_ExchangeRequest:
      err = _HandleState_WaitingForExchangeRequest( inHeader, *inInfo );
      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; { haPairSetupState = eState_M1_SRPStartRequest; } goto exit; } } while( 1==0 );
      err = _HandleState_HandleExchangeRespond(inFd , inInfo );
      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; { haPairSetupState = eState_M1_SRPStartRequest; } goto exit; } } while( 1==0 );
      break;

    default:
      ;
      err = 0;
  }

exit:
  if(err!=0){
    HKCleanPairSetupInfo( inInfo );
    pairErrorNum++;
  }
    
  return err;
}


OSStatus _HandleState_WaitingForSRPStartRequest( HTTPHeader_t* inHeader, pairInfo_t** inInfo )
{
  ;
  const uint8_t *             src = (const uint8_t *) inHeader->extraDataPtr;
  const uint8_t * const       end = src + inHeader->extraDataLen;
  uint8_t                     eid;
  const uint8_t *             ptr;
  unsigned int                      len;
  char *                      tmp;

  OSStatus err = 0;

   
  if(haPairSetupState != eState_M1_SRPStartRequest){
    pairErrorNum++;
    return 0;
  }

  HKCleanPairSetupInfo( inInfo ); 
  *inInfo = calloc(1, sizeof(pairInfo_t));
  do { if( ! !(!(*inInfo)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
  _haPairSetupRunning = 1;

  while( TLVGetNext( src, end, &eid, &ptr, &len, &src ) == 0 )
  {
    tmp = calloc( len + 1, sizeof( uint8_t ) );
    do { if( ! !(!(tmp)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
    memcpy( tmp, ptr, len );

    switch( eid )
    {
      case 0x06:
        do { if( ! !(!(haPairSetupState == *(uint8_t *)tmp)) ) { ; { err = -6709; } goto exit; } } while( 1==0 );
        free(tmp);
      break;
        case 0x00:
        free(tmp);
        break;
      default:
        free( tmp );
        ;
        break;
    }
  }
  (*inInfo)->SRPUser = (char *)hkSRPUser;
  haPairSetupState = eState_M2_SRPStartRespond;
  
exit:
  return err;
}

OSStatus _HandleState_HandleSRPStartRespond( int inFd, pairInfo_t* inInfo )
{
  ;
  OSStatus err = 0;
  int i, j;
  uint8_t *outTLVResponse = 0;
  unsigned int outTLVResponseLen = 0;
  uint8_t *tlvPtr;
  uint8_t *httpResponse = 0;
  unsigned int httpResponseLen = 0;


  do { if( ! !(!(_verifier||_password)) ) { ; { err = -6705; } goto exit; } } while( 1==0 );
  inInfo->SRPServer = srp_server_setup( SRP_SHA512, SRP_NG_3072, inInfo->SRPUser, 
                                        (const unsigned char *)_password, _len_password, 
                                        (const unsigned char *)_verifier, _len_verifier,
                                        (const unsigned char *)_salt, _len_salt,
                                        0, 0);
  do { if( ! !(!(inInfo->SRPServer)) ) { ; goto exit; } } while( 1==0 );


  outTLVResponseLen += sizeof(uint8_t) + 2;
  for(i = inInfo->SRPServer->len_B/255; i>0; i--)
    outTLVResponseLen += 255 + 2;
  outTLVResponseLen += inInfo->SRPServer->len_B%255 + 2;
  outTLVResponseLen += inInfo->SRPServer->len_s + 2;

  outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
  do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

  tlvPtr = outTLVResponse;

   
  *tlvPtr++ = 0x06;
  *tlvPtr++ = sizeof(uint8_t);
  *tlvPtr++ = (uint8_t)eState_M2_SRPStartRespond;
  
   
  *tlvPtr++ = 0x02;
  *tlvPtr++ = inInfo->SRPServer->len_s;
  memcpy( tlvPtr, inInfo->SRPServer->bytes_s, inInfo->SRPServer->len_s );
  tlvPtr += inInfo->SRPServer->len_s;

   
  j = inInfo->SRPServer->len_B/255;
  for(i = 0; i < j; i++){
    *tlvPtr++ = 0x03;
    *tlvPtr++ = 255;
    memcpy( tlvPtr, inInfo->SRPServer->bytes_B+i*255, 255 );
    tlvPtr += 255;
  }
  *tlvPtr++ = 0x03;
  *tlvPtr++ = inInfo->SRPServer->len_B%255;
  memcpy( tlvPtr, inInfo->SRPServer->bytes_B+255*j, inInfo->SRPServer->len_B%255 );
  tlvPtr += inInfo->SRPServer->len_B%255;
  
   
  err =  CreateSimpleHTTPMessageNoCopy( "application/pairing+tlv8", outTLVResponseLen, &httpResponse, &httpResponseLen );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  err = SocketSend( inFd, httpResponse, httpResponseLen );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  err = SocketSend( inFd, outTLVResponse, outTLVResponseLen );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

  haPairSetupState = eState_M3_SRPVerifyRequest;

exit:
  if(outTLVResponse) free(outTLVResponse);
  if(httpResponse) free(httpResponse);
  return err;
}

OSStatus _HandleState_WaitingForSRPVerifyRequest( HTTPHeader_t* inHeader, pairInfo_t* inInfo )
{
  ;
  const uint8_t *             src = (const uint8_t *) inHeader->extraDataPtr;
  const uint8_t * const       end = src + inHeader->extraDataLen;
  uint8_t                     eid;
  const uint8_t *             ptr;
  unsigned int                      len;
  char *                      tmp;
  OSStatus err = 0;

  while( TLVGetNext( src, end, &eid, &ptr, &len, &src ) == 0 )
  {

    switch( eid )
    {
      case 0x06:
        tmp = calloc( len, sizeof( uint8_t ) );
        do { if( ! !(!(tmp)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
        memcpy( tmp, ptr, len );
        do { if( ! !(!(haPairSetupState == *(uint8_t *)tmp)) ) { ; { err = -6709; } goto exit; } } while( 1==0 );
        free(tmp);
      break;
        case 0x03:
        if(inInfo->SRPControllerPublicKey == 0){
          inInfo->SRPControllerPublicKey = calloc( len, sizeof( uint8_t ) );
          do { if( ! !(!(inInfo->SRPControllerPublicKey)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
          memcpy( inInfo->SRPControllerPublicKey, ptr, len );
          inInfo->SRPControllerPublicKeyLen = len;
        }else{
          inInfo->SRPControllerPublicKey = realloc( inInfo->SRPControllerPublicKey, inInfo->SRPControllerPublicKeyLen+len );
          do { if( ! !(!(inInfo->SRPControllerPublicKey)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
          memcpy( inInfo->SRPControllerPublicKey+inInfo->SRPControllerPublicKeyLen, ptr, len );
          inInfo->SRPControllerPublicKeyLen += len;
        }
        break;
      case 0x04:
        if(inInfo->SRPControllerProof == 0){
          inInfo->SRPControllerProof = calloc( len, sizeof( uint8_t ) );
          do { if( ! !(!(inInfo->SRPControllerProof)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
          memcpy( inInfo->SRPControllerProof, ptr, len );
          inInfo->SRPControllerProofLen = len;
        }else{
          inInfo->SRPControllerProof = realloc( inInfo->SRPControllerProof, inInfo->SRPControllerProofLen+len );
          do { if( ! !(!(inInfo->SRPControllerProof)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
          memcpy( inInfo->SRPControllerProof+inInfo->SRPControllerProofLen, ptr, len );
          inInfo->SRPControllerProofLen += len;
        }
        break;
      default:
        ;
        break;
    }
  }


  
  haPairSetupState = eState_M4_SRPVerifyRespond;


exit:
  return err;
}

OSStatus _HandleState_HandleSRPVerifyRespond( int inFd, pairInfo_t* inInfo )
{
  ;
  OSStatus err = 0;
  uint8_t *outTLVResponse = 0;
  unsigned int outTLVResponseLen = 0;
  uint8_t *tlvPtr;
  uint8_t signMFiChallenge[32];
  uint8_t signMFiChallengeSHA[20];
  SHA1Context ctx;
  uint8_t *MFiProof = 0;
  unsigned int  MFiProofLen;
  uint8_t *outCertificatePtr = 0;
  unsigned int outCertificateLen;
  uint8_t *encryptedData = 0;
  unsigned long long encryptedDataLen;
  int i, j;

  uint8_t *httpResponse = 0;
  unsigned int httpResponseLen = 0;

  const uint8_t * bytes_HAMK = 0;

  ;
  err = srp_server_generate_session_key( inInfo->SRPServer, inInfo->SRPControllerPublicKey, inInfo->SRPControllerPublicKeyLen );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

  srp_server_verify_session( inInfo->SRPServer,  inInfo->SRPControllerProof,  &bytes_HAMK );

  if ( !bytes_HAMK ){
    outTLVResponseLen += sizeof(uint8_t) + 2;
    outTLVResponseLen += sizeof(uint8_t) + 2;

    outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
    do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

    tlvPtr = outTLVResponse;
    *tlvPtr++ = 0x06;
    *tlvPtr++ = sizeof(uint8_t);
    *tlvPtr++ = eState_M4_SRPVerifyRespond;

    *tlvPtr++ = 0x07;
    *tlvPtr++ = sizeof(uint8_t);
    *tlvPtr++ = 0x02;
    ;
    haPairSetupState = eState_M1_SRPStartRequest;
  }
  else{
     
    inInfo->HKDF_Key = malloc(32);
    do { if( ! !(!(inInfo->HKDF_Key)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
    err = hkdf(SHA512,  (const unsigned char *)hkdfSetupSalt, strlen(hkdfSetupSalt),
                        inInfo->SRPServer->session_key, inInfo->SRPServer->len_session_key,
                        (const unsigned char *)hkdfSetupInfo, strlen(hkdfSetupInfo), inInfo->HKDF_Key, 32);
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

    if(_haUseMFiAuth == 1){

      err = hkdf(SHA512,  (const unsigned char *)hkdfMFiSalt, strlen(hkdfMFiSalt),
                          inInfo->SRPServer->session_key, inInfo->SRPServer->len_session_key,
                          (const unsigned char *)hkdfMFiInfo, strlen(hkdfMFiInfo), signMFiChallenge, 32);
      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );  
      SHA1Reset( (&ctx) );
      SHA1Input( (&ctx), (signMFiChallenge), (32) );
      SHA1Result( (&ctx), (signMFiChallengeSHA) );

      ;
      err = MicoMFiAuthInitialize( _mfi_cp_port );
      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
      ;
      err =  MicoMFiAuthCreateSignature( signMFiChallengeSHA, 20 , &MFiProof,  &MFiProofLen);
      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
      ;
      err = MicoMFiAuthCopyCertificate( &outCertificatePtr, &outCertificateLen );
      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );


       
      outTLVResponseLen = 0;
      outTLVResponseLen += MFiProofLen + 2;
      for(i = outCertificateLen/255; i>0; i--)
        outTLVResponseLen += 255 + 2;
      outTLVResponseLen += outCertificateLen%255 + 2;

      outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
      do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

      tlvPtr = outTLVResponse;
      *tlvPtr++ = 0x0A;
      *tlvPtr++ = MFiProofLen;
      memcpy(tlvPtr, MFiProof, MFiProofLen);
      tlvPtr+= MFiProofLen;

      j = outCertificateLen/255;
      for(i = 0; i < j; i++){
        *tlvPtr++ = 0x09;
        *tlvPtr++ = 255;
        memcpy( tlvPtr, outCertificatePtr+i*255, 255 );
        tlvPtr += 255;
      }

      *tlvPtr++ = 0x09;
      *tlvPtr++ = outCertificateLen%255;
      memcpy( tlvPtr, outCertificatePtr+255*j, outCertificateLen%255 );
      tlvPtr += outCertificateLen%255;

      encryptedData = calloc(outTLVResponseLen + 16, sizeof(uint8_t));
      do { if( ! !(!(encryptedData)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

      err =  crypto_aead_chacha20poly1305_encrypt(encryptedData, &encryptedDataLen, outTLVResponse, outTLVResponseLen,
                                                  0, 0, 0, (const unsigned char *)AEAD_Nonce_Setup04,
                                                  (const unsigned char *)inInfo->HKDF_Key);

      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; { ; } goto exit; } } while( 1==0 );
      do { if( ! !(!(encryptedDataLen - 16U == outTLVResponseLen)) ) { ; { ; } goto exit; } } while( 1==0 );
      free(outTLVResponse);
      outTLVResponse = 0;

    }

    outTLVResponseLen = 0;
    outTLVResponseLen += sizeof(uint8_t) + 2;
    outTLVResponseLen += inInfo->SRPServer->len_AMK + 2;
    if(_haUseMFiAuth == 1){
      for(i = encryptedDataLen/255; i>0; i--)
        outTLVResponseLen += 255 + 2;
      outTLVResponseLen += encryptedDataLen%255 + 2;
    }

    outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
    do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

    tlvPtr = outTLVResponse;
    *tlvPtr++ = 0x06;
    *tlvPtr++ = sizeof(uint8_t);
    *tlvPtr++ = eState_M4_SRPVerifyRespond;

    *tlvPtr++ = 0x04;
    *tlvPtr++ = inInfo->SRPServer->len_AMK;
    memcpy( tlvPtr, bytes_HAMK, inInfo->SRPServer->len_AMK );
    tlvPtr += inInfo->SRPServer->len_AMK;

    if(_haUseMFiAuth == 1){
      j = encryptedDataLen/255;
      for(i = 0; i < j; i++){
        *tlvPtr++ = 0x05;
        *tlvPtr++ = 255;
        memcpy( tlvPtr, encryptedData+i*255, 255 );
        tlvPtr += 255;
      }

      *tlvPtr++ = 0x05;
      *tlvPtr++ = encryptedDataLen%255;
      memcpy( tlvPtr, encryptedData+255*j, encryptedDataLen%255 );
      tlvPtr += encryptedDataLen%255;
    }

    haPairSetupState = eState_M5_ExchangeRequest;
  }

  err =  CreateSimpleHTTPMessageNoCopy( "application/pairing+tlv8", outTLVResponseLen, &httpResponse, &httpResponseLen );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  err = SocketSend( inFd, httpResponse, httpResponseLen );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  err = SocketSend(inFd, outTLVResponse, outTLVResponseLen);
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

exit:
  if(outTLVResponse) free(outTLVResponse);
  if(encryptedData) free(encryptedData);
  if(httpResponse) free(httpResponse);
  if(MFiProof) free(MFiProof);
  if(outCertificatePtr) free(outCertificatePtr);

  return err;

}

OSStatus _HandleState_WaitingForExchangeRequest( HTTPHeader_t* inHeader, pairInfo_t* inInfo )
{
  ;
  const uint8_t *             src = (const uint8_t *) inHeader->extraDataPtr;
  const uint8_t *             end = src + inHeader->extraDataLen;
  uint8_t                     eid;
  const uint8_t *             ptr;
  unsigned int                      len;
  char *                      tmp;
  OSStatus                    err = 0;
  unsigned char *             encryptedData = 0;
  unsigned long long          encryptedDataLen = 0;
  unsigned char *             authTag = 0;

  unsigned char *             decryptedData = 0;
  unsigned long long          decryptedDataLen = 0;

  char *                      controllerIdentifier = 0;
  unsigned int                      controllerIdentifierLen = 0;
  uint8_t *                   controllerLTPK = 0;

  uint8_t *                   signature = 0;

  uint8_t                     signHKDF[32];

  pair_list_in_flash_t        *pairList = 0;

  while( TLVGetNext( src, end, &eid, &ptr, &len, &src ) == 0 )
  {

    switch( eid )
    {
      case 0x06:
        tmp = calloc( len, sizeof( uint8_t ) );
        do { if( ! !(!(tmp)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
        memcpy( tmp, ptr, len );
        do { if( ! !(!(haPairSetupState == *(uint8_t *)tmp)) ) { ; { err = -6709; } goto exit; } } while( 1==0 );
        free(tmp);
      break;
      case 0x05:
        encryptedData = calloc( len, sizeof( uint8_t ) );
        do { if( ! !(!(encryptedData)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
        memcpy( encryptedData, ptr, len );
        encryptedDataLen = len;
        break;
      default:
        ;
        break;
    }
  }

  decryptedData = malloc( encryptedDataLen-16U );
  do { if( ! !(!(decryptedData)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
  err =  crypto_aead_chacha20poly1305_decrypt(decryptedData, &decryptedDataLen, 0, 
                                              (const unsigned char *)encryptedData, encryptedDataLen, 0, 0,  
                                              (const unsigned char *)AEAD_Nonce_Setup05, (const unsigned char *)inInfo->HKDF_Key);
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; { ; } goto exit; } } while( 1==0 );

  free(encryptedData);
  encryptedData = 0;

    
  src = (const uint8_t *) decryptedData;
  end = src + decryptedDataLen;
  while( TLVGetNext( src, end, &eid, &ptr, &len, &src ) == 0 )
  {
    tmp = calloc( len + 1, sizeof( uint8_t ) ); 
    do { if( ! !(!(tmp)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
    memcpy( tmp, ptr, len );

    switch( eid )
    {
      case 0x01:
        controllerIdentifier = tmp;
        controllerIdentifierLen = len;
        break;
      case 0x03:
        controllerLTPK = (uint8_t *)tmp;
        break;
      case 0x0A:
        signature = (uint8_t *)tmp;
        break;
      default:
        ;
        break;
    }
  }  

  free(decryptedData);
  decryptedData = 0;

   
  err = hkdf(SHA512,  (const unsigned char *)hkdfSetupCSignSalt, strlen(hkdfSetupCSignSalt),
                      inInfo->SRPServer->session_key, inInfo->SRPServer->len_session_key,
                      (const unsigned char *)hkdfSetupCSignInfo, strlen(hkdfSetupCSignInfo), signHKDF, 32);
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );  

  signature = realloc(signature, 64 + 32 + controllerIdentifierLen + 32);
  memcpy(signature+64,    signHKDF, 32);
  memcpy(signature+64+32, controllerIdentifier, controllerIdentifierLen);
  memcpy(signature+64+32+controllerIdentifierLen, controllerLTPK, 32);

  err = crypto_sign_open(0, 0, signature, 64 + 32 + controllerIdentifierLen + 32, controllerLTPK);
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

   
  if(HKPairInfoInsert(controllerIdentifier, controllerLTPK, 1) == -6763)
    inInfo->pairListFull = 1;

  haPairSetupState = eState_M6_ExchangeRespond;

exit:
  if(encryptedData) free(encryptedData);
  if(decryptedData) free(decryptedData);
  if(controllerIdentifier) free(controllerIdentifier);
  if(controllerLTPK) free(controllerLTPK);
  if(signature) free(signature);
  if(authTag) free(authTag);
  if(pairList) free(pairList);
  return err; 
}

OSStatus _HandleState_HandleExchangeRespond( int inFd, pairInfo_t** inInfo )
{
  ;
  OSStatus err = 0;
  uint8_t *outTLVResponse = 0;
  unsigned int outTLVResponseLen = 0;
  uint8_t *tlvPtr;

  uint8_t *httpResponse = 0;
  unsigned int httpResponseLen = 0;
  uint8_t  signHKDF[32];
  uint8_t LTSK[64];
  unsigned char *       encryptedData = 0;
  unsigned long long  encryptedDataLen;
  uint8_t *signature = 0;
  unsigned long long signatureLen;
  uint8_t *XYZ = 0;
  unsigned int XYZLen = 0;
  char *accessoryName = 0;
  mico_system_status_wlan_t *wlan_status;
  mico_system_get_status_wlan( &wlan_status );

  if((*inInfo)->pairListFull == 1){
    ;

    outTLVResponseLen += sizeof(uint8_t) + 2;
    outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
    do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

    tlvPtr = outTLVResponse;
    *tlvPtr++ = 0x07;
    *tlvPtr++ = sizeof(uint8_t);
    *tlvPtr++ = 0x04;
    ;
  }else{

    
    
    
    
    
    

    if((*_key_storage)(LTSK+32, LTSK, 0) != 0){
      err = crypto_sign_keypair(LTSK+32, LTSK);
      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );    
    }

    accessoryName = __strdup_trans_dot(wlan_status->mac);

    err = hkdf(SHA512,  (const unsigned char *)hkdfSetupASignSalt, strlen(hkdfSetupASignSalt),
                      (*inInfo)->SRPServer->session_key, (*inInfo)->SRPServer->len_session_key,
                      (const unsigned char *)hkdfSetupASignInfo, strlen(hkdfSetupASignInfo), signHKDF, 32);
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

     
    XYZLen = 32+strlen(accessoryName)+32;

    signature = calloc(64+XYZLen, sizeof(uint8_t));
    do { if( ! !(!(signature)) ) { ; { err= -6728; } goto exit; } } while( 1==0 );

    XYZ = calloc(XYZLen, sizeof(uint8_t));
    do { if( ! !(!(XYZ)) ) { ; { err= -6728; } goto exit; } } while( 1==0 );

    memcpy(XYZ, signHKDF, 32);
    memcpy(XYZ+32, accessoryName, strlen(accessoryName));
    memcpy(XYZ+32+strlen(accessoryName), LTSK+32, 32);
    
    err = crypto_sign( signature,&signatureLen, XYZ, XYZLen, LTSK );
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
    do { if( ! !(!(signatureLen == 64+XYZLen)) ) { ; goto exit; } } while( 1==0 );

     
    outTLVResponseLen += strlen(accessoryName) + 2; 
    outTLVResponseLen += 32 + 2;  
    outTLVResponseLen += 64 + 2;  

    outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
    do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

    tlvPtr = outTLVResponse;
    *tlvPtr++ = 0x01;
    *tlvPtr++ = strlen(accessoryName);
    memcpy( tlvPtr, accessoryName, strlen(accessoryName) );
    tlvPtr += strlen(accessoryName);
    free(accessoryName);
    accessoryName = 0;

    *tlvPtr++ = 0x03;
    *tlvPtr++ = 32;
    memcpy( tlvPtr, LTSK+32, 32 );
    tlvPtr += 32;

    *tlvPtr++ = 0x0A;
    *tlvPtr++ = 64;
    memcpy( tlvPtr, signature, 64 );

    encryptedData = calloc(outTLVResponseLen + 16, sizeof(uint8_t));

    do { if( ! !(!((*inInfo)->HKDF_Key)) ) { ; { err = -6705; } goto exit; } } while( 1==0 );
    err =  crypto_aead_chacha20poly1305_encrypt(encryptedData, &encryptedDataLen, outTLVResponse, outTLVResponseLen,
                                                0, 0, 0, (const unsigned char *)AEAD_Nonce_Setup06,
                                                (const unsigned char *)(*inInfo)->HKDF_Key);

    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; { ; } goto exit; } } while( 1==0 );
    do { if( ! !(!(encryptedDataLen - 16U == outTLVResponseLen)) ) { ; { ; } goto exit; } } while( 1==0 );
    free(outTLVResponse);
    outTLVResponse = 0;

     
    outTLVResponseLen = 0;
    outTLVResponseLen += sizeof(uint8_t) + 2;
    outTLVResponseLen += encryptedDataLen + 2;

    outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
    do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

    tlvPtr = outTLVResponse;
    *tlvPtr++ = 0x06;
    *tlvPtr++ = sizeof(uint8_t);
    *tlvPtr++ = eState_M6_ExchangeRespond;

    *tlvPtr++ = 0x05;
    *tlvPtr++ = encryptedDataLen;
    memcpy( tlvPtr, encryptedData, encryptedDataLen);
  }

  haPairSetupState = eState_M1_SRPStartRequest;

  err =  CreateSimpleHTTPMessageNoCopy( "application/pairing+tlv8", outTLVResponseLen, &httpResponse, &httpResponseLen );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  err = SocketSend( inFd, httpResponse, httpResponseLen );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  err = SocketSend(inFd, outTLVResponse, outTLVResponseLen);
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

   
  if((*inInfo)->pairListFull != 1){
    
    
    err = (*_key_storage)(LTSK+32, LTSK, 1);
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  }
  haPairSetupState = eState_M1_SRPStartRequest;
  HKCleanPairSetupInfo( inInfo );
  _haPairSetupRunning = 0;

exit:
  if(outTLVResponse) free(outTLVResponse);
  if(httpResponse) free(httpResponse);
  if(signature) free(signature);
  if(accessoryName) free(accessoryName);
  if(XYZ) free(XYZ);
  if(encryptedData) free(encryptedData);
  return err;

}


OSStatus HKPairVerifyEngine( int inFd, HTTPHeader_t* inHeader, pairVerifyInfo_t* inInfo )
{
  OSStatus err = 0;
  do { if( ! !(!(inInfo)) ) { ; { err = -6745; } goto exit; } } while( 1==0 );

  switch ( inInfo->haPairVerifyState ){
    case eState_M1_VerifyStartRequest:
      err = _HandleState_WaitingForVerifyStartRequest( inHeader, inInfo );
      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; { inInfo->haPairVerifyState = eState_M1_VerifyStartRequest; } goto exit; } } while( 1==0 );
      err =  _HandleState_WaitingForVerifyStartRespond( inFd , inInfo );
      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; { inInfo->haPairVerifyState = eState_M1_VerifyStartRequest; } goto exit; } } while( 1==0 );
      break;

    case eState_M3_VerifyFinishRequest:
      err = _HandleState_WaitingForVerifyFinishRequest( inHeader, inInfo );
      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; { inInfo->haPairVerifyState = eState_M1_VerifyStartRequest; } goto exit; } } while( 1==0 );
      err = _HandleState_WaitingForVerifyFinishRespond(inFd , inInfo );
      do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; { inInfo->haPairVerifyState = eState_M1_VerifyStartRequest; } goto exit; } } while( 1==0 );
      break;

    default:
      ;
      err = -6709;
  }

exit:
  return err;
}


OSStatus _HandleState_WaitingForVerifyStartRequest( HTTPHeader_t* inHeader, pairVerifyInfo_t* inInfo )
{
  ;
  OSStatus                    err = 0;
  const uint8_t *             src = (const uint8_t *) inHeader->extraDataPtr;
  const uint8_t * const       end = src + inHeader->extraDataLen;
  uint8_t                     eid;
  const uint8_t *             ptr;
  unsigned int                      len;
  char *                      tmp = 0;

  while( TLVGetNext( src, end, &eid, &ptr, &len, &src ) == 0 )
  {
    tmp = calloc( len+1, sizeof( uint8_t ) );
    do { if( ! !(!(tmp)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
    memcpy( tmp, ptr, len );

    switch( eid )
    {
      case 0x06:
        do { if( ! !(!(inInfo->haPairVerifyState == *(uint8_t *)tmp)) ) { ; { err = -6709; } goto exit; } } while( 1==0 );
        free(tmp);
        break;
      case 0x03:
        inInfo->pControllerCurve25519PK = (uint8_t *)tmp;
        break;
      default:
        ;
        break;
    }
  }
  inInfo->haPairVerifyState = eState_M2_VerifyStartRespond;

exit:
  return err;
}

OSStatus _HandleState_WaitingForVerifyStartRespond(int inFd, pairVerifyInfo_t* inInfo )
{
  ;
  OSStatus            err = 0;
  uint8_t             *outTLVResponse = 0;
  unsigned int              outTLVResponseLen = 0;
  uint8_t             *tlvPtr;
  uint8_t             *httpResponse = 0;
  unsigned int              httpResponseLen = 0;
  uint8_t             *ABC = 0;
  unsigned int              ABCLen = 0;
  uint8_t             *signature = 0;
  unsigned long long  signatureLen = 0;
  unsigned char       *encryptedData = 0;
  unsigned long long  encryptedDataLen = 0;
  char                *accessoryName = 0;
  mico_system_status_wlan_t  *wlan_status;
  uint8_t             LTSK[64];

  mico_system_get_status_wlan( &wlan_status );

  inInfo->pAccessoryCurve25519PK = malloc(32);
  do { if( ! !(!(inInfo->pAccessoryCurve25519PK)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
  inInfo->pAccessoryCurve25519SK = malloc(32);
  do { if( ! !(!(inInfo->pAccessoryCurve25519SK)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
  inInfo->pSharedSecret = malloc(32);
  do { if( ! !(!(inInfo->pSharedSecret)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
  inInfo->pHKDFKey = malloc(32);
  do { if( ! !(!(inInfo->pHKDFKey)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );


   
  err = MicoRandomNumberRead( inInfo->pAccessoryCurve25519SK, 32 );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  curve25519_donna( inInfo->pAccessoryCurve25519PK, inInfo->pAccessoryCurve25519SK, 0 );

   
  curve25519_donna( inInfo->pSharedSecret, inInfo->pAccessoryCurve25519SK, inInfo->pControllerCurve25519PK );

   
  accessoryName = __strdup_trans_dot(wlan_status->mac);

  ABCLen = 32+strlen(accessoryName)+32;

  ABC = calloc(ABCLen, sizeof(uint8_t));
  do { if( ! !(!(ABC)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

  signature = calloc(64+ABCLen, sizeof(uint8_t));
  do { if( ! !(!(signature)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

  memcpy(ABC,                           inInfo->pAccessoryCurve25519PK,   32);
  memcpy(ABC+32,                        accessoryName,                    strlen(accessoryName));
  memcpy(ABC+32+strlen(accessoryName),  inInfo->pControllerCurve25519PK,  32);

  (*_key_storage)( LTSK+32, LTSK, 0 );

  err = crypto_sign(signature,&signatureLen, ABC, ABCLen, LTSK );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  free(ABC);
  ABC = 0;

   
  outTLVResponseLen = 0;
  outTLVResponseLen += strlen(accessoryName) + 2;
  outTLVResponseLen += 64 + 2;

  outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
  do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
  tlvPtr = outTLVResponse;

  *tlvPtr++ = 0x01;
  *tlvPtr++ = strlen(accessoryName);
  memcpy(tlvPtr, accessoryName, strlen(accessoryName));
  tlvPtr += strlen(accessoryName);
  free(accessoryName);
  accessoryName = 0;

  *tlvPtr++ = 0x0A;
  *tlvPtr++ = 64;
  memcpy( tlvPtr, signature, 64 );
  free(signature);
  signature = 0;

   
  err = hkdf(SHA512,  (const unsigned char *) hkdfVerifySalt, strlen(hkdfVerifySalt),
                      inInfo->pSharedSecret, 32,
                      (const unsigned char *)hkdfVerifyInfo, strlen(hkdfVerifyInfo), inInfo->pHKDFKey, 32);
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

   
  encryptedData = calloc(outTLVResponseLen+16, sizeof(uint8_t));
  do { if( ! !(!(encryptedData)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

  err =  crypto_aead_chacha20poly1305_encrypt(encryptedData, &encryptedDataLen, outTLVResponse, outTLVResponseLen,
                                              0, 0, 0, (const unsigned char *)AEAD_Nonce_Verify02,
                                              (const unsigned char *)inInfo->pHKDFKey);

  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; { ; } goto exit; } } while( 1==0 );
  do { if( ! !(!(encryptedDataLen - 16U == outTLVResponseLen)) ) { ; { ; } goto exit; } } while( 1==0 );
  free(outTLVResponse);
  outTLVResponse = 0;

   
  outTLVResponseLen = 0;
  outTLVResponseLen += sizeof(uint8_t) + 2;
  outTLVResponseLen += 32 + 2;
  outTLVResponseLen += encryptedDataLen + 2;

  outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
  do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

  tlvPtr = outTLVResponse;
  *tlvPtr++ = 0x06;
  *tlvPtr++ = sizeof(uint8_t);
  *tlvPtr++ = eState_M2_VerifyStartRespond;

  *tlvPtr++ = 0x03;
  *tlvPtr++ = 32;
  memcpy( tlvPtr, inInfo->pAccessoryCurve25519PK, 32);
  tlvPtr += 32;

  *tlvPtr++ = 0x05;
  *tlvPtr++ = encryptedDataLen;
  memcpy( tlvPtr, encryptedData, encryptedDataLen );

  err =  CreateSimpleHTTPMessageNoCopy( "application/pairing+tlv8", outTLVResponseLen, &httpResponse, &httpResponseLen );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  err = SocketSend( inFd, httpResponse, httpResponseLen );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  err = SocketSend(inFd, outTLVResponse, outTLVResponseLen);
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  inInfo->haPairVerifyState = eState_M3_VerifyFinishRequest;

exit:
  if(accessoryName) free(accessoryName);
  if(ABC) free(ABC);
  if(signature) free(signature);
  if(encryptedData) free(encryptedData);
  if(outTLVResponse) free(outTLVResponse);
  if(httpResponse) free(httpResponse);
  return err;
}

OSStatus _HandleState_WaitingForVerifyFinishRequest(HTTPHeader_t* inHeader, pairVerifyInfo_t* inInfo )
{
  ;
  OSStatus                    err = 0;
  const uint8_t *             src = (const uint8_t *) inHeader->extraDataPtr;
  const uint8_t *             end = src + inHeader->extraDataLen;
  uint8_t                     eid;
  const uint8_t *             ptr;
  unsigned int                      len;
  char *                      tmp = 0;
  uint8_t *                   encryptedData = 0;
  unsigned int                      encryptedDataLen = 0;
  uint8_t *                   decryptedData = 0;
  unsigned long long          decryptedDataLen = 0;
  uint8_t *                   signature = 0;
  char *                      controllerIdentifier = 0;
  unsigned int                      controllerIdentifierLen = 0;

  while( TLVGetNext( src, end, &eid, &ptr, &len, &src ) == 0 )
  {
    tmp = calloc( len, sizeof( uint8_t ) );
    do { if( ! !(!(tmp)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
    memcpy( tmp, ptr, len );

    switch( eid )
    {
      case 0x06:
        do { if( ! !(!(inInfo->haPairVerifyState == *(uint8_t *)tmp)) ) { ; { err = -6709; } goto exit; } } while( 1==0 );
        free(tmp);
        break;
      case 0x05:
        encryptedData = (uint8_t *)tmp;
        encryptedDataLen = len;
        break;
      default:
        ;
        break;
    }
  }

  decryptedData = malloc( encryptedDataLen-16U );
  do { if( ! !(!(decryptedData)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
  err =  crypto_aead_chacha20poly1305_decrypt(decryptedData, &decryptedDataLen, 0, 
                                              (const unsigned char *)encryptedData, encryptedDataLen, 0, 0,  
                                              (const unsigned char *)AEAD_Nonce_Verify03, (const unsigned char *)inInfo->pHKDFKey);
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; { ; } goto exit; } } while( 1==0 );

  src = (const uint8_t *) decryptedData;
  end = src + decryptedDataLen;
  while( TLVGetNext( src, end, &eid, &ptr, &len, &src ) == 0 )
  {
    tmp = calloc( len+1, sizeof( uint8_t ) ); 
    do { if( ! !(!(tmp)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
    memcpy( tmp, ptr, len );

    switch( eid )
    {
      case 0x01:
        controllerIdentifier = tmp;
        HKPairInfoFindByName(controllerIdentifier, inInfo->pControllerLTPK, 0 );
        inInfo->pControllerIdentifier = malloc(len+1);
        memcpy(inInfo->pControllerIdentifier, tmp, len+1);
        controllerIdentifierLen = len;
        break;
      case 0x0A:
        signature = (uint8_t *)tmp;
        break;
      default:
        ;
        break;
    }
  }

  signature = realloc(signature, 64 + 32 + controllerIdentifierLen + 32);
  do { if( ! !(!(signature)) ) { ; { err= -6728; } goto exit; } } while( 1==0 );
  memcpy(signature+64,                            inInfo->pControllerCurve25519PK,  32);
  memcpy(signature+64+32,                         controllerIdentifier,             controllerIdentifierLen);
  memcpy(signature+64+32+controllerIdentifierLen, inInfo->pAccessoryCurve25519PK,   32);

  err = crypto_sign_open(0, 0, signature, 64 + 32 + controllerIdentifierLen + 32, inInfo->pControllerLTPK);
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  ;

exit:
  if(encryptedData) free(encryptedData);
  if(decryptedData) free(decryptedData);
  if(controllerIdentifier) free(controllerIdentifier);
  if(signature) free(signature);
  return err;
}

OSStatus _HandleState_WaitingForVerifyFinishRespond(int inFd, pairVerifyInfo_t* inInfo )
{
  ;
  OSStatus err = 0;
  uint8_t *outTLVResponse = 0;
  unsigned int outTLVResponseLen = 0;
  uint8_t *tlvPtr;

  uint8_t *httpResponse = 0;
  unsigned int httpResponseLen = 0;

  outTLVResponseLen += sizeof(uint8_t) + 2;

  outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
  do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

  tlvPtr = outTLVResponse;
  *tlvPtr++ = 0x06;
  *tlvPtr++ = sizeof(uint8_t);
  *tlvPtr++ = eState_M4_SRPVerifyRespond;

  inInfo->verifySuccess = 1;
  inInfo->A2CKey = malloc(32);
  do { if( ! !(!(inInfo->A2CKey)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
  err = hkdf(SHA512,  (const unsigned char *) hkdfA2CKeySalt, strlen(hkdfA2CKeySalt),
                            inInfo->pSharedSecret, 32,
                            (const unsigned char *)hkdfA2CInfo, strlen(hkdfA2CInfo), inInfo->A2CKey, 32);
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

  inInfo->C2AKey = malloc(32);
  do { if( ! !(!(inInfo->C2AKey)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
  err = hkdf(SHA512,  (const unsigned char *) hkdfC2AKeySalt, strlen(hkdfC2AKeySalt),
                            inInfo->pSharedSecret, 32,
                            (const unsigned char *)hkdfC2AInfo, strlen(hkdfC2AInfo), inInfo->C2AKey, 32);
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

  err =  CreateSimpleHTTPMessageNoCopy( "application/pairing+tlv8", outTLVResponseLen, &httpResponse, &httpResponseLen );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  err = SocketSend( inFd, httpResponse, httpResponseLen );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  err = SocketSend( inFd, outTLVResponse, outTLVResponseLen );
  do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

exit:
  if(outTLVResponse) free(outTLVResponse);
  if(httpResponse) free(httpResponse);
  return err;
}

OSStatus HKSendPairResponseMessage(int sockfd, int status, uint8_t *payload, int payloadLen, security_session_t *session )
{
  OSStatus err;
  uint8_t *httpResponse = 0;
  unsigned int httpResponseLen = 0;
  const char *buffer = 0;
  int bufferLen;

  buffer = (const char *)payload;
  bufferLen = payloadLen;

  err = CreateHTTPRespondMessageNoCopy( status, "application/pairing+tlv8", bufferLen, &httpResponse, &httpResponseLen );

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

OSStatus HKPairAddRemoveEngine( int inFd, HTTPHeader_t* inHeader, security_session_t *session  )
{
  ;
  OSStatus err = 0;
  uint8_t methold = Pair_Unknown;
  char *                      controllerIdentifier = 0;
  uint8_t *                   controllerLTPK = 0;
  uint32_t        permissions = 0x0;
  uint32_t i;
  uint8_t *httpResponse = 0;
  uint8_t *outTLVResponse = 0;
  unsigned int outTLVResponseLen = 0;
  uint8_t *tlvPtr;
  _Bool needSeparator = 0;
  char foundIdentifier[64];
  uint8_t foundControllerLTPK[32];
  _Bool permission;

  const uint8_t *             src = (const uint8_t *) inHeader->extraDataPtr;
  const uint8_t * const       end = src + inHeader->extraDataLen;
  uint8_t                     eid;
  const uint8_t *             ptr;
  unsigned int                      len;
  char *                      tmp;
  _Bool                        isAdmin = 0;
  uint32_t                    pairedCount = 0;

  while( TLVGetNext( src, end, &eid, &ptr, &len, &src ) == 0 )
  {
    tmp = calloc( len + 1, sizeof( uint8_t ) );
    do { if( ! !(!(tmp)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );
    memcpy( tmp, ptr, len );

    switch( eid )
    {
      case 0x06:
        do { if( ! !(!(1 == *(uint8_t *)tmp)) ) { ; { err = -6709; } goto exit; } } while( 1==0 );
        free(tmp);
        break;
      case 0x00:
        methold = *(uint8_t *)tmp;
        free(tmp);
        break;
      case 0x01:
        controllerIdentifier = tmp;
        break;
      case 0x03:
        controllerLTPK = (uint8_t *)tmp;
        break;
      case 0x0B:
        permissions = *(uint8_t *)tmp;
        free(tmp);
        break;
      default:
        free( tmp );
        ;
        break;
    }
  }
  
  HKPairInfoFindByName(session->controllerIdentifier, 0, &isAdmin );

  if( isAdmin == 0){ 
        outTLVResponseLen += sizeof(uint8_t) + 2;
        outTLVResponseLen += sizeof(uint8_t) + 2;

        outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
        do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

        tlvPtr = outTLVResponse;
        *tlvPtr++ = 0x06;
        *tlvPtr++ = sizeof(uint8_t);
        *tlvPtr++ = eState_M2_PairingRespond;

        *tlvPtr++ = 0x07;
        *tlvPtr++ = sizeof(uint8_t);
        *tlvPtr++ = 0x01;

        err = HKSendPairResponseMessage(inFd, 200, outTLVResponse, outTLVResponseLen, session );
        goto exit;        
      }

  if(methold == Pair_Add){
    do { if( ! !(!(controllerIdentifier && controllerLTPK)) ) { ; { err = -6705; } goto exit; } } while( 1==0 );

    if(HKPairInfoInsert(controllerIdentifier, controllerLTPK, (permissions&0x1)) == -6763){
      outTLVResponseLen += sizeof(uint8_t) + 2;
      outTLVResponseLen += sizeof(uint8_t) + 2;

      outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
      do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

      tlvPtr = outTLVResponse;
      *tlvPtr++ = 0x06;
      *tlvPtr++ = sizeof(uint8_t);
      *tlvPtr++ = eState_M2_PairingRespond;

      *tlvPtr++ = 0x07;
      *tlvPtr++ = sizeof(uint8_t);
      *tlvPtr++ = 0x04;

      err = HKSendPairResponseMessage(inFd, 200, outTLVResponse, outTLVResponseLen, session );
      goto exit;
    }

    outTLVResponseLen += sizeof(uint8_t) + 2;

    outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
    do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

    tlvPtr = outTLVResponse;
    *tlvPtr++ = 0x06;
    *tlvPtr++ = sizeof(uint8_t);
    *tlvPtr++ = eState_M2_PairingRespond;

    err = HKSendPairResponseMessage(inFd, 200, outTLVResponse, outTLVResponseLen, session );
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

  }else if(methold == Pair_List){ 
    pairedCount = HKPairInfoCount();

    outTLVResponseLen += sizeof(uint8_t) + 2; 

    needSeparator = 0;
    for(i=0; i<pairedCount; i++){
      HKPairInfoFindByIndex(i, foundIdentifier, foundControllerLTPK, &permission );
      
      if(needSeparator)
        outTLVResponseLen += 2; 
      else
        needSeparator = 1;
      outTLVResponseLen += strlen(foundIdentifier) + 2; 
      outTLVResponseLen += 32 + 2;  
      outTLVResponseLen += sizeof(uint8_t) + 2;  
    }

    outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
    do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

    tlvPtr = outTLVResponse;
    *tlvPtr++ = 0x06;
    *tlvPtr++ = sizeof(uint8_t);
    *tlvPtr++ = eState_M2_PairingRespond;

    needSeparator = 0;
    for(i=0; i < pairedCount; i++){

    
    HKPairInfoFindByIndex(i, foundIdentifier, foundControllerLTPK, &permission );


      if(needSeparator){
        *tlvPtr++ = 0xFF;
        *tlvPtr++ = 0x0;
      }
      else
        needSeparator = 1;

      *tlvPtr++ = 0x01;
      *tlvPtr++ = strlen(foundIdentifier);
      strncpy((char *)tlvPtr, foundIdentifier, strlen(foundIdentifier));
      tlvPtr+= strlen(foundIdentifier);

      *tlvPtr++ = 0x03;
      *tlvPtr++ = 32;
      memcpy(tlvPtr, foundControllerLTPK, 32);
      tlvPtr+= 32;

      *tlvPtr++ = 0x0B;
      *tlvPtr++ = sizeof(uint8_t);
      *tlvPtr++= permission;
    }

    err = HKSendPairResponseMessage(inFd, 200, outTLVResponse, outTLVResponseLen, session );
    
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );
  }else if(methold == Pair_Remove){
    do { if( ! !(!(controllerIdentifier)) ) { ; { err = -6705; } goto exit; } } while( 1==0 );

    if( HKPairInfoRemove(controllerIdentifier) != 0 ){ 
      hk_bonjour_update_status_flag( );

      outTLVResponseLen += sizeof(uint8_t) + 2;
      outTLVResponseLen += sizeof(uint8_t) + 2;

      outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
      do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

      tlvPtr = outTLVResponse;
      *tlvPtr++ = 0x06;
      *tlvPtr++ = sizeof(uint8_t);
      *tlvPtr++ = eState_M2_PairingRespond;

      *tlvPtr++ = 0x07;
      *tlvPtr++ = sizeof(uint8_t);
      *tlvPtr++ = 0x01;

      err = HKSendPairResponseMessage(inFd, 200, outTLVResponse, outTLVResponseLen, session );
      goto exit;    
    }

    outTLVResponseLen += sizeof(uint8_t) + 2;

    outTLVResponse = calloc( outTLVResponseLen, sizeof( uint8_t ) );
    do { if( ! !(!(outTLVResponse)) ) { ; { err = -6728; } goto exit; } } while( 1==0 );

    tlvPtr = outTLVResponse;
    *tlvPtr++ = 0x06;
    *tlvPtr++ = sizeof(uint8_t);
    *tlvPtr++ = eState_M2_PairingRespond;

    err = HKSendPairResponseMessage(inFd, 200, outTLVResponse, outTLVResponseLen, session );
    
    do { OSStatus localErr; localErr = (OSStatus)(err); if( ! !(localErr != 0) ) { ; goto exit; } } while( 1==0 );

  }else{
    err = -1;
    HKSendResponseMessage(inFd, 400, 0, 0, session);
    mico_rtos_delay_milliseconds(100);
    goto exit;
  }

exit: 
  if(outTLVResponse) free(outTLVResponse);
  if(controllerIdentifier)  free(controllerIdentifier);
  if(controllerLTPK)  free(controllerLTPK);
  if(httpResponse) free(httpResponse);
  ;
  return err;
}

int verify_otp(void)
{
  return 1;
}
