#Define  bt0     pin_b5
#define  bt1     pin_b4
#define  bt2     pin_b3
#define  bt3     pin_b2

#define  on      bt0       //dk led don, motor
#define  off     bt1
#define  inv     bt2

#define  up      bt0    //dk led don
#define  dw      bt1
#define  clr     bt2
#define  mod     bt3

#define  stop    bt3

#define  on1     bt0     
#define  off1    bt1
#define  on2     bt2       
#define  off2    bt3   

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//thu vien cho cac phim don va ban phim cam ung
//co 2 cach phat hien va chong doi phim nhan
//tra ve 
//tac gia: NDP su pham kt thuat tp hcm
 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//cac ham con cua cac phim nhan don theo cach 1
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//phim bt0-cach 1: co chong doi, delay 20ms, cho nha phim
//dinh nghia them 1 so ten khac     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                       
#define phim_on_c1  phim_bt0_c1    
#define phim_run_c1 phim_bt0_c1 
#define phim_up_c1  phim_bt0_c1       

int1 phim_bt0_c1(int1 ktnp,usi16 dl)   
{                    
   if (!input(bt0))   
   {        
      delay_ms(20);                                     
      if (!input(bt0))
      {
         if(ktnp) while(!input(bt0));
         if(dl!=0)  delay_ms(dl);
         return co_nhan;      
      }                      
      return khong_nhan;   
   }         
  return khong_nhan;  
}     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//phim bt1-cach 1: co chong doi, delay 20ms, cho nha phim
//dinh nghia them 1 so ten khac      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
#define phim_off_c1   phim_bt1_c1   
#define phim_stop_c1  phim_bt1_c1
#define phim_dw_c1    phim_bt1_c1                  
int1 phim_bt1_c1(int1 ktnp,usi16 dl)                                               
{
   if (!input(bt1))   
   {                       
      delay_ms(20);
      if (!input(bt1))
      {
         if(ktnp) while(!input(bt1));    
         if(dl!=0) delay_ms(dl);
         return co_nhan;
      } 
      return khong_nhan;
   }
   return khong_nhan;  
}       
     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//phim bt2-cach 1: co chong doi, delay 20ms, cho nha phim
//dinh nghia them 1 so ten khac      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
#define phim_inv_c1 phim_bt2_c1      
int1 phim_bt2_c1(int1 ktnp,usi16 dl)      
{
   if (!input(bt2))   
   {        
      delay_ms(20);                
      if (!input(bt2))
      {
         if(ktnp) while(!input(bt2));    
         if(dl!=0) delay_ms(dl);
         return co_nhan;
      }                                     
      return khong_nhan; 
   }
   return khong_nhan;  
}      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//phim bt3-cach 1: co chong doi, delay 20ms, cho nha phim
//dinh nghia them 1 so ten khac      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     
#define phim_mode_c1  phim_bt3_c1 
#define phim_ud_c1    phim_bt3_c1  
int1 phim_bt3_c1(int1 ktnp,usi16 dl)      
{                       
   if (!input(bt3))   
   {                       
      delay_ms(20);                       
      if (!input(bt3))
      {                      
         if(ktnp) while(!input(bt3));    
         if(dl!=0) delay_ms(dl);
         return co_nhan;
      } 
      return khong_nhan;   
      }                       
   return khong_nhan;  
}  

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      
//ham kiem tra 2 phim on/off
//neu co nhan on lam bit tt = enable va tt phim = co nhan
//neu co nhan of lam bit tt = disable va tt phim = co nhan
//neu khong nhan thi bit tt khong doi va tt phim = khong nhan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     
int1 phim_on_off_inv_3btn()   
{                                                      
   if(phim_on_c1(c_ktnp,0)==co_nhan)   
   {                
      tt_on_off = tt_on;
      return co_nhan;            
   }                         
   else                       
   if(phim_off_c1(c_ktnp,0)==co_nhan)
   {
      tt_on_off = tt_off;     
      return co_nhan;    
   } 
   else                       
   if(phim_inv_c1(c_ktnp,0)==co_nhan)     
   {                                                    
      tt_inv = true;                         
      return co_nhan;       
   }                        
   else   return khong_nhan;
}
  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx       
