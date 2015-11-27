/*
 * (C) Copyright 2011 Samsung Electronics Co. Ltd
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#include <common.h>
#include <asm/arch/pmic.h>

#ifdef CONFIG_AXP221_PMU
extern int use_axp_flag;
extern void axp221_pmic_init(void);
#endif
void Delay(void)
{
	unsigned long i;
	for(i=0;i<DELAY;i++);
}

#ifndef CONFIG_UT_OEM

void IIC0_SCLH_SDAH(void)
{
	IIC0_ESCL_Hi;
	IIC0_ESDA_Hi;
	Delay();
}

void IIC0_SCLH_SDAL(void)
{
	IIC0_ESCL_Hi;
	IIC0_ESDA_Lo;
	Delay();
}

void IIC0_SCLL_SDAH(void)
{
	IIC0_ESCL_Lo;
	IIC0_ESDA_Hi;
	Delay();
}

void IIC0_SCLL_SDAL(void)
{
	IIC0_ESCL_Lo;
	IIC0_ESDA_Lo;
	Delay();
}
#endif

void IIC1_SCLH_SDAH(void)
{
	IIC1_ESCL_Hi;
	IIC1_ESDA_Hi;
	Delay();
}

void IIC1_SCLH_SDAL(void)
{
	IIC1_ESCL_Hi;
	IIC1_ESDA_Lo;
	Delay();
}

void IIC1_SCLL_SDAH(void)
{
	IIC1_ESCL_Lo;
	IIC1_ESDA_Hi;
	Delay();
}

void IIC1_SCLL_SDAL(void)
{
	IIC1_ESCL_Lo;
	IIC1_ESDA_Lo;
	Delay();
}

#ifndef CONFIG_UT_OEM

void IIC3_SCLH_SDAH(void)
{
	IIC3_ESCL_Hi;
	IIC3_ESDA_Hi;
	Delay();
}

void IIC3_SCLH_SDAL(void)
{
	IIC3_ESCL_Hi;
	IIC3_ESDA_Lo;
	Delay();
}

void IIC3_SCLL_SDAH(void)
{
	IIC3_ESCL_Lo;
	IIC3_ESDA_Hi;
	Delay();
}

void IIC3_SCLL_SDAL(void)
{
	IIC3_ESCL_Lo;
	IIC3_ESDA_Lo;
	Delay();
}

void IIC0_ELow(void)
{
	IIC0_SCLL_SDAL();
	IIC0_SCLH_SDAL();
	IIC0_SCLH_SDAL();
	IIC0_SCLL_SDAL();
}

void IIC0_EHigh(void)
{
	IIC0_SCLL_SDAH();
	IIC0_SCLH_SDAH();
	IIC0_SCLH_SDAH();
	IIC0_SCLL_SDAH();
}
#endif

void IIC1_ELow(void)
{
	IIC1_SCLL_SDAL();
	IIC1_SCLH_SDAL();
	IIC1_SCLH_SDAL();
	IIC1_SCLL_SDAL();
}

void IIC1_EHigh(void)
{
	IIC1_SCLL_SDAH();
	IIC1_SCLH_SDAH();
	IIC1_SCLH_SDAH();
	IIC1_SCLL_SDAH();
}

#ifndef CONFIG_UT_OEM

void IIC3_ELow(void)
{
	IIC3_SCLL_SDAL();
	IIC3_SCLH_SDAL();
	IIC3_SCLH_SDAL();
	IIC3_SCLL_SDAL();
}

void IIC3_EHigh(void)
{
	IIC3_SCLL_SDAH();
	IIC3_SCLH_SDAH();
	IIC3_SCLH_SDAH();
	IIC3_SCLL_SDAH();
}

void IIC0_EStart(void)
{
	IIC0_SCLH_SDAH();
	IIC0_SCLH_SDAL();
	Delay();
	IIC0_SCLL_SDAL();
}

void IIC0_EEnd(void)
{
	IIC0_SCLL_SDAL();
	IIC0_SCLH_SDAL();
	Delay();
	IIC0_SCLH_SDAH();
}

void IIC0_EAck_write(void)
{
	unsigned long ack;

	IIC0_ESDA_INP;			// Function <- Input

	IIC0_ESCL_Lo;
	Delay();
	IIC0_ESCL_Hi;
	Delay();
	ack = GPD1DAT;
	IIC0_ESCL_Hi;
	Delay();
	IIC0_ESCL_Hi;
	Delay();

	IIC0_ESDA_OUTP;			// Function <- Output (SDA)

	ack = (ack>>0)&0x1;
//	while(ack!=0);

	IIC0_SCLL_SDAL();
}

void IIC0_EAck_read(void)
{
	IIC0_ESDA_OUTP;			// Function <- Output

	IIC0_ESCL_Lo;
	IIC0_ESCL_Lo;
	//IIC0_ESDA_Lo;
	IIC0_ESDA_Hi;
	IIC0_ESCL_Hi;
	IIC0_ESCL_Hi;

	IIC0_ESDA_INP;			// Function <- Input (SDA)

	IIC0_SCLL_SDAL();
}
#endif
void IIC1_EStart(void)
{
	IIC1_SCLH_SDAH();
	IIC1_SCLH_SDAL();
	Delay();
	IIC1_SCLL_SDAL();
}

void IIC1_EEnd(void)
{
	IIC1_SCLL_SDAL();
	IIC1_SCLH_SDAL();
	Delay();
	IIC1_SCLH_SDAH();
}

void IIC1_EAck_write(void)
{
	unsigned long ack;

	IIC1_ESDA_INP;			// Function <- Input

	IIC1_ESCL_Lo;
	Delay();
	IIC1_ESCL_Hi;
	Delay();
	ack = GPD1DAT;
	IIC1_ESCL_Hi;
	Delay();
	IIC1_ESCL_Hi;
	Delay();

	IIC1_ESDA_OUTP;			// Function <- Output (SDA)

	ack = (ack>>2)&0x1;
//	while(ack!=0);

	IIC1_SCLL_SDAL();
}

void IIC1_EAck_read(void)
{
	IIC1_ESDA_OUTP;			// Function <- Output

	IIC1_ESCL_Lo;
	IIC1_ESCL_Lo;
	//IIC1_ESDA_Lo;
	IIC1_ESDA_Hi;
	IIC1_ESCL_Hi;
	IIC1_ESCL_Hi;

	IIC1_ESDA_INP;			// Function <- Input (SDA)

	IIC1_SCLL_SDAL();
}

#ifndef CONFIG_UT_OEM

void IIC3_EStart(void)
{
	IIC3_SCLH_SDAH();
	IIC3_SCLH_SDAL();
	Delay();
	IIC3_SCLL_SDAL();
}

void IIC3_EEnd(void)
{
	IIC3_SCLL_SDAL();
	IIC3_SCLH_SDAL();
	Delay();
	IIC3_SCLH_SDAH();
}

void IIC3_EAck(void)
{
	unsigned long ack;

	IIC3_ESDA_INP;			// Function <- Input

	IIC3_ESCL_Lo;
	Delay();
	IIC3_ESCL_Hi;
	Delay();
	ack = GPA1DAT;
	IIC3_ESCL_Hi;
	Delay();
	IIC3_ESCL_Hi;
	Delay();

	IIC3_ESDA_OUTP;			// Function <- Output (SDA)

	ack = (ack>>2)&0x1;
//	while(ack!=0);

	IIC3_SCLL_SDAL();
}

void IIC0_ESetport(void)
{
	GPD1PUD &= ~(0xf<<0);	// Pull Up/Down Disable	SCL, SDA

	IIC0_ESCL_Hi;
	IIC0_ESDA_Hi;

	IIC0_ESCL_OUTP;		// Function <- Output (SCL)
	IIC0_ESDA_OUTP;		// Function <- Output (SDA)

	Delay();
}
#endif

void IIC1_ESetport(void)
{
	GPD1PUD &= ~(0xf<<4);	// Pull Up/Down Disable	SCL, SDA

	IIC1_ESCL_Hi;
	IIC1_ESDA_Hi;

	IIC1_ESCL_OUTP;		// Function <- Output (SCL)
	IIC1_ESDA_OUTP;		// Function <- Output (SDA)

	Delay();
}

#ifndef CONFIG_UT_OEM

void IIC3_ESetport(void)
{
	GPA1PUD &= ~(0xf<<4);	// Pull Up/Down Disable	SCL, SDA

	IIC3_ESCL_Hi;
	IIC3_ESDA_Hi;

	IIC3_ESCL_OUTP;		// Function <- Output (SCL)
	IIC3_ESDA_OUTP;		// Function <- Output (SDA)

	Delay();
}

void IIC0_EWrite (unsigned char ChipId, unsigned char IicAddr, unsigned char IicData)
{
	unsigned long i;

	IIC0_EStart();

////////////////// write chip id //////////////////
	for(i = 7; i>0; i--)
	{
		if((ChipId >> i) & 0x0001)
			IIC0_EHigh();
		else
			IIC0_ELow();
	}

	IIC0_ELow();	// write

	IIC0_EAck_write();	// ACK

////////////////// write reg. addr. //////////////////
	for(i = 8; i>0; i--)
	{
		if((IicAddr >> (i-1)) & 0x0001)
			IIC0_EHigh();
		else
			IIC0_ELow();
	}

	IIC0_EAck_write();	// ACK

////////////////// write reg. data. //////////////////
	for(i = 8; i>0; i--)
	{
		if((IicData >> (i-1)) & 0x0001)
			IIC0_EHigh();
		else
			IIC0_ELow();
	}

	IIC0_EAck_write();	// ACK

	IIC0_EEnd();
}

void IIC0_ERead (unsigned char ChipId, unsigned char IicAddr, unsigned char *IicData)
{
	unsigned long i, reg;
	unsigned char data = 0;

	IIC0_EStart();

////////////////// write chip id //////////////////
	for(i = 7; i>0; i--)
	{
		if((ChipId >> i) & 0x0001)
			IIC0_EHigh();
		else
			IIC0_ELow();
	}

	IIC0_ELow();	// write

	IIC0_EAck_write();	// ACK

////////////////// write reg. addr. //////////////////
	for(i = 8; i>0; i--)
	{
		if((IicAddr >> (i-1)) & 0x0001)
			IIC0_EHigh();
		else
			IIC0_ELow();
	}

	IIC0_EAck_write();	// ACK

	IIC0_EStart();

////////////////// write chip id //////////////////
	for(i = 7; i>0; i--)
	{
		if((ChipId >> i) & 0x0001)
			IIC0_EHigh();
		else
			IIC0_ELow();
	}

	IIC0_EHigh();	// read

	IIC0_EAck_write();	// ACK

////////////////// read reg. data. //////////////////
	IIC0_ESDA_INP;

	IIC0_ESCL_Lo;
	IIC0_ESCL_Lo;
	Delay();

	for(i = 8; i>0; i--)
	{
		IIC0_ESCL_Lo;
		IIC0_ESCL_Lo;
		Delay();
		IIC0_ESCL_Hi;
		IIC0_ESCL_Hi;
		Delay();
		reg = GPD1DAT;
		IIC0_ESCL_Hi;
		IIC0_ESCL_Hi;
		Delay();
		IIC0_ESCL_Lo;
		IIC0_ESCL_Lo;
		Delay();

		reg = (reg >> 0) & 0x1;
		data |= reg << (i-1);
	}

	IIC0_EAck_read();	// ACK
	IIC0_ESDA_OUTP;

	IIC0_EEnd();

	*IicData = data;
}
#endif

void IIC1_ERead (unsigned char ChipId, unsigned char IicAddr, unsigned char *IicData)
{
	unsigned long i, reg;
	unsigned char data = 0;

	IIC1_EStart();

////////////////// write chip id //////////////////
	for(i = 7; i>0; i--)
	{
		if((ChipId >> i) & 0x0001)
			IIC1_EHigh();
		else
			IIC1_ELow();
	}

	IIC1_ELow();	// write

	IIC1_EAck_write();	// ACK

////////////////// write reg. addr. //////////////////
	for(i = 8; i>0; i--)
	{
		if((IicAddr >> (i-1)) & 0x0001)
			IIC1_EHigh();
		else
			IIC1_ELow();
	}

	IIC1_EAck_write();	// ACK

	IIC1_EStart();

////////////////// write chip id //////////////////
	for(i = 7; i>0; i--)
	{
		if((ChipId >> i) & 0x0001)
			IIC1_EHigh();
		else
			IIC1_ELow();
	}

	IIC1_EHigh();	// read

	IIC1_EAck_write();	// ACK

////////////////// read reg. data. //////////////////
	IIC1_ESDA_INP;

	IIC1_ESCL_Lo;
	IIC1_ESCL_Lo;
	Delay();

	for(i = 8; i>0; i--)
	{
		IIC1_ESCL_Lo;
		IIC1_ESCL_Lo;
		Delay();
		IIC1_ESCL_Hi;
		IIC1_ESCL_Hi;
		Delay();
		reg = GPD1DAT;
		IIC1_ESCL_Hi;
		IIC1_ESCL_Hi;
		Delay();
		IIC1_ESCL_Lo;
		IIC1_ESCL_Lo;
		Delay();

		reg = (reg >> 2) & 0x1;		//eric repair 2014-04-10
		data |= reg << (i-1);
	}

	IIC1_EAck_read();	// ACK
	IIC1_ESDA_OUTP;

	IIC1_EEnd();

	*IicData = data;
}

void IIC1_EWrite (unsigned char ChipId, unsigned char IicAddr, unsigned char IicData)
{
	unsigned long i;

	IIC1_EStart();

////////////////// write chip id //////////////////
	for(i = 7; i>0; i--)
	{
		if((ChipId >> i) & 0x0001)
			IIC1_EHigh();
		else
			IIC1_ELow();
	}

	IIC1_ELow();	// write 'W'

	IIC1_EAck_write();	// ACK

////////////////// write reg. addr. //////////////////
	for(i = 8; i>0; i--)
	{
		if((IicAddr >> (i-1)) & 0x0001)
			IIC1_EHigh();
		else
			IIC1_ELow();
	}

	IIC1_EAck_write();	// ACK

////////////////// write reg. data. //////////////////
	for(i = 8; i>0; i--)
	{
		if((IicData >> (i-1)) & 0x0001)
			IIC1_EHigh();
		else
			IIC1_ELow();
	}

	IIC1_EAck_write();	// ACK

	IIC1_EEnd();
}

#ifndef CONFIG_UT_OEM

void IIC3_EWrite (unsigned char ChipId, unsigned char IicAddr, unsigned char IicData)
{
	unsigned long i;

	IIC3_EStart();

////////////////// write chip id //////////////////
	for(i = 7; i>0; i--)
	{
		if((ChipId >> i) & 0x0001)
			IIC3_EHigh();
		else
			IIC3_ELow();
	}

	IIC3_ELow();	// write 'W'

	IIC3_EAck();	// ACK

////////////////// write reg. addr. //////////////////
	for(i = 8; i>0; i--)
	{
		if((IicAddr >> (i-1)) & 0x0001)
			IIC3_EHigh();
		else
			IIC3_ELow();
	}

	IIC3_EAck();	// ACK

////////////////// write reg. data. //////////////////
	for(i = 8; i>0; i--)
	{
		if((IicData >> (i-1)) & 0x0001)
			IIC3_EHigh();
		else
			IIC3_ELow();
	}

	IIC3_EAck();	// ACK

	IIC3_EEnd();
}


void I2C_MAX8997_VolSetting(PMIC_RegNum eRegNum, u8 ucVolLevel, u8 ucEnable)
{
	u8 reg_addr, reg_bitpos, reg_bitmask, vol_level;
	u8 read_data;

	reg_bitpos = 0;
	reg_bitmask = 0x3F;
	if(eRegNum == 0)
	{
		reg_addr = 0x19;
	}
	else if(eRegNum == 1)
	{
		reg_addr = 0x22;
	}
	else if(eRegNum == 2)
	{
		reg_addr = 0x2B;
	}
	else if(eRegNum == 3)
	{
		reg_addr = 0x2D;
	}
	else if(eRegNum == 4)
	{
		reg_addr = 0x48;
	}
	else if(eRegNum == 5)
	{
		reg_addr = 0x44;
	}
	else
		while(1);

	vol_level = ucVolLevel&reg_bitmask;

	IIC0_ERead(MAX8997_ADDR, reg_addr, &read_data);

	read_data = (read_data & (~(reg_bitmask<<reg_bitpos))) | (vol_level<<reg_bitpos);

	IIC0_EWrite(MAX8997_ADDR, reg_addr, read_data);

	I2C_MAX8997_EnableReg(eRegNum, ucEnable);
}

void I2C_MAX8997_EnableReg(PMIC_RegNum eRegNum, u8 ucEnable)
{
	u8 reg_addr, reg_bitpos;
	u8 read_data;

	reg_bitpos = 0;
	if(eRegNum == 0)
	{
		reg_addr = 0x18;
	}
	else if(eRegNum == 1)
	{
		reg_addr = 0x21;
	}
	else if(eRegNum == 2)
	{
		reg_addr = 0x2A;
	}
	else if(eRegNum == 3)
	{
		reg_addr = 0x2C;
	}
	else if(eRegNum == 4)
	{
		reg_addr = 0x48;
		reg_bitpos = 0x6;
	}
	else if(eRegNum == 5)
	{
		reg_addr = 0x44;
		reg_bitpos = 0x6;
	}

	else
		while(1);

	IIC0_ERead(MAX8997_ADDR, reg_addr, &read_data);

	read_data = (read_data & (~(1<<reg_bitpos))) | (ucEnable<<reg_bitpos);

	IIC0_EWrite(MAX8997_ADDR, reg_addr, read_data);
}

#define CALC_S5M8767_BUCK234_VOLT(x)  ( (x<600) ? 0 : ((x-600)/6.25) )
#define CALC_S5M8767_BUCK156_VOLT(x)  ( (x<650) ? 0 : ((x-650)/6.25) )

void I2C_S5M8767_VolSetting(PMIC_RegNum eRegNum, unsigned char ucVolLevel, unsigned char ucEnable)
{
	unsigned char reg_addr, reg_bitpos, reg_bitmask, vol_level;

	reg_bitpos = 0;
	reg_bitmask = 0xFF;
	if(eRegNum == 0)
	{
		reg_addr = 0x33;
	}
	else if(eRegNum == 1)
	{
	        reg_addr = 0x35;
	}
	else if(eRegNum == 2)
	{
	        reg_addr = 0x3E;
	}
	else if(eRegNum == 3)
	{
		reg_addr = 0x47;
	}
	else if(eRegNum == 4)
	{
		reg_addr = 0x50;
	}
	else
	      while(1);

	vol_level = ucVolLevel&reg_bitmask;
	IIC0_EWrite(S5M8767_ADDR, reg_addr, vol_level);
}
#endif
#ifdef CONFIG_AXP221_PMU
extern int axp221_check(void);
#endif
#if 1

static u8 set_ddr_volt(u8 level)
{
	u8 reg_val = 0x1C;  //1.4v
	switch(level) {
		case 1:   //1.2v
			reg_val = 0x18;
			break;
			
		case 2:   //1.25v
			reg_val = 0x19;
			break;
			
		case 3:   //1.3v
			reg_val = 0x1a;
			break;

		case 4:   //1.35v
			reg_val = 0x1b;
			break;
			
		default:	
		case 5://1.4v
			reg_val = 0x1c;  
			break;

		case 6:   //1.45v
			reg_val = 0x1d;
			break;
			
		case 7:   //1.5v
			reg_val = 0x1e;
			break;		
	}
	
	return reg_val;
}

/***********************************************************
REGx/VSET[2:0]     |
                             | REGx/VSET[5:3]
----------------------------------------------------------- 
                                000    001    010    011    100    101    110    111              
                       000 | 0.600 0.800 1.000 1.200 1.600 2.000 2.400 3.200
                       001 | 0.625 0.825 1.025 1.250 1.650 2.050 2.500 3.300
                       010 | 0.650 0.850 1.050 1.300 1.700 2.100 2.600 3.400
                       011 | 0.675 0.875 1.075 1.350 1.750 2.150 2.700 3.500
                       100 | 0.700 0.900 1.100 1.400 1.800 2.200 2.800 3.600
                       101 | 0.725 0.925 1.125 1.450 1.850 2.250 2.900 3.700
                       110 | 0.750 0.950 1.150 1.500 1.900 2.300 3.000 3.800
                       111 | 0.775 0.975 1.175 1.550 1.950 2.350 3.100 3.900

***********************************************************/

