//ham 501
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat 2 byte ra dk 1 led quet sang
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_8led_7doan_quet_1(unsigned int ma,so_hthi)
{     
      xuat_1byte(~ma);   xuat_1byte(~so_hthi);
      
      mo_8_led_quet;
      mo_ic_74573_b_thong_dl();
      
      output_high(rck_8ledquet); output_low(rck_8ledquet);
      chot_ic_74573_b_goi_du_lieu;
}
//ham 502
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat 2 byte ra tat 8 led quet
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_8led_7doan_quet_tat_led()
{
   xuat_8led_7doan_quet_1(0xff,0xff);
}
//ham 503
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con hien thi led theo thu tu
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
const unsigned char ttledquet[8]= {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
void xuat_8led_7doan_quet_2(unsigned int thutuled,so_hthi)
{         
      xuat_1byte(~ (ttledquet[thutuled]));   xuat_1byte(~so_hthi);     
      mo_8_led_quet;
      mo_ic_74573_b_thong_dl();
      output_high(rck_8ledquet); output_low(rck_8ledquet);
      chot_ic_74573_b_goi_du_lieu;
}
//ham 504
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con hien thi 8 so tren 8 led quet - co kiem tra
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
unsigned char led_7dq[8]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
unsigned int8 tt8led=0;
void hien_thi_8led_7doan_quet()
{     
      for(tt8led=0;tt8led<8;tt8led++)
         if (led_7dq[tt8led]!=0xff)
         {           
            xuat_8led_7doan_quet_2(tt8led, led_7dq[tt8led]);
            delay_us(100);
            xuat_8led_7doan_quet_tat_led();           
            }
}
//ham 505
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con hien thi 8 so tren 8 led quet - khong kiem tra
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void hien_thi_8led_7doan_quet_all()
{     
      for(tt8led=0;tt8led<8;tt8led++)         
         {           
            xuat_8led_7doan_quet_2(tt8led, led_7dq[tt8led]);
            delay_us(100);
            xuat_8led_7doan_quet_tat_led();           
            }
}

void delay_quet_8led(unsigned int16 dl)
{ 
      unsigned int8 i;
      for (i=0; i<dl;i++)
      hien_thi_8led_7doan_quet_all();
} 

void giai_ma_gan_cho_8led_quet_16_xoa(unsigned int16 x)
{     
      led_7dq[0]= ma7doan [x %10];    
      led_7dq[1]= ma7doan [x/10%10];
      led_7dq[2]= ma7doan [x/100%10];    
      led_7dq[3]= ma7doan [x/1000%10];
      led_7dq[4]= ma7doan [x/10000%10];
      if (led_7dq[4]==maso0) 
      {
            led_7dq[4]=0xff;
            if (led_7dq[3]==maso0) 
            {
               led_7dq[3]=0xff;
               if (led_7dq[2]==maso0) 
               {
                  led_7dq[2]=0xff;
                  if (led_7dq[1]==maso0) 
                  {
                     led_7dq[1]=0xff;
                  }
               }
            }
      }
            
}
         

