#include <stdio.h>
#include <stdint.h>
int ceil_log2(uint32_t x){
    uint32_t r = 0,shift;
    
    //x--;
    int last_position = __builtin_ctz(x)+1;
    uint32_t mask = 0xffffffff;
    mask = mask << (32 - last_position);
    mask >>= (32 - last_position);
    x = mask>>1;
    
    shift = (x>0xffff) << 4;
    x >>= shift;
    r = r | shift;
    
    shift = (x>0xff) << 3;
    x >>= shift;
    r = r|shift;
    
    shift = (x>0xf) << 2;
    x >>= shift;
    r = r|shift;
    
    shift = (x>0x3) << 1;
    x >>= shift;

    return (r | shift | x>>1 )+1;
}

int main()
{
    uint32_t x = 1;
    uint32_t logx = ceil_log2(x);

    printf("%d\n",logx);
    return 0;

}
