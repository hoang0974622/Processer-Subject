#include <b_tv_lbr_chuong_all.c>                      
void main()     
{                                                            
   set_up_port_ic_chot();
   //setup_timer0;
   khoi_tao_timer0();
   khoi_tao_timer1_ngat();
   setup_lcd();
   //khoi_tao_glcd();
   khoi_tao_ds18b20();
   khoi_tao_adc();
   //khoi_tao_ds13b07();
   pcf8591_xuat_dac(250);
   stepmotor_delay=5;
   stepmotor_onoff=1;
   lcd_command(0x40);
   for(i=0;i<64;i++) lcd_data(lcd_ma_8doan[i]);
   dc_motor_enable();
   output_low(pin_c1);
   setup_ccp1(ccp_pwm);

   
   while(true)
   {                                                          
      bai_thi();
      //bai_904_step_on_off_inv();
      //bai_903_step_on_off_inv();
      //bai_902_step_on_off_qn();
      //bai_901_step_on_off();
      
      //bai_831_pir_dk_den();
      //bai_822_pcf8591_4led_cds_on_off_den();
      //bai_821_pcf8591_4led_cds();
      //bai_815_pcf8591_4led_lm35ab();
      //bai_814_pcf8591_4led_lm35a_buz_den();
      //bai_813_pcf8591_4led_lm35a_buz();
      //bai_812_pcf8591_4led_lm35a_buz()
      //bai_811_pcf8591_4led_lm35a();
      //bai_809_i2c_rt_lcd_to_nho();
      //bai_808_i2c_rt_lcd_to();
      //bai_807_i2c_rt_lcd_3key_chuong();
      //bai_806_i2c_rt_lcd_3key_alram();
      //bai_805_i2c_rt_lcd_3key_buzzer();
      //bai_804_i2c_rt_lcd_3key_nn();
      //bai_803_i2c_rt_lcd_3key();
      //bai_802_i2c_rt_lcd_3key();
      //bai_801_i2c_rt_lcd();
      //bai_735_ds18b20a_t0();
      //bai_734_ds18b20a_lm35a();
      //bai_733_ds18b20a_lcd_buzzer();
      //bai_732_ds18b20a_on_off_32led();
      //bai_731_ds18b20a();
      //bai_714_lcd_2lm35_t0_gp2d12();
      //bai_713_gp2d12_ss1cm();
      //bai_712_gp2d12_ss1cm();
      //bai_711_gp2d12_ss10cm();
      //bai_711_gp2d12_ss10cm();
      //bai_710_lm35_counter_lcd();
      //bai_709_lm35_up_dw();
      //bai_708_lm35a_counter_t0();
      //bai_707_2lm35_lcd();
      //bai_706_2lm35_buzz();
      //bai_705_adc_2lm35();
      //bai_704_lm35a_buzz_auto();
      //bai_703_lm35a_buzz_auto();
      //bai_702_lm35a_buzz();
      //bai_701_lm35a();
      
      //bai_672_glcd_tonghop_5_module();
      //bai_671_glcd_tonghop_5_module();
      //BAI_655_GLCD_DEM_GIAY();
      //bai_664_glcd_dem_sp_t0_ht_cot();
      //bai_663_glcd_dt_dt();
      //bai_662_glcd_2bitmap_spkt();
      //bai_661_glcd_bitmap_spkt();
      //bai_654_glcd_lcd_4led_dem_sp_t0();
      //bai_653_glcd_dem_sp_t0();
      //bai_652_glcd_hien_thi_chuoi();
      //bai_644_lcd_dem_sp_ktl();
      //bai_643_lcd_dem_00_99();
      //bai_642_lcd_so_0123();
      //bai_641_lcd_so_0();
      //bai_636_lcd_apple_dichchuyen();
      //bai_635_lcd_apple();
      //bai_634_lcd_8kytu();
      //bai_633_lcd_3kytu();
      //bai_632_ht_20_traitim();
      //bai_631_ht_trai_tim();
      // bai_625_lcd_4led_dem_sp_t0_matrix_key();
      //bai_624_lcd_key4x4_dich();
      //bai_623_lcd_key4x4_dich_4hang_1234();
      //bai_622_lcd_key4x4_dich();
      //bai_621_lcd_key4x4();
      //bai_617_lcd_4led_dem_sp_t0_ud();
      //bai_616_lcd_4led_dem_sp_t0();
      //bai_615_lcd_8led_gio_phut_giay();
      //bai_614_lcd_gio_phut_giay();
      //bai_613_lcd_ht_dem_gio_phut_giay();
      //bai_612_lcd_ht_dem_phut_giay();
      //bai_611_lcd_ht_dem_giay();
      //bai_606_lcd_ht_2hang_dich_2c();
      //bai_605_lcd_ht_2hang_dich_phai();
      //bai_604_lcd_ht_2hang_dich_trai();
      //bai_603_lcd_ht_4kytu_4goc();
      //bai_602_lcd_hienthi_4hang();
      //bai_601_lcd_hienthi_4hang();
      
      //bai_521_3module_123();
      //bai_518_dem_xung_t0_ssc();
      //bai_517_dem_gio_phut_giay_key_caitien();
      //bai_516_dem_gio_phut_giay_key_caitien();
      //bai_515_dem_gio_phut_giay_key();
      //bai_514_dem_gio_phut_giay();
      //bai_513_dem_phut_giay();
      //bai_512_dem_giay_cx();
      //bai_511_dem_giay();
      //bai_504_hienthi_8so_cach3();
      //bai_503_hienthi_8so_cach2();
      //bai_502_hienthi_10();
      //bai_501_hienthi_8so();
      
      //bai_424_key_4x4_4led_dich_undo4();
      //bai_423_key_4x4_4led_dich();
      //bai_422_dem_xung_t0_quang_cao_32led();
      //bai_421_dem_xung_t0_quang_cao_32led();
      //bai_417_dem_xung_t0_start_stop_32led();//khi dung thi xoa t0_8bit
      //bai_416_dem_xung_t0_0_9999();//khi dung thi xoa t0_8bit
      //bai_415_dem_xung_t0_250_300();//khi dung thi xoa t0_8bit va sua set_timer0(250)
      //bai_414_dem_xung_t0_240_255(); //khi dung nho sua set_timer0(240)
      //bai_413_dem_xung_t0_xoa_so0_vn_ct();
      //bai_412_dem_xung_t0_xoa_so0_vn();
      //bai_411_dem_xung_t0();
      //bai_409_dem_phut_giay();
      //bai_408_dem_0000_9999();
      //bai_407_dem_000_999();
      //bai_406_dem_00_59_00_3s();
      //bai_405_dem_00_59_00();
      //bai_404_dem_00_59();
      //bai_403_dem_00_99();
      //bai_402_dem_0_9();
      //bai_401_hienthi_4so();
      
      //b338_quangcao();
      //b337_tonghop_up_dn_clr();
      //b335_7CT_7BTN();
      //b334_matranphim_8led_16_btn_on_off();
      //b333_matranphim_8led_on_off();
      //b332_matranphim_leddon();
      //b325_16led_up_dw_clr_2() ;
      //b324_16led_up_dw_clr_1();
      //b323_on_off_inv_cdoi_8led();
      //b322_on_off_inv_8led();
      //b321_dk_32led_on_off_2bt();
      //bai_311_tong_hop_dk_32led();
      //bai_310_tong_hop_dk_32led();
      //bai_309_std_pst_32led(30);
      //bai_308_std_pst_32led(30);
      //bai_307_std_pst_32led(30);
      //bai_306_std_pst_16led_ss(50);
      //bai_305_std_pst_16led(50);
      //bai_304_std_pst_8led(100);
      //bai_303_chop_tat_32led(500);
      //bai_302_chop_tat_16led(500);
      //bai_301_chop_tat_8led_c2(500);
      //bai_301_chop_tat_8led_c1();
   }
}

