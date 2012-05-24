/* -*- c++ -*- */
/*
 * Copyright 2004 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
#ifndef INCLUDED_HOWTO_null_symbol_resample_bb_H
#define INCLUDED_HOWTO_null_symbol_resample_bb_H

#include <gr_block.h>

class howto_null_symbol_resample_bb;

/*
 * We use boost::shared_ptr's instead of raw pointers for all access
 * to gr_blocks (and many other data structures).  The shared_ptr gets
 * us transparent reference counting, which greatly simplifies storage
 * management issues.  This is especially helpful in our hybrid
 * C++ / Python system.
 *
 * See http://www.boost.org/libs/smart_ptr/smart_ptr.htm
 *
 * As a convention, the _sptr suffix indicates a boost::shared_ptr
 */
 
 typedef boost::shared_ptr<howto_null_symbol_resample_bb> howto_null_symbol_resample_bb_sptr;
 
 /*!
 * \brief Return a shared_ptr to a new instance of howto_square2_ff.
 *
 * To avoid accidental use of raw pointers, howto_make_null_symbol_resample_bb's
 * constructor is private.  howto_make_null_symbol_resample_bb is the public
 * interface for creating new instances.
 */
howto_null_symbol_resample_bb_sptr howto_make_null_symbol_resample_bb (unsigned int tu);

/*!
 * \brief square2 a stream of floats.
 * \ingroup block
 *
 * This uses the preferred technique: subclassing gr_sync_block.
 */
class howto_null_symbol_resample_bb : public gr_block
{
  // The friend declaration allows howto_make_null_symbol_resample_bb to
  // access the private constructor.
  private:

  friend howto_null_symbol_resample_bb_sptr howto_make_null_symbol_resample_bb(unsigned int tu);

  howto_null_symbol_resample_bb (unsigned int tu);  	// private constructor
                        
                        
  unsigned int d_tu;			// FFT Leange in OFDM Symbol
  unsigned int d_counter_sample;

 public:
  ~howto_null_symbol_resample_bb ();		// public destructor
  
  void forecast (int noutput_items, gr_vector_int &ninput_items_required);
  
  // Where all the action really happens

  int general_work (int noutput_items,
		    gr_vector_int &ninput_items,
		    gr_vector_const_void_star &input_items,
		    gr_vector_void_star &output_items);
};

#endif /* INCLUDED_HOWTO_null_symbol_resample_bb_H */
