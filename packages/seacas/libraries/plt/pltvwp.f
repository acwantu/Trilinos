C Copyright (C) 2009 National Technology & Engineering Solutions
C of Sandia, LLC (NTESS).  Under the terms of Contract DE-NA0003525 with
C NTESS, the U.S. Government retains certain rights in this software.
C 
C Redistribution and use in source and binary forms, with or without
C modification, are permitted provided that the following conditions are
C met:
C 
C     * Redistributions of source code must retain the above copyright
C       notice, this list of conditions and the following disclaimer.
C 
C     * Redistributions in binary form must reproduce the above
C       copyright notice, this list of conditions and the following
C       disclaimer in the documentation and/or other materials provided
C       with the distribution.
C 
C     * Neither the name of NTESS nor the names of its
C       contributors may be used to endorse or promote products derived
C       from this software without specific prior written permission.
C 
C THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
C "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
C LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
C A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
C OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
C SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
C LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
C DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
C THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
C (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
C OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
C 

C $Id: pltvwp.f,v 1.3 1993/07/19 17:06:45 gdsjaar Exp $ 
C $Log: pltvwp.f,v $
C Revision 1.3  1993/07/19 17:06:45  gdsjaar
C Changed hex constants back to preceding X, --needed on cray. Works
C either way on other systems.
C
c Revision 1.2  1993/07/16  17:33:23  gdsjaar
c Integer constant too big on sun, replaced it with hexadecimal notation
c
c Revision 1.1  1993/07/16  16:49:50  gdsjaar
c Changed plt to library rather than single source file.
c 
C=======================================================================
      SUBROUTINE PLTVWP(PLL,PUR,N,MASK,PX,PY)
      REAL PLL(2),PUR(2)
      INTEGER MASK(*)
      REAL PX(*),PY(*)
      INTEGER IZBIT(32)
      DATA IZBIT/1,          2,          4,          8,
     *          16,         32,         64,        128,
     *         256,        512,       1024,       2048,
     *        4096,       8192,      16384,      32768,
     *       65536,     131072,     262144,     524288,
     *     1048576,    2097152,    4194304,    8388608,
     *    16777216,   33554432,   67108864,  134217728,
     *   268435456,  536870912, 1073741824, X'80000000'/

      PUR1 = PUR(1) + .0001
      PUR2 = PUR(2) + .0001
      PLL1 = PLL(1) - .0001
      PLL2 = PLL(2) - .0001
      J = 0
      KM = 0
 2300 IF (.NOT. (J.LT.N)) GO TO 2310
      JN = MIN(N-J,32)
      J1 = J
      J = J + JN
      KM = KM + 1
      IF (MASK(KM).EQ.0) THEN
         GO TO 2300

      END IF

      DO 2320 K = 1,JN
         IF (IAND(MASK(KM),IZBIT(K)).EQ.0) THEN
            GO TO 2320

         END IF

         IF (PX(K+J1).LT.PLL1 .OR. PX(K+J1).GT.PUR1) THEN
            MASK(KM) = IAND(MASK(KM),NOT(IZBIT(K)))
            GO TO 2320

         END IF

         IF (PY(K+J1).LT.PLL2 .OR. PY(K+J1).GT.PUR2) THEN
            MASK(KM) = IAND(MASK(KM),NOT(IZBIT(K)))
            GO TO 2320

         END IF

 2320 CONTINUE
      GO TO 2300

 2310 CONTINUE
      RETURN

      END
