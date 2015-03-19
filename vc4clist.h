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

#endif /* _VC4CLIST_H_INCLUDED_ */
