
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"


TaskHandle_t Enty_Task_Handle =NULL;
TaskHandle_t Exit_Task_Handle =NULL;
/* Private function prototypes -----------------------------------------------*/

static void vEntry_Task(void *pvparameters);
static void vExit_Task(void *pvparameters);

/* USER CODE BEGIN PFP */
void vApplicationIdleHook(void);
int count1,count2;
int main(void)
{
/*BaseType_t xTaskCreate(    TaskFunction_t pvTaskCode,
                            const char * const pcName,
                            const configSTACK_DEPTH_TYPE uxStackDepth,
                            void *pvParameters,
                            UBaseType_t uxPriority,
                            TaskHandle_t *pxCreatedTask
                          ); */

  xTaskCreate(vEntry_Task,"Entry Task",200,NULL,1,&Enty_Task_Handle);
  xTaskCreate(vExit_Task,"Exit Task",200,NULL,1,&Exit_Task_Handle);
 
  vTaskStartScheduler();
  while (1)
  {

  }

}
void vAssertCalled( unsigned long ulLine, const char * const pcFileName )
{
 	taskENTER_CRITICAL();
	{
        printf("[ASSERT] %s:%lu\n", pcFileName, ulLine);
        fflush(stdout);
	}
	taskEXIT_CRITICAL();
	exit(-1);
}



/* USER CODE BEGIN 4 */
 static void vEntry_Task(void *p)
 {
	while(1)
	{
	count1++;
	printf("Entry Task Count : %d\n",count1);
        vTaskDelay(500);
		
       }
}
static void vExit_Task(void *p){
	while(1)
	{
	count2++;
	printf("Exit Task Count : %d\n",count2);
        vTaskDelay(100);	
	}
		
}

/* USER CODE END 4 */
void vApplicationIdleHook(void)
{
//	printf("Idle\r\n");
}

