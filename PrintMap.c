#include "includes.h"

 
 

 
 
 
 
 /*--------------------------------------------------
  ������ long_delay()
  Ŀ�ģ� Ϊ���������ṩһ�����ݵ���ʱ�����ⶪʧ����
  ���룺 �� 
  ����� ��
  ���� ��
  -------------------------------------------------*/ 

void long_delay(void) {
    uint16 k,l;
     
     
       for(k=0;k<2;k++)
       for(l=0;l<500;l++);
}


 /*--------------------------------------------------
  ������  print_init_map
  Ŀ�ģ�  ��ӡ�ɼ���ԭʼͼ�� 
  ���룺  �� 
  �����  �ô��� �������λ��
  ����  map_point ָ��û�г�ʼ�� 
  -------------------------------------------------*/ 



void print_init_map(void){

  uint16 ii;
  uint8 *map_point=&ImageBuffer[0][0];
 

 for(ii=0;ii<RealRow*RealColumn;ii++) 
 {
  
        Sci_write(*map_point);
        map_point++;   
 }

 
}



 



void print_centerline(void) {

uint16 ii;
uint8 *point=&CenterLine[0];

for(ii=0;ii<RealRow;ii++) {
       
       
       Sci_write(*point);
       point++;
   
    }
    
    
}  

 
void print_binarymap(void) {

    uint16 jj;
    uint8 *point=&ImageBuffer[0][0];
   
   
   
    for(jj=0;jj<RealRow*RealColumn;jj++) {
         
         if(*point==1)
             Sci_write('1');
         else Sci_write('0');
         point++;
         
         if(!(jj%RealColumn) && jj!=0)
         Sci_write(10);
         
        }
    }
            

  void SystemStop(void){
  
       Motor_left=0;
       Motor_right=0;
       SteerDirection=Direction_mid;
       while(1);
  
  
  }
  
  
 void VoidBreak(void) 
 {
 
   if(CurrentSpeed_left<=10 && CurrentSpeed_right<=10)
   
     SystemStop();
 
 
 }
  
  
  
  
  
  
  
  
 