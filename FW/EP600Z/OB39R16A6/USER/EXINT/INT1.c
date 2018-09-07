#include "OB39R16A6.h"
#include "INT1.h"
#include "global.h"



void Start_INT1(void)
{
    EA = 1; 
    //设置为下降沿触发
    EX1 = 1;
    IT1 = 1;  
    
      

}




void INT1_ISR(void) interrupt d_INT1_Vector
{
    FGcount++;


}