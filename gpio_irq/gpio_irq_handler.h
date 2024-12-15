#ifndef _GPIO_INTERRUPT_HANDLER_H_
#define _GPIO_INTERRUPT_HANDLER_H_

// include para usarmos os recursos preexistentes 
// no kernel para tratamento de interrupções
#include <linux/interrupt.h>

//função exportada para parametrizar dinamicamente o gpio monitorado
//int configure_gpio_irq(int gpio_id);

//Manipulador de interrupção
irqreturn_t gpio_irq_handler(int irq, void *dev_id);

#endif
