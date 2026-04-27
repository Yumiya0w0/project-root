void reverseBits(uint32_t& val)
{
    // devide and conquer
    val = (val << 16) | (val >> 16);
    // mask = 0xFF00FF00 
    val = ((val & 0xFF00FF00) >> 8 ) | ((val & 0x00FF00FF) << 8 );
    // mask =  0xF0F0F0F0
    val = ((val & 0xF0F0F0F0) >> 4 ) | ((val & 0x0F0F0F0F) << 4 );
    // mask =  1100 1100 ..., 0011 0011 ...
    val = ((val & 0xCCCCCCCC) >> 2 ) | ((val & 0x33333333) << 2 );
    // mask =  1010 1010 ..., 0101 0101 ...
    val = ((val & 0xAAAAAAAA) >> 1 ) | ((val & 0x55555555) << 1 );
}