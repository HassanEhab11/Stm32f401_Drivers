

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPI1_BASE_ADDRESS	0x40013000
#define SPI2_BASE_ADDRESS	0x40003800
#define SPI3_BASE_ADDRESS	0x40003C00


typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
	
}SPI_REG_s;

#define MSPI1	((SPI_REG_s *) SPI1_BASE_ADDRESS)
#define MSPI2	((SPI_REG_s *) SPI2_BASE_ADDRESS)
#define MSPI3	((SPI_REG_s *) SPI3_BASE_ADDRESS)

#endif