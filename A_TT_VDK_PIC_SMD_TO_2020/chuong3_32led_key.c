                                                                                          
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//TAT CA DEU VIET THEO BAI VA HAM THEO BAI 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//Khai bao bien 32led key
signed int8 mp,mp1=1;
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 301: chop tat 8 led theo cach 1 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_301_chop_tat_8led_c1()
{                                                 
   xuat_32led_don_4byte(0,0,0,0);
   delay_ms(200);   
   xuat_32led_don_4byte(0,0,0,0xff);
   delay_ms(200);              
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 301: chop tat 8 led theo cach 2
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_301_chop_tat_8led_c2(unsigned int16 dl)
{                                                 
   xuat_32led_don_4byte(0,0,0,0);
   delay_ms(dl);   
   xuat_32led_don_4byte(0,0,0,0xff);
   delay_ms(dl);              
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 302: chop tat 16 led theo cach 2
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_302_chop_tat_16led(unsigned int16 dl)
{                                                 
   xuat_32led_don_4byte(0,0,0,0);
   delay_ms(dl);   
   xuat_32led_don_4byte(0,0,0xff,0xff);
   delay_ms(dl);              
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 303: chop tat 32 led 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_303_chop_tat_32led(unsigned int16 dl)
{                                                 
   xuat_32led_don_4byte(0,0,0,0);
   delay_ms(dl);   
   xuat_32led_don_4byte(0xff,0xff,0xff,0xff);
   delay_ms(dl);              
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 304: sang tat dan 8 led 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_304_std_pst_8led(unsigned int16 dl)
{                                                 
   for(i=0;i<8;i++)
   {
      y8=(y8<<1)+1;
      xuat_32led_don_4byte(0,0,0,y8);
      delay_ms(dl);
   }             
   for(i=0;i<8;i++)
   {
      y8=(y8<<1);
      xuat_32led_don_4byte(0,0,0,y8);
      delay_ms(dl);
   }               
}


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 305: sang tat dan 16 led 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_305_std_pst_16led(unsigned int16 dl)
{                                                 
   for(i=0;i<16;i++)
   {
      lp=(lp<<1)+1;
      xuat_32led_don_2word(0,lp);
      delay_ms(dl);
   }             
   for(i=0;i<16;i++)
   {
      lp=(lp<<1);
      xuat_32led_don_2word(0,lp);
      delay_ms(dl);
   }               
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 306: sang tat dan 16 led chay 2 nhom song song
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_306_std_pst_16led_ss(unsigned int16 dl)
{                                                 
   for(i=0;i<16;i++)
   {
      lt=(lt>>1)+0x8000;
      xuat_32led_don_2word(lt,lt);
      delay_ms(dl);
   }             
   for(i=0;i<16;i++)
   {
      lt=(lt>>1);
      xuat_32led_don_2word(lt,lt);
      delay_ms(dl);
   }               
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 307: sang tat dan 32 led pst
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_307_std_pst_32led(unsigned int16 dl)
{                                                 
   for(i=0;i<32;i++)
   {
      y=(y<<1)+1;
      xuat_32led_don_1dw(y);
      delay_ms(dl);
   }             
   for(i=0;i<32;i++)
   {
      y=(y<<1);
      xuat_32led_don_1dw(y);
      delay_ms(dl);
   }               
}


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 308: sang tat dan 32 led tsp
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_308_std_tsp_32led(unsigned int16 dl)
{                                                 
   for(i=0;i<32;i++)
   {
      y=(y>>1)+0x80000000;
      xuat_32led_don_1dw(y);
      delay_ms(dl);
   }             
   for(i=0;i<32;i++)
   {
      y=(y>>1);
      xuat_32led_don_1dw(y);
      delay_ms(dl);
   }               
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 309: sang tat dan 32 led pst-tsp
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_309_std_pst_32led(unsigned int16 dl)
{                                                 
   bai_307_std_pst_32led(dl);
   bai_308_std_tsp_32led(dl);
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 310: tong hop nheu chuong trinh
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_310_chop_tat_32led_nlan(unsigned int16 dl,usi8 n)
{                                                    
   for(sl=0;sl<n;sl++)
   {
      bai_303_chop_tat_32led(dl);
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_310_std_pst_32led_nlan(unsigned int16 dl,usi8 n)
{                                                    
   for(sl=0;sl<n;sl++)
   {
      bai_307_std_pst_32led(dl);
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_310_std_tsp_32led_nlan(unsigned int16 dl,usi8 n)
{                                                    
   for(sl=0;sl<n;sl++)
   {
      bai_308_std_tsp_32led(dl);
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_310_tong_hop_dk_32led()
{                                                 
   ham_310_chop_tat_32led_nlan(100,5);
   ham_310_std_pst_32led_nlan(30,2);
   ham_310_chop_tat_32led_nlan(100,5);
   ham_310_std_tsp_32led_nlan(30,2);  
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 305: sang tat dan 16 led 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_311_xuat_std_tnv_ttr_pst_tsp(unsigned int16 dl, unsigned int8 tt)
{
   if(tt==0)   xuat_32led_don_2word(lp,lp);
   if(tt==1)   xuat_32led_don_2word(lt,lt);
   if(tt==2)   xuat_32led_don_2word(lt,lp);
   if(tt==3)   xuat_32led_don_2word(lp,lt);   
   delay_ms(dl);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void ham_311_std_tnv_ttr_pst_tsp(unsigned int16 dl,unsigned int8 tt)
{                                                 
   for(i=0;i<16;i++)
   {
      lp=(lp<<1)+1;
      lt=(lt>>1)+0x8000;
      ham_311_xuat_std_tnv_ttr_pst_tsp(dl,tt);
   }             
   for(i=0;i<16;i++)
   {
      lp=(lp<<1);
      lt=(lt>>1);
      ham_311_xuat_std_tnv_ttr_pst_tsp(dl,tt);
   }               
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_311_tong_hop_dk_32led()
{                                                 
   ham_310_chop_tat_32led_nlan(100,5);
   ham_310_std_pst_32led_nlan(30,2);
   ham_310_chop_tat_32led_nlan(100,5);
   ham_310_std_tsp_32led_nlan(30,2); 
   ham_310_chop_tat_32led_nlan(100,5);
   ham_311_std_tnv_ttr_pst_tsp(30,2); 
   ham_310_chop_tat_32led_nlan(100,5);
   ham_311_std_tnv_ttr_pst_tsp(30,3); 
   
   ham_310_chop_tat_32led_nlan(100,5);
   ham_311_std_tnv_ttr_pst_tsp(30,0); 
   ham_310_chop_tat_32led_nlan(100,5);
   ham_311_std_tnv_ttr_pst_tsp(30,1); 
   
}


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 321: dk 32led on off 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void b321_dk_32led_on_off_2bt()  
{  
   if(phim_on_c1(c_ktnp,0)==co_nhan)
      xuat_32led_don_1dw(0xffffffff);
   if(phim_off_c1(c_ktnp,0)==co_nhan) 
      xuat_32led_don_1dw(0);                                   
} 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 322: dk 8led on off inv 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void b322_on_off_inv_8led()  
{  
   WHILE(INPUT(ON));
   Y8 = 0X0F;
   XUAT_32LED_DON_4BYTE(0,0,0,Y8);
   DO
   {
      IF(!INPUT(INV))
      {
         Y8 = ~Y8;
         XUAT_32LED_DON_4BYTE(0,0,0,Y8);
      }
   }WHILE(INPUT(OFF));
   XUAT_32LED_DON_4BYTE(0,0,0,0);                                  
} 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 323: dk 8led on off inv CHONG DOI
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_323_phim_inv()
{
   IF(!INPUT(INV))
   {
      DELAY_MS(20);
      IF(!INPUT(INV))
      {
         Y8=~Y8;
         XUAT_32LED_DON_4BYTE(0,0,0,Y8);
         WHILE(!INPUT(INV));
      }
   }
}
void b323_on_off_inv_cdoi_8led()  
{  
   WHILE(INPUT(ON));
   Y8 = 0X0F;
   XUAT_32LED_DON_4BYTE(0,0,0,Y8);
   DO
   {
     ham_323_phim_inv(); 
   }WHILE(INPUT(OFF));
   XUAT_32LED_DON_4BYTE(0,0,0,0);                                  
} 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 324: dk 16led UP DW CLR
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_324_phim_up()
{
   IF(!INPUT(UP))
   {
      DELAY_MS(20);
      IF(!INPUT(UP))
      {
         lp=(lp<<1) + 1;
         XUAT_32LED_DON_2WORD(0,lp);
         do{}WHILE(!INPUT(UP));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_324_phim_dw()
{
   IF(!INPUT(dw))
   {
      DELAY_MS(20);
      IF(!INPUT(dw))
      {
         lp=(lp>>1);
         XUAT_32LED_DON_2WORD(0,lp);
         do{}WHILE(!INPUT(dw));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_324_phim_clr()
{
   IF(!INPUT(clr))
   {
      DELAY_MS(20);
      IF(!INPUT(clr))
      {
         lp=0;
         XUAT_32LED_DON_2WORD(0,lp);
         do{}WHILE(!INPUT(clr));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void b324_16led_up_dw_clr_1()  
{  
     ham_324_phim_up();
     ham_324_phim_dw();
     ham_324_phim_clr();
                                     
} 


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 325: dk 16led UP DW CLR - CLR them chuc nang dao chieu
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_325_phim_up()
{
   IF(!INPUT(UP))
   {
      DELAY_MS(20);
      IF(!INPUT(UP))
      {
         if(i==0)
            lp=(lp<<1) + 1;
         else
            lp=(lp>>1) + 0x8000;
         XUAT_32LED_DON_2WORD(0,lp);
         do{}WHILE(!INPUT(UP));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_325_phim_dw()
{
   IF(!INPUT(dw))
   {
      DELAY_MS(20);
      IF(!INPUT(dw))
      {
         if(i==0)
            lp=(lp>>1);
         else
            lp=(lp<<1);
         XUAT_32LED_DON_2WORD(0,lp);
         do{}WHILE(!INPUT(dw));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_325_phim_clr()
{
   IF(!INPUT(clr))
   {
      DELAY_MS(20);
      IF(!INPUT(clr))
      {
         lp=0;
         i=~i;
         XUAT_32LED_DON_2WORD(0,lp);
         do{}WHILE(!INPUT(clr));
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void b325_16led_up_dw_clr_2()  
{  
    
     ham_325_phim_up();
     ham_325_phim_dw();
     ham_325_phim_clr();
                                     
} 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 326: dk 32led UP DW CLR 7 che do
// Duoc giai o bai b337

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 332: ma tran phim hien thi led don
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void b332_matranphim_leddon()  
{  
    signed int8 mp;
    mp = key_4x4_dw();
    if(mp!=0xff)
      xuat_32led_don_4byte(0,0,0,mp);
                                     
} 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 333: ma tran phim dieu khien 8 led sang tat
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void b333_matranphim_8led_on_off()  
{  
    signed int8 mp;
    do 
    {
      mp=key_nhan();
    }while(mp!=1);
    xuat_32led_don_4byte(0,0,0,0xff);
    
    do 
    {
      mp=key_nhan();
    }while(mp!=0);
    xuat_32led_don_4byte(0,0,0,0);
                                     
} 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 334: ma tran phim dieu khien 8 phim led sang va 8 phim led tat
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void b334_matranphim_8led_16_btn_on_off()  
{  
      signed int8 mp;
      mp=key_4x4_dw();
      if(mp<8)
         {y8=y8|(1<<mp);
         xuat_32led_don_4byte(0,0,0,y8);}
      else if(mp<16)
           {y8=y8  &(~(1<<(mp-8)));
           xuat_32led_don_4byte(0,0,0,y8);}                                    
} 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 335: BAI TONG HOP TUONG TU 326 NHUNG DUNG MA TRAN PHAM
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void bai_335_7ct_7btn()
{
   xuat_4led_7doan_1so(ma7doan[mp]);
   mp=key_4x4_up();
   if(mp==1) sang_tat_32led(10,0);
   if(mp==2) sang_tat_dan_pst_32led(10,0);
   if(mp==3) sang_tat_dan_tsp_32led(10,0);
   if(mp==4) sang_tat_dan_ngoai_vao_32led(10,0);
   if(mp==5) sang_tat_dan_trong_ra_32led(10,0);
   if(mp==6) sang_don_pst_32led(10,0);
   if(mp==7) sang_don_tsp_32led(10,0);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 337: dk 32led UP DW CLR 7 che do *bai giai cho bai 326*
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_337_phim_up()
{
   if(!input(up) && (ttct<7))
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
void ham_337_phim_dw()
{
   if(!input(dw) && (ttct>1))
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
void ham_337_phim_clr()
{
   if(!input(clr) && (ttct>1))
   {
      delay_ms(10);
      if(!input(dw))
      {
         ttct=1;
         reset_toan_bo_bien();
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void b337_tonghop_up_dn_clr()
{
   xuat_4led_7doan_1so(ma7doan[ttct]);
   if(ttct==1) sang_tat_32led(10,0);
   if(ttct==2) sang_tat_dan_pst_32led(10,0);
   if(ttct==3) sang_tat_dan_tsp_32led(10,0);
   if(ttct==4) sang_tat_dan_ngoai_vao_32led(10,0);
   if(ttct==5) sang_tat_dan_trong_ra_32led(10,0);
   if(ttct==6) sang_don_pst_32led(10,0);
   if(ttct==7) sang_don_tsp_32led(10,0);
   ham_337_phim_up();
   ham_337_phim_dw();
   ham_337_phim_clr(); 
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Bai 338: dk 32led chay 7 che do tu dong
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void b338_quangcao()
{
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
   xuat_4led_7doan_2so(ma7doan[ttct_td/10],ma7doan[ttct_td%10]);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

