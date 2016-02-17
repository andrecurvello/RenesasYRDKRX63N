
void main( void )
{ 
  unsigned char * const PDR     = (unsigned char * )0x0008C00E;
  unsigned char * const PODR    = (unsigned char * )0x0008C02E;
  unsigned char * const PMR     = (unsigned char * )0x0008C06E;
  unsigned char * const ODR0    = (unsigned char * )0x0008C09C;
  unsigned char * const DSCR    = (unsigned char * )0x0008C0EE;
  
  *PDR  |= 0x08;        // Set bit 3 to 1 (Set LED5 as output)
  *PMR  &= ~(0x08);     // Set bit 3 to 0 (Set LED5 as general I/O)
  *ODR0 &= ~(0x40);     // Set bit 6 to 0 (Set LED5 as push-pull output)
  *DSCR &= ~(0x08);     // Set bit 3 to 0 (Set LED5 as "normal" drive capacity)
    
  for(;;)
  {
    for (volatile int i= 10000; i > 0; i--)
    {
      // NOTE: The volatile keyword assures this empty loop won't optimize.
    }
    *PODR ^= (0x08); // Toggle bit 3 (Turn LED5 on/off)
  }
  
}
