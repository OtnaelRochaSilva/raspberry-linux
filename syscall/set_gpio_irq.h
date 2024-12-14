#ifndef _SET_GPIO_IRQ_
#define _SET_GPIO_IRQ_

asmlinkage long sys_set_gpio_irq(int gpio, bool enable=1);

#endif
