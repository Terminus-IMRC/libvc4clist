#include <stdint.h>
#include "vc4clist.h"
#include "vc4clist_codes.h"

static uint32_t gen_mask32(unsigned nbits);
static void add_id_backend(uint32_t *p, enum vc4clist_code val);
static void add_bits(uint32_t *p, uint32_t val, unsigned nbits, unsigned offset);
static void forward_pointer(uint32_t **pp);

#define add_id(p, val_suffix) add_id_backend(p, VC4CLIST_CODE_##val_suffix)

static uint32_t gen_mask32(unsigned nbits)
{
	if (nbits >= 32) /* To avoid interfering compile warnings */
		return ~ (uint32_t)0;
	else
		return (1 << (nbits + 1)) - 1;
}

static void add_id_backend(uint32_t *p, enum vc4clist_code val)
{
	add_bits(p, val, 32, 0);
}

static void add_bits(uint32_t *p, uint32_t val, unsigned nbits, unsigned offset)
{
	*p |= (val & gen_mask32(nbits)) << offset;
}

static void forward_pointer(uint32_t **pp)
{
	(*pp)++;
}

void vc4clist_add_HALT(uint32_t **pp)
{
	add_id(*pp, HALT);
	forward_pointer(pp);
}

void vc4clist_add_NOP(uint32_t **pp)
{
	add_id(*pp, NOP);
	forward_pointer(pp);
}

void vc4clist_add_FLUSH(uint32_t **pp)
{
	add_id(*pp, FLUSH);
	forward_pointer(pp);
}

void vc4clist_add_FLUSH_ALL_STATE(uint32_t **pp)
{
	add_id(*pp, FLUSH_ALL_STATE);
	forward_pointer(pp);
}

void vc4clist_add_START_TILE_BINNING(uint32_t **pp)
{
	add_id(*pp, START_TILE_BINNING);
	forward_pointer(pp);
}

void vc4clist_add_INCREMENT_SEMAPHORE(uint32_t **pp)
{
	add_id(*pp, INCREMENT_SEMAPHORE);
	forward_pointer(pp);
}

void vc4clist_add_WAIT_ON_SEMAPHORE(uint32_t **pp)
{
	add_id(*pp, WAIT_ON_SEMAPHORE);
	forward_pointer(pp);
}

void vc4clist_add_BRANCH(uint32_t **pp, uint32_t addr)
{
	add_id(*pp, BRANCH);
	forward_pointer(pp);

	add_bits(*pp, addr, 32, 0);
	forward_pointer(pp);
}

void vc4clist_add_BRANCH_TO_SUB_LIST(uint32_t **pp, uint32_t addr)
{
	add_id(*pp, BRANCH_TO_SUB_LIST);
	forward_pointer(pp);

	add_bits(*pp, addr, 32, 0);
	forward_pointer(pp);
}

void vc4clist_add_RETURN_FROM_SUB_LIST(uint32_t **pp)
{
	add_id(*pp, RETURN_FROM_SUB_LIST);
	forward_pointer(pp);
}

void vc4clist_add_STORE_MULTI_SAMPLE_RESOLVED_TILE_COLOR_BUFFER(uint32_t **pp)
{
	add_id(*pp, STORE_MULTI_SAMPLE_RESOLVED_TILE_COLOR_BUFFER);
	forward_pointer(pp);
}

void vc4clist_add_STORE_MULTI_SAMPLE_RESOLVED_TILE_COLOR_BUFFER_AND_SIGNAL_END_OF_FRAME(uint32_t **pp)
{
	add_id(*pp, STORE_MULTI_SAMPLE_RESOLVED_TILE_COLOR_BUFFER_AND_SIGNAL_END_OF_FRAME);
	forward_pointer(pp);
}