int late_pmic_init(u8 volt)
{
	u8 reg_data;
	u8 reg_value;
#ifdef CONFIG_AXP221_PMU

	if(axp221_check( )) {
		
		return 1;
	}
#endif

	IIC1_ESetport();
	Delay();
	printf("===late_pmic_init==\n");
	reg_data = set_ddr_volt(volt);
	#if 0
	IIC1_EWrite(ACT8847_ADDR, 0x10, reg_data); // LDO1,vdd_ddr 1.3v 1b 1.35 1c 1.4
	
	IIC1_ERead(ACT8847_ADDR,0x12,&reg_value); // enable volt	
	reg_value |= (1<<7);
	IIC1_EWrite(ACT8847_ADDR,0x12, reg_value);
	IIC1_EWrite(ACT8847_ADDR,0x80,0x1E);// LDO10,0x21 1.65v 0x20 1.6v 0x1F 1.55v 0x1E 1.5v .....
	#endif
/*	
	Delay();
	IIC1_EWrite(ACT8847_ADDR, 0x40, 0x1a); // 

	Delay();
	*/
	Delay();

//	GPM3CON = (GPM3CON & ~(0xf<<20))|(0x1<<20);
//	GPM3CON = (GPM3CON & ~(0xf<<24))|(0x1<<24);
	
//	GPM3DAT |= (0x1<<5);
//	GPM3DAT |= (0x1<<6);
//	Delay();
//	Delay();
	GPD1PUD |= (0x5<<4);	// restore reset value: Pull Up/Down Enable SCL, SDA


	return 0;

}


