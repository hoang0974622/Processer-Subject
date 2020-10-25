//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//TAT CA DEU VIET THEO BAI VA HAM THEO BAI 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//Khai bao bien timer
unsigned int8 t0,t0_tam;
unsigned int16 t0_16bit,t0_tam_16bit;
unsigned int8 donvi=0,chuc=0,tram=0;
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void khoi_tao_timer0()
{
   setup_timer_0(t0_ext_l_to_h | t0_div_1);
   set_timer0(0);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 401: hien thi 4 so tu 0-3 cho 4 led 7doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_401_hienthi_4so()
{
   xuat_4led_7doan_4so(0xb0, 0xa4, 0xf9, 0xc0);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 402: hien thi 0-9 cho 1 led 7doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_402_dem_0_9()
{
   for(i=0;i<10;i++)
   {
      xuat_4led_7doan_1so(ma7doan[i]);
      delay_ms(500);
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 403: hien thi 00-99 cho 2 led 7doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_403_dem_00_99()
{
   for(i=0;i<99;i++)
   {
      xuat_4led_7doan_2so(ma7doan[i/10],ma7doan[i%10]);
      delay_ms(100);
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 404: hien thi 00-59 cho 2 led 7doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_404_dem_00_59()
{
   for(i=0;i<60;i++)
   {
      xuat_4led_7doan_2so(ma7doan[i/10],ma7doan[i%10]);
      delay_ms(500);
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 405: hien thi 00-59-00 cho 2 led 7doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_405_dem_00_59_00()
{
   for(i=0;i<60;i++)
   {
      xuat_4led_7doan_2so(ma7doan[i/10],ma7doan[i%10]);
      delay_ms(200);
   }
   i=59;
   for(i=59;i>0;i--)
   {
      xuat_4led_7doan_2so(ma7doan[i/10],ma7doan[i%10]);
      delay_ms(200);
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 406: hien thi 00-59-00 cho 2 led 7doan, thoi gian dung tai 59 va 00 la 3s
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_406_dem_00_59_00_3s()
{
      i=0;
      do
      {
         xuat_4led_7doan_2so(ma7doan[i/10],ma7doan[i%10]);
         delay_ms(200);
         if(i==59)
            break;
         i++;
      }while(i<=59);
      delay_ms(3000);
      do
      { 
            xuat_4led_7doan_2so(ma7doan[i/10],ma7doan[i%10]);
            delay_ms(200);
            if(i==0)
               break;
            i--;
  
      }while(i>=0);
      delay_ms(3000);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 407: hien thi 000-999 cho 3 led 7doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_407_dem_000_999()
{
   for(y=0;y<1000;y++)
   {
      xuat_4led_7doan_3so(ma7doan[y/100],ma7doan[y/10%10],ma7doan[y%10]);
      delay_ms(50);
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 408: hien thi 00.0-9999 cho 4 led 7doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_408_dem_0000_9999()
{

   
   for(y=0;y<10000;y++)
   {
      xuat_4led_7doan_4so(ma7doan[y/1000],ma7doan[y/100%10],ma7doan[y/10%10],ma7doan[y%10]);
      delay_ms(50);
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 409: hien thi dem phut giay cho 2 led 7doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_409_dem_phut_giay()
{
   for(y=0;y<60;y++)
   {
      for(i=0;i<60;i++)
      {
         xuat_4led_7doan_4so(ma7doan[y/10],ma7doan[y%10],ma7doan[i/10],ma7doan[i%10]);
         delay_ms(500);
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 411: dem dung counter t0 hien thi 4 led 7doan 0-100
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_411_dem_xung_t0()
{
   t0=get_timer0();
   xuat_4led_7doan_3so(ma7doan[t0/100],ma7doan[t0/10%10],ma7doan[t0%10]);
   if(t0>=101)
      set_timer0(1);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 412: dem dung counter t0 hien thi 4 led 7doan 0-100 xoa so 0 vo nghia
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_412_giai_ma_hien_thi(unsigned int16 tam)
{
   donvi=ma7doan[tam%10];
   chuc=ma7doan[tam/10%10];
   tram=ma7doan[tam/100];
   if(tram==0xc0)
   {
      tram=0xff;
      if(chuc==0xc0)
         chuc=0xff;
   }
   xuat_4led_7doan_3so(tram,chuc,donvi);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void bai_412_dem_xung_t0_xoa_so0_vn()
{
   t0=get_timer0();
   ham_412_giai_ma_hien_thi(t0);
   if(t0>=101)
      set_timer0(1);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 413: dem dung counter t0 hien thi 4 led 7doan 0-100 xoa so 0 vo nghia 
//         nhung chi hien thi khi co ket qua dem
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void bai_413_dem_xung_t0_xoa_so0_vn_ct()
{
   t0_tam=t0=0;
   t0=get_timer0();
   if(t0!=t0_tam)
   {
      t0_tam=t0;
      xuat_4led_7doan_giaima_xoa_so0(t0);
   }
   if(t0>=101)
      set_timer0(1);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 414: dem 4 led 7doan tu 240-255
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void bai_414_dem_xung_t0_240_255()
{
   t0_tam=t0=0;
   t0=get_timer0();
   if(t0!=t0_tam)
   {
      t0_tam=t0;
      xuat_4led_7doan_giaima_xoa_so0(t0);
   }
   if(t0==0)
      set_timer0(240);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 415: dem 4 led 7doan tu 250-300
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void bai_415_dem_xung_t0_250_300()
{
   t0_tam_16bit=t0_16bit=0;
   t0_16bit=get_timer0();
   if(t0_16bit!=t0_tam_16bit)
   {
      t0_tam_16bit=t0_16bit;
      xuat_4led_7doan_giaima_xoa_so0(t0_16bit);
   }
   if(t0_16bit>=301)
      set_timer0(250);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 416: dem 4 led 7doan tu 0-9999
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void bai_416_dem_xung_t0_0_9999()
{
   t0_tam_16bit=t0_16bit=0;
   t0_16bit= get_timer0();
   if(t0_16bit!=t0_tam_16bit)
   {
      t0_tam_16bit=t0_16bit;
      xuat_4led_7doan_giaima_xoa_so0(t0_16bit);
   }
   if(t0_16bit>=10000)
      set_timer0(1);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 417: giong bai 413 nhung hien thi 32led don va co nut nhan on off
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_417_phim_on()
{
   IF(!INPUT(on))
   {
      DELAY_MS(20);
      IF(!INPUT(on))
      {
         setup_timer_0(t0_ext_l_to_h);
         set_timer0(t0_16bit);
         xuat_32led_don_1dw(0xFFFFFFFF);
         do{}WHILE(!INPUT(on));
      }
   }
  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_417_phim_off()
{
   IF(!INPUT(off))
   {
      DELAY_MS(20);
      IF(!INPUT(off))
      {
         setup_timer_0(t0_ext_l_to_h | t0_div_1|T0_OFF);
         xuat_32led_don_1dw(0x00);
         set_timer0(t0_16bit);
         do{}WHILE(!INPUT(off));
      }
   }
  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_417_dem_xung_t0_start_stop_32led()
{
   ham_417_phim_on();
   ham_417_phim_off();
   t0_tam_16bit=t0_16bit=0;
   t0_16bit=get_timer0();
   if(t0_16bit!=t0_tam_16bit)
   {
      t0_tam_16bit=t0_16bit;
      xuat_4led_7doan_giaima_xoa_so0(t0_16bit);
   }
   if(t0_16bit>=10000)
      set_timer0(1);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 421: ket hop 413 va 338 : vua dem san pham vua dieu khien 32 led don sang nhieu chuong trinh
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_421_phim_up()
{
   if((!input(up)) && (ttct<7))
   {
      delay_ms(10);
      if(!input(up))
      {
         ttct++;
         while(!input(up));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_421_phim_dw()
{
   if((!input(dw)) && (ttct>1))
   {
      delay_ms(10);
      if(!input(dw))
      {
         ttct--;
         while(!input(dw));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_421_phim_clr()
{
   if((!input(clr)) && (ttct>1))
   {
      delay_ms(10);
      if(!input(clr))
      {
         ttct=1;
         while(!input(clr));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_421_dem_xung_t0_quang_cao_32led()
{
   //ttct=1;
   t0_tam=t0;
   t0=get_timer0();
   if(t0!=t0_tam)
   {
      t0_tam=t0;
      xuat_4led_7doan_giaima_xoa_so0(t0);
      if(t0>=101)
         set_timer0(1);
   }
   if(ttct==1) sang_tat_32led(10,0);
   if(ttct==2) sang_tat_dan_pst_32led(10,0);
   if(ttct==3) sang_tat_dan_tsp_32led(10,0);
   if(ttct==4) sang_tat_dan_ngoai_vao_32led(10,0);
   if(ttct==5) sang_tat_dan_trong_ra_32led(10,0);
   if(ttct==6) sang_don_pst_32led(10,0);
   if(ttct==7) sang_don_tsp_32led(10,0);
   ham_421_phim_up();
   ham_421_phim_dw();
   ham_421_phim_clr();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 422: ket hop 413 va 338 : vua dem san pham vua dieu khien 32 led don sang nhieu chuong trinh nhung tu dong
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_422_dem_xung_t0_quang_cao_32led()
{
   //ttct=1;
   t0_tam=t0;
   t0=get_timer0();
   if(t0!=t0_tam)
   {
      t0_tam=t0;
      xuat_4led_7doan_giaima_xoa_so0(t0);
      if(t0>=101)
         set_timer0(1);
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
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 423: dich 4 led 7 doan, du lieu nhap tu ma tran phim
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
unsigned char m4led[4]={0x7f,0x7f,0x7f,0x7f};
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_423_key_4x4_4led_dich()
{
   unsigned int mp,i;
   
   xuat_4led_7doan_4so(m4led[3],m4led[2],m4led[1],m4led[0]);
   do {mp=key_4x4_dw();}
   while(mp==0xff);
   for(i=3;i>0;i--)
   {
      m4led[i]=m4led[i-1];  
   }
   m4led[0]=ma7doan[mp];
   xuat_4led_7doan_4so(m4led[3],m4led[2],m4led[1],m4led[0]);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 424: dich 4 led 7 doan, du lieu nhap tu ma tran phim, phim C tra ve ban dau, phim B undo toi da 4
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
unsigned char m4led8[8]={0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f};
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_424_key_4x4_4led_dich_undo4()
{
   unsigned int mp;
   signed int i,j;
   xuat_4led_7doan_4so(m4led8[4],m4led8[5],m4led8[6],m4led8[7]);
   do 
   {
      mp=key_4x4_dw();
   }
   while(mp==0xff);
   if(mp<10)
   {
     for(i=0;i<8;i++)
      {
         m4led8[i]=m4led8[i+1];
      }
      m4led8[7]=ma7doan[mp];
      if(j<4)
         j++;
   }
   else if(mp==0x0B)//phimB
   { 
      if(j>0)
      {
         j--;
         for(i=6;i>-1;i--)
            m4led8[i+1]=m4led8[i];
      }
    }
   else if(mp==0x0C)//phimC
   {
      j=0;
      for(i=0;i<8;i++)
         m4led8[i]=0x7f;
   }
   xuat_4led_7doan_4so(m4led8[4],m4led8[5],m4led8[6],m4led8[7]);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
