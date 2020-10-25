#include    <18f4550.h>
#device     adc=10
#fuses      nowdt,put,hs,noprotect,nolvp,cpudiv1
#use        i2c(master,slow,sda=pin_b0,scl=pin_b1)
#use        delay(clock=20000000)      
//#use        rs232(baud=9600, xmit=pin_c6,rcv=pin_c7) 

#define  usi8  unsigned int8     
#define  usi16 unsigned int16           
#define  usi32 unsigned int32                                                                    
#define  si8   signed int8    

#define co_reset  true
#define no_reset  false 

#define tt_on     1          
#define tt_off    0       
#define enable    1                        
#define disable   0
#define sang      1          
#define tat       0  
#define tat_l7d  0xff     
#define cx_vn     true   //co xoa so 0 vo nghia        
#define kx_vn     false  //khong xoa so 0 vo nghia          
#define co_fill  true
#define no_fill  false  

unsigned int8 i;
unsigned int8 y8,sl;
unsigned int16 lt,lp;
unsigned int32 y;
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//dinh nghia cac trang thai co nhan va khong nhan phim
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
#define co_nhan      1            
#define khong_nhan   0           
#define c_ktnp       1  //co kiem tra nha phim          
#define k_ktnp       0  //khong kiem tra nha phim 
#define sole_1       false            
#define sole_2       true  

int1 tt_on_off=0,tt_inv=0;  
unsigned int16  dl_btn=0;
//int1 tt_led=0,tt_ena_dis=0;  
//int1 t0_on_off=0,tt_1btn=0;   
//int1 t3_on_off=0; 
//int1 refresh=0; 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//ham reset cac bien
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void reset_cac_bien()
{     
   tt_on_off=0;tt_inv=0;
   dl_btn=0;
   y8=0; lt=0;lp=0;y=0;sl=0;
}             

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define  enable_573a      pin_d1  //cs0 cua a 
#define  enable_573b      pin_d0  //cs1 cua b
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      
#define  ssdo             pin_e2  //chung tat ca
#define  ssck             pin_e0  //chung tat ca
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define  rck_4led7doan    pin_d7  //a - 4 byte
#define  g_4led7doan      pin_d6  //a - 4 byte
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define  rck_matranled    pin_d7  //b - 3 byte dao
#define  g_matranled      pin_d6  //b - 3 byte dao
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define  rck_32led        pin_d5  //a - 4 byte
#define  g_32led          pin_d4  //a - 4 byte
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define  rck_8ledquet     pin_d5  //b - 2 byte dao
#define  g_8ledquet       pin_d4  //b - 2 byte dao
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define  rck_lcd20x4      pin_d3  //a - 2 byte dao
#define  g_lcd20x4        pin_d2  //a - 2 byte dao
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define  rck_buzerelay    pin_d3  //b - 1 byte
#define  g_buzerelay      pin_d2  //b - 1 byte 


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define     chot_2_ic_74573_a_b  output_d(0xfc)
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
unsigned int8 tin_hieu_dk_74573_a;
#bit     g_4a    = tin_hieu_dk_74573_a.6
#bit     g_32a   = tin_hieu_dk_74573_a.4
#bit     g_lcda  = tin_hieu_dk_74573_a.2
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define  mo_32_led_don    g_32a=0;
#define  tat_32_led_don   g_32a=1; 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define  mo_4_led_7doan   g_4a=0;
#define  tat_4_led_7doan  g_4a=1;  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define  mo_glcd_lcd      g_lcda=0;
#define  tat_glcd_lcd     g_lcda=1;  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
unsigned int8 tin_hieu_dk_74573_b;  
#bit     g_mtb   = tin_hieu_dk_74573_b.6
#bit     g_8b    = tin_hieu_dk_74573_b.4
#bit     g_rbdcb = tin_hieu_dk_74573_b.2
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define  mo_led_matran        g_mtb=0;
#define  tat_led_matran       g_mtb=1; 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define  mo_8_led_quet        g_8b=0;
#define  tat_8_led_quet       g_8b=1;                        
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define  mo_relay_buzzer_dc   g_rbdcb=0;
#define  tat_relay_buzzer_dc  g_rbdcb=1; 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//chuong trinh con khoi tao ic chot
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define  cho_ic_74573_a_goi_du_lieu     output_high(enable_573a)
#define  chot_ic_74573_a_goi_du_lieu    output_low(enable_573a)

