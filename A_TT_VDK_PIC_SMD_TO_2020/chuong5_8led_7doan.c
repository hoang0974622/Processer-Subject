//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//TAT CA DEU VIET THEO BAI VA HAM THEO BAI 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//Khai bao bien 8led 7 doan
unsigned int16 tg_delay;
signed int8 gio=0,phut=0,giay=0,bdn=0,dem_tg_exit=0;
unsigned int8 led7dq[8]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8};
unsigned int8 gia_tri_mod;
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//Khoi tao ngat timer1
#int_timer1
void interrupt_timer1()
{
   bdn++;
   set_timer1(3036);
   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Khoi tao timer1 va cho phep ngat timer1 
void khoi_tao_timer1_ngat()
{
   setup_timer_1(t1_internal| t1_div_by_8);
   set_timer1(3036);
   enable_interrupts(global);
   enable_interrupts(int_timer1);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 501: hien thi 8 led 7doan quet
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_501_hienthi_8so()
{
  tg_delay=1;
  xuat_8led_7doan_quet_1(0x7f,0xc0);//0
  delay_ms(tg_delay);
  
  xuat_8led_7doan_quet_1(0xbf,0xf9);//1
  delay_ms(tg_delay);
  
  xuat_8led_7doan_quet_1(0xdf,0xa4);//2
  delay_ms(tg_delay);
  
  xuat_8led_7doan_quet_1(0xef,0xb0);//3
  delay_ms(tg_delay);
  
  xuat_8led_7doan_quet_1(0xf7,0x99);//4
  delay_ms(tg_delay);
  
  xuat_8led_7doan_quet_1(0xfb,0x92);//5
  delay_ms(tg_delay);
  
  xuat_8led_7doan_quet_1(0xfd,0x82);//6
  delay_ms(tg_delay);
  
  xuat_8led_7doan_quet_1(0xfe,0xf8);//7
  delay_ms(tg_delay);
  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 502: hien thi 8 led 7doan quet 2 so 1 0 ben phai
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_502_hienthi_10()
{
  tg_delay=1;
  xuat_8led_7doan_quet_1(0x7f,0xc0);//0
  delay_ms(tg_delay);
  
  xuat_8led_7doan_quet_1(0xbf,0xf9);//1
  delay_ms(tg_delay);
  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 503: hien thi 8 led 7doan quet cach 2
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_503_hienthi_8so_cach2()
{
  tg_delay=1;
  xuat_8led_7doan_quet_2(0,0xc0);//0
  delay_ms(tg_delay);
  
  xuat_8led_7doan_quet_2(1,0xf9);//1
  delay_ms(tg_delay);
  
  xuat_8led_7doan_quet_2(2,0xa4);//2
  delay_ms(tg_delay);
  
  xuat_8led_7doan_quet_2(3,0xb0);//3
  delay_ms(tg_delay);
  
  xuat_8led_7doan_quet_2(4,0x99);//4
  delay_ms(tg_delay);
  
  xuat_8led_7doan_quet_2(5,0x92);//5
  delay_ms(tg_delay);
  
  xuat_8led_7doan_quet_2(6,0x82);//6
  delay_ms(tg_delay);
  
  xuat_8led_7doan_quet_2(7,0xf8);//7
  delay_ms(tg_delay);
  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 504: hien thi 8 led 7doan quet cach 3
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_504_hien_thi_8led()
{
   for(i=0;i<8;i++)
  {
   xuat_8led_7doan_quet_2(i,led7dq[i]);
   delay_us(100);
   xuat_8led_7doan_quet_tat_led();
  }
}
void bai_504_hienthi_8so_cach3()
{
  ham_504_hien_thi_8led();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 511: hien thi 8 led 7doan quet dem giay
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_511_hienthi_delay()
{
   for(y=0;y<200;y++)
  {
   xuat_8led_7doan_quet_2(0,ma7doan[giay%10]);
   delay_us(200);
   xuat_8led_7doan_quet_tat_led();
   xuat_8led_7doan_quet_2(1,ma7doan[giay/10]);
   delay_us(200);
   xuat_8led_7doan_quet_tat_led();
  }
}
void bai_511_dem_giay()
{
  for(giay=0;giay<60;giay++)
   ham_511_hienthi_delay();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 512: hien thi 8 led 7doan quet dem giay chinh xac dung ngat timer1
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_512_giai_ma_gan_cho_8led_quet()
{
   led_7dq[0]=ma7doan[giay%10];
   led_7dq[1]=ma7doan[giay/10];
  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_512_dem_giay_cx()
{
  ham_512_giai_ma_gan_cho_8led_quet();
  if(bdn<10)
   hien_thi_8led_7doan_quet();
  else
  {
   bdn=bdn-10;
   giay++;
   if(giay==60)
      giay=0;
  }  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 513 hien thi 8 led 7doan quet dem phut giay chinh xac dung ngat timer1
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_513_giai_ma_gan_cho_8led_quet()
{
   led_7dq[0]=ma7doan[giay%10];
   led_7dq[1]=ma7doan[giay/10];
   led_7dq[2]=ma7doan[phut%10];
   led_7dq[3]=ma7doan[phut/10];
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_513_dem_phut_giay()
{
  ham_513_giai_ma_gan_cho_8led_quet();
  if(bdn<10)
   hien_thi_8led_7doan_quet();
  else
  {
   bdn=bdn-10;
   giay++;
   if(giay==60)
   {
      giay=0;
      phut++;
      if(phut==60)
         phut=0;
   }
      
  }  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 514 hien thi 8 led 7doan quet dem gio phut giay chinh xac dung ngat timer1
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_514_giai_ma_gan_cho_8led_quet()
{
   led_7dq[0]=ma7doan[giay%10];
   led_7dq[1]=ma7doan[giay/10];
   led_7dq[2]=ma7doan[phut%10];
   led_7dq[3]=ma7doan[phut/10];
   led_7dq[4]=ma7doan[gio%10];
   led_7dq[5]=ma7doan[gio/10];
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_514_dem_gio_phut_giay()
{
  ham_514_giai_ma_gan_cho_8led_quet();
  if(bdn<10)
   hien_thi_8led_7doan_quet();
  else
  {
   bdn=bdn-10;
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
//Bai 515 hien thi 8 led 7doan quet dem gio phut giay chinh xac dung ngat timer1 co phim nhan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_515_giai_ma_gan_cho_8led_quet()
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
void ham_515_delay_hienthi()
{
   for(i=0;i<100;i++)
      hien_thi_8led_7doan_quet();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_515_phim_mod()
{
   if(!input(mod))
   {
      ham_515_delay_hienthi();
      if(!input(mod))
      {
         gia_tri_mod++;
         if(gia_tri_mod>=4)   gia_tri_mod=0;
         ham_515_giai_ma_gan_cho_8led_quet();
         do
         {
            hien_thi_8led_7doan_quet();
         }while(!input(mod));
      }
      
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_515_phim_up()
{
   if(!input(up))
   {
      ham_515_delay_hienthi();
      if(!input(up))
      {
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
         ham_515_giai_ma_gan_cho_8led_quet();
         do
         {
            hien_thi_8led_7doan_quet();
         }while(!input(up));
      }
      
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_515_phim_dw()
{
   if(!input(dw))
   {
      ham_515_delay_hienthi();
      if(!input(dw))
      {
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
         ham_515_giai_ma_gan_cho_8led_quet();
         do
         {
            hien_thi_8led_7doan_quet();
         }while(!input(dw));
      }
      
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_515_dem_gio_phut_giay_key()
{
  ham_515_giai_ma_gan_cho_8led_quet();
  if(bdn<10)
  {
   hien_thi_8led_7doan_quet();
   ham_515_phim_mod();
   ham_515_phim_up();
   ham_515_phim_dw();
   
  }
  else
  {
   bdn=bdn-10;
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
//Bai 516 cai tien 515
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_516_giai_ma_gan_cho_8led_quet()
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
void ham_516_phim_mod()
{
   if(phim_bt1_c2(60))
   {
         gia_tri_mod++;
         if(gia_tri_mod>=4)   gia_tri_mod=0;
   } 
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_516_phim_up()
{
   if(phim_bt0_c2(60))
   {
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
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_516_phim_dw()
{
   if(phim_bt2_c2(60))
   {
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
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_516_dem_gio_phut_giay_key_caitien()
{
  ham_516_giai_ma_gan_cho_8led_quet();
  if(bdn<10)
  {
   hien_thi_8led_7doan_quet();
   ham_516_phim_mod();
   ham_516_phim_up();
   ham_516_phim_dw();
   
  }
  else
  {
   bdn=bdn-10;
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
//Bai 517 cai tien 516
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_517_giai_ma_gan_cho_8led_quet()
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
void ham_517_tat_2led_chinh()
{
   if       (gia_tri_mod==1) {led_7dq[7]=0xff; led_7dq[6]=0xff;}
   else if  (gia_tri_mod==2) {led_7dq[4]=0xff; led_7dq[3]=0xff;}
   else if  (gia_tri_mod==3) {led_7dq[1]=0xff; led_7dq[0]=0xff;}
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_517_phim_mod()
{
   if(phim_bt1_c2(60))
   {
         gia_tri_mod++;
         if(gia_tri_mod>=4)   gia_tri_mod=0;
         dem_tg_exit=0;
   } 
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_517_phim_up()
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
         ham_517_giai_ma_gan_cho_8led_quet();
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_517_phim_dw()
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
         ham_517_giai_ma_gan_cho_8led_quet();
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_517_dem_gio_phut_giay_key_caitien()
{
  ham_517_giai_ma_gan_cho_8led_quet();
  if(bdn<10)
  {
   if(gia_tri_mod!=0)
   {
      if((bdn==0) &&(input(bt0))&&(input(bt2)))
         ham_517_tat_2led_chinh();
      else if(bdn==5) ham_517_giai_ma_gan_cho_8led_quet();
   }
   hien_thi_8led_7doan_quet();
   ham_517_phim_mod();
   ham_517_phim_up();
   ham_517_phim_dw();
   
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
//Bai 518 dem xung ngoai dung counter t- hien thi tren 8led quet dem 00-99
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_518_giai_ma_gan_cho_8led_quet()
{
   led_7dq[0]=ma7doan[t0%10];
   led_7dq[1]=ma7doan[t0/10];
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_518_phim_on()
{
   IF(!INPUT(on))
   {
      DELAY_MS(20);
      IF(!INPUT(on))
      {
         setup_timer_0(t0_ext_l_to_h);
         set_timer0(t0);
         do{}WHILE(!INPUT(on));
      }
   }
  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_518_phim_off()
{
   IF(!INPUT(off))
   {
      DELAY_MS(20);
      IF(!INPUT(off))
      {
         setup_timer_0(t0_ext_l_to_h | t0_div_1|T0_OFF);
         set_timer0(t0);
         do{}WHILE(!INPUT(off));
      }
   }
  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_518_phim_clr()
{
   IF(!INPUT(clr))
   {
      DELAY_MS(20);
      IF(!INPUT(clr))
      {
         setup_timer_0(t0_ext_l_to_h);
         set_timer0(0);
      }
   }
  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_518_dem_xung_t0_ssc()
{
   t0_tam=t0=0;
   ham_518_giai_ma_gan_cho_8led_quet();
   t0=get_timer0();
   if(t0!=t0_tam)
   {
      t0_tam=t0;
      ham_518_giai_ma_gan_cho_8led_quet();
   }
   if(t0==100)
      set_timer0(0);
    hien_thi_8led_7doan_quet();
    ham_518_phim_on();
    ham_518_phim_off();
    ham_518_phim_clr();
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 521 ket hop 3 module 1 2 3 (ket hop bai 517 voi bai 422)
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_521_giai_ma_gan_cho_8led_quet()
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
void ham_521_tat_2led_chinh()
{
   if       (gia_tri_mod==1) {led_7dq[7]=0xff; led_7dq[6]=0xff;}
   else if  (gia_tri_mod==2) {led_7dq[4]=0xff; led_7dq[3]=0xff;}
   else if  (gia_tri_mod==3) {led_7dq[1]=0xff; led_7dq[0]=0xff;}
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_521_phim_mod()
{
   if(phim_bt1_c2(60))
   {
         gia_tri_mod++;
         if(gia_tri_mod>=4)   gia_tri_mod=0;
         dem_tg_exit=0;
   } 
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_521_phim_up()
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
         ham_521_giai_ma_gan_cho_8led_quet();
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_521_phim_dw()
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
         ham_521_giai_ma_gan_cho_8led_quet();
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void bai_521_3module_123()
{
   xuat_4led_7doan_giaima_xoa_so0(t0);
   ham_521_giai_ma_gan_cho_8led_quet();
   if(bdn<10)
  {
   if(gia_tri_mod!=0)
   {
      if((bdn==0) &&(input(bt0))&&(input(bt2)))
         ham_521_tat_2led_chinh();
      else if(bdn==5) ham_521_giai_ma_gan_cho_8led_quet();
   }
   hien_thi_8led_7doan_quet();
   ham_521_phim_mod();
   ham_521_phim_up();
   ham_521_phim_dw();
   t0=get_timer0();
   if(t0!=t0_tam)
   {
      t0_tam=t0;
      xuat_4led_7doan_giaima_xoa_so0(t0);
      if(t0>=101) set_timer0(1);
   }
   if(ttct_td==1) sang_tat_32led(10,0);
   if(ttct_td==2) sang_tat_dan_pst_32led(10,0);
   if(ttct_td==3) sang_tat_dan_tsp_32led(10,0);
   if(ttct_td==4) sang_tat_dan_ngoai_vao_32led(10,0);
   if(ttct_td==5) sang_tat_dan_trong_ra_32led(10,0);
   if(ttct_td==6) sang_don_pst_32led(10,0);
   if(ttct_td==7) diem_sang_dich_trai_mat_dan_32led(10,0);
   if(ttct_td==8) sang_don_tsp_32led(10,0);
   if(ttct_td==9) diem_sang_dich_phai_mat_dan_32led(10,0);
   if(ttct_td==10) sang_tat_dan_trai_sang_phai_2x16led(10,0);
   if(ttct_td==11) sang_tat_dan_phai_sang_trai_2x16led(10,0);
   if(ttct_td==12) diem_sang_di_chuyen_pst_32led(10,0);
   if(ttct_td==13) diem_sang_di_chuyen_tsp_32led(10,0);
   if(ttct_td==14) sang_don_tnt_32led(10,0);
   if(ttct_td==15) sang_don_ttr_32led(10,0);
   if(ttct_td>15) ttct_td=1;
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







