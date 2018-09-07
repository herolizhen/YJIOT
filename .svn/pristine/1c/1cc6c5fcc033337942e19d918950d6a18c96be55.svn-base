#include "OB39R32T1.h"
#include "INT.h"
#include "global.h"
#include "TM1620.h"


//void Start_INT1(void)
//{
//    EA = 1; 
//    //设置为下降沿触发
//    EX1 = 1;
//    IT1 = 1;  
//    
//      

//}




//void INT1_ISR(void) interrupt d_INT1_Vector
//{
//    FGcount++;


//}



void Start_INT3(void)
{
    EA = 1; 
    //设置为下降沿触发
    //EX3 = 1;
    IEN2 |= (1 << 2);
    IT3 = 1;  
    
      

}




void INT3_ISR(void) interrupt d_INT3_Vector
{
    //static unsigned char i = 0;
  
    FGcount++;
  
//    i++;
//    if(i % 10 == 0)
//    {
//        TM1620_DispalyData(2,i);
//    }


}