void vc4clist_add_STORE_FULL_RESOLUTION_TILE_BUFFER(uint32_t **pp, uint32_t dis_cbw, uint32_t dis_zsbw, uint32_t dis_cow, uint32_t ltof, uint32_t addr)
{
	addr >>= (32 - 28);

	add_id(*pp, STORE_FULL_RESOLUTION_TILE_BUFFER);
	forward_pointer(pp);

	add_bits(*pp, dis_cbw, 1, 0);
	add_bits(*pp, dis_zsbw, 1, 1);
	add_bits(*pp, dis_cow, 1, 2);
	add_bits(*pp, ltof, 1, 3);
	add_bits(*pp, addr, 28, 4);
	forward_pointer(pp);
}

void vc4clist_add_RELOAD_FULL_RESOLUTION_TILE_BUFFER(uint32_t **pp, uint32_t dis_cbr, uint32_t dis_zsbr, uint32_t addr)
{
	addr >>= (32 - 28);

	add_id(*pp, RELOAD_FULL_RESOLUTION_TILE_BUFFER);
	forward_pointer(pp);

	add_bits(*pp, dis_cbr, 1, 0);
	add_bits(*pp, dis_zsbr, 1, 1);
	add_bits(*pp, addr, 28, 4);
	forward_pointer(pp);
}

void vc4clist_add_STORE_TILE_BUFFER_GENERAL(uint32_t **pp, uint32_t bts, uint32_t fmt, uint32_t mode, uint32_t pcf, uint32_t dis_dbs, uint32_t dis_cbc, uint32_t dis_zsbc, uint32_t dis_vgmbc, uint32_t dis_cbd, uint32_t dis_zsbd, uint32_t dis_vgmbd, uint32_t ltof, uint32_t addr)
{
	addr >>= (32 - 28);

	add_id(*pp, STORE_TILE_BUFFER_GENERAL);
	forward_pointer(pp);

	add_bits(*pp, bts, 3, 0);
	add_bits(*pp, fmt, 2, 4);
	add_bits(*pp, mode, 2, 6);
	add_bits(*pp, pcf, 2, 8);
	add_bits(*pp, dis_dbs, 1, 12);
	add_bits(*pp, dis_cbc, 1, 13);
	add_bits(*pp, dis_zsbc, 1, 14);
	add_bits(*pp, dis_vgmbc, 1, 15);
	add_bits(*pp, dis_cbd, 1, 16);
	add_bits(*pp, dis_zsbd, 1, 17);
	add_bits(*pp, dis_vgmbd, 1, 18);
	add_bits(*pp, ltof, 1, 19);
	add_bits(*pp, addr, 32 - 20, 20);
	forward_pointer(pp);

	add_bits(*pp, addr, 20, 0);
	forward_pointer(pp);
}

void vc4clist_add_LOAD_TILE_BUFFER_GENERAL(uint32_t **pp, uint32_t btl, uint32_t fmt, uint32_t pcf, uint32_t dis_cbl, uint32_t dis_zsbl, uint32_t dis_vgmbl, uint32_t addr)
{
	addr >>= (32 - 28);

	add_id(*pp, LOAD_TILE_BUFFER_GENERAL);
	forward_pointer(pp);

	add_bits(*pp, btl, 3, 0);
	add_bits(*pp, fmt, 2, 4);
	add_bits(*pp, pcf, 2, 8);
	add_bits(*pp, dis_cbl, 1, 16);
	add_bits(*pp, dis_zsbl, 1, 17);
	add_bits(*pp, dis_vgmbl, 1, 18);
	add_bits(*pp, addr, 32 - 20, 20);
	forward_pointer(pp);

	add_bits(*pp, addr, 20, 0);
	forward_pointer(pp);
}

void vc4clist_add_INDEXED_PRIMITIVE_LIST(uint32_t **pp, uint32_t pm, uint32_t it, uint32_t len, uint32_t addr, uint32_t maxi)
{
	add_id(*pp, INDEXED_PRIMITIVE_LIST);
	forward_pointer(pp);

	add_bits(*pp, pm, 4, 0);
	add_bits(*pp, it, 4, 4);
	add_bits(*pp, len, 32 - 8, 8);
	forward_pointer(pp);

	add_bits(*pp, len, 8, 0);
	add_bits(*pp, addr, 32 - 40 % 32, 40 % 32);
	forward_pointer(pp);

	add_bits(*pp, addr, 40 % 32, 0);
	add_bits(*pp, maxi, 32 - 72 % 32, 72 % 32);
	forward_pointer(pp);

	add_bits(*pp, maxi, 72 % 32, 0);
	forward_pointer(pp);
}

