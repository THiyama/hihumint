/***************************************************************/
/*                                                             */
/*      PROJECT NAME :  hihumint                               */
/*      FILE         :  interrupt_handlers.c                   */
/*      DESCRIPTION  :  Interrupt program                      */
/*      CPU SERIES   :  RX600                                  */
/*      CPU TYPE     :  RX631                                  */
/*                                                             */
/*      This file is generated by e2 studio.                   */
/*                                                             */
/***************************************************************/             
                                                                         
#include <machine.h>
#include "vect.h"

#pragma section IntPRG

// Exception(Supervisor Instruction)
void Excep_SuperVisorInst(void){/* brk(); */}

// Exception(Undefined Instruction)
void Excep_UndefinedInst(void){/* brk(); */}

// Exception(Floating Point)
void Excep_FloatingPoint(void){/* brk(); */}

// NMI
void NonMaskableInterrupt(void){/* brk(); */}

// Dummy
void Dummy(void){/* brk(); */}

// BRK
void Excep_BRK(void){ wait(); }

// BUSERR
void Excep_BUSERR(void){ }

// FCU_FCUERR
void Excep_FCUIF_FIFEERR(void){ }

// FCU_FRDYI
void Excep_FCUIF_FRDYI(void){ }

// ICU SWINT
void Excep_ICU_SWINT(void){ }

void cmt_0_interrupt();
// CMTU0_CMT0

#pragma interrupt (Excep_CMT0_CMI0 (vect=28,enable))
void Excep_CMT0_CMI0(void){
	cmt_0_interrupt();
}

void cmt_1_interrupt();
#pragma interrupt (Excep_CMT1_CMI1(vect=29,enable))
// CMTU1_CMT1
void Excep_CMT1_CMI1(void){
	cmt_1_interrupt();
}
// CMTU2_CMT2
void Excep_CMT2_CMI2(void){ }

// CMTU3_CMT3
void Excep_CMT3_CMI3(void){ }

// ETHER EINT
void Excep_ETHER_EINT(void){ }

// USB0 D0FIFO0
void Excep_USB0_D0FIFO0(void){ }

// USB0 D1FIFO0
void Excep_USB0_D1FIFO0(void){ }

// USB0 USBI0
void Excep_USB0_USBI0(void){ }

// USB1 D0FIFO1
void Excep_USB1_D0FIFO1(void){ }

// USB1 D1FIFO1
void Excep_USB1_D1FIFO1(void){ }

// USB1 USBI1
void Excep_USB1_USBI1(void){ }

// RSPI0 SPRI0
void Excep_RSPI0_SPRI0(void){ }

// RSPI0 SPTI0
void Excep_RSPI0_SPTI0(void){ }

// RSPI0 SPII0
void Excep_RSPI0_SPII0(void){ }

// RSPI1 SPRI1
void Excep_RSPI1_SPRI1(void){ }

// RSPI1 SPTI1
void Excep_RSPI1_SPTI1(void){ }

// RSPI1 SPII1
void Excep_RSPI1_SPII1(void){ }

// RSPI2 SPRI2
void Excep_RSPI2_SPRI2(void){ }

// RSPI2 SPTI2
void Excep_RSPI2_SPTI2(void){ }

// RSPI2 SPII2
void Excep_RSPI2_SPII2(void){ }

// CAN0 RXF0
void Excep_CAN0_RXF0(void){ }

// CAN0 TXF0
void Excep_CAN0_TXF0(void){ }

// CAN0 RXM0
void Excep_CAN0_RXM0(void){ }

// CAN0 TXM0
void Excep_CAN0_TXM0(void){ }

// CAN1 RXF1
void Excep_CAN1_RXF1(void){ }

// CAN1 TXF1
void Excep_CAN1_TXF1(void){ }

// CAN1 RXM1
void Excep_CAN1_RXM1(void){ }

// CAN1 TXM1
void Excep_CAN1_TXM1(void){ }

// RTC CUP
void Excep_RTC_CUP(void){ }

// IRQ0
void Excep_IRQ0(void){ }