#endif	

#ifdef CONFIG_UT_OEM
#define rGPX0CON		*(volatile unsigned long *)(0x11000c00)
#define rGPX0DAT		*(volatile unsigned long *)(0x11000c04)
#define rGPX0PUD		*(volatile unsigned long *)(0x11000c08)
#define rINF_REG6_REG	*(volatile unsigned long *)(0x10020800+0x18)

#define rRTC_CON		*(volatile unsigned long *)(0x10070040)

void pmic_volt_init(void)
{
	IIC1_ESetport();
	Delay();	
	IIC1_EWrite(ACT8847_ADDR, 0x40, 0x15); 
	
/* TEST by Albert_lee 2013-09-16 begin */
//	IIC1_ERead(ACT8847_ADDR, 0x69, &temp); 
//	temp &= ~(1<<7);
//	IIC1_EWrite(ACT8847_ADDR, 0x69, temp); 
//
//	IIC1_ERead(ACT8847_ADDR, 0x71, &temp); 
//	temp &= ~(1<<7);
//	IIC1_EWrite(ACT8847_ADDR, 0x71, temp); 
 /*Albert_lee 2013-09-16 end*/
	
//	IIC1_EWrite(ACT8847_ADDR, 0x58, 0x10); //Alive
//	IIC1_EWrite(ACT8847_ADDR, 0x40, 0x16); 

	Delay();	
}