void vc4clist_add_VERTEX_ARRAY_PRIMITIVES(uint32_t **pp, uint32_t pm, uint32_t len, uint32_t ifv)
{
	add_id(*pp, VERTEX_ARRAY_PRIMITIVES);
	forward_pointer(pp);

	add_bits(*pp, pm, 8, 0);
	add_bits(*pp, len, 32 - 8, 8);
	forward_pointer(pp);

	add_bits(*pp, len, 8, 0);
	add_bits(*pp, ifv, 32 - 40 % 32, 40 % 32);
	forward_pointer(pp);

	add_bits(*pp, ifv, 40 % 32, 0);
	forward_pointer(pp);
}

void vc4clist_add_VG_COORDINATE_ARRAY_PRIMITIVES(uint32_t **pp, uint32_t pt, uint32_t cl, uint32_t len, uint32_t addr)
{
	add_id(*pp, VG_COORDINATE_ARRAY_PRIMITIVES);
	forward_pointer(pp);

	add_bits(*pp, pt, 4, 0);
	add_bits(*pp, cl, 4, 4);
	add_bits(*pp, len, 32 - 8, 8);
	forward_pointer(pp);

	add_bits(*pp, len, 8, 0);
	add_bits(*pp, addr, 32 - 40 % 32, 40 % 32);
	forward_pointer(pp);

	add_bits(*pp, addr, 40 % 32, 0);
	forward_pointer(pp);
}

void vc4clist_add_PRIMITIVE_LIST_FORMAT(uint32_t **pp, uint32_t pt, uint32_t dt)
{
	add_id(*pp, PRIMITIVE_LIST_FORMAT);
	forward_pointer(pp);

	add_bits(*pp, pt, 4, 0);
	add_bits(*pp, dt, 4, 4);
	forward_pointer(pp);
}

void vc4clist_add_GL_SHADER_STATE(uint32_t **pp, uint32_t naa, uint32_t esr, uint32_t addr)
{
	addr >>= (32 - 28);

	add_id(*pp, GL_SHADER_STATE);
	forward_pointer(pp);

	add_bits(*pp, naa, 3, 0);
	add_bits(*pp, esr, 1, 3);
	/* TODO: offset 0 for this field considered wrong */
	add_bits(*pp, addr, 28, 4);
	forward_pointer(pp);
}

void vc4clist_add_NV_SHADER_STATE(uint32_t **pp, uint32_t addr)
{
	add_id(*pp, NV_SHADER_STATE);
	forward_pointer(pp);

	add_bits(*pp, addr, 32, 0);
	forward_pointer(pp);
}

void vc4clist_add_VG_SHADER_STATE(uint32_t **pp, uint32_t addr)
{
	add_id(*pp, VG_SHADER_STATE);
	forward_pointer(pp);

	add_bits(*pp, addr, 32, 0);
	forward_pointer(pp);
}

void vc4clist_add_VG_INLINE_SHADER_RECORD(uint32_t **pp, uint32_t dual, uint32_t code_addr, uint32_t unif_addr)
{
	code_addr >>= (32 - 29);

	add_id(*pp, VG_INLINE_SHADER_RECORD);
	forward_pointer(pp);

	add_bits(*pp, dual, 3, 0);
	add_bits(*pp, code_addr, 29, 3);
	forward_pointer(pp);

	add_bits(*pp, unif_addr, 32, 32 % 32);
	forward_pointer(pp);
}

