#include"includes.h"
/*-----------------------------------
������AtuoStop 
Ŀ�ģ���������� �Զ�ֹͣ  
���룺��⵽���ߵĵڶ���  ֻ�������ߵĵڶ��м�� 
�����ֱ�ӽ�����ѭ�� ��ɲ�� 
˼�룺��ѭ  ��-��-��-��-�� ��������     

����
------------------------------------*/

/****************ͼ��*****************
mode  :    0   1  2  3  4   5   6             

image : 00000ffff000fff0000fff00000
          ��   �� �� ��  �� ��  ��     
**************************************/



uint8 stoped;

void AutoStop(void) {
    
      uint8 ii,jj;
      uint8 left=0;
      uint8 mode=0;              //״̬      
      uint8 b2w=0,w2b=0;
 
      uint8 buffer[RealColumn];
 
      uint8 left_edge,right_edge;
      uint16 kk;
 
 if(DeadLine>11){
 
 
  
 
 
  
                                           
  for(jj=0;jj<20;jj++) {                    // �������10�У��Է�ֹ ©��� 10�����ݶ�Ӧ20cm��������ٶ�Ҫ�� 
    
      
     for(ii=0;ii<RealColumn-10;ii++) {
        
        if(ImageBuffer[jj][ii]||ImageBuffer[jj+1][ii]||ImageBuffer[jj+2][ii])
             buffer[ii]=1;
       
        else buffer[ii]=0;
     
     }
      
     
   
     mode=0; 
     
     
     
     left_edge= CenterLine[jj]+7*jj/10-50;
        if(left_edge < 0) left_edge=0;
                 
        
     right_edge=CenterLine[jj]-7*jj/10+50;
        if(right_edge>(RealColumn-10))  right_edge=RealColumn-10;
     
      
    for(ii=left_edge;ii<right_edge;ii++)    
    {
           
      
       if(buffer[ii]==0 && buffer[ii+1]==1)     //��⵽   ��-���� 
       {
            left=ii;
            
            w2b=ii;
       
        switch(mode) 
           {
            case 0: {
           
              mode=1;
              break;
           
                    }
                    
            case 2: {
            
           if(w2b-b2w>=2)
                  mode=3;
             
             
                else  mode=0;
              
              
              break;
                
            }
            
            case 4: {
            
                if(w2b-b2w>=2)
                  mode=5;
            
                 else  mode=0;
                 
                  break;
                  }
             
            default:mode=0;
                    break;  
        
              }
        }
        
          if(buffer[ii]==1 && buffer[ii+1]==0) // ��⵽    ��-����
           {
              b2w=ii;
             
           switch(mode) 
           {
                case 1: {                                     //�����߿�
                     if((ii-left)>=10)      
                        mode=2;
                    
                       break;
                      }
          
                case 3: {
                       if((ii-left)>=2 && (ii-left)<10)      //�ܵ���� խһ�� 
                       
                       
                       
                       mode=4;
                       
                    
                       break;
                    }
                    
                case 5:{
                        if((ii-left)>=10) {                 //�����߿�
                        
                       if(abs(ExpectDirection)<50) {
                        
                         Motor_left=0;
                         Motor_right=0;
                    SteerDirection=Direction_mid;
                         Motor_left_r=100;
                         Motor_right_r=100;
                         
                         for(kk=0;kk<40000;kk++);
                          for(kk=0;kk<40000;kk++);
                          for(kk=0;kk<40000;kk++);
                          for(kk=0;kk<40000;kk++);
                         Motor_left_r=0;
                         Motor_right_r=0;
                         
                         
                         stoped=1;
                         
                        // print_binarymap();
                        
                        // while(1);                   //����������ѭ��
                         }
                        
                        }       //ֹͣ  
                        break;
                    
                       }
                default:  
            
                      mode=0;        
          
             } //end of switch 
      }//end of if  
     
   
    }// end of for ii
  }
   
  
 }//end of if (DeadLine>12);
}//end of function 

 




