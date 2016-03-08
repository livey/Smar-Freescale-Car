#include "includes.h"
uint8 SampleLock;
uint8 ProcessLock; 

uint16 system_time=0;

uint8  ImageBuffer[RealRow][RealColumn]={0}; //�洢������ͼ  

const uint8  SampleLine[Row_max]={                 //�洢ʵ����Ҫ�Ĳ�������  
                                             //ͨ�������˲�������ֵ���Ե��������ܶ�  
/* 
4,9,14,19,24,29,34,39,44,49,
54,59,64,69,74,79,84,89,94,99,
114,119,124,129,134,139,144,149,     //ǰ��ʮ���� ÿ��5��һ������ֵ   
 
152,155,158,161,164,167,170,173,176,179,
182,185,188,191,194,197,200,203,207,209,
211,213,215,216,217,219,220,222,223,225,230,233     //ǰ��ʮ����ÿ��������ɼ�һ��                                     
 
*/ 

1,5,10,16,20,31,40,45,57,62,68,79,88,97,105,
112,119,126,132,137,143,   148,152,   157,161,
165,169,172,176,179,182,185,188,190,193,
195,198,200,202,204,206,208,210,213,
215,217,218,220,221,223,224,225,227,228,
229,231,233,234, 236,237 
 
                                         
};
                                                    
int16 CurrentSpeed_left =0;
int16 CurrentSpeed_right=0;  
 
uint8  TrueLine=0;                           //��ʵ�Ĳ�������  
uint16 LineCount=0;                          //�����˶����� ���ж��˶��ٴ���

uint16 ii,jj;


/*-------------------------------------------------------
  ������  j���жϺ���
  Ŀ�ģ�  ��־һ���źŵĵ��� ���ý����е�׼�� ���������� 
  ���룺  �� 
  �����  ��
  ����   
  ------------------------------------------------------*/ 





#pragma  CODE_SEG NON_BANKED


void interrupt 24 intportj7(void){           //���ж� 

     PIFJ_PIFJ7=1;                           //���жϱ�־
     
     system_time++;
     
     CurrentSpeed_left=PACNT;                       //ÿ����ʮ��ms����һ���ٶȸ��� 
      
      PACNT=0;                                       //��ռ����� 
     
     
     CurrentSpeed_right=PORTB;
    
     PTT_PTT4=1;
     PTT_PTT4=0;                                      //����
     PTT_PTT4=0;
     PTT_PTT4=0;
     PTT_PTT4=0;
     
     PTT_PTT4=1;
     
   //  if((CurrentSpeed_left-CurrentSpeed_right)>0xa0)   // ��ֹ��λ������������ 
    //      CurrentSpeed_right<<=8;
     
     
     
                                    
     
     if(!ProcessLock) {                     //���û�����ڴ���
     SampleLock=1;                          //��������
     
     PIEP_PIEP7=1;                          //�������ж�
     
     LineCount=0;                           //��������������
     TrueLine=0;                            //ʵ�ʲ�����������
     
     }
 
  
 
  
 
 
 

}


/*------------------------------------------------------
  ������  P�� �жϺ���  
  Ŀ�ģ�  ���ж� ��ȡÿһ�е����� ���һ֡ͼ��  
  ���룺  �� 
  �����   
  ���� TureLine++ �Ŵ���λ�� �������ݲɼ�����ȷ
  -----------------------------------------------------*/ 




#pragma CODE_SEG NON_BANKED                  //���ж� 
 
