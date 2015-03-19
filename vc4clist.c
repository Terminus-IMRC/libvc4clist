#include <stdint.h>
#include "vc4clist.h"
#include "vc4clist_codes.h"

static uint32_t gen_mask32(unsigned nbits);
static void add_id(uint32_t *p, enum vc4clist_code val);
static void add_bits(uint32_t *p, uint32_t val, unsigned nbits, unsigned offset);
static void forward_pointer(uint32_t **pp);

static uint32_t gen_mask32(unsigned nbits)
{
	if (nbits >= 32) /* To avoid interfering compile warnings */
		return ~ (uint32_t)0;
	else
		return (1 << (nbits + 1)) - 1;
}

static void add_id(uint32_t *p, enum vc4clist_code val)
{
	add_bits(p, val, 32, 0);
}

static void add_bits(uint32_t *p, uint32_t val, unsigned nbits, unsigned offset)
{
	*p |= val & (gen_mask32(nbits) << offset);
}

static void forward_pointer(uint32_t **pp)
{
	(*pp)++;
}

void vc4clist_add_HALT(uint32_t **pp)
{
	add_id(*pp, VC4CLIST_CODE_HALT);
	forward_pointer(pp);
}

void vc4clist_add_NOP(uint32_t **pp)
{
	add_id(*pp, VC4CLIST_CODE_NOP);
	forward_pointer(pp);
}