static void pwr_key_init( void)
{
	volatile int value = 0;
	int power_key_det;
	int val;
	
	val = rGPX0CON;
	val &= ~(0xf<<4);
	rGPX0CON = val;
	
	val = rGPX0PUD;
	val &= ~(0x3<<2); 
	rGPX0PUD = val;

//	Delay();
	pmic_volt_init();
	Delay();
	
	value = rGPX0DAT;
	power_key_det = (value>>1)&0x1 ;

	if(power_key_det==0)
		rINF_REG6_REG = 1;
	else
		rINF_REG6_REG = 0;

	//32K
	rRTC_CON = 0x201;
	
	return power_key_det;
}


#endif


void pmic_init(void)
{
	float vdd_arm, vdd_int, vdd_g3d;
	float vdd_mif;
	float vdd_ldo14;


	u8 read_data;
	unsigned char reg_value;

	vdd_arm = CONFIG_PM_VDD_ARM;
	vdd_int = CONFIG_PM_VDD_INT;
	vdd_g3d = CONFIG_PM_VDD_G3D;
	vdd_mif = CONFIG_PM_VDD_MIF;
	vdd_ldo14 = CONFIG_PM_VDD_LDO14;

#ifdef CONFIG_AXP221_PMU
	if(axp221_check( ))
	{
		axp221_pmic_init( );
		return;
	}
#endif

#ifdef CONFIG_UT_OEM


	IIC1_EWrite(ACT8847_ADDR,0x80,0x1E);// LDO10,0x21 1.65v 0x20 1.6v 0x1F 1.55v 0x1E 1.5v .....



	IIC1_EWrite(ACT8847_ADDR, 0x10, 0x1e); // LDO1,vdd_ddr 1.3v 1b 1.35 1c 1.4
	
	IIC1_ERead(ACT8847_ADDR,0x12,&reg_value); // enable volt	
	reg_value |= (1<<7);
	IIC1_EWrite(ACT8847_ADDR,0x12, reg_value);
	
	pwr_key_init();

	return ;
#else
	IIC0_ESetport();
	IIC3_ESetport();

	/* read ID */
	IIC0_ERead(MAX8997_ADDR, 0, &read_data);
	if (read_data == 0x77) {
		I2C_MAX8997_VolSetting(PMIC_BUCK1, CALC_MAXIM_BUCK1245_VOLT(vdd_arm * 1000), 1);
		I2C_MAX8997_VolSetting(PMIC_BUCK2, CALC_MAXIM_BUCK1245_VOLT(vdd_int * 1000), 1);
		I2C_MAX8997_VolSetting(PMIC_BUCK3, CALC_MAXIM_BUCK37_VOLT(vdd_g3d * 1000), 1);

		/* LDO14 config */
		I2C_MAX8997_VolSetting(PMIC_LDO14, CALC_MAXIM_ALL_LDO(vdd_ldo14 * 1000), 3);

		/* VDD_MIF, mode 1 register */
		IIC3_EWrite(MAX8952_ADDR, 0x01, 0x80 | (((unsigned char)(vdd_mif * 100))-77));
	} else if((0 <= read_data) && (read_data <= 0x4)) {
		I2C_S5M8767_VolSetting(PMIC_BUCK1, CALC_S5M8767_BUCK156_VOLT(vdd_mif * 1000), 1);
		I2C_S5M8767_VolSetting(PMIC_BUCK2, CALC_S5M8767_BUCK234_VOLT(vdd_arm * 1000), 1);
		I2C_S5M8767_VolSetting(PMIC_BUCK3, CALC_S5M8767_BUCK234_VOLT(vdd_int * 1000), 1);
		I2C_S5M8767_VolSetting(PMIC_BUCK4, CALC_S5M8767_BUCK234_VOLT(vdd_g3d * 1000), 1);

		IIC0_EWrite(S5M8767_ADDR, 0x5A, 0x58);
	} else {
		/* set DVS1,2,3 as 0 by GPL0 */
		*((volatile unsigned int *)0x110000c0) = 0x11111111;
		*((volatile unsigned int *)0x110000c4) = 0x7;
		*((volatile unsigned int *)0x110000c4) = 0x0;
		*((volatile unsigned int *)0x110000c4) = 0x7;
		*((volatile unsigned int *)0x110000c4) = 0x0;
		*((volatile unsigned int *)0x110000c0) = 0x0;
		
		/* VDD_MIF */
		IIC0_EWrite(MAX77686_ADDR, 0x11, CALC_MAXIM77686_BUCK156789_VOLT(vdd_mif * 1000));
		/* VDD_ARM */
		IIC0_EWrite(MAX77686_ADDR, 0x14, CALC_MAXIM77686_BUCK234_VOLT(vdd_arm * 1000));
		/* VDD_INT */
		IIC0_EWrite(MAX77686_ADDR, 0x1E, CALC_MAXIM77686_BUCK234_VOLT(vdd_int * 1000));
		/* VDD_G3D */
		IIC0_EWrite(MAX77686_ADDR, 0x28, CALC_MAXIM77686_BUCK234_VOLT(vdd_g3d * 1000));
	}
#endif

	GPA1PUD |= (0x5<<4);	// restore reset value: Pull Up/Down Enable SCL, SDA
}
