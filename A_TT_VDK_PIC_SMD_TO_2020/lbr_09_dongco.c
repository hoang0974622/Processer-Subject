unsigned  int16 stepmotor_fullstep[]=  {0x0700,0x0680,0x0580,0x0380};
unsigned  int16 stepmotor_halfstep[]=  {0x0380,0x0300,0x0600,0x0000,0x0400,0x0480,0x0580,0x0780};


unsigned  int8 stepmotor_i=0, stepmotor_delay;
int1 stepmotor_tn=0,stepmotor_onoff=0;

void step_motor_quay_thuan_fs()                     
{
      rbdc=rbdc & 0xf87f;           
      rbdc=rbdc | stepmotor_fullstep[stepmotor_i];
      //xuat_buzzer_relay();         
      stepmotor_i--;
      stepmotor_i = stepmotor_i & 0x03;
}
void step_motor_quay_nghich_fs()
{
      rbdc=rbdc & 0xf87f;           
      rbdc=rbdc | stepmotor_fullstep[stepmotor_i];
      //xuat_buzzer_relay();
      stepmotor_i++;
      stepmotor_i = stepmotor_i & 0x03;
}
void motor_step_run_fs()
{
   if (stepmotor_tn) step_motor_quay_thuan_fs();
   else           step_motor_quay_nghich_fs();
}

void step_motor_quay_thuan_hs()
{
      rbdc=rbdc & 0xf87f;           
      rbdc=rbdc | stepmotor_halfstep[stepmotor_i];
      xuat_buzzer_relay();
      stepmotor_i++;
      stepmotor_i = stepmotor_i & 0x07;
}
void step_motor_quay_nghich_hs()
{     
      rbdc=rbdc & 0xf87f;
      rbdc=rbdc | stepmotor_halfstep[stepmotor_i];
      xuat_buzzer_relay();
      stepmotor_i--;
      stepmotor_i = stepmotor_i & 0x07;
}
void motor_step_run_hs()
{
   if (stepmotor_tn) step_motor_quay_thuan_hs();
   else           step_motor_quay_nghich_hs();
}

void step_motor_reset_thoigian()                     
{                                        
   stepmotor_delay=5;
   stepmotor_onoff=0;
}
 
                                                   