void vc4clist_add_CONFIGURATION_BITS(uint32_t **pp, uint32_t ena_ffp, uint32_t ena_rfp, uint32_t cp, uint32_t ena_do, uint32_t apl, uint32_t crt, uint32_t rom, uint32_t cps, uint32_t cum, uint32_t crm, uint32_t dtf, uint32_t ena_zu, uint32_t ena_ez, uint32_t ena_ezu)
{
	add_id(*pp, CONFIGURATION_BITS);
	forward_pointer(pp);

	add_bits(*pp, ena_ffp, 1, 0);
	add_bits(*pp, ena_rfp, 1, 1);
	add_bits(*pp, cp, 1, 2);
	add_bits(*pp, ena_do, 1, 3);
	add_bits(*pp, apl, 1, 4);
	add_bits(*pp, crt, 1, 5);
	add_bits(*pp, rom, 2, 6);
	add_bits(*pp, cps, 1, 8);
	add_bits(*pp, cum, 2, 9);
	add_bits(*pp, crm, 1, 11);
	add_bits(*pp, dtf, 3, 12);
	add_bits(*pp, ena_zu, 1, 15);
	add_bits(*pp, ena_ez, 1, 16);
	add_bits(*pp, ena_ezu, 1, 17);
	forward_pointer(pp);
}

void vc4clist_add_FLAT_SHADE_FLAGS(uint32_t **pp, uint32_t flag)
{
	add_id(*pp, FLAT_SHADE_FLAGS);
	forward_pointer(pp);

	add_bits(*pp, flag, 32, 0);
	forward_pointer(pp);
}

void vc4clist_add_POINTS_SIZE(uint32_t **pp, uint32_t size)
{
	add_id(*pp, POINTS_SIZE);
	forward_pointer(pp);

	add_bits(*pp, size, 32, 0);
	forward_pointer(pp);
}

void vc4clist_add_LINE_WIDTH(uint32_t **pp, uint32_t width)
{
	add_id(*pp, LINE_WIDTH);
	forward_pointer(pp);

	add_bits(*pp, width, 32, 0);
	forward_pointer(pp);
}

void vc4clist_add_RHT_X_BOUNDARY(uint32_t **pp, uint32_t bnd)
{
	add_id(*pp, RHT_X_BOUNDARY);
	forward_pointer(pp);

	add_bits(*pp, bnd, 16, 0);
	forward_pointer(pp);
}

void vc4clist_add_DEPTH_OFFSET(uint32_t **pp, uint32_t fac, uint32_t unit)
{
	add_id(*pp, DEPTH_OFFSET);
	forward_pointer(pp);

	add_bits(*pp, fac, 16, 0);
	add_bits(*pp, unit, 16, 16);
	forward_pointer(pp);
}

void vc4clist_add_CLIP_WINDOW(uint32_t **pp, uint32_t lpc, uint32_t bpc, uint32_t wp, uint32_t hp)
{
	add_id(*pp, CLIP_WINDOW);
	forward_pointer(pp);

	add_bits(*pp, lpc, 16, 0);
	add_bits(*pp, bpc, 16, 16);
	forward_pointer(pp);

	add_bits(*pp, wp, 16, 32 % 32);
	add_bits(*pp, hp, 16, 48 % 32);
	forward_pointer(pp);
}

void vc4clist_add_VIEWPORT_OFFSET(uint32_t **pp, uint32_t x, uint32_t y)
{
	add_id(*pp, VIEWPORT_OFFSET);
	forward_pointer(pp);

	add_bits(*pp, x, 16, 0);
	add_bits(*pp, y, 16, 16);
	forward_pointer(pp);
}

void vc4clist_add_Z_MIN_AND_MAX_CLIPPED_PLANES(uint32_t **pp, uint32_t min, uint32_t max)
{
	add_id(*pp, Z_MIN_AND_MAX_CLIPPED_PLANES);
	forward_pointer(pp);

	add_bits(*pp, min, 32, 0);
	forward_pointer(pp);

	add_bits(*pp, max, 32, 32 % 32);
	forward_pointer(pp);
}

void vc4clist_add_CLIPPER_XY_SCALING(uint32_t **pp, uint32_t width, uint32_t height)
{
	add_id(*pp, CLIPPER_XY_SCALING);
	forward_pointer(pp);

	add_bits(*pp, width, 32, 0);
	forward_pointer(pp);

	add_bits(*pp, height, 32, 32 % 32);
	forward_pointer(pp);
}

