//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//TAT CA DEU VIET THEO BAI VA HAM THEO BAI

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//Khai bao bien dong co buoc,dong co dc va encoder,pwm,dieu khien pid
unsigned int8 pwm_capso;
unsigned int16 duty;
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 901:  dieu khin dung co buoc có 2 nút dieu khien: ON, OFF.Khi nhan ON thì dng co quay theo chieu kim dong ho, khi nhan OFF thì ngung
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_901_step_on_off()
{
   while(input(on));
   do
   {
      step_motor_quay_thuan_fs();
      delay_ms(stepmotor_delay);
   }
   while (input(off));
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 902:  dieu khin dung co buoc có 2 nút dieu khien: ON, OFF.Khi nhan ON thì dng co quay nguoc chieu kim dong ho, khi nhan OFF thì ngung
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_902_step_on_off_qn()
{
   while(input(on));
   do
   {
      step_motor_quay_nghich_fs();
      delay_ms(stepmotor_delay);
   }
   while (input(off));
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 903:  dieu khin dung co buoc có 3 nút dieu khien: ON, OFF, INV
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_903_phim_inv()
{
   if (!input(inv))
   {
      delay_ms(20);
      {
         if (!input(inv))
         {
            stepmotor_tn=~stepmotor_tn;
            do
            {
               motor_step_run_fs();
               delay_ms(stepmotor_delay);
            }
            while(!input(inv));
         }
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_903_step_on_off_inv()
{
   while(input(on));
   do
   {
      
      motor_step_run_fs();
      delay_ms(stepmotor_delay);
      ham_903_phim_inv();
   }
   while (input(off));
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai 904:  giong 903 nhung hien thi them so buoc tren 4 led 7 doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ham_904_phim_inv()
{
   if (!input(inv))
   {
      delay_ms(20);
      {
         if (!input(inv))
         {
            stepmotor_tn=~stepmotor_tn;
            so_buoc=0;
            do
            {
               motor_step_run_fs();
               delay_ms(stepmotor_delay);
            }
            while(!input(inv));
         }
      }
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_904_step_on_off_inv()
{
   while(input(on));
   do
   {
      
      motor_step_run_fs();
      delay_ms(stepmotor_delay);
      ham_904_phim_inv();
      xuat_4led_7doan_giaima_xoa_so0(so_buoc);
   }
   while (input(off));
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Bai thi
unsigned int8 flag1=0;
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void hien_thi_4led_7doan()
{
   xuat_4led_7doan_4so(0xff,ma7doan[giay/10],ma7doan[giay%10],0xff);
   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void hien_thi_lcd_so_to()
{
   //setup_lcd();
   lcd_hienthi_so_z_toado_xy(t0/10,2,0);
   lcd_hienthi_so_z_toado_xy(t0%10,2,3);
   if(flag1==0)
   {
      lcd_goto_xy(0,0);
      lcd_data("                    ");
      lcd_goto_xy(1,0);
      lcd_data("                    ");
      lcd_goto_xy(0,18);
      lcd_data(lm35a/10+0x30);
      lcd_data(lm35a%10+0x30);
   }
   else if(flag1==1)
   {
      lcd_hienthi_so_z_toado_xy(lm35a/10,0,14);
      lcd_hienthi_so_z_toado_xy(lm35a%10,0,17);
   }
   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void doc_nd_lm35a()
{
   set_adc_channel(0);
   lm35a=0;
   for(j=0;j<(200);j++)
   {
      lm35a = lm35a + read_adc();
      delay_us(100);
   }
   lm35a=lm35a/2.046;
   lm35a=lm35a/(200);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bai_thi()
{
  if(bdn<10)
  {
   hien_thi_4led_7doan();
   t0=get_timer0();
   if(t0!=t0_tam)
   {
      if(flag==0)
      {
         t0_tam=t0;
         hien_thi_lcd_so_to();
         duty=duty+50;
         set_pwm1_duty(duty);
         pwm_capso=t0;
         
      }
      else if(flag==1)
      {
         t0=20-t0;
         t0_tam=t0;
         hien_thi_lcd_so_to();
         duty=duty-50;
         set_pwm1_duty(duty);
         pwm_capso=t0;
      }
      
   }
   if(t0>=21)
   {
      set_timer0(1);
      flag=1;
   }
   else if(t0==0)
   {
     set_timer0(0);
     flag=0; 
   }
   doc_nd_lm35a();
   hien_thi_lcd_so_to();
  } 
  else
  {
   bdn=bdn-10;
   giay++;
   if(giay<=29)
     flag1=0;
   else
      flag1=1;
   if(giay==60)
      giay=0;
  }  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx





