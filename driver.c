#include "header.h"
static int pen_probe(struct usb_interface *interface , const struct usb_device_id *id)
{
printk(KERN_INFO "[*] driver (%04X:%04X) plugged os pro***********\n",id->idVendor,id->idProduct);
//system("xbacklight -dec 10");

return 0;
}

static void pen_disconnect(struct usb_interface *interface)
{
printk(KERN_INFO "[*] Removed");
}

static struct usb_device_id pen_table[]={
{USB_DEVICE(0x0781,0x5567)},
 {} //terminating entry
};

static struct usb_driver pen_driver =
{
.name = "driver",
.id_table=pen_table, //id
.probe = pen_probe,
.disconnect = pen_disconnect,
};

static int __init pen_init(void)
{
int ret =-1;
printk(KERN_INFO "[*]driver constructor");
printk(KERN_INFO "[*]registering with the kernel");
ret=usb_register(&pen_driver);
printk(KERN_INFO "[*]complete");
return ret;
};

static void __exit pen_exit(void)
{
//deregister
printk(KERN_INFO "[*]driver destructor");
usb_deregister(&pen_driver);
printk(KERN_INFO "[*]driver destructed");
};
module_init(pen_init);
module_exit(pen_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DRIVER");
MODULE_DESCRIPTION("REG");



