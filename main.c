#include "includes.h"
 


/*---------------------------------------------------------------------
  ������ ������
  Ŀ�ģ� ���������ĳ�������  
         
         ͼ���̨�ɼ�-��ͼ����������ȡ-��ͼ�������-� PID �ٶȷ������
         
  ���룺  �� 
  �����  ��
  ����  ͼ��������Ӧ�ô򿪲����� ����Ȼ���������ؽ��Ŵ���  
  
   
  ---------------------------------------------------------------------*/ 

 
 


void main(void) {

 stoped=0;
 

 DisableInterrupts;              /****ϵͳ��ʼ��***/  

 System_init();


 SampleLock=1; 
 ProcessLock=0;
 
 EnableInterrupts;
 
 
 
   
 SteerDirection=Direction_mid;









 
 
 
 while(system_time<120);         //��ֹͣ����  
  
 Motor_left=100;
 Motor_right=100;                      
   
   
ThreshHold=0x80;    //0x80
  
  
  
while(1) {
  
if(!SampleLock) {               //���û���ڲ��� ��ʼ����ͼ��  
        
  
     ProcessLock=1; 
       
      
    
    
        
     
 //  if(Sci_read()=='a')
         
  //      print_init_map();
         
     //   print_binarymap();
       
      
     //  ThreshHold=AutoThresh(StartLine);
       
       
       ImageCenterCalculate();   //����ͼ����������ȡ 
   
      
       
      
     // if(Sci_read()=='a')
         
          // print_init_map();
         
      // print_binarymap();
  
    
     // while(Sci_read()!='a');       //��ӡͼ�� ����ʵ�ʴ��� 
     
   
   
   
   if(system_time>500)          //���������  10s ֮��  
      {
        
         AutoStop();
   
      }
        
    
     if(system_time>200)
       VoidBreak();
     
   
   // if(system_time>200)
   //    SystemStop();  
       
       
        ImageProcess(); 
      
        AutoControl(); 
         
         
         
  
    /*   
        Sci_write(0x00); 
        Sci_write(CurrentSpeed_right); 
        Sci_write(0xff);
        Sci_write(CurrentSpeed_left);
     
      */    
        
    
       ProcessLock=0;               //�رմ�����  
       SampleLock=1;                //�򿪲����� 
     
   
     }
    
    
   
    
     
     
      // ImageProcess();             //����ͼ����ȡ�����ߺ��ͼ�� ���� �Ƕ� �� �ٶ�      
     //  AutoControl();              //���������ߴ����õ� �Ƕ� �� �����ٶ�ֵ���� PID ����   
    
    
    
}//  end of while(1);


}