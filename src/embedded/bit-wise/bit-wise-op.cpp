unsigned int set_bit(unsigned int x, int n){
    return x | (1 << n);
}

unsigned int clear_bit(unsigned int x, int n){
    return x & ~(1 << n);
}

unsigned int toggle_bit(unsigned int x, int n){
    return x ^ (1 << n);
}

bool is_bit_set(unsigned int x, int n){
    return (x >> n) & 1;
}

unsigned int get_bits(unsigned int x, int n, int pos){
    unsigned int mask = ~(~0U << n);
    return (x >> pos) & mask;
}

unsigned int set_field(unsigned int x, int n, int pos){
    unsigned int mask = ~(~0U << n) << pos;
    return x & mask;
}
// 假設我們直接操作一個暫存器的地址 (指標)
void set_field(unsigned int *reg, unsigned int val, int n, int pos) {
    // 1. 產生遮罩 (例如 pos=4, n=3，則產生 0...01110000)
    unsigned int mask = ((1U << n) - 1) << pos; 
    
    // 2. 清除該欄位：先將 mask 反轉 (變成 1...10001111)，與原值 AND，這會把目標欄位歸零
    *reg &= ~mask; 
    
    // 3. 寫入新值：將 val 限制在 n 位元內 (val & ((1U << n) - 1))，再移到正確位置，用 OR 寫入
    *reg |= ((val & ((1U << n) - 1)) << pos);
}

volatile unsigned int* reg = (unsigned int*)0x40001000;
set_field(reg, 1, 1, 5);

#define READ_REG(addr) return *(volatile unsigned int*)addr;
// test input: READ_REG(base_addr + offset)
// test input: unsigned int val = READ_REG(0x40001000);

#define READ_REG(addr) (*(volatile unsigned int*)(addr));
#define REG_TIMER_EXPIRED 0x00000001
#define TIMER_EXPIRED_BIT 0

static bool alarm_triggered;
void Timer_ISR(){
    set_field(REG_TIMER_EXPIRED, 0, 1, TIMER_EXPIRED_BIT)
    alarm_triggered = true;
}
int main(){
    while(1){
        if(alarm_triggered == true){
            printf("Alarm!!\n");
            alarm_triggered = false;
        }
    }
}

int countSetBits1(unsigned int x)
{
    int n = 0;
    for(int i = 0; i < sizeof(x)*8 ; i++)
    {
        if (x & 1) n++;
        x = x >> 1;
    }
    return n;
}

int countSetBits2(unsigned int x)
{
    int n = 0;
    // while(x & (x-1)) // there are still 1s in x
    while(x) 
    {
        n++;
        x = x & (x-1);
    }
    return n;
}