#define  cho_ic_74573_b_goi_du_lieu     output_high(enable_573b)
#define  chot_ic_74573_b_goi_du_lieu    output_low(enable_573b)
void mo_ic_74573_a_thong_dl();

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//khai bao du lieu 16 bit cho module relay, triac, buzzer, dong co
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
unsigned int16 rbdc;
#bit step_motor_enable  = rbdc.0    //1=ena,0=dis
#bit step_motor_in1     = rbdc.1    
#bit step_motor_in2     = rbdc.2
#bit step_motor_in3     = rbdc.3
#bit step_motor_in4     = rbdc.4
#bit dc_enable          = rbdc.5    //1=ena,0=dis
#bit pwrkey             = rbdc.6    //khoi tao sim900

#bit buzzer             = rbdc.8    //1=on,0=off
#bit triac_1            = rbdc.9    //1=on,0=off
#bit triac_2            = rbdc.10   //1=on,0=off
#bit relay_1            = rbdc.11   //0=on,1=off
#bit relay_2            = rbdc.12   //0=on,1=off  

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//xuat các thieu dieu khien
//giu nguyen cac trang thai cua 2 module khac
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void mo_ic_74573_a_thong_dl()
{     
   output_d(0x00);
   output_bit(g_32led,g_32a);
   output_bit(g_4led7doan,g_4a);
   output_bit(g_lcd20x4,g_lcda);  
   cho_ic_74573_a_goi_du_lieu;
}  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void mo_ic_74573_b_thong_dl()
{     
   output_d(0x00);
   output_bit(g_matranled,g_mtb);
   output_bit(g_8ledquet,g_8b);
   output_bit(g_buzerelay,g_rbdcb); 
   cho_ic_74573_b_goi_du_lieu;
}                                  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//ham khoi tao cac port va ic chot
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void set_up_port_ic_chot()
{     
   set_tris_d(0x00);                    
   output_d(0xff);
   tin_hieu_dk_74573_a=0xff;            
   tin_hieu_dk_74573_b=0xff;      
   chot_ic_74573_a_goi_du_lieu;
   chot_ic_74573_b_goi_du_lieu;  
   set_tris_a(0x1f);
   set_tris_e(0x00);
   set_tris_B(0x3c);     
   rbdc=0;

   setup_adc(adc_clock_div_32);
   setup_adc_ports(an0_to_an2|vss_vdd );         
   set_adc_channel(2);
   reset_cac_bien();
} 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//ham 102: xuat 1 byte ra thanh ghi dich
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void xuat_1byte(unsigned int8 bytexuat)
{                        
   unsigned int8   sb;   
   #bit bseri  = bytexuat.7                      
   for (sb=0;sb<8;sb++)
   {                                                 
      output_bit(ssdo,bseri);    
      output_low(ssck); output_high(ssck);
      bytexuat = bytexuat<<1;         
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//module dieu khien relay,triac, buzzer, dong co, sim
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_buzzer_relay()
{     
   unsigned int8 rbdc1,rbdc2;
   rbdc1=rbdc; rbdc2=rbdc>>8;      
   xuat_1byte(rbdc2);      xuat_1byte(rbdc1);      
   mo_relay_buzzer_dc;
   mo_ic_74573_b_thong_dl();
      
   output_high(rck_buzerelay);   output_low(rck_buzerelay);
   chot_ic_74573_b_goi_du_lieu;
}
//ham 602
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void buzzer_on()
{    
   buzzer=1;
   xuat_buzzer_relay();         
}
//ham 603
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void buzzer_off()
{     
   buzzer=0;
   xuat_buzzer_relay();
}
//ham 604
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void relay_1_on()
{    
   relay_1=1;
   xuat_buzzer_relay();         
}
//ham 603
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void relay_1_off()
{    
   relay_1=0;
   xuat_buzzer_relay();         
}
//ham 604
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void relay_2_on()
{    
   relay_2=1;
   xuat_buzzer_relay();         
}
//ham 607
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void relay_2_off()
{    
   relay_2=0;
   xuat_buzzer_relay();         
}
//ham 608
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void relay_1_relay_2_on()
{    
   relay_1=1;  relay_2=1;
   xuat_buzzer_relay();         
}
//ham 609
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void relay_1_relay_2_off()
{    
   relay_1=0;  relay_2=0;
   xuat_buzzer_relay();         
}
//ham 610
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void triac_1_on()
{    
   triac_1=1;
   xuat_buzzer_relay();         
}   
//ham 611
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void triac_1_off()
{    
   triac_1=0;
   xuat_buzzer_relay();         
}
//ham 612
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void triac_2_on()
{    
   triac_2=1;
   xuat_buzzer_relay();         
}
//ham 613
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void triac_2_off()
{    
   triac_2=0;
   xuat_buzzer_relay();         
}  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx        
const unsigned char ma7doan[16]= {
0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
#define     maso0    0xc0
#define     maso1    0xf9                         
#define     maso2    0xa4    
#define     maso3    0xb0
#define     maso4    0x99
#define     maso5    0x92
#define     maso6    0x82                     
#define     maso7    0xf8  
