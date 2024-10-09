#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const char ____versions[]
__used __section("__versions") =
	"\x18\x00\x00\x00\xed\x25\xcd\x49"
	"alloc_workqueue\0"
	"\x20\x00\x00\x00\x4d\x50\xf5\x57"
	"dpll_device_change_ntf\0\0"
	"\x1c\x00\x00\x00\x1a\x96\xf6\x8a"
	"dpll_pin_change_ntf\0"
	"\x18\x00\x00\x00\x9f\x5e\xd8\xd4"
	"dpll_device_put\0"
	"\x1c\x00\x00\x00\x43\xea\x9e\x89"
	"dpll_pin_unregister\0"
	"\x10\x00\x00\x00\xba\x0c\x7a\x03"
	"kfree\0\0\0"
	"\x14\x00\x00\x00\xbb\x6d\xfb\xbd"
	"__fentry__\0\0"
	"\x24\x00\x00\x00\x0b\x57\x1e\x61"
	"auxiliary_driver_unregister\0"
	"\x18\x00\x00\x00\x0d\x9a\xbe\xe4"
	"dpll_pin_get\0\0\0\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x20\x00\x00\x00\x6d\xb5\xfc\xb2"
	"queue_delayed_work_on\0\0\0"
	"\x1c\x00\x00\x00\x63\xa5\x03\x4c"
	"random_kmalloc_seed\0"
	"\x1c\x00\x00\x00\x0c\xd2\x03\x8c"
	"destroy_workqueue\0\0\0"
	"\x1c\x00\x00\x00\xea\xac\xf8\xf6"
	"dpll_netdev_pin_set\0"
	"\x20\x00\x00\x00\x14\x7f\xa7\x06"
	"dpll_device_unregister\0\0"
	"\x1c\x00\x00\x00\xca\x39\x82\x5b"
	"__x86_return_thunk\0\0"
	"\x18\x00\x00\x00\x14\xc4\x00\x92"
	"dpll_pin_put\0\0\0\0"
	"\x2c\x00\x00\x00\x6a\xfb\x6b\x78"
	"mlx5_blocking_notifier_unregister\0\0\0"
	"\x24\x00\x00\x00\x4a\x18\xa7\x9f"
	"cancel_delayed_work_sync\0\0\0\0"
	"\x18\x00\x00\x00\x39\x63\xf4\xc6"
	"init_timer_key\0\0"
	"\x20\x00\x00\x00\x1e\x8a\x95\x2d"
	"dpll_netdev_pin_clear\0\0\0"
	"\x30\x00\x00\x00\x11\x9c\xc8\x18"
	"mlx5_core_uplink_netdev_event_replay\0\0\0\0"
	"\x1c\x00\x00\x00\x44\xd9\x05\x3a"
	"dpll_pin_register\0\0\0"
	"\x20\x00\x00\x00\x6a\xdf\xee\xff"
	"delayed_work_timer_fn\0\0\0"
	"\x20\x00\x00\x00\x8f\x30\xfa\xe0"
	"dpll_device_register\0\0\0\0"
	"\x28\x00\x00\x00\x0c\xdd\xae\x84"
	"mlx5_blocking_notifier_register\0"
	"\x24\x00\x00\x00\xfe\xe8\x47\xb4"
	"__auxiliary_driver_register\0"
	"\x18\x00\x00\x00\x19\x4e\x00\x34"
	"kmalloc_trace\0\0\0"
	"\x2c\x00\x00\x00\xc6\xfa\xb1\x54"
	"__ubsan_handle_load_invalid_value\0\0\0"
	"\x18\x00\x00\x00\x53\x9a\xdf\x54"
	"dpll_device_get\0"
	"\x18\x00\x00\x00\x52\x57\xa3\x91"
	"kmalloc_caches\0\0"
	"\x20\x00\x00\x00\x77\x1f\xd3\x52"
	"mlx5_core_access_reg\0\0\0\0"
	"\x18\x00\x00\x00\x3a\x0a\xd8\xfc"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "mlx5_core");

MODULE_ALIAS("auxiliary:mlx5_core.dpll");

MODULE_INFO(srcversion, "AE16BE79953C9037B9C52FE");
