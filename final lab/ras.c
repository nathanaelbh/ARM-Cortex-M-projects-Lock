/*
 * ras.c
 *
 *  Created on: Oct 22, 2019
 *      Author: Nathanael Bhooshi
 */

#include "ras.h"
#include <stdint.h>
#include <stdbool.h>
#include <inc/hw_memmap.h>
#include <driverlib/pin_map.h>
#include <driverlib/sysctl.h>
#include <driverlib/gpio.h>
#include <driverlib/adc.h>

void rasInit(){
    //
    // Enable the ADC0 module.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0); //enables the port and pin
    //
    // Wait for the ADC0 module to be ready.
    //

    ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0); //
    //This function configures the initiation criteria for a sample sequence. Valid sample sequencers
    //range from zero to three; sequencer zero captures up to eight samples, sequencers one and
    //two capture up to four samples, and sequencer three captures a single sample. The trigger
    //condition and priority (with respect to other sample sequencer execution) are set.

    //while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0))
   // {
    // }
    //
    // Enable the first sample sequencer to capture the value of channel 0 when
    // the processor trigger occurs.
    //
    ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_CH6); //double check if right channel
    ADCSequenceStepConfigure(ADC0_BASE, 0, 1, ADC_CTL_IE | ADC_CTL_END | ADC_CTL_CH7); // changed channel number
    ADCSequenceEnable(ADC0_BASE, 0);
}

void rasRead(uint32_t data[2]){// read value from 0 - 4095
    //
    // Trigger the sample sequence.
    //
    ADCProcessorTrigger(ADC0_BASE, 0);
    //
    // Wait until the sample sequence has completed.
    //
    while(!ADCIntStatus(ADC0_BASE, 0, false))
    {
    }
    //
    // Read the value from the ADC.
    //
    ADCSequenceDataGet(ADC0_BASE, 0, data);
    ADCIntClear(ADC0_BASE, 0);
}

