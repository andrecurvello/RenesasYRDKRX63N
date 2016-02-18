#include "iorx63n.h"

void main( void )
{ 
  
  PORTE.PDR.BIT.B3 = 1;         // Set bit 3 to 1 (Set LED5 as output)
  PORTE.PMR.BIT.B3 = 0;         // Set bit 3 to 0 (Set LED5 as general I/O)
  PORTE.ODR0.BIT.B6 = 0;        // Set bit 6 to 0 (Set LED5 as push-pull output)
  PORTE.DSCR.BIT.B3 = 0;        // Set bit 3 to 0 (Set LED5 as "normal" drive capacity)
    
  for(;;)
  {
    for (volatile int i= 10000; i > 0; i--)
    {
      // NOTE: The volatile keyword assures this empty loop won't optimize.
    }
    PORTE.PODR.BIT.B3 ^= 1;     // Toggle bit 3 (Turn LED5 on/off)
  }
  
}