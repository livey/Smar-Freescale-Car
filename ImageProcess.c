#include "includes.h" 

#define Adot 15 
#define Bdot 40          ///40

#define SafeSpeed  20
#define BreakSpeed 10
#define SpeedMax   80        //80

#define A0 13
#define A1 7    //��������ٶ�������С�ٶ�ԭ�� 
 
 
#define Direct_P  310
 

//   #define maxspeed  110
 //  #define minspeed  20
#define minline   10
#define maxline   59     

 

/*----------------------------------------------------
�����IImageProcess 
Ŀ�ģ�����ȡ�����ߺ��ͼ����д��� �õ�Ԥ�Ʒ�����ٶ�
���룺��ֵ�����ͼ��
����������ķ������    ����������������  
����
-----------------------------------------------------*/  


 int16  ExpectDirection;
 uint16 ExpectSpeed_left;
 uint16 ExpectSpeed_right;
 uint16 ExpectSpeed;
 int16 speed;
 
 uint8 MAX_SPEED;
 uint8 MIN_SPEED;
 

/*��ȡ �������ٶ��뷽��*/

 
 
 


void ImageProcess(void)  {
  
   
      int offset;
      int ii,sum_all,sum_back;
		  int R;
		  int Speed;

		  int  k1,k2,k3;
		  int a0,a1,a2,a3;
		  long  jj;
		  long  aa,bb;
		  
		  
		  int16 zuobiao[RealRow]={0};


   ///////////////////////////////////////////
            ///////����任/////////
    /////////////�任��ʵ�ʵ�����/////////////
    

       for(ii=0;ii<RealRow;ii++)
           zuobiao[ii]=(CenterLine[ii]-Mid_line)*ii/50+(CenterLine[ii]-Mid_line)>>1;
           




     /*����ͼ��ָ�ԭ��*/

 
	 /*ͼ��ο��߶�̬����*/  //�ٶȿ���  

   if(DeadLine==0)
   
     {
        ExpectDirection=ExpectDirection/abs(ExpectDirection)*220;
        ExpectSpeed=SafeSpeed;
   
        return;  
     }
   
    else  if( DeadLine<7)
		  {
			  

			  ExpectDirection=(zuobiao[DeadLine]/abs(zuobiao[DeadLine]))*220;
			  ExpectSpeed=SafeSpeed;

			  return;                                

          }
	 else if(DeadLine<Adot)
		   {


			 a1=zuobiao[DeadLine]+zuobiao[DeadLine-1]+zuobiao[ii-2]+zuobiao[ii-3];
			 a1>>=2;
        

			   ExpectDirection=Direct_P*a1/DeadLine;                           // ��ҪУ����ϵ�� 


			   

		    }
      else if (DeadLine>=Adot)
		    {



				 ii=(DeadLine-60)*(Bdot-Adot)/(60-Adot)+Bdot;

			 
				
				a1=zuobiao[ii]+zuobiao[ii-1]+zuobiao[ii-2]+zuobiao[ii-3];
				a1>>=2;

				 
				  
         ExpectDirection=Direct_P*a1/ii;
  
			  }


  
 
 
 
 
 
 // �ٶȿ��� 
 
  if(DeadLine<minline)
      ExpectSpeed=MIN_SPEED;
  
  else 
  
      ExpectSpeed=MAX_SPEED-(maxline-DeadLine)*(MAX_SPEED-MIN_SPEED)/(maxline-minline);

 
 
}

       
 
 
 
 
 
 
           
   
   
int16 abs(int16 x) {

 if(x<0)
   return(-x);
   
  else return(x);


}
 
 
  
   
   