// IRQ1
void Excep_IRQ1(void){ }

// IRQ2
void Excep_IRQ2(void){ }

// IRQ3
void Excep_IRQ3(void){ }

// IRQ4
void Excep_IRQ4(void){ }

// IRQ5
void Excep_IRQ5(void){ }

// IRQ6
void Excep_IRQ6(void){ }

// IRQ7
void Excep_IRQ7(void){ }

// IRQ8
void Excep_IRQ8(void){ }

// IRQ9
void Excep_IRQ9(void){ }

// IRQ10
void Excep_IRQ10(void){ }

// IRQ11
void Excep_IRQ11(void){ }

// IRQ12
void Excep_IRQ12(void){ }

// IRQ13
void Excep_IRQ13(void){ }

// IRQ14
void Excep_IRQ14(void){ }

// IRQ15
void Excep_IRQ15(void){ }

// USB RESUME USBR0
void Excep_USB_USBR0(void){ }

// USB RESUME USBR1
void Excep_USB_USBR1(void){ }

// RTC ALM
void Excep_RTC_ALM(void){ }

// RTC SLEEP
void Excep_RTC_SLEEP(void){ }

// ADA0 ADI0
void Excep_ADA0_ADI0(void){ }

// S12AD0 S12ADI0
void Excep_S12AD0_S12ADI0(void){ }

// GROUP E0
void Excep_GROUP_E0(void){ }

// GROUP E1
void Excep_GROUP_E1(void){ }

// GROUP E2
void Excep_GROUP_E2(void){ }

// GROUP E3
void Excep_GROUP_E3(void){ }

// GROUP E4
void Excep_GROUP_E4(void){ }

// GROUP E5
void Excep_GROUP_E5(void){ }

// GROUP E6
void Excep_GROUP_E6(void){ }

// vector 113 reserved

// GROUP L0
void Excep_GROUP_L0(void){ }

// SCIX_SCIX0
void Excep_SCIX_SCIX0(void){ }

// SCIX_SCIX1
void Excep_SCIX_SCIX1(void){ }

// SCIX_SCIX2
void Excep_SCIX_SCIX2(void){ }

// SCIX_SCIX3
void Excep_SCIX_SCIX3(void){ }

// TPU0 TGIA0
void Excep_TPU0_TGIA0(void){ }

// TPU0 TGIB0
void Excep_TPU0_TGIB0(void){ }

// TPU0 TGIC0
void Excep_TPU0_TGIC0(void){ }

// TPU0 TGID0
void Excep_TPU0_TGID0(void){ }

// TPU1 TGIA1
void Excep_TPU1_TGIA1(void){ }

// TPU1 TGIB1
void Excep_TPU1_TGIB1(void){ }

// TPU2 TGIA2
void Excep_TPU2_TGIA2(void){ }

// TPU2 TGIB2
void Excep_TPU2_TGIB2(void){ }

// TPU3 TGIA3
void Excep_TPU3_TGIA3(void){ }

// TPU3 TGIB3
void Excep_TPU3_TGIB3(void){ }

// TPU3 TGIC3
void Excep_TPU3_TGIC3(void){ }

// TPU3 TGID3
void Excep_TPU3_TGID3(void){ }

// TPU4 TGIA4
void Excep_TPU4_TGIA4(void){ }

// TPU4 TGIB4
void Excep_TPU4_TGIB4(void){ }

// TPU5 TGIA15
void Excep_TPU5_TGIA5(void){ }

// TPU5 TGIB5
void Excep_TPU5_TGIB5(void){ }

// TPU6/MTU0 TGIA6/TGIA0
void Excep_TPU6_TGIA6(void){ }

// TPU6/MTU0 TGIB6/TGIB0
void Excep_TPU6_TGIB6(void){ }

// TPU6/MTU0 TGIC6/TGIC0
void Excep_TPU6_TGIC6(void){ }

// TPU6/MTU0 TGID6/TGID0
void Excep_TPU6_TGID6(void){ }

// TPU6/MTU0 TGIE6/TGIE0
void Excep_TPU6_TGIE6(void){ }