void interrupt 56 intportp7 (void) {

        PIFP_PIFP7=1;
   
     if(LineCount==SampleLine[TrueLine]) {       //����Ϊ��Ҫ�ɼ������� 
     
     
      
      
      for(ii=0;ii<RealColumn;ii++) {             //�˴�ִ��   15*RealColumn(80)   
      
         ImageBuffer[TrueLine][ii]=PORTA;        //��ʼ�ɼ���һ�е����� 
      //  ImageBuffer[TrueLine][ii]=PORTA;
      //   ImageBuffer[TrueLine][ii]=PORTA;
        
     
      /*    ȡֵ��  �����������ѡ��Ľ��зǵȾ����       
                
           
            
           image[line][0]=PORTA;   image[line][0]=PORTA;   image[line][0]=PORTA;  
           image[line][1]=PORTA;   image[line][1]=PORTA;   image[line][1]=PORTA;  
           image[line][2]=PORTA;   image[line][2]=PORTA;   image[line][2]=PORTA;  
           image[line][3]=PORTA;   image[line][3]=PORTA;   image[line][3]=PORTA;  
           image[line][4]=PORTA;   image[line][4]=PORTA;   image[line][4]=PORTA;  
           image[line][5]=PORTA;   image[line][5]=PORTA;   image[line][5]=PORTA;  
           image[line][6]=PORTA;   image[line][6]=PORTA;   image[line][6]=PORTA;  
           image[line][7]=PORTA;   image[line][7]=PORTA;   image[line][7]=PORTA;  
           image[line][8]=PORTA;   image[line][8]=PORTA;   image[line][8]=PORTA;  
           image[line][9]=PORTA;   image[line][9]=PORTA;   image[line][9]=PORTA;  
           image[line][10]=PORTA;  image[line][10]=PORTA;  image[line][10]=PORTA;
           image[line][11]=PORTA;  image[line][11]=PORTA;  image[line][11]=PORTA;  
           image[line][12]=PORTA;  image[line][12]=PORTA;  image[line][12]=PORTA;  
           image[line][13]=PORTA;  image[line][13]=PORTA;  image[line][13]=PORTA;  
           image[line][14]=PORTA;  image[line][14]=PORTA;  image[line][14]=PORTA;  
           image[line][15]=PORTA;  image[line][15]=PORTA;  image[line][15]=PORTA;  
           image[line][16]=PORTA;  image[line][16]=PORTA;  image[line][16]=PORTA;  
           image[line][17]=PORTA;  image[line][17]=PORTA;  image[line][17]=PORTA;  
           image[line][18]=PORTA;  image[line][18]=PORTA;  image[line][18]=PORTA;  
           image[line][19]=PORTA;  image[line][19]=PORTA;  image[line][19]=PORTA;  
           image[line][20]=PORTA;  image[line][20]=PORTA;  image[line][20]=PORTA;  
           image[line][21]=PORTA;  image[line][21]=PORTA;  image[line][21]=PORTA; 
           image[line][22]=PORTA;  image[line][22]=PORTA;  image[line][22]=PORTA;  
           image[line][23]=PORTA;  image[line][23]=PORTA;  image[line][23]=PORTA;  
           image[line][24]=PORTA;  image[line][24]=PORTA;  image[line][24]=PORTA;  
           image[line][25]=PORTA;  image[line][25]=PORTA;  image[line][25]=PORTA;  
           image[line][26]=PORTA;  image[line][26]=PORTA;  image[line][26]=PORTA;  
           image[line][27]=PORTA;  image[line][27]=PORTA;  image[line][27]=PORTA;  
           image[line][28]=PORTA;  image[line][28]=PORTA;  image[line][28]=PORTA;  
           image[line][29]=PORTA;  image[line][29]=PORTA;  image[line][29]=PORTA;  
           image[line][30]=PORTA;  image[line][30]=PORTA;  image[line][30]=PORTA;  
           image[line][31]=PORTA;  image[line][31]=PORTA;  image[line][31]=PORTA;  
           image[line][32]=PORTA;  image[line][32]=PORTA;  image[line][32]=PORTA;
           image[line][33]=PORTA;  image[line][33]=PORTA;  image[line][33]=PORTA;  
           image[line][34]=PORTA;  image[line][34]=PORTA;  image[line][34]=PORTA;  
           image[line][35]=PORTA;  image[line][35]=PORTA;  image[line][35]=PORTA;  
           image[line][36]=PORTA;  image[line][36]=PORTA;  image[line][36]=PORTA;  
           image[line][37]=PORTA;  image[line][37]=PORTA;  image[line][37]=PORTA;  
           image[line][38]=PORTA;  image[line][38]=PORTA;  image[line][38]=PORTA;  
           image[line][39]=PORTA;  image[line][39]=PORTA;  image[line][39]=PORTA;  
           image[line][40]=PORTA;  image[line][40]=PORTA;  image[line][40]=PORTA;  
           image[line][41]=PORTA;  image[line][41]=PORTA;  image[line][41]=PORTA;  
           image[line][42]=PORTA;  image[line][42]=PORTA;  image[line][42]=PORTA;  
           image[line][43]=PORTA;  image[line][43]=PORTA;  image[line][43]=PORTA;   
           image[line][44]=PORTA;  image[line][44]=PORTA;  image[line][44]=PORTA;  
           image[line][45]=PORTA;  image[line][45]=PORTA;  image[line][45]=PORTA;  
           image[line][46]=PORTA;  image[line][46]=PORTA;  image[line][46]=PORTA;  
           image[line][47]=PORTA;  image[line][47]=PORTA;  image[line][47]=PORTA;  
           image[line][48]=PORTA;  image[line][48]=PORTA;  image[line][48]=PORTA;  
           image[line][49]=PORTA;  image[line][49]=PORTA;  image[line][49]=PORTA;  
           image[line][50]=PORTA;  image[line][50]=PORTA;  image[line][50]=PORTA;  
           image[line][51]=PORTA;  image[line][51]=PORTA;  image[line][51]=PORTA;  
           image[line][52]=PORTA;  image[line][52]=PORTA;  image[line][52]=PORTA;  
           image[line][53]=PORTA;  image[line][53]=PORTA;  image[line][53]=PORTA;  
           image[line][54]=PORTA;  image[line][54]=PORTA;  image[line][54]=PORTA;
           image[line][55]=PORTA;  image[line][55]=PORTA;  image[line][55]=PORTA;  
           image[line]56[]=PORTA;  image[line][56]=PORTA;  image[line][56]=PORTA;  
           image[line][57]=PORTA;  image[line][57]=PORTA;  image[line][57]=PORTA;  
           image[line][58]=PORTA;  image[line][58]=PORTA;  image[line][58]=PORTA;  
           image[line][59]=PORTA;  image[line][59]=PORTA;  image[line][59]=PORTA;  
           image[line][60]=PORTA;  image[line][60]=PORTA;  image[line][60]=PORTA;  
           image[line][61]=PORTA;  image[line][61]=PORTA;  image[line][61]=PORTA;  
           image[line][62]=PORTA;  image[line][62]=PORTA;  image[line][62]=PORTA;  
           image[line][63]=PORTA;  image[line][63]=PORTA;  image[line][63]=PORTA;  
           image[line][64]=PORTA;  image[line][64]=PORTA;  image[line][64]=PORTA;  
           image[line][65]=PORTA;  image[line][65]=PORTA;  image[line][65]=PORTA;
           image[line][66]=PORTA;  image[line][66]=PORTA;  image[line][66]=PORTA;  
           image[line][67]=PORTA;  image[line][67]=PORTA;  image[line][67]=PORTA;  
           image[line][68]=PORTA;  image[line][68]=PORTA;  image[line][68]=PORTA;  
           image[line][69]=PORTA;  image[line][69]=PORTA;  image[line][69]=PORTA;  
           image[line][70]=PORTA;  image[line][70]=PORTA;  image[line][70]=PORTA;  
           image[line][71]=PORTA;  image[line][71]=PORTA;  image[line][71]=PORTA;  
           image[line][72]=PORTA;  image[line][72]=PORTA;  image[line][72]=PORTA;  
           image[line][73]=PORTA;  image[line][73]=PORTA;  image[line][73]=PORTA;  
           image[line][74]=PORTA;  image[line][74]=PORTA;  image[line][74]=PORTA;  
           image[line][75]=PORTA;  image[line][75]=PORTA;  image[line][75]=PORTA;  
           image[line][76]=PORTA;  image[line][76]=PORTA;  image[line][76]=PORTA;
           image[line][77]=PORTA;  image[line][77]=PORTA;  image[line][77]=PORTA;  
           image[line][78]=PORTA;  image[line][78]=PORTA;  image[line][78]=PORTA;  
           image[line][79]=PORTA;  image[line][79]=PORTA;  image[line][79]=PORTA;  
                     
         
          */      
     
     
     
      }
     
     
     
     
      TrueLine++;                              //�����һ�е�ʵ�� �ɼ� ʵ�ʲ���������һ 
     }
       
       
       
       
                                     
   LineCount++;                                 //ʵ��������һ  
   
   if(LineCount>=Line_max||TrueLine>=Row_max)
   
     {
     
      SampleLock=0;                //�������� ����û���ڲ���  
      ProcessLock=1;               //�򿪴����� ��ֹ ���ж� ��ռ ��һ֡δ�����ͼ��  
      PIEP_PIEP7=0;                //�����ж� 
     
     
     }
        
     
   
     


}
  


