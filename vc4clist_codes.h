#ifndef _VC4CLIST_CODES_H_INCLUDED_
#define _VC4CLIST_CODES_H_INCLUDED_

#include <stdint.h>

	enum vc4clist_code {
		VC4CLIST_CODE_HALT = 0,
		VC4CLIST_CODE_NOP = 1,
		VC4CLIST_CODE_FLUSH = 4,
		VC4CLIST_CODE_FLUSH_ALL_STATE = 5,
		VC4CLIST_CODE_START_TILE_BINNING = 6,
		VC4CLIST_CODE_INCREMENT_SEMAPHORE = 7,
		VC4CLIST_CODE_WAIT_ON_SEMAPHORE = 8,
		VC4CLIST_CODE_BRANCH = 16,
		VC4CLIST_CODE_BRANCH_TO_SUB_LIST = 17,
		VC4CLIST_CODE_RETURN_FROM_SUB_LIST = 18,
		VC4CLIST_CODE_STORE_MULTI_SAMPLE_RESOLVED_TILE_COLOR_BUFFER = 24,
		VC4CLIST_CODE_STORE_MULTI_SAMPLE_RESOLVED_TILE_COLOR_BUFFER_AND_SIGNAL_END_OF_FRAME = 25,
		VC4CLIST_CODE_STORE_FULL_RESOLUTION_TILE_BUFFER = 26,
		VC4CLIST_CODE_RELOAD_FULL_RESOLUTION_TILE_BUFFER = 27,
		VC4CLIST_CODE_STORE_TILE_BUFFER_GENERAL = 28,
		VC4CLIST_CODE_LOAD_TILE_BUFFER_GENERAL = 29,
		VC4CLIST_CODE_INDEXED_PRIMITIVE_LIST = 32,
		VC4CLIST_CODE_VERTEX_ARRAY_PRIMITIVES = 33,
		VC4CLIST_CODE_VG_COORDINATE_ARRAY_PRIMITIVES = 41,
		VC4CLIST_CODE_VG_INLINE_PRIMITIVES = 42,
		VC4CLIST_CODE_COMPRESSED_PRIMITIVE_LIST = 48,
		VC4CLIST_CODE_CLIPPED_PRIMITIVE_WITH_COMPRESSED_PRIMITIVE_LIST = 49,
		VC4CLIST_CODE_PRIMITIVE_LIST_FORMAT = 56,
		VC4CLIST_CODE_GL_SHADER_STATE = 64,
		VC4CLIST_CODE_NV_SHADER_STATE = 65,
		VC4CLIST_CODE_VG_SHADER_STATE = 66,
		VC4CLIST_CODE_VG_INLINE_SHADER_RECORD = 67,
		VC4CLIST_CODE_CONFIGURATION_BITS = 96,
		VC4CLIST_CODE_FLAT_SHADE_FLAGS = 97,
		VC4CLIST_CODE_POINTS_SIZE = 98,
		VC4CLIST_CODE_LINE_WIDTH = 99,
		VC4CLIST_CODE_RHT_X_BOUNDARY = 100,
		VC4CLIST_CODE_DEPTH_OFFSET = 101,
		VC4CLIST_CODE_CLIP_WINDOW = 102,
		VC4CLIST_CODE_VIEWPORT_OFFSET = 103,
		VC4CLIST_CODE_Z_MIN_AND_MAX_CLIPPED_PLANES = 104,
		VC4CLIST_CODE_CLIPPER_XY_SCALING = 105,
		VC4CLIST_CODE_CLIPPER_Z_SCALE_AND_OFFSET = 106, /* TODO: 105 on the manual considered wrong */
		VC4CLIST_CODE_TILE_BINNING_MODE_CONFIGURATION = 112,
		VC4CLIST_CODE_TILE_RENDERING_MODE_CONFIGURATION = 113,
		VC4CLIST_CODE_CLEAR_COLORS = 114,
		VC4CLIST_CODE_TILE_COORDINATES = 115,
	};

#endif /* _VC4CLIST_CODES_H_INCLUDED_ */
