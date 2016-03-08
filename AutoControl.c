#include "includes.h" 

/*-----------------------------------------------
������   AutoControl  
Ŀ�ģ�   PID �㷨���Ʒ�����ٶ�
���룺   �����ķ������������������ٶ� ʵ���ٶ� 
�����   ����������  ��������ٶ���� 
            
����   PWM�������ܲ��õ������ʵķ���   


------------------------------------------------*/






  static int16 duty; 

   
    
    
void  Motor_PID(void) {
   
      static int16   erro0_left=0,erro1_left=0,erro2_left=0;
      static int16   erro0_right=0,erro1_right=0,erro2_right=0;
      
      
      static int16   duty_left=100,duty_right=100;
      uint8 beta1,beta0;
      int ii;
      
       
    ///////ɲ���ж�///////////////
    //////////////////////////////
   
  //       Sci_write(CurrentSpeed_left);
  //       Sci_write(0xff);
  //        Sci_write(CurrentSpeed_right);
         
         
   
  ///////////////���ٴ������/////////////////////////////////////////////////////   
                                                                                //
    if(((CurrentSpeed_left+CurrentSpeed_right)>>1-ExpectSpeed)>0) {             //
                                                                                //
                                                                                //
            Motor_left=0;                                                       //
            Motor_right=0;                                                      //
                                                                                //
                                                                                //
                                                                                //
            Motor_left=0;                                                       //
            Motor_right=0;                                                      //
                                                                                //
             Motor_left_r=100;                                                  //
             Motor_right_r=100;                                                 //
                                                                                //
           for(ii=0;ii<30000;ii++);                                             //
           for(ii=0;ii<30000;ii++);
           for(ii=0;ii<30000;ii++); 
           for(ii=0;ii<30000;ii++);
           for(ii=0;ii<30000;ii++);                                             //
                                                                                //
               Motor_left_r=0;                                                  //
               Motor_right_r=0;                                                 //
                                                                                //
  /*  if(((CurrentSpeed_left+CurrentSpeed_right)>>1-ExpectSpeed)>6) {           //
               Motor_left_r=100;                                                //
               Motor_right_r=100;                                               //
                                                                                //
           for(ii=0;ii<30000;ii++);                                             //
            for(ii=0;ii<30000;ii++);                                            //
                                                                                //
               Motor_left_r=0;                                                  //
               Motor_right_r=0;                                                 //
                                                                                //
                                                                                //
                                                                                //
              }                                                                 //
    */                                                                          //
                                                                                //
      }                                                                         //
     /////////////////////////////////////////////////////////////////////////////
     
     
     
     //////��С�ٶ�����//////// 
      
      
      if(ExpectSpeed<20)
          ExpectSpeed=20;
      /////////////////// 
 
     
 
   
       //���ٿ���  ���� 
    
       //////////////////////////////
         
        //ExpectSpeed=25;
       /////////////////////////////
   
  
     if(ExpectDirection>0) {
        
         ExpectSpeed_left = ExpectSpeed ;
         ExpectSpeed_right= ExpectSpeed+abs(ExpectSpeed*abs(duty)/350); 
       
     
     }
      
      else {
      
           ExpectSpeed_right=ExpectSpeed;
           ExpectSpeed_left =ExpectSpeed+abs(ExpectSpeed*abs(duty)/350);
     
      }
    
      
  /*       
       
        ExpectSpeed_left= 0x60;
        ExpectSpeed_right=0x60;
       
   */   
   
       
       
       
       
   ///  if( !(ExpectSpeed_right%16))
  ///               ExpectSpeed_right--;
          
     
       erro0_left = ExpectSpeed_left - CurrentSpeed_left;
       erro0_right= ExpectSpeed_right- CurrentSpeed_right;
      
/////////////////////////////////////       �ж��Ƿ񳬵�  
///     Y�� ����pd����
///     N�� ����pid ����  
//////////////////////////////////////      
 
      
      duty_left+=(erro0_left-erro1_left)*Kp_left     + erro0_left *Ki_left +
                 (erro0_left+erro2_left-erro1_left<<1)*Kd_left;
                 
                        
      duty_right+=(erro0_right-erro1_right)*Kp_right + erro0_right*Ki_right+
                  (erro0_right+erro2_right-erro1_right<<1)*Kd_right;  
      
      
      
     erro2_left=erro1_left;
     erro1_left=erro0_left;
     
     erro2_right=erro1_right;
     erro1_right=erro0_right;
     
  ///////////////////////////////////////  
    
 //    duty_left= ExpectSpeed;
 //    duty_right=ExpectSpeed; 
    
 ////////////////////////////////////////    
 
 
 
     
     
      if(duty_right>100) {
        
            duty_right=100;
        
      }
      
      if (duty_right<0) {
      
            duty_right=0;
    
      
      }
     
  
  
  
  
     
      if(duty_left>100){
         duty_left=100;                         //��ֹ���� ���趨��Сֵ  
 
                         
        }
       if(duty_left<0) {
           duty_left=0;
        
      }
    
    
    
    
    
    
    
    
    
    
    
    
    if(!stoped){
      
     
      Motor_left=duty_left;
      Motor_right=duty_right;
      
      
    }
    
       
}


void Steer_PID(void) {

      static int16 erro0,erro1,erro_sum;
      
      static int16 last_direction=0;
      
      int direct=0;
      
 
   /*   
     erro0=ExpectDirection-last_direction;
     erro_sum+=erro0; 
        
      duty=erro0*Steer_Kp+(erro0-erro1)*Steer_Kd+erro_sum*Steer_Ki;  
     
        
      if(duty<-220) {
        duty=-220;
       erro_sum-=erro0;
      }
      else if (duty>220) {
        duty=220;
        
        erro_sum-=erro0;
      }
        erro1=erro0;
     
     
      last_direction=duty;
     
    */
    
    
  
  
  /*�޸ĺ󣬲�����pid�㷨*/     
    
    if(ExpectDirection<-220)
         duty=-220;
    
   else  if(ExpectDirection>220)
         duty=220;
    
   else duty=ExpectDirection;
   
    
    /////////////////////////
     
     
     
      direct=Direction_mid+duty;
      
      
     
      
      
      SteerDirection=direct;

}                      

 void AutoControl(void)

{
    
    
    
     
   
    Steer_PID();
    
    
    Motor_PID();
      
      
  
      
}






























  
