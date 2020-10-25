//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//TAT CA DEU VIET THEO BAI VA HAM THEO BAI
#include <graphics.c>
#include <math.h>
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void khoi_tao_glcd()
{
   setup_glcd(glcd_text_mode);
   setup_glcd(glcd_graphic_mode);
   glcd_command(glcd_clear_display);
   glcd_mau_nen(0);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Khai bao bien LCD_GLCD
unsigned int8 gioi_han,flag=0,gioi_han_tam[2];
unsigned char hang1[20]={"                    "};
unsigned char hang2[20]={"                    "};
unsigned char hang3[20]={"                    "};
unsigned char hang4[20]={"                    "};
unsigned char hang1234[80]={"                                                                                "};
signed int8 dem;
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 601: hien thi 4 hang ki tu
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_601_lcd_hienthi_4hang()
{
  unsigned char hang1[]={"1 hien thi lcd 20x4** "};
  unsigned char hang2[]={"2 dai hoc su pham kt"};
  unsigned char hang3[]={"3 bo thi nghiem vdk "};
  unsigned char hang4[]={"0123456789abcdefghij"};
  
  lcd_command(lcd_addr_line1);
  for (i=0;i<20;i++) { lcd_data(hang1[i]); }
  
  lcd_command(lcd_addr_line2);
  for (i=0;i<20;i++) { lcd_data(hang2[i]); }
  
  lcd_command(lcd_addr_line3);
  for (i=0;i<20;i++) { lcd_data(hang3[i]); }
  
  lcd_command(lcd_addr_line4);
  for (i=0;i<20;i++) { lcd_data(hang4[i]); }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 602: hien thi 4 hang ki tu cach 2
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_602_lcd_hienthi_4hang()
{
  lcd_command(lcd_addr_line1);
  lcd_data("1 hien thi lcd 20x4** "); 
  
  lcd_command(lcd_addr_line2);
  lcd_data("2 dai hoc su pham kt"); 
  
  lcd_command(lcd_addr_line3);
  lcd_data("3 bo thi nghiem vdk "); 
  
  lcd_command(lcd_addr_line4);
  lcd_data("0123456789abcdefghij"); 
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 603: hien thi 4 hang 4 ki tu A B C D 4 goc
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_603_lcd_ht_4kytu_4goc()
{
  
  lcd_command(lcd_addr_line1);
  lcd_data("A"); 
  
  lcd_command(lcd_addr_line2);
  lcd_data("                   B"); 
  
  lcd_command(lcd_addr_line3);
  lcd_data("  C"); 
  
  lcd_command(lcd_addr_line4);
  lcd_data("                 D"); 
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 604: hien thi 2 hang ki tu va dich trai sau 1 khoang thoi gian tre 1 giay
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_604_lcd_ht_2hang_dich_trai()
{
  
  lcd_command(lcd_addr_line1);
  lcd_data("khoa dien - dien tu "); 
  
  lcd_command(lcd_addr_line2);
  lcd_data("bm dientucong nghiep"); 
  delay_ms(1000);
  lcd_command(lcd_shift_left);
  delay_ms(1000);

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 605: hien thi 2 hang ki tu va dich phai sau 1 khoang thoi gian tre 1 giay
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_605_lcd_ht_2hang_dich_phai()
{
  
  lcd_command(lcd_addr_line1);
  lcd_data("khoa dien - dien tu "); 
  
  lcd_command(lcd_addr_line2);
  lcd_data("bm dientucong nghiep"); 
  delay_ms(1000);
  lcd_command(lcd_shift_right);
  delay_ms(1000);

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 606: hien thi 2 hang ki tu va dich trai 2 hang tren xuong 3 hang duoi r dich phai tro lai 2 hang tren r lap lai sau 1 khoang thoi gian tre 1 giay
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_606_lcd_ht_2hang_dich_2c()
{
  
  lcd_command(lcd_addr_line1);
  lcd_data("khoa dien - dien tu "); 
  
  lcd_command(lcd_addr_line2);
  lcd_data("bm dientucong nghiep"); 
  delay_ms(1000);
   for(i=0;i<20;i++)
  {
   lcd_command(lcd_shift_left);
   delay_ms(1000);
  }
  for(i=0;i<20;i++)
  {
   lcd_command(lcd_shift_right);
   delay_ms(1000);
  }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 611: hien thi lcd dem giay
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_611_lcd_hienthi_dongho()
{
   lcd_goto_xy(0,18);
   delay_us(20);
   lcd_data(giay/10 + 0x30);
   lcd_data(giay%10 + 0x30);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_611_lcd_ht_dem_giay()
{
  lcd_goto_xy(0,0);
  lcd_data("DONG HO:");
  ham_611_lcd_hienthi_dongho();
  delay_ms(1000);
  giay++;
  if(giay==60) giay=0;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 612: hien thi lcd dem phut giay
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_612_lcd_hienthi_dongho()
{
   lcd_goto_xy(0,15);
   delay_us(20);
   lcd_data(phut/10 + 0x30);
   lcd_data(phut%10 + 0x30);
   lcd_data("-");
   lcd_data(giay/10 + 0x30);
   lcd_data(giay%10 + 0x30);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_612_lcd_ht_dem_phut_giay()
{
  lcd_goto_xy(0,0);
  lcd_data("DONG HO:");
  ham_612_lcd_hienthi_dongho();
  delay_ms(1000);
  giay++;
  if(giay==60)
   {
      giay=0;
      phut++;
      if(phut==60)
         phut=0;
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 613: hien thi lcd dem gio phut giay
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_613_lcd_hienthi_dongho()
{
   lcd_goto_xy(0,12);
   delay_us(20);
   lcd_data(gio/10 + 0x30);
   lcd_data(gio%10 + 0x30);
   lcd_data("-");
   lcd_data(phut/10 + 0x30);
   lcd_data(phut%10 + 0x30);
   lcd_data("-");
   lcd_data(giay/10 + 0x30);
   lcd_data(giay%10 + 0x30);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_613_lcd_ht_dem_gio_phut_giay()
{
  lcd_goto_xy(0,0);
  lcd_data("DONG HO:");
  ham_613_lcd_hienthi_dongho();
  delay_ms(1000);
  giay++;
  if(giay==60)
   {
      giay=0;
      phut++;
      if(phut==60)
      {
         phut=0;
         gio++;
         if(gio==24)
            gio=0;
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 614: hien thi lcd dem gio phut giay chinh xac co 3 nut nhan chinh thoi gian
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_614_lcd_hienthi_dongho()
{
   lcd_goto_xy(0,12);
   delay_us(20);
   lcd_data(gio/10 + 0x30);
   lcd_data(gio%10 + 0x30);
   lcd_data("-");
   lcd_data(phut/10 + 0x30);
   lcd_data(phut%10 + 0x30);
   lcd_data("-");
   lcd_data(giay/10 + 0x30);
   lcd_data(giay%10 + 0x30);
   
   lcd_goto_xy(1,0);
   lcd_data(gia_tri_mod + 0x30);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_614_phim_mod()
{
   if(phim_bt1_c2(60))
   {
         gia_tri_mod++;
         if(gia_tri_mod>=4)   gia_tri_mod=0;
         dem_tg_exit=0;
   } 
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_614_phim_up()
{
   if(phim_bt0_c2(60))
   {
         dem_tg_exit=0;
         switch(gia_tri_mod)
         {
            case 1: if(gio==23) gio=0;
                    else        gio++;
                    break;
            case 2: if(phut==59) phut=0;
                    else         phut++;
                    break;
            case 3: if(giay==59) giay=0;
                    else         giay++;  
                    break;
            default: break;        
         }
         ham_614_lcd_hienthi_dongho();
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_614_phim_dw()
{
   if(phim_bt2_c2(60))
   {
         dem_tg_exit=0;
         switch(gia_tri_mod)
         {
            case 1: if(gio==0) gio=23;
                    else        gio--;
                    break;
            case 2: if(phut==0) phut=59;
                    else         phut--;
                    break;
            case 3: if(giay==0) giay=59;
                    else         giay--;  
                    break;
            default: break;        
         }
         ham_614_lcd_hienthi_dongho();
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_614_lcd_gio_phut_giay()
{

  lcd_goto_xy(0,0);
  lcd_data("DONG HO:");
  ham_614_lcd_hienthi_dongho();
  if(bdn<10)
  {
   ham_614_phim_mod();
   ham_614_phim_up();
   ham_614_phim_dw();   
  }
  else
  {
   bdn=bdn-10;
   dem_tg_exit++;
   if(dem_tg_exit==20) gia_tri_mod=0;
   giay++;
   if(giay==60)
   {
      giay=0;
      phut++;
      if(phut==60)
      {
         phut=0;
         gio++;
         if(gio==24)
            gio=0;
      }
   }
      
  }  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 615: hien thi lcd dem gio phut giay chinh xac co 3 nut nhan chinh thoi gian va hien thi tren 8led 7 doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_615_lcd_hienthi_dongho()
{
   lcd_goto_xy(0,12);
   delay_us(20);
   lcd_data(gio/10 + 0x30);
   lcd_data(gio%10 + 0x30);
   lcd_data("-");
   lcd_data(phut/10 + 0x30);
   lcd_data(phut%10 + 0x30);
   lcd_data("-");
   lcd_data(giay/10 + 0x30);
   lcd_data(giay%10 + 0x30);
   
   lcd_goto_xy(1,0);
   lcd_data(gia_tri_mod + 0x30);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_615_tat_2led_chinh()
{
   if       (gia_tri_mod==1) {led_7dq[7]=0xff; led_7dq[6]=0xff;}
   else if  (gia_tri_mod==2) {led_7dq[4]=0xff; led_7dq[3]=0xff;}
   else if  (gia_tri_mod==3) {led_7dq[1]=0xff; led_7dq[0]=0xff;}
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_615_giai_ma_gan_cho_8led_quet()
{
   led_7dq[0]=ma7doan[giay%10];
   led_7dq[1]=ma7doan[giay/10];
   led_7dq[3]=ma7doan[phut%10];
   led_7dq[4]=ma7doan[phut/10];
   led_7dq[6]=ma7doan[gio%10];
   led_7dq[7]=ma7doan[gio/10];
   if(gia_tri_mod==1)   led_7dq[6]=led_7dq[6] & 0x7f;
   else if(gia_tri_mod==2)   led_7dq[3]=led_7dq[3] & 0x7f;
   else if(gia_tri_mod==3)   led_7dq[0]=led_7dq[0] & 0x7f;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_615_phim_mod()
{
   if(phim_bt1_c2(60))
   {
         gia_tri_mod++;
         if(gia_tri_mod>=4)   gia_tri_mod=0;
         dem_tg_exit=0;
   } 
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_615_phim_up()
{
   if(phim_bt0_c2(60))
   {
         dem_tg_exit=0;
         switch(gia_tri_mod)
         {
            case 1: if(gio==23) gio=0;
                    else        gio++;
                    break;
            case 2: if(phut==59) phut=0;
                    else         phut++;
                    break;
            case 3: if(giay==59) giay=0;
                    else         giay++;  
                    break;
            default: break;        
         }
         ham_615_giai_ma_gan_cho_8led_quet();
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_615_phim_dw()
{
   if(phim_bt2_c2(60))
   {
         dem_tg_exit=0;
         switch(gia_tri_mod)
         {
            case 1: if(gio==0) gio=23;
                    else        gio--;
                    break;
            case 2: if(phut==0) phut=59;
                    else         phut--;
                    break;
            case 3: if(giay==0) giay=59;
                    else         giay--;  
                    break;
            default: break;        
         }
         ham_615_giai_ma_gan_cho_8led_quet();
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_615_lcd_8led_gio_phut_giay()
{

  lcd_goto_xy(0,0);
  lcd_data("DONG HO:");
  ham_615_lcd_hienthi_dongho();
  ham_517_giai_ma_gan_cho_8led_quet();
  if(bdn<10)
  {
   if(gia_tri_mod!=0)
   {
      if((bdn==0) &&(input(bt0))&&(input(bt2)))
         ham_615_tat_2led_chinh();
      else if(bdn==5) ham_615_giai_ma_gan_cho_8led_quet();
   }
   hien_thi_8led_7doan_quet();
   ham_615_phim_mod();
   ham_615_phim_up();
   ham_615_phim_dw();
   
  }
  else
  {
   bdn=bdn-10;
   dem_tg_exit++;
   if(dem_tg_exit==20) gia_tri_mod=0;
   giay++;
   if(giay==60)
   {
      giay=0;
      phut++;
      if(phut==60)
      {
         phut=0;
         gio++;
         if(gio==24)
            gio=0;
      }
   }
      
  }  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 616:dem sp dung counter t0 hien thi tren lcd 20x4 o hang thu 1 va hien thi tren 4 led 7 doan, gioi han 000 - 100
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_616_hienthi_lcd()
{
   lcd_goto_xy(0,17);
   lcd_data(t0/100 + 0x30);
   lcd_data(t0/10%10 + 0x30);
   lcd_data(t0%10 + 0x30);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_616_lcd_4led_dem_sp_t0()
{
   ham_616_hienthi_lcd();
   xuat_4led_7doan_giaima_xoa_so0(t0);
   do
   {
      t0=get_timer0();
   }while(t0==t0_tam);
   if(t0>=101) set_timer0(1);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 617:dem sp dung counter t0 hien thi tren lcd 20x4 o hang thu 1 va hien thi tren 4 led 7 doan
//co 3 nut nhan de cai gioi han dem (01-99)
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_617_hienthi_lcd()
{
   lcd_goto_xy(0,0);
   lcd_data("GIA TRI CAI: ");
   lcd_goto_xy(0,17);
   lcd_data(gioi_han/10 + 0x30);
   lcd_data(gioi_han%10 + 0x30);
   
   
   lcd_goto_xy(1,0);
   lcd_data("GIA TRI DEM: ");
   lcd_goto_xy(1,17);
   lcd_data(t0/100 + 0x30);
   lcd_data(t0/10%10 + 0x30);
   lcd_data(t0%10 + 0x30);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_617_phim_up()
{  
   if(phim_bt0_c2(60))
   {
      if(gioi_han<99)
         gioi_han++;
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_617_phim_dw()
{  
   if(phim_bt1_c2(60))
   {
      if(gioi_han>1)
         gioi_han--;
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_617_phim_clr()
{  
   if(phim_bt2_c2(60))
   {
      gioi_han=1;
      set_timer0(00);
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_617_lcd_4led_dem_sp_t0_ud()
{
   ham_617_hienthi_lcd();
   ham_617_phim_up();
   ham_617_phim_dw();
   ham_617_phim_clr();
   xuat_4led_7doan_2_so_xoa_so0(gioi_han,t0);
   do
   {
      t0=get_timer0();
   }while(t0==t0_tam);
   if(t0>=(gioi_han+1)) set_timer0(1);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 621:nhan phim bat ky cua ma tran phim thi xuat hien o vi tri dau tien bên phai hang 2. Neu nhan phim tiep theo thi so truoc do mat
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_621_hienthi_lcd()
{
   lcd_goto_xy(1,19);
   if(mp<10) lcd_data(mp + 0x30);
   else      lcd_data(mp+0x37);

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_621_lcd_key4x4()
{
   lcd_goto_xy(0,0);
   lcd_data("HAY NHAN PHIM");
   do
   {
      mp=key_4x4_up();
   }while(mp==0xff);
   ham_621_hienthi_lcd();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 622:nhan phim bat ky cua ma tran phim thi xuat hien o vi tri dau tien bên phai hang 2. Neu nhan phim tiep theo thi so truoc do dich qua trai
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_622_lcd_key4x4_dich()
{
   lcd_goto_xy(0,0);
   lcd_data("HAY NHAN PHIM");
   lcd_goto_xy(1,0);
   for (i=0;i<20;i++) { lcd_data(hang2[i]); }
   do {mp=key_4x4_dw();}
   while(mp==0xff);
   for(i=0;i<19;i++)
   {
      hang2[i]=hang2[i+1];  
   }
   if(mp<10)
      hang2[19]=(mp+0x30);
   else 
      hang2[19]=(mp+0x37);
   lcd_goto_xy(1,0);
   for (i=0;i<20;i++) { lcd_data(hang2[i]); }
   
   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 623:nhan phim bat ky cua ma tran phim thi xuat hien o vi tri dau tien bên phai hang 1. Neu nhan phim tiep theo thi so truoc do dich qua trai. Du hang 1 se dich xuong 2 3 4
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_623_hienthi_lcd()
{
   lcd_goto_xy(0,0);
   for (i=0;i<20;i++) { lcd_data(hang1234[i+60]); }
   lcd_goto_xy(1,0);
   for (i=0;i<20;i++) { lcd_data(hang1234[i+40]); }
   lcd_goto_xy(2,0);
   for (i=0;i<20;i++) { lcd_data(hang1234[i+20]); }
   lcd_goto_xy(3,0);
   for (i=0;i<20;i++) { lcd_data(hang1234[i]); }

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_623_lcd_key4x4_dich_4hang_1234()
{
   ham_623_hienthi_lcd();
   do {mp=key_4x4_dw();}
   while(mp==0xff);
   for(i=0;i<79;i++)
   {
      hang1234[i]=hang1234[i+1];  
   }
   
   if(mp<10)
      hang1234[79]=(mp+0x30);
   else 
      hang1234[79]=(mp+0x37);

   ham_623_hienthi_lcd();
   
   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 624:ht 2 hang. Nhan A buzzer keu ung voi thoi gian Y(dc nhap tu ban phim 0-9).
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_624_hienthi_lcd()
{
   lcd_goto_xy(1,17);
   lcd_data(mp1 + 0x30);
   if(flag==1)
    {
      lcd_goto_xy(1,8);
      lcd_data("ON ");
   }  

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_624_lcd_key4x4_dich()
{
   lcd_goto_xy(0,0);
   lcd_data("DIEU KHIEN BUZZER");
   lcd_goto_xy(1,0);
   lcd_data("BUZZER: OFF, TG: ");
   do 
   {
      mp=key_4x4_dw();
   }
   while(mp==0xff);
   if(mp<10)
   {
      mp1=mp; 
      flag=0;
      ham_624_hienthi_lcd();
   }
   if(mp==0x0A)
   {
      flag=1;
      buzzer_on();
      ham_624_hienthi_lcd();
      delay_ms(mp1*1000);
      flag=0;
      buzzer_off();            
   }                   
   ham_624_hienthi_lcd(); 
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 625:giong 617 nhung su dung ma tran phim de cai gioi han
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_625_hienthi_lcd()
{
   lcd_goto_xy(0,0);
   lcd_data("GIA TRI CAI: ");
   lcd_goto_xy(0,17);
   lcd_data(gioi_han/10 + 0x30);
   lcd_data(gioi_han%10 + 0x30);
   
   
   lcd_goto_xy(1,0);
   lcd_data("GIA TRI DEM: ");
   lcd_goto_xy(1,17);
   lcd_data(t0/100 + 0x30);
   lcd_data(t0/10%10 + 0x30);
   lcd_data(t0%10 + 0x30);

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_625_lcd_4led_dem_sp_t0_matrix_key()
{
   xuat_4led_7doan_2_so_xoa_so0(gioi_han,t0);
   ham_625_hienthi_lcd();
   t0_tam=t0;

   t0=get_timer0();
   if(t0!=t0_tam)
   {
      t0_tam=t0;
      ham_625_hienthi_lcd();
      xuat_4led_7doan_2_so_xoa_so0(gioi_han,t0);
   }
   if(t0>=(gioi_han+1)) set_timer0(1);
   
   mp=key_4x4_dw();
   if(mp!=0xff)
   {
      gioi_han_tam[0]=gioi_han_tam[1];
      gioi_han_tam[1]=mp;     
      if(mp==0x0C)
         {
            gioi_han_tam[0]=0;
            gioi_han_tam[1]=1;
         }
      gioi_han=gioi_han_tam[0]*10+gioi_han_tam[1];
      ham_625_hienthi_lcd();
      xuat_4led_7doan_2_so_xoa_so0(gioi_han,t0);
   }

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 631:HIEN THI TRAI TIM
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_631_ht_trai_tim()
{
   unsigned char hang2[]={0x0a,0x15,0x11,0x11,0x0a,0x04,0,0};
    signed int8 i;
   lcd_goto_xy(0,0);
   lcd_data("Hien thi trai tim");
   lcd_command(0x40);
   for(i=0;i<8;i++) lcd_data(hang2[i]);
   
   lcd_goto_xy(1,0);
   lcd_data(0);
  while(true);
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 632:HIEN THI 20 TRAI TIM
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_632_ht_20_traitim()
{
   unsigned char hang2[]={0x0a,0x15,0x11,0x11,0x0a,0x04,0,0};
    signed int8 i;
   lcd_goto_xy(0,0);
   lcd_data("Hien thi trai tim");
   lcd_command(0x40);
   for(i=0;i<8;i++) lcd_data(hang2[i]);
   
   lcd_goto_xy(1,0);
   for(i=0;i<20;i++)
      lcd_data(0);
  while(true);
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 633:HIEN THI 3 ky tu trai tim - hinh thoi - hinh vuong
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_633_lcd_3kytu()
{
   unsigned char hang1[]={0x0a,0x15,0x11,0x11,0x0a,0x04,0,0};//trai tim
   unsigned char hang2[]={0x1f,0x11,0x11,0x11,0x11,0x1f,0,0};//hinh vuong
   unsigned char hang3[]={0x04,0x0a,0x11,0x0a,0x04,0,0,0};//hinh thoi
    signed int8 i;
   lcd_goto_xy(0,0);
   lcd_data("Hien thi 3 ky tu");
   lcd_command(0x40);
   for(i=0;i<8;i++) lcd_data(hang1[i]);
   
   lcd_command(0x48);
   for(i=0;i<8;i++) lcd_data(hang2[i]);
   
   lcd_command(0x50);
   for(i=0;i<8;i++) lcd_data(hang3[i]);
   
   lcd_goto_xy(1,0);
   lcd_data(0);
   lcd_data(1);
   lcd_data(2);
  while(true);
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 634:HIEN THI 8 ky tu bat ky
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_634_lcd_8kytu()
{
   unsigned char hang1[]={0x0a,0x15,0x11,0x11,0x0a,0x04,0,0};//trai tim
   unsigned char hang2[]={0x1f,0x11,0x11,0x11,0x11,0x1f,0,0};//hinh vuong
   unsigned char hang3[]={0x04,0x0a,0x11,0x0a,0x04,0,0,0};//hinh thoi
   unsigned char hang4[]={0,0,0x04,0x0a,0x1f,0,0,0};//tam giac
   unsigned char hang5[]={0x1f,0x11,0x11,0x11,0x11,0x11,0x11,0x1f};// hinh chu nhat
   unsigned char hang6[]={0x04,0x0a,0x11,0x11,0x11,0x11,0x1f,0};//ngoi nha 
   unsigned char hang7[]={0x0e,0x11,0x11,0x11,0x0e,0,0,0};//hinh bat giac 
   unsigned char hang8[]={0x04,0x0a,0x11,0x11,0x11,0x0a,0x04,0}; //hinh luc giac
    signed int8 i;
   lcd_goto_xy(0,0);
   lcd_data("Hien thi 8 ky tu");
   lcd_command(0x40);
   for(i=0;i<8;i++) lcd_data(hang1[i]);
   
   lcd_command(0x48);
   for(i=0;i<8;i++) lcd_data(hang2[i]);
   
   lcd_command(0x50);
   for(i=0;i<8;i++) lcd_data(hang3[i]);
   
   lcd_command(0x58);
   for(i=0;i<8;i++) lcd_data(hang4[i]);
   
   lcd_command(0x60);
   for(i=0;i<8;i++) lcd_data(hang5[i]);
   
   lcd_command(0x68);
   for(i=0;i<8;i++) lcd_data(hang6[i]);
   
   lcd_command(0x70);
   for(i=0;i<8;i++) lcd_data(hang7[i]);
   
   lcd_command(0x78);
   for(i=0;i<8;i++) lcd_data(hang8[i]);
   
   lcd_goto_xy(1,0);
   lcd_data(0); lcd_data(1); lcd_data(2); lcd_data(3);
   lcd_data(4); lcd_data(5); lcd_data(6); lcd_data(7);  
  while(true);
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 635:HIEN THI bieu tuong apple
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_635_lcd_apple()
{
   unsigned char hang1[]={0,0,0,0,0x0f,0x0f,0x1f,0x1f};
   unsigned char hang2[]={0x08,0x08,0x18,0x10,0x1e,0x1f,0x1e,0x1c};
   unsigned char hang3[]={0x1f,0x1f,0x1f,0x1f,0x0f,0x0f,0x07,0x07};
   unsigned char hang4[]={0x1c,0x1c,0x1e,0x1f,0x1f,0x1c,0x1c,0x0c};
    signed int8 i;
    lcd_goto_xy(0,0);
    lcd_data("BIEU TUONG APPLE");
   lcd_command(0x40);
   for(i=0;i<8;i++) lcd_data(hang1[i]);
   
   lcd_command(0x48);
   for(i=0;i<8;i++) lcd_data(hang2[i]);
   
   lcd_command(0x50);
   for(i=0;i<8;i++) lcd_data(hang3[i]);
   
   lcd_command(0x58);
   for(i=0;i<8;i++) lcd_data(hang4[i]);
   
   lcd_goto_xy(1,0);
   lcd_data(0); 
   lcd_data(1); 
   lcd_goto_xy(2,0);
   lcd_data(2); 
   lcd_data(3);

  while(true);
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 636:HIEN THI bieu tuong apple di chuyen tu phai sang trai r tu trai sang phai
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_636_lcd_apple_dichchuyen()
{
   unsigned char hang1[]={0,0,0,0,0x0f,0x0f,0x1f,0x1f};
   unsigned char hang2[]={0x08,0x08,0x18,0x10,0x1e,0x1f,0x1e,0x1c};
   unsigned char hang3[]={0x1f,0x1f,0x1f,0x1f,0x0f,0x0f,0x07,0x07};
   unsigned char hang4[]={0x1c,0x1c,0x1e,0x1f,0x1f,0x1c,0x1c,0x0c};
    signed int8 i;
   lcd_goto_xy(0,0);
   lcd_data("BIEU TUONG APPLE");
   lcd_command(0x40);
   for(i=0;i<8;i++) lcd_data(hang1[i]);
   
   lcd_command(0x48);
   for(i=0;i<8;i++) lcd_data(hang2[i]);
   
   lcd_command(0x50);
   for(i=0;i<8;i++) lcd_data(hang3[i]);
   
   lcd_command(0x58);
   for(i=0;i<8;i++) lcd_data(hang4[i]);
   
   lcd_goto_xy(1,0);
   lcd_data(0); 
   lcd_data(1); 
   lcd_goto_xy(2,0);
   lcd_data(2); 
   lcd_data(3);
   delay_ms(500);
   
   for(i=0;i<18;i++)
   {
      lcd_goto_xy(1,i);
      lcd_data(" ");
      lcd_data(0); 
      lcd_data(1);
      lcd_goto_xy(2,i);
      lcd_data(" ");
      lcd_data(2); 
      lcd_data(3);  
      delay_ms(500);
   }
   for(i=17;i>=0;i--)
   {
      lcd_goto_xy(1,i);
      lcd_data(0); 
      lcd_data(1);
      lcd_data(" ");
      lcd_goto_xy(2,i);
      lcd_data(2); 
      lcd_data(3); 
      lcd_data(" ");
      delay_ms(500);
   }
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 641:HIEN THI ky tu so 0, moi con so chiem 6 ki tu tren lcd2004
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_641_lcd_so_0()
{
   lcd_goto_xy(0,0);
   lcd_data("hien thi so 0 hang 3");
   lcd_command(0x40);
   for(i=0;i<64;i++) lcd_data(lcd_ma_8doan[i]);
   lcd_hienthi_so_z_toado_xy(0,2,0);

}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 642:HIEN THI ky tu so 0123, moi con so chiem 6 ki tu tren lcd2004
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_642_lcd_so_0123()
{
   lcd_goto_xy(0,0);
   lcd_data("hien thi so 0123");
   lcd_command(0x40);
   for(i=0;i<64;i++) lcd_data(lcd_ma_8doan[i]);
   lcd_hienthi_so_z_toado_xy(0,2,0);
   lcd_hienthi_so_z_toado_xy(1,2,4);
   lcd_hienthi_so_z_toado_xy(2,2,8);
   lcd_hienthi_so_z_toado_xy(3,2,12);

}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 643:dem tu 00-99 hien thi kich thuoc lon
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_643_lcd_dem_00_99()
{
   lcd_goto_xy(0,0);
   lcd_data("**dem tu so 00 den 99**");
   lcd_command(0x40);
   for(i=0;i<64;i++) lcd_data(lcd_ma_8doan[i]);
   lcd_hienthi_so_z_toado_xy(0,2,0);
   for(dem=0;dem<100;dem++)
   {
      lcd_hienthi_so_z_toado_xy(dem/10,2,0);
      lcd_hienthi_so_z_toado_xy(dem%10,2,3);
      delay_ms(200);
   }

}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 644:dem sp dung counter t0 hien thi tren lcd 20x4 o hang thu 1 va hien thi tren 4 led 7 doan, gioi han 000 - 100 
//HIEN THI SO LON(HIEU CHINH BAI 616)
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_644_hienthi_lcd_ktl()
{
   lcd_hienthi_so_z_toado_xy(t0/100,2,0);
   lcd_hienthi_so_z_toado_xy(t0/10%10,2,3);
   lcd_hienthi_so_z_toado_xy(t0%10,2,6);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_644_lcd_dem_sp_ktl()
{
   lcd_goto_xy(0,0);
   lcd_data("**DEM SAN PHAM**");
   ham_644_hienthi_lcd_ktl();
   lcd_command(0x40);
   for(i=0;i<64;i++) lcd_data(lcd_ma_8doan[i]);
   xuat_4led_7doan_giaima_xoa_so0(t0);
   do
   {
      t0=get_timer0();
   }while(t0==t0_tam);
   if(t0>=101) set_timer0(1);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//****GLCD**********************GLCD**********************
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 652:hien thi chuoi GLCD fornt 16x16
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_652_glcd_hien_thi_chuoi()
{
   glcd_command(glcd_addr_line1);
   glcd_data("dh-supham kt hcm");
   
   glcd_command(glcd_addr_line2);
   glcd_data("bo mon dien tu");
   
   glcd_command(glcd_addr_line3);
   glcd_data("cong nghiep");
   
   glcd_command(glcd_addr_line4);
   glcd_data("thuc hanh vdk");
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 653:dem san pham dung counter t0 hien thi tren GLCD fornt 16x16
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_653_glcd_hienthi_t0(unsigned t0)
{
   glcd_command(glcd_addr_line2);
   glcd_data(t0/100 + 0x30);
   glcd_data(t0/10%10 + 0x30);
   glcd_data(t0%10 + 0x30);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_653_glcd_dem_sp_t0()
{
   glcd_command(glcd_addr_line1);
   glcd_data("dem san pham");
   t0=get_timer0();
   ham_653_glcd_hienthi_t0(t0);
   if(t0!=t0_tam)
   {
      ham_653_glcd_hienthi_t0(t0);
      t0_tam=t0;
   }
   xuat_4led_7doan_giaima_xoa_so0(t0);
   if(t0>=101) set_timer0(1);
   

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 654:dem san pham dung counter t0 hien thi tren GLCD fornt 16x16,4led 7 doan va LCD
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_654_glcd_hienthi_t0(unsigned t0)
{
   glcd_command(glcd_addr_line2);
   glcd_data(t0/100 + 0x30);
   glcd_data(t0/10%10 + 0x30);
   glcd_data(t0%10 + 0x30);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_654_hienthi_lcd()
{ 
   lcd_goto_xy(1,0);
   lcd_data(t0/100 + 0x30);
   lcd_data(t0/10%10 + 0x30);
   lcd_data(t0%10 + 0x30);

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_654_glcd_lcd_4led_dem_sp_t0()
{
   glcd_command(glcd_addr_line1);
   glcd_data("dem san pham");
   lcd_goto_xy(0,0);
   lcd_data("dem san pham");
   t0=get_timer0();
   ham_654_glcd_hienthi_t0(t0);
   ham_654_hienthi_lcd();
   if(t0!=t0_tam)
   {
      t0_tam=t0;
   }
   xuat_4led_7doan_giaima_xoa_so0(t0);
   ham_654_glcd_hienthi_t0(t0);
   ham_654_hienthi_lcd();
   if(t0>=101) set_timer0(1);
   

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 661:hien thi logo DHSPKT tren glcd
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_661_glcd_bitmap_spkt()
{
   glcd_mau_nen(0);
   glcd_xuat_anh(64,64,32,0);
   gdram_vdk_to_gdram_glcd_all ();
   

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 662:hien thi 2 logo DHSPKT tren glcd
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_662_glcd_2bitmap_spkt()
{
   glcd_mau_nen(0);
   glcd_xuat_anh(64,64,64,0);
   glcd_xuat_anh(64,64,0,0);
   gdram_vdk_to_gdram_glcd_all ();
   

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 663:ve duong thang, duong tron tren glcd
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_663_glcd_dt_dt()
{
   glcd_mau_nen(0);
   glcd_line(0,0,50,50,1);
   glcd_circle(40,40,20,0,1);
   gdram_vdk_to_gdram_glcd_all ();
   

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 664:
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_664_hienthi()
{
   glcd_rect(donvi*7,0,donvi*7+5,5,0,1);
   glcd_rect(chuc*7,7,chuc*7+5,12,0,1);
   glcd_rect(tram*7,14,tram*7+5,19,0,1);
   gdram_vdk_to_gdram_glcd_all ();
   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_664_glcd_dem_sp_t0_ht_cot()
{
   delay_ms(5);
   t0=get_timer0();
   if(t0!=t0_tam)
   {
      donvi++;
      t0_tam=t0;
   }
   ham_664_hienthi();
   if(donvi==10)
   {
      donvi=0;
      chuc++;
      glcd_rect(0,0,90,5,1,0);
      if(chuc==10)
      {
         chuc=0;
         tram++;
         glcd_rect(0,7,90,12,1,0);
         if(tram==10)
         {
            tram=0;
            glcd_rect(0,14,90,19,1,0);
         }
      }
   }
   ham_664_hienthi();
   
   

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 665:VE VONG TRON VA KIM GIAY, VE DONG HO. DUNG T1 DINH THOI.
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
VOID ham_665_SO_LAMA()
{
   // SO XII
   GLCD_LINE(26, 2, 30, 6, 1);
   GLCD_LINE(30, 2, 26, 6, 1);
   GLCD_LINE(32, 2, 32, 6, 1);
   GLCD_LINE(34, 2, 34, 6, 1);
   // SO III
   GLCD_LINE(56, 29, 56, 33, 1);
   GLCD_LINE(58, 29, 58, 33, 1);
   GLCD_LINE(60, 29, 60, 33, 1);
   // SO VI
   GLCD_LINE(27, 54, 29, 60, 1);
   GLCD_LINE(31, 54, 29, 60, 1);
   GLCD_LINE(33, 54, 33, 60, 1);
   //SO IX
   GLCD_LINE(3, 29, 3, 33, 1);
   GLCD_LINE(5, 29, 9, 33, 1);
   GLCD_LINE(9, 29, 5, 33, 1);
   //
   GLCD_CIRCLE(31, 31, 31, 0, 1);
   GLCD_CIRCLE(31, 31, 2, 1, 1);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
VOID ham_665_DONGHO_TEXT()
{
   GLCD_COMMAND(0x80 + 4);
   GLCD_DATA("Dong Ho");
   // TEXT GIAY
   GLCD_COMMAND(0x98 + 4);
   GLCD_DATA("Giay:");
   GLCD_DATA(giay / 10 + 0x30);
   GLCD_DATA(giay % 10 + 0x30);
   GLCD_DATA("S");
   // TEXT PHUT
   GLCD_COMMAND(0x88 + 4);
   GLCD_DATA("Phut:");
   GLCD_DATA(phut / 10 + 0x30);
   GLCD_DATA(phut % 10 + 0x30);
   GLCD_DATA("P");
   // TEXT GIO
   GLCD_COMMAND(0x94);
   GLCD_DATA("Gio:");
   GLCD_DATA(gio / 10 + 0x30);
   GLCD_DATA(gio % 10 + 0x30);
   GLCD_DATA("H");
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_665_hienthi_lcd()
{
   lcd_goto_xy(0,0);
   lcd_data("DONG HO: ");
   lcd_data(gio/10 + 0x30);
   lcd_data(gio%10 + 0x30);
   lcd_data(":");
   lcd_data(phut/10+0x30);
   lcd_data(phut%10+0x30);
   lcd_data(":");
   lcd_data(giay/10+0x30);
   lcd_data(giay%10+0x30);
}
 //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
VOID BAI_655_GLCD_DEM_GIAY()
{
   GDRAM_VDK_TO_GDRAM_GLCD_ALL();
   ham_665_hienthi_lcd();
   GLCD_CIRCLE(31, 31, 31, 0, 1);
   GLCD_CIRCLE(31, 31, 2, 1, 1);
   ham_665_SO_LAMA();
      IF(bdn < 10)
      {
      }

      ELSE
      {
         bdn = 0;
         giay++;
         IF(giay == 60)
         {
            giay = 0;
            phut++;
            IF(phut == 60)
            {
               phut = 0;
               gio++;
               IF(gio == 13)
               {
                  gio = 0;
               }
            }
         }

         //SETUP_GLCD(0x30);
         //DONGHO_TEXT();
         // KIM GIAY, PHUT, GIO
         //GLCD_COMMAND(0x36);
         GLCD_MAU_NEN(0);
         GLCD_LINE(31, 31,(FLOAT)31 + 25 * sin((6 * 3.14) / 180 * giay),(float)31 - 24* cos((6 * 3.14) / 180 * giay), 1);
         GLCD_LINE(31, 31,(FLOAT)31 + 20 * sin((6 * 3.14) / 180 * phut),(float)31 - 20 * cos((6 * 3.14) / 180 * phut), 1);
         GLCD_LINE(31, 31,(FLOAT)31 + 12 * sin((6 * 3.14) / 180 * gio),(float)31 - 15 * cos((6 * 3.14) / 180 * gio), 1);
         
         ham_665_SO_LAMA();
         ham_665_hienthi_lcd();
         GDRAM_VDK_TO_GDRAM_GLCD_ALL();
      }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 671:32led don chay quang cao || 8led quet dem gio phu giay || LCD GLCD,4led thi hien thi ket qua dem san pham tu t0
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_671_glcd_hienthi_t0()
{
   glcd_command(glcd_addr_line2);
   glcd_data(t0/100 + 0x30);
   glcd_data(t0/10%10 + 0x30);
   glcd_data(t0%10 + 0x30);
   
   lcd_goto_xy(1,0);
   lcd_data(t0/100 + 0x30);
   lcd_data(t0/10%10 + 0x30);
   lcd_data(t0%10 + 0x30);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_671_giai_ma_gan_cho_8led_quet()
{
   led_7dq[0]=ma7doan[giay%10];
   led_7dq[1]=ma7doan[giay/10];
   led_7dq[2]=0xbf;
   led_7dq[3]=ma7doan[phut%10];
   led_7dq[4]=ma7doan[phut/10];
   led_7dq[5]=0xbf;
   led_7dq[6]=ma7doan[gio%10];
   led_7dq[7]=ma7doan[gio/10];
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_671_tat_2led_chinh()
{
   if     (gia_tri_mod == 1)    {led_7dq[7]=0xff;  led_7dq[6]=0xff;}
   else if(gia_tri_mod == 2)    {led_7dq[4]=0xff;  led_7dq[3]=0xff;}
   else if(gia_tri_mod == 3)    {led_7dq[1]=0xff;  led_7dq[0]=0xff;}
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_671_phim_mod()
{
   if(phim_bt1_c2(50))
   {
      gia_tri_mod++;
      if(gia_tri_mod>=4)   gia_tri_mod=0;
      dem_tg_exit=0;
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_671_phim_up()
{
   if(phim_bt0_c2(50))
   {
     dem_tg_exit=0;
     switch (gia_tri_mod)
     {
         case 1:     if(gio==23)    gio=0;
                     else           gio++;
                     break;
         case 2:     if(phut==59)    phut=0;
                     else           phut++;
                     break;
         case 3:     if(giay==59)    giay=0;
                     else           giay++;
                     break; 
         default:    break;        
     }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_671_phim_dw()
{
   if(phim_bt2_c2(20))
   {
      dem_tg_exit=0;
      switch (gia_tri_mod)
      {
         case 1:     if(gio==0)    gio=23;
                     else           gio--;
                     break;
         case 2:     if(phut==0)    phut=59;
                     else           phut--;
                     break;
         case 3:     if(giay==0)    giay=59;
                     else           giay--;
                     break; 
         default:    break;     
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_671_glcd_tonghop_5_module()
{
   glcd_command(glcd_addr_line1);
   glcd_data("dem san pham:");
   lcd_command(lcd_addr_line1);
   lcd_data("lcd: dem san pham:");
   xuat_4led_7doan_giaima_xoa_so0(t0);
   ham_671_glcd_hienthi_t0();
   ham_671_giai_ma_gan_cho_8led_quet();
   if(bdn<10)
     {
         if((bdn<5)&&(input(bt0))&&(input(bt2)))
            ham_671_tat_2led_chinh();
         hien_thi_8led_7doan_quet_all();
         ham_671_phim_mod();
         ham_671_phim_up();
         ham_671_phim_dw();
         t0=get_timer0();
         if(t0!=t0_tam)
         {
            t0_tam = t0;
            ham_671_glcd_hienthi_t0();
            xuat_4led_7doan_giaima_xoa_so0(t0);
            if (t0>=101)   set_timer0(1);
         }
            if (ttct_td==1) sang_tat_32led(2,1);
            if (ttct_td==2) sang_tat_dan_pst_32led(5,1);
            if (ttct_td==3) sang_tat_dan_tsp_32led(5,1);
            if (ttct_td==4) sang_tat_dan_ngoai_vao_32led(5,1);
            if (ttct_td==5) sang_tat_dan_trong_ra_32led(5,1);
            if (ttct_td==6) sang_don_pst_32led(5,1);
            if (ttct_td==7) diem_sang_dich_trai_mat_dan_32led(5,1);
            if (ttct_td==8) sang_don_tsp_32led(5,1);
            if (ttct_td==9) diem_sang_dich_phai_mat_dan_32led(5,1);
            if (ttct_td==10) sang_tat_dan_trai_sang_phai_2x16led(5,1);
            if (ttct_td==11) sang_tat_dan_phai_sang_trai_2x16led(5,1);
            if (ttct_td==12) diem_sang_di_chuyen_pst_32led(5,1);
            if (ttct_td==13) diem_sang_di_chuyen_tsp_32led(5,1);
            if (ttct_td==14) sang_don_tnt_32led(5,1);
            if (ttct_td==15) sang_don_ttr_32led(5,1);
            if (ttct_td>15) ttct_td=1;
     }
     else
     {
         bdn = bdn-10;
         dem_tg_exit++;
         if (dem_tg_exit==20)  gia_tri_mod=0;
         giay++;
         if (giay==60) 
         {
            giay = 0;
            phut++;
            if(phut==60)
            {
               phut=0;
               gio++;
               if(gio==24) gio=0;
            }
         }
      }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 672:giong 671 nhung them logo su pham ky thuat
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_672_glcd_hienthi_t0()
{
   glcd_command(glcd_addr_line2);
   glcd_data(t0/100 + 0x30);
   glcd_data(t0/10%10 + 0x30);
   glcd_data(t0%10 + 0x30);
   
   lcd_goto_xy(1,0);
   lcd_data(t0/100 + 0x30);
   lcd_data(t0/10%10 + 0x30);
   lcd_data(t0%10 + 0x30);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_672_giai_ma_gan_cho_8led_quet()
{
   led_7dq[0]=ma7doan[giay%10];
   led_7dq[1]=ma7doan[giay/10];
   led_7dq[2]=0xbf;
   led_7dq[3]=ma7doan[phut%10];
   led_7dq[4]=ma7doan[phut/10];
   led_7dq[5]=0xbf;
   led_7dq[6]=ma7doan[gio%10];
   led_7dq[7]=ma7doan[gio/10];
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_672_tat_2led_chinh()
{
   if     (gia_tri_mod == 1)    {led_7dq[7]=0xff;  led_7dq[6]=0xff;}
   else if(gia_tri_mod == 2)    {led_7dq[4]=0xff;  led_7dq[3]=0xff;}
   else if(gia_tri_mod == 3)    {led_7dq[1]=0xff;  led_7dq[0]=0xff;}
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_672_phim_mod()
{
   if(phim_bt1_c2(50))
   {
      gia_tri_mod++;
      if(gia_tri_mod>=4)   gia_tri_mod=0;
      dem_tg_exit=0;
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_672_phim_up()
{
   if(phim_bt0_c2(50))
   {
     dem_tg_exit=0;
     switch (gia_tri_mod)
     {
         case 1:     if(gio==23)    gio=0;
                     else           gio++;
                     break;
         case 2:     if(phut==59)    phut=0;
                     else           phut++;
                     break;
         case 3:     if(giay==59)    giay=0;
                     else           giay++;
                     break; 
         default:    break;        
     }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_672_phim_dw()
{
   if(phim_bt2_c2(20))
   {
      dem_tg_exit=0;
      switch (gia_tri_mod)
      {
         case 1:     if(gio==0)    gio=23;
                     else           gio--;
                     break;
         case 2:     if(phut==0)    phut=59;
                     else           phut--;
                     break;
         case 3:     if(giay==0)    giay=59;
                     else           giay--;
                     break; 
         default:    break;     
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_672_glcd_tonghop_5_module()
{
   setup_glcd(glcd_graphic_mode);
   glcd_xuat_anh(64,64,64,0);
   gdram_vdk_to_gdram_glcd_all();
   setup_glcd(glcd_text_mode);
   glcd_command(glcd_addr_line1);
   glcd_data("dem:");
   lcd_command(lcd_addr_line1);
   lcd_data("lcd: dem san pham:");
   xuat_4led_7doan_giaima_xoa_so0(t0);
   ham_672_glcd_hienthi_t0();
   ham_672_giai_ma_gan_cho_8led_quet();
   
   if(bdn<10)
     {
         if((bdn<5)&&(input(bt0))&&(input(bt2)))
            ham_671_tat_2led_chinh();
         hien_thi_8led_7doan_quet_all();
         ham_672_phim_mod();
         ham_672_phim_up();
         ham_672_phim_dw();
         t0=get_timer0();
         if(t0!=t0_tam)
         {
            t0_tam = t0;
            ham_672_glcd_hienthi_t0();
            xuat_4led_7doan_giaima_xoa_so0(t0);
            if (t0>=101)   set_timer0(1);
         }
            if (ttct_td==1) sang_tat_32led(2,1);
            if (ttct_td==2) sang_tat_dan_pst_32led(5,1);
            if (ttct_td==3) sang_tat_dan_tsp_32led(5,1);
            if (ttct_td==4) sang_tat_dan_ngoai_vao_32led(5,1);
            if (ttct_td==5) sang_tat_dan_trong_ra_32led(5,1);
            if (ttct_td==6) sang_don_pst_32led(5,1);
            if (ttct_td==7) diem_sang_dich_trai_mat_dan_32led(5,1);
            if (ttct_td==8) sang_don_tsp_32led(5,1);
            if (ttct_td==9) diem_sang_dich_phai_mat_dan_32led(5,1);
            if (ttct_td==10) sang_tat_dan_trai_sang_phai_2x16led(5,1);
            if (ttct_td==11) sang_tat_dan_phai_sang_trai_2x16led(5,1);
            if (ttct_td==12) diem_sang_di_chuyen_pst_32led(5,1);
            if (ttct_td==13) diem_sang_di_chuyen_tsp_32led(5,1);
            if (ttct_td==14) sang_don_tnt_32led(5,1);
            if (ttct_td==15) sang_don_ttr_32led(5,1);
            if (ttct_td>15) ttct_td=1;
     }
     else
     {
         bdn = bdn-10;
         dem_tg_exit++;
         if (dem_tg_exit==20)  gia_tri_mod=0;
         giay++;
         if (giay==60) 
         {
            giay = 0;
            phut++;
            if(phut==60)
            {
               phut=0;
               gio++;
               if(gio==24) gio=0;
            }
         }
      }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx




