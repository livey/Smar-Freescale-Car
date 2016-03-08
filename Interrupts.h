#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "types.h" 

#define RealRow      (60)    //ʵ����Ҫ�Ĳ�������������  
#define RealColumn   (110)

#define Line_max     (240)   //����ж�����Ϊ 240��/֡ 
#define Line_min     (0)  

#define Row_max      (60)    //���õ�ʵ������������  
#define Row_min      (0) 

#define Column_min   (0) 
#define Column_max   (110)    //���õ����������� 

#define Mid_line      52   
 
extern uint8 SampleLock;     // �������� ͼ��ɼ�����ͼ������  
extern uint8 ProcessLock; 
extern uint8 ImageBuffer[RealRow][RealColumn];    //�洢ͼ������  

extern int16 CurrentSpeed_left;    // ��ǰ�ٶ�ֵ    
extern int16 CurrentSpeed_right;  

extern uint16 system_time;

#endif  