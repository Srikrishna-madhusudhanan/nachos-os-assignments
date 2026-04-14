// implemented for assignment-6 malloc and free

#include "syscall.h"

#define NULL ((void *)0)

typedef long Align; // For alignment to the most restrictive boundary
union header { 
	struct { 
		union header *ptr; // Next block in the free list
		unsigned size; // Size of this block in "units"
	 } s;
      	Align x; // Never used, this is just to force alignment of the union 
};
typedef union header Header;

static Header base; // Dummy block to initialize the list
static Header *freep = NULL; // Pointer to the current start of the search in the free list


#define NALLOC 64 // Minimum units to request Sbrk to reduce system call overhead 

// Free implementation
void free(void *ap) {
    Header *bp, *p;

    if (freep == NULL) {
    base.s.ptr = freep = &base;
    base.s.size = 0;
    }

    bp = (Header *)ap - 1; // point to the block header 

    // find the correct insertion point in the circular linked list
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr) {
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr)) {
            break; // bp is at the beginning or end of the list 
        }
    }

    // merge with the following block if they are contiguous
    if (bp + bp->s.size == p->s.ptr) {
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else {
        bp->s.ptr = p->s.ptr;
    }

    // merge with the previous block (p) if they are contiguous
    if (p + p->s.size == bp) {
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else {
        p->s.ptr = bp;
    }

    freep = p; // we can start the next malloc search from here
}

// helper function to request more heap memory
// uses the Sbrk syscall
static Header *request_mem(unsigned nu) {
    char *cp;
    Header *up;

    if (nu < NALLOC) nu = NALLOC; // round up to minimum size 

    // request memory from the Nachos kernel 
    cp = Sbrk(nu * sizeof(Header));
    PrintString("Sbrk returned:");
    PrintNum(cp);
    PrintString("\n");
    if (cp == (char *)-1) return NULL; // sbrk failed 

    up = (Header *)cp;
    up->s.size = nu;
    free((void *)(up + 1)); // add the new large block to the free list
    return freep;
}



// Malloc implementation
void *malloc(unsigned int nbytes) {
    Header *p, *prevp;
    unsigned int nunits;

    // Calculate number of units needed, rounding up and adding 1 for the header
    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;

    // Initialization: Create the circular list with a dummy block on the first call
    if ((prevp = freep) == NULL) {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }

    // Search the circular free list
    for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {

        if (p->s.size >= nunits) { // check if a block is big enough 
            
	    if (p->s.size == nunits) { // if exactly the size as requested
                prevp->s.ptr = p->s.ptr; // delink from the list 
            } else { // else if block is larger than needed, split it 
                p->s.size -= nunits; // shrink the existing free block 
                p += p->s.size;      // move pointer to the newly carved out block 
                p->s.size = nunits;  // set the size of the new block 
            }

            freep = prevp; // update freep for the next search (next-fit) 
            return (void *)(p + 1); // return pointer to data area (just beyond header)
        }

        // if we circled back to the start without finding space, request more memory 
        if (p == freep) {
            if ((p = request_mem(nunits)) == NULL) {
		PrintString("Out of Heap Memory!");
		PrintString("\n");
                return NULL; // out of heap memory 
            }
        }
    }
}



