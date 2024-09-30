/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "software_timer.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */
int status = 0;
const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {1, 2, 3, 4};
int hour = 15, minute = 8, second = 50;
const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
//uint8_t matrix_buffer [8] = {0x01 , 0x02 , 0x03 , 0x04 , 0x05 , 0x06 , 0x07 , 0x08};
uint8_t matrix_buffer [8] = {0xFF , 0x03 , 0x01 , 0xCC , 0xCC , 0x01 , 0x03 , 0xFF};
uint8_t matrix_buffer1 [8] = {0x01 , 0x02 , 0x04 , 0x08 , 0x10 , 0x20 , 0x40 , 0x80};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_TIM2_Init(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_TIM2_Init();
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
setTimer(0, 30);
setTimer(1, 70);
setTimer(2, 57);
setTimer(3, 9);
setTimer(4, 22);
setTimer(5, 17);
setTimer(6, 11);
setTimer(7, 80);
//initEx1();
//initEx2();
//initEx3();
//initEx5();
  while (1)
  {
	  //Init BLINKY
	  if(timer_flag[0] == 1){
		  setTimer(0, 100);
		  HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	  }
	  //EX1
//	  if(timer_flag[1] == 1){
//		  setTimer(1, 50);
//		  switch(status){
//			  case 0:
//				  status = 1;
//				  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//				  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
//				  display7SEG(2);
//				  break;
//			  case 1:
//				  status = 0;
//				  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
//				  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//				  display7SEG(1);
//				  break;
//			  default:
//				  status = 0;
//
//		  }
//	  }
	  //EX2
//	  if(timer_flag[2] == 1){
//		  setTimer(2, 50);
//		  switch(status){
//			  case 0:
//				  status = 1;
//				  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
//				  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//				  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//				  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
//				  display7SEG(1);
//				  HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, RESET);
//				  break;
//			  case 1:
//				  status = 2;
//				  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//				  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
//				  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//				  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
//				  display7SEG(2);
//				  break;
//			  case 2:
//				  status = 3;
//				  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//				  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//				  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
//				  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
//				  display7SEG(3);
//				  HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, SET);
//				  break;
//			  case 3:
//				  status = 0;
//				  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//				  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//				  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//				  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
//				  display7SEG(0);
//				  break;
//			  default:
//				  status = 0;
//		  }
//	  }
	  //EX3
	  if(timer_flag[3] == 1){
		  setTimer(3, 50);//EX4 setTimer(3, 100);
		  if(index_led >= MAX_LED || index_led < 0){
			  index_led = 0;
		  }
		  update7SEG(index_led++);
	  }
	  //DOT
	  if(timer_flag[4] == 1){
		  setTimer(4, 100);
		  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	  }
	  //EX5
	  if(timer_flag[5] == 1){
		  setTimer(5, 100);
		  second++;
		  if ( second >= 60) {
		  second = 0;
		  minute ++;
		  }
		  if( minute >= 60) {
		  minute = 0;
		  hour ++;
		  }
		  if( hour >=24){
		  hour = 0;
		  }
		  updateClockBuffer ();
	  }
	  //EX9
	  if(timer_fla[7] == 1){
	  if(timer_flag[6] == 1){
		  setTimer(6, 2);
		  if(index_led_matrix >= MAX_LED_MATRIX || index_led_matrix < 0){
			  index_led_matrix = 0;
		  }
		  updateLEDMatrix(index_led_matrix++);
	  }
	  }
	  //EX10
	  if(timer_flag[7] == 1){
		  setTimer(7, 80);
		  for(int i = 0; i < MAX_LED_MATRIX; i++){
			  matrix_buffer[i] = matrix_buffer[(i+1)%8];
		  }
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG_3_Pin|SEG_4_Pin|SEG_5_Pin
                          |SEG_6_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin LED_RED_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG_0_Pin SEG_1_Pin SEG_2_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin SEG_3_Pin SEG_4_Pin SEG_5_Pin
                           SEG_6_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG_3_Pin|SEG_4_Pin|SEG_5_Pin
                          |SEG_6_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	for(int i = 0; i < no_timer; i++){
		runTimer(i);
	}
}
void display7SEG(int num){
	switch(num){
		case 0:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, RESET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, SET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, SET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, SET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, SET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, RESET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, SET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, SET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, SET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, SET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, SET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, SET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, RESET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, SET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, SET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, RESET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, RESET);
	}
}
void initEx1(){
	status = 0;
	display7SEG(1);
}
void initEx2(){
	  status = 0;
	  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	  display7SEG(1);
}
void initEx3(){
	  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
}
void initEx5(){

}
void update7SEG(int index){
	switch (index){
		case 0:
		// Display the first 7 SEG with led_buffer [0]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[0]);
		break ;
		case 1:
		// Display the second 7 SEG with led_buffer [1]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[1]);
		break ;
		case 2:
		// Display the third 7 SEG with led_buffer [2]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[2]);
		break ;
		case 3:
		// Display the forth 7 SEG with led_buffer [3]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			display7SEG(led_buffer[3]);
		break ;
		default :
			display7SEG(led_buffer[0]);
		break ;
	}
}
void updateClockBuffer(){
	led_buffer[0] = hour/10;
	led_buffer[1] = hour%10;
	led_buffer[2] = minute/10;
	led_buffer[3] = minute%10;
}
void updateLEDMatrix(int index){
	switch (index){
		case 0:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, matrix_buffer[0]&matrix_buffer1[0]);
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, matrix_buffer[0]&matrix_buffer1[1]);
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, matrix_buffer[0]&matrix_buffer1[2]);
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, matrix_buffer[0]&matrix_buffer1[3]);
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, matrix_buffer[0]&matrix_buffer1[4]);
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, matrix_buffer[0]&matrix_buffer1[5]);
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, matrix_buffer[0]&matrix_buffer1[6]);
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, matrix_buffer[0]&matrix_buffer1[7]);
			break;
		case 1:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, matrix_buffer[1]&matrix_buffer1[0]);
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, matrix_buffer[1]&matrix_buffer1[1]);
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, matrix_buffer[1]&matrix_buffer1[2]);
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, matrix_buffer[1]&matrix_buffer1[3]);
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, matrix_buffer[1]&matrix_buffer1[4]);
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, matrix_buffer[1]&matrix_buffer1[5]);
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, matrix_buffer[1]&matrix_buffer1[6]);
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, matrix_buffer[1]&matrix_buffer1[7]);
			break;
		case 2:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, matrix_buffer[2]&matrix_buffer1[0]);
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, matrix_buffer[2]&matrix_buffer1[1]);
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, matrix_buffer[2]&matrix_buffer1[2]);
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, matrix_buffer[2]&matrix_buffer1[3]);
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, matrix_buffer[2]&matrix_buffer1[4]);
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, matrix_buffer[2]&matrix_buffer1[5]);
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, matrix_buffer[2]&matrix_buffer1[6]);
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, matrix_buffer[2]&matrix_buffer1[7]);
			break;
		case 3:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, matrix_buffer[3]&matrix_buffer1[0]);
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, matrix_buffer[3]&matrix_buffer1[1]);
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, matrix_buffer[3]&matrix_buffer1[2]);
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, matrix_buffer[3]&matrix_buffer1[3]);
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, matrix_buffer[3]&matrix_buffer1[4]);
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, matrix_buffer[3]&matrix_buffer1[5]);
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, matrix_buffer[3]&matrix_buffer1[6]);
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, matrix_buffer[3]&matrix_buffer1[7]);
			break;
		case 4:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, matrix_buffer[4]&matrix_buffer1[0]);
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, matrix_buffer[4]&matrix_buffer1[1]);
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, matrix_buffer[4]&matrix_buffer1[2]);
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, matrix_buffer[4]&matrix_buffer1[3]);
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, matrix_buffer[4]&matrix_buffer1[4]);
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, matrix_buffer[4]&matrix_buffer1[5]);
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, matrix_buffer[4]&matrix_buffer1[6]);
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, matrix_buffer[4]&matrix_buffer1[7]);
			break;
		case 5:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, matrix_buffer[5]&matrix_buffer1[0]);
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, matrix_buffer[5]&matrix_buffer1[1]);
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, matrix_buffer[5]&matrix_buffer1[2]);
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, matrix_buffer[5]&matrix_buffer1[3]);
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, matrix_buffer[5]&matrix_buffer1[4]);
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, matrix_buffer[5]&matrix_buffer1[5]);
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, matrix_buffer[5]&matrix_buffer1[6]);
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, matrix_buffer[5]&matrix_buffer1[7]);
			break;
		case 6:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, matrix_buffer[6]&matrix_buffer1[0]);
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, matrix_buffer[6]&matrix_buffer1[1]);
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, matrix_buffer[6]&matrix_buffer1[2]);
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, matrix_buffer[6]&matrix_buffer1[3]);
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, matrix_buffer[6]&matrix_buffer1[4]);
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, matrix_buffer[6]&matrix_buffer1[5]);
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, matrix_buffer[6]&matrix_buffer1[6]);
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, matrix_buffer[6]&matrix_buffer1[7]);
			break;
		case 7:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, matrix_buffer[7]&matrix_buffer1[0]);
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, matrix_buffer[7]&matrix_buffer1[1]);
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, matrix_buffer[7]&matrix_buffer1[2]);
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, matrix_buffer[7]&matrix_buffer1[3]);
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, matrix_buffer[7]&matrix_buffer1[4]);
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, matrix_buffer[7]&matrix_buffer1[5]);
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, matrix_buffer[7]&matrix_buffer1[6]);
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, matrix_buffer[7]&matrix_buffer1[7]);
			break;
		default:
			break;
	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
