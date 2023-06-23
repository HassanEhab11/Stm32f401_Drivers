

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_



void MUSART_VidInit(void) ;
void MUSART1_VidSendCharSync( u8 Copy_u8Char) ;
void MUSART1_VidSendStringSynch ( u8 * Copy_ptrString ) ;
u8   MUSART1_u8RecCharSynch(void) ;
u8 * MUSART1_PtrReadStringSynch (void) ;
void MUSART1_VidSetCallBack(void (*ptr) (void)) ;

#endif /* USART_INTERFACE_H_ */
