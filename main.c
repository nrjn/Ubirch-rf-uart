
/**
 * ubirch#1 template project.
 *
 * This is a template for creating a new project using the ubirch toolchain.
 *
 * @author Matthias L. Jugel
 * @date 2016-05-20
 *
 * Copyright 2016 ubirch GmbH (https://ubirch.com)
 *
 * == LICENSE ==
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <board.h>
#include <ubirch/timer.h>
#include <ubirch/uart.h>
#include <ubirch/ws2812b.h>
#include <fsl_flexio.h>
#include <fsl_lpuart.h>

void init_led(void)
{
  // initialize FlexIO
  flexio_config_t flexio_config;
  CLOCK_SetFlexio0Clock(kCLOCK_CoreSysClk);
  FLEXIO_GetDefaultConfig(&flexio_config);
  FLEXIO_Init(FLEXIO0, &flexio_config);
  FLEXIO_Reset(FLEXIO0);

  // enable external pin to output LED data signal
  CLOCK_EnableClock(kCLOCK_PortA);
  PORT_SetPinMux(PORTA, 14U, kPORT_MuxAlt5);

  delay(1000);

  ws2812b_init(&ws2812b_config_default);
  uint32_t led_off[3] = {0, 0, 0};
  ws2812b_send((uint32_t *)led_off, 3);
  delay_us(50);
}

void send_to_subGHz() {
  if (kLPUART_TxDataRegEmptyFlag & LPUART_GetStatusFlags(LPUART1)){
    //LPUART_WriteByte(LPUART1, value); //void LPUART_WriteBlocking(LPUART_Type *base, const uint8_t *data, size_t length)
    const uint8_t data[2] = {1, 2};
    LPUART_WriteBlocking(LPUART1, data, 2);
  }
}

//void  receive_from_subGHz() {
//
//}

int main(void) {
    board_init();
    board_console_init(BOARD_DEBUG_BAUD);
    init_led();
    uart2_init();
    PRINTF("ubirch-template v1.0\r\n");

    while (1) {
      BOARD_LED0(true);
      delay(1000);
      BOARD_LED0(false);
      delay(1000);

//      uint8_t data_array[10] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
      send_to_subGHz();
//      receive_from_subGHz();
    }


    return 0;
}


