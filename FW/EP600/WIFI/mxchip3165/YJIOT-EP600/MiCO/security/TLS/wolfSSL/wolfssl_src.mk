#
#  UNPUBLISHED PROPRIETARY wolfssl CODE
#  Copyright (c) 2016 MXCHIP Inc.
#
#  The contents of this file may not be disclosed to third parties, copied or
#  duplicated in any form, in whole or in part, without the prior written
#  permission of MXCHIP Corporation.
#

$(NAME)_SOURCES :=	wolfssl/wolfcrypt/src/aes.c \
					wolfssl/wolfcrypt/src/arc4.c \
					wolfssl/wolfcrypt/src/asm.c \
					wolfssl/wolfcrypt/src/asn.c \
					wolfssl/wolfcrypt/src/blake2b.c \
					wolfssl/wolfcrypt/src/camellia.c \
					wolfssl/wolfcrypt/src/chacha.c \
					wolfssl/wolfcrypt/src/chacha20_poly1305.c \
					wolfssl/wolfcrypt/src/coding.c \
					wolfssl/wolfcrypt/src/compress.c \
					wolfssl/wolfcrypt/src/curve25519.c \
					wolfssl/wolfcrypt/src/des3.c \
					wolfssl/wolfcrypt/src/dh.c \
					wolfssl/wolfcrypt/src/dsa.c \
					wolfssl/wolfcrypt/src/ecc.c \
					wolfssl/wolfcrypt/src/ecc_fp.c \
					wolfssl/wolfcrypt/src/ed25519.c \
					wolfssl/wolfcrypt/src/error.c \
					wolfssl/wolfcrypt/src/fe_low_mem.c \
					wolfssl/wolfcrypt/src/fe_operations.c \
					wolfssl/wolfcrypt/src/ge_low_mem.c \
					wolfssl/wolfcrypt/src/ge_operations.c \
					wolfssl/wolfcrypt/src/hash.c \
					wolfssl/wolfcrypt/src/hc128.c \
					wolfssl/wolfcrypt/src/hmac.c \
					wolfssl/wolfcrypt/src/integer.c \
					wolfssl/wolfcrypt/src/logging.c \
					wolfssl/wolfcrypt/src/md2.c \
					wolfssl/wolfcrypt/src/md4.c \
					wolfssl/wolfcrypt/src/md5.c \
					wolfssl/wolfcrypt/src/memory.c \
					wolfssl/wolfcrypt/src/pkcs7.c \
					wolfssl/wolfcrypt/src/poly1305.c \
					wolfssl/wolfcrypt/src/pwdbased.c \
					wolfssl/wolfcrypt/src/rabbit.c \
					wolfssl/wolfcrypt/src/random.c \
					wolfssl/wolfcrypt/src/ripemd.c \
					wolfssl/wolfcrypt/src/rsa.c \
					wolfssl/wolfcrypt/src/sha.c \
					wolfssl/wolfcrypt/src/sha256.c \
					wolfssl/wolfcrypt/src/sha512.c \
					wolfssl/wolfcrypt/src/srp.c \
					wolfssl/wolfcrypt/src/tfm.c \
					wolfssl/wolfcrypt/src/wc_encrypt.c \
					wolfssl/wolfcrypt/src/wc_port.c \
					wolfssl/src/crl.c \
					wolfssl/src/internal.c \
					wolfssl/src/io.c \
					wolfssl/src/keys.c \
					wolfssl/src/ocsp.c \
					wolfssl/src/sniffer.c \
					wolfssl/src/ssl.c \
					wolfssl/src/tls.c
					
$(NAME)_SOURCES +=	mico/crypto_wrap.c \
                    mico/ssl_wrap.c
					
$(NAME)_INCLUDES := wolfssl \
					mico
					
$(NAME)_DEFINES :=	WOLFSSL_USER_SETTINGS

