#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/workqueue.h>
#include "gpio_irq_handler.h"

static DECLARE_WORK(gpio_t, gpio_irq_task);
int gpio_irq_id;

static irqreturn_t gpio_irq_handler(int irq, void *dev_id){
	schedule_work(&gpio_t);
	return IRQ_HANDLED;
}

static void gpio_irq_task( struct work_struct *work){
	printk(KERN_INFO "Interrupção no Gpio %d detectada!\n", gpio_irq_id);
	//aqui vamos colocar o restante do código para tratar a interrupção como por exemplo
	//iniciar a comunicação i2c, ou gravar um registro no mariadb e printar na tela para o usuário.
}
