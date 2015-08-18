
/*
   Copyright (c) 2014 Malte Hildingsson, malte (at) afterwi.se

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
 */

#ifndef AW_SHA1STR_H
#define AW_SHA1STR_H

#include "aw-sha1.h"

#ifdef __cplusplus
extern "C" {
#endif

static void sha1str(char s[static SHA1_SIZE * 2], unsigned char h[static SHA1_SIZE]) {
	unsigned i;

	for (i = 0; i < SHA1_SIZE; ++i) {
		s[i * 2 + 0] = ((h[i] >> 4) < 10 ? '0' : 'W') + (h[i] >> 4);
		s[i * 2 + 1] = ((h[i] & 15) < 10 ? '0' : 'W') + (h[i] & 15);
	}

	s[i] = 0;
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* AW_SHA1STR_H */

