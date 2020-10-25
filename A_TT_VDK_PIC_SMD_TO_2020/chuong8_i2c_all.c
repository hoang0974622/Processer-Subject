//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//TAT CA DEU VIET THEO BAI VA HAM THEO BAI
#define solando 100
#define gioihan_dk 180
#define pir pin_a3

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//Khai bao bien DS13B07  ADC-DAC PCF8591  EEPROM NT AT24C256 
unsigned int16 k;
unsigned char giatri_mod=0;
unsigned int16 giay_ch=0x00,phut_ch=0x00,gio_ch=0x7,ttsd=0;
unsigned int8 dac=0;
unsigned int16 adc_lm35a,adc_lm35b,adc_cds;
int1 tt_triac=0,tt_triac1=0;
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void khoi_tao_ds13b07()
{
   lcd_command(lcd_addr_line1);
   lcd_data("clock:");
   doc_thoi_gian_tu_realtime();
   if (ma_ds13!=ma_ds)
   {
   thiet_lap_thoi_gian_hien_tai();
   nap_thoi_gian_htai_vao_ds1307();
   }
   //thiet_lap_thoi_gian_hien_tai();
   //nap_thoi_gian_htai_vao_ds1307();
   
   doc_thoi_gian_tu_realtime();
   giaytam=giay_ds13; 
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void hien_thi_gia_tri_mod ( )
{
   lcd_command(0x8a);
   lcd_data(giatri_mod+0x30);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
unsigned int8 hieu_chinh_so_bcd_tang(unsigned int8 x )
{
   unsigned int8 y;
   y = x;
   x = x & 0x0f;
   if (x==0x0a) y = y + 6;
   return(y);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
unsigned int8 hieu_chinh_so_bcd_giam(unsigned int8 x )
{
   unsigned int8 y;
   y = x;
   x = x & 0x0f;
   if (x==0x0f) y = y - 6;
   return(y);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void luu_giai_ma_hien_thi_sau_khi_chinh()
{
   nap_thoi_gian_htai_vao_ds1307();
   hien_thi_thoi_gian_ds1307 ( );
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 801: doc thoi gian thuc hien thi tren lcd 20x4
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_801_i2c_rt_lcd()
{
   doc_thoi_gian_tu_realtime();
   if (giaytam!=giay_ds13)
   {
   giaytam=giay_ds13;
   hien_thi_thoi_gian_ds1307 ( );
   }
   delay_ms(500);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 802: doc thoi gian thuc hien thi tren lcd 20x4, co 3 nut chinh up down mod
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_802_phim_mod()
{
   if (!input(mod))
   {
      delay_ms(20);
      {
         if (!input(mod))
         {
            if(giatri_mod<3) giatri_mod++;
            else giatri_mod=0;
            hien_thi_gia_tri_mod( );
            while(!input(mod));
         }
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_802_phim_up()
{
   if (!input(up))
   {
      delay_ms(20);
      if (!input(up))
      {
         switch (giatri_mod)
         {
            case 1:  if (giay_ds13==0x59) giay_ds13=0;
                     else
                     {
                        giay_ds13++;
                        giay_ds13=hieu_chinh_so_bcd_tang(giay_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 2:  if (phut_ds13==0x59) phut_ds13=0;
                     else
                     {
                        phut_ds13++;
                        phut_ds13=hieu_chinh_so_bcd_tang(phut_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 3:  if (gio_ds13==0x23) gio_ds13=0;
                     else
                     {
                        gio_ds13++;
                        gio_ds13=hieu_chinh_so_bcd_tang(gio_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
                     
            default: break;
         }
         while(!input(up));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_802_phim_dw()
{
   if (!input(dw))
   {
      delay_ms(20);
      if (!input(dw))
      {
         switch (giatri_mod)
         {
            case 1:  if (giay_ds13==0) giay_ds13=0x59;
                     else
                     {
                        giay_ds13--;
                        giay_ds13=hieu_chinh_so_bcd_giam(giay_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 2:  if (phut_ds13==0) phut_ds13=0x59;
                     else
                     {
                        phut_ds13--;
                        phut_ds13=hieu_chinh_so_bcd_giam(phut_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 3:  if (gio_ds13==0) gio_ds13=0x23;
                     else
                     {
                        gio_ds13--;
                        gio_ds13=hieu_chinh_so_bcd_giam(gio_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
                     
            default: break;
         }
         while(!input(dw));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_802_i2c_rt_lcd_3key()
{
   doc_thoi_gian_tu_realtime();
   if (giaytam!=giay_ds13)
   {
      giaytam=giay_ds13;
      hien_thi_gia_tri_mod ( );
      hien_thi_thoi_gian_ds1307 ( );
   }
   for(k=0;k<10000;k++)
   {
      ham_802_phim_mod();
      ham_802_phim_up();
      ham_802_phim_dw();
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 803: doc thoi gian thuc hien thi tren lcd 20x4, co 3 nut chinh up down mod, them chuc nang chinh ngay thang nam
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_803_phim_mod()
{
   if (!input(mod))
   {
      delay_ms(20);
      {
         if (!input(mod))
         {
            if(giatri_mod<6) giatri_mod++;
            else giatri_mod=0;
            hien_thi_gia_tri_mod( );
            while(!input(mod));
         }
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_803_phim_up()
{
   if (!input(up))
   {
      delay_ms(20);
      if (!input(up))
      {
         switch (giatri_mod)
         {
            case 1:  if (giay_ds13==0x59) giay_ds13=0;
                     else
                     {
                        giay_ds13++;
                        giay_ds13=hieu_chinh_so_bcd_tang(giay_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 2:  if (phut_ds13==0x59) phut_ds13=0;
                     else
                     {
                        phut_ds13++;
                        phut_ds13=hieu_chinh_so_bcd_tang(phut_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 3:  if (gio_ds13==0x23) gio_ds13=0;
                     else
                     {
                        gio_ds13++;
                        gio_ds13=hieu_chinh_so_bcd_tang(gio_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 4:  if (ngay_ds13==0x31) ngay_ds13=1;
                     else   
                     {
                        ngay_ds13++;
                        ngay_ds13=hieu_chinh_so_bcd_tang(ngay_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 5:  if (thang_ds13==0x12) thang_ds13=1;
                     else
                     {
                        thang_ds13++;
                        thang_ds13=hieu_chinh_so_bcd_tang(thang_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 6: if (nam_ds13==0x99) nam_ds13=0;
                     else
                     {
                        nam_ds13++;
                        nam_ds13=hieu_chinh_so_bcd_tang(nam_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
                     
            default: break;
         }
         while(!input(up));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_803_phim_dw()
{
   if (!input(dw))
   {
      delay_ms(20);
      if (!input(dw))
      {
         switch (giatri_mod)
         {
            case 1:  if (giay_ds13==0) giay_ds13=0x59;
                     else
                     {
                        giay_ds13--;
                        giay_ds13=hieu_chinh_so_bcd_giam(giay_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 2:  if (phut_ds13==0) phut_ds13=0x59;
                     else
                     {
                        phut_ds13--;
                        phut_ds13=hieu_chinh_so_bcd_giam(phut_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 3:  if (gio_ds13==0) gio_ds13=0x23;
                     else
                     {
                        gio_ds13--;
                        gio_ds13=hieu_chinh_so_bcd_giam(gio_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 4:  if (ngay_ds13==0) ngay_ds13=0x31;
                     else
                     {
                        ngay_ds13--;
                        ngay_ds13=hieu_chinh_so_bcd_giam(ngay_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 5:  if (thang_ds13==1) thang_ds13=0x12;
                     else
                     {
                        thang_ds13--;
                        thang_ds13=hieu_chinh_so_bcd_giam(thang_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 6:  if (nam_ds13==0) nam_ds13=0x99;
                     else
                     {
                        nam_ds13--;
                        nam_ds13=hieu_chinh_so_bcd_giam(nam_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;       
                     
            default: break;
         }
         while(!input(dw));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_803_nhap_nhay_con_tro()
{
   switch (giatri_mod)
   {
      case 1:  lcd_command(0xd3);
               break;
      case 2:  lcd_command(0xd0);
               break;
      case 3:  lcd_command(0xcd);
               break;
      case 4:  lcd_command(0x8d);
               break;
      case 5:  lcd_command(0x90);
               break;
      case 6:  lcd_command(0x93);
               break;
               
      default: break;
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_803_i2c_rt_lcd_3key()
{
   doc_thoi_gian_tu_realtime();
   if (giaytam!=giay_ds13)
   {
      giaytam=giay_ds13;
      hien_thi_gia_tri_mod ( );
      hien_thi_thoi_gian_ds1307 ( );
   }
   for(k=0;k<10000;k++)
   {
      //ham_803_nhap_nhay_con_tro();
      ham_803_phim_mod();
      ham_803_phim_up();
      ham_803_phim_dw();
   }
   if (giatri_mod!=0) ham_803_nhap_nhay_con_tro();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 804: doc thoi gian thuc hien thi tren lcd 20x4, co 3 nut chinh up down mod, them chuc nang chinh ngay thang nam, co nhap nhanh
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_804_phim_mod()
{
   if (!input(mod))
   {
      delay_ms(20);
      {
         if (!input(mod))
         {
            if(giatri_mod<6) giatri_mod++;
            else giatri_mod=0;
            hien_thi_gia_tri_mod( );
            while(!input(mod));
         }
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_804_phim_up()
{
   if (!input(up))
   {
      delay_ms(20);
      if (!input(up))
      {
         switch (giatri_mod)
         {
            case 1:  if (giay_ds13==0x59) giay_ds13=0;
                     else
                     {
                        giay_ds13++;
                        giay_ds13=hieu_chinh_so_bcd_tang(giay_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 2:  if (phut_ds13==0x59) phut_ds13=0;
                     else
                     {
                        phut_ds13++;
                        phut_ds13=hieu_chinh_so_bcd_tang(phut_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 3:  if (gio_ds13==0x23) gio_ds13=0;
                     else
                     {
                        gio_ds13++;
                        gio_ds13=hieu_chinh_so_bcd_tang(gio_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 4:  if (ngay_ds13==0x31) ngay_ds13=1;
                     else   
                     {
                        ngay_ds13++;
                        ngay_ds13=hieu_chinh_so_bcd_tang(ngay_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 5:  if (thang_ds13==0x12) thang_ds13=1;
                     else
                     {
                        thang_ds13++;
                        thang_ds13=hieu_chinh_so_bcd_tang(thang_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 6: if (nam_ds13==0x99) nam_ds13=0;
                     else
                     {
                        nam_ds13++;
                        nam_ds13=hieu_chinh_so_bcd_tang(nam_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
                     
            default: break;
         }
         while(!input(up));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_804_phim_dw()
{
   if (!input(dw))
   {
      delay_ms(20);
      if (!input(dw))
      {
         switch (giatri_mod)
         {
            case 1:  if (giay_ds13==0) giay_ds13=0x59;
                     else
                     {
                        giay_ds13--;
                        giay_ds13=hieu_chinh_so_bcd_giam(giay_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 2:  if (phut_ds13==0) phut_ds13=0x59;
                     else
                     {
                        phut_ds13--;
                        phut_ds13=hieu_chinh_so_bcd_giam(phut_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 3:  if (gio_ds13==0) gio_ds13=0x23;
                     else
                     {
                        gio_ds13--;
                        gio_ds13=hieu_chinh_so_bcd_giam(gio_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 4:  if (ngay_ds13==0) ngay_ds13=0x31;
                     else
                     {
                        ngay_ds13--;
                        ngay_ds13=hieu_chinh_so_bcd_giam(ngay_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 5:  if (thang_ds13==1) thang_ds13=0x12;
                     else
                     {
                        thang_ds13--;
                        thang_ds13=hieu_chinh_so_bcd_giam(thang_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 6:  if (nam_ds13==0) nam_ds13=0x99;
                     else
                     {
                        nam_ds13--;
                        nam_ds13=hieu_chinh_so_bcd_giam(nam_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;       
                     
            default: break;
         }
         while(!input(dw));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_804_nhap_nhay_con_tro()
{
   switch (giatri_mod)
   {
      case 1:  lcd_goto_xy(3,9); lcd_data("  ");
               break;
      case 2:  lcd_goto_xy(3,6); lcd_data("  ");
               break;
      case 3:  lcd_goto_xy(3,3); lcd_data("  ");
               break;
      case 4:  lcd_goto_xy(3,12); lcd_data("  ");
               break;
      case 5:  lcd_goto_xy(3,15); lcd_data("  ");
               break;
      case 6:  lcd_goto_xy(3,18); lcd_data("  ");
               break;
               
      default: break;
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_804_i2c_rt_lcd_3key_nn()
{
   doc_thoi_gian_tu_realtime();
   if (giaytam!=giay_ds13)
   {
      giaytam=giay_ds13;
      hien_thi_gia_tri_mod ( );
      hien_thi_thoi_gian_ds1307 ( );
   }
   for(k=0;k<10000;k++)
   {
      //ham_804_nhap_nhay_con_tro();
      ham_804_phim_mod();
      ham_804_phim_up();
      ham_804_phim_dw();
   }
   if (giatri_mod!=0) ham_804_nhap_nhay_con_tro();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//bai 805 doc thoi gian tren ds1307 co 3 nut nhan chinh duoc ngay thang nam buzzer
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_805_i2c_rt_lcd_3key_buzzer()
{
   bai_804_i2c_rt_lcd_3key_nn();
   if(giay_ds13 == 0x59)
   {
      //buzzer_on();
      delay_ms(200);
      buzzer_off();
   }
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 806: hieu chinh 804 them chuc nang hen gio
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_806_phim_mod()
{
   if (!input(mod))
   {
      delay_ms(20);
      {
         if (!input(mod))
         {
            if(giatri_mod<3) giatri_mod++;
            else giatri_mod=0;
            hien_thi_gia_tri_mod( );
            while(!input(mod));
         }
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_806_phim_up()
{
   if (!input(up))
   {
      delay_ms(20);
      if (!input(up))
      {
         switch (giatri_mod)
         {
            case 1:  if (giay_ch==0x59) giay_ch=0;
                     else
                     {
                        giay_ch++;
                        giay_ch=hieu_chinh_so_bcd_tang(giay_ch);
                     }
                     //luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 2:  if (phut_ch==0x59) phut_ch=0;
                     else
                     {
                        phut_ch++;
                        phut_ch=hieu_chinh_so_bcd_tang(phut_ch);
                     }
                     //luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 3:  if (gio_ch==0x23) gio_ch=0;
                     else
                     {
                        gio_ch++;
                        gio_ch=hieu_chinh_so_bcd_tang(gio_ch);
                     }
                     //luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;    
                     
            default: break;
         }
         while(!input(up));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_806_phim_dw()
{
   if (!input(dw))
   {
      delay_ms(20);
      if (!input(dw))
      {
         switch (giatri_mod)
         {
            case 1:  if (giay_ch==0) giay_ch=0x59;
                     else
                     {
                        giay_ch--;
                        giay_ch=hieu_chinh_so_bcd_giam(giay_ch);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 2:  if (phut_ch==0) phut_ch=0x59;
                     else
                     {
                        phut_ch--;
                        phut_ch=hieu_chinh_so_bcd_giam(phut_ch);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 3:  if (gio_ch==0) gio_ch=0x23;
                     else
                     {
                        gio_ch--;
                        gio_ch=hieu_chinh_so_bcd_giam(gio_ch);
                     }
                     //luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;                          
                     
            default: break;
         }
         while(!input(dw));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_806_nhap_nhay_con_tro()
{
   switch (giatri_mod)
   {
         case 3:  lcd_goto_xy(2,3);
                  lcd_data(' ');
                  lcd_goto_xy(2,4);
                  lcd_data(' ');
                  break;
         case 2:  lcd_goto_xy(2,6);
                  lcd_data(' ');
                  lcd_goto_xy(2,7);
                  lcd_data(' ');
                  break;
         case 1:  lcd_goto_xy(2,9);
                  lcd_data(' ');
                  lcd_goto_xy(2,10);
                  lcd_data(' ');
                  break;
         default: break;
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_806_hien_thi_gio_canh_bao_lcd()
{     
      lcd_goto_xy(2,3);  //lcd_command (0x8c);
      lcd_data(gio_ch/16  +0x30);    lcd_data(gio_ch%16  +0x30);
      lcd_data(' ');
      lcd_data(phut_ch/16 +0x30);    lcd_data(phut_ch%16 +0x30);
      lcd_data(' ');
      lcd_data(giay_ch/16 +0x30);    lcd_data(giay_ch%16 +0x30);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_806_i2c_rt_lcd_3key_alram()
{
   doc_thoi_gian_tu_realtime();
   ham_806_hien_thi_gio_canh_bao_lcd();
   if (giaytam!=giay_ds13)
   {
      giaytam=giay_ds13;
      hien_thi_gia_tri_mod ( );
      hien_thi_thoi_gian_ds1307 ( );    
   }
   if((gio_ch==gio_ds13)&&(phut_ch==phut_ds13)&&(giay_ch==giay_ds13)&&flag==0)
   {
      //buzzer_on();
      xuat_32led_don_4byte(0xff,0xff,0xff,0xff);
      flag=1;
      ttsd=giay_ds13;
   }
   if(flag==1)
   {
      if((ttsd+5)<=giay_ds13)
      {
         xuat_32led_don_4byte(0,0,0,0);
         flag=0;
      }
      //buzzer_off();
   }

   for(k=0;k<10000;k++)
   {
      ham_806_phim_mod();
      ham_806_phim_up();
      ham_806_phim_dw();
   }
   if (giatri_mod!=0) ham_806_nhap_nhay_con_tro();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 807: hieu chinh 805 co them cac moc thoi gian chuong reo
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_807_phim_mod()
{
   if (!input(mod))
   {
      delay_ms(20);
      {
         if (!input(mod))
         {
            if(giatri_mod<6) giatri_mod++;
            else giatri_mod=0;
            hien_thi_gia_tri_mod( );
            while(!input(mod));
         }
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_807_phim_up()
{
   if (!input(up))
   {
      delay_ms(20);
      if (!input(up))
      {
         switch (giatri_mod)
         {
            case 1:  if (giay_ds13==0x59) giay_ds13=0;
                     else
                     {
                        giay_ds13++;
                        giay_ds13=hieu_chinh_so_bcd_tang(giay_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 2:  if (phut_ds13==0x59) phut_ds13=0;
                     else
                     {
                        phut_ds13++;
                        phut_ds13=hieu_chinh_so_bcd_tang(phut_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 3:  if (gio_ds13==0x23) gio_ds13=0;
                     else
                     {
                        gio_ds13++;
                        gio_ds13=hieu_chinh_so_bcd_tang(gio_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 4:  if (ngay_ds13==0x31) ngay_ds13=1;
                     else   
                     {
                        ngay_ds13++;
                        ngay_ds13=hieu_chinh_so_bcd_tang(ngay_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 5:  if (thang_ds13==0x12) thang_ds13=1;
                     else
                     {
                        thang_ds13++;
                        thang_ds13=hieu_chinh_so_bcd_tang(thang_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 6: if (nam_ds13==0x99) nam_ds13=0;
                     else
                     {
                        nam_ds13++;
                        nam_ds13=hieu_chinh_so_bcd_tang(nam_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
                     
            default: break;
         }
         while(!input(up));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_807_phim_dw()
{
   if (!input(dw))
   {
      delay_ms(20);
      if (!input(dw))
      {
         switch (giatri_mod)
         {
            case 1:  if (giay_ds13==0) giay_ds13=0x59;
                     else
                     {
                        giay_ds13--;
                        giay_ds13=hieu_chinh_so_bcd_giam(giay_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 2:  if (phut_ds13==0) phut_ds13=0x59;
                     else
                     {
                        phut_ds13--;
                        phut_ds13=hieu_chinh_so_bcd_giam(phut_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 3:  if (gio_ds13==0) gio_ds13=0x23;
                     else
                     {
                        gio_ds13--;
                        gio_ds13=hieu_chinh_so_bcd_giam(gio_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 4:  if (ngay_ds13==0) ngay_ds13=0x31;
                     else
                     {
                        ngay_ds13--;
                        ngay_ds13=hieu_chinh_so_bcd_giam(ngay_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 5:  if (thang_ds13==1) thang_ds13=0x12;
                     else
                     {
                        thang_ds13--;
                        thang_ds13=hieu_chinh_so_bcd_giam(thang_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;
            case 6:  if (nam_ds13==0) nam_ds13=0x99;
                     else
                     {
                        nam_ds13--;
                        nam_ds13=hieu_chinh_so_bcd_giam(nam_ds13);
                     }
                     luu_giai_ma_hien_thi_sau_khi_chinh();
                     break;       
                     
            default: break;
         }
         while(!input(dw));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_807_nhap_nhay_con_tro()
{
   switch (giatri_mod)
   {
      case 1:  lcd_goto_xy(3,9); lcd_data("  ");
               break;
      case 2:  lcd_goto_xy(3,6); lcd_data("  ");
               break;
      case 3:  lcd_goto_xy(3,3); lcd_data("  ");
               break;
      case 4:  lcd_goto_xy(3,12); lcd_data("  ");
               break;
      case 5:  lcd_goto_xy(3,15); lcd_data("  ");
               break;
      case 6:  lcd_goto_xy(3,18); lcd_data("  ");
               break;
               
      default: break;
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_807_hien_thi_gio_canh_bao_lcd()
{     
      lcd_goto_xy(2,3);  //lcd_command (0x8c);
      lcd_data(gio_ch/16  +0x30);    lcd_data(gio_ch%16  +0x30);
      lcd_data(' ');
      lcd_data(phut_ch/16 +0x30);    lcd_data(phut_ch%16 +0x30);
      lcd_data(' ');
      lcd_data(giay_ch/16 +0x30);    lcd_data(giay_ch%16 +0x30);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_807_i2c_rt_lcd_3key_chuong()
{
   doc_thoi_gian_tu_realtime();
   ham_806_hien_thi_gio_canh_bao_lcd();
   if((gio_ch==gio_ds13)&&(phut_ch==phut_ds13)&&(giay_ch==giay_ds13)&&flag==0)
   {
      //buzzer_on();
      if((gio_ch==0x07)&&(phut_ch==0x00)&&(giay_ch==0x00))
      {
         gio_ch=0x07;
         phut_ch=0x02;
         giay_ch=0x00;
      }
      if((gio_ch==0x07)&&(phut_ch==0x02)&&(giay_ch==0x00))
      {
         gio_ch=0x07;
         phut_ch=0x04;
         giay_ch=0x00;
      }      
      ttsd=giay_ds13;
      xuat_32led_don_4byte(0xff,0xff,0xff,0xff);
      flag=1;
   }
   if(flag==1)
   {
      if((ttsd+5)<=giay_ds13)
      {
         xuat_32led_don_4byte(0,0,0,0);
         flag=0;
      }
      //buzzer_off();
   }
   if (giaytam!=giay_ds13)
   {
      giaytam=giay_ds13;
      hien_thi_gia_tri_mod ( );
      hien_thi_thoi_gian_ds1307 ( );
   }
   for(k=0;k<10000;k++)
   {
      //ham_804_nhap_nhay_con_tro();
      ham_807_phim_mod();
      ham_807_phim_up();
      ham_807_phim_dw();
   }
   if (giatri_mod!=0) ham_807_nhap_nhay_con_tro();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 808: hieu chinh hien thi thoi gian so lon
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_808_hien_thi_thoi_gian_ds1307_so_z( )
{     lcd_goto_xy(1,0);  //lcd_command (0x8c);   
      lcd_hienthi_so_z_toado_xy((gio_ds13/16),2,0);
      lcd_hienthi_so_z_toado_xy((gio_ds13%16),2,3);
      lcd_data(' ');
      lcd_hienthi_so_z_toado_xy((phut_ds13/16),2,7);
      lcd_hienthi_so_z_toado_xy((phut_ds13%16),2,10);
      lcd_data(' ');
      lcd_hienthi_so_z_toado_xy((giay_ds13/16),2,14);
      lcd_hienthi_so_z_toado_xy((giay_ds13%16),2,17);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_808_i2c_rt_lcd_to()
{
   doc_thoi_gian_tu_realtime();
   lcd_command(0x40);
   for(i=0;i<64;i++) lcd_data(lcd_ma_8doan[i]);
   if (giaytam!=giay_ds13)
   {
      giaytam=giay_ds13;
      ham_808_hien_thi_thoi_gian_ds1307_so_z( );
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 809: hien thi thoi gian so lon va so nho bang 1 nut nha
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_809_phim_mod()
{
   if (!input(mod))
   {
      delay_ms(20);
      {
         if (!input(mod))
         {
            setup_lcd();
            if(giatri_mod<1) giatri_mod++;
            else giatri_mod=0;
            hien_thi_gia_tri_mod( );
            while(!input(mod));
         }
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_809_i2c_rt_lcd_to_nho()
{
   ham_809_phim_mod();
   if(giatri_mod==0)
   {
      bai_803_i2c_rt_lcd_3key();
   }
   else
   {
      bai_808_i2c_rt_lcd_to();
   }

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 811: do nhiet do lm35a voi kenh an0 cua ic ADC PCF 8591, hien thi 4 led 7 doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_811_pcf8591_4led_lm35a()
{
   pcf8591_chonkenh(pcf8591_channel_0); //lm35a
   delay_us(100);
   adc_lm35a=0;
   for(i=0;i<100;i++)
   {
      
      delay_us(20);
      adc_lm35a=adc_lm35a + pcf8591_doc_adc();
   }
   adc_lm35a= adc_lm35a/100;
   xuat_4led_7doan_giaima_xoa_so0(adc_lm35a);

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 812: giong 811 nhung nhiet do lon hon gioi han cai 40doC thi bao chuong
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_812_so_sanh_dk_buzzer()
{
   if((lm35a>nd_tren)&&(ttqn==0))
   {
      ttqn=1;
      //buzzer_on();
      xuat_32led_don_4byte(0xff,0xff,0xff,0xff);
   }
   else if((lm35a>nd_tren)&&(ttqn==1))
   {
      ttqn=0;
      //buzzer_off();
      xuat_32led_don_4byte(0,0,0,0);
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_812_pcf8591_4led_lm35a_buz()
{
   pcf8591_chonkenh(pcf8591_channel_0); //lm35a
   delay_us(100);
   adc_lm35a=0;
   for(i=0;i<100;i++)
   {
      
      delay_us(20);
      adc_lm35a=adc_lm35a + pcf8591_doc_adc();
   }
   adc_lm35a= adc_lm35a/100;
   xuat_4led_7doan_giaima_xoa_so0(adc_lm35a);
   ham_812_so_sanh_dk_buzzer();

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 813: giong 812 nhung do them lm35a kenh an1 va hien thi ben trai
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_813_doc_nd_lm35b()
{    
   pcf8591_chonkenh(pcf8591_channel_1); //lm35b
   delay_us(100);
   adc_lm35b=0;
   for(i=0;i<100;i++)
   {     
      delay_us(20);
      adc_lm35b=adc_lm35b + pcf8591_doc_adc();
   }
   adc_lm35b= adc_lm35b/100;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_813_pcf8591_4led_lm35a_buz()
{
   ham_813_doc_nd_lm35b();
   xuat_4led_7doan_2_so(adc_lm35b,adc_lm35a);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 814: tu dong do va khong che nhiet do trong tam 33 den 35do, khi nho hon 33 thi mo triac. khi nhiet do qua 35 thi tat triac va bat loa
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_814_so_sanh_dk_buzzer()
{
   if(lm35a>nd_tren && (ttqn==0))
   {
      ttqn=1;
      //buzzer_on();
      xuat_32led_don_4byte(0xff,0xff,0xff,0xff);
      triac_2_off();
   }
   else if((lm35a<nd_tren)&& (ttqn==1))
   {
      ttqn=0;
      //buzzer_off();
      xuat_32led_don_4byte(0,0,0,0);
   }
   else if((lm35a<nd_duoi) && (ttqn==0)) triac_2_on();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_814_doc_nd_lm35a()
{  
   pcf8591_chonkenh(pcf8591_channel_0); //lm35a
   delay_us(100);
   adc_lm35a=0;
   for(i=0;i<100;i++)
   {     
      delay_us(20);
      adc_lm35a=adc_lm35a + pcf8591_doc_adc();
   }
   adc_lm35a= adc_lm35a/100;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_814_pcf8591_4led_lm35a_buz_den()
{
   ham_814_doc_nd_lm35a();
   xuat_4led_7doan_2_so(0,adc_lm35a);
   ham_814_so_sanh_dk_buzzer();

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 815: do nhiet do tu 2 cam bien lm35a va lm35b
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_815_doc_nd_lm35a()
{  
   pcf8591_chonkenh(pcf8591_channel_0); //lm35a
   delay_us(100);
   adc_lm35a=0;
   for(i=0;i<100;i++)
   {     
      delay_us(20);
      adc_lm35a=adc_lm35a + pcf8591_doc_adc();
   }
   adc_lm35a= adc_lm35a/100;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_815_doc_nd_lm35b()
{    
   pcf8591_chonkenh(pcf8591_channel_1); //lm35b
   delay_us(100);
   adc_lm35b=0;
   for(i=0;i<100;i++)
   {     
      delay_us(20);
      adc_lm35b=adc_lm35b + pcf8591_doc_adc();
   }
   adc_lm35b= adc_lm35b/100;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_815_pcf8591_4led_lm35ab()
{
   ham_815_doc_nd_lm35a();
   ham_815_doc_nd_lm35b();
   xuat_4led_7doan_2_so(adc_lm35b,adc_lm35a);

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 821: do anh sang dung cam bien photocell cds pdv-p8103 noi voi kenh an3 cua adc pcf 8591, hien thi tren mdoule 4 led 7 doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_821_pcf8591_4led_cds()
{
   adc_cds=0;
   pcf8591_chonkenh(pcf8591_channel_2); //cds
   for(i=0;i<solando;i++)
   {
      delay_us(20);
      adc_cds=adc_cds + pcf8591_doc_adc();
   }
   adc_cds=adc_cds/solando;
   xuat_4led_7doan_giaima_xoa_so0(adc_cds);

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 822: dieu khien den tu dong sang su dung cam bien photocell cds pdv-p8103 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_822_sosanh_cds_dk_den()
{
   if ((adc_cds>gioihan_dk)&&(tt_triac==0))
   {
      tt_triac = 1;
      triac_2_on();
   }
   else if ((adc_cds<gioihan_dk-20)&&(tt_triac==1))
   {
      tt_triac = 0;
      triac_2_off();
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_822_pcf8591_4led_cds_on_off_den()
{
   adc_cds=0;
   pcf8591_chonkenh(pcf8591_channel_2); //cds
   for(i=0;i<solando;i++)
   {
      delay_us(20);
      adc_cds=adc_cds + pcf8591_doc_adc();
   }
   adc_cds=adc_cds/solando;
   xuat_4led_7doan_giaima_xoa_so0(adc_cds);
   ham_822_sosanh_cds_dk_den();

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 831: dieu khien den tu dong sang khi phat hien co nguoi chuyen dong hoac tat khi khong co nguoi chuyen dong 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_831_kiemtra_pir_mo_den()
{
   if(input(pir)&&(tt_triac==0))
   {
      triac_2_off();
      tt_triac=1;
   }
   else if (!input(pir)&&(tt_triac==1))
   {
      triac_2_on();
      tt_triac=0;
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_831_pir_dk_den()
{
   ham_831_kiemtra_pir_mo_den();

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 832: 2 yeu cau
//yc1: dung cam bien photocel cds pdv-p8103 de dieu khien den
///yc2: dung cam bien pir dieu khien den khi co nguoi va khong co nguoi,sang 32led
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_832_kiemtra_pir_mo_den()
{
   if(input(pir)&&(tt_triac==0))
   {
      triac_2_off();
      tt_triac=1;
   }
   else if (!input(pir)&&(tt_triac==1))
   {
      triac_2_on();
      tt_triac=0;
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_832_sosanh_cds_dk_den()
{
   if ((adc_cds>gioihan_dk)&&(tt_triac1==0))
   {
      tt_triac = 1;
      xuat_32led_don_4byte(0xff,0xff,0xff,0xff);
   }
   else if ((adc_cds<gioihan_dk-20)&&(tt_triac1==1))
   {
      tt_triac1 = 0;
      xuat_32led_don_4byte(0,0,0,0);
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_832_pir_dk_32led_cds_dk_den()
{
   adc_cds=0;
   pcf8591_chonkenh(pcf8591_channel_2); //cds
   for(i=0;i<solando;i++)
   {
      delay_us(20);
      adc_cds=adc_cds + pcf8591_doc_adc();
   }
   adc_cds=adc_cds/solando;
   xuat_4led_7doan_giaima_xoa_so0(adc_cds);
   ham_832_sosanh_cds_dk_den();
   ham_832_kiemtra_pir_mo_den();

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
