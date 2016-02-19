#include "iorx63n.h"

void main( void )
{ 
  
  PORTE.PDR.BIT.B3 = 1;         // Set bit 3 to 1 (Set LED5 as output)
  PORTE.PMR.BIT.B3 = 0;         // Set bit 3 to 0 (Set LED5 as general I/O)
  PORTE.ODR0.BIT.B6 = 0;        // Set bit 6 to 0 (Set LED5 as push-pull output)
  PORTE.DSCR.BIT.B3 = 0;        // Set bit 3 to 0 (Set LED5 as "normal" drive capacity)
    
  PORT4.PDR.BIT.B0 = 0;         // Set bit 0 to 0 (Set SW1 as input)
  PORT4.PMR.BIT.B0 = 0;         // Set bit 0 to 0 (Set SW1 as general I/O)
  PORT4.PCR.BIT.B0 = 0;         // Set bit 0 to 0 (Set SW1 to not use pull-up, since it already has one on the board)
  
  for(;;)
  {
    if(0==PORT4.PIDR.BIT.B0)
      PORTE.PODR.BIT.B3 = 1;     // Turn LED off (1) when switch is pressed (0)
    else
      PORTE.PODR.BIT.B3 = 0;    // LED is on (0) when switch is not pressed (1)
  }  
  
}