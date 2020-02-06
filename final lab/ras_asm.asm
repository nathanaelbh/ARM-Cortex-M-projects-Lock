

; To include names declared in C
  .cdecls "stdint.h","stdbool.h","inc/hw_memmap.h","driverlib/pin_map.h","driverlib/sysctl.h","driverlib/gpio.h","ras.h","driverlib/adc.h"
				.data
                .text
                .global  ADCRead

RAS_PORT		.field	ADC0_BASE




ADCRead		PUSH{LR,r0}

				LDR r0,RAS_PORT
				MOV r1,#0
				BL  ADCProcessorTrigger

Loop			LDR    r0, RAS_PORT
				MOV		r1,#0
				MOV		r2,#false
				BL		ADCIntStatus
				CMP     r0,#0
				BEQ		Loop


				LDR		r0,RAS_PORT
				MOV		r1,#0
				POP     {r2}
				BL		ADCSequenceDataGet


				LDR		r0,RAS_PORT
				MOV		r1,#0
				BL 		ADCIntClear



				POP {PC}