//ham kiem tra 2 phim on/off
//neu co nhan on lam bit tt = enable va tt phim = co nhan
//neu co nhan of lam bit tt = disable va tt phim = co nhan
//neu khong nhan thi bit tt khong doi va tt phim = khong nhan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     
int1 phim_on_off_2btn()   
{                     
   if(phim_on_c1(c_ktnp,0)==co_nhan)     
   {
      tt_on_off = tt_on;
      return co_nhan;   
   }                         
   else                       
   if(phim_off_c1(c_ktnp,0)==co_nhan)
   {
      tt_on_off = tt_off;     
      return co_nhan;    
   }
   else   return khong_nhan;                   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                               
//ham kiem tra phim on 
//neu co nhan thi dao bit tt_on_off va tra ve co nhan
//neu khong nhan tra ve tt khong nhan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     
int1 phim_on_off_1btn()   
{                     
   if(phim_on_c1(c_ktnp,0)==co_nhan)   
   {
      tt_on_off = ~tt_on_off;
      return co_nhan;   
   }                         
   else   return khong_nhan;                   
}   


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//cac ham con cua cac phim nhan don theo cach 2
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//phim bt0-cach 2: nhan so lan thuc hien la bien dl
//kiem tra neu co nhan thi tang bien dem dl_btn,delay 1ms.   
//Neu bien dl_btn = dl thi reset dl_btn = 0,
//xem nhu co nhan va ket thuc. 
//con lai thi xem nhu chua nhan hoac chua du thoi gian nhan
//moi chu ky thuc hien lon nhat la 1ms - khong cho nha phim 
//dinh nghia them 1 so ten khac  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
#define phim_on_c2  phim_bt0_c2                    
#define phim_run_c2 phim_bt0_c2      
#define phim_up_c2  phim_bt0_c2                    
int1 phim_bt0_c2(usi16 dl)  
{                      
   if (!input(bt0))                       
   {   
      dl_btn++;   delay_ms(1);               
      if(dl_btn>=dl) 
      {  
         dl_btn =0;
         return co_nhan;
      }     
      else
      {
         return khong_nhan; 
      }
   }
    else  return khong_nhan;    
} 
    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham chong doi cach 1 cho phim bt1
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      
#define phim_off_c2   phim_bt1_c2   
#define phim_stop_c2  phim_bt1_c2  
#define phim_dw_c2    phim_bt1_c2  
int1 phim_bt1_c2(usi16 dl)
{                      
   if (!input(bt1))   
   {           
      dl_btn++;  delay_ms(1); 
      if(dl_btn >= dl)    
      {  
         dl_btn =0;
         return co_nhan;
      }     
      else
      {
         return khong_nhan; 
      }
    }
    else  return khong_nhan;    
}     

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham chong doi cach 1 cho phim bt31
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#define phim_inv_c2    phim_bt2_c2  

int1 phim_bt2_c2(usi16 dl) 
{                      
   if (!input(bt2))   
   {                                  
      dl_btn++;  delay_ms(1); 
      if(dl_btn >= dl) 
      {  
         dl_btn =0;
         return co_nhan;   
      }     
      else            
      {
         return khong_nhan; 
      }
    }
    else  return khong_nhan;    
}                                       
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham chong doi cach 1 cho phim bt31
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx        
#define phim_mode_c2  phim_bt3_c2  
#define phim_ud_c2    phim_bt3_c2  
 
                              
int1 phim_bt3_c2(usi16 dl) 
{                      
   if (!input(bt3))    
   {                         
      dl_btn++;    delay_ms(1);                                               
      if(dl_btn >= dl) 
      {                              
         dl_btn =0;                                 
         return co_nhan; 
      }     
      else
      {
         return khong_nhan; 
      }
    }
    else  return khong_nhan;    
}                     



const unsigned char maquetkey[4]= {0x3f,0x7f,0xbf,0xff};
unsigned int8  mpt1=0,mpt2=0;  
unsigned int key_nhan()
{     signed int8 maphim,hang,cot;
      maphim=hang=0xff;
      for(cot=0;cot<4;cot++)
            {   
               output_b(maquetkey[cot]);
               if         (!input(pin_b2))      {hang=3;   break;}
               else    if (!input(pin_b3))      {hang=2;   break;}
               else    if (!input(pin_b4))      {hang=1;   break;}
               else    if (!input(pin_b5))      {hang=0;   break;}
            }          
         if (hang!=0xff)   maphim   = cot*4 + hang;
         return(maphim);
}
unsigned int key_4x4_dw()
{     
      mpt1=key_nhan();         
      if (mpt1!=0xff)   
      {  delay_ms(1);  
         mpt1=key_nhan();
         do{mpt2=key_nhan();}
         while (mpt2==mpt1);
      }             
      return(mpt1);
}

unsigned int key_4x4_up()
{            
      mpt1=key_nhan();
      if (mpt1!=0xff)   
      {  
         if (mpt1!=mpt2)
            {
               return(mpt1);  //phim moi
               mpt2=mpt1;
            }
         else
         {
            delay_ms(1);
            mpt1=key_nhan();
            do
            {
               mpt2=key_nhan();
               }
            while (mpt2!=mpt1);
               return(mpt1);     //thoat vi trung ma phim da nhan
               mpt2=mpt1;           
         }
      }  
      else 
      {
         return(mpt1);  //thoat vi khong nhan
         mpt2=mpt1;
      }      
}



                                      
                                      
