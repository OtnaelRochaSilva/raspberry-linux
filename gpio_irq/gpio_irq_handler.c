#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>
#include <linux/irq.h>
#include <linux/workqueue.h>
#include "gpio_irq_handler.h"

static void gpio_irq_task( struct work_struct *work){

	printk(KERN_INFO "Interrupção no Gpio detectada!\n");	
	//aqui vamos colocar o restante do código para tratar a interrupção como por exemplo
	//iniciar a comunicação i2c, ou gravar um registro no mariadb e printar na tela para o usuário.
}

static DECLARE_WORK(gpio_irq_work, gpio_irq_task);

irqreturn_t gpio_irq_handler(int irq, void *dev_id){
	schedule_work(&gpio_irq_work);
	return IRQ_HANDLED;
}
