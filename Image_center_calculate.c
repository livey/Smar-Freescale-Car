#include "includes.h"

  //#define Threshhold    (0x60)


uint8 CenterLine[RealRow]={0};
uint8 DeadLine=RealRow-1;
uint8 StartLine=0;
uint8 *MapPoint=&ImageBuffer[0][0];


  
  /*****ͼ���ֵ������****/   
                                           
void Binarate(void){

        uint16 ii;
        MapPoint=&ImageBuffer[0][0];
        
    for(ii=0;ii<RealRow*RealColumn;ii++) {
    
      if(*MapPoint>ThreshHold)
         *MapPoint=0;
      else *MapPoint=1;
      
      MapPoint++;
    
     }
    

}


     

  


 
    



      /*****��������ȡ����������*****/ 
 
/*--------------------------------------------
������ Calculate  
Ŀ�ģ� �������߽���Ѳ�� 
���룺 ����ͼ�񻺴� 
����� ����������  

���� 1����ʼ�׶εĵ�Ѳ��û���ҵ�Ҫ������      
----------------------------------------------*/      
      
      
      
      
       

void Calculate(void){

       uint8 FindFirst=0; 
       uint8 m=0;
       uint8 findleft=0;
     
       int8 left=0;
       int8 right=0;
       int8 left_temp;
       int8 right_temp;
       uint8 ii,jj;
       int16 Right_line=RealColumn-9;
       int16 Left_line=0;
       int8  lostline=0;
       
       DeadLine=0;
       StartLine=0;
      
      
      
      

  /*��Ϊǰ���кܿ����ǰ��ߣ����߲�����������Ӧ�ö����� ǰ�漸��ȫ���� �ܺ�����Բ�һ�� */

	while(!FindFirst)                                   //   ��ֵ���� ǰһ�е�����
    {
			for(ii=Left_line;ii<Right_line;ii++)                     // ��ȥ ��Ե������
			{
				  if(ImageBuffer[m][ii]==0  && ImageBuffer[m][ii+1]==1 )     // ��� ��"0" ��Ϊ  "1"���ҵ��� ���Ե��
                    {

						findleft=1;
						left=ii;

					}

			    	else if(ImageBuffer[m][ii]==1 &&  ImageBuffer[m][ii+1]==0  )   // ����� 1 ��Ϊ 0 ���ҵ��� �ұ�Ե��
                                {
						right=ii;
						if(findleft)                        //��� �������Ե��

						{
							if((right-left)>=6 && (right-left)<13  )   //���˹��ֹ�ϸ����
                                                        {

									CenterLine[m]=(right+left)>>1;
									FindFirst=1;                          //��һ���ұ��صĵ����ض�������صĸ���
								  StartLine=m; 
									break;


								}
						}

					}
					
				

			}
			
   	if(m>=5){
   	    DeadLine=0;
 		    m=RealRow;                    //��ֹ��������   
 			   break;
   	}
    	findleft=0;
			m++;              //���û���ҵ�  ����һ��Ѱ��
		}//end of while(findfirst);  

   



	/*���������� Ѱ�� ����������������*/
	
	for(jj=m;jj<RealRow-1;jj++)
	{
		findleft=0;                                   //û���ҵ� ��һ����Ե��
	//	right_temp=right;
  //	left_temp=left;
		CenterLine[jj]=(left+right)>>1;               // Ϊ�������� Ĭ�����ĵ㼴Ϊ��һ�����ĵ�
    
    Left_line= CenterLine[jj]+7*jj/10-50;
    
      if(Left_line<0)  Left_line=0;
      
    Right_line=CenterLine[jj]-7*jj/10+50;  
      
        if(Right_line>109) Right_line=109;
        
        
  if(left-7<Left_line||right+8>=Right_line) {
  
                                     //��⵽��Ե ���˳� 
    goto haha;
  }

		for(ii=left-7;ii<right+8;ii++)				  // ������ ����㷶Χ�ҵ�
		{
			if(ImageBuffer[jj][ii]==0  &&  ImageBuffer[jj][ii+1]==1)                 //�ҵ�����ߵĵ�
            {
					findleft=1;
					left_temp=ii;

				}
			else if(ImageBuffer[jj][ii]==1 && ImageBuffer[jj][ii+1]==0)                 //�ҵ����ұߵ�
         {
					right_temp=ii;	            							  //��ֹ�˿�ʼ��Ϊ��һ���ڵ��׵���� �� ����ǰ��İ׵��� ��Ȼ�кڵ��׵Ĺ���
					if((right_temp-left_temp)>=1  && (right_temp-left_temp)<12 && findleft)                  
				    	{
						CenterLine[jj]=(right_temp+left_temp)>>1;
						DeadLine=jj;
						left=left_temp;
						right=right_temp;


						break;

				    	}
			 	}

     	if(ii==right+7) {left-=2;right+=2;lostline++; 
     	
     	
     	
     	
                                    ////////////////////////// 
                                    
     	                                   if(lostline>4) 
     	                              ///////////////////////////                
     	                                     goto  haha;
     	
     	                                        break;}    //���û���ҵ�������������������Χ 
				                                            //��Ϊ�ܿ�����������ת������� 

		}


	}

haha:              //�������˲�

   for(ii=StartLine+2;ii<DeadLine+1;ii++)
	    

			  CenterLine[ii]=(5*CenterLine[ii-2]+5*CenterLine[ii-1]+6*CenterLine[ii])>>4;
 
     



}

/*-----------------------------------------------
����:  ImageCenterCalculate 
Ŀ�ģ� ������������ȡ
���룺 �ɼ���ͼ��
����� ���������� CenterLine    ��β��־  DeadLine
���� 
-----------------------------------------------*/




void  ImageCenterCalculate(void) {

 Binarate();
 
 Calculate(); 
 
 

}
