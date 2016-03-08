#ifndef IMAGE_PROCESS_H
#define IMAGE_PROCESS_H
#include "types.h" 

void ImageProcess(void);

extern int16 ExpectDirection;    // �����ķ��� 
extern uint16 ExpectSpeed_left;    // �����������ٶ�
extern uint16 ExpectSpeed_right;   // �����������ٶ�
extern uint16 ExpectSpeed;

extern uint8 MAX_SPEED;
extern uint8 MIN_SPEED; 


#endif 