// TPU6/MTU0 TGIF6/TGIF0
void Excep_TPU6_TGIF6(void){ }

// TPU7/MTU1 TGIA7/TGIA1
void Excep_TPU7_TGIA7(void){ }

// TPU7/MTU1 TGIB7/TGIB1
void Excep_TPU7_TGIB7(void){ }

// TPU8/MTU2 TGIA8/TGIA2
void Excep_TPU8_TGIA8(void){ }

// TPU8/MTU2 TGIB8/TGIB2
void Excep_TPU8_TGIB8(void){ }

// TPU9/MTU3 TGIA9/TGIA3
void Excep_TPU9_TGIA9(void){ }

// TPU9/MTU3 TGIB9/TGIB3
void Excep_TPU9_TGIB9(void){ }

// TPU9/MTU3 TGIC9/TGIC3
void Excep_TPU9_TGIC9(void){ }

// TPU9/MTU3 TGID9/TGID3
void Excep_TPU9_TGID9(void){ }

// TPU10/MTU4 TGIA10/TGIA4
void Excep_TPU10_TGIA10(void){ }

// TPU10/MTU4 TGIB10/TGIB4
void Excep_TPU10_TGIB10(void){ }

// TPU10/MTU4 TGIC10/TGIC4
void Excep_TPU10_TGIC10(void){ }

// TPU10/MTU4 TGID10/TGID4
void Excep_TPU10_TGID10(void){ }

// TPU10/MTU4 TGIV10/TGIV4
void Excep_TPU10_TGIV10(void){ }

// MTU5 TGIU5
void Excep_MTU5_TGIU5(void){ }

// MTU5 TGIV5
void Excep_MTU5_TGIV5(void){ }

// MTU5 TGIW5
void Excep_MTU5_TGIW5(void){ }

// TPU11 TGIA11
void Excep_TPU11_TGIA11(void){ }

// TPU11 TGIB11
void Excep_TPU11_TGIB11(void){ }

// POE2 OEI1
void Excep_POE2_OEI1(void){ }

// POE2 OEI2
void Excep_POE2_OEI2(void){ }

// TMR0_CMIA0
void Excep_TMR0_CMIA0(void){ }

// TMR0_CMIB0
void Excep_TMR0_CMIB0(void){ }

// TMR0_OVI0
void Excep_TMR0_OVI0(void){ }

// TMR1_CMIA1
void Excep_TMR1_CMIA1(void){ }

// TMR1_CMIB1
void Excep_TMR1_CMIB1(void){ }

// TMR1_OVI1
void Excep_TMR1_OVI1(void){ }

// TMR2_CMIA2
void Excep_TMR2_CMIA2(void){ }

// TMR2_CMIB2
void Excep_TMR2_CMIB2(void){ }

// TMR2_OVI2
void Excep_TMR2_OVI2(void){ }

// TMR3_CMIA3
void Excep_TMR3_CMIA3(void){ }

// TMR3_CMIB3
void Excep_TMR3_CMIB3(void){ }

// TMR3_OVI3
void Excep_TMR3_OVI3(void){ }

// RIIC0 EEI0
void Excep_RIIC0_EEI0(void){ }

// RIIC0 RXI0
void Excep_RIIC0_RXI0(void){ }

// RIIC0 TXI0
void Excep_RIIC0_TXI0(void){ }

// RIIC0 TEI0
void Excep_RIIC0_TEI0(void){ }

// RIIC1 EEI0
void Excep_RIIC1_EEI0(void){ }

// RIIC1 RXI0
void Excep_RIIC1_RXI0(void){ }

// RIIC1 TXI0
void Excep_RIIC1_TXI0(void){ }

// RIIC1 TEI0
void Excep_RIIC1_TEI0(void){ }

// RIIC2 EEI0
void Excep_RIIC2_EEI0(void){ }

// RIIC2 RXI0
void Excep_RIIC2_RXI0(void){ }

// RIIC2 TXI0
void Excep_RIIC2_TXI0(void){ }