void vc4clist_add_CLIPPER_Z_SCALE_AND_OFFSET(uint32_t **pp, uint32_t scale, uint32_t offset)
{
	add_id(*pp, CLIPPER_Z_SCALE_AND_OFFSET);
	forward_pointer(pp);

	add_bits(*pp, scale, 32, 0);
	forward_pointer(pp);

	add_bits(*pp, offset, 32, 32 % 32);
	forward_pointer(pp);
}

void vc4clist_add_TILE_BINNING_MODE_CONFIGURATION(uint32_t **pp, uint32_t tile_addr, uint32_t size, uint32_t state_addr, uint32_t width, uint32_t height, uint32_t mm, uint32_t tbd, uint32_t aitsda, uint32_t ibsize, uint32_t bsize, uint32_t db)
{
	add_id(*pp, TILE_BINNING_MODE_CONFIGURATION);
	forward_pointer(pp);

	add_bits(*pp, tile_addr, 32, 0);
	forward_pointer(pp);

	add_bits(*pp, size, 32, 32 % 32);
	forward_pointer(pp);

	add_bits(*pp, state_addr, 32, 64 % 32);
	forward_pointer(pp);

	add_bits(*pp, width, 8, 96 % 32);
	add_bits(*pp, height, 8, 104 % 32);
	add_bits(*pp, mm, 1, 112 % 32);
	add_bits(*pp, tbd, 1, 113 % 32);
	add_bits(*pp, aitsda, 1, 114 % 32);
	add_bits(*pp, ibsize, 2, 115 % 32);
	add_bits(*pp, bsize, 2, 117 % 32);
	add_bits(*pp, db, 1, 119 % 32);
	forward_pointer(pp);
}

void vc4clist_add_TILE_RENDERING_MODE_CONFIGURATION(uint32_t **pp, uint32_t addr, uint32_t width, uint32_t height, uint32_t mm, uint32_t tbd, uint32_t nhdrfmt, uint32_t dm, uint32_t mf, uint32_t ena_vgmb, uint32_t scm, uint32_t ezud, uint32_t dis_ezc, uint32_t db)
{
	add_id(*pp, TILE_RENDERING_MODE_CONFIGURATION);
	forward_pointer(pp);

	add_bits(*pp, addr, 32, 0);
	forward_pointer(pp);

	add_bits(*pp, width, 16, 32 % 32);
	add_bits(*pp, height, 16, 32 % 32);
	forward_pointer(pp);

	add_bits(*pp, mm, 1, 64 % 32);
	add_bits(*pp, tbd, 1, 65 % 32);
	add_bits(*pp, nhdrfmt, 2, 66 % 32);
	add_bits(*pp, dm, 2, 68 % 32);
	add_bits(*pp, mf, 2, 70 % 32);
	add_bits(*pp, ena_vgmb, 1, 72 % 32);
	add_bits(*pp, scm, 1, 73 % 32);
	add_bits(*pp, ezud, 1, 74 % 32);
	add_bits(*pp, dis_ezc, 1, 75 % 32);
	add_bits(*pp, db, 1, 76 % 32);
	forward_pointer(pp);
}

void vc4clist_add_CLEAR_COLORS(uint32_t **pp, uint64_t cc, uint32_t cz, uint32_t cvg, uint32_t cs)
{
	add_id(*pp, CLEAR_COLORS);
	forward_pointer(pp);

	add_bits(*pp, cc >> 32, 32, 0);
	forward_pointer(pp);

	add_bits(*pp, cc & 0xffffffff, 32, 0);
	forward_pointer(pp);

	add_bits(*pp, cz, 24, 64 % 32);
	add_bits(*pp, cvg, 8, 88 % 32);
	forward_pointer(pp);

	add_bits(*pp, cs, 8, 96 % 32);
	forward_pointer(pp);
}

void vc4clist_add_TILE_COORDINATES(uint32_t **pp, uint32_t col, uint32_t row)
{
	add_id(*pp, TILE_COORDINATES);
	forward_pointer(pp);

	add_bits(*pp, col, 8, 0);
	add_bits(*pp, row, 8, 8);
	forward_pointer(pp);
}
