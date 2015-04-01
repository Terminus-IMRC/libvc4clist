#ifndef _VC4CLIST_H_INCLUDED_
#define _VC4CLIST_H_INCLUDED_

#include <stdint.h>

	void vc4clist_add_HALT(uint32_t **pp);
	void vc4clist_add_NOP(uint32_t **pp);
	void vc4clist_add_FLUSH(uint32_t **pp);
	void vc4clist_add_FLUSH_ALL_STATE(uint32_t **pp);
	void vc4clist_add_START_TILE_BINNING(uint32_t **pp);
	void vc4clist_add_INCREMENT_SEMAPHORE(uint32_t **pp);
	void vc4clist_add_WAIT_ON_SEMAPHORE(uint32_t **pp);
	void vc4clist_add_BRANCH(uint32_t **pp, uint32_t addr);
	void vc4clist_add_BRANCH_TO_SUB_LIST(uint32_t **pp, uint32_t addr);
	void vc4clist_add_RETURN_FROM_SUB_LIST(uint32_t **pp);
	void vc4clist_add_STORE_MULTI_SAMPLE_RESOLVED_TILE_COLOR_BUFFER(uint32_t **pp);
	void vc4clist_add_STORE_MULTI_SAMPLE_RESOLVED_TILE_COLOR_BUFFER_AND_SIGNAL_END_OF_FRAME(uint32_t **pp);
	void vc4clist_add_STORE_FULL_RESOLUTION_TILE_BUFFER(uint32_t **pp, uint32_t dis_cbw, uint32_t dis_zsbw, uint32_t dis_cow, uint32_t ltof, uint32_t addr);
	void vc4clist_add_RELOAD_FULL_RESOLUTION_TILE_BUFFER(uint32_t **pp, uint32_t dis_cbr, uint32_t dis_zsbr, uint32_t addr);
	void vc4clist_add_STORE_TILE_BUFFER_GENERAL(uint32_t **pp, uint32_t bts, uint32_t fmt, uint32_t mode, uint32_t pcf, uint32_t dis_dbs, uint32_t dis_cbc, uint32_t dis_zsbc, uint32_t dis_vgmbc, uint32_t dis_cbd, uint32_t dis_zsbd, uint32_t dis_vgmbd, uint32_t ltof, uint32_t addr);
	void vc4clist_add_LOAD_TILE_BUFFER_GENERAL(uint32_t **pp, uint32_t btl, uint32_t fmt, uint32_t pcf, uint32_t dis_cbl, uint32_t dis_zsbl, uint32_t dis_vgmbl, uint32_t addr);
	void vc4clist_add_INDEXED_PRIMITIVE_LIST(uint32_t **pp, uint32_t pm, uint32_t it, uint32_t len, uint32_t addr, uint32_t maxi);
	void vc4clist_add_VERTEX_ARRAY_PRIMITIVES(uint32_t **pp, uint32_t pm, uint32_t len, uint32_t ifv);
	void vc4clist_add_VG_COORDINATE_ARRAY_PRIMITIVES(uint32_t **pp, uint32_t pt, uint32_t cl, uint32_t len, uint32_t addr);
	void vc4clist_add_PRIMITIVE_LIST_FORMAT(uint32_t **pp, uint32_t pt, uint32_t dt);
	void vc4clist_add_GL_SHADER_STATE(uint32_t **pp, uint32_t naa, uint32_t esr, uint32_t addr);
	void vc4clist_add_NV_SHADER_STATE(uint32_t **pp, uint32_t addr);
	void vc4clist_add_VG_SHADER_STATE(uint32_t **pp, uint32_t addr);
	void vc4clist_add_VG_INLINE_SHADER_RECORD(uint32_t **pp, uint32_t dual, uint32_t code_addr, uint32_t unif_addr);
	void vc4clist_add_CONFIGURATION_BITS(uint32_t **pp, uint32_t ena_ffp, uint32_t ena_rfp, uint32_t cp, uint32_t ena_do, uint32_t apl, uint32_t crt, uint32_t rom, uint32_t cps, uint32_t cum, uint32_t crm, uint32_t dtf, uint32_t ena_zu, uint32_t ena_ez, uint32_t ena_ezu);
	void vc4clist_add_FLAT_SHADE_FLAGS(uint32_t **pp, uint32_t flag);
	void vc4clist_add_POINTS_SIZE(uint32_t **pp, uint32_t size);
	void vc4clist_add_LINE_WIDTH(uint32_t **pp, uint32_t width);
	void vc4clist_add_RHT_X_BOUNDARY(uint32_t **pp, uint32_t bnd);
	void vc4clist_add_DEPTH_OFFSET(uint32_t **pp, uint32_t fac, uint32_t unit);
	void vc4clist_add_CLIP_WINDOW(uint32_t **pp, uint32_t lpc, uint32_t bpc, uint32_t wp, uint32_t hp);
	void vc4clist_add_VIEWPORT_OFFSET(uint32_t **pp, uint32_t x, uint32_t y);
	void vc4clist_add_Z_MIN_AND_MAX_CLIPPED_PLANES(uint32_t **pp, uint32_t min, uint32_t max);
	void vc4clist_add_CLIPPER_XY_SCALING(uint32_t **pp, uint32_t width, uint32_t height);
	void vc4clist_add_CLIPPER_Z_SCALE_AND_OFFSET(uint32_t **pp, uint32_t scale, uint32_t offset);
	void vc4clist_add_TILE_BINNING_MODE_CONFIGURATION(uint32_t **pp, uint32_t tile_addr, uint32_t size, uint32_t state_addr, uint32_t width, uint32_t height, uint32_t mm, uint32_t tbd, uint32_t aitsda, uint32_t ibsize, uint32_t bsize, uint32_t db);
	void vc4clist_add_TILE_RENDERING_MODE_CONFIGURATION(uint32_t **pp, uint32_t addr, uint32_t width, uint32_t height, uint32_t mm, uint32_t tbd, uint32_t nhdrfmt, uint32_t dm, uint32_t mf, uint32_t ena_vgmb, uint32_t scm, uint32_t ezud, uint32_t dis_ezc, uint32_t db);
	void vc4clist_add_CLEAR_COLORS(uint32_t **pp, uint64_t cc, uint32_t cz, uint32_t cvg, uint32_t cs);
	void vc4clist_add_TILE_COORDINATES(uint32_t **pp, uint32_t col, uint32_t row);

#endif /* _VC4CLIST_H_INCLUDED_ */