// RIIC2 TEI0
void Excep_RIIC2_TEI0(void){ }

// RIIC3 EEI0
void Excep_RIIC3_EEI0(void){ }

// RIIC3 RXI0
void Excep_RIIC3_RXI0(void){ }

// RIIC3 TXI0
void Excep_RIIC3_TXI0(void){ }

// RIIC3 TEI0
void Excep_RIIC3_TEI0(void){ }

// DMACA DMAC0
void Excep_DMACA_DMAC0(void){ }

// DMAC DMAC1
void Excep_DMACA_DMAC1(void){ }

// DMAC DMAC2
void Excep_DMACA_DMAC2(void){ }

// DMAC DMAC3
void Excep_DMACA_DMAC3(void){ }

// EXDMAC DMAC0
void Excep_EXDMAC_DMAC0(void){ }

// EXDMAC DMAC1
void Excep_EXDMAC_DMAC1(void){ }

// SCI0_RXI0
void Excep_SCI0_RXI0(void){ }

// SCI0_TXI0
void Excep_SCI0_TXI0(void){ }

// SCI0_TEI0
void Excep_SCI0_TEI0(void){ }

// SCI1_RXI1
void Excep_SCI1_RXI1(void){ }

// SCI1_TXI1
void Excep_SCI1_TXI1(void){ }

// SCI1_TEI1
void Excep_SCI1_TEI1(void){ }

// SCI2_RXI2
void Excep_SCI2_RXI2(void){ }

// SCI2_TXI2
void Excep_SCI2_TXI2(void){ }

// SCI2_TEI2
void Excep_SCI2_TEI2(void){ }

// SCI3_RXI3
void Excep_SCI3_RXI3(void){ }

// SCI3_TXI3
void Excep_SCI3_TXI3(void){ }

// SCI3_TEI3
void Excep_SCI3_TEI3(void){ }

// SCI4_RXI4
void Excep_SCI4_RXI4(void){ }

// SCI4_TXI4
void Excep_SCI4_TXI4(void){ }

// SCI4_TEI4
void Excep_SCI4_TEI4(void){ }

// SCI5_RXI5
void Excep_SCI5_RXI5(void){ }

// SCI5_TXI5
void Excep_SCI5_TXI5(void){ }

// SCI5_TEI5
void Excep_SCI5_TEI5(void){ }

// SCI6_RXI6
void Excep_SCI6_RXI6(void){ }

// SCI6_TXI6
void Excep_SCI6_TXI6(void){ }

// SCI6_TEI6
void Excep_SCI6_TEI6(void){ }

// SCI7_RXI7
void Excep_SCI7_RXI7(void){ }

// SCI7_TXI7
void Excep_SCI7_TXI7(void){ }

// SCI7_TEI7
void Excep_SCI7_TEI7(void){ }

// SCI8_RXI8
void Excep_SCI8_RXI8(void){ }

// SCI8_TXI8
void Excep_SCI8_TXI8(void){ }

// SCI8_TEI8
void Excep_SCI8_TEI8(void){ }

// SCI9_RXI9
void Excep_SCI9_RXI9(void){ }

// SCI9_TXI9
void Excep_SCI9_TXI9(void){ }

// SCI9_TEI9
void Excep_SCI9_TEI9(void){ }

// SCI10_RXI10
void Excep_SCI10_RXI10(void){ }

// SCI10_TXI10
void Excep_SCI10_TXI10(void){ }

// SCI10_TEI10
void Excep_SCI10_TEI10(void){ }

// SCI11_RXI11
void Excep_SCI11_RXI11(void){ }

// SCI11_TXI11
void Excep_SCI11_TXI11(void){ }

// SCI11_TEI11
void Excep_SCI11_TEI11(void){ }

// SCI12_RXI12
void Excep_SCI12_RXI12(void){ }

// SCI12_TXI12
void Excep_SCI12_TXI12(void){ }

// SCI12_TEI12
void Excep_SCI12_TEI12(void){ }

// IEBUS IEBINT
void Excep_IEBUS_IEBINT(void){ }
