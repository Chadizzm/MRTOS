#include "nvic.h"


void NVIC_EnableIRQ(IRQn_t IRQn) {
  uint32_t * const NVIC_ISER = (uint32_t * const)0xE000E100;
  *NVIC_ISER = 0x1 << IRQn;
}

void NVIC_DisableIRQ(IRQn_t IRQn) {
  uint32_t * const NVIC_ICER = (uint32_t * const)0xE000E180;
  *NVIC_ICER = 0x1 << IRQn;
}

void NVIC_SetPendingIRQ(IRQn_t IRQn) {
  uint32_t * const NVIC_ISPR = (uint32_t * const)0xE000E200;
  *NVIC_ISPR = 0x1 << IRQn;
}

void NVIC_ClearPendingIRQ(IRQn_t IRQn) {
  uint32_t * const NVIC_CSPR = (uint32_t * const)0xE000E280;
  *NVIC_CSPR = 0x1 << IRQn;
}

uint32_t NVIC_GetPendingIRQ(IRQn_t IRQn) {
  uint32_t * const NVIC_ISPR = (uint32_t * const)0xE000E200;
  return (*NVIC_ISPR & (0x1 << IRQn));
}

void NVIC_SetPriority(IRQn_t IRQn, uint8_t priority) {
  uint32_t * const NVIC_IPR = (uint32_t * const)0xE000E400;
  int index = IRQn / 4;
  int offset = IRQn % 4;

  uint32_t priorities = NVIC_IPR[index];

  // 0 out  priority
  priorities &= ~(0xF << (offset * 4));

  // set new priority
  priorities |= (priority << (offset * 4));

  NVIC_IPR[index] = priorities;
}

uint32_t NVIC_GetPriority(IRQn_t IRQn) {
  uint32_t * const NVIC_IPR = (uint32_t * const)0xE000E400;
  int index = IRQn / 4;
  int offset = IRQn % 4;

  uint32_t priorities = NVIC_IPR[index];

  // shift over priorities
  priorities >>= (offset * 4);

  // 0 out higher bits
  priorities &= 0x0000000F;
  return priorities;
}