#define   GIAY_HTAI      0X55
#define   PHUT_HTAI      0X33
#define   GIO_HTAI       0X08
#define   THU_HTAI       8
#define   NGAY_HTAI      0X16
#define   THANG_HTAI     0X06
#define   NAM_HTAI       0X13      
#define   MA_DS          0X98
                                                   
#define  ADDR_WR_1307   0xd0
#define  ADDR_RD_1307   0xd1
#define  ADDR_MEM        0x00

unsigned  char    nam_ds13,thang_ds13,ngay_ds13,thu_ds13,gio_ds13,
                  phut_ds13,giay_ds13,ma_ds13,control_ds13,giaytam;
                                                                             
void thiet_lap_thoi_gian_hien_tai()
{     giay_ds13   =   giay_htai;       phut_ds13  =    phut_htai;   
      gio_ds13    =   gio_htai;        thu_ds13   =    thu_htai;
      ngay_ds13   =   ngay_htai;       thang_ds13 =    thang_htai;   
      nam_ds13    =   nam_htai;   
      control_ds13 = 0x90;             ma_ds13      =   ma_ds; 
      giaytam=0;
}
 
void nap_thoi_gian_htai_vao_ds1307()
{     i2c_start();         
      i2c_write(addr_wr_1307);    i2c_write(0x00);
      i2c_write(giay_ds13);        i2c_write(phut_ds13);      
      i2c_write(gio_ds13);         i2c_write(thu_ds13);      
      i2c_write(ngay_ds13);        i2c_write(thang_ds13);            
      i2c_write(nam_ds13);         i2c_write(control_ds13);   
      i2c_write(ma_ds13);
      i2c_stop();
}
    
void doc_thoi_gian_tu_realtime()
{   
      i2c_start();
      i2c_write(addr_wr_1307);
      i2c_write(addr_mem);                     
      i2c_start();                
                
      i2c_write(addr_rd_1307);
      giay_ds13      =  i2c_read();              
      phut_ds13      =  i2c_read();             
      gio_ds13       =  i2c_read();             
      thu_ds13       =  i2c_read(); 
      ngay_ds13      =  i2c_read(); 
      thang_ds13     =  i2c_read(); 
      nam_ds13       =  i2c_read(); 
      control_ds13   =  i2c_read();          
      ma_ds13        =  i2c_read(0);     //not ack
      i2c_stop();
}    

   
void doc_giay_tu_realtime()
{   
      i2c_start();
      i2c_write(addr_wr_1307);
      i2c_write(addr_mem);                     
      i2c_start();                
                
      i2c_write(addr_rd_1307);
      giay_ds13      =  i2c_read(0);              
      i2c_stop();
}  
        
 
void hien_thi_thoi_gian_ds1307 ( )
{     lcd_goto_xy(3,3);  //lcd_command (0x8c);   
      lcd_data(gio_ds13/16  +0x30);    lcd_data(gio_ds13%16  +0x30);
      lcd_data(' ');
      lcd_data(phut_ds13/16 +0x30);    lcd_data(phut_ds13%16 +0x30);
      lcd_data(' ');
      lcd_data(giay_ds13/16 +0x30);    lcd_data(giay_ds13%16 +0x30);
      lcd_goto_xy(3,12); //lcd_command (0xcc);  
      lcd_data(ngay_ds13/16 +0x30);    lcd_data(ngay_ds13%16 +0x30);
      lcd_data(' ');
      lcd_data(thang_ds13/16 +0x30);   lcd_data(thang_ds13%16 +0x30);
      lcd_data(' ');
      lcd_data(nam_ds13/16 +0x30);     lcd_data(nam_ds13%16 +0x30); 
}

#define pcf8591_address_wr    0x90
#define pcf8591_address_rd    0x91

#define pcf8591_channel_0       0x40
#define pcf8591_channel_1       0x41
#define pcf8591_channel_2       0x42
#define pcf8591_channel_3       0x43

void pcf8591_chonkenh(unsigned char kenh)
{
   i2c_start();
   i2c_write(pcf8591_address_wr);
   i2c_write(kenh);
   i2c_stop();
}

void pcf8591_xuat_dac(unsigned char dac_out)
{
   i2c_start();
   i2c_write(pcf8591_address_wr);
   i2c_write(pcf8591_channel_0);
   i2c_write(dac_out);
   i2c_stop();
}

unsigned char  pcf8591_doc_adc()
{ unsigned char tam;
   i2c_start();
   i2c_write(pcf8591_address_rd);   
   tam= i2c_read(0);
   i2c_stop();
 return tam;
}




