/* write.h

   Copyright (C) 1987, 1992 Free Software Foundation, Inc.
   
   This file is part of GAS, the GNU Assembler.
   
   GAS is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.
   
   GAS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with GAS; see the file COPYING.  If not, write to
   the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */

#ifndef TC_I960
#ifdef hpux
#define EXEC_MACHINE_TYPE HP9000S200_ID
#endif
#endif /* TC_I960 */

#ifndef LOCAL_LABEL
#ifdef DOT_LABEL_PREFIX
#define LOCAL_LABEL(name) (name[0] =='.' \
			   && ( name [1] == 'L' || name [1] == '.' ))
#else  /* not defined DOT_LABEL_PREFIX */
#define LOCAL_LABEL(name) (name [0] == 'L' )
#endif /* not defined DOT_LABEL_PREFIX */
#endif /* LOCAL_LABEL */

#define S_LOCAL_NAME(s) (LOCAL_LABEL(S_GET_NAME(s)))

/* The bit_fix was implemented to support machines that need variables
   to be inserted in bitfields other than 1, 2 and 4 bytes. 
   Furthermore it gives us a possibillity to mask in bits in the symbol
   when it's fixed in the objectcode and check the symbols limits.
   
   The or-mask is used to set the huffman bits in displacements for the
   ns32k port.
   The acbi, addqi, movqi, cmpqi instruction requires an assembler that
   can handle bitfields. Ie handle an expression, evaluate it and insert
   the result in an some bitfield. ( ex: 5 bits in a short field of a opcode) 
   */

struct bit_fix {
	int			fx_bit_size;	/* Length of bitfield		*/
	int			fx_bit_offset;	/* Bit offset to bitfield	*/
	long			fx_bit_base;	/* Where do we apply the bitfix.
						   If this is zero, default is assumed. */
	long                  fx_bit_base_adj;/* Adjustment of base */
	long			fx_bit_max;	/* Signextended max for bitfield */
	long			fx_bit_min;	/* Signextended min for bitfield */
	long			fx_bit_add;	/* Or mask, used for huffman prefix */
};
typedef struct bit_fix bit_fixS;
/*
 * FixSs may be built up in any order.
 */

struct fix {
	fragS *fx_frag;	/* Which frag? */
	long fx_where;	/* Where is the 1st byte to fix up? */
	symbolS *fx_addsy; /* NULL or Symbol whose value we add in. */
	symbolS *fx_subsy; /* NULL or Symbol whose value we subtract. */
	long fx_offset;	/* Absolute number we add in. */
	struct fix *fx_next;	/* NULL or -> next fixS. */
	short int fx_size;	/* How many bytes are involved? */
	char fx_pcrel;	/* TRUE: pc-relative. */
	char fx_pcrel_adjust;/* pc-relative offset adjust */
	char fx_im_disp;	/* TRUE: value is a displacement */
	bit_fixS *fx_bit_fixP;	/* IF NULL no bitfix's to do */  
	char fx_bsr;		/* sequent-hack */
	enum reloc_type fx_r_type;	/* Sparc hacks */
	char fx_callj;	/* TRUE if target is a 'callj'
			   (used by i960) */
	long fx_addnumber;
};

typedef struct fix fixS;

COMMON char *next_object_file_charP;

#ifndef MANY_SEGMENTS
COMMON fixS *text_fix_root, *text_fix_tail;	/* Chains fixSs. */
COMMON fixS *data_fix_root, *data_fix_tail;	/* Chains fixSs. */
#endif
COMMON fixS **seg_fix_rootP, **seg_fix_tailP;	/* -> one of above. */
extern long string_byte_count;
extern int section_alignment[];

#if __STDC__ == 1

bit_fixS *bit_fix_new(char size, char offset, long base_type, long base_adj, long min, long max, long add);
void append(char **charPP, char *fromP, unsigned long length);
void record_alignment(segT seg, int align);
void write_object_file(void);

fixS *fix_new(fragS *frag,
	      int where,
	      int size,
	      symbolS *add_symbol,
	      symbolS *sub_symbol,
	      long offset,
	      int pcrel,
	      enum reloc_type r_type);

#else /* not __STDC__ */

bit_fixS *bit_fix_new();
fixS *fix_new();
void append();
void record_alignment();
void write_object_file();

#endif /* not __STDC__ */

/*
 * Local Variables:
 * comment-column: 0
 * fill-column: 131
 * End:
 */

/* end of write.h */
