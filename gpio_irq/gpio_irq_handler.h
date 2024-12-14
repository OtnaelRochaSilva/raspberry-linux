#ifndef _GPIO_INTERRUPT_HANDLER_H_
#define _GPIO_INTERRUPT_HANDLER_H_

// include para usarmos os recursos preexistentes 
// no kernel para tratamento de interrupções
#include <linux/interrupt.h>

// Vai possibilitar a mudança dinâmica de pinos de interrupção
extern int gpio_irq_id;

irqreturn_t gpio_irq_handler(int irq, void *dev_id);

#endif

