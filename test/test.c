#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>

MODULE_LICENSE("GPLV2");
MODULE_VERSION("0.1");


static int __init hello(void)
{
	printk(KERN_INFO "starting....\n");
	printk(KERN_INFO "Hello world\n");
	printk("currentpid:%d name:%s",current->pid,current->comm);
	printk(KERN_DEBUG "%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}
static void __exit hello_completed(void)
{
	printk(KERN_INFO "Completed\n");
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);

}

module_init(hello);
module_exit(hello_completed);
