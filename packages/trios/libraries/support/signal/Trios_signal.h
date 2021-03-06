/**
//@HEADER
// ************************************************************************
//
//                   Trios: Trilinos I/O Support
//                 Copyright 2011 Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//Questions? Contact Ron A. Oldfield (raoldfi@sandia.gov)
//
// *************************************************************************
//@HEADER
 */
/*-------------------------------------------------------------------------*/
/**
 *   @file Trios_signal.h
 *
 *   @author Ron Oldfield (raoldfi\@sandia.gov)
 *   $Revision: 756 $
 *   $Date: 2006-06-27 14:12:27 -0600 (Tue, 27 Jun 2006) $
 *
 */

#ifndef _RPC_SIGNAL_H_
#define _RPC_SIGNAL_H_

#include <Trios_threads.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__STDC__) || defined(__cplusplus)

    /**
     * @brief Install signal handlers.
     *
     * Along with the signal handlers, we pass optional
     * mutex/cond variable pair so we can signal any
     * threads waiting for the abort call.
     */
    extern int trios_install_sighandler();


    /**
     * @brief Return the exit_now variable.  If set,
     * it is time to exit the service.
     */
    extern int trios_exit_now();


    /**
     * @brief Cleanly abort the running service.
     *
     * The abort function kills a running service by sending a
     * SIGINT signal to the running process.  If the service
     * has already started,  the signal is caught by the
     * signal handler.
     */
    extern void trios_abort();


#else /* K&R C */

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif
