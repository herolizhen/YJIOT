#include "SOFT_IIC.h"

#include "sensor.h"

/*
void Set_SDA_Pin_Mode(unsigned char mode)
{
    if(mode == PIN_INPUT)
    {
        //PIN设置为输入时，PxM0对应的位置0，PxM1对应的位置1
        SOFT_IIC_PxM0 &= ~(1 << SOFT_IIC_SDA_PORTBIT);
        SOFT_IIC_PxM1 |= ((1 << SOFT_IIC_SDA_PORTBIT));
    }
    else if(mode == PIN_OUTPUT)
    {      
        SOFT_IIC_PxM0 &= ~(1 << SOFT_IIC_SDA_PORTBIT);
        SOFT_IIC_PxM1 &= ~(1 << SOFT_IIC_SDA_PORTBIT);
    }
}

void Set_SCL_Pin_Mode(unsigned char mode)
{
    if(mode == PIN_INPUT)
    {
        //PIN设置为输入时，PxM0对应的位置0，PxM1对应的位置1
        SOFT_IIC_PxM0 &= ~(1 << SOFT_IIC_SCL_PORTBIT);
        SOFT_IIC_PxM1 |= ((1 << SOFT_IIC_SCL_PORTBIT));
    }
    else if(mode == PIN_OUTPUT)
    {      
        SOFT_IIC_PxM0 &= ~(1 << SOFT_IIC_SCL_PORTBIT);
        SOFT_IIC_PxM1 &= ~(1 << SOFT_IIC_SCL_PORTBIT);     
    }
}

void Soft_IIC_PinConifg(void)
{
    //PIN设置为推挽输出，PxM0对应的位置1，PxM1对应的位置0  
    SOFT_IIC_PxM0 &= ~((1 << SOFT_IIC_SDA_PORTBIT) | (1 << SOFT_IIC_SCL_PORTBIT));
    SOFT_IIC_PxM1 &= ~((1 << SOFT_IIC_SDA_PORTBIT) | (1 << SOFT_IIC_SCL_PORTBIT));
  
    SOFT_IIC_SCL_PIN = 1;
    SOFT_IIC_SDA_PIN = 1;
}

#define IIC_DELAY_COUNT  10

static void i2c_delay(void)
{
	int i = 0;
	for(i = 0;i < IIC_DELAY_COUNT;i++);
}

*/

IIC_Operations_Typedef IIC_Operations;

static void i2c_delay1(unsigned int num)
{
	int i = 0;
	for(i = 0;i < num;i++);
}



//**********启动读写时序子函数**********
void I2C_start(void)
{
  IIC_Operations.Set_SDA_Pin_Mode(PIN_OUTPUT);
	IIC_Operations.SDA_1();
	IIC_Operations.i2c_delay();
	IIC_Operations.SCL_1();
	IIC_Operations.i2c_delay();
	IIC_Operations.SDA_0();
	IIC_Operations.i2c_delay();
	IIC_Operations.SCL_0();
	IIC_Operations.i2c_delay();
}


//**********停止操作子函数**********
void I2C_stop(void)
{
  IIC_Operations.Set_SDA_Pin_Mode(PIN_OUTPUT);
	IIC_Operations.SDA_0();
	IIC_Operations.i2c_delay();
	IIC_Operations.SCL_1();
	IIC_Operations.i2c_delay();
	IIC_Operations.SDA_1();
	IIC_Operations.i2c_delay();
	
}

/*
*********************************************************************************************************
*	函 数 名: i2c_WaitAck
*	功能说明: CPU产生一个时钟，并读取器件的ACK应答信号
*	形    参：无
*	返 回 值: 返回0表示正确应答，1表示无器件响应
*********************************************************************************************************
*/
unsigned char I2C_WaitAck(void)
{
	unsigned char re = 0;
  
	IIC_Operations.SDA_1();	/* CPU释放SDA总线 */
	
  IIC_Operations.Set_SDA_Pin_Mode(PIN_INPUT);
  
	IIC_Operations.i2c_delay();
	IIC_Operations.SCL_1();	/* CPU驱动SCL = 1, 此时器件会返回ACK应答 */
	IIC_Operations.i2c_delay();
	
	if (IIC_Operations.I2C_SDA_READ())	/* CPU读取SDA口线状态 */
	{
		re = 1;
	}
	else
	{
		re = 0;
	}
	IIC_Operations.SCL_0();
	IIC_Operations.i2c_delay();
	return re;
}

/*响应*/
void I2C_Ack(void)
{
  IIC_Operations.Set_SDA_Pin_Mode(PIN_OUTPUT);
	IIC_Operations.SDA_0();	/* CPU驱动SDA = 0 */
	IIC_Operations.i2c_delay();
	IIC_Operations.SCL_1();	/* CPU产生1个时钟 */
	IIC_Operations.i2c_delay();
	IIC_Operations.SCL_0();
	IIC_Operations.i2c_delay();
	IIC_Operations.SDA_1();	/* CPU释放SDA总线 */
}


/*
*********************************************************************************************************
*	函 数 名: i2c_NAck
*	功能说明: CPU产生1个NACK信号
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void I2C_NAck(void)
{
  IIC_Operations.Set_SDA_Pin_Mode(PIN_OUTPUT);
	IIC_Operations.SDA_1();	/* CPU驱动SDA = 1 */
	IIC_Operations.i2c_delay();
	IIC_Operations.SCL_1();	/* CPU产生1个时钟 */
	IIC_Operations.i2c_delay();
	IIC_Operations.SCL_0();
	IIC_Operations.i2c_delay();	
}



