//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//TAT CA DEU VIET THEO BAI VA HAM THEO BAI
#define nd_tren 30
#define nd_duoi 25
#define gh_nda_tren 0x23
#define gh_nda_duoi 0x21
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void khoi_tao_adc()
{
   setup_adc(adc_clock_div_32);
   //setup_adc_ports(an0 | vss_vdd);
   //set_adc_channel(0);
   setup_adc_ports(an0_to_an1 | vss_vdd);
   //set_adc_channel(2);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//Khai bao bien TT SANG SO -ADC,CAC CAM BIEN
unsigned int8 j,solan=100;
unsigned int16 lm35a=0,lm35b=0,gtcdt=35;
unsigned int16 kqadc;
float k_cach,clk_cach;
int1 ttqn=0;
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 701: do nhiet do hien thi tren 4 led 7 doan dung adc kenh thu 0. Do trung binh 100 lan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_701_lm35a()
{
   for(j=0;j<solan;j++)
   {
      lm35a = lm35a + read_adc();
      delay_ms(1);
   }
   lm35a=lm35a/2.046;
   lm35a=lm35a/solan;
   xuat_4led_7doan_giaima_xoa_so0(lm35a);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 702: do nhiet do hien thi tren 4 led 7 doan dung adc kenh thu 0. Do trung binh 100 lan
// nhiet do qua 40 buzzer keu
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_702_so_sanh_dk_buzzer()
{
   if((lm35a>nd_tren)&&(ttqn==0))
   {
      ttqn=1;
      buzzer_on();
   }
   else if((lm35a>nd_tren)&&(ttqn==1))
   {
      ttqn=0;
      buzzer_off();
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_702_lm35a_buzz()
{
   for(j=0;j<solan;j++)
   {
      lm35a = lm35a + read_adc();
      delay_ms(1);
   }
   lm35a=lm35a/2.046;
   lm35a=lm35a/solan;
   xuat_4led_7doan_giaima_xoa_so0(lm35a);
   ham_702_so_sanh_dk_buzzer();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 703: do nhiet do hien thi tren 4 led 7 doan dung adc kenh thu 0. Do trung binh 100 lan
// che do mo den tu dong nhiet do qua 40 buzzer keu=> led tat de giam nhiet do va nguoc lai
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_703_so_sanh_dk_buzzer()
{
   if((lm35a>nd_tren)&&(ttqn==0))
   {
      ttqn=1;
      buzzer_on();
      triac_2_off();
   }
   else if((lm35a>nd_tren)&&(ttqn==1))
   {
      ttqn=0;
      buzzer_off();
   }
   else if((lm35a<nd_duoi)&&(ttqn==0)) triac_2_on();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_703_lm35a_buzz_auto()
{
   for(j=0;j<solan;j++)
   {
      lm35a = lm35a + read_adc();
      delay_ms(1);
   }
   lm35a=lm35a/2.046;
   lm35a=lm35a/solan;
   xuat_4led_7doan_giaima_xoa_so0(lm35a);
   ham_703_so_sanh_dk_buzzer();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 704: do nhiet do hien thi tren 4 led 7 doan va LCD chu to dung adc kenh thu 0. Do trung binh 100 lan
// che do mo den tu dong nhiet do qua 40 buzzer keu=> led tat de giam nhiet do va nguoc lai
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_704_so_sanh_dk_buzzer()
{
   if((lm35a>nd_tren)&&(ttqn==0))
   {
      ttqn=1;
      buzzer_on();
      triac_2_off();
   }
   else if((lm35a>nd_tren)&&(ttqn==1))
   {
      ttqn=0;
      buzzer_off();
   }
   else if((lm35a<nd_duoi)&&(ttqn==0)) triac_2_on();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_704_hienthi_lcd()
{
   lcd_hienthi_so_z_toado_xy(lm35a/10,2,0);
   lcd_hienthi_so_z_toado_xy(lm35a%10,2,3);   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_704_lm35a_buzz_auto()
{
   lcd_goto_xy(0,0);
   lcd_data("hien thi nhiet do");
   for(j=0;j<solan;j++)
   {
      lm35a = lm35a + read_adc();
      delay_ms(1);
   }
   lm35a=lm35a/2.046;
   lm35a=lm35a/solan;
   xuat_4led_7doan_giaima_xoa_so0(lm35a);
   ham_704_hienthi_lcd();
   lcd_command(0x40);
   for(i=0;i<64;i++) lcd_data(lcd_ma_8doan[i]);
   ham_704_so_sanh_dk_buzzer();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 705: do nhiet do 2 kenh hien thi tren 4 led 7 doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_705_doc_nd_lm35a()
{
   set_adc_channel(0);
   lm35a=0;
   for(j=0;j<solan;j++)
   {
      lm35a = lm35a + read_adc();
      delay_us(100);
   }
   lm35a=lm35a/2.046;
   lm35a=lm35a/solan;   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_705_doc_nd_lm35b()
{
   set_adc_channel(1);
   lm35b=0;
   for(j=0;j<solan;j++)
   {
      lm35b = lm35b + read_adc();
      delay_us(100);
   }
   lm35b=lm35b/2.046;
   lm35b=lm35b/solan;   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_705_adc_2lm35()
{
   ham_705_doc_nd_lm35a();
   ham_705_doc_nd_lm35b();
   xuat_4led_7doan_2_so(lm35b,lm35a);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 706: do nhiet do 2 kenh hien thi tren 4 led 7 doan co auto
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_706_doc_nd_lm35a()
{
   set_adc_channel(0);
   lm35a=0;
   for(j=0;j<solan;j++)
   {
      lm35a = lm35a + read_adc();
      delay_us(100);
   }
   lm35a=lm35a/2.046;
   lm35a=lm35a/solan;   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_706_doc_nd_lm35b()
{
   set_adc_channel(1);
   lm35b=0;
   for(j=0;j<solan;j++)
   {
      lm35b = lm35b + read_adc();
      delay_us(100);
   }
   lm35b=lm35b/2.046;
   lm35b=lm35b/solan;   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_706_so_sanh_dk_buzzer()
{
   if((lm35a>nd_tren|| lm35b>nd_tren) && (ttqn==0))
   {
      ttqn=1;
      //buzzer_on();
      xuat_32led_don_4byte(0xff,0xff,0xff,0xff);
      triac_2_off();
   }
   else if((lm35a<nd_tren) && (lm35b<nd_tren) && (ttqn==1))
   {
      ttqn=0;
      //buzzer_off();
      xuat_32led_don_4byte(0,0,0,0);
   }
   else if((lm35a<nd_duoi) && (lm35b<nd_duoi) && (ttqn==0)) triac_2_on();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_706_2lm35_buzz()
{
   ham_706_doc_nd_lm35a();
   ham_706_doc_nd_lm35b();
   ham_706_so_sanh_dk_buzzer();
   xuat_4led_7doan_2_so(lm35b,lm35a);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 707: cai tien 706 them hien thi LCD so to
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_707_doc_nd_lm35a()
{
   set_adc_channel(0);
   lm35a=0; 
   for(j=0;j<solan;j++)
   {
      lm35a = lm35a + read_adc();
      delay_us(100);
   }
   lm35a=lm35a/2.046;
   lm35a=lm35a/solan;   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_707_doc_nd_lm35b()
{
   set_adc_channel(1);
   lm35b=0;
   for(j=0;j<solan;j++)
   {
      lm35b = lm35b + read_adc();
      delay_us(100);
   }
   lm35b=lm35b/2.046;
   lm35b=lm35b/solan;   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_707_so_sanh_dk_buzzer()
{
   if((lm35a>nd_tren|| lm35b>nd_tren) && (ttqn==0))
   {
      ttqn=1;
      //buzzer_on();
      xuat_32led_don_4byte(0xff,0xff,0xff,0xff);
      triac_2_off();
   }
   else if((lm35a<nd_tren) && (lm35b<nd_tren) && (ttqn==1))
   {
      ttqn=0;
      //buzzer_off();
      xuat_32led_don_4byte(0,0,0,0);
   }
   else if((lm35a<nd_duoi) && (lm35b<nd_duoi) && (ttqn==0)) triac_2_on();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_707_hienthi_lcd()
{
   lcd_goto_xy(0,0);
   lcd_data("LM35A: ");
   lcd_hienthi_so_z_toado_xy(lm35a/10,0,9);
   lcd_hienthi_so_z_toado_xy(lm35a%10,0,12); 
   lcd_goto_xy(3,0);
   lcd_data("LM35B: ");
   lcd_hienthi_so_z_toado_xy(lm35b/10,2,9);
   lcd_hienthi_so_z_toado_xy(lm35b%10,2,12);     
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_707_2lm35_lcd()
{
   ham_707_doc_nd_lm35a();
   ham_707_doc_nd_lm35b();
   ham_707_so_sanh_dk_buzzer();
   xuat_4led_7doan_2_so(lm35b,lm35a);
   ham_707_hienthi_lcd();
   lcd_command(0x40);
   for(i=0;i<64;i++) lcd_data(lcd_ma_8doan[i]);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 708: do nhiet do hien thi tren 4 led 7 doan 
// doc gia tri T0 dem san pham
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_708_lm35a_counter_t0()
{
   for(j=0;j<solan/2;j++)
   {
      lm35a = lm35a + read_adc();
      delay_ms(1);
   }
   lm35a=lm35a/2.046;
   lm35a=lm35a/(solan/2);
   t0=get_timer0();
   if(t0!=t0_tam)
   {
      t0_tam=t0;
      if(t0>=100) set_timer0(1);
   }
   xuat_4led_7doan_2_so_xoa_so0(t0,lm35a);

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 709: do nhiet do hien thi tren 4 led 7 doan 
// 2 led hien thi nhiet do, 2 led hien thi gia tri cai co the tuy chinh bang nut nhan UP DW
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_709_doc_nd_lm35a()
{
   set_adc_channel(0);
   lm35a=0; 
   for(j=0;j<solan/2;j++)
   {
      lm35a = lm35a + read_adc();
      delay_us(100);
   }
   lm35a=lm35a/2.046;
   lm35a=lm35a/(solan/2);   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_709_so_sanh_dk_buzzer()
{
   if((lm35a>gtcdt) && (ttqn==0))
   {
      ttqn=1;
      //buzzer_on();
      xuat_32led_don_4byte(0xff,0xff,0xff,0xff);
      triac_2_off();
   }
   else if((lm35a<gtcdt) && (ttqn==1))
   {
      ttqn=0;
      //buzzer_off();
      xuat_32led_don_4byte(0,0,0,0);
   }
   else if((lm35a<(gtcdt-5)) && (ttqn==0)) triac_2_on();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_709_phim_up()
{
   if((!input(up)) && (gtcdt<60))
   {
      delay_ms(10);
      if(!input(up))
      {
         gtcdt++;
         xuat_4led_7doan_2_so_xoa_so0(gtcdt,lm35a);
         while(!input(up));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_709_phim_dw()
{
   if((!input(dw)) && (gtcdt>35))
   {
      delay_ms(10);
      if(!input(dw))
      {
         gtcdt--;
         xuat_4led_7doan_2_so_xoa_so0(gtcdt,lm35a);
         while(!input(dw));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_709_lm35_up_dw()
{
   ham_709_doc_nd_lm35a();
   ham_709_phim_up();
   ham_709_phim_dw();
   ham_709_so_sanh_dk_buzzer();
   xuat_4led_7doan_2_so(gtcdt,lm35a);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 710: do 2 kenh nhiet do adc hien thi tren lcd va dem san pham
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_710_doc_nd_lm35a()
{
   set_adc_channel(0);
   lm35a=0; 
   for(j=0;j<solan/2;j++)
   {
      lm35a = lm35a + read_adc();
      delay_us(100);
   }
   lm35a=lm35a/2.046;
   lm35a=lm35a/(solan/2);   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_710_doc_nd_lm35b()
{
   set_adc_channel(1);
   lm35b=0;
   for(j=0;j<solan;j++)
   {
      lm35b = lm35b + read_adc();
      delay_us(100);
   }
   lm35b=lm35b/2.046;
   lm35b=lm35b/solan;   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_710_so_sanh_dk_buzzer()
{
   if((lm35a>nd_tren|| lm35b>nd_tren) && (ttqn==0))
   {
      ttqn=1;
      //buzzer_on();
      xuat_32led_don_4byte(0xff,0xff,0xff,0xff);
      triac_2_off();
   }
   else if((lm35a<nd_tren) && (lm35b<nd_tren) && (ttqn==1))
   {
      ttqn=0;
      //buzzer_off();
      xuat_32led_don_4byte(0,0,0,0);
   }
   else if((lm35a<nd_duoi) && (lm35b<nd_duoi) && (ttqn==0)) triac_2_on();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_710_hienthi_lcd()
{
   lcd_goto_xy(0,0);
   lcd_data("NHIET DO LM35A: ");
   lcd_data(lm35a/10+0x30);
   lcd_data(lm35a%10+0x30); 
   lcd_goto_xy(1,0);
   lcd_data("NHIET DO LM35B: ");
   lcd_data(lm35b/10+0x30);
   lcd_data(lm35b%10+0x30);
   lcd_goto_xy(2,0);
   lcd_data("DEM SAN PHAM: ");
   lcd_data(t0/10+0x30);
   lcd_data(t0%10+0x30);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_710_lm35_counter_lcd()
{
   ham_710_doc_nd_lm35a();
   ham_710_doc_nd_lm35b();
   ham_710_so_sanh_dk_buzzer();
   t0=get_timer0();
   if(t0!=t0_tam)
   {
      t0_tam=t0;
      ham_710_hienthi_lcd();
   }
   ham_710_hienthi_lcd();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 711: do khoang cach dung led thu phat voi do phan giai 10cm
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_711_gp2d12_ss10cm()
{
   kqadc=read_adc();
   delay_ms(30);
   if     (kqadc>=490) k_cach=10;
   else if(kqadc>=276) k_cach=20;
   else if(kqadc>=194) k_cach=30;
   else if(kqadc>=150) k_cach=40;
   else if(kqadc>=122) k_cach=50;
   else if(kqadc>=106) k_cach=60;
   else if(kqadc>=96)  k_cach=70;
   else if(kqadc>=80)  k_cach=80;
   xuat_4led_7doan_giaima_xoa_so0(k_cach);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 712: do khoang cach dung led thu phat voi do phan giai 1cm
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_712_giai_ma_hienthi_4led(float tam)
{
   unsigned int16 x;
   x=(unsigned int16) tam;
   xuat_4led_7doan_giaima_xoa_so0(x);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_712_gp2d12_ss1cm()
{
    kqadc=0;
   for (j=0; j<20; j++)
   {
      kqadc=kqadc+read_adc();
      delay_ms(10);
   }
   kqadc=kqadc /20;
   if (kqadc <= 80) k_cach=80;
   else if ((kqadc>80) &&(kqadc<87))
   {
      clk_cach = kqadc-80;
      k_cach=80 - clk_cach/0.77;
   }
   else if (kqadc==87) k_cach=70;
   else if ((kqadc>87) &&(kqadc<106))
   {
      clk_cach = kqadc-87;
      k_cach=70 - clk_cach/2.11;
   }
   else if (kqadc==106) k_cach=60;
   else if ((kqadc>106) &&(kqadc<124))
   {
      clk_cach = kqadc-106;
      k_cach=60 - clk_cach/2;
   }
   else if (kqadc==124) k_cach=50;
   else if ((kqadc>124) &&(kqadc<150))
   {
      clk_cach = kqadc-124;
      k_cach=50 - clk_cach/2.88;
   }
   else if (kqadc==150) k_cach=40;
   else if ((kqadc>150) &&(kqadc<196))
   {
      clk_cach = kqadc-150;
      k_cach=40 - clk_cach/5.11;
   }
   else if (kqadc==196) k_cach=30;
   else if ((kqadc>196) &&(kqadc<276))
   {
      clk_cach = kqadc-196;
      k_cach=30 - clk_cach/8.88;
   }
   else if (kqadc==276) k_cach=20;
   else if ((kqadc>276) &&(kqadc<490))
   {
      clk_cach = kqadc-276;
      k_cach=20 - clk_cach/23.77;
   }
   else if (kqadc==490) k_cach=10;
   ham_712_giai_ma_hienthi_4led(k_cach);
   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 713: do khoang cach dung led thu phat voi do phan giai 1cm dung phuong trinh de tinh khoang cach
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_713_giai_ma_hienthi_4led(float tam)
{
   unsigned int16 x;
   x=(unsigned int16) tam;
   xuat_4led_7doan_giaima_xoa_so0(x);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_713_gp2d12_ss1cm()
{
   kqadc=read_adc();
   delay_ms(40);
   k_cach=pow(4277/kqadc,1.106);
   if (k_cach>80) k_cach=80;
   ham_713_giai_ma_hienthi_4led(k_cach);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 714: do 2 kenh nhiet do adc hien thi tren lcd, dem san pham va do khoang cach
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_714_doc_nd_lm35a()
{
   set_adc_channel(0);
   lm35a=0; 
   for(j=0;j<solan/2;j++)
   {
      lm35a = lm35a + read_adc();
      delay_us(100);
   }
   lm35a=lm35a/2.046;
   lm35a=lm35a/(solan/2);   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_714_doc_nd_lm35b()
{
   set_adc_channel(1);
   lm35b=0;
   for(j=0;j<solan;j++)
   {
      lm35b = lm35b + read_adc();
      delay_us(100);
   }
   lm35b=lm35b/2.046;
   lm35b=lm35b/solan;   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_714_doc_khoangcach_gp2d12()
{
   set_adc_channel(2);
   kqadc=read_adc();
   delay_ms(40);
   k_cach=pow(4277/kqadc,1.106);
   if (k_cach>80) k_cach=80;  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_714_hienthi_lcd()
{
   lcd_goto_xy(0,0);
   lcd_data("LM35A: ");
   lcd_data(lm35a/10+0x30);
   lcd_data(lm35a%10+0x30); 
   lcd_goto_xy(0,11);
   lcd_data("LM35B: ");
   lcd_data(lm35b/10+0x30);
   lcd_data(lm35b%10+0x30);
   lcd_goto_xy(1,0);
   lcd_data("DEM SAN PHAM: ");
   lcd_data(t0/10+0x30);
   lcd_data(t0%10+0x30);
   lcd_goto_xy(3,0);
   lcd_data("KC: ");
   lcd_data((unsigned int16) k_cach/10+0x30);
   lcd_data((unsigned int16) k_cach%10+0x30);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_714_lcd_2lm35_t0_gp2d12()
{
   ham_714_doc_nd_lm35a();
   ham_714_doc_nd_lm35b();
   ham_714_doc_khoangcach_gp2d12();
   t0=get_timer0();
   if(t0!=t0_tam)
   {
      t0_tam=t0;
   }
   ham_714_hienthi_lcd();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 731: doc nhiet do tu cam bien ds18b20a hien thi tren 2 led 7 doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_731_ds18b20a()
{

   if(touch_present()) {doc_giatri_ds18b20();}
   if(ds18al!=ds18a_tam)
   {
      ds18a_tam = ds18al;
      ds18a = ds18a>>4;
      ds18a = ds18a & 0x0ff;
      xuat_4led_7doan_giaima_xoa_so0(ds18a);
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 732: doc nhiet do tu cam bien ds18b20a hien thi tren 2 led 7 doan
// nhiet do lon hon 33 thi 16 led phao sang,16 led trai tat va khi nhiet do duoi 31 thi nguoc lai
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_732_ds18b20a_on_off_32led()
{

  if(touch_present()) {doc_giatri_ds18b20();}
   if(ds18al!=ds18a_tam)
   {
      ds18a_tam = ds18al;
      ds18a = ds18a>>4;
      ds18a = ds18a & 0x0ff;
      xuat_4led_7doan_giaima_xoa_so0(ds18a);
      if ((ds18a>gh_nda_tren)&&(ttqn==0))
      {
         ttqn = 1;
         xuat_32led_don_1dw(0x0000ffff);
      }
      else if ((ds18a<gh_nda_duoi)&&(ttqn==1))
      {
         ttqn = 0;
         xuat_32led_don_1dw(0xffff0000);
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 733: doc nhiet do tu cam bien ds18b20a hien thi tren 2 led 7 doan
// khong che tu dong nhiet do tu 33-35
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_733_ds18b20a_lcd_buzzer()
{
  if(touch_present()) {doc_giatri_ds18b20();}
   if(ds18al!=ds18a_tam)
   {
      ds18a_tam = ds18al;
      ds18a = ds18a>>4;
      ds18a = ds18a & 0x0ff;
      lcd_goto_xy(0,0);
      lcd_data("Nhiet do :  ");
      lcd_data( ds18a/10+0x30);
      lcd_data( ds18a%10+0x30);      
      //xuat_4led_7doan_giaima_xoa_so0(ds18a);
      if ((ds18a>gh_nda_tren)&&(ttqn==0))
      {
         ttqn = 1;
         triac_2_off();
         //buzzer_on();
         xuat_32led_don_1dw(0x00000000);
         xuat_4led_7doan_giaima_xoa_so0(35);
        
      }
      else if ((ds18a<gh_nda_duoi)&&(ttqn==1))
      {
         ttqn = 0;
         triac_2_on();
         //buzzer_off();
         xuat_4led_7doan_giaima_xoa_so0(33);
         xuat_32led_don_1dw(0xffffffff);
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 734: doc nhiet do tu cam bien ds18b20a hien thi tren 2 led 7 doan va cam bien lm35 de so sanh
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_734_doc_nd_lm35a()
{
   set_adc_channel(0);
   lm35a=0; 
   for(j=0;j<solan;j++)
   {
      lm35a = lm35a + read_adc();
      delay_us(100);
   }
   lm35a=lm35a/2.046;
   lm35a=lm35a/(solan);   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_734_ds18b20a_lm35a()
{
   ham_734_doc_nd_lm35a();
   if(touch_present()) {doc_giatri_ds18b20();}
   if(ds18al!=ds18a_tam)
   {
      ds18a_tam = ds18al;
      ds18a = ds18a>>4;
      ds18a = ds18a & 0x0ff;
      //xuat_4led_7doan_giaima_xoa_so0(ds18a);
      xuat_4led_7doan_2_so(lm35a,ds18a);
      if((lm35a>nd_tren) && (ttqn==0))
      {
         ttqn=1;
         //buzzer_on();
         xuat_32led_don_4byte(0xff,0xff,0xff,0xff);
         triac_2_off();
      }
      else if((lm35a<nd_tren) && (ttqn==1))
      {
         ttqn=0;
         //buzzer_off();
         xuat_32led_don_4byte(0,0,0,0);
      }
      else if((lm35a<nd_duoi) && (ttqn==0)) triac_2_on();
   }
   //ham_734_doc_nd_lm35a();
   //xuat_4led_7doan_2_so(lm35a,ds18a);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 735: doc nhiet do tu cam bien ds18b20a hien thi tren 2 led 7 doan va t0 hien thi ben trai dem tu 00-99
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_735_ds18b20a_t0()
{

   if(touch_present()) {doc_giatri_ds18b20();}
   if(ds18al!=ds18a_tam)
   {
      ds18a_tam = ds18al;
      ds18a = ds18a>>4;
      ds18a = ds18a & 0x0ff;
      //xuat_4led_7doan_giaima_xoa_so0(ds18a);
   }
   t0=get_timer0();
   if(t0!=t0_tam)
   {
      t0_tam=t0;
      if(t0>=100) set_timer0(1);
   }
   xuat_4led_7doan_2_so_xoa_so0(t0,ds18a);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx










