#ifndef __CMD_CONFIG__
#define __CMD_CONFIG__

#include <command.h>

extern int do_reboot (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	reboot,	4,	0,	do_reboot,
	"reboot fbc",
	"reboot		- restart system.\n"
	"reboot -r upgrade [host]\n	- restart enter upgrade program,host option for select g9tv channel.\n"
	"							  default console mode."
);

#ifndef _IN_BOOT_ROM_
extern int do_suspend(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	suspend,	1,	0,	do_suspend,
	"suspend",
	"/N\n"
	"This command will into suspend\n"
);

extern int do_test(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	load,	3,	0,	do_test,
	"load",
	"/N\n"
	"This command will into suspend\n"
);

extern int do_mem_md(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	md,	5,	1,	do_mem_md,
	"memory display",
	"[.b, .w, .l] address [# of objects]"
);

extern int do_mem_mw(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	mw,	6,	1,	do_mem_mw,
	"memory write (fill)",
	"[.b, .w, .l] address value [count]"
);
#endif

#ifdef IN_FBC_MAIN_CONFIG
extern int do_spi_flash(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	sf,	5,	0,	do_spi_flash,
	"SPI flash sub-system",
	"sf read addr offset len 	- read `len' bytes starting at\n"
	"				  `offset' to memory at `addr'\n"
	"sf write addr offset len	- write `len' bytes from memory\n"
	"				  at `addr' to flash at `offset'\n"
	"sf erase offset len		- erase `len' bytes from `offset'"
);

extern int do_help(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	help,	2,	1,	do_help,
	"print command description/usage",
	"\n"
	"	- print brief description of all commands\n"
	"help command ...\n"
	"	- print detailed usage of 'command'"
);

extern int do_log_out(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	logcat,	6,	0,	do_log_out,
	"logcat",
	"[-c, -s] [TAG:PRIO]"
);

extern int do_mem_cp(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	cp,	4,	1,	do_mem_cp,
	"memory copy",
	"[.b, .w, .l] source target count"
);

extern int do_key_transfer(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	key,	3,	0,	do_key_transfer,
	"key",
	""
);


extern int do_vpp_debug(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	vpp,	10,	0,	do_vpp_debug,
	"vpp",
	""
);
extern int do_gamma_debug(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	gamma,	10,	0,	do_gamma_debug,
	"gamma",
	""
);
extern int do_cm_debug(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	cm,	10,	0,	do_cm_debug,
	"cm",
	""
);
extern int do_demura_debug(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	demura,	10,	0,	do_demura_debug,
	"demura",
	""
);
extern int do_dnlp_debug(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	dnlp,	4,	0,	do_dnlp_debug,
	"dnlp",
	""
);
extern int do_cmd_debug(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	cmd,	10,	0,	do_cmd_debug,
	"cmd",
	""
);
extern int do_scmd_debug(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	scmd,	10,	0,	do_scmd_debug,
	"scmd",
	""
);

extern int do_mem_crc (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	crc32,	4,	1,	do_mem_crc,
	"checksum calculation",
	"address count [addr]\n    - compute CRC32 checksum [save at addr]"
);

extern int do_hdmi_debug(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	hdmi,	10,	1,	do_hdmi_debug,
	"hdmi",
	""
);

extern int do_i2c_test(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
FBC_BOOT_CMD(
	i2c,	10,	0,	do_i2c_test,
	"",
	"i2c -r addr reg len ---- i2c read.\n"
	"i2c -w addr reg value [value...] ---- i2c write.\n"
);

extern int do_cri(cmd_tbl_t *cmdtp, int flag, int argc, char *const argv[]);
FBC_BOOT_CMD(
	cri,	10,	0,	do_cri,
	"",
	"cri pid r                      ---- read current project id.\n"
	"cri pid w id                   ---- write project id as id.\n"
	"cri pid wa id                  ---- write project id as id and load pq from bin to pq param by id.\n"
	"cri sn r                       ---- read factory sn.\n"
	"cri sn w ascii_str             ---- write factory sn as ascii_str.\n"
	"cri did r                      ---- read device id.\n"
	"cri did w ascii_str            ---- write device id as ascii_str.\n"
	"cri sf r offset len            ---- read spi flash len bytes from offset (max allow 16KB).\n"
	"cri sf w offset hex_str        ---- write spi flash trans from hex_str. (hex_str len should be multiple as 2.)\n"
);

#endif

#ifdef IN_FBC_MAIN_CONFIG
cmd_tbl_t *default_cmd[] = {
	GET_CMD_ADDR_FROM_CNAME(suspend),	\
	GET_CMD_ADDR_FROM_CNAME(help),		\
	GET_CMD_ADDR_FROM_CNAME(md),	\
	GET_CMD_ADDR_FROM_CNAME(mw),	\
	GET_CMD_ADDR_FROM_CNAME(cp),	\
	GET_CMD_ADDR_FROM_CNAME(logcat), \
	GET_CMD_ADDR_FROM_CNAME(key),\
	GET_CMD_ADDR_FROM_CNAME(vpp),\
	GET_CMD_ADDR_FROM_CNAME(gamma),\
	GET_CMD_ADDR_FROM_CNAME(cm),\
	GET_CMD_ADDR_FROM_CNAME(demura),\
	GET_CMD_ADDR_FROM_CNAME(dnlp),\
	GET_CMD_ADDR_FROM_CNAME(cmd),\
	GET_CMD_ADDR_FROM_CNAME(scmd),\
	GET_CMD_ADDR_FROM_CNAME(hdmi),	\
	GET_CMD_ADDR_FROM_CNAME(crc32),\
	GET_CMD_ADDR_FROM_CNAME(reboot),\
	GET_CMD_ADDR_FROM_CNAME(sf),\
	GET_CMD_ADDR_FROM_CNAME(i2c),\
	GET_CMD_ADDR_FROM_CNAME(cri),
};
#else
cmd_tbl_t *default_cmd[] = {
#ifndef _IN_BOOT_ROM_
	GET_CMD_ADDR_FROM_CNAME(suspend),	\
	GET_CMD_ADDR_FROM_CNAME(md),	\
	GET_CMD_ADDR_FROM_CNAME(mw),	\
	GET_CMD_ADDR_FROM_CNAME(reboot),\
	GET_CMD_ADDR_FROM_CNAME(load),
#else
	GET_CMD_ADDR_FROM_CNAME(reboot),
#endif
};
#endif

#endif
