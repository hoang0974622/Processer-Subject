

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//xuat 1 bit roi tra lai ket qua sau khi dich di 1 bit
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
unsigned  int8 xuat_1bit(unsigned int8 bytexuat)
{
      unsigned int8   xbitx;   
      #bit bserix  = xbitx.0
      xbitx = bytexuat;
                                            
      output_bit(ssdo,bserix);    
      output_low(ssck); output_high(ssck);
      xbitx= xbitx>>1;   
      return(xbitx);  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//ham 101

//ham 104





//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx         
void xuat_2byte(unsigned int16 byte2xuat)
{
   int8 sbb;
   unsigned int16   xx;   //short  bseri;
   #bit bserix  = xx.15
   xx = byte2xuat;
   for (sbb=0;sbb<16;sbb++)
      {                                                 
         output_bit(ssdo,bserix);    
         output_low(ssck);         output_high(ssck);
         xx= xx<<1;         
     }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat ra led ma tran
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_matranled(unsigned int16 mahang,unsigned int16 macot1,
unsigned int16 macot2,unsigned int16 macot3)
{      
      xuat_2byte(macot3);
      xuat_2byte(macot2);
      xuat_2byte(macot1);
      xuat_2byte(mahang);
      
      mo_led_matran;
      mo_ic_74573_b_thong_dl();
      
      output_high(rck_matranled); output_low(rck_matranled); 
      chot_ic_74573_b_goi_du_lieu;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat ra led ma tran
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void tat_matranled()
{      
      xuat_2byte(0);
      xuat_2byte(0);
      xuat_2byte(0);
      xuat_2byte(0);           
      output_high(rck_matranled); output_low(rck_matranled); 
}
unsigned  int8 hieu_chinh_4bit_cao(unsigned int8 xzy)
{
      int1  btg;
      unsigned int8   bx;   
      #bit bit4  = bx.4
      #bit bit5  = bx.5
      #bit bit6  = bx.6
      #bit bit7  = bx.7
      bx=xzy;
      btg=bit4;   bit4=bit7;  bit7=btg;
      btg=bit5;   bit5=bit6;  bit6=btg;      
      return(bx);  
}  

