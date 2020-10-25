//ham 701
  
unsigned int8 lcddata=0; 
unsigned int8 lcdcontrol=0;
unsigned int8 glcddata=0;
unsigned int8 glcdcontrol=0;    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//chuong trinh con xuat du lieu 4 byte ra glcd va lcd
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_glcd_lcd()
{      
    xuat_1byte(glcdcontrol);             
    xuat_1byte(glcddata);
    xuat_1byte(lcdcontrol);       
    xuat_1byte(lcddata);      
                                  
    mo_glcd_lcd;
    mo_ic_74573_a_thong_dl();            
    output_high(rck_lcd20x4);     
    output_low(rck_lcd20x4);
    chot_ic_74573_a_goi_du_lieu;
}
//ham 702
void xuat_lcd20x4(unsigned int8 lcd_signal,lcd_ins_hthi)
{     
    lcdcontrol = ~lcd_signal;
    lcddata    = ~lcd_ins_hthi;      
    xuat_glcd_lcd();
}
//ham 703
void xuat_glcd128x64(unsigned int8 glcd_signal,glcd_ins_hthi)
{     
    glcdcontrol = ~glcd_signal;
    glcddata    = ~glcd_ins_hthi;     
    xuat_glcd_lcd();
}
     

