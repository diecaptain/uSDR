
/*
 * "Copyright (c) 2010-2012 The Regents of the University of Michigan.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the
 *   distribution.
 * - Neither the name of the copyright holders nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * @author Ye-Sheng Kuo <samkuo@eecs.umich.edu>
 * Last update: 8/22/2012
 */

#ifndef RX_PACKET_H_
#define RX_PACKET_H_

#include <stdio.h>
#include <stdlib.h>
#include "CMSIS/a2fxxxm3.h"

struct rx_packet_str{
	uint8_t frame_type;
	uint8_t security_en;
	uint8_t frame_pending;
	uint8_t ack_req;
	uint8_t intra_pan;
	uint8_t dest_addr_mode;
	uint8_t dsn;
	uint16_t dest_pan_ID;
	uint32_t dest_addr_LSB, dest_addr_MSB;

	uint8_t packet_length;
	uint32_t payload_idx;

	uint8_t src_addr_mode;
	uint16_t src_pan_ID;
	uint32_t src_addr_LSB, src_addr_MSB;
	uint8_t rssi;
	uint8_t crc;
};

// check pending data in received fifo
inline uint8_t isFifoEmpty();

// read fifo out using dma
void read_fifo(uint32_t* rdata);

// create a received packet, frame filtering
uint8_t rx_packet_create(struct rx_packet_str* rp, uint32_t* rx_data);

#endif
