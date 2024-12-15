#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>
#include <linux/syscalls.h>
#include <linux/interrupt.h>
#include "set_gpio_irq.h"
#include "../gpio_irq/gpio_irq_handler.h"

//armazenará o último gpio vinculado a irq, 
//posteriormente podemos pensar nisto como uma lista
int gpio_irq_id = -1;
int irq_gpio = -1;

asmlinkage long sys_set_gpio_irq(int gpio, bool enable){

	if (gpio < 0){
		printk(KERN_WARNING "Gpio inválido '%d' digite um valor >= 0!\n", gpio);
		return -EINVAL;
	}

	if (enable){

		//revisar esta parte
		if(gpio_irq_id != -1 && gpio_irq_id == gpio){
			//libera os recursos, 
			//antes de habilitar novamente o irq para gpio
			free_irq(gpio_irq_id, NULL);
		}

		//mapeamento da irq associada ao Gpio
		irq_gpio = gpio_to_irq(gpio);
		
		int result_req_irq = request_irq(irq_gpio, gpio_irq_handler, IRQF_TRIGGER_RISING, "Telemetria_Gpio_IRQ", NULL);
		if (result_req_irq){
			printk(KERN_ERR "Falha ao requisitar irq: %d\n", result_req_irq);
			return -EIO;
		}
		gpio_irq_id = gpio;

	} else {
		if (gpio_irq_id != -1){
			free_irq(gpio_irq_id, NULL);
			gpio_irq_id = -1;
		}
	}

	return 0;
}
