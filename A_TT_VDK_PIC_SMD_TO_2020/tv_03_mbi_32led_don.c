//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//ham 301
//chuong trinh con xuat 4 byte ra 32 led don
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void xuat_32led_don_4byte(unsigned int8 bld3,bld2,bld1,bld0)
{     
      xuat_1byte(bld3);          
      xuat_1byte(bld2);                     
      xuat_1byte(bld1);          
      xuat_1byte(bld0);            
      mo_32_led_don;      
      mo_ic_74573_a_thong_dl();            
      output_high(rck_32led);    output_low(rck_32led);
      chot_ic_74573_a_goi_du_lieu;      
}
//ham 302
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat 2 word 16 bitra 32 led don
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_32led_don_2word(unsigned int16 wld1, unsigned int16 wld0)
{     
     unsigned int8  b3,b2,b1,b0;
     b3 = wld1>>8;  b2 = wld1; 
     b1 = wld0>>8;  b0 = wld0;
     xuat_32led_don_4byte(b3,b2,b1,b0);
}
//ham 303
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat 1 double word ra 32 led don
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_32led_don_1dw(unsigned long long dwld)
{     
     unsigned int16  wd1,wd0;
     wd1 = dwld>>16;  wd0 = dwld;
     xuat_32led_don_2word(wd1,wd0);
} 

