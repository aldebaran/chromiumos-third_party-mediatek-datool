/*
 * Copyright (c) 2014 MediaTek Inc.
 * Author: Tristan Shieh <tristan.shieh@mediatek.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _CMDS_H_
#define _CMDS_H_

#include <stdint.h>
#include <tty_usb.h>

int start_cmd(tty_usb_handle *h);

int get_hw_code(tty_usb_handle *h, uint16_t* pdata);
#define TGT_CFG_SBC_EN                  0x00000001
#define TGT_CFG_SLA_EN                  0x00000002
#define TGT_CFG_DAA_EN                  0x00000004
#define TGT_CFG_EPP_PARAM_EXIST         0x00000008
#define TGT_CFG_ROOT_CERT_REQUIRED      0x00000010
int get_target_config(tty_usb_handle *h, uint32_t* data);
int send_auth(tty_usb_handle *h, void* p_auth, size_t len);
int send_da(tty_usb_handle *h, uint32_t addr, void* da, size_t len_da, void* sig, size_t len_sig);
int jump_da(tty_usb_handle *h, uint32_t addr);

int download_download_agent(tty_usb_handle *h, char *da_path, uint16_t chip_code);
int get_emmc_nand_info(tty_usb_handle *h);
int send_da_part_2(tty_usb_handle *h, uint32_t base_addr, void *da, uint32_t len_da, void *sig, size_t len_sig);

#endif // _CMDS_H_

