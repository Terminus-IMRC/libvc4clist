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
