#ifndef _EN_CUSTOM_H 
#define _EN_CUSTOM_H

#include <linux/types.h>

typedef  struct __packed  {
	u16 packet_bitmap;
	u16 packet_len[4];
} metadata_header_t;

inline metadata_header_t unpack_metadata_header(u8 *data) {
	// Unpack metadata header from network data buffer
	metadata_header_t metadata_header;
	metadata_header.packet_bitmap = (data[0] << 8) | data[1];
	metadata_header.packet_len[0] = (data[2] << 8) | data[3];
	metadata_header.packet_len[1] = (data[4] << 8) | data[5];
	metadata_header.packet_len[2] = (data[6] << 8) | data[7];
	return metadata_header;
}

inline void pack_metadata_header(u8 *data, metadata_header_t metadata_header) {
	// Pack metadata header into network data buffer
	data[0] = (metadata_header.packet_bitmap >> 8) & 0xFF;
	data[1] = metadata_header.packet_bitmap & 0xFF;
	data[2] = (metadata_header.packet_len[0] >> 8) & 0xFF;
	data[3] = metadata_header.packet_len[0] & 0xFF;
	data[4] = (metadata_header.packet_len[1] >> 8) & 0xFF;
	data[5] = metadata_header.packet_len[1] & 0xFF;
	data[6] = (metadata_header.packet_len[2] >> 8) & 0xFF;
	data[7] = metadata_header.packet_len[2] & 0xFF;
}
#endif /* _EN_CUSTOM_H */
