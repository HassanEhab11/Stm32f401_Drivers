#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_








void MSPI_MastervoidInit(void);
u8   MSPI1_VidSendDataU8  ( u8 Copy_u8Data     ) ;
void MSPI_SendRecievptr(u8 Copy_DataTransmit,u8 *Copy_u8RetData);
void MSPI1_VidSetCallBack ( void (*ptr) (void) ) ;


#endif /* SPI_INTERFACE_H_ */
