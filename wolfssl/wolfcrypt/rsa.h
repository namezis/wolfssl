/* rsa.h
 *
 * Copyright (C) 2006-2014 wolfSSL Inc.
 *
 * This file is part of wolfSSL. (formerly known as CyaSSL)
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef NO_RSA

#ifndef WOLF_CRYPT_RSA_H
#define WOLF_CRYPT_RSA_H

/* for fips */
#include <cyassl/ctaocrypt/rsa.h>

#ifdef __cplusplus
    extern "C" {
#endif

WOLFSSL_API int  wc_InitRsaKey(RsaKey* key, void*);
WOLFSSL_API int  wc_FreeRsaKey(RsaKey* key);

WOLFSSL_API int  wc_RsaPublicEncrypt(const byte* in, word32 inLen, byte* out,
                                 word32 outLen, RsaKey* key, RNG* rng);
WOLFSSL_API int  wc_RsaPrivateDecryptInline(byte* in, word32 inLen, byte** out,
                                        RsaKey* key);
WOLFSSL_API int  wc_RsaPrivateDecrypt(const byte* in, word32 inLen, byte* out,
                                  word32 outLen, RsaKey* key);
WOLFSSL_API int  wc_RsaSSL_Sign(const byte* in, word32 inLen, byte* out,
                            word32 outLen, RsaKey* key, RNG* rng);
WOLFSSL_API int  wc_RsaSSL_VerifyInline(byte* in, word32 inLen, byte** out,
                                    RsaKey* key);
WOLFSSL_API int  wc_RsaSSL_Verify(const byte* in, word32 inLen, byte* out,
                              word32 outLen, RsaKey* key);
WOLFSSL_API int  wc_RsaEncryptSize(RsaKey* key);

WOLFSSL_API int  wc_RsaPrivateKeyDecode(const byte* input, word32* inOutIdx,
                                                               RsaKey*, word32);
WOLFSSL_API int  wc_RsaPublicKeyDecode(const byte* input, word32* inOutIdx,
                                                               RsaKey*, word32);
WOLFSSL_API int  wc_RsaPublicKeyDecodeRaw(const byte* n, word32 nSz,
                                        const byte* e, word32 eSz, RsaKey* key);
WOLFSSL_API int  wc_RsaFlattenPublicKey(RsaKey*, byte*, word32*, byte*,
                                                                       word32*);

#ifdef WOLFSSL_KEY_GEN
    WOLFSSL_API int MakeRsaKey(RsaKey* key, int size, long e, RNG* rng);
    WOLFSSL_API int RsaKeyToDer(RsaKey*, byte* output, word32 inLen);
#endif

#ifdef HAVE_CAVIUM
    WOLFSSL_API int  RsaInitCavium(RsaKey*, int);
    WOLFSSL_API void RsaFreeCavium(RsaKey*);
#endif


#ifdef HAVE_FIPS
    /* fips wrapper calls, user can call direct */
    WOLFSSL_API int  wc_InitRsaKey_fips(RsaKey* key, void*);
    WOLFSSL_API int  wc_FreeRsaKey_fips(RsaKey* key);

    WOLFSSL_API int  wc_RsaPublicEncrypt_fips(const byte* in,word32 inLen,byte* out,
                                 word32 outLen, RsaKey* key, RNG* rng);
    WOLFSSL_API int  wc_RsaPrivateDecryptInline_fips(byte* in, word32 inLen,
                                                 byte** out, RsaKey* key);
    WOLFSSL_API int  wc_RsaPrivateDecrypt_fips(const byte* in, word32 inLen,
                                           byte* out,word32 outLen,RsaKey* key);
    WOLFSSL_API int  wc_RsaSSL_Sign_fips(const byte* in, word32 inLen, byte* out,
                            word32 outLen, RsaKey* key, RNG* rng);
    WOLFSSL_API int  wc_RsaSSL_VerifyInline_fips(byte* in, word32 inLen, byte** out,
                                    RsaKey* key);
    WOLFSSL_API int  wc_RsaSSL_Verify_fips(const byte* in, word32 inLen, byte* out,
                              word32 outLen, RsaKey* key);
    WOLFSSL_API int  wc_RsaEncryptSize_fips(RsaKey* key);

    WOLFSSL_API int wc_RsaPrivateKeyDecode_fips(const byte* input, word32* inOutIdx,
                                            RsaKey*, word32);
    WOLFSSL_API int wc_RsaPublicKeyDecode_fips(const byte* input, word32* inOutIdx,
                                           RsaKey*, word32);
#endif /* HAVE_FIPS */


#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* WOLF_CRYPT_RSA_H */

#endif /* NO_RSA */