//**********写入8位子函数**********
void I2C_SendOneByte(unsigned char a)
{
	unsigned char temp;
	unsigned char i, j;

  IIC_Operations.Set_SDA_Pin_Mode(PIN_OUTPUT);
	temp = a;
	for(i=0;i<8;i++)
	{
	    j=temp&0x80;
		if(j==0)
		{
			IIC_Operations.SDA_0();
		}
		else
		{
			IIC_Operations.SDA_1();
		}
		IIC_Operations.SCL_1();
		IIC_Operations.i2c_delay();
		IIC_Operations.SCL_0();
    IIC_Operations.i2c_delay();
		temp = temp<<1;
	}
  
}


unsigned char I2C_ReadOneByte(void)
{
	unsigned char i;
	unsigned char value;

	/* 读到第1个bit为数据的bit7 */
	value = 0;
  IIC_Operations.Set_SDA_Pin_Mode(PIN_INPUT);
	for (i = 0; i < 8; i++)
	{
		value <<= 1;
		IIC_Operations.SCL_1();
		IIC_Operations.i2c_delay();
		if (IIC_Operations.I2C_SDA_READ())
		{
			value |= 1;
		}
		IIC_Operations.SCL_0();
    IIC_Operations.i2c_delay();
	}
	return value;
}





/**
  * @brief   使用IIC读取数据
  * @param   
  * 	@arg ClientAddr:从设备地址
  *		@arg pBuffer:存放由从机读取的数据的缓冲区指针
  *		@arg readAddr:表示读取从设备哪个寄存器的数据
  *		@arg NumByteToRead:读取的数据长度
  * @retval  无
  */
unsigned int I2C_ReadBytes(unsigned char ClientAddr, unsigned char* pBuffer,unsigned int NumByteToRead)
{
	
	/* 第1步：发起I2C总线启动信号 */
	I2C_start();
	
	/* 第2步：发起控制字节，高7bit是地址，bit0是读写控制位，0表示写，1表示读 */
	I2C_SendOneByte((ClientAddr << 1) | I2C_DIR_RD);	/* 此处是读指令 */
  	
	/* 第3步：等待ACK */
	if (I2C_WaitAck() != 0)
	{
		goto cmd_fail;	/* 器件无应答 */
	}

	while(NumByteToRead) 
	{
     
     if(IIC_Operations.IIC_NUM == TOUCH_KEY_IIC)
     {
       //跟触摸芯片通讯每发送或者接收完一个字节后必须延时较长的时间，否则通讯会出问题
       i2c_delay1(100);   
     }
     else if(IIC_Operations.IIC_NUM == HPD05_IIC)
     {
       i2c_delay1(10);
     }
     
    
		*pBuffer = I2C_ReadOneByte();
    
		/* 读指针自增 */
		pBuffer++; 
      
		/*计数器自减 */
		NumByteToRead--;

		if (NumByteToRead == 0)
		{
			I2C_NAck();	/* 最后1个字节读完后，CPU产生NACK信号(驱动SDA = 1) */

			/* 发送I2C总线停止信号 */
			//I2C_stop();
			break;
		}
    
		I2C_Ack();	/* 中间字节读完后，CPU产生ACK信号(驱动SDA = 0) */ 

 
  }

	/* 发送I2C总线停止信号 */
	I2C_stop();
	return 0;	/* 执行成功 */

cmd_fail: /* 命令执行失败后，切记发送停止信号，避免影响I2C总线上其他设备 */
	/* 发送I2C总线停止信号 */
	I2C_stop();
	return 1;
}


/**
  * @brief   使用IIC写入数据
  * @param   
  * 	@arg ClientAddr:从设备地址
  *		@arg pBuffer:缓冲区指针
  *     @arg NumByteToWrite:写的字节数
  * @retval  无
  */
unsigned int I2C_WriteBytes(unsigned char ClientAddr, unsigned char* pBuffer, unsigned int NumByteToWrite)
{
	//unsigned int m;	

  /*　第0步：发停止信号，启动内部写操作　*/
  I2C_stop();
  
  /* 通过检查器件应答的方式，判断内部写操作是否完成, 一般小于 10ms 			
    CLK频率为200KHz时，查询次数为30次左右
  */		
    /* 第1步：发起I2C总线启动信号 */
    I2C_start();
    
    /* 第2步：发起控制字节，高7bit是地址，bit0是读写控制位，0表示写，1表示读 */
    I2C_SendOneByte((ClientAddr << 1) | I2C_DIR_WR);	/* 此处是写指令 */
    
    /* 第3步：发送一个时钟，判断器件是否正确应答 */
    if (I2C_WaitAck() == 0)
    {
      //break;
    }
	  else
	 {
		  goto cmd_fail;
	 }
  
	
  while(NumByteToWrite)
  {
     if(IIC_Operations.IIC_NUM == TOUCH_KEY_IIC)
     {
       //跟触摸芯片通讯每发送或者接收完一个字节后必须延时较长的时间，否则通讯会出问题
       i2c_delay1(100);   
     }
     else if(IIC_Operations.IIC_NUM == HPD05_IIC)
     {
       i2c_delay1(10);
     }
	    /* 第4步：开始写入数据 */
      I2C_SendOneByte(*pBuffer);

      /* 第5步：检查ACK */
      if (I2C_WaitAck() != 0)
      {
          goto cmd_fail;	/* 器件无应答 */
      }
      
      NumByteToWrite--;
      
      if(NumByteToWrite == 0)
      {
          goto end;
      }
      
      pBuffer++;	/* 地址增1 */		
      
     
  }
	
	/* 命令执行成功，发送I2C总线停止信号 */
end:
  i2c_delay1(60);
  I2C_stop();
  return 0;

cmd_fail: /* 命令执行失败后，切记发送停止信号，避免影响I2C总线上其他设备 */
	/* 发送I2C总线停止信号 */
  I2C_stop();
  return 1;
}


