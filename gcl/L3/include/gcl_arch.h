
/*
Copyright (c) 2012, MAURO BIANCO, UGO VARETTO, SWISS NATIONAL SUPERCOMPUTING CENTRE (CSCS)
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Swiss National Supercomputing Centre (CSCS) nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MAURO BIANCO, UGO VARETTO, OR 
SWISS NATIONAL SUPERCOMPUTING CENTRE (CSCS), BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef _GCL_ARCH_
#define _GCL_ARCH_

/** \file 
    In this file the different types of architectures are
    defined. The Architectures specifies where the data to be
    exchanged by communication patterns are residing. The possible
    choices are: \link GCL::gcl_cpu \endlink , \link GCL::gcl_gpu
    \endlink , end, for illustration purpose only, \link GCL::gcl_mic
    \endlink , which is not supported at the moment. 

    The assumption is that data to be exchanged is in the same place
    for all the processes involved in a pattern. That is, it is not
    possible to send data from a cpu main memory to a remote GPU
    memory.
*/

namespace GCL {
  /** Indicate that the data is on the main memory of the process
   */
  struct gcl_cpu {};

  /** Indicates that the data is on the memory of a GPU
   */
  struct gcl_gpu {};

  /** Indicates that the data is on the memory of a MIC card.

      Note: Not supported, placed here only for illustration.
   */
  struct gcl_mic {}; // Not supported, placed here only for illustration.
}

#endif
