//ham 401
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//chuong trinh con xuat 4 byte ra 4 led 7 doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void xuat_4led_7doan_4so(unsigned int bl743,bl742,bl741,bl740)
{     
      xuat_1byte(bl740);   xuat_1byte(bl741);
      xuat_1byte(bl742);   xuat_1byte(bl743);
      
      mo_4_led_7doan;
      mo_ic_74573_a_thong_dl();
       
      output_low(rck_4led7doan);   output_high(rck_4led7doan); 
      chot_ic_74573_a_goi_du_lieu;
}
//ham 404
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void xuat_4led_7doan_3so(unsigned int bl742,bl741,bl740)
{     
     xuat_4led_7doan_4so(0xff,bl742,bl741,bl740);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//ham 403
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void xuat_4led_7doan_2so(unsigned int bl741,bl740)
{     
     xuat_4led_7doan_4so(0xff,0xff,bl741,bl740);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//ham 402
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void xuat_4led_7doan_1so(unsigned int bl740)
{     
     xuat_4led_7doan_4so(0xff,0xff,0xff,bl740);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                           
//ham 405
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con hien thi du lieu 16 bit tren 4 led 7 doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
unsigned char donvi4,chuc4,tram4,ngan4;
void  xuat_4led_7doan_giaima_xoa_so0 (unsigned int16 tam)
{         
      donvi4 = ma7doan[tam %10];         
      chuc4  = ma7doan[tam/10%10];
      tram4  = ma7doan[tam/100%10]; 
      ngan4  = ma7doan[tam/1000%10];       
      if (ngan4==0xc0)
      {
         ngan4=0xff;
         if (tram4==0xc0)
         {
            tram4=0xff;
            if (chuc4==0xc0)   chuc4=0xff;
         }
      }
      xuat_4led_7doan_4so(ngan4,tram4,chuc4,donvi4);   
}

void  xuat_4led_7doan_2_so (unsigned int8 bh,bl)
{         
 xuat_4led_7doan_4so(ma7doan[bh/10],ma7doan[bh%10],ma7doan[bl/10],ma7doan[bl%10]);   
}  

unsigned char donvi2,donvi1,chuc2,chuc1;
void  xuat_4led_7doan_2_so_xoa_so0 (unsigned int8 bh,bl)
{
   donvi2 = ma7doan[bh %10];         
   chuc2  = ma7doan[bh/10%10];
   donvi1 = ma7doan[bl %10];         
   chuc1  = ma7doan[bl/10%10];
   if(chuc2==0xc0)
   {
      chuc2=0xff;
   }
   if(chuc1==0xc0)
   {
      chuc1=0xff;
   }
   xuat_4led_7doan_4so(chuc2,donvi2,chuc1,donvi1